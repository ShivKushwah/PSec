machine UntrustedInitializer {
    var handler: machine_handle;
    start state Initial {
        entry {
            handler = new TrustedInitializer();
        }
    }
}

secure_machine TrustedInitializer {
    
    var clientUSM: machine_handle;
    var bankSSM: secure_machine_handle;
    start state Initial {
        entry {
            clientUSM = new ClientWebBrowser();
            bankSSM = new BankEnclave();
            send bankSSM, TRUSTEDProvisionBankSSM, clientUSM; //secure_send
            send clientUSM, BankPublicIDEvent, Declassify(bankSSM) as machine_handle; //untrusted_send
        }
    }
}

secure_machine BankEnclave {
    var clientSSM: secure_machine_handle;
    var clientUSM: machine_handle;
    var masterSecret : secure_StringType;
    var userCredential : secure_StringType;
    start state Initial {
        entry { 
            goto ReceiveClientUSM;
        } 
    }

    state ReceiveClientUSM {
        on TRUSTEDProvisionBankSSM do (payload: machine_handle) {
            clientUSM = payload;
            clientSSM = new ClientEnclave();
            MeasureStartTrustedSend();
            send clientSSM, TRUSTEDProvisionClientSSM, clientUSM;
            goto RegisterNewBankAccount;
            
        }
    }

    state RegisterNewBankAccount {
        on UNTRUSTEDReceiveRegistrationCredentials do (payload: StringType) {
            print "Bank: Creating new bank account!";
            userCredential = payload;
            masterSecret = GenerateRandomMasterSecret();
            MeasureStartTrustedSend2();
            send clientSSM, MasterSecretEvent, masterSecret; //secure_send
            send clientUSM, PublicIDEvent, Declassify(clientSSM) as machine_handle; //untrusted_send
            goto AuthCheck;

        }
    }

    state AuthCheck {
       on AuthenticateRequest goto Verify;
    }

    state Verify { 
        entry (payload : (usernamePW: StringType, OTPCode: StringType)) {
            if (Declassify(userCredential) == payload.usernamePW && Hash(masterSecret as StringType, userCredential as StringType) == payload.OTPCode) {
                send clientUSM, AuthSuccess; //untrusted_send
            } else {
                send clientUSM, AuthFailure; //untrusted_send
            }
            
            goto AuthCheck;
        }

    }
}
machine UntrustedInitializer {
    var handler: machine_handle;
    start state Initial {
        entry {
            handler = new TrustedInitializer() @ this;
        }
    }
}

secure_machine TrustedInitializer {
    
    var clientUSM: machine_handle;
    var bankSSM: secure_machine_handle;
    start state Initial {
        entry {
            clientUSM = new ClientWebBrowser();
            bankSSM = new BankEnclave() @ this;
            send bankSSM, TRUSTEDProvisionBankSSM, Endorse(clientUSM) as secure_machine_handle; //secure_send
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
        on TRUSTEDProvisionBankSSM do (payload: secure_machine_handle) {
            clientUSM = Declassify(payload) as machine_handle;
            clientSSM = new ClientEnclave() @ clientUSM;
            send clientSSM, TRUSTEDProvisionClientSSM, Endorse(clientUSM) as secure_machine_handle;
            goto RegisterNewBankAccount;
            
        }
    }

    state RegisterNewBankAccount {
        on UNTRUSTEDReceiveRegistrationCredentials do (payload: StringType) {
            print "Bank: Creating new bank account!";
            userCredential = Endorse(payload) as secure_StringType;
            masterSecret = GenerateRandomMasterSecret();
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
            if (Declassify(userCredential) as StringType == payload.usernamePW && Hash(Declassify(masterSecret) as StringType, Declassify(userCredential) as StringType) == payload.OTPCode) {
                print "Auth Success";
                send clientUSM, AuthSuccess; //untrusted_send
            } else {
                print "Auth Failure";
                send clientUSM, AuthFailure; //untrusted_send
            }
            // EXIT();
            goto AuthCheck;
        }

    }
}
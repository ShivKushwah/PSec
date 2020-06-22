machine UntrustedInitializer {
    var handler: machine_handle;
    start state Initial {
        entry {
            handler = new TrustedInitializer() @ this;
        }
    }
}

machine TrustedInitializer {
    
    var clientUSM: machine_handle;
    var bankSSM: machine_handle;
    start state Initial {
        entry {
            clientUSM = new ClientWebBrowser();
            bankSSM = new BankEnclave() @ this;
            unencrypted_send bankSSM, TRUSTEDProvisionBankSSM, clientUSM;
            unencrypted_send clientUSM, BankPublicIDEvent, bankSSM;
        }
    }
}

machine BankEnclave {
    var clientSSM: machine_handle;
    var clientUSM: machine_handle;
    var masterSecret : StringType;
    var userCredential : StringType;
    start state Initial {
        entry { 
            goto ReceiveClientUSM;
        } 
    }

    state ReceiveClientUSM {
        on TRUSTEDProvisionBankSSM do (payload: machine_handle) {
            clientUSM = payload;
            clientSSM = new ClientEnclave() @ clientUSM;
            unencrypted_send clientSSM, TRUSTEDProvisionClientSSM, clientUSM;
            goto RegisterNewBankAccount;
            
        }
    }

    state RegisterNewBankAccount {
        on UNTRUSTEDReceiveRegistrationCredentials do (payload: StringType) {
            print "Bank: Creating new bank account!";
            userCredential = payload;
            masterSecret = GenerateRandomMasterSecret();
            unencrypted_send clientSSM, MasterSecretEvent, masterSecret; //unencrypted_send
            unencrypted_send clientUSM, PublicIDEvent, clientSSM; //untrusted_unencrypted_send
            goto AuthCheck;

        }
    }

    state AuthCheck {
       on AuthenticateRequest goto Verify;
    }

    state Verify { 
        entry (payload : (usernamePW: StringType, OTPCode: StringType)) {
            if (userCredential == payload.usernamePW && Hash(masterSecret, userCredential) == payload.OTPCode) {
                print "Auth Success";
                unencrypted_send clientUSM, AuthSuccess; //untrusted_unencrypted_send
            } else {
                print "Auth Failure";
                unencrypted_send clientUSM, AuthFailure; //untrusted_unencrypted_send
            }
            
            goto AuthCheck;
        }

    }
}
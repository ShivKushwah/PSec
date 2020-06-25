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
            goto RegisterNewBankAccount;
        } 
    }

    state RegisterNewBankAccount {
        on UNTRUSTEDReceiveRegistrationCredentials do (payload: (machine_handle, StringType)) {
            print "Bank: Creating new bank account!";

            clientUSM = payload.0;
            userCredential = Endorse(payload.1) as secure_StringType;
            masterSecret = GenerateRandomMasterSecret();

            clientSSM = new ClientEnclave() @ clientUSM;
            send clientSSM, TRUSTEDProvisionClientSSM, Endorse(clientUSM) as secure_machine_handle; //secure_send
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
machine UntrustedInitializer {
    var handler: machine_handle;
    start state Initial {
        entry {
            handler = new TrustedInitializer();
        }
    }
}

secure_machine TrustedInitializer {
    
    var clientUSM: machine_handle; //TODO make a differentition between secure_machine and machine
    var bankSSM: machine_handle;
    start state Initial {
        entry {
            clientUSM = new ClientWebBrowser();
            bankSSM = new BankEnclave(clientUSM);
            untrusted_send clientUSM, BankPublicIDEvent, bankSSM;
        }
    }
}

secure_machine BankEnclave {
    var clientSSM: StringType;//TODO why is type checking disabled for StringType vs machine_handle
    var clientUSM: machine_handle;
    var masterSecret : StringType;
    var userCredential : StringType;
    start state Initial {
        entry (payload: machine_handle) { 
            clientUSM = payload;
            clientSSM = new ClientEnclave(clientUSM);

            print "Bank: Creating New Bank Account. Enter Credentials below!";
            userCredential = GetUserInput();
            
            masterSecret = GenerateRandomMasterSecret();

            secure_send clientSSM, MasterSecretEvent, masterSecret;
            // print "Bank Enclave about to print clientSSM";
            // PrintKey(clientSSM);
            untrusted_send clientUSM, PublicIDEvent, clientSSM;
            goto AuthCheck;
        } 
    }

    state AuthCheck {
       on AuthenticateRequest goto Verify;
    }

    state Verify { 
        entry (payload : (StringType, StringType)) {
            if (userCredential == payload.0 && Hash(masterSecret, userCredential) == payload.1) {
                untrusted_send clientUSM, AuthSuccess;
            } else {
                untrusted_send clientUSM, AuthFailure;
            }
            
            goto AuthCheck;
        }

    }
}
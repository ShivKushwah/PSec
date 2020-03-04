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
    var bankSSM: secure_machine_handle;
    start state Initial {
        entry {
            clientUSM = new ClientWebBrowser();
            print "created new client USM with key";
            PrintKey(clientUSM);
            bankSSM = new BankEnclave(clientUSM);
            send clientUSM, BankPublicIDEvent, bankSSM as machine_handle; //untrusted_send
        }
    }
}

secure_machine BankEnclave {
    var clientSSM: secure_machine_handle;//TODO why is type checking disabled for StringType vs machine_handle
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

            send clientSSM, MasterSecretEvent, masterSecret; //secure_send
            // print "Bank Enclave about to print clientSSM";
            // PrintKey(clientSSM);
            send clientUSM, PublicIDEvent, clientSSM as machine_handle; //untrusted_send
            goto AuthCheck;
        } 
    }

    state AuthCheck {
       on AuthenticateRequest goto Verify;
    }

    state Verify { 
        entry (payload : (StringType, StringType)) {
            if (userCredential == payload.0 && Hash(masterSecret, userCredential) == payload.1) {
                send clientUSM, AuthSuccess; //untrusted_send
            } else {
                send clientUSM, AuthFailure; //untrusted_send
            }
            
            goto AuthCheck;
        }

    }
}
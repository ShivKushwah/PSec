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
            print "created new client USM with key";
            PrintKey(clientUSM);
            bankSSM = new BankEnclave();
            send bankSSM, TRUSTEDProvisionBankSSM, clientUSM; //secure_send
            send clientUSM, BankPublicIDEvent, bankSSM as machine_handle; //untrusted_send
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
            send clientSSM, TRUSTEDProvisionClientSSM, clientUSM;

            print "Bank: Creating New Bank Account. Enter Credentials below!";
            userCredential = GetUserInput();
            print "KIRAT-CRED";
            // PrintString(userCredential);
            PrintRawSecureStringType(userCredential);
            
            masterSecret = GenerateRandomMasterSecret();
            print "Stuff";
            PrintRawSecureStringType(masterSecret);
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
        entry (payload : (usernamePW: StringType, OTPCode: StringType)) {
            print "KIRAT2-CRED";
            PrintString(payload.usernamePW);
            PrintRawSecureStringType(userCredential);
            PrintRawStringType(Hash(masterSecret as StringType, userCredential as StringType));
            if (userCredential as StringType == payload.usernamePW) {
                print "YEETKIRAT";
            }
            if (Hash(masterSecret as StringType, userCredential as StringType) == payload.OTPCode) {
                print "YEETKIRAT2";
            }
            if (userCredential as StringType == payload.usernamePW && Hash(masterSecret as StringType, userCredential as StringType) == payload.OTPCode) {
                send clientUSM, AuthSuccess; //untrusted_send
            } else {
                send clientUSM, AuthFailure; //untrusted_send
            }
            
            goto AuthCheck;
        }

    }
}
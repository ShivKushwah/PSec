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
    var registeredCredentials : map[secure_StringType, secure_StringType];
    var credentialToMasterSecretMap : map[secure_StringType, secure_StringType];

    start state Initial {
        entry { 
            goto RegisterNewBankAccount;
        } 
    }

    state RegisterNewBankAccount {
        on UNTRUSTEDReceiveRegistrationCredentials do (payload: (machine_handle, StringType, StringType)) {
            var masterSecret : secure_StringType;
            var username : secure_StringType;  
            var password : secure_StringType;      
            
            clientUSM = payload.0;
            username = Endorse(payload.1) as secure_StringType;
            password = Endorse(payload.2) as secure_StringType;
            masterSecret = GenerateRandomMasterSecret();
            registeredCredentials[username] = password;
            credentialToMasterSecretMap[username] = masterSecret;

            print "Bank: Creating new bank account!";

            clientSSM = new ClientEnclave() @ clientUSM;
            send clientSSM, TRUSTEDProvisionClientSSM, Endorse(clientUSM) as secure_machine_handle; //secure_send
            send clientSSM, MasterSecretEvent, masterSecret; //secure_send
            send clientUSM, PublicIDEvent, Declassify(clientSSM) as machine_handle; //untrusted_send
        }

        on UNTRUSTEDAuthenticateRequest do (payload : (Username: StringType, Password: StringType, OTPCode: StringType)) {
            var masterSecret : secure_StringType;
            var inputUsername : secure_StringType; 
            var inputPassword : secure_StringType;
            inputUsername = Endorse(payload.Username) as secure_StringType;
            inputPassword = Endorse(payload.Password) as secure_StringType;
            masterSecret = credentialToMasterSecretMap[inputUsername];

            // Declassify(userCredential in registeredCredentials) as bool && 
        
            if ((Declassify(registeredCredentials[inputUsername]) as StringType == Declassify(inputPassword) as StringType) && Hash(Declassify(masterSecret) as StringType, Declassify(inputPassword) as StringType) == payload.OTPCode) {
                print "Auth Success";
                send clientUSM, AuthSuccess; //untrusted_send
            } else {
                print "Auth Failure";
                send clientUSM, AuthFailure; //untrusted_send
            }

            
            // if (Declassify(userCredential) as StringType == payload.usernamePW && Hash(Declassify(masterSecret) as StringType, Declassify(userCredential) as StringType) == payload.OTPCode) {
            //     print "Auth Success";
            //     send clientUSM, AuthSuccess; //untrusted_send
            // } else {
            //     print "Auth Failure";
            //     send clientUSM, AuthFailure; //untrusted_send
            // }
            // EXIT();
        }

    }
}
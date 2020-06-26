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
            unencrypted_send clientUSM, BankPublicIDEvent, bankSSM;
        }
    }
}

machine BankEnclave {
    var clientSSM: machine_handle;
    var clientUSM: machine_handle;
    var registeredCredentials : map[StringType, StringType];
    var credentialToMasterSecretMap : map[StringType, StringType];

    start state Initial {
        entry { 
            goto RegisterNewBankAccount;
        } 
    }

    state RegisterNewBankAccount {
        on UNTRUSTEDReceiveRegistrationCredentials do (payload: (machine_handle, StringType, StringType)) {
            var masterSecret : StringType;
            var username : StringType;  
            var password : StringType;      

            clientUSM = payload.0;
            username = payload.1;
            password = payload.2;
            masterSecret = GenerateRandomMasterSecret();
            registeredCredentials[username] = password;
            credentialToMasterSecretMap[username] = masterSecret;

            print "Bank: Creating new bank account!";

            clientSSM = new ClientEnclave() @ clientUSM;
            unencrypted_send clientSSM, TRUSTEDProvisionClientSSM, clientUSM; //unencrypted_send
            unencrypted_send clientSSM, MasterSecretEvent, masterSecret; //unencrypted_send
            unencrypted_send clientUSM, PublicIDEvent, clientSSM; //unencrypted_send
        }

        on UNTRUSTEDAuthenticateRequest do (payload : (Username: StringType, Password: StringType, OTPCode: StringType)) {
            var masterSecret : StringType;
            var inputUsername : StringType; 
            var inputPassword : StringType;
            inputUsername = payload.Username;
            inputPassword = payload.Password;
            masterSecret = credentialToMasterSecretMap[inputUsername];

            //userCredential == payload.usernamePW

            if ((registeredCredentials[inputUsername] == inputPassword) && Hash(masterSecret, inputPassword) == payload.OTPCode) {
                print "Auth Success";
                unencrypted_send clientUSM, AuthSuccess; //untrusted_unencrypted_send
            } else {
                print "Auth Failure";
                unencrypted_send clientUSM, AuthFailure; //untrusted_unencrypted_send
            }
            // EXIT();
        }
    }

}
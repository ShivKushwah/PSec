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
    var registeredCredentials : seq[StringType];
    var credentialToMasterSecretMap : map[StringType, StringType];

    start state Initial {
        entry { 
            goto RegisterNewBankAccount;
        } 
    }

    state RegisterNewBankAccount {
        on UNTRUSTEDReceiveRegistrationCredentials do (payload: (machine_handle, StringType)) {
            var masterSecret : StringType;
            var userCredential : StringType;

            clientUSM = payload.0;
            userCredential = payload.1;
            masterSecret = GenerateRandomMasterSecret();
            registeredCredentials += (sizeof(registeredCredentials), userCredential);
            credentialToMasterSecretMap[userCredential] = masterSecret;

            print "Bank: Creating new bank account!";

            clientSSM = new ClientEnclave() @ clientUSM;
            unencrypted_send clientSSM, TRUSTEDProvisionClientSSM, clientUSM; //unencrypted_send
            unencrypted_send clientSSM, MasterSecretEvent, masterSecret; //unencrypted_send
            unencrypted_send clientUSM, PublicIDEvent, clientSSM; //unencrypted_send
        }

        on UNTRUSTEDAuthenticateRequest do (payload : (usernamePW: StringType, OTPCode: StringType)) {
            var masterSecret : StringType;
            var userCredential : StringType; 
            userCredential = payload.usernamePW;
            masterSecret = credentialToMasterSecretMap[userCredential];

            //userCredential == payload.usernamePW

            if (Hash(masterSecret, userCredential) == payload.OTPCode) {
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
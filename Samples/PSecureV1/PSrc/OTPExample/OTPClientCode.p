secure_machine ClientEnclave {
    var masterSecret: secure_StringType;
    var clientUSM : machine_handle;
    var result: map[int, int];
    start state Initial {
        defer GenerateOTPCodeEvent;
        on TRUSTEDProvisionClientSSM do (payload : machine_handle) {
            clientUSM = payload;
            goto ReceiveMasterSecretEvent;
        }
    }

    state ReceiveMasterSecretEvent {
        defer GenerateOTPCodeEvent;
        on MasterSecretEvent goto ProvisionEnclaveWithSecret;
    }

    state ProvisionEnclaveWithSecret {
        entry (payload : secure_StringType){
            masterSecret = payload;
            goto WaitForGenerateOTP;
        }
    }

    state WaitForGenerateOTP {
        on GenerateOTPCodeEvent do (usernamePassword: StringType) {
            var hashedString : StringType;
            var masterSecretDeclassifed : StringType;
            print "debug-1 bro";
            print "yellokirat2";
            PrintString(masterSecret);
            masterSecretDeclassifed = masterSecret as StringType;
            print "debug0 bro";
            hashedString = Hash(masterSecretDeclassifed, usernamePassword);
            print "debug bro";

            send clientUSM, OTPCodeEvent, hashedString; //untrusted_send
            print "debug2 bro";
        }
    }

}

machine ClientWebBrowser {
    var clientSSM: machine_handle;
    var bankSSM: machine_handle;
    var usernamePassword: StringType;
    var OTPCode: StringType;
    start state Initial {
        defer PublicIDEvent;
        on BankPublicIDEvent goto SaveBankSSM;
    }

    state SaveBankSSM {
        entry (payload: machine_handle) {
            bankSSM = payload;
        }
        on PublicIDEvent goto Authenticate;
    }
    
    state Authenticate {
        entry (payload: machine_handle) {
            clientSSM = payload;
            print "Client Web Browser: Enter Credentials to login to bank!\n";
            usernamePassword = GetUserInput();
            goto RequestOTPCodeGeneration;
        }
    }

    state RequestOTPCodeGeneration {
        entry {
            send clientSSM, GenerateOTPCodeEvent, usernamePassword; //untrusted_send
            receive {
                case OTPCodeEvent : (payload : StringType) {
                    goto SaveOTPCode, payload;
                }
            }
        }
    }

    state SaveOTPCode {
        entry (payload : StringType) {
            //print "OTP Code Received: {0}\n", payload;
            print "OTP Code Received:\n";
            // PrintString(payload); //TODO undo comment this out
            OTPCode = payload;
            goto ValidateOTPCode;
        }

    }

    state ValidateOTPCode {
        entry {
            send bankSSM, AuthenticateRequest, (usernamePassword, OTPCode); //untrusted_send
            receive {
                case AuthSuccess : {
                    goto Done;
                }
                case AuthFailure : {
                    print "Authentication Failed!";
                    print "Client Web Browser: Reenter Credentials to login!";
                    usernamePassword = GetUserInput();
                    goto RequestOTPCodeGeneration;
                }
            }
        }
        
    }

    state Done {
        entry {
            print "Client Web Browser Authenticated Successfully!";
        }
     }

}
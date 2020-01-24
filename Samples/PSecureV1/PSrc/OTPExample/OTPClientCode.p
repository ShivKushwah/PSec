secure_machine ClientEnclave {
    var masterSecret: StringType;
    var clientUSM : machine_handle;
    var result: map[int, int];
    start state Initial {
        defer GenerateOTPCodeEvent;
        entry (payload: machine_handle) {
            clientUSM = payload;
        }
        on MasterSecretEvent goto ProvisionEnclaveWithSecret;
    }

    state ProvisionEnclaveWithSecret {
        entry (payload : StringType){
            masterSecret = payload;
            goto WaitForGenerateOTP;
        }
    }

    state WaitForGenerateOTP {
        on GenerateOTPCodeEvent do (usernamePassword: StringType) {
            untrusted_send clientUSM, OTPCodeEvent, Hash(masterSecret, usernamePassword);
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
            untrusted_send clientSSM, GenerateOTPCodeEvent, usernamePassword;
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
            PrintString(payload);
            OTPCode = payload;
            goto ValidateOTPCode;
        }

    }

    state ValidateOTPCode {
        entry {
            untrusted_send bankSSM, AuthenticateRequest, (usernamePassword, OTPCode);
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
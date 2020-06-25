machine ClientEnclave {
    var masterSecret: StringType;
    var clientUSM : machine_handle;
    
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
        entry (payload : StringType){
            masterSecret = payload;
            goto WaitForGenerateOTP;
        }
    }

    state WaitForGenerateOTP {
        on GenerateOTPCodeEvent do (usernamePassword: StringType) {
            var hashedString : StringType;          
            hashedString = Hash(masterSecret, usernamePassword);
            unencrypted_send clientUSM, OTPCodeEvent, hashedString; //untrusted_unencrypted_send
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
            goto RegisterAccountInBank;
        }
    }

    state RegisterAccountInBank {
        entry {
            var credentials : StringType;
            
            print "MEASURE OTPBASELINE START:";
            MeasureTime();
            
            credentials = GetUserInput();
            unencrypted_send bankSSM, UNTRUSTEDReceiveRegistrationCredentials, credentials;
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
            var machineTypeToValidate : string;
            machineTypeToValidate = "ClientEnclave";
            // if (localAuthenticate(clientSSM, machineTypeToValidate)) {
            //     print "Authenticated installed enclave!";
            // }
            unencrypted_send clientSSM, GenerateOTPCodeEvent, usernamePassword; //untrusted_unencrypted_send
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
            unencrypted_send bankSSM, AuthenticateRequest, (usernamePW = usernamePassword, OTPCode = OTPCode); //untrusted_unencrypted_send
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
            print "Client Web Browser Authenticated Successfully!\n";
            print "MEASURE OTPBASELINE END:";
            MeasureTime();
            EXIT();
        }
     }

}
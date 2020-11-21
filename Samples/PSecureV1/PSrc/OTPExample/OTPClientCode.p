secure_machine ClientEnclave {
    var masterSecret: secure_StringType;
    var clientUSM : machine_handle;
    
    start state Initial {
        defer GenerateOTPCodeEvent;
        on TRUSTEDProvisionClientSSM do (payload : secure_machine_handle) {
            clientUSM = Declassify(payload) as machine_handle;
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
        on GenerateOTPCodeEvent do (password: StringType) {
            var hashedString : StringType;
            hashedString = Hash(Declassify(masterSecret) as StringType, password);
            send clientUSM, OTPCodeEvent, hashedString; //untrusted_send
        }
    }

}

machine ClientWebBrowser {
    var clientSSM: machine_handle;
    var bankSSM: machine_handle;
    var username: StringType;
    var password: StringType;
    var OTPCode: StringType;
    var numCodesGenerated: int;

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
            // print "MEASURE BASELINE START:";
            // MeasureTime();

            username = GetUsernameInput();
            password = GetPasswordInput();
            send bankSSM, UNTRUSTEDReceiveRegistrationCredentials, (this, username, password);
        }
        on PublicIDEvent goto Authenticate;
    }
    
    state Authenticate {
        entry (payload: machine_handle) {
            print "MEASURE BASELINE START:";
            MeasureTime();

            numCodesGenerated = 0;
            
            clientSSM = payload;
            print "Client Web Browser: Enter Credentials to login to bank!\n";
            goto CheckEnclave;
        }
    }

    state CheckEnclave {
        entry {
            var machineTypeToValidate : string;
            machineTypeToValidate = "ClientEnclave";
            if (localAuthenticate(clientSSM, machineTypeToValidate)) {
                print "Authenticated installed enclave!";
            }
            goto RequestOTPCodeGeneration;
        }
    }

    state RequestOTPCodeGeneration {
        entry {
            send clientSSM, GenerateOTPCodeEvent, password; //untrusted_send
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
            send bankSSM, UNTRUSTEDAuthenticateRequest, (Username = username, Password = password, OTPCode = OTPCode); //untrusted_send
            receive {
                case AuthSuccess : {
                    if (numCodesGenerated > 5) {
                        goto Done;
                    }
                    numCodesGenerated = numCodesGenerated + 1;
                    goto RequestOTPCodeGeneration;
                }
                case AuthFailure : {
                    print "Authentication Failed!";
                    print "Client Web Browser: Reenter Credentials to login!";
                    username = GetUsernameInput();
                    password = GetPasswordInput();
                    goto RequestOTPCodeGeneration;
                }
            }
        }
        
    }

    state Done {
        entry {
            print "Client Web Browser Authenticated Successfully!\n";
            print "MEASURE BASELINE END:";
            MeasureTime();
            EXIT();
        }
     }

}
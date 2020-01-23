type StringType;
type machine_handle;

fun CreateMachineSecureChild(): machine_handle;
fun PrintString(inputString : StringType);
fun SecureSend(sendingToMachine : machine_handle, eventToSend : event, numArgs : int, arg : int);
fun GetThis() : machine_handle;
fun Concat(input1:StringType, input2:StringType) : StringType;
fun Hash(input1:StringType, input2:StringType) : StringType;
fun UntrustedCreateCoordinator();
fun UntrustedSend(publicID: machine_handle, even : event, payload: int);
fun InitializeUntrustedMachine();
fun CreateSecureMachineRequest(): machine_handle;
fun CreateUSMMachineRequest(): machine_handle;
fun PrintKey(input : machine_handle);
fun GetStringFromUser() : StringType;
fun GenerateRandomMasterSecret() : StringType;

event BankPublicIDEvent : machine_handle;
event PublicIDEvent : machine_handle;
trusted event MasterSecretEvent: StringType;
event GenerateOTPCodeEvent : StringType;
event OTPCodeEvent : StringType;
trusted event MapEvent: map[int, int];
event AuthenticateRequest : (StringType, StringType);
event AuthSuccess;
event AuthFailure;

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
    start state Initial {
        entry (payload: machine_handle) { 
            clientUSM = payload;
            clientSSM = new ClientEnclave(clientUSM);
            
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
            untrusted_send clientUSM, AuthSuccess;
            goto AuthCheck;
        }

    }
}

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
            //untrusted_send clientUSM, OTPCodeEvent, usernamePassword + masterSecret;

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
            usernamePassword = GetStringFromUser();

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
                    goto ValidateOTPCode;
                }
            }
        }
        
    }

    state Done {
        entry {
            print "Client Web Browswer Authenticated Successfully!";
        }
     }

}

// type StringType;
// type Str;

// event Ping assert 2;
// event Pong assert 2 : int;
// event UntrustedEventFromPing : int;
// fun CreateMachineSecureChild(): StringType;
// fun PrintString(inputString : StringType);
// fun SecureSend(sendingToMachine : StringType, eventToSend : event, numArgs : int, arg : int);
// fun GetThis() : StringType;
// fun Concat(input1:StringType, input2:StringType) : StringType;
// event Success;
// fun UntrustedCreateCoordinator();
// fun UntrustedSend(publicID: StringType, even : event, payload: int);
// fun InitializeUntrustedMachine();
// fun CreateSecureMachineRequest(): StringType;
// fun CreateUSMMachineRequest(): StringType;
// fun PrintKey(input : StringType);
// fun GetStringFromUser() : Str;
// fun PrintStr(inputStr : Str);

// event PublicIDEvent : StringType;
// trusted event MasterSecretEvent: (int, seq[StringType]);
// event GenerateOTPCodeEvent : StringType;
// event OTPCodeEvent : StringType;
// trusted event MapEvent: map[int, int];

// trusted event TestEvent: int;
// event TestEvent2: int;
// 
// machine GodUntrusted {
//     var handler: StringType;
//     start state Initial {
//         entry {
//             handler = new GodMachine();
//         }
//     }
// }

// secure_machine GodMachine {
//     var clientUSM: StringType;
//     var bankSSM: StringType;
//     start state Initial {
//         entry {
//             clientUSM = new ClientWebBrowser();
//             bankSSM = new BankEnclave(clientUSM);
//         }
//     }
// }

// secure_machine BankEnclave {
//     var clientSSM: StringType;
//     var clientUSM: StringType;
//     var result: (int, seq[StringType]);
//     var temp: seq[StringType];
//     start state Initial {
//         entry (payload: StringType) { 
//             clientUSM = payload;
//             clientSSM = new ClientEnclave(clientUSM);
//             temp += (sizeof(temp), GetThis());
//             result = (7, temp);

//             // PrintString(clientSSM);

//             secure_send clientSSM, MasterSecretEvent, result;
//             // PrintString(clientSSM);
//             print "Bank Enclave about to print clientSSM";
//             PrintKey(clientSSM);
//             untrusted_send clientUSM, PublicIDEvent, clientSSM;
//         } 
//     }
// }

// secure_machine ClientEnclave {
//     var masterSecret: StringType;
//     var clientUSM : StringType;
//     var result: map[int, int];
//     var testMachine: StringType;
//     start state Initial {
//         defer GenerateOTPCodeEvent;
//         entry (payload: StringType) {
//             clientUSM = payload;
//         }
//         on MasterSecretEvent goto ProvisionEnclaveWithSecret;
//     }

//     state ProvisionEnclaveWithSecret {
//         entry (payload : (int, seq[StringType])){
//             masterSecret = payload.1[0];
//             goto WaitForGenerateOTP;
//         }
//     }

//     state WaitForGenerateOTP {
//         entry {
//             print "HARHARHAR";
//         }
//         on GenerateOTPCodeEvent do (usernamePassword: StringType) {
//             //untrusted_send clientUSM, OTPCodeEvent, usernamePassword + masterSecret;
//             print "HIIII";
//             result[8] = 25;
//             testMachine = new TestMachine();
//             print "BYEEE";
//             // print "YELLO\n"; 
//             secure_send testMachine, MapEvent, result;
//             print "Harmina";
//             PrintString(Concat(usernamePassword, masterSecret));

//             untrusted_send clientUSM, OTPCodeEvent, Concat(usernamePassword, masterSecret);
//         }
//     }

// }

// machine ClientWebBrowser {
//     var clientSSM: StringType;
//     var usernamePassword: StringType;
//     start state Initial {
//         on PublicIDEvent goto Authenticate;
//     }
    
//     state Authenticate {
//         entry (payload: StringType) {
//             clientSSM = payload;
//             usernamePassword = GetThis();
//             // PrintString(clientSSM);
//             print "YEE AUTHENTICATE\n";
//             PrintKey(clientSSM);
//             untrusted_send clientSSM, GenerateOTPCodeEvent, usernamePassword;
//             receive {
//                 case OTPCodeEvent : (payload : StringType) {
//                     goto SaveOTPCode, payload;
//                 }
//             }
//         }
//     }

//     state SaveOTPCode {
//         entry (payload : StringType) {
//             //print "OTP Code Received: {0}\n", payload;
//             print "OTP Code Received:\n";
//             PrintString(payload);
//             goto Done;
//         }

//     }

//     state Done { }

// }

// secure_machine TestMachine {
//     start state Initial {
//         on MapEvent goto TestMap;
//     }
//     state TestMap {
//         entry (payload: map[int, int]) {
//             print "Map Value should be 25: {0}\n", payload[8];
//             goto Done;
//         }
//     }

//     state Done {
//         entry {
//             print "DONE BOYS";
//         }
//      }
// }
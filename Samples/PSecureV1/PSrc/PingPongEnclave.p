type StringType;

event Ping assert 2;
event Pong assert 2 : int;
event UntrustedEventFromPing : int;
fun CreateMachineSecureChild(): StringType;
fun PrintString(inputString : StringType);
fun SecureSend(sendingToMachine : StringType, eventToSend : event, numArgs : int, arg : int);
fun GetThis();
event Success;
fun UntrustedCreateCoordinator();
fun UntrustedSend(publicID: StringType, even : event, payload: int);
fun InitializeUntrustedMachine();
fun CreateSecureMachineRequest(): StringType;
fun CreateUSMMachineRequest(): StringType;

event PublicIDEvent : StringType;
trusted event MasterSecretEvent: map[int, int];
event GenerateOTPCodeEvent : int;
event OTPCodeEvent : int;

machine GodUntrusted {
    var handler: StringType;
    start state Initial {
        entry {
            handler = new GodMachine();
        }
    }
}

secure_machine GodMachine {
    var clientUSM: StringType;
    var bankSSM: StringType;
    start state Initial {
        entry {
            clientUSM = new ClientWebBrowser();
            bankSSM = new BankEnclave(clientUSM);
        }
    }
}

secure_machine BankEnclave {
    var clientSSM: StringType;
    var clientUSM: StringType;
    var result: map[int, int];
    start state Initial {
        entry (payload: StringType) { 
            clientUSM = payload;
            clientSSM = new ClientEnclave(clientUSM);
            result[3] = 7;

            // PrintString(clientSSM);

            secure_send clientSSM, MasterSecretEvent, result;
            PrintString(clientSSM);
            untrusted_send clientUSM, PublicIDEvent, clientSSM;
        } 
    }
}

secure_machine ClientEnclave {
    var masterSecret: int;
    var clientUSM : StringType;
    var result: map[int, int];
    start state Initial {
        defer GenerateOTPCodeEvent;
        entry (payload: StringType) {
            clientUSM = payload;
        }
        on MasterSecretEvent goto ProvisionEnclaveWithSecret;
    }

    state ProvisionEnclaveWithSecret {
        entry (payload : map[int, int]){
            masterSecret = payload[3];
            goto WaitForGenerateOTP;
        }
    }

    state WaitForGenerateOTP {
        on GenerateOTPCodeEvent do (usernamePassword: int) {
            untrusted_send clientUSM, OTPCodeEvent, usernamePassword + masterSecret;
            result[3] = masterSecret;
        }
    }

}

machine ClientWebBrowser {
    var clientSSM: StringType;
    var usernamePassword: int;
    start state Initial {
        on PublicIDEvent goto Authenticate;
    }
    
    state Authenticate {
        entry (payload: StringType) {
            clientSSM = payload;
            usernamePassword = 10;
            // PrintString(clientSSM);
            untrusted_send clientSSM, GenerateOTPCodeEvent, usernamePassword;
            receive {
                case OTPCodeEvent : (payload : int) {
                    goto SaveOTPCode, payload;
                }
            }
        }
    }

    state SaveOTPCode {
        entry (payload : int) {
            print "OTP Code Received: {0}\n", payload;
            goto Done;
        }

    }

    state Done { }

}
type StringType;

event Pong assert 2 : int;
event UntrustedEventFromPing : int;
fun CreateMachineSecureChild(): StringType;
fun PrintString(inputString : StringType);
fun SecureSend(sendingToMachine : StringType, eventToSend : event, numArgs : int, arg : int);
fun GetThis() : StringType;
fun Concat(input1:StringType, input2:StringType) : StringType;
event Success;
fun UntrustedCreateCoordinator();
fun UntrustedSend(publicID: StringType, even : event, payload: int);
fun InitializeUntrustedMachine();
fun CreateSecureMachineRequest(): StringType;
fun CreateUSMMachineRequest(): StringType;

event PublicIDEvent : StringType;
trusted event MasterSecretEvent: (int, seq[StringType]);
event GenerateOTPCodeEvent : StringType;
event OTPCodeEvent : StringType;
trusted event MapEvent: map[int, int];

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
    var result: (int, seq[StringType]);
    var temp: seq[StringType];
    start state Initial {
        entry (payload: StringType) { 
            clientUSM = payload;
            clientSSM = new ClientEnclave(clientUSM);
            temp += (sizeof(temp), GetThis());
            result = (7, temp);

            // PrintString(clientSSM);

            secure_send clientSSM, MasterSecretEvent, result;
            PrintString(clientSSM);
            untrusted_send clientUSM, PublicIDEvent, clientSSM;
        } 
    }
}

secure_machine ClientEnclave {
    var masterSecret: StringType;
    var clientUSM : StringType;
    var result: map[int, int];
    var testMachine: StringType;
    start state Initial {
        defer GenerateOTPCodeEvent;
        entry (payload: StringType) {
            clientUSM = payload;
        }
        on MasterSecretEvent goto ProvisionEnclaveWithSecret;
    }

    state ProvisionEnclaveWithSecret {
        entry (payload : (int, seq[StringType])){
            masterSecret = payload.1[0];
            goto WaitForGenerateOTP;
        }
    }

    state WaitForGenerateOTP {
        on GenerateOTPCodeEvent do (usernamePassword: StringType) {
            //untrusted_send clientUSM, OTPCodeEvent, usernamePassword + masterSecret;
            result[8] = 25;
            testMachine = new TestMachine();
            secure_send testMachine, MapEvent, result;

            untrusted_send clientUSM, OTPCodeEvent, Concat(usernamePassword, masterSecret);
        }
    }

}

machine ClientWebBrowser {
    var clientSSM: StringType;
    var usernamePassword: StringType;
    start state Initial {
        on PublicIDEvent goto Authenticate;
    }
    
    state Authenticate {
        entry (payload: StringType) {
            clientSSM = payload;
            usernamePassword = GetThis();
            // PrintString(clientSSM);
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
            goto Done;
        }

    }

    state Done { }

}

secure_machine TestMachine {
    start state Initial {
        on MapEvent goto TestMap;
    }
    state TestMap {
        entry (payload: map[int, int]) {
            print "Map Value should be 25: {0}\n", payload[8];
            goto Done;
        }
    }

    state Done {
        entry {
            print "DONE BOYS";
        }
     }
}
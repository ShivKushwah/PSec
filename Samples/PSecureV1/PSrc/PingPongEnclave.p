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

machine GodUntrusted {
    var handler: StringType;
    start state Initial {
        entry {
            handler = new GodMachine();
        }
    }
}

secure_machine GodMachine {

    start state Initial {
        entry {
             
        }
    }

}

secure_machine BankEnclave {

    start state Initial {
        entry { 
            
        } 
    }

}

secure_machine ClientEnclave {
    start state Initial {
        entry {
        
        }

    }

}

machine ClientWebBrowser {

    start state Ping_Init {
        entry {
            
        }
    }

}

machine ServerHost {
    start state Init {


    }

}
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

secure_machine Coordinator {
    var PongSecureChild: StringType;


    start state Initial {
        entry {
             PongSecureChild = new Pong();
             PongSecureChild = new Temp();
        }
        on UntrustedEventFromPing goto Whoa;
    }

    state Whoa { 
        entry {
            print "WHOA";
        }
    }

}

secure_machine Pong {
    var secureChildRegular: StringType;
    var thisVar : StringType;

    start state Initial {
        entry { 
            thisVar = GetThis();
            
            secureChildRegular = new SecureChild(thisVar);
            PrintString(secureChildRegular);
            // SecureSend(secureChildRegular, Pong, 1, 7);
            // SecureSend(secureChildRegular, Pong, 1, 7);
            secure_send secureChildRegular, Pong, 3;
            // secure_send secureChildRegular, Pong, 3;

            
            // secure_send secureChildRegular, Pong;
            // secure_send secureChildRegular, Pong;
        } 
        on Ping goto Done; 
    }

    state Done { 
        entry {
            print "YOOOOO";
	    }

    }
}

secure_machine SecureChild {
    var parent : StringType;
    start state Initial {
        entry (payload: StringType) {
            // if (payload == 10) {
            //     print "HOORAY";
            // }
            parent = payload;
        }
        on Pong goto Next;

    }

    state Next {
        entry {
            secure_send parent, Ping;
            goto Done;
        }
    }

    state Done { }
}

machine Ping {
    var pongId: machine;
    var coordinatorID: StringType;
    var numArgs : int;
    var payld : int;

    start state Ping_Init {
        entry {
            InitializeUntrustedMachine();
            GetThis();
            pongId = new Temp();
            // send pongId, Pong, 4;
            coordinatorID = new Coordinator();// UntrustedCreateCoordinator();
            numArgs = 1;
            payld = 9;
            PrintString(coordinatorID);
            untrusted_send coordinatorID, UntrustedEventFromPing, payld;
            // UntrustedSend(coordinatorID, UntrustedEventFromPing, payld);
    	    raise Success;   	   
        }
        on Success goto Done;
    }

    state Done {  }

}

machine Temp {
    start state Init {

        on Pong goto Done;

    }

    state Done { }
}
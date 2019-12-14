type StringType;

event Ping assert 2;
event Pong assert 2 : int;
event UntrustedEventFromPing;

//fun SecureSendPingEventToPongEnclave();
fun UntrustedCreateCoordinator();
fun UntrustedSend(publicID: StringType, even : event, payload: int);
fun InitializeUntrustedMachine();
fun GetThis();
event Success;

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
            send pongId, Pong, 4;
            coordinatorID = UntrustedCreateCoordinator(); //Start up PrtTrusted in the Pong Enclave
            numArgs = 1;
            payld = 9;
            UntrustedSend(coordinatorID, UntrustedEventFromPing, payld);
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



// secure_machine Coordinator { }
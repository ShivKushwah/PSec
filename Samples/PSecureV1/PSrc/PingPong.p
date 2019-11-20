type StringType;

event Ping assert 2;
event Pong assert 2 : int;
//fun SecureSendPingEventToPongEnclave();
fun InitializePongEnclave();
fun UntrustedCreateCoordinator();
event Success;

machine Ping {
    var pongId: machine;
    var coordinatorID: StringType;

    start state Ping_Init {
        entry {
            pongId = new Temp();
            send pongId, Pong, 4;
            coordinatorID = UntrustedCreateCoordinator(); //Start up PrtTrusted in the Pong Enclave
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
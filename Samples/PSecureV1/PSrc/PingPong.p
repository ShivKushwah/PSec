event Ping assert 2;
event Pong assert 2;
fun SecureSendPingEventToPongEnclave();
fun InitializePongEnclave();
event Success;

machine Ping {
    var pongId: machine;

    start state Ping_Init {
        entry {
           pongId = new Temp();
            InitializePongEnclave(); //Start up PrtTrusted in the Pong Enclave
    	    raise Success;   	   
        }
        on Success goto Done;
    }

    state Done {  }

}

machine Temp {
    start state Init {

    }
}

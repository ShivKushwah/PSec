event Ping assert 2;
event Pong assert 2;
fun SecureSendPingEventToPongEnclave();
event Success;

machine Ping {
    var pongId: machine;

    start state Ping_Init {
        entry {
    	    raise Success;   	   
        }
        on Success goto Ping_SendingPing;
    }

    state Ping_SendingPing {
        entry {
            SecureSendPingEventToPongEnclave(); //Send Ping to the enclave's Pong machine
    	    raise Success;
	    }
        on Success goto Ping_WaitPong;
    }

    state Ping_WaitPong {
        on Pong goto Done; //Receives this message from the Pong machine in the enclave
    }

    state Done {  }

}

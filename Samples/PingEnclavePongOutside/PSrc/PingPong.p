//event Ping assert 1 : machine;
event Ping assert 2;
event Pong assert 2;
fun SecureSend();
event Success;

machine Ping {
    var pongId: machine;

    start state Ping_Init {
        entry {
            //pongId = new Pong();
    	    raise Success;   	   
        }
        on Success goto Ping_SendingPing;
    }

    state Ping_SendingPing {
        entry {
    	   //send pongId, Ping, this;
    	    raise Success;
	}
        on Success goto Ping_WaitPong;
     }

     state Ping_WaitPong {
        //idea make a foreigntypescall here to enclave.cpp to add the Pong event to the queue
        entry {
            SecureSend();
        }
        on Pong goto Done;
     }

    state Done {
        entry {
            raise Success;
        }
        on Success goto ReallyDone;
     }

     state ReallyDone {
     }


}

//event Ping assert 1 : machine;
event Ping assert 2;

event Pong assert 2;
fun SecureReceive();
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
            SecureReceive();
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

machine Pong {
    start state Pong_WaitPing {
        entry (payload: int) {
            // if (payload == 6) {
            //     print "Gurgy";
            // }
            // print "Kirat";
         }
        on Ping goto Pong_SendingPong;
    }

    state Pong_SendingPong {
	//entry (payload: machine) {
        entry {
	     //send payload, Pong;
	     raise Success;		 	  
	}
        on Success goto Done;
    }

    state Done { }
}

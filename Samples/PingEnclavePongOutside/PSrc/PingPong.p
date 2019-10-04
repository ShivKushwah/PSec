//event Ping assert 1 : machine;
event Ping assert 2;

event Pong assert 2;
event Success;

machine Ping {
    var pongId: machine;

    start state Ping_Init {
        entry {
        //entry (payload: machine) {
      	    //pongId = payload;
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
        on Pong goto Done;
     }

    state Done {
        entry {
            print "Kirat";
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

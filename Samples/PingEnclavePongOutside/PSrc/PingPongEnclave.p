//event Ping assert 1 : machine;
event Ping assert 2;

event Pong assert 2;
event Success;

//@secure
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

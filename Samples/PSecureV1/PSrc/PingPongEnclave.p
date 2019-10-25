event Ping assert 2;
event Pong assert 2;
fun SecureSendPongEventToPingMachine();
event Success;

//@secure
machine Pong {
    start state Pong_WaitPing {
        on Ping goto Pong_SendingPong; //Receives this event from the Ping Machine in App.cpp
    }

    state Pong_SendingPong {
        entry {
	        SecureSendPongEventToPingMachine(); //Send Pong to app.cpp's Ping machine
	        raise Success;		 	  
	    }
        on Success goto Done;
    }

    state Done { }
}

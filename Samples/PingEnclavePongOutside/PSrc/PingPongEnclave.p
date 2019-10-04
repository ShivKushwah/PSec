//event Ping assert 1 : machine;
event Ping assert 2;
event Pong assert 2;
fun SecureSend();
event Success;

//@secure
machine Pong {
    start state Pong_WaitPing {
        entry (payload: int) {

         }
        on Ping goto Pong_SendingPong;
    }

    state Pong_SendingPong {
	//entry (payload: machine) {
        entry {
	     SecureSend();
	     raise Success;		 	  
	}
        on Success goto Done;
    }

    state Done { }
}

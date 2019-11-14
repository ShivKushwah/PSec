type StringType;

event Ping assert 2;
event Pong assert 2;
fun CreateMachineSecureChild(): StringType;
fun PrintString(inputString : StringType);
fun SecureSend(sendingToMachine : StringType, eventToSend : event);
event Success;

secure_machine Coordinator {
    var PongSecureChild: StringType;

    start state Initial {
        entry {
            PongSecureChild = new Pong();
        }
    }

}

secure_machine Pong {
    var secureChildRegular: StringType;

    start state Initial {
        entry { 
            secureChildRegular = new SecureChild();
            PrintString(secureChildRegular);
            secure_send secureChildRegular, Pong;
            secure_send secureChildRegular, Pong;
        } 
        on Ping goto Pong_SendingPong; 
    }

    state Pong_SendingPong {
        entry {
	        raise Success;		 	  
	    }
        on Success goto Done;
    }

    state Done { }
}

secure_machine SecureChild {
    start state Initial {
        on Pong goto Next;

    }

    state Next {
        on Pong goto Done;
    }

    state Done { }
}
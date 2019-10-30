type StringType;

event Ping assert 2;
event Pong assert 2;
fun CreateMachineSecureChild(): StringType;
fun PrintString(inputString : StringType);
event Success;

//@secure
machine Pong {
    var secureChildPublicIDKey: StringType;

    start state Initial {
        entry { 
            secureChildPublicIDKey = CreateMachineSecureChild();
            PrintString(secureChildPublicIDKey);
            //Call SecureSendMessage() next;
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

//@secure
machine SecureChild {
    start state Initial {
        entry {
            //Take the Pong parent as a payload and secure send it a Ping Message
            raise Success;
        }
        on Success goto Done;

    }

    state Done { }
}
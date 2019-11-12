type StringType;

event Ping assert 2;
event Pong assert 2;
event even : StringType;
fun CreateMachineSecureChild(): StringType;
//fun CreateMachineSecureChild2(): machine;
fun PrintString(inputString : StringType);
fun SecureSend(sendingToMachine : StringType, eventToSend : event);
event Success;

//@secure
machine Pong {
    var secureChildPublicIDKey: StringType;
    var secureChildPublicIDKey2: StringType;
    var secureChildPublicIDKey3: StringType;
    var secureChildRegular: StringType;
    var secureChildRegular2: machine;
    var secureChildRegular3: machine;
    var kirat: machine;

    start state Initial {
        entry { 
            //secureChildPublicIDKey = CreateMachineSecureChild();
            //secureChildPublicIDKey2 = CreateMachineSecureChild();
            //secureChildPublicIDKey3 = CreateMachineSecureChild();
            //PrintString(secureChildPublicIDKey);
            //PrintString(secureChildPublicIDKey2);
            //PrintString(secureChildPublicIDKey3);
            secureChildRegular = new SecureChild();
            PrintString(secureChildRegular);
            //SecureSend(secureChildRegular, Pong);
            //SecureSend(secureChildRegular, Pong);
            // send kirat, even, secureChildRegular;
            //send kirat, even, secureChildRegular;
            secure_send secureChildRegular, Pong;
            secure_send secureChildRegular, Pong;


            //send machineVar, tempEvent;

            // secureChildRegular2 = new SecureChild();
            // secureChildRegular3 = new SecureChild();

            //secureChildRegular = CreateMachineSecureChild2();
            //secureChildRegular2 = CreateMachineSecureChild2();
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
        on Pong goto Next;

    }

    state Next {
        on Pong goto Done;
    }

    state Done { }
}
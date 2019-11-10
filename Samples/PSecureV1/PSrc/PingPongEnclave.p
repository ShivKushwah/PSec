type StringType;

event Ping assert 2;
event Pong assert 2;
fun CreateMachineSecureChild(): StringType;
//fun CreateMachineSecureChild2(): machine;
fun PrintString(inputString : StringType);
event Success;

//@secure
machine Pong {
    var secureChildPublicIDKey: StringType;
    var secureChildPublicIDKey2: StringType;
    var secureChildPublicIDKey3: StringType;
    var secureChildRegular: StringType;
    var secureChildRegular2: machine;
    var secureChildRegular3: machine;



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
        entry {
            //Take the Pong parent as a payload and secure send it a Ping Message
            raise Success;
        }
        on Success goto Done;

    }

    state Done { }
}
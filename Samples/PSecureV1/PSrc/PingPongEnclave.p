type StringType;

event Ping assert 2;
event Pong assert 2;
fun SecureSendPongEventToPingMachine();
fun CreateMachineSecureChild(): int; //have this return a string
fun GetDefaultString() : StringType;
fun ReadString(inputString : StringType);
event Success;

//@secure
machine Pong {
    var secureChildID: int;
    var tempString: StringType;

    start state Pong_WaitPing {
        entry {
            tempString = GetDefaultString();
           // print "Temp String is";
            //print "{0}: success!", tempString; 
            ReadString(tempString);
            
            secureChildID = CreateMachineSecureChild();
            //Call SecureSendMessage();
        }
        on Ping goto Pong_SendingPong; //Receives this event from the Ping Machine in App.cpp
    }

    state Pong_SendingPong {
        entry {
	        //SecureSendPongEventToPingMachine(); //Send Pong to app.cpp's Ping machine
	        raise Success;		 	  
	    }
        on Success goto Done;
    }

    state Done { }
}

//@secure
machine SecureChild {
    start state Pong_WaitPing {
        on Ping goto Pong_SendingPong; //Receives this event from the Ping Machine in App.cpp
    }

    state Pong_SendingPong {
        entry {
	        //SecureSendPongEventToPingMachine(); //Send Pong to app.cpp's Ping machine
	        raise Success;		 	  
	    }
        on Success goto Done;
    }

    state Done { }
}
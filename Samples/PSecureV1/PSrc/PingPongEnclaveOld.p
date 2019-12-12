//-----------------------
type StringType;

event Ping assert 2;
event Pong assert 2 : int;
event UntrustedEventFromPing;
fun CreateMachineSecureChild(): StringType;
fun PrintString(inputString : StringType);
fun SecureSend(sendingToMachine : StringType, eventToSend : event, numArgs : int, arg : int);
fun GetThis();
event Success;

secure_machine Coordinator {
    var PongSecureChild: StringType;


    start state Initial {
        entry {
             PongSecureChild = new Pong();
        }
        on UntrustedEventFromPing goto Whoa;
    }

    state Whoa { 
        entry {
            print "WHOA";
        }
    }

}

secure_machine Pong {
    var secureChildRegular: StringType;
    var thisVar : StringType;

    start state Initial {
        entry { 
            thisVar = GetThis();
            
            secureChildRegular = new SecureChild(thisVar);
            PrintString(secureChildRegular);
            // SecureSend(secureChildRegular, Pong, 1, 7);
            // SecureSend(secureChildRegular, Pong, 1, 7);
            secure_send secureChildRegular, Pong, 3;
            // secure_send secureChildRegular, Pong, 3;

            
            // secure_send secureChildRegular, Pong;
            // secure_send secureChildRegular, Pong;
        } 
        on Ping goto Done; 
    }

    state Done { 
        entry {
            print "YOOOOO";
	    }

    }
}

secure_machine SecureChild {
    var parent : StringType;
    start state Initial {
        entry (payload: StringType) {
            // if (payload == 10) {
            //     print "HOORAY";
            // }
            parent = payload;
        }
        on Pong goto Next;

    }

    state Next {
        entry {
            secure_send parent, Ping;
            goto Done;
        }
    }

    state Done { }
}
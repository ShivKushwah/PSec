type StringType;

event Ping assert 2;
event Pong assert 2 : int;
fun CreateMachineSecureChild(): StringType;
fun PrintString(inputString : StringType);
fun SecureSend(sendingToMachine : StringType, eventToSend : event, numArgs : int, arg : int);
event Success;

secure_machine Coordinator {
    var PongSecureChild: StringType;
    var sidhu : int;
    var har : secure_int;
    var b : bool;
    var bb : secure_bool;


    start state Initial {
        entry {
            var kirat : secure_int;

            PongSecureChild = new Pong();
            
        }
    }

}

secure_machine Pong {
    var secureChildRegular: StringType;
    var sBool : secure_bool;

    start state Initial {
        entry { 
            var kirat : secure_int;
            kirat = 7 + 5;
            
            secureChildRegular = new SecureChild();
            PrintString(secureChildRegular);
            // SecureSend(secureChildRegular, Pong, 1, 7);
            // SecureSend(secureChildRegular, Pong, 1, 7);
            secure_send secureChildRegular, Pong, 3;
            secure_send secureChildRegular, Pong, 3;

            
            // secure_send secureChildRegular, Pong;
            // secure_send secureChildRegular, Pong;

            // if (sBool) {
            //     secure_send secureChildRegular, Pong;
            //     secure_send secureChildRegular, Pong;
            // }
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


//             kirat = (7 + 5) + 8 + 9;
//             har = 17;
//             kirat = kirat + har;
//             kirat = sidhu;
//             b = true;
//             bb = false;
//             bb = b;
//             bb = true && false;
//             bb = bb && false;
//             if (true) {
//                 print "Kirat";
//             }

//             if (b) {
//                 kirat = 7;
//                 sidhu = 9;
//             } else {
//                 kirat = 6;
//             }

//             // if (kirat == 7) {
//             //     sidhu = 7;
//             // } else {
//             //     sidhu = 6;
//             // }

//             if (kirat == 7) {
//                 kirat = 8;
//             } else {
//                 kirat = 6;
//             }

//             if (kirat == 7) {
//                 kirat = 8;
//                 kirat = 7;
//             } else {
//                 kirat = 6;
//                 kirat = 9;
//             }

//             if (kirat == sidhu) {
//                 kirat = 8;
//                 kirat = 7;
//             } else {
//                 kirat = 6;
//                 kirat = 9;
//             }

//             if (b == bb) {
//                 kirat = 8;
//                 kirat = 7;
//             } else {
//                 kirat = 6;
//                 kirat = 9;
//             }


//             if (b == bb) {

//                 kirat = sidhu;

//                 if (kirat == sidhu) {
//                     kirat = sidhu - 1;
//                 } else {
//                     kirat = 17;
//                 }

//             } else {
//                 kirat = sidhu + 1;
//             }

//             if (b == b) {

//                 kirat = sidhu;

//                 if (sidhu == sidhu) {
//                     sidhu = sidhu - 1;
//                 } else {
//                     sidhu = 17;
//                 }

//             } else {
//                 kirat = sidhu + 1;
//             }



//             // if (b == bb) {

//             //     kirat = sidhu;

//             //     if (sidhu == sidhu) {
//             //         sidhu = sidhu - 1;
//             //     } else {
//             //         sidhu = 17;
//             //     }

//             // } else {
//             //     kirat = sidhu + 1;
//             // }

//             // if (b == bb) {
//             //     kirat = 8;
//             //     sidhu = 7;
//             // } else {
//             //     kirat = 6;
//             //     kirat = 9;
//             // }

//             // if (kirat == sidhu) {
//             //     kirat = 8;
//             //     sidhu = 7;
//             // } else {
//             //     kirat = 6;
//             //     kirat = 9;
//             // }

//             // if (kirat == 7) {
//             //     kirat = 8;
//             //     sidhu = 7;
//             // } else {
//             //     kirat = 6;
//             //     kirat = 9;
//             // }





//             //b = true && bb;
//             // b = bb;
//             // if (sidhu) {
//             //     print "Kirat";
//             // }
//             //sidhu = kirat + 7;
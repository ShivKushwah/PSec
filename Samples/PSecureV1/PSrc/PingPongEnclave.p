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
    var s_int : secure_int;
    var reg_int : int;
    var s_bool : secure_int;

    start state Initial {
        entry {
            s_int = 7;
            s_int = -7;
            reg_int = -7;
            reg_int = reg_int + 1;
            reg_int = -reg_int;
            s_int = -s_int;
            s_int = reg_int;

            if (s_int == 7) {
                s_int = s_int + 1;
            } else {
                s_int = 9;
            }

            if (s_int == 7) {
                s_int = s_int + 1;
            }

            if (reg_int == 7) {
                reg_int = 8;
            }

            if (s_int == 7) {
                s_int = s_int + 1;
            } else  {
                if (s_int == 10) {
                    s_int = 8;
                } else {
                    s_int = 9;
                }
            }

            while (s_int == 7) {
                s_int = s_int + 1;
            }

             while (s_int == 7) {
                
            }

            while (reg_int == 7) {
                s_int = s_int + 1;

            }

            // Following lines should be commented out unless error testing
            // reg_int = s_int;

            // if (s_int == 7) {
            //     s_int = s_int + 1;
            // } else  {
            //     if (reg_int == 7) {
            //         s_int = 8;
            //     } else {
            //         s_int = 9;
            //     }
            // }

            // while (s_int == 7) {
            //     reg_int = reg_int + 1;
            // }

            //
            
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
    start state Initial {

    }
}

secure_machine SecureChild {
    start state Initial {

    }
}

/*
//Actual Code

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
    // var sidhu : int;
    // var har : secure_int;
    // var b : bool;
    // var bb : secure_bool;


    start state Initial {
        entry {
            // var kirat : secure_int;

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
    // var sBool : secure_bool;
    var thisVar : StringType;

    start state Initial {
        entry { 
            // var kirat : secure_int;
            // kirat = 7 + 5;

            thisVar = GetThis();
            
            secureChildRegular = new SecureChild(thisVar);
            PrintString(secureChildRegular);
            // SecureSend(secureChildRegular, Pong, 1, 7);
            // SecureSend(secureChildRegular, Pong, 1, 7);
            secure_send secureChildRegular, Pong, 3;
            // secure_send secureChildRegular, Pong, 3;

            
            // secure_send secureChildRegular, Pong;
            // secure_send secureChildRegular, Pong;

            // if (sBool) {
            //     secure_send secureChildRegular, Pong;
            //     secure_send secureChildRegular, Pong;
            // }
        } 
        on Ping goto Done; 
                // on UntrustedEventFromPing goto Done;
    }

    state Done { 
        entry {
            print "YOOOOO";
	    }
                // on UntrustedEventFromPing goto Done;

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

*/

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
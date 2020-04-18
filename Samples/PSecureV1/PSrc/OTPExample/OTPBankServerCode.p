machine UntrustedInitializer {
    var handler: machine_handle;
    start state Initial {
        entry {
            print "MEASURE UNTRUSTED CREATE START:";
            MeasureTime();
            handler = new TrustedInitializer();
        }
    }
}

secure_machine TrustedInitializer {
    
    var clientUSM: machine_handle;
    var bankSSM: secure_machine_handle;
    start state Initial {
        entry {
            print "MEASURE UNTRUSTED CREATE END:";
            MeasureTime();
            clientUSM = new ClientWebBrowser();
            bankSSM = new BankEnclave();
            send bankSSM, TRUSTEDProvisionBankSSM, clientUSM as secure_machine_handle; //secure_send
            send clientUSM, BankPublicIDEvent, Declassify(bankSSM) as machine_handle; //untrusted_send
        }
    }
}

secure_machine BankEnclave {
    var clientSSM: secure_machine_handle;
    var clientUSM: machine_handle;
    var masterSecret : secure_StringType;
    var userCredential : secure_StringType;
    start state Initial {
        entry { 
            goto ReceiveClientUSM;
        } 
    }

    state ReceiveClientUSM {
        on TRUSTEDProvisionBankSSM do (payload: secure_machine_handle) {
            print "MEASURE TRUSTED CREATE START:";
            MeasureTime();
            clientSSM = new ClientEnclave();
            print "MEASURE TRUSTED SEND START:";
            MeasureTime();
            clientUSM = Declassify(payload) as machine_handle;
            send clientSSM, TRUSTEDProvisionClientSSM, clientUSM as secure_machine_handle;
            goto RegisterNewBankAccount;
            
        }
    }

    state RegisterNewBankAccount {
        on UNTRUSTEDReceiveRegistrationCredentials do (payload: StringType) {
            print "MEASURE UNTRUSTED SEND END:";
            MeasureTime();

            print "Bank: Creating new bank account!";
            userCredential = payload;
            masterSecret = GenerateRandomMasterSecret();
            print "MEASURE TRUSTED SEND 2 START:";
            MeasureTime();
            send clientSSM, MasterSecretEvent, masterSecret; //secure_send
            send clientUSM, PublicIDEvent, Declassify(clientSSM) as machine_handle; //untrusted_send
            goto AuthCheck;

        }
    }

    state AuthCheck {
       on AuthenticateRequest goto Verify;
    }

    state Verify { 
        entry (payload : (usernamePW: StringType, OTPCode: StringType)) {
            print "MEASURE UNTRUSTED SEND 2 END:";
            MeasureTime();
            if (Declassify(userCredential) == payload.usernamePW && Hash(masterSecret as StringType, userCredential as StringType) == payload.OTPCode) {
                print "Auth Success";
                send clientUSM, AuthSuccess; //untrusted_send
            } else {
                print "Auth Failure";
                send clientUSM, AuthFailure; //untrusted_send
            }
            
            goto AuthCheck;
        }

    }
}


// //Measurement Code
// machine UntrustedInitializer {
//     var handler: machine_handle;
//     start state Initial {
//         entry {
//             print "MEASURE UNTRUSTED CREATE START:";
//             MeasureTime();
//             handler = new MeasureMachine();
//             print "MEASURE UNTRUSTED CREATE SSM START:";
//             MeasureTime();
//             handler = new TrustedInitializer();
//         }
//     }
// }

// machine MeasureMachine {
//     start state Initial {
//         entry {
//             print "MEASURE UNTRUSTED CREATE END:";
//             MeasureTime();
//         }
//     }
// }

// secure_machine TrustedInitializer {
    
//     var clientUSM: machine_handle;
//     var bankSSM: secure_machine_handle;
//     start state Initial {
//         entry {
//             print "MEASURE UNTRUSTED CREATE SSM END:";
//             MeasureTime();
//             clientUSM = new ClientWebBrowser();
//             bankSSM = new BankEnclave();
//             send bankSSM, TRUSTEDProvisionBankSSM, clientUSM as secure_machine_handle; //secure_send
//             send clientUSM, BankPublicIDEvent, Declassify(bankSSM) as machine_handle; //untrusted_send
//         }
//     }
// }

// secure_machine BankEnclave {
//     var clientSSM: secure_machine_handle;
//     var clientUSM: machine_handle;
//     var masterSecret : secure_StringType;
//     var userCredential : secure_StringType;
//     start state Initial {
//         entry { 
//             goto ReceiveClientUSM;
//         } 
//     }

//     state ReceiveClientUSM {
//         on TRUSTEDProvisionBankSSM do (payload: secure_machine_handle) {
//             print "MEASURE TRUSTED CREATE START:";
//             MeasureTime();
//             clientSSM = new ClientEnclave();
//             print "MEASURE TRUSTED SEND START:";
//             MeasureTime();
//             send clientSSM, TRUSTEDMeasureEvent1, (fst = 1 as secure_int, snd = GetHelloWorld() as secure_StringType);
//             print "MEASURE TRUSTED SEND 2 START:";
//             MeasureTime();
//             send clientSSM, TRUSTEDMeasureEvent2, (fst = 1 as secure_int, snd = GetHelloWorld() as secure_StringType);

//             clientUSM = Declassify(payload) as machine_handle;
//             send clientSSM, TRUSTEDProvisionClientSSM, clientUSM as secure_machine_handle;
//             goto RegisterNewBankAccount;
            
//         }
//     }

//     state RegisterNewBankAccount {
//         on MeasureEvent1 do (payload: (fst:int, snd:StringType)) {
//             print "MEASURE UNTRUSTED SEND END:";
//             MeasureTime();
//         }
//         on MeasureEvent2 do (payload: (fst:int, snd:StringType)) {
//             print "MEASURE UNTRUSTED SEND 2 END:";
//             MeasureTime();
//         }
//         on UNTRUSTEDReceiveRegistrationCredentials do (payload: StringType) {
//             // print "MEASURE UNTRUSTED SEND END:";
//             // MeasureTime();

//             print "Bank: Creating new bank account!";
//             userCredential = payload;
//             masterSecret = GenerateRandomMasterSecret();
//             // print "MEASURE TRUSTED SEND 2 START:";
//             // MeasureTime();
//             send clientSSM, MasterSecretEvent, masterSecret; //secure_send
//             send clientUSM, PublicIDEvent, Declassify(clientSSM) as machine_handle; //untrusted_send
//             goto AuthCheck;

//         }
//     }

//     state AuthCheck {
//        on AuthenticateRequest goto Verify;
//     }

//     state Verify { 
//         entry (payload : (usernamePW: StringType, OTPCode: StringType)) {
//             // print "MEASURE UNTRUSTED SEND 2 END:";
//             // MeasureTime();
//             PrintRawStringType(Declassify(userCredential) as StringType);
//             PrintRawStringType(payload.usernamePW as StringType);
//             PrintRawStringType(Hash(masterSecret as StringType, userCredential as StringType));
//             PrintRawStringType(payload.OTPCode);
//             if (Declassify(userCredential) as StringType == payload.usernamePW as StringType && Hash(masterSecret as StringType, userCredential as StringType) == payload.OTPCode) {
//                 send clientUSM, AuthSuccess; //untrusted_send
//             } else {
//                 send clientUSM, AuthFailure; //untrusted_send
//             }
            
//             goto AuthCheck;
//         }

//     }
// }
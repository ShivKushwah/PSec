trusted event Ping;

secure_machine ExampleMachine {
    var ssn : secure_int;
    var insecure_int : int;
    var s_int : secure_int;
    var s_handle : secure_machine_handle;
    var handle : machine_handle;

    start state Initial {
        entry {      
            ssn = ReadSSNFromUser(); // Valid

            if (ssn == (Endorse(6123456) as secure_int)) { // Valid
                s_int = Endorse(7) as secure_int; 
            } else {
                s_int = Endorse(8) as secure_int;
            }

            s_int = s_int + (Endorse(1) as secure_int); // Valid

            insecure_int = 10; // Valid
            s_int = Endorse(insecure_int) as secure_int;

            while (insecure_int < 15) { // Valid
                s_int = s_int + (Endorse(1) as secure_int);
                insecure_int = insecure_int + 1;
            }

            while (s_int < (Endorse(20) as secure_int)) { // Valid
                s_int = s_int + (Endorse(1) as secure_int);
                send s_handle, Ping;
            }

            // Invalid Code Below

            // Invalid because value of insecure_int after this if statement
            // will leak whether ssn is 6123456 or not
            // if (ssn == (Endorse(6123456) as secure_int)) { 
            //     insecure_int = 7;
            // } else {
            //     insecure_int = 8;
            // }

            // Invalid because value of ssn will be leaked by assigning it to a
            // non-secret variable
            // insecure_int = ssn; 

            // Invalid because value of s_int will be compromised by looking at value
            // of insecure_int after execution of while statement
            // while (s_int < (Endorse(15) as secure_int)) {
            //     s_int = s_int + (Endorse(1) as secure_int);
            //     insecure_int = insecure_int + 1;
            // }

        }
    }
}


fun ReadSSNFromUser() : secure_int {
    return Endorse(6123456) as secure_int;
}
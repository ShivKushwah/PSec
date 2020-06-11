secure_machine EmailUserEnclave {
    var secureSpamSSM : secure_machine_handle;
    var emailUserUSM : machine_handle;
    
    start state Initial {
        on TRUSTEDProvisionEmailUserEnclave do (payload : (secure_machine_handle, secure_machine_handle)) {
            secureSpamSSM = payload.0;
            emailUserUSM = Declassify(payload.1) as machine_handle;
            goto ReceiveEmailBodyAndSendSpamRequest;
        }
    }

    state ReceiveEmailBodyAndSendSpamRequest {
        on UNTRUSTEDEmailBodyEvent do (payload: StringType) {
            send secureSpamSSM, TRUSTEDEmailBodyEvent, (this, Endorse(payload) as secure_StringType);
            goto ReceiveSpamResult;
        }
    }

    state ReceiveSpamResult {
        on TRUSTEDSpamResultEvent do (payload: secure_bool) {
            send emailUserUSM, UNTRUSTEDSpamResultEvent, Declassify(payload) as bool;
            goto ReceiveEmailBodyAndSendSpamRequest;
        }
    }

}

machine EmailUser {
    var secureSpamSSM : machine_handle;
    var emailEnclaveSSM: machine_handle;

    start state Initial {
        on UNTRUSTEDSecureSpamFilterIDEvent goto SaveSecureSpamFilter;
    }

    state SaveSecureSpamFilter {
        entry (payload: machine_handle) {
            secureSpamSSM = payload;
            goto SaveEmailUserEnclave;
        }
    }

    state SaveEmailUserEnclave {
        entry {
            send secureSpamSSM, UNTRUSTEDReceiveEmailEnclaveIDEvent, this;
        }
        on UNTRUSTEDEmailEnclaveIDEvent do (payload: machine_handle)  {
            emailEnclaveSSM = payload;
            goto RequestSpamCheck;
        }
    }

    state RequestSpamCheck {
        entry {
            var emailBody : StringType;
            send emailEnclaveSSM, UNTRUSTEDEmailBodyEvent, emailBody;
        }
        on UNTRUSTEDSpamResultEvent goto Done;
    }

    state Done {
        entry (payload: bool) {
            if (payload == true) {
                print "Spam detected and deleted!";
            } else {
                print "Email is good!";
            }
        }
     }
}
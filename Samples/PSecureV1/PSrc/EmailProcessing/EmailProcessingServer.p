machine UntrustedInitializer {
    var handler: machine_handle;
    start state Initial {
        entry {
            handler = new TrustedInitializer() @ this;
        }
    }
}

secure_machine TrustedInitializer {
    
    var emailUserUSM: machine_handle;
    var spamFilterSSM: secure_machine_handle;
    start state Initial {
        entry {
            emailUserUSM = new EmailUser();
            spamFilterSSM = new SecureSpamFilter() @ this;
            send emailUserUSM, UNTRUSTEDSecureSpamFilterIDEvent, Declassify(spamFilterSSM) as machine_handle; //untrusted_send
        }
    }
}

secure_machine SecureSpamFilter {

    start state Initial {
        on UNTRUSTEDReceiveEmailEnclaveIDEvent do (payload: machine_handle) {
            var emailEnclaveSSM: secure_machine_handle;
            emailEnclaveSSM = new EmailUserEnclave() @ payload;
            send emailEnclaveSSM, TRUSTEDProvisionEmailUserEnclave, (this, payload); 
            send payload, UNTRUSTEDEmailEnclaveIDEvent, Declassify(emailEnclaveSSM) as machine_handle;
        }

        on TRUSTEDEmailBodyEvent do (payload: (secure_machine_handle, secure_StringType)) {
            var emailEnclaveSSM: secure_machine_handle;
            emailEnclaveSSM = payload.0;
            if ($) {
                send emailEnclaveSSM, TRUSTEDSpamResultEvent, Endorse(true) as secure_bool;
            } else {
                send emailEnclaveSSM, TRUSTEDSpamResultEvent, Endorse(false) as secure_bool;
            }
        }
    }  
}
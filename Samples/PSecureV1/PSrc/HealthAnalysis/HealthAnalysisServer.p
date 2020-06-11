machine UntrustedInitializer {
    var handler: machine_handle;
    start state Initial {
        entry {
            handler = new TrustedInitializer() @ this;
        }
    }
}

secure_machine TrustedInitializer {
    
    var userUSM: machine_handle;
    var healthAnalyzerSSM: secure_machine_handle;

    start state Initial {
        entry {
            userUSM = new User();
            healthAnalyzerSSM = new SecureHealthAnalyzer() @ this;
            send userUSM, UNTRUSTEDSecureHealthAnalyzerIDEvent, Declassify(healthAnalyzerSSM) as machine_handle; //untrusted_send
        }
    }
}

secure_machine SecureHealthAnalyzer {
    var MLHost : secure_machine_handle;

    start state Initial {
        entry {
            MLHost = new awsMLHost() @ this;
        }

        on UNTRUSTEDReceiveUserEnclaveIDEvent do (payload: machine_handle) {
            var userEnclaveSSM: secure_machine_handle;
            userEnclaveSSM = new UserEnclave() @ payload;
            send userEnclaveSSM, TRUSTEDProvisionUserEnclave, (this, Endorse(payload) as secure_machine_handle); 
            send payload, UNTRUSTEDUserEnclaveIDEvent, Declassify(userEnclaveSSM) as machine_handle;
        }

        on TRUSTEDHealthInfoEvent do (payload: (secure_machine_handle, secure_StringType)) {
            send MLHost, TRUSTEDHealthInfoEvent, (payload.0, payload.1);
        }
    }  
}

secure_machine awsMLHost {

    start state Initial {
        on TRUSTEDHealthInfoEvent do (payload: (secure_machine_handle, secure_StringType)) {
            var userEnclaveSSM: secure_machine_handle;
            userEnclaveSSM = payload.0;
            if ($) {
                send userEnclaveSSM, TRUSTEDHealthInfoResultEvent, Endorse(true) as secure_bool;
            } else {
                send userEnclaveSSM, TRUSTEDHealthInfoResultEvent, Endorse(false) as secure_bool;
            }
        }
    }  
}
secure_machine UserEnclave {
    var healthAnalyzerSSM : secure_machine_handle;
    var userUSM : machine_handle;
    
    start state Initial {
        on TRUSTEDProvisionUserEnclave do (payload : (secure_machine_handle, secure_machine_handle)) {
            healthAnalyzerSSM = payload.0;
            userUSM = Declassify(payload.1) as machine_handle;
            goto ReceiveHealthInfoAndSendHealthRequest;
        }
    }

    state ReceiveHealthInfoAndSendHealthRequest {
        on UNTRUSTEDHealthInfoEvent do (payload: StringType) {
            send healthAnalyzerSSM, TRUSTEDHealthInfoEvent, (this, Endorse(payload) as secure_StringType);
            goto ReceiveHealthInfoResult;
        }
    }

    state ReceiveHealthInfoResult {
        on TRUSTEDHealthInfoResultEvent do (payload: secure_bool) {
            send userUSM, UNTRUSTEDHealthInfoResultEvent, Declassify(payload) as bool;
            goto ReceiveHealthInfoAndSendHealthRequest;
        }
    }

}

machine User {
    var healthAnalyzerSSM : machine_handle;
    var userEnclaveSSM: machine_handle;

    start state Initial {
        on UNTRUSTEDSecureHealthAnalyzerIDEvent goto SaveSecureHealthAnalyzer;
    }

    state SaveSecureHealthAnalyzer {
        entry (payload: machine_handle) {
            healthAnalyzerSSM = payload;
            goto SaveUserEnclave;
        }
    }

    state SaveUserEnclave {
        entry {
            send healthAnalyzerSSM, UNTRUSTEDReceiveUserEnclaveIDEvent, this;
        }
        on UNTRUSTEDUserEnclaveIDEvent do (payload: machine_handle)  {
            userEnclaveSSM = payload;
            goto RequestHealthCheck;
        }
    }

    state RequestHealthCheck {
        entry {
            var healthInfo : StringType;
            send userEnclaveSSM, UNTRUSTEDHealthInfoEvent, healthInfo;
        }
        on UNTRUSTEDHealthInfoResultEvent goto Done;
    }

    state Done {
        entry (payload: bool) {
            if (payload == true) {
                print "Healthy!";
            } else {
                print "Health issue :(";
            }
        }
     }
}
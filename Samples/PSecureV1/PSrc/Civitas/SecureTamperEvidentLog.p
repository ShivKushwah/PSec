/**************************************
Secure TamperEvidentLog Machine
* Stores votes in sequential order as received from SecureBallotBoxMachine
***************************************/
secure_machine SecureTamperEvidentLogMachine 
{
    var log: seq[(credential: secure_StringType, vote: secure_int)];
    var parent: secure_machine_handle;
    start state Init {
         on TRUSTEDProvisionSecureTamperEvidentLogMachine do (payload: secure_machine_handle) {
            parent = payload;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        on TRUSTEDeAddItem do (payload: (credential : secure_StringType, vote: secure_int)){
            // var cred : secure_int;
            // if (payload.credential as StringType == GenerateCredential1()) {
			// 	cred = 1775847362;
			// } else {
			// 	cred = 1861262373;
			// }
            log += (sizeof(log), (credential = payload.credential, vote = payload.vote));
            send parent, TRUSTEDeRespAddItem, true; //secure_send
        }
        on TRUSTEDeGetLog do
        {
            send parent, TRUSTEDeRespGetLog, log; //secure_send
        }
    }
}
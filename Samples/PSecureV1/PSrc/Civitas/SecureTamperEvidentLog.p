/**************************************
Secure TamperEvidentLog Machine
* Stores votes in sequential order as received from SecureBallotBoxMachine
***************************************/
secure_machine SecureTamperEvidentLogMachine 
{
    var log: seq[(credential: int, vote: secure_int)];
    var parent: secure_machine_handle;
    start state Init {
         on TRUSTEDProvisionSecureTamperEvidentLogMachine do (payload: secure_machine_handle) {
            parent = payload;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        on TRUSTEDeAddItem do (payload: (credential : int, vote: secure_int)){
            log += (sizeof(log), (credential = payload.credential, vote = payload.vote));
            secure_send parent, TRUSTEDeRespAddItem, true;
        }
        on TRUSTEDeGetLog do
        {
            secure_send parent, TRUSTEDeRespGetLog, log;
        }
    }
}
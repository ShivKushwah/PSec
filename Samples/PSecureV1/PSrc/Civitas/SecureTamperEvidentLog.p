/**************************************
Secure TamperEvidentLog Machine
* Stores votes in sequential order as received from SecureBallotBoxMachine
***************************************/
secure_machine SecureTamperEvidentLogMachine 
{
    var log: seq[(credential: int, vote: secure_int)];
    var parent: machine_handle;
    start state Init {
        entry(payload: (parentMachine: machine_handle, parentCapability:capability))
         {
            parent = payload.parentMachine;
            SaveCapability(payload.parentCapability);
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
/**************************************
Secure TamperEvidentLog Machine
* Stores votes in sequential order as received from SecureBallotBoxMachine
***************************************/
machine SecureTamperEvidentLogMachine 
{
    var log: seq[(credential: StringType, vote: int)];
    var parent: machine_handle;
    start state Init {
         on TRUSTEDProvisionSecureTamperEvidentLogMachine do (payload: machine_handle) {
            parent = payload;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        on TRUSTEDeAddItem do (payload: (credential : StringType, vote: int)){
            log += (sizeof(log), (credential = payload.credential, vote = payload.vote));
            send parent, TRUSTEDeRespAddItem, true; //send
        }
        on TRUSTEDeGetLog do
        {
            send parent, TRUSTEDeRespGetLog, log; //send
        }
    }
}
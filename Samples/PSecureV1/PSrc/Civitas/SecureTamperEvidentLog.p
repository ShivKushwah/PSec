secure_machine SecureTamperEvidentLogMachine 
{
    var log: seq[(credential: int, vote: int)]; //seq[(credential, vote)]
    var parent: machine_handle;
    start state Init {
        entry(payload: machine_handle)
         {
            parent = payload;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        on TRUSTEDeAddItem do (payload: (credential : int, vote: int)){
            log += (sizeof(log), (credential = payload.credential, vote = payload.vote));
            untrusted_send parent, TRUSTEDeRespAddItem, true;
        }
        on TRUSTEDeGetLog do
        {
            print "Is issue here?";
            // print log;
            untrusted_send parent, TRUSTEDeRespGetLog, log;
        }
    }
}
secure_machine SecureTamperEvidentLogMachine 
{
    var log: seq[int];
    var parent: machine_handle;
    start state Init {
        entry(payload: machine_handle)
         {
            parent = payload;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        on TRUSTEDeAddItem do (item: int){
            log += (sizeof(log), item);
            untrusted_send parent, TRUSTEDeRespAddItem, true;
        }
        // on TRUSTEDeGetLog do
        // {
        //     secure_send parent, TRUSTEDeRespGetLog, log;
        // }
    }
}
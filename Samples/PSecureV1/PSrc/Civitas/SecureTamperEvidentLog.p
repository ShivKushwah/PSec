secure_machine SecureTamperEvidentLogMachine 
{
    // var log: seq[data];
    var parent: machine_handle;
    start state Init {
        entry(payload: machine_handle)
         {
            parent = payload;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        // on TRUSTEDeAddItem do (item: data){
        //     log += (sizeof(log), item);
        //     secure_send parent, TRUSTEDeRespAddItem, true;
        // }
        // on TRUSTEDeGetLog do
        // {
        //     secure_send parent, TRUSTEDeRespGetLog, log;
        // }
    }
}
event eAddItem: data;
event eRespAddItem: bool;
event eGetLog;
event eRespGetLog : seq[data];

machine TamperEvidentLogMachine 
receives eAddItem, eGetLog;
sends eRespAddItem, eRespGetLog;
{
    var log: seq[data];
    var parent: machine;
    start state Init {
        entry(payload: machine)
         {
            parent = payload;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        on eAddItem do (item: data){
            log += (sizeof(log), item);
            send parent, eRespAddItem, true;
        }
        on eGetLog do
        {
            send parent, eRespGetLog, log;
        }
    }
}


/**************************************
Secure TamperEvidentLog Machine
* Stores votes in sequential order as received from SecureBallotBoxMachine
***************************************/
machine SecureTamperEvidentLogMachine 
{
    var log: seq[(credential: StringType, vote: int)];
    var parent: machine_handle;
    var memory : machine_handle;
    start state Init {
         on TRUSTEDProvisionSecureTamperEvidentLogMachine do (payload: machine_handle) {
            parent = payload;
            memory = new StorageMachine() @ this;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        on TRUSTEDeAddItem do (payload: (credential : StringType, vote: int)){
            var sealedVote : sealed_data;

            // sealedVote = seal(payload);
            send memory, UNTRUSTEDSendSealedVote, sealedVote;
            // // Can later retrieve using `unseal(sealedVote) as (secure_StringType, secure_int)`

            // if (Declassify((unseal(sealedVote) as (secure_StringType, secure_int)).1) as int == Declassify(payload.vote) as int) {
            //     print "Sealed Vote Successfully!";
            // }

            log += (sizeof(log), (credential = payload.credential, vote = payload.vote));
            send parent, TRUSTEDeRespAddItem, true; //send
        }
        on TRUSTEDeGetLog do
        {
            send parent, TRUSTEDeRespGetLog, log; //send
        }
    }
}

machine StorageMachine 
{
    var untrusted_memory: seq[sealed_data];

    start state Init {
         on UNTRUSTEDSendSealedVote do (payload: sealed_data) {
            untrusted_memory += (sizeof(untrusted_memory), payload);
         }
    }
}
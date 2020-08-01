/**************************************
Secure TamperEvidentLog Machine
* Stores votes in sequential order as received from SecureBallotBoxMachine
***************************************/
secure_machine SecureTamperEvidentLogMachine 
{
    var log: seq[(credential: secure_StringType, vote: secure_int)];
    var parent: secure_machine_handle;
    var memory : machine_handle;
    start state Init {
         on TRUSTEDProvisionSecureTamperEvidentLogMachine do (payload: secure_machine_handle) {
            parent = payload;
            memory = new StorageMachine() @ this;
            goto WaitForRequests;
         }
    }

    state WaitForRequests {
        on TRUSTEDeAddItem do (payload: (credential : secure_StringType, vote: secure_int)){
            var sealedVote : sealed_data;

            sealedVote = seal(payload);
            send memory, UNTRUSTEDSendSealedVote, sealedVote;
            // Can later retrieve using `unseal(sealedVote) as (secure_StringType, secure_int)`

            if (Declassify((unseal(sealedVote) as (secure_StringType, secure_int)).1) as int == Declassify(payload.vote) as int) {
                print "Sealed Vote Successfully!";
            }
            
            log += (sizeof(log), (credential = payload.credential, vote = payload.vote));
            send parent, TRUSTEDeRespAddItem, Endorse(true) as secure_bool; //secure_send
        }
        on TRUSTEDeGetLog do
        {
            send parent, TRUSTEDeRespGetLog, log; //secure_send
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
/****************************************
Tabulation Teller Machine
* Eliminates duplicate votes (keeps only most recent vote per vote credential)
* Sends final votes to Secure Bulletin Board
****************************************/

secure_machine SecureTabulationTellerMachine 
{
    var bulletinBoard: secure_machine_handle;
    var supervisor: secure_machine_handle;
    var allVotes: seq[(credential : int, vote : secure_int)];

    start state Init {
        ignore TRUSTEDValidCredential;
        entry (payload:(bBoard: secure_machine_handle, supervisor: secure_machine_handle)){
            bulletinBoard = payload.bBoard;
            supervisor = payload.supervisor;
        }
        on TRUSTEDeAllVotes do (payload: (ballotID : int, votes : seq[(credential : int, vote : secure_int)])){
            //allVotes are ordered by time
            allVotes = payload.votes;
            goto DoTally;
        }
    }
    
    state DoTally {
        entry {
            var result: map[int, secure_int];
            var i: int;
            i = 0;
            while(i < sizeof(allVotes))
            {
                secure_send supervisor, TRUSTEDValidateCredential, (tabulationTellerMachine = secure_this, credentialToCheck = allVotes[i].credential);
                receive {
                    case TRUSTEDValidCredential : {
                        //map enables us to consider the latest vote
                        result[allVotes[i].credential] = allVotes[i].vote; 
                        
                    }
                    case TRUSTEDInvalidCredential : {
                        //Drop this vote
                    }
                }
                i = i + 1;
                
            }

            secure_send bulletinBoard, TRUSTEDeElectionResults, result;
        }
    }
}
/****************************************
Tabulation Teller Machine
* Eliminates duplicate votes (keeps only most recent vote per vote credential)
* Sends final votes to Secure Bulletin Board
****************************************/

machine SecureTabulationTellerMachine 
{
    var bulletinBoard: machine_handle;
    var supervisor: machine_handle;
    var allVotes: seq[(credential : StringType, vote : int)];

    start state Init {

        on TRUSTEDProvisionSecureTabulationTellerMachine do (payload:(bBoard: machine_handle, supervisor: machine_handle)){
            bulletinBoard = payload.bBoard;
            supervisor = payload.supervisor;
            goto ReceiveVotes;
        }
    }

    state ReceiveVotes {
        on TRUSTEDeAllVotes do (payload: (ballotID : int, votes : seq[(credential : StringType, vote : int)])){
            //allVotes are ordered by time
            allVotes = payload.votes;
            goto DoTally;
        }
    }
    
    state DoTally {
        entry {
            var result: map[StringType, int];
            var i: int;
            i = 0;
            while(i < sizeof(allVotes))
            {
                send supervisor, TRUSTEDValidateCredential, (tabulationTellerMachine = this, credentialToCheck = allVotes[i].credential); //send
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

            send bulletinBoard, TRUSTEDeElectionResults, result; //send
        }
    }
}
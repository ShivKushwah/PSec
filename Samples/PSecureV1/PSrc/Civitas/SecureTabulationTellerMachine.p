/****************************************
Tabulation Teller Machine
* Eliminates duplicate votes (keeps only most recent vote per vote credential)
* Sends final votes to Secure Bulletin Board
****************************************/

secure_machine SecureTabulationTellerMachine 
{
    var bulletinBoard: secure_machine_handle;
    var supervisor: secure_machine_handle;
    var allVotes: seq[(credential : secure_StringType, vote : secure_int)];

    start state Init {

        on TRUSTEDProvisionSecureTabulationTellerMachine do (payload:(bBoard: secure_machine_handle, supervisor: secure_machine_handle)){
            bulletinBoard = payload.bBoard;
            supervisor = payload.supervisor;
            goto ReceiveVotes;
        }
    }

    state ReceiveVotes {
        on TRUSTEDeAllVotes do (payload: (ballotID : int, votes : seq[(credential : secure_StringType, vote : secure_int)])){
            //allVotes are ordered by time
            allVotes = payload.votes;
            goto DoTally;
        }
    }
    
    state DoTally {
        entry {
            var result: map[secure_StringType, secure_int];
            var i: int;
            i = 0;
            while(i < sizeof(allVotes))
            {
                send supervisor, TRUSTEDValidateCredential, (tabulationTellerMachine = this, credentialToCheck = allVotes[i].credential); //secure_send
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

            send bulletinBoard, TRUSTEDeElectionResults, result; //secure_send
        }
    }
}
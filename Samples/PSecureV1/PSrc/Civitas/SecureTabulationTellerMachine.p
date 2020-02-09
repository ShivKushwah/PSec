/****************************************
Tabulation Teller Machine
* Eliminates duplicate votes (keeps only most recent vote per vote credential)
* Sends final votes to Secure Bulletin Board
****************************************/

secure_machine SecureTabulationTellerMachine 
{
    var bulletinBoard: machine_handle;
    var supervisor: machine_handle;
    var allVotes: seq[(credential : int, vote : secure_int)];

    start state Init {
        entry (payload:(bBoard: machine_handle, bBoardCapability: capability, supervisor: machine_handle, supervisorCapability: capability)){
            bulletinBoard = payload.bBoard;
            supervisor = payload.supervisor;
            SaveCapability(payload.bBoardCapability);
            SaveCapability(payload.supervisorCapability);
        }
        on TRUSTEDeAllVotes do (payload: (ballotID : int, votes : seq[(credential : int, vote : secure_int)])){
            //allVotes are ordered by time
            allVotes = payload.votes;
            goto DoTally;
        }
    }
    
    state DoTally {
        entry {
            var result: map[int, int];
            var i: int;
            i = 0;
            while(i < sizeof(allVotes))
            {
                secure_send supervisor, TRUSTEDValidateCredential, (tabulationTellerMachine = GetThis(), tabulationTellerCapability = GetCapability(GetThis()), credentialToCheck = allVotes[i].credential);
                receive {
                    case TRUSTEDValidCredential : {
                        //map enables us to consider the latest vote
                        result[allVotes[i].credential] = DeclassifyInt(allVotes[i].vote); 
                        
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
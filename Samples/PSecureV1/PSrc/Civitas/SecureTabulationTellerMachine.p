/****************************************
Tabulation Teller Machine
* Eliminates duplicate votes (keeps only most recent vote per vote credential)
* Sends final votes to Secure Bulletin Board
****************************************/

secure_machine SecureTabulationTellerMachine 
{
    var bulletinBoard: machine_handle;
    var allVotes: seq[(credential : int, vote : int)];

    start state Init {
        entry (payload:(bBoard: machine_handle, bBoardCapability: capability)){
            bulletinBoard = payload.bBoard;
            SaveCapability(payload.bBoardCapability);
        }
        on TRUSTEDeAllVotes do (payload: (ballotID : int, votes : seq[(credential : int, vote : int)])){
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
                //TODO validate the credentials
                result[allVotes[i].credential] = allVotes[i].vote; //map enables us to consider the latest vote
                i = i + 1;
            }

            secure_send bulletinBoard, TRUSTEDeElectionResults, result;
        }
    }
}
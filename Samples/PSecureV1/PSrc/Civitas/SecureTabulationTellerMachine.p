/****************************************
* Tabulation Teller Machine
* TabulationTeller -> BulletinBoard -> ElectionResults.
****************************************/

//Receives a request to count votes, and after counting votes, sends them to the public BulletinBoard
secure_machine SecureTabulationTellerMachine 
{
    var bulletinBoard: machine_handle;
    var allVotes: seq[(credential : int, vote : int)];

    start state Init {
        // defer eDoTally; //TODO remove?

        entry (bBoard: machine_handle){
            bulletinBoard = bBoard;
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

            // secure_send bulletinBoard, TRUSTEDeElectionResults, result; //TODO make trusted
            untrusted_send bulletinBoard, TRUSTEDeElectionResults, result;
        }
    }
}
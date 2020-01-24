/****************************************
* Tabulation Teller Machine
* TabulationTeller -> BulletinBoard -> ElectionResults.
****************************************/

//Receives a request to count votes, and after counting votes, sends them to the public BulletinBoard
secure_machine SecureTabulationTellerMachine 
{
    var bulletinBoard: machine_handle;
    // var allVotes: seq[Vote];

    start state Init {
        // defer eDoTally; //TODO remove?

        entry (bBoard: machine_handle){
            bulletinBoard = bBoard;
        }
        // on TRUSTEDeAllVotes do (payload: seq[Vote]){
        //     allVotes = payload;
        //     goto DoTally;
        // }
    }
    
    state DoTally {
        // entry {
        //     var result: map[int, int];
        //     var i: int;
        //     i = 0;
        //     while(i < sizeof(allVotes))
        //     {
        //         //TODO validate the credentials

        //         //consider the latest vote

        //         result[allVotes[i].credentials] = allVotes[i].vote;
        //         i = i + 1;
        //     }

        //     secure_send bulletinBoard, TRUSTEDeElectionResults, result;
        // }
    }
}
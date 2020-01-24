/*****************************
BallotBox Machine
* BallotBox -> BulletinBoard -> AllVotesFor.
******************************/

//Receives direct votes from VotingClients and upon voting completion, requests the TabulationTeller to count the votes
secure_machine SecureBallotBoxMachine
{
    var bulletinBoard: machine_handle;
    var tabulationTeller: machine_handle;
    var appendOnlyLog: machine_handle;

    start state Init {
        entry (bBoard: machine_handle){
            bulletinBoard = bBoard;
            // appendOnlyLog = new TamperEvidentLogMachine(this); //essentially the db of votes for this ballotbox
            // tabulationTeller = new TabulationTellerMachine(bulletinBoard); //counts the votes
        }
        // on TRUSTEDeStartElection goto WaitForVotes;
        // on TRUSTEDeVote do {
        //     print "Vote ignored, voting has not started yet !!";
        // }
    }

    // state WaitForVotes {
    //     on TRUSTEDeVote do (payload: (Vote, secure_machine))
    //     {
    //         secure_send appendOnlyLog, TRUSTEDeAddItem, payload.0;
    //         receive {
    //             case TRUSTEDeRespAddItem : (result: bool) {
    //                 if(result)
    //                 {
    //                     secure_send payload.1, TRUSTEDeRespConfirmVote;
    //                 }
    //             }
    //         }
    //     }
    //     on eCloseElection goto VoteCounting;
    // }

    // state VoteCounting {
    //     entry {
    //         secure_send appendOnlyLog, TRUSTEDeGetLog;
    //         receive{
    //             case TRUSTEDeRespGetLog: (p: seq[any]) //p is all the votes returned by the appendOnlyLog
    //             {
    //                 secure_send tabulationTeller, TRUSTEDeAllVotes, (ballotId = 0, votes = p as seq[Vote]);
    //             }
    //         }

    //         goto WaitForGetResultsQuery;
    //     }


    // }

    // state WaitForGetResultsQuery {
    //         on eVote do {
    //         print "Vote ignored, voting phase is over";
    //     }
    // }
}
/****************************************
* Bulletin Board Machine
* BulletinBoard -> VotingClient = RespElectionResults.
* BulletinBoard -> BallotBox = Confrimation.
* BulletinBoard -> TabulationTeller -> AllVotes.
*****************************************/

//Stores the election results and VotingClients can verify their vote was included
secure_machine SecureBulletinBoardMachine
{
    var electionResults: map[int, int];
    start state Init {
        // on TRUSTEDeGetElectionResults do {
        //     print "Election Results not Available";
        // }
        defer TRUSTEDeGetElectionResults;
        on TRUSTEDeElectionResults do (payload: map[int, int]) {
            electionResults = payload;
            // goto SendResults;
        }
    }

    state SendResults { 
        on TRUSTEDeGetElectionResults do (payload: machine_handle){
            untrusted_send payload, TRUSTEDeRespElectionResults, (allVotes = electionResults, whoWon = 0); //TODO why = 0?
        }
    }
}
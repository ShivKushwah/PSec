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
    var electionResultsKeys : seq[int];
    var i : int;
    var countCandidate0 : int;
    var countCandidate1 : int;
    var winner : int;
    start state Init {
        // on TRUSTEDeGetElectionResults do {
        //     print "Election Results not Available";
        // }
        defer TRUSTEDeGetElectionResults;
        on TRUSTEDeElectionResults do (payload: map[int, int]) {
            electionResults = payload;
            goto SendResults;
        }
    }

    state SendResults { 
        on TRUSTEDeGetElectionResults do (payload: (requestingMachine: machine_handle, requestingMachineCapability: capability)){
            SaveCapability(payload.requestingMachineCapability);
            electionResultsKeys = keys(electionResults);
            i = 0;
            countCandidate0 = 0;
            countCandidate1 = 0;
            while (i < sizeof(electionResultsKeys)) {
                if (electionResults[electionResultsKeys[i]] == 0) {
                    countCandidate0 = countCandidate0 + 1;
                } else {
                    countCandidate1 = countCandidate1 + 1;
                }
                print "Incrementing candidate!";
                i = i + 1;
            }
            print "Count 0 - {0}", countCandidate0;
            print "Count 1 - {0}", countCandidate1;
            if (countCandidate0 > countCandidate1) {
                winner = 0;
            } else if (countCandidate1 > countCandidate0) {
                winner = 1;
            } else {
                winner = 2; //Tie
            }
            secure_send payload.requestingMachine, TRUSTEDeRespElectionResults, (allVotes = electionResults, whoWon = winner); 
        }
    }
}
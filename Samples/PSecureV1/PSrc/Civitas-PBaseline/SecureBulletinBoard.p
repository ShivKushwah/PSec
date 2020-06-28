/****************************************
Secure Bulletin Board machine
* Publicly display election results
* Votes are stored per credential, so they are anonymized
* Enable SecureVotingClients to verify their vote was included
*****************************************/

machine SecureBulletinBoardMachine
{
    var electionResults: map[StringType, int];
    
    start state Init {
        defer TRUSTEDeGetElectionResults;
        on TRUSTEDeElectionResults do (payload: map[StringType, int]) {
            electionResults = payload;
            goto SendResults;
        }
    }

    state SendResults { 
        on TRUSTEDeGetElectionResults do (requestingMachine: machine_handle){
            var electionResultsKeys : seq[StringType];
            var i : int;
            var countCandidate0 : int;
            var countCandidate1 : int;
            var winner : int;

            electionResultsKeys = keys(electionResults);
            i = 0;
            countCandidate0 = 0;
            countCandidate1 = 0;

            while (i < sizeof(electionResultsKeys)) {
                if (electionResults[electionResultsKeys[i]] == 0) {
                    //Vote for Candidate0
                    countCandidate0 = countCandidate0 + 1;
                } else {
                    //Vote for Candidate1
                    countCandidate1 = countCandidate1 + 1;
                }
                i = i + 1;
            }
            // print "Count 0 - {0}", countCandidate0;
            // print "Count 1 - {0}", countCandidate1;
            if (countCandidate0 > countCandidate1) {
                winner = 0;
            } else if (countCandidate1 > countCandidate0) {
                winner = 1;
            } else {
                winner = 2; //Tie
            }
            send requestingMachine, TRUSTEDeRespElectionResults, (allVotes = electionResults, whoWon = winner); //send
        }
    }
}
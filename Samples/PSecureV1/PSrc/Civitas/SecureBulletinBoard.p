/****************************************
Secure Bulletin Board machine
* Publicly display election results
* Votes are stored per credential, so they are anonymized
* Enable SecureVotingClients to verify their vote was included
*****************************************/

secure_machine SecureBulletinBoardMachine
{
    var electionResults: map[int, secure_int];
    
    start state Init {
        defer TRUSTEDeGetElectionResults;
        on TRUSTEDeElectionResults do (payload: map[int, secure_int]) {
            electionResults = payload;
            goto SendResults;
        }
    }

    state SendResults { 
        on TRUSTEDeGetElectionResults do (requestingMachine: secure_machine_handle){
            var electionResultsKeys : seq[int];
            var i : int;
            var countCandidate0 : secure_int;
            var countCandidate1 : secure_int;
            var winner : secure_int;

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
            secure_send requestingMachine, TRUSTEDeRespElectionResults, (allVotes = electionResults, whoWon = winner); 
        }
    }
}
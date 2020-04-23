/****************************************
Secure Bulletin Board machine
* Publicly display election results
* Votes are stored per credential, so they are anonymized
* Enable SecureVotingClients to verify their vote was included
*****************************************/

secure_machine SecureBulletinBoardMachine
{
    var electionResults: map[secure_StringType, secure_int];
    
    start state Init {
        defer TRUSTEDeGetElectionResults;
        on TRUSTEDeElectionResults do (payload: map[secure_StringType, secure_int]) {
            electionResults = payload;
            goto SendResults;
        }
    }

    state SendResults { 
        on TRUSTEDeGetElectionResults do (requestingMachine: secure_machine_handle){
            var electionResultsKeys : seq[secure_StringType];
            var i : int;
            var countCandidate0 : secure_int;
            var countCandidate1 : secure_int;
            var winner : secure_int;

            electionResultsKeys = keys(electionResults);
            i = 0;
            countCandidate0 = Endorse(0) as secure_int;
            countCandidate1 = Endorse(0) as secure_int;

            while (i < sizeof(electionResultsKeys)) {
                if (Declassify(electionResults[electionResultsKeys[i]]) as int == 0) {
                    //Vote for Candidate0
                    countCandidate0 = countCandidate0 + (Endorse(1) as secure_int);
                } else {
                    //Vote for Candidate1
                    countCandidate1 = countCandidate1 + (Endorse(1) as secure_int);
                }
                i = i + 1;
            }
            // print "Count 0 - {0}", countCandidate0;
            // print "Count 1 - {0}", countCandidate1;
            if (countCandidate0 > countCandidate1) {
                winner = Endorse(0) as secure_int;
            } else if (countCandidate1 > countCandidate0) {
                winner = Endorse(1) as secure_int;
            } else {
                winner = Endorse(2) as secure_int; //Tie
            }
            send requestingMachine, TRUSTEDeRespElectionResults, (allVotes = electionResults, whoWon = winner); //secure_send
        }
    }
}
/****************************************
* Bulletin Board Machine
* BulletinBoard -> VotingClient = RespElectionResults.
* BulletinBoard -> BallotBox = Confrimation.
* BulletinBoard -> TabulationTeller -> AllVotes.
*****************************************/

machine BulletinBoardMachine 
receives eAllVotes, eGetElectionResults;
sends eRespElectionResults;
{
    var allVotes : seq[Vote];
    var electionResults: map[int, int];
    start state Init {
        on eGetElectionResults do {
            print "Election Results not Available";
        }
        on eAllVotes do (payload: AllVotesInBallot) {
            allVotes = payload.votes;
            goto ComputeResults;
        }
    }

    state ComputeResults {
        entry {
            var i: int;
            i = 0;
            while(i < sizeof(allVotes))
            {
                //consider the latest vote
                //validate the credentials
                electionResults[allVotes[i].credentials] = allVotes[i].vote;
                i = i + 1;
            }
        }
        on eGetElectionResults do (p: machine){
            send p, eRespElectionResults, (allVotes = electionResults, whoWon = 0);
        }
    }
}
/*****************************
BallotBox Machine
* BallotBox -> BulletinBoard -> AllVotesFor.
******************************/

machine BallotBoxMachine
sends eAllVotes;
receives eVote, eStartElection, eCloseElection;
{
    var bulletinBoard: machine;
    var appendOnlyLog: machine;
    start state Init {
        entry (bBoard: machine){
            bulletinBoard = bBoard;
            appendOnlyLog = new TamperEvidentLogMachine(this);
        }
        on eStartElection goto WaitForVotes;
        on eVote do {
            print "Vote ignored, voting has not started yet !!";
        }
    }

    state WaitForVotes {
        on eVote do (payload: (Vote, machine))
        {
            send appendOnlyLog, eAddItem, payload.0;
            receive {
                case eRespAddItem : (result: bool) {
                    if(result)
                    {
                        send payload.1, eRespConfirmVote;
                    }
                }
            }
        }
        on eCloseElection goto VoteCounting;
    }

    state VoteCounting {
        entry {
            send appendOnlyLog, eGetLog;
            receive{
                case eRespGetLog: (p: seq[data])
                {
                    var vote: Vote;
                    var allVotes: map[int, int];
                    var i: int;
                    i = 0;
                    while(i < sizeof(p))
                    {
                        vote = p[i] as Vote;
                        //consider the latest vote
                        //validate the credentials
                        allVotes[vote.credentials] = vote.vote;
                        i = i + 1;
                    }
                    send bulletinBoard, eAllVotes, (ballotId = 0, votes = allVotes);
                }
            }

            goto WaitForGetResultsQuery;
        }


    }

    state WaitForGetResultsQuery {
            on eVote do {
            print "Vote ignored, voting phase is over";
        }
    }
}

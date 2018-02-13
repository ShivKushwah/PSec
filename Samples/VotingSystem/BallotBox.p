/*****************************
BallotBox Machine
* BallotBox -> BulletinBoard -> AllVotesFor.
******************************/

machine BallotBoxMachine
sends eAllVotes, eAddItem, eGetLog, eRespConfirmVote;
receives eVote, eStartElection, eCloseElection, eRespGetLog, eRespAddItem;
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
                    send bulletinBoard, eAllVotes, (ballotId = 0, votes = p as seq[Vote]);
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

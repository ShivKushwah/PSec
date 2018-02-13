/***************************
Voting Client Machine
* VotingClient -> BallotBox = eVote.
* VotingClient -> BulletinBoard = ConfirmVote.
* VotingClient -> BulletinBoard = GetElectionResults.
***************************/

machine VotingClientMachine
receives eRespConfirmVote, eRespElectionResults;
sends eVote, eGetElectionResults;
{
    //secret
    var credentials: int;
    var ballotBox: machine;
    var bulletinBoard: machine;
    start state Init {
        entry (payload:(bBox: machine, bBoard: machine)){
            var doVoting: bool;
            credentials = ReadCredentials();
            ballotBox = payload.bBox;
            bulletinBoard = payload.bBoard;
            doVoting = ReadOperationToPerform();
            if(doVoting)
                goto SubmitVote;
            else
                goto ValidateResults;
        }
    }

    fun ReadCredentials() : int;
    /* {
        return 1;
    }*/
    fun ReadOperationToPerform() : bool;
    /*{
        return $;
    }*/
    fun ReadVote(): int;
    /*{
        return 10;
    }*/

    state SubmitVote {
        entry {
            var vote : int;
            vote = ReadVote();
            send ballotBox, eVote, ((credentials = credentials, vote = vote), this);
        }
        on eRespConfirmVote goto Done with {
            print "Vote successfully submitted to the ballot box";
        }
    }

    state ValidateResults {
        entry {
            credentials = ReadCredentials();
            send bulletinBoard, eGetElectionResults, this;
        }
        on eRespElectionResults do (results: ElectionResults){
            var vote: int;
            if(!(credentials in results.allVotes))
            {
                print "My vote not found!!";
                raise halt;
            }
            else
            {
                print "Your vote for {0} was counted", results.allVotes[credentials];
            }
            print "{0} won the election", results.whoWon;
            goto Done;
        }
    }
    state Done {
        entry {
            print "Operation successfully performed, closing client safely";
            //this should close the enclave
            raise halt;
        }
    }

}









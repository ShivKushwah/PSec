/***************************
Secure VotingClient Machine
* Secure machine that VotingUSMs interact with 
that enables them to vote anonymously and securely
***************************/
secure_machine SecureVotingClientMachine
{
    var credential: int;
    var ballotBox: secure_machine_handle;
    var bulletinBoard: secure_machine_handle;
    var requestingMachine : machine_handle;

    start state Init {
        entry (payload: (ballotBox:secure_machine_handle, bulletinBoard:secure_machine_handle)) {
            //print out THIS here
            print "TEST1";
            PrintMachineHandle(this);
            ballotBox = payload.ballotBox;
            bulletinBoard = payload.bulletinBoard;
            goto WaitForVote;
        }
    }

    state WaitForVote {
        on UNTRUSTEDVoteRequest goto SubmitVote;
    }

    state SubmitVote {
        entry (payload: (credential : int, vote : int, requestingMachine : machine_handle)) {
            var secure_vote: secure_int;
            requestingMachine = payload.requestingMachine;
            secure_vote = payload.vote;
            credential = payload.credential;
            secure_send ballotBox, TRUSTEDeVote, (credential = credential, vote = payload.vote, requestingMachine = secure_this);
        }
        on TRUSTEDeRespConfirmVote goto ValidateResults with {
            print "Vote successfully submitted to the ballot box";
        }
    }

    state ValidateResults {
        entry {
            secure_send bulletinBoard, TRUSTEDeGetElectionResults, secure_this;
        }
        on TRUSTEDeRespElectionResults do (payload: (allVotes : map[int, secure_int], whoWon : secure_int)) {
            var winner : int;
            var voteCounted : bool;
            if(!(credential in payload.allVotes))
            {
                print "ERROR: Vote not found!";
                raise halt;
            }
            else
            {
                voteCounted = true;
            }
            print "HARBINDER";
            print "TEST2";
            PrintMachineHandle(this);
            //print out this here
            untrusted_send requestingMachine, UNTRUSTEDGetResults, (whoWon = DeclassifyInt(payload.whoWon), myVoteCounted = voteCounted);
            print "GURGY";
            goto Done;
        }
    }
    state Done {
        entry {
            print "Operation successfully performed, closing client safely";
            raise halt;
        }
    }

}

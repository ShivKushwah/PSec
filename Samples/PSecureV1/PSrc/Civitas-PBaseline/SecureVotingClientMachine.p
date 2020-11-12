/***************************
Secure VotingClient Machine
* Secure machine that VotingUSMs interact with 
that enables them to vote anonymously and securely
***************************/
machine SecureVotingClientMachine
{
    var credential: StringType;
    var ballotBox: machine_handle;
    var bulletinBoard: machine_handle;
    var requestingMachine : machine_handle;

    start state Init {
        on TRUSTEDProvisionSecureVotingClientMachine do (payload: (ballotBox:machine_handle, bulletinBoard:machine_handle)) {
            ballotBox = payload.ballotBox;
            bulletinBoard = payload.bulletinBoard;
            goto WaitForVote;
        }
    }

    state WaitForVote {
        on UNTRUSTEDVoteRequest goto SubmitVote;
    }

    state SubmitVote {
        entry (payload: (credential : StringType, vote : int, requestingMachine : machine_handle)) {
            var secure_vote: int;
            var i : int;
            i = 0;
            requestingMachine = payload.requestingMachine;
            secure_vote = payload.vote;
            credential = payload.credential;
            while (i < 18) {
                send ballotBox, TRUSTEDeVote, (credential = credential, vote = payload.vote, requestingMachine = this); //send
                i = i + 1;
            }
        }
        on TRUSTEDeRespConfirmVote goto ValidateResults with {
            print "Vote successfully submitted to the ballot box";
        }
    }

    state ValidateResults {
        ignore TRUSTEDeRespConfirmVote;
        entry {
            send bulletinBoard, TRUSTEDeGetElectionResults, this; //send
        }
        on TRUSTEDeRespElectionResults do (payload: (allVotes : map[StringType, int], whoWon : int)) {
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
            
            send requestingMachine, UNTRUSTEDGetResults, (whoWon = payload.whoWon, myVoteCounted = voteCounted); //untrusted_send, whoWon = DeclassifyInt(payload.whoWon)
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

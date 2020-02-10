/***************************
Secure VotingClient Machine
* Secure machine that VotingUSMs interact with 
that enables them to vote anonymously and securely
***************************/
secure_machine SecureVotingClientMachine
{
    var credential: int;
    var ballotBox: machine_handle;
    var bulletinBoard: machine_handle;
    var requestingMachine : machine_handle;

    start state Init {
        entry (payload: (ballotBox:machine_handle, bulletinBoard:machine_handle, ballotBoxCapability:capability, bulletinBoardCapability:capability)) {
            ballotBox = payload.ballotBox;
            bulletinBoard = payload.bulletinBoard;
            SaveCapability(payload.ballotBoxCapability);
            SaveCapability(payload.bulletinBoardCapability);
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
            secure_send ballotBox, TRUSTEDeVote, (credential = credential, vote = payload.vote, requestingMachine = GetThis(), requestingMachineCapability = GetCapability(GetThis()));
        }
        on TRUSTEDeRespConfirmVote goto ValidateResults with {
            print "Vote successfully submitted to the ballot box";
        }
    }

    state ValidateResults {
        entry {
            secure_send bulletinBoard, TRUSTEDeGetElectionResults, (requestingMachine = GetThis(), requestingMachineCapability = GetCapability(GetThis()));
        }
        on TRUSTEDeRespElectionResults do (payload: (allVotes : map[int, secure_int], whoWon : secure_int)) {
            if(!(credential in payload.allVotes))
            {
                print "ERROR: Vote not found!";
                raise halt;
            }
            else
            {
                print "Your vote for {0} was counted", DeclassifyInt(payload.allVotes[credential]);
            }
            print "{0} won the election", DeclassifyInt(payload.whoWon);
            // untrusted_send requestingMachine, UNTRUSTEDGetResults, (whoWon = DeclassifyInt(payload.whoWon), myVoteCounted = true);
            untrusted_send requestingMachine, UNTRUSTEDGetResults, DeclassifyInt(payload.whoWon);
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

/***************************
Secure VotingClient Machine
* Secure machine that VotingUSMs interact with 
that enables them to vote anonymously and securely
***************************/
secure_machine SecureVotingClientMachine
{
    var credential: secure_StringType;
    var ballotBox: secure_machine_handle;
    var bulletinBoard: secure_machine_handle;
    var requestingMachine : machine_handle;

    start state Init {
        on TRUSTEDProvisionSecureVotingClientMachine do (payload: (ballotBox:secure_machine_handle, bulletinBoard:secure_machine_handle)) {
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
            var secure_vote: secure_int;
            var i : int;
            i = 0;
            requestingMachine = payload.requestingMachine;
            secure_vote = Endorse(payload.vote) as secure_int;
            credential = Endorse(payload.credential) as secure_StringType;
            while (i < 1) {
                send ballotBox, TRUSTEDeVote, (credential = credential, vote = Endorse(payload.vote) as secure_int, requestingMachine = this); //secure_send
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
            send bulletinBoard, TRUSTEDeGetElectionResults, this; //secure_send
        }
        on TRUSTEDeRespElectionResults do (payload: (allVotes : map[secure_StringType, secure_int], whoWon : secure_int)) {
            var winner : int;
            var voteCounted : bool;
            
            if(Declassify(!(credential in payload.allVotes)) as bool)
            {
                print "ERROR: Vote not found!";
                raise halt;
            }
            else
            {
                voteCounted = true;
            }
            
            send requestingMachine, UNTRUSTEDGetResults, (whoWon = Declassify(payload.whoWon) as int, myVoteCounted = voteCounted); //untrusted_send, whoWon = DeclassifyInt(payload.whoWon)
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

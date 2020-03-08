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

    var temp_int_credential : secure_int;

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
            requestingMachine = payload.requestingMachine;
            secure_vote = payload.vote;
            credential = payload.credential;
            if (payload.credential == GenerateCredential1()) {
				temp_int_credential = 1775847362;
			} else {
				temp_int_credential = 1861262373;
			}
            send ballotBox, TRUSTEDeVote, (credential = credential, vote = payload.vote, requestingMachine = this); //secure_send
        }
        on TRUSTEDeRespConfirmVote goto ValidateResults with {
            print "Vote successfully submitted to the ballot box";
        }
    }

    state ValidateResults {
        entry {
            send bulletinBoard, TRUSTEDeGetElectionResults, this; //secure_send
        }
        on TRUSTEDeRespElectionResults do (payload: (allVotes : map[secure_StringType, secure_int], whoWon : secure_int)) {
            var winner : int;
            var voteCounted : bool;
            if(DeclassifyBool(!(credential in payload.allVotes)))
            {
                print "ERROR: Vote not found!";
                raise halt;
            }
            else
            {
                voteCounted = true;
            }
            
            send requestingMachine, UNTRUSTEDGetResults, (whoWon = DeclassifyInt(payload.whoWon), myVoteCounted = voteCounted); //untrusted_send, whoWon = DeclassifyInt(payload.whoWon)
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

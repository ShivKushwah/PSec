//d
/***************************
Voting Client Machine
* VotingClient -> BallotBox = eVote.
* VotingClient -> BulletinBoard = ConfirmVote.
* VotingClient -> BulletinBoard = GetElectionResults.
***************************/

//Enclave for each client that enables them to vote anonymously as well as change votes
secure_machine SecureVotingClientMachine
{
    var credential: int;
    var ballotBox: machine_handle;
    var bulletinBoard: machine_handle;
    var username: int;
    var password: int;

    start state Init {
        entry (payload: (ballotBox:machine_handle, bulletinBoard:machine_handle, username:int, password:int, ballotBoxCapability:capability, bulletinBoardCapability:capability)) {
            credential = payload.username + payload.password;//ReadCredentials(); //This function contacts RegistrationTellers to get
            // an anonymous credential so that no one knows how this machine voted
            username = payload.username;
            password = payload.password;
            ballotBox = payload.ballotBox;
            bulletinBoard = payload.bulletinBoard;
            SaveCapability(payload.ballotBoxCapability);
            SaveCapability(payload.bulletinBoardCapability);
            goto WaitForVote;
        }
    }

    // fun ReadCredentials() : int; 
    // /* {
    //     return 1;
    // }*/

    // fun ReadVote(): int;
    // /*{
    //     return 10;
    // }*/

    state WaitForVote {
        on UNTRUSTEDVoteRequest goto AcceptVote;
    }

    state AcceptVote {
        entry (payload: (username_attempt: int, password_attempt: int, vote: int)) {
            if (payload.username_attempt == username && payload.password_attempt == password) {
                goto SubmitVote, payload.vote;
            } else {
                goto WaitForVote;
            }
        }
    }

    state SubmitVote {
        entry (vote : int) {
            secure_send ballotBox, TRUSTEDeVote, (credential = credential, vote = vote, requestingMachine = GetThis(), requestingMachineCapability = GetCapability(GetThis()));
    //         //Highlight NOTE: "this" is public ID of this machine, so it can receive a confirmation
        }
        on TRUSTEDeRespConfirmVote goto ValidateResults with {
            print "Vote successfully submitted to the ballot box";
        }
    }

    state ValidateResults {
        entry {
            secure_send bulletinBoard, TRUSTEDeGetElectionResults, (requestingMachine = GetThis(), requestingMachineCapability = GetCapability(GetThis()));
        }
        on TRUSTEDeRespElectionResults do (payload: (allVotes : map[int, int], whoWon : int)) {
            if(!(credential in payload.allVotes))
            {
                print "ERROR";
                print "My vote not found!!";
                // raise halt;
            }
            else
            {
                print "Your vote for {0} was counted", payload.allVotes[credential];
            }
            print "{0} won the election", payload.whoWon;
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

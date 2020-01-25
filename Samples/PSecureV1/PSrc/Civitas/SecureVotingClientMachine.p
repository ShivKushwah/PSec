/***************************
Voting Client Machine
* VotingClient -> BallotBox = eVote.
* VotingClient -> BulletinBoard = ConfirmVote.
* VotingClient -> BulletinBoard = GetElectionResults.
***************************/

//Enclave for each client that enables them to vote anonymously as well as change votes
secure_machine SecureVotingClientMachine
{
    var credentials: secure_int;
    var ballotBox: machine_handle;
    var bulletinBoard: machine_handle;
    var username: secure_int;
    var password: secure_int;

    start state Init {
        entry (payload:(machine_handle, machine_handle, int, int)){
            // credentials = ReadCredentials(); //This function contacts RegistrationTellers to get
            // // an anonymous credential so that no one knows how this machine voted
            // username = usrName;
            // password = pw;
            // ballotBox = payload.bBox;
            // bulletinBoard = payload.bBoard;
            // goto WaitForVote;
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

    // state WaitForVote {
    //     on UNTRUSTEDVoteRequest goto AcceptVote;
    // }

    // state AcceptVote {
    //     entry (payload: (username_attempt: int, password_attempt: int, vote: int)) {
    //         if (payload.0 == username && payload.1 == password) {
    //             goto SubmitVote, payload.2;
    //         } else {
    //             goto WaitForVote;
    //         }
    //     }
    // }

    // state SubmitVote {
    //     entry (vote : int) {
    //         secure_send ballotBox, TRUSTEDeVote, ((credentials = credentials, vote = vote), this);
    //         //Highlight NOTE: "this" is public ID of this machine, so it can receive a confirmation
    //     }
    //     on TRUSTEDeRespConfirmVote goto ValidateResults with {
    //         print "Vote successfully submitted to the ballot box";
    //         goto ValidateResults;
    //     }
    // }

    // state ValidateResults {
    //     entry {
    //         secure_send bulletinBoard, TRUSTEDeGetElectionResults, this;
    //     }
    //     on TRUSTEDeRespElectionResults do (results: ElectionResults){
    //         var vote: int;
    //         if(!(credentials in results.allVotes))
    //         {
    //             print "My vote not found!!";
    //             raise halt;
    //         }
    //         else
    //         {
    //             print "Your vote for {0} was counted", results.allVotes[credentials];
    //         }
    //         print "{0} won the election", results.whoWon;
    //         goto Done;
    //     }
    // }
    // state Done {
    //     entry {
    //         print "Operation successfully performed, closing client safely";
    //         //this should close the enclave
    //         raise halt;
    //     }
    // }

}

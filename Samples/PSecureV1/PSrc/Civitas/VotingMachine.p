/***************************
Untrusted Voting Client Machine
* Voter uses this machine to connect to the SecureVotingClient 
to be able to vote.
* Voter must pass in their credential they obtained during the registration phase 
***************************/
machine VotingUSM {

	var supervisor: machine_handle;
	var votingSecureMachine: machine_handle;
	var credential: int;
	var vote: int;


	start state Init {
        entry (payload: (supervisor: machine_handle, credential: int)) {
			supervisor = payload.supervisor;
			credential = payload.credential;

			untrusted_send supervisor, UNTRUSTEDGetVotingSSM, GetThis();
			
		}
		on UNTRUSTEDReceiveVotingSSM goto Vote;
	}

	state Vote {
		entry (payload: machine_handle) {
			votingSecureMachine = payload;
			vote = 1;
			untrusted_send votingSecureMachine, UNTRUSTEDVoteRequest, (credential = credential, vote = vote, requestingMachine = GetThis());
			receive {
				// case UNTRUSTEDGetResults : (payload : (whoWon : int, myVoteCounted : bool)) {
				// 	if (payload.myVoteCounted) {
				// 		print "My vote was successfully counted!";
				// 	} else {
				// 		print "ERROR: My vote was not counted!";
				// 	}
				// 	print "{0} won the election", payload.whoWon;
				// 	goto Done;
				// }
				case UNTRUSTEDGetResults : (whoWon : int) {
					print "{0} won the election", whoWon;
					goto Done;
				}
			}
		}
	}

	state Done {

	}
	
}
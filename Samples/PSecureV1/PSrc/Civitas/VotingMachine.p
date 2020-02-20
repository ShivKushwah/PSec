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

			untrusted_send supervisor, UNTRUSTEDGetVotingSSM, this;
			
		}
		on UNTRUSTEDReceiveVotingSSM goto Vote;
	}

	state Vote {
		entry (payload: machine_handle) {
			votingSecureMachine = payload;
			vote = 1;
			print "HARPREET";
			PrintMachineHandle(votingSecureMachine);
			untrusted_send votingSecureMachine, UNTRUSTEDVoteRequest, (credential = credential, vote = vote, requestingMachine = this);
			print "Kiran";
			PrintMachineHandle(votingSecureMachine);	
			//make foreign function to check PublicIdentityKey of votingSecureMachine
		}
		on UNTRUSTEDGetResults do (payload : (whoWon : int, myVoteCounted : bool)) {
				if (payload.myVoteCounted) {
					print "My vote was successfully counted!\n";
				} else {
					print "ERROR: My vote was not counted!\n";
				}
				print "{0} won the election\n", payload.whoWon;
				goto Done;
		}
	}

	state Done {

	}
	
}
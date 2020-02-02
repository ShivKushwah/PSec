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
			untrusted_send votingSecureMachine, UNTRUSTEDVoteRequest, (credential = credential, vote = vote);
			goto Done;
		}
	}

	state Done {

	}
	
}
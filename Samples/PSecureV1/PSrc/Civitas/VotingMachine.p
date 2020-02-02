//d
//Represents the untrusted user inputting their vote. Sends voting request to VotingClient to vote securely.
machine VotingUSM {

	var supervisor: machine_handle;
	var votingSecureMachine: machine_handle;
	var credential: int;
	var vote: int;


	start state Init {
        entry (payload: (supervisor: machine_handle, credential: int)) {
			supervisor = payload.supervisor;
			credential = payload.credential; //TODO get string input

			untrusted_send supervisor, UNTRUSTEDGetVotingSSM, GetThis();
			
		}
		on UNTRUSTEDReceiveVotingSSM goto Vote;
	}

	state Vote {
		entry (payload: machine_handle) {
			votingSecureMachine = payload;
			vote = 1; //TODO get int input
			untrusted_send votingSecureMachine, UNTRUSTEDVoteRequest, (credential = credential, vote = vote);
			goto Done;
		}
	}

	state Done {

	}
	
}
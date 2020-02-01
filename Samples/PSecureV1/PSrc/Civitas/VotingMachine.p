//d
//Represents the untrusted user inputting their vote. Sends voting request to VotingClient to vote securely.
machine VotingUSM {

	var supervisor: machine_handle;
	var votingSecureMachine: machine_handle;
	var username: int;
	var password: int;
	var vote: int;


	start state Init {
        entry (payload: (parent: machine_handle, username: int, password: int)) {
			supervisor = payload.parent;
			username = payload.username; //TODO get string input
			password = payload.password;

			untrusted_send supervisor, UNTRUSTEDGetVotingSSM, (requestingMachine = GetThis(), username = username); //TODO Ask about this
			
		}
		on UNTRUSTEDReceiveVotingSSM goto Vote;
	}

	state Vote {
		entry (payload: machine_handle) {
			votingSecureMachine = payload;
			vote = 1; //TODO get int input
			untrusted_send votingSecureMachine, UNTRUSTEDVoteRequest, (username_attempt = username, password_attempt = password, vote = vote);
			goto Done;
		}
	}

	state Done {

	}
	
}
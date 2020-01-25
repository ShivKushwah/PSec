//Represents the untrusted user inputting their vote. Sends voting request to VotingClient to vote securely.
machine VotingUSM {

	var supervisor: machine_handle;
	var votingSecureMachine: machine_handle;
	var username: int;
	var password: int;


	start state Init {
        entry (payload: machine_handle) {
			supervisor = payload;
			username = 2;
			password = 2;

            // 	username = payload.1;
		    // 	password = payload.2;

			untrusted_send supervisor, UNTRUSTEDGetVotingSSM, (GetThis(), username); //TODO Ask about this
			
		}
		on UNTRUSTEDReceiveVotingSSM goto Vote;
	}

	state Vote {
		entry (payload: machine_handle) {
			votingSecureMachine = payload;
			untrusted_send votingSecureMachine, UNTRUSTEDVoteRequest, (username, password, 1);
			goto Done;
		}
	}

	state Done {

	}
	
}
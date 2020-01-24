//Represents the untrusted user inputting their vote. Sends voting request to VotingClient to vote securely.
machine VotingUSM {

	var supervisor: machine_handle;
	var votingSecureMachine: machine_handle;
	var username: int;
	var password: int;


	start state Init {
        entry (payload: machine_handle) {
			supervisor = payload;

            // 	username = payload.1;
		    // 	password = payload.2;

			// untrusted_send supervisor, UNTRUSTEDGetVotingSSM, (this, username); //TODO Ask about this
			
		}
		// entry (payload: (supervisor: secure_machine, username: int, password: int)) {
		// 	supervisor = payload.0;

		// 	username = payload.1;
		// 	password = payload.2;

		// 	untrusted_send supervisor, UNTRUSTEDGetVotingSSM, (this, username); //TODO Ask about this
			
		// }
		// on UNTRUSTEDReceiveVotingSSM goto Vote;
	}

	state Vote {
		// entry (payload: secure_machine) {
		// 	votingSecureMachine = payload;
		// 	untrusted_send votingSecureMachine, UNTRUSTEDVoteRequest, (username, pw, 1);
		// 	goto Done;
		// }
	}

	state Done {

	}
	
}
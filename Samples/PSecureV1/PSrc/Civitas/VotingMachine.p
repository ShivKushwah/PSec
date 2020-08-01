/***************************
Untrusted Voting Client Machine
* Voter uses this machine to connect to the SecureVotingClient 
to be able to vote.
* Voter must pass in their credential they obtained during the registration phase 
***************************/
machine VotingUSM {

	var supervisor: machine_handle;
	var votingSecureMachine: machine_handle;
	var credential: StringType;
	var vote: int;


	start state Init {
		on UNTRUSTEDProvisionVotingUSM do (payload: (supervisor: machine_handle, credential: StringType)) {
			print "VotingUSM ready!";
			print "MEASURE BASELINE START:";
            MeasureTime();
			supervisor = payload.supervisor;
			credential = payload.credential;

			send supervisor, UNTRUSTEDGetVotingSSM, this; //untrusted_send
			
		}
		on UNTRUSTEDReceiveVotingSSM goto Vote;
	}

	state Vote {
		entry (payload: machine_handle) {
			var machineTypeToValidate : string;
			votingSecureMachine = payload;
			machineTypeToValidate = "SecureVotingClientMachine";
            if (localAuthenticate(votingSecureMachine, machineTypeToValidate)) {
                print "Authenticated installed enclave!";
            }
			vote = 1;
			send votingSecureMachine, UNTRUSTEDVoteRequest, (credential = credential, vote = vote, requestingMachine = this); //untrusted_send
		}
		on UNTRUSTEDGetResults do (payload : (whoWon : int, myVoteCounted : bool)) {
				if (payload.myVoteCounted) {
					print "My vote was successfully counted!\n";
				} else {
					print "ERROR: My vote was not counted!\n";
				}
				print "{0} won the election\n", payload.whoWon;
				print "MEASURE BASELINE END:";
            	MeasureTime();
				EXIT();
				goto Done;
		}
	}

	state Done {

	}
	
}
machine InitializerMachine {

	var supervisor: machine_handle;
	var votingMachine: machine_handle;
	var votingMachine2: machine_handle;
	// var supervisor2: secure_machine_handle;
	// var votingMachine3: secure_machine_handle;


	start state Init {
		entry {
			supervisor = new SecureSupervisorMachine();
			// supervisor2 = new SecureSupervisorMachine();
			votingMachine = new VotingUSM(); 
			send votingMachine, UNTRUSTEDProvisionVotingUSM, (supervisor = supervisor, credential = 177584736); //untrusted_send
			votingMachine2 = new VotingUSM();
			send votingMachine2, UNTRUSTEDProvisionVotingUSM, (supervisor = supervisor, credential = 986126237); //untrusted_send
			// votingMachine3 = new VotingUSM((supervisor = supervisor, credential = 98));
			
		}
	}
	
}
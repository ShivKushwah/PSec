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
			untrusted_send votingMachine, UNTRUSTEDProvisionVotingUSM, (supervisor = supervisor, credential = 17);
			votingMachine2 = new VotingUSM();
			untrusted_send votingMachine2, UNTRUSTEDProvisionVotingUSM, (supervisor = supervisor, credential = 98);
			// votingMachine3 = new VotingUSM((supervisor = supervisor, credential = 98));
			
		}
	}
	
}
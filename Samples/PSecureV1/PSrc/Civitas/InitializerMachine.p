machine InitializerMachine {

	var supervisor: machine_handle;
	var votingMachine: machine_handle;
	var votingMachine2: machine_handle;


	start state Init {
		entry {
			// supervisor = new SecureSupervisor();
			// votingMachine = new VotingUSM(supervisor);
			// votingMachine2 = new VotingUSM(supervisor);
		}
	}
	
}
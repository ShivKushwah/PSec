machine InitializerMachine {

	var supervisor: machine_handle;
	var votingMachine: machine_handle;
	var votingMachine2: machine_handle;


	start state Init {
		entry {
			supervisor = new SecureSupervisorMachine();
			votingMachine = new VotingUSM((supervisor = supervisor, credential = 17)); 
			votingMachine2 = new VotingUSM((supervisor = supervisor, credential = 7));
			
		}
	}
	
}
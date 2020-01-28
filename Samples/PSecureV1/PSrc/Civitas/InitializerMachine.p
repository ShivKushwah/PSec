machine InitializerMachine {

	var supervisor: machine_handle;
	var votingMachine: machine_handle;
	var votingMachine2: machine_handle;


	start state Init {
		entry {
			supervisor = new SecureSupervisorMachine();
			votingMachine = new VotingUSM((parent = supervisor, username = 2, password = 2)); //TODO how did passing new VotingUSM(supervisor, 2, 2) pass in type checker? thats not even a tuple?
			votingMachine2 = new VotingUSM((parent = supervisor, username = 1, password = 1));
		}
	}
	
}
machine InitializerMachine {

	var supervisor: machine_handle;
	var votingMachine: machine_handle;
	var votingMachine2: machine_handle;

	start state Init {
		entry {
			supervisor = new SecureSupervisorMachine();
			votingMachine = new VotingUSM(); 
			send votingMachine, UNTRUSTEDProvisionVotingUSM, (supervisor = supervisor, credential = GenerateCredential1()); //untrusted_send
			votingMachine2 = new VotingUSM();
			send votingMachine2, UNTRUSTEDProvisionVotingUSM, (supervisor = supervisor, credential = GenerateCredential2()); //untrusted_send			
		}
	}
	
}
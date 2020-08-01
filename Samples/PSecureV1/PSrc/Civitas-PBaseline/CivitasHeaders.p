//Civitas Events
event UNTRUSTEDGetVotingSSM : machine_handle;
event UNTRUSTEDReceiveVotingSSM : machine_handle;
event UNTRUSTEDVoteRequest : (credential : StringType, vote : int, requestingMachine : machine_handle);
event UNTRUSTEDGetResults : (whoWon : int, myVoteCounted : bool);
event UNTRUSTEDProvisionVotingUSM : (supervisor : machine_handle, credential : StringType);
event UNTRUSTEDSendSealedVote : sealed_data;
event eCloseElection;

event TRUSTEDeStartElection : int;
event TRUSTEDeVote : (credential : StringType, vote : int, requestingMachine: machine_handle);
event TRUSTEDeAddItem : (credential: StringType, vote: int);
event TRUSTEDeRespAddItem : bool;
event TRUSTEDeRespConfirmVote;
event TRUSTEDeGetLog;
event TRUSTEDeRespGetLog : seq[(credential : StringType, vote : int)];
event TRUSTEDeAllVotes : (ballotID : int, votes : seq[(credential : StringType, vote : int)]);
event TRUSTEDValidateCredential : (tabulationTellerMachine : machine_handle, credentialToCheck : StringType);
event TRUSTEDValidCredential;
event TRUSTEDInvalidCredential;
event TRUSTEDeElectionResults : map[StringType, int];
event TRUSTEDeRespElectionResults: (allVotes : map[StringType, int], whoWon : int);
event TRUSTEDeGetElectionResults : machine_handle;
event TRUSTEDProvisionSecureTamperEvidentLogMachine : machine_handle;
event TRUSTEDProvisionSecureTabulationTellerMachine : (bBoard : machine_handle, supervisor : machine_handle);
event TRUSTEDProvisionSecureBallotBoxMachine : (bBoard : machine_handle, supervisor : machine_handle);
event TRUSTEDProvisionSecureVotingClientMachine : (ballotBox : machine_handle, bulletinBoard : machine_handle);

//Civitas Functions
fun GenerateCredential1() : StringType;
fun GenerateCredential2() : StringType;
fun PrintKey(input : machine_handle);
fun PrintPCapability(input : capability);
fun PrintString(inputString : StringType);
fun PrintMachineHandle(inputString : machine_handle);
fun EXIT();
fun MeasureTime();
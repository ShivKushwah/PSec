type StringType;
type machine_handle;
type capability;
type secure_machine_handle;

//Foreign Functions callable from P Code
fun PrintKey(input : machine_handle);
fun PrintPCapability(input : capability);
fun PrintString(inputString : StringType);

//TODO Make below functions P commands rather than Foreign functions user needs to call
fun GetCapability(input: machine_handle) : capability; //Should be "get_capability"
fun SaveCapability(input: capability); //Should be "save_capability"
fun GetThis() : machine_handle; //Should be "this"
fun DeclassifyInt(input : secure_int) : int;
fun CastHandle(input : secure_machine_handle) : machine_handle;

//Functions necessary for .h file, should not be called by user
//TODO Add to PrtCodeGenerator
// fun CreateMachineSecureChild(): machine_handle;
fun CreateSecureMachineRequest(): secure_machine_handle;
fun CreateUSMMachineRequest(): machine_handle;

event UNTRUSTEDGetVotingSSM : machine_handle;
event UNTRUSTEDReceiveVotingSSM : machine_handle;
event UNTRUSTEDVoteRequest : (credential : int, vote : int, requestingMachine : machine_handle);
event UNTRUSTEDGetResults : (whoWon : int, myVoteCounted : bool);
// event UNTRUSTEDGetResults : int;
trusted event TRUSTEDeStartElection : int;
trusted event TRUSTEDeVote : (credential : int, vote : secure_int, requestingMachine: machine_handle, requestingMachineCapability: capability);
trusted event TRUSTEDeAddItem : (credential: int, vote: secure_int);
trusted event TRUSTEDeRespAddItem : bool;
trusted event TRUSTEDeRespConfirmVote;
event eCloseElection;
trusted event TRUSTEDeGetLog;
trusted event TRUSTEDeRespGetLog : seq[(credential : int, vote : secure_int)];
trusted event TRUSTEDeAllVotes : (ballotID : int, votes : seq[(credential : int, vote : secure_int)]);
trusted event TRUSTEDValidateCredential : (tabulationTellerMachine : machine_handle, tabulationTellerCapability : capability, credentialToCheck : int);
trusted event TRUSTEDValidCredential;
trusted event TRUSTEDInvalidCredential;
trusted event TRUSTEDeElectionResults : map[int, secure_int];
trusted event TRUSTEDeRespElectionResults: (allVotes : map[int, secure_int], whoWon : secure_int);
trusted event TRUSTEDeGetElectionResults : (requestingMachine: machine_handle, requestingMachineCapability: capability);
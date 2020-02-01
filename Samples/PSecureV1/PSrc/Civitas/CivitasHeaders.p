type StringType;
type machine_handle;
type capability;

//Foreign Functions callable from P Code
fun PrintKey(input : machine_handle);
fun PrintPCapability(input : capability);
fun PrintString(inputString : StringType);

//TODO Make below functions P commands rather than Foreign functions user needs to call
fun GetCapability(input: machine_handle) : capability; //Should be "get_capability"
fun SaveCapability(input: capability); //Should be "save_capability"
fun GetThis() : machine_handle; //Should be "this"

//Functions necessary for .h file, should not be called by user
//TODO Add to PrtCodeGenerator
fun CreateMachineSecureChild(): machine_handle;
fun CreateSecureMachineRequest(): machine_handle;
fun CreateUSMMachineRequest(): machine_handle;


event UNTRUSTEDGetVotingSSM : (requestingMachine:machine_handle, username:int);
event StrEvent : StringType;
event UNTRUSTEDReceiveVotingSSM : machine_handle;
event UNTRUSTEDVoteRequest : (username_attempt : int, password_attempt : int, vote : int);
trusted event TRUSTEDeStartElection : int;
trusted event TRUSTEDeVote : (credential : int, vote : int, requestingMachine: machine_handle, requestingMachineCapability: capability);
trusted event TRUSTEDeAddItem : (credential: int, vote: int);
trusted event TRUSTEDeRespAddItem : bool;
trusted event TRUSTEDeRespConfirmVote;
event eCloseElection;
trusted event TRUSTEDeGetLog;
trusted event TRUSTEDeRespGetLog : seq[(credential : int, vote : int)];
trusted event TRUSTEDeAllVotes : (ballotID : int, votes : seq[(credential : int, vote : int)]);
trusted event TRUSTEDeElectionResults : map[int, int];
trusted event TRUSTEDeRespElectionResults: (allVotes : map[int, int], whoWon : int);
trusted event TRUSTEDeGetElectionResults : (requestingMachine: machine_handle, requestingMachineCapability: capability);
type StringType;
type machine_handle;
type capability;

//Foreign Functions callable from P Code
fun PrintKey(input : machine_handle);
fun PrintPCapability(input : capability);
fun PrintString(inputString : StringType);

fun GetThis() : machine_handle;
fun CreateMachineSecureChild(): machine_handle;
fun CreateSecureMachineRequest(): machine_handle;
fun CreateUSMMachineRequest(): machine_handle;

fun GetCapability(input: machine_handle) : capability;
fun SaveCapability(input: capability);
fun GetUserInput() : StringType;

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
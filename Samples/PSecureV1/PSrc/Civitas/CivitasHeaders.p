type StringType;
type machine_handle;
type capability;
type secure_machine_handle;
type secure_StringType;

//Foreign Functions callable from P Code
fun PrintKey(input : machine_handle);
fun PrintPCapability(input : capability);
fun PrintString(inputString : StringType);
fun PrintMachineHandle(inputString : machine_handle);

//TODO Make below functions P commands rather than Foreign functions user needs to call
fun GetCapability(input: machine_handle) : capability; //Should be "get_capability"
fun SaveCapability(input: capability); //Should be "save_capability"
fun GetThis() : machine_handle; //Should be "this"
// fun GetThisSecure() : secure_machine_handle; //Should be "this"
fun DeclassifyInt(input : secure_int) : int;
fun DeclassifyBool(input : secure_bool) : bool;
fun DeclassifyHandle(input : secure_machine_handle) : machine_handle;

fun GenerateCredential1() : StringType;
fun GenerateCredential2() : StringType;

// fun Declassify(input : secure_int) : int;
// fun Declassify(input : secure_StringType) : StringType;

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
trusted event TRUSTEDeVote : (credential : secure_int, vote : secure_int, requestingMachine: secure_machine_handle);
trusted event TRUSTEDeAddItem : (credential: secure_int, vote: secure_int);
trusted event TRUSTEDeRespAddItem : bool;
trusted event TRUSTEDeRespConfirmVote;
event eCloseElection;
trusted event TRUSTEDeGetLog;
trusted event TRUSTEDeRespGetLog : seq[(credential : secure_int, vote : secure_int)];
trusted event TRUSTEDeAllVotes : (ballotID : int, votes : seq[(credential : secure_int, vote : secure_int)]);
trusted event TRUSTEDValidateCredential : (tabulationTellerMachine : secure_machine_handle, credentialToCheck : secure_int);
trusted event TRUSTEDValidCredential;
trusted event TRUSTEDInvalidCredential;
trusted event TRUSTEDeElectionResults : map[secure_int, secure_int];
trusted event TRUSTEDeRespElectionResults: (allVotes : map[secure_int, secure_int], whoWon : secure_int);
trusted event TRUSTEDeGetElectionResults : secure_machine_handle;

event UNTRUSTEDProvisionVotingUSM : (supervisor : machine_handle, credential : StringType);
trusted event TRUSTEDProvisionSecureTamperEvidentLogMachine : secure_machine_handle;
trusted event TRUSTEDProvisionSecureTabulationTellerMachine : (bBoard : secure_machine_handle, supervisor : secure_machine_handle);
trusted event TRUSTEDProvisionSecureBallotBoxMachine : (bBoard : secure_machine_handle, supervisor : secure_machine_handle);
trusted event TRUSTEDProvisionSecureVotingClientMachine : (ballotBox : secure_machine_handle, bulletinBoard : secure_machine_handle);
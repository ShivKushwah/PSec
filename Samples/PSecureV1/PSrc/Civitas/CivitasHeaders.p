//Civitas Events
event UNTRUSTEDGetVotingSSM : machine_handle;
event UNTRUSTEDReceiveVotingSSM : machine_handle;
event UNTRUSTEDVoteRequest : (credential : StringType, vote : int, requestingMachine : machine_handle);
event UNTRUSTEDGetResults : (whoWon : int, myVoteCounted : bool);
event UNTRUSTEDProvisionVotingUSM : (supervisor : machine_handle, credential : StringType);
event eCloseElection;

trusted event TRUSTEDeStartElection : secure_int;
trusted event TRUSTEDeVote : (credential : secure_StringType, vote : secure_int, requestingMachine: secure_machine_handle);
trusted event TRUSTEDeAddItem : (credential: secure_StringType, vote: secure_int);
trusted event TRUSTEDeRespAddItem : secure_bool;
trusted event TRUSTEDeRespConfirmVote;
trusted event TRUSTEDeGetLog;
trusted event TRUSTEDeRespGetLog : seq[(credential : secure_StringType, vote : secure_int)];
trusted event TRUSTEDeAllVotes : (ballotID : secure_int, votes : seq[(credential : secure_StringType, vote : secure_int)]);
trusted event TRUSTEDValidateCredential : (tabulationTellerMachine : secure_machine_handle, credentialToCheck : secure_StringType);
trusted event TRUSTEDValidCredential;
trusted event TRUSTEDInvalidCredential;
trusted event TRUSTEDeElectionResults : map[secure_StringType, secure_int];
trusted event TRUSTEDeRespElectionResults: (allVotes : map[secure_StringType, secure_int], whoWon : secure_int);
trusted event TRUSTEDeGetElectionResults : secure_machine_handle;
trusted event TRUSTEDProvisionSecureTamperEvidentLogMachine : secure_machine_handle;
trusted event TRUSTEDProvisionSecureTabulationTellerMachine : (bBoard : secure_machine_handle, supervisor : secure_machine_handle);
trusted event TRUSTEDProvisionSecureBallotBoxMachine : (bBoard : secure_machine_handle, supervisor : secure_machine_handle);
trusted event TRUSTEDProvisionSecureVotingClientMachine : (ballotBox : secure_machine_handle, bulletinBoard : secure_machine_handle);

//Civitas Functions
fun GenerateCredential1() : StringType;
fun GenerateCredential2() : StringType;
fun PrintKey(input : machine_handle);
fun PrintPCapability(input : capability);
fun PrintString(inputString : StringType);
fun PrintMachineHandle(inputString : machine_handle);

/**
 * PSec Internal Library
 */
 //TODO Potentially add to PrtCodeGenerator
type StringType;
type machine_handle;
type capability;
type secure_machine_handle;
type secure_StringType;

fun Declassify(input : any) : any;
fun Endorse(input : any) : any;

fun GetThis() : machine_handle;

fun CreateSecureMachineRequest(): secure_machine_handle;
fun CreateUSMMachineRequest(): machine_handle;


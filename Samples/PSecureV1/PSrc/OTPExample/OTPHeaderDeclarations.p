type StringType;
type machine_handle;
type capability;
type secure_machine_handle;
type secure_StringType;

// fun CreateMachineSecureChild(): machine_handle;
// fun PrintString(inputString : StringType);
fun PrintString(inputString : StringType);
fun PrintRawStringType(inputString : StringType);
fun PrintRawSecureStringType(inputString : secure_StringType);

fun Declassify(input : any) : any;

fun Classify(input : any) : any;


// fun SecureSend(sendingToMachine : secure_machine_handle, eventToSend : event, numArgs : int, arg : int);
fun GetThis() : machine_handle;
fun Concat(input1:StringType, input2:StringType) : StringType;
fun Hash(input1:StringType, input2:StringType) : StringType;
// fun UntrustedCreateCoordinator();
// fun UntrustedSend(publicID: machine_handle, even : event, payload: int);
// fun InitializeUntrustedMachine();
fun CreateSecureMachineRequest(): secure_machine_handle;
fun CreateUSMMachineRequest(): machine_handle;
fun PrintKey(input : machine_handle);
fun GenerateRandomMasterSecret() : StringType;
fun GetUserInput() : StringType;
// fun CastHandle(input : secure_machine_handle) : machine_handle;

fun MeasureTime();

event BankPublicIDEvent : machine_handle;
event PublicIDEvent : machine_handle;
event UNTRUSTEDReceiveRegistrationCredentials : StringType;
trusted event MasterSecretEvent: secure_StringType;
event GenerateOTPCodeEvent : StringType;
event OTPCodeEvent : StringType;
trusted event MapEvent: map[secure_int, secure_int];
event AuthenticateRequest : (usernamePW : StringType, OTPCode : StringType);
event AuthSuccess;
event AuthFailure;

trusted event TRUSTEDProvisionBankSSM : secure_machine_handle;
trusted event TRUSTEDProvisionClientSSM : secure_machine_handle;

// //Measurement Code
// type StringType;
// type machine_handle;
// type capability;
// type secure_machine_handle;
// type secure_StringType;

// // fun CreateMachineSecureChild(): machine_handle;
// // fun PrintString(inputString : StringType);
// fun PrintString(inputString : StringType);
// fun PrintRawStringType(inputString : StringType);
// fun PrintRawSecureStringType(inputString : secure_StringType);

// fun Declassify(input : any) : any;

// fun Classify(input : any) : any;


// // fun SecureSend(sendingToMachine : secure_machine_handle, eventToSend : event, numArgs : int, arg : int);
// fun GetThis() : machine_handle;
// fun Concat(input1:StringType, input2:StringType) : StringType;
// fun Hash(input1:StringType, input2:StringType) : StringType;
// // fun UntrustedCreateCoordinator();
// // fun UntrustedSend(publicID: machine_handle, even : event, payload: int);
// // fun InitializeUntrustedMachine();
// fun CreateSecureMachineRequest(): secure_machine_handle;
// fun CreateUSMMachineRequest(): machine_handle;
// fun PrintKey(input : machine_handle);
// fun GenerateRandomMasterSecret() : StringType;
// fun GetUserInput() : StringType;
// // fun CastHandle(input : secure_machine_handle) : machine_handle;
// fun GetHelloWorld() : StringType;

// fun MeasureTime();

// trusted event TRUSTEDMeasureEvent1 : (fst: secure_int, snd: secure_StringType);
// trusted event TRUSTEDMeasureEvent2 : (fst: secure_int, snd: secure_StringType);
// event MeasureEvent1 : (fst: int, snd: StringType);
// event MeasureEvent2 : (fst: int, snd: StringType);

// event BankPublicIDEvent : machine_handle;
// event PublicIDEvent : machine_handle;
// event UNTRUSTEDReceiveRegistrationCredentials : StringType;
// trusted event MasterSecretEvent: secure_StringType;
// event GenerateOTPCodeEvent : StringType;
// event OTPCodeEvent : StringType;
// trusted event MapEvent: map[secure_int, secure_int];
// event AuthenticateRequest : (usernamePW : StringType, OTPCode : StringType);
// event AuthSuccess;
// event AuthFailure;

// trusted event TRUSTEDProvisionBankSSM : secure_machine_handle;
// trusted event TRUSTEDProvisionClientSSM : secure_machine_handle;
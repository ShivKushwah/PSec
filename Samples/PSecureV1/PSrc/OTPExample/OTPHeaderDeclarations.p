type StringType;
type machine_handle;

fun CreateMachineSecureChild(): machine_handle;
fun PrintString(inputString : StringType);
fun SecureSend(sendingToMachine : machine_handle, eventToSend : event, numArgs : int, arg : int);
fun GetThis() : machine_handle;
fun Concat(input1:StringType, input2:StringType) : StringType;
fun Hash(input1:StringType, input2:StringType) : StringType;
fun UntrustedCreateCoordinator();
fun UntrustedSend(publicID: machine_handle, even : event, payload: int);
fun InitializeUntrustedMachine();
fun CreateSecureMachineRequest(): machine_handle;
fun CreateUSMMachineRequest(): machine_handle;
fun PrintKey(input : machine_handle);
fun GenerateRandomMasterSecret() : StringType;
fun GetUserInput() : StringType;

event BankPublicIDEvent : machine_handle;
event PublicIDEvent : machine_handle;
trusted event MasterSecretEvent: StringType;
event GenerateOTPCodeEvent : StringType;
event OTPCodeEvent : StringType;
trusted event MapEvent: map[int, int];
event AuthenticateRequest : (StringType, StringType);
event AuthSuccess;
event AuthFailure;
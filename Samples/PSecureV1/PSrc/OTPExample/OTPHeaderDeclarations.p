//OTP Events
event BankPublicIDEvent : machine_handle;
event PublicIDEvent : machine_handle;
event UNTRUSTEDReceiveRegistrationCredentials : (machine_handle, StringType);
event GenerateOTPCodeEvent : StringType;
event OTPCodeEvent : StringType;
event AuthenticateRequest : (usernamePW : StringType, OTPCode : StringType);
event AuthSuccess;
event AuthFailure;

trusted event MasterSecretEvent: secure_StringType;
trusted event MapEvent: map[secure_int, secure_int];
trusted event TRUSTEDProvisionClientSSM : secure_machine_handle;

//OTP Functions
fun PrintString(inputString : StringType);
fun PrintRawStringType(inputString : StringType);
fun PrintRawSecureStringType(inputString : secure_StringType);
fun PrintKey(input : machine_handle);
fun GenerateRandomMasterSecret() : secure_StringType;
fun GetUserInput() : StringType;
fun Concat(input1:StringType, input2:StringType) : StringType;
fun Hash(input1:StringType, input2:StringType) : StringType;

fun MeasureTime();
fun EXIT();
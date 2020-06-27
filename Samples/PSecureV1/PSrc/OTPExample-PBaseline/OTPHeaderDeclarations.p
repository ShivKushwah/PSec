//OTP Events
event BankPublicIDEvent : machine_handle;
event PublicIDEvent : machine_handle;
event UNTRUSTEDReceiveRegistrationCredentials : (machine_handle, StringType, StringType);
event GenerateOTPCodeEvent : StringType;
event OTPCodeEvent : StringType;
event UNTRUSTEDAuthenticateRequest : (Username : StringType, Password : StringType, OTPCode : StringType);
event AuthSuccess;
event AuthFailure;

event MasterSecretEvent: StringType;
event MapEvent: map[int, int];
event TRUSTEDProvisionClientSSM : machine_handle;

//OTP Functions
fun PrintString(inputString : StringType);
fun PrintRawStringType(inputString : StringType);
fun PrintRawSecureStringType(inputString : StringType);
fun PrintKey(input : machine_handle);
fun GenerateRandomMasterSecret() : StringType;
fun GetUsernameInput() : StringType;
fun GetPasswordInput() : StringType;
fun Concat(input1:StringType, input2:StringType) : StringType;
fun Hash(input1:StringType, input2:StringType) : StringType;

fun MeasureTime();
fun EXIT();
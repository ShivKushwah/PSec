//Email Processing Events
event UNTRUSTEDSecureSpamFilterIDEvent : machine_handle;
event UNTRUSTEDReceiveEmailEnclaveIDEvent : machine_handle;
event UNTRUSTEDEmailEnclaveIDEvent : machine_handle;
event UNTRUSTEDEmailBodyEvent : StringType;
event UNTRUSTEDSpamResultEvent : bool;

trusted event TRUSTEDSecureSpamFilterIDEvent : secure_machine_handle;
trusted event TRUSTEDProvisionEmailUserEnclave : (secure_machine_handle, secure_machine_handle);
trusted event TRUSTEDEmailBodyEvent: (secure_machine_handle, secure_StringType);
trusted event TRUSTEDSpamResultEvent: secure_bool;

//Email Processing Functions
fun PrintString(inputString : StringType);
fun PrintRawStringType(inputString : StringType);
fun PrintRawSecureStringType(inputString : secure_StringType);
fun PrintKey(input : machine_handle);

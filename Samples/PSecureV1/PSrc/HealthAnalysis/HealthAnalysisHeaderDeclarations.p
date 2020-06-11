//Email Processing Events
event UNTRUSTEDSecureHealthAnalyzerIDEvent : machine_handle;
event UNTRUSTEDReceiveUserEnclaveIDEvent : machine_handle;
event UNTRUSTEDUserEnclaveIDEvent : machine_handle;
event UNTRUSTEDHealthInfoEvent : StringType;
event UNTRUSTEDHealthInfoResultEvent : bool;

trusted event TRUSTEDSecureHealthAnalyzerIDEvent : secure_machine_handle;
trusted event TRUSTEDProvisionUserEnclave : (secure_machine_handle, secure_machine_handle);
trusted event TRUSTEDHealthInfoEvent: (secure_machine_handle, secure_StringType);
trusted event TRUSTEDHealthInfoResultEvent: secure_bool;

//Email Processing Functions
fun PrintString(inputString : StringType);
fun PrintRawStringType(inputString : StringType);
fun PrintRawSecureStringType(inputString : secure_StringType);
fun PrintKey(input : machine_handle);

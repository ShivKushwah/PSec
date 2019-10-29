#include "enclave.h"

PRT_PROCESS *process;

extern char secure_message[SIZE_OF_MESSAGE]; 
unordered_map<int, identityKeyPair> PMachineIDToIdentityDictionary;
unordered_map<string, int> PublicIdentityKeyToPMachineIDDictionary;
unordered_map<int, string> PMachineIDtoCapabilityKeyDictionary;

map<PMachineChildPair, string> PMachineToChildCapabilityKey;

int ID_GENERATOR_SEED = 1;

void ErrorHandler(PRT_STATUS status, PRT_MACHINEINST *ptr)
{
    if (status == PRT_STATUS_ASSERT)
    {
        ocall_print("exiting with PRT_STATUS_ASSERT (assertion failure)\n");
        // exit(1);
    }
    else if (status == PRT_STATUS_EVENT_OVERFLOW)
    {
        ocall_print("exiting with PRT_STATUS_EVENT_OVERFLOW\n");
        // exit(1);
    }
    else if (status == PRT_STATUS_EVENT_UNHANDLED)
    {
        ocall_print("exiting with PRT_STATUS_EVENT_UNHANDLED\n");
        // exit(1);
    }
    else if (status == PRT_STATUS_QUEUE_OVERFLOW)
    {
        ocall_print("exiting with PRT_STATUS_QUEUE_OVERFLOW \n");
        // exit(1);
    }
    else if (status == PRT_STATUS_ILLEGAL_SEND)
    {
        ocall_print("exiting with PRT_STATUS_ILLEGAL_SEND \n");
        // exit(1);
    }
    else
    {
        ocall_print("unexpected PRT_STATUS in ErrorHandler: \n");
        // exit(2);
    }


}

static PRT_BOOLEAN cooperative = PRT_FALSE;
static int threads = 1;

// todo: make tester useful for performance testing also, not finished yet...
static PRT_BOOLEAN perf = PRT_FALSE;
static long steps = 0;
static long startTime = 0;
static long perfEndTime = 0;
static const char* parg = NULL;
static const char* workspaceConfig;

void Log(PRT_STEP step, PRT_MACHINESTATE* senderState, PRT_MACHINEINST *receiver, PRT_VALUE* event, PRT_VALUE* payload)
{ 
    PrtPrintStep(step, senderState, receiver, event, payload);
}

static void PrintUsage(void)
{
    ocall_print("Usage: Tester [options]\n");
    ocall_print("This program tests the compiled state machine in program.c and program.h\n");
    ocall_print("Options:\n");
	ocall_print("	-w [path]		[path] represents the path to the workspace config file\n");
    ocall_print("   -cooperative     run state machine with the cooperative scheduler\n");
	ocall_print("   -threads [n]     run P using multiple threads\n");
	ocall_print("   -perf [n]        run performance test that outputs #steps every 10 seconds, terminating after n seconds\n");
	ocall_print("   -arg [x]         pass argument 'x' to P main machine\n");
}

static void RunPerfTest()
{

}

void MyAssert(PRT_INT32 condition, PRT_CSTRING message)
{
	if (condition != 0)
	{
		return;
	}
	else if (message == NULL)
	{
		ocall_print("ASSERT");
	}
	else
	{
		ocall_print("ASSERT: ");
        ocall_print(message);
	}
	// exit(1);
}


static void RunToIdle(void* process)
{
    // In the tester we run the state machines until there is no more work to do then we exit
    // instead of blocking indefinitely.  This is then equivalent of the non-cooperative case
    // where we PrtRunStateMachine once (inside PrtMkMachine).  So we do NOT call PrtWaitForWork.
    
    PRT_PROCESS_PRIV* privateProcess = (PRT_PROCESS_PRIV*)process;
	while (privateProcess->terminating == PRT_FALSE)
	{
		PRT_STEP_RESULT result = PrtStepProcess((PRT_PROCESS*)process);
		switch (result) {
		case PRT_STEP_TERMINATING:
			break;
		case PRT_STEP_IDLE:
			PrtWaitForWork((PRT_PROCESS*) process);
			break;
		case PRT_STEP_MORE:
			PrtYieldThread();
			break;
		}
	}
}

extern "C" void P_SecureSendPongEventToPingMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{  
    int ret;
    char* other_machine_name = "PingMachine";
    // Copy the Pong event's ID as the message to be sent
    memcpy(secure_message, itoa(P_EVENT_Pong.value.valueUnion.ev, secure_message, 10), SIZE_OF_MESSAGE);
    ocall_pong_enclave_attestation_in_thread(&ret, other_machine_name, strlen(other_machine_name)+1, 0);
}

int handle_incoming_events_pong_enclave(PRT_UINT32 eventIdentifier) {
    PRT_VALUE* pingEvent = PrtMkEventValue(eventIdentifier);
    PRT_MACHINEID pongId;
    pongId.machineId = 1;

    PRT_MACHINEINST* pongMachine = PrtGetMachine(process, PrtMkMachineValue(pongId));
    PrtSend(NULL, pongMachine, pingEvent, 0);
    return 0;
}

extern int Delta;

int enclave_main(void)
{
    ocall_print("hello, world!\n");
	//PRT_DBG_START_MEM_BALANCED_REGION
	//{
		PRT_GUID processGuid;
		PRT_VALUE *payload;

		processGuid.data1 = 1;
		processGuid.data2 = 0;
		processGuid.data3 = 0;
		processGuid.data4 = 0;
		process = PrtStartProcess(processGuid, &P_GEND_IMPL_DefaultImpl, ErrorHandler, Log);
        ocall_print("after start process!\n");
        if (cooperative)
        {
            PrtSetSchedulingPolicy(process, PRT_SCHEDULINGPOLICY_COOPERATIVE);
        }
		if (parg == NULL)
		{
			payload = PrtMkNullValue();

		}
		else
		{
			int i = atoi(parg);
			payload = PrtMkIntValue(i);
            
		}

		PrtUpdateAssertFn(MyAssert);
        ocall_print("after update assert fn!\n");

        PRT_UINT32 mainMachine2;
		PRT_BOOLEAN foundMachine2 = PrtLookupMachineByName("Pong", &mainMachine2);
        ocall_print_int(mainMachine2);
		PrtAssert(foundMachine2, "No 'Pong' machine found!");
		PRT_MACHINEINST* pongMachine = PrtMkMachine(process, mainMachine2, 1, &payload);


        ocall_print("after mk machine!\n");

        if (cooperative)
        {
            // test some multithreading across state machines.
            /*
            typedef void *(*start_routine) (void *);
            pthread_t tid[threads];
            for (int i = 0; i < threads; i++)
            {
                pthread_create(&tid[i], NULL, (start_routine)RunToIdle, (void*)process);
            }
            for (int i = 0; i < threads; i++)
            {
                pthread_join(tid[i], NULL);
            }
            */
        }
}


extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachineID = context->id->valueUnion.mid->machineId;
    char* newMachineID = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    //TODO extract the newMachineType from the argument
    char* createMachineRequest = "Create:SecureChild";
    int ret_value;
    ocall_network_request(&ret_value, createMachineRequest, newMachineID, SIZE_OF_IDENTITY_STRING);
    ocall_print("New Machine ID is: ");
    ocall_print(newMachineID);

    //Now, need to retrieve capabilityKey for this machineID and store (thisMachineID, newMachineID) -> capabilityKey
    char* getChildMachineIDRequest = "GetKey:PongPublic:SecureChildPublic1";
    char* capabilityKey = retrieveCapabilityKey();//(char*) malloc(SIZE_OF_CAPABILITYKEY); 
    //ocall_network_request(&ret_value, getChildMachineIDRequest, capabilityKey, SIZE_OF_CAPABILITYKEY);
    ocall_print("Pong Machine has received capability key for secure child: ");
    ocall_print(capabilityKey);

    PMachineToChildCapabilityKey[make_tuple(currentMachineID, string(newMachineID))] = string(capabilityKey);

    //Return the newMachineID and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, newMachineID);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}

char* retrieveCapabilityKey() {
    int ret;
    char* other_machine_name = "KPS"; //TODO change this to KPS, bc this is actually assuming PingAttestion.c is KPS
    //TODO change the last int (1 or 0) to denote KPS createCpabilityKey or getCapabilityKey etc
    ocall_pong_enclave_attestation_in_thread(&ret, (char*)other_machine_name, strlen(other_machine_name)+1, 2);
    char* capabilityKey = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKey, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKey;
}

int createMachineAPI(char* machineType, char* untrustedHostID, char* parentTrustedMachineID, char* returnNewMachineID, uint32_t ID_SIZE) {
    string secureChildPublicID;
    string secureChildPrivateID;
    generateIdentity(secureChildPublicID, secureChildPrivateID);
    int PMachineID = createMachine(machineType, untrustedHostID, parentTrustedMachineID);
    PMachineIDToIdentityDictionary[PMachineID] = make_tuple(secureChildPublicID, secureChildPrivateID);
    PublicIdentityKeyToPMachineIDDictionary[secureChildPublicID] = PMachineID;

    //Contacting KPS for capability key
    string capabilityKeyReceived = receiveCapabilityKey();
    ocall_print("Capability Key is: ");
    ocall_print(capabilityKeyReceived.c_str());
    PMachineIDtoCapabilityKeyDictionary[PMachineID] = capabilityKeyReceived;
    memcpy(returnNewMachineID, secureChildPublicID.c_str(), secureChildPublicID.length() + 1);
}

char* receiveCapabilityKey() {
    int ret;
    char* other_machine_name = "KPS"; //TODO change this to KPS, bc this is actually assuming PingAttestion.c is KPS
    //TODO change the last int (1 or 0) to denote KPS createCpabilityKey or getCapabilityKey etc
    ocall_pong_enclave_attestation_in_thread(&ret, (char*)other_machine_name, strlen(other_machine_name)+1, 1);
    char* capabilityKey = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKey, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKey;
}

//publicID and privateID must be allocated by the caller
void generateIdentity(string& publicID, string& privateID) {
    //TODO Make this generate a random pk sk pair
    publicID = "SecureChildPublic" + to_string(ID_GENERATOR_SEED);
    privateID = "SecureChildPrivate" + to_string(ID_GENERATOR_SEED);
    ID_GENERATOR_SEED += 1;
} 

int createMachine(char* machineType, char* untrustedHostID, char* parentTrustedMachineID) {
    PRT_VALUE *payload = PrtMkNullValue();
    PRT_UINT32 mainMachine2;
	PRT_BOOLEAN foundMachine2 = PrtLookupMachineByName(machineType, &mainMachine2);
    ocall_print_int(mainMachine2);
	PrtAssert(foundMachine2, "No machine found!");
	PRT_MACHINEINST* pongMachine = PrtMkMachine(process, mainMachine2, 1, &payload);
    return mainMachine2;
}


//String Class

extern "C" void P_FREE_StringType_IMPL(PRT_UINT64 frgnVal)
{
	PrtFree((PRT_STRING)frgnVal);
}

extern "C" PRT_BOOLEAN P_ISEQUAL_StringType_IMPL(PRT_UINT64 frgnVal1, PRT_UINT64 frgnVal2)
{
	return strcmp((PRT_STRING)frgnVal1, (PRT_STRING)frgnVal2) == 0 ? PRT_TRUE : PRT_FALSE;
}

extern "C" PRT_STRING P_TOSTRING_StringType_IMPL(PRT_UINT64 frgnVal)
{
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, "String : %lld", frgnVal);
	return str;
}

extern "C" PRT_UINT32 P_GETHASHCODE_StringType_IMPL(PRT_UINT64 frgnVal)
{
	return (PRT_UINT32)frgnVal;
}

extern "C" PRT_UINT64 P_MKDEF_StringType_IMPL(void)
{
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, "xyx$12");
	return (PRT_UINT64)str;
}

extern "C" PRT_UINT64 P_CLONE_StringType_IMPL(PRT_UINT64 frgnVal)
{
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, (PRT_STRING)frgnVal);
	return (PRT_UINT64)str;
}

extern "C" void P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_UINT64 val = (*P_VAR_payload)->valueUnion.frgn->value;
    ocall_print("String P value is:");
    ocall_print((char*) val);
    
}




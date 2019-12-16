#include "enclave.h"

PRT_PROCESS *process =  NULL;
extern PRT_PROGRAMDECL* program;

extern char secure_message[SIZE_OF_MESSAGE]; 
unordered_map<int, identityKeyPair> MachinePIDToIdentityDictionary;
unordered_map<string, int> PublicIdentityKeyToMachinePIDDictionary;
unordered_map<int, string> MachinePIDtoCapabilityKeyDictionary;

map<PMachineChildPair, string> PMachineToChildCapabilityKey;
map<PublicMachineChildPair, string> PublicIdentityKeyToChildSessionKey;

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

char* generateCStringFromFormat(char* format_string, char* strings_to_print[], int num_strings) {
        //NOTE make changes in app.cpp as well

    if (num_strings > 5) {
        ocall_print("Too many strings passed to generateCStringFromFormat!");
        return "ERROR!";
    }
    // ocall_print("KIRAT");
    char* returnString = (char*) malloc(100);


    // for (int i = num_strings; i < 5; i++) {
    //     strings_to_print[i] = "hello";
    // }

    char* str1 = strings_to_print[0];
    char* str2 = strings_to_print[1];
    char* str3 = strings_to_print[2];
    char* str4 = strings_to_print[3];
    char* str5 = strings_to_print[4];

    snprintf(returnString, 100, format_string, str1, str2, str3, str4, str5);
    //ocall_print("Return string is");
    //ocall_print(returnString);
    return returnString;

}

int handle_incoming_event(PRT_UINT32 eventIdentifier, PRT_MACHINEID receivingMachinePID, int numArgs, char* payload) {
    PRT_VALUE* event = PrtMkEventValue(eventIdentifier);
    PRT_MACHINEINST* machine = PrtGetMachine(process, PrtMkMachineValue(receivingMachinePID));
    if (numArgs == 0) {
        PrtSend(NULL, machine, event, 0);
    } else {
        PRT_VALUE** prtPayload =  deserializeStringToPrtValue(numArgs, payload, PRT_VALUE_KIND_INT);
        PrtSend(NULL, machine, event, numArgs, prtPayload);
    }
    return 0;
}

extern int Delta;

extern "C" PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
    //USMs can only make untrusted requests to create machines
    ocall_print("UGHH");
    return P_CreateMachineSecureChild_IMPL(context, argRefs);
}

extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    char* requestedNewMachineTypeToCreate = (char*) argRefs[0];
    char* currentMachineIDPublicKey;
    currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str()); 

    if (!machineTypeIsSecure(requestedNewMachineTypeToCreate)) {
        //TODO Add case here if we are creating untrusted machine (Do we need this because inside the enclave we dont
        //have untrusted machines)

    }

    int numArgs = atoi((char*) argRefs[1]);

    PRT_VALUE* payloadPrtValue;
    char* payloadString;  
    int payloadType;

    if (numArgs == 1) {
        payloadPrtValue = *(argRefs[2]);
        payloadType = payloadPrtValue->discriminator;
        payloadString = serializePrtValueToString(payloadPrtValue);
    }

    char* newMachinePublicIDKey = (char*) malloc(SIZE_OF_IDENTITY_STRING + 1);
    int requestSize = 5 + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_NEWMACHINETYPE + 1 + 10 + 1 + SIZE_OF_MAX_MESSAGE + 1 + SIZE_OF_MAX_EVENT_PAYLOAD + 1;
    char* createMachineRequest = (char*) malloc(requestSize);//(char*)("Create:" + string(currentMachineIDPublicKey) + ":" + string(requestedNewMachineTypeToCreate)).c_str();
    if (numArgs == 0) {
        snprintf(createMachineRequest, requestSize, "Create:%s:%s:0", currentMachineIDPublicKey, requestedNewMachineTypeToCreate);
    } else {
        snprintf(createMachineRequest, requestSize, "Create:%s:%s:%d:%d:%s", currentMachineIDPublicKey, requestedNewMachineTypeToCreate, numArgs, payloadType, payloadString);

    }
    
    char* machineNameWrapper[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine is sending out the following network request:", machineNameWrapper, 1)); //TODO use this method for all future ocall_prints
    ocall_print(createMachineRequest);
    int ret_value;
    ocall_network_request(&ret_value, createMachineRequest, newMachinePublicIDKey, SIZE_OF_IDENTITY_STRING + 1);
    
    char* machineNameWrapper2[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine has created a new machine with Identity Public Key as:", machineNameWrapper2, 1)); //TODO use this method for all future ocall_prints
    ocall_print(newMachinePublicIDKey);

    //Now, need to retrieve capabilityKey for this newMachinePublicIDKey and store (thisMachineID, newMachinePublicIDKey) -> capabilityKey
    string request = "GetKey:" + string(currentMachineIDPublicKey) + ":" + string(newMachinePublicIDKey);//TODO unhardcode current Machine name
    //TODO replace above line with snprintf as did with createMachineRequest, and do this everywhere in code
    char* getChildMachineIDRequest = (char*) request.c_str(); 
    char* capabilityKey = retrieveCapabilityKeyForChildFromKPS(currentMachineIDPublicKey, newMachinePublicIDKey);//(char*) malloc(SIZE_OF_CAPABILITYKEY); 
    //ocall_network_request(&ret_value, getChildMachineIDRequest, capabilityKey, SIZE_OF_CAPABILITYKEY);
    
    char* machineNameWrapper3[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine has received capability key for secure child:", machineNameWrapper3, 1)); //TODO use this method for all future ocall_prints
    ocall_print(capabilityKey);

    PMachineToChildCapabilityKey[make_tuple(currentMachinePID, string(newMachinePublicIDKey))] = string(capabilityKey);

    //Return the newMachinePublicIDKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, newMachinePublicIDKey);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}

extern "C" PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;

    ocall_print("Entered Secure Send");

    char* currentMachineIDPublicKey;
    currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str()); 

    PRT_VALUE** P_ToMachine_Payload = argRefs[0];
    PRT_UINT64 sendingToMachinePublicIDPValue = (*P_ToMachine_Payload)->valueUnion.frgn->value;
    char* sendingToMachinePublicID = (char*) sendingToMachinePublicIDPValue;
    if (PMachineToChildCapabilityKey.count(make_tuple(currentMachinePID, string(sendingToMachinePublicID))) == 0) {
        ocall_print("ERROR: No Capability Key found!");
    }
    string capabilityKey = PMachineToChildCapabilityKey[make_tuple(currentMachinePID, string(sendingToMachinePublicID))];
    ocall_print((char*)capabilityKey.c_str());

    //Check if we don't have a pre-existing session key with the other machine, if so 
    //we need to intialize communications and establish a session key
    if (PublicIdentityKeyToChildSessionKey.count(make_tuple(string(currentMachineIDPublicKey), string(sendingToMachinePublicID))) == 0) {
        int requestSize = 8 + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_IDENTITY_STRING + 1;
        char* initComRequest = (char*) malloc(requestSize);
        snprintf(initComRequest, requestSize, "InitComm:%s:%s", currentMachineIDPublicKey, sendingToMachinePublicID);
        
        char* machineNameWrapper[] = {currentMachineIDPublicKey};
        ocall_print(generateCStringFromFormat("%s machine is sending out following network request:", machineNameWrapper, 1));
        ocall_print(initComRequest);
        char* newSessionKey = (char*) malloc(SIZE_OF_SESSION_KEY);
        int ret_value;
        ocall_network_request(&ret_value, initComRequest, newSessionKey, SIZE_OF_SESSION_KEY);
        char* machineNameWrapper2[] = {currentMachineIDPublicKey};
        ocall_print(generateCStringFromFormat("%s machine has received new session key:", machineNameWrapper2, 1));       
        ocall_print(newSessionKey);
        PublicIdentityKeyToChildSessionKey[make_tuple(string(currentMachineIDPublicKey), string(sendingToMachinePublicID))] = string(newSessionKey);
    }


    string sessionKey = PublicIdentityKeyToChildSessionKey[make_tuple(string(currentMachineIDPublicKey), string(sendingToMachinePublicID))];
    //TODO use sessionKey to encrypt message
    PRT_VALUE** P_Event_Payload = argRefs[1];
    char* event = (char*) malloc(SIZE_OF_MAX_EVENT_NAME);
    itoa((*P_Event_Payload)->valueUnion.ev , event, SIZE_OF_MAX_EVENT_NAME);

    const int size_of_max_num_args = 10; //TODO if modififying this, modify it in app.cpp

    PRT_VALUE** P_NumEventArgs_Payload = argRefs[2];
    int numArgs = (*P_NumEventArgs_Payload)->valueUnion.nt;
    char* numArgsPayload = (char*) malloc(size_of_max_num_args);
    itoa(numArgs, numArgsPayload, SIZE_OF_MAX_EVENT_PAYLOAD);

    char* eventMessagePayload = (char*) malloc(SIZE_OF_MAX_EVENT_PAYLOAD);

    for (int i = 0; i < numArgs; i++) {
        PRT_VALUE** P_EventMessage_Payload = argRefs[i + 3];
        char* payload = serializePrtValueToString(*P_EventMessage_Payload);
        //TODO we need to encode the type of each payload element. Like the following "PRT_KIND_VALUE_INT:72:PRT_KIND_BOOL:true" etc
        if (i == 0) {
            char* parameters[] = {payload};
            eventMessagePayload = generateCStringFromFormat("%s", parameters, 1);
        } else {
            char* parameters[] = {eventMessagePayload, payload};
            eventMessagePayload = generateCStringFromFormat("%s:%s", parameters, 2);
        }
    }

    int requestSize = 4 + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_MAX_MESSAGE + 1 + size_of_max_num_args + 1 + SIZE_OF_MAX_EVENT_PAYLOAD + 1;
    char* secureSendRequest = (char*) malloc(requestSize);
    snprintf(secureSendRequest, requestSize, "Send:%s:%s:%s:%s:%s", currentMachineIDPublicKey, sendingToMachinePublicID, event, numArgsPayload, eventMessagePayload);
    char* machineNameWrapper[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine is sending out following network request:", machineNameWrapper, 1));      
    ocall_print(secureSendRequest);
    char* empty;
    int ret_value;
    ocall_network_request(&ret_value, secureSendRequest, empty, 0);

    char* machineNameWrapper2[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine has succesfully sent message", machineNameWrapper2, 1));
}

char* serializePrtValueToString(PRT_VALUE* value) {
    //TODO code the rest of the types
    //TODO if modifying this, also modify in app.cpp
    if (value->discriminator == PRT_VALUE_KIND_INT) {
        char* integer = (char*) malloc(10);
        itoa(value->valueUnion.nt, integer, 10);
        return integer;
    } else if (value->discriminator == PRT_VALUE_KIND_FOREIGN) {
        if (value->valueUnion.frgn->typeTag == 0) { //if StringType
            return (char*) value->valueUnion.frgn->value;
        } else {
            return "UNSUPPORTED_TYPE";
        }
    } else {
        return "UNSUPPORTED_TYPE";
    }

}

PRT_VALUE** deserializeStringToPrtValue(int numArgs, char* str, int payloadType) {
        //TODO if there are changes in here make changes in enclave.cpp

    //TODO code the rest of the types (only int is coded for now)
    PRT_VALUE** values = (PRT_VALUE**) PrtCalloc(numArgs, sizeof(PRT_VALUE*));
    for (int i = 0; i < numArgs; i++) {
        char* split = strtok(str, ":");
        values[i] = (PRT_VALUE*)PrtMalloc(sizeof(PRT_VALUE));
        values[i]->discriminator = (PRT_VALUE_KIND) payloadType;
        if (payloadType == PRT_VALUE_KIND_INT) {
            values[i]->valueUnion.nt = atoi(split);
        } else if (payloadType == PRT_VALUE_KIND_FOREIGN) {
            values[i]->valueUnion.frgn = (PRT_FOREIGNVALUE*) PrtMalloc(sizeof(PRT_FOREIGNVALUE));
            values[i]->valueUnion.frgn->typeTag = 0; //TODO hardcoded for StringType
            PRT_STRING prtStr = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	        sprintf_s(prtStr, 100, str);
            values[i]->valueUnion.frgn->value = (PRT_UINT64) prtStr; //TODO do we need to memcpy?
        }
    }
    return values;
}

char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey) {
    int ret;
    char* other_machine_name = "KPS";
    int requestSize = SIZE_OF_IDENTITY_STRING + SIZE_OF_IDENTITY_STRING;
    char* requestString = (char*) malloc(requestSize);
    snprintf(requestString, requestSize, "%s:%s", currentMachinePublicIDKey, childPublicIDKey);    
    ocall_pong_enclave_attestation_in_thread(&ret, (char*)other_machine_name, strlen(other_machine_name)+1, RETRIEVE_CAPABLITY_KEY_CONSTANT, requestString);
    char* capabilityKey = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKey, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKey;
}

int machineTypeIsSecure(char* machineType) {
    PRT_UINT32 interfaceName;  
	PrtLookupMachineByName(machineType, &interfaceName);
    PRT_UINT32 instanceOf = program->interfaceDefMap[interfaceName];
    PRT_MACHINEDECL* curMachineDecl = program->machines[instanceOf];
    return curMachineDecl->isSecure;
}

                                        
void UntrustedCreateMachineAPI(char* machineTypeToCreate, int lengthString, char* returnNewMachinePublicID, int numArgs, int payloadType, char* payloadString, int ID_SIZE, int PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {

    if (process == NULL) {

         ocall_print("hello, world!\n");
	//PRT_DBG_START_MEM_BALANCED_REGION
	//{
		PRT_GUID processGuid;

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

    PRT_VALUE *payload;
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


    string secureChildPublicIDKey;
    string secureChildPrivateIDKey;
    generateIdentity(secureChildPublicIDKey, secureChildPrivateIDKey);
    char* publicIdKeyCopy = (char*) malloc(secureChildPublicIDKey.length() + 1);
    strncpy(publicIdKeyCopy, (char*)secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length() + 1);
    ocall_add_identity_to_eid_dictionary((char*)publicIdKeyCopy, enclaveEid);
    int newMachinePID = getNextPID(); 
    //Store new machine information in enclave's dictionaries
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(secureChildPublicIDKey, secureChildPrivateIDKey);
    PublicIdentityKeyToMachinePIDDictionary[secureChildPublicIDKey] = newMachinePID;

    char* secureChildPublicIDKeyCopy = (char*) malloc(secureChildPublicIDKey.size() + 1);
    memcpy(secureChildPublicIDKeyCopy, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.size() + 1);
    registerMachineWithNetwork(secureChildPublicIDKeyCopy);

    //NOTE No one has the capability key for this SSM

    //"Return" the publicIDKey of the new machine
    memcpy(returnNewMachinePublicID, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length() + 1);
    createMachine(machineTypeToCreate, "", 0, PRT_VALUE_KIND_INT, "");


    // PRT_UINT32 mainMachine2;
	// PRT_BOOLEAN foundMachine2 = PrtLookupMachineByName(machineTypeToCreate, &mainMachine2);
    // ocall_print_int(mainMachine2);
	// PrtAssert(foundMachine2, "No machine found of that type in this enclave!");
	// PrtMkMachine(process, mainMachine2, 1, &payload);
    // ocall_print("after mk machine!\n");
}

void eprint(char* printStr) {
    ocall_print(printStr);
}


int createMachineAPI(char* machineType, char* parentTrustedMachinePublicIDKey, char* returnNewMachinePublicIDKey, int numArgs, int payloadType, char* payload, uint32_t ID_SIZE, uint32_t PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    if (process == NULL) {

         ocall_print("hello, world!\n");
	//PRT_DBG_START_MEM_BALANCED_REGION
	//{
		PRT_GUID processGuid;

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

    PRT_VALUE *payloadPrt;
    if (parg == NULL)
    {
        payloadPrt = PrtMkNullValue();

    }
    else
    {
        int i = atoi(parg);
        payloadPrt = PrtMkIntValue(i);
        
    }
    
    //TODO Do we need to verify signature of parentTrustedMachinePublicIDKey?
    string secureChildPublicIDKey;
    string secureChildPrivateIDKey;
    generateIdentity(secureChildPublicIDKey, secureChildPrivateIDKey);
    char* publicIdKeyCopy = (char*) malloc(secureChildPublicIDKey.length() + 1);
    strncpy(publicIdKeyCopy, (char*)secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length() + 1);
    ocall_add_identity_to_eid_dictionary((char*)publicIdKeyCopy, enclaveEid);
    int newMachinePID = getNextPID(); 
    //Store new machine information in enclave's dictionaries
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(secureChildPublicIDKey, secureChildPrivateIDKey);
    PublicIdentityKeyToMachinePIDDictionary[secureChildPublicIDKey] = newMachinePID;

    //Contacting KPS for capability key
    string capabilityKeyReceived = receiveNewCapabilityKeyFromKPS(parentTrustedMachinePublicIDKey ,(char*)secureChildPublicIDKey.c_str());
    ocall_print("Enclave received new capability Key from KPS: ");
    ocall_print(capabilityKeyReceived.c_str());
    MachinePIDtoCapabilityKeyDictionary[newMachinePID] = capabilityKeyReceived;

    char* secureChildPublicIDKeyCopy = (char*) malloc(secureChildPublicIDKey.size() + 1);
    memcpy(secureChildPublicIDKeyCopy, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.size() + 1);
    registerMachineWithNetwork(secureChildPublicIDKeyCopy);

    //"Return" the publicIDKey of the new machine
    memcpy(returnNewMachinePublicIDKey, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length() + 1);
    createMachine(machineType, parentTrustedMachinePublicIDKey, numArgs, payloadType, payload);
}

char* receiveNewCapabilityKeyFromKPS(char* parentTrustedMachineID, char* newMachinePublicIDKey) {
    int ret;
    char* other_machine_name = "KPS";
    int requestSize = SIZE_OF_IDENTITY_STRING + SIZE_OF_IDENTITY_STRING;
    char* requestString = (char*) malloc(requestSize);
    snprintf(requestString, requestSize, "%s:%s", newMachinePublicIDKey, parentTrustedMachineID);
    ocall_pong_enclave_attestation_in_thread(&ret, (char*)other_machine_name, strlen(other_machine_name)+1, CREATE_CAPABILITY_KEY_CONSTANT, requestString);
    char* capabilityKey = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKey, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKey;
}

char* registerMachineWithNetwork(char* newMachineID) {

    int ret_value;
    char* num = (char*) malloc(10);
    itoa(ENCLAVE_NUMBER, num, 10);
    char* machineKeyWrapper[] = {newMachineID, num};
    
    char* networkResult = (char*) malloc(100);
    ocall_network_request(&ret_value, generateCStringFromFormat("RegisterMachine:%s:%s", machineKeyWrapper, 2), networkResult, 100);

}

//publicID and privateID must be allocated by the caller
void generateIdentity(string& publicID, string& privateID) {
    //TODO Make this generate a random pk sk pair

    uint32_t val; 
    sgx_read_rand((unsigned char *) &val, 4);
    publicID = "Enclave2Publi" + to_string(val % 100);
    privateID = "Enclave2Privat" + to_string(val % 100);
} 

int getNextPID() {
    return ((PRT_PROCESS_PRIV*)process)->numMachines + 1;
}

int createMachine(char* machineType, char* parentTrustedMachineID, int numArgs, int payloadType, char* payload) {
    PRT_VALUE* prtPayload;
    if (numArgs > 0) {
        ocall_print("Serialized the following payload");
        ocall_print(payload);
        prtPayload = *(deserializeStringToPrtValue(numArgs, payload, payloadType));
    } else {
        prtPayload = PrtMkNullValue();
    }
    PRT_UINT32 newMachinePID;
	PRT_BOOLEAN foundMachine = PrtLookupMachineByName(machineType, &newMachinePID);
    ocall_print_int(newMachinePID);
	PrtAssert(foundMachine, "No machine found!");
	PRT_MACHINEINST* pongMachine = PrtMkMachine(process, newMachinePID, 1, &prtPayload);
    return pongMachine->id->valueUnion.mid->machineId;
}



int initializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* returnSessionKey, uint32_t ID_SIZE, uint32_t SESSION_KEY_SIZE) {
    ocall_print("Initialize Communication API Called!");
    //TODO need to verify signature over requestingMachineIDKey
    if (PublicIdentityKeyToChildSessionKey.count(make_tuple(string(receivingMachineIDKey), string(requestingMachineIDKey))) == 0) {
        //TODO this logic needs to be diffie hellman authenticated encryption
        string newSessionKey;
        generateSessionKey(newSessionKey);
        PublicIdentityKeyToChildSessionKey[make_tuple(receivingMachineIDKey, requestingMachineIDKey)] = newSessionKey;
        memcpy(returnSessionKey, (char*)newSessionKey.c_str(), SIZE_OF_SESSION_KEY);
        ocall_print("Returning correct session key!");
        return 0;
    } else {
        char* errorMsg = "Already created!";
        memcpy(returnSessionKey, errorMsg, strlen(errorMsg) + 1); 
        ocall_print("ERROR:Session has already been initalized in the past!");
        return 1;
    }
    
}

void generateSessionKey(string& newSessionKey) {
    //TODO Make this generate a random key
    uint32_t val; 
    sgx_read_rand((unsigned char *) &val, 4);
    newSessionKey = "GenSessionKe" + to_string(val % 100);
} 

int sendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* eventNum, char* numArgs, char* payload, uint32_t ID_SIZE, uint32_t MAX_EVENT_SIZE, uint32_t MAX_PAYLOAD_SIZE) {
    //TODO eventNum should be encrypted and requestingMachineIDKey should be verified with signature
    PRT_MACHINEID receivingMachinePID;
    ocall_print("SecureChildMachine has a PID of:");
    char* temp = (char*) malloc(10);
    snprintf(temp, 5, "%d", PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)]);
    ocall_print(temp);
    receivingMachinePID.machineId = PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)];
    handle_incoming_event(atoi(eventNum), receivingMachinePID, atoi(numArgs), payload);

}

int sendUntrustedMessageAPI(char* receivingMachineIDKey, char* eventNum, char* payload, uint32_t ID_SIZE, uint32_t MAX_EVENT_SIZE, uint32_t MAX_PAYLOAD_SIZE) {
    //TODO if modifying this, modify USMsendMessageAPI in app.cpp
    PRT_MACHINEID receivingMachinePID;
    ocall_print("SecureChildMachine has a PID of:");
    char* temp = (char*) malloc(10);
    snprintf(temp, 5, "%d", PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)]);
    ocall_print(temp);
    receivingMachinePID.machineId = PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)];
    handle_incoming_event(atoi(eventNum), receivingMachinePID, 1, payload);

}

extern "C" PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    char* currentMachineIDPublicKey;
 
    currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str()); 
    //Return the currentMachineIDPublicKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, currentMachineIDPublicKey);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}

extern "C" void P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   
}

extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   
}

extern "C" void P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   
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




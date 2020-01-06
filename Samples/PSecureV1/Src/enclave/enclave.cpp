#include "enclave.h"

PRT_PROCESS *process =  NULL;
extern PRT_PROGRAMDECL* program;

sgx_enclave_id_t current_eid;

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

extern int Delta;

extern "C" PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
    return P_CreateMachineSecureChild_IMPL(context, argRefs);
}

extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    return sendCreateMachineNetworkRequest(context, argRefs, "Create:", true);
}

extern "C" PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    return P_UntrustedCreateCoordinator_IMPL(context, argRefs);
}

extern "C" PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    sendSendNetworkRequest(context, argRefs, "Send", true);
}

char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey) {
    int ret;
    char* other_machine_name = "KPS";
    int requestSize = SIZE_OF_IDENTITY_STRING + SIZE_OF_IDENTITY_STRING;
    char* requestString = (char*) malloc(requestSize);
    snprintf(requestString, requestSize, "%s:%s", currentMachinePublicIDKey, childPublicIDKey);    
    ocall_pong_enclave_attestation_in_thread(&ret, current_eid, (char*)other_machine_name, strlen(other_machine_name)+1, RETRIEVE_CAPABLITY_KEY_CONSTANT, requestString);
    char* capabilityKey = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKey, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKey;
}
                                        
void UntrustedCreateMachineAPI(sgx_enclave_id_t currentEid, char* machineTypeToCreate, int lengthString, char* returnNewMachinePublicID, int numArgs, int payloadType, char* payloadString, int ID_SIZE, int PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    current_eid = currentEid;
    char* newMachinePublicIDKey = createMachineHelper(machineTypeToCreate, "", numArgs, payloadType, payloadString, false, enclaveEid);
    //"Return" the publicIDKey of the new machine
    memcpy(returnNewMachinePublicID, newMachinePublicIDKey, strlen(newMachinePublicIDKey) + 1);
}

void eprint(char* printStr) {
    ocall_print(printStr);
}

void startPrtProcessIfNotStarted() {
    if (process == NULL) {
	//PRT_DBG_START_MEM_BALANCED_REGION
	//{
		PRT_GUID processGuid;

		processGuid.data1 = 1;
		processGuid.data2 = 0;
		processGuid.data3 = 0;
		processGuid.data4 = 0;
		process = PrtStartProcess(processGuid, &P_GEND_IMPL_DefaultImpl, ErrorHandler, Log);
        ocall_print("Started Prt Process inside Enclave!\n");
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

        PrtUpdateAssertFn(MyAssert);

    }

}



char* createMachineHelper(char* machineType, char* parentTrustedMachinePublicIDKey, int numArgs, int payloadType, char* payload, bool isSecureCreate, sgx_enclave_id_t enclaveEid) {
    startPrtProcessIfNotStarted();

    if (!machineTypeIsSecure(machineType)) {
        return "Error: Tried to Create USM inside enclave!";
    }
    
    //TODO Do we need to verify signature of parentTrustedMachinePublicIDKey?
    string machineTypeToCreateString = createString(machineType);
    string secureChildPublicIDKey;
    string secureChildPrivateIDKey;
    generateIdentity(secureChildPublicIDKey, secureChildPrivateIDKey, machineTypeToCreateString);
    char* publicIdKeyCopy = (char*) malloc(secureChildPublicIDKey.length() + 1);
    strncpy(publicIdKeyCopy, (char*)secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length() + 1);
    ocall_add_identity_to_eid_dictionary((char*)publicIdKeyCopy, enclaveEid);
    int newMachinePID = getNextPID(); 
    //Store new machine information in enclave's dictionaries
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(secureChildPublicIDKey, secureChildPrivateIDKey);
    PublicIdentityKeyToMachinePIDDictionary[secureChildPublicIDKey] = newMachinePID;

    if (isSecureCreate) {
        //Contacting KPS for capability key
        string capabilityKeyReceived = receiveNewCapabilityKeyFromKPS(parentTrustedMachinePublicIDKey ,(char*)secureChildPublicIDKey.c_str());
        ocall_print("Enclave received new capability Key from KPS: ");
        ocall_print(capabilityKeyReceived.c_str());
        MachinePIDtoCapabilityKeyDictionary[newMachinePID] = capabilityKeyReceived;
    }

    char* secureChildPublicIDKeyCopy = (char*) malloc(secureChildPublicIDKey.size() + 1);
    memcpy(secureChildPublicIDKeyCopy, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.size() + 1);
    registerMachineWithNetwork(secureChildPublicIDKeyCopy);

    if (isSecureCreate) {
        createMachine(machineType, numArgs, payloadType, payload);

    } else {
        createMachine(machineType, 0, PRT_VALUE_KIND_INT, "");
    }

    char* returnNewMachinePublicIDKey = (char*) malloc(secureChildPublicIDKey.length() + 1);
    memcpy(returnNewMachinePublicIDKey, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length() + 1);
    return returnNewMachinePublicIDKey;

}


int createMachineAPI(sgx_enclave_id_t currentEid, char* machineType, char* parentTrustedMachinePublicIDKey, char* returnNewMachinePublicIDKey, int numArgs, int payloadType, char* payload, uint32_t ID_SIZE, uint32_t PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    current_eid = currentEid;
    char* newMachinePublicIDKey = createMachineHelper(machineType, parentTrustedMachinePublicIDKey, numArgs, payloadType, payload, true, enclaveEid);
    //"Return" the publicIDKey of the new machine
    memcpy(returnNewMachinePublicIDKey, newMachinePublicIDKey, strlen(newMachinePublicIDKey) + 1);
}

char* receiveNewCapabilityKeyFromKPS(char* parentTrustedMachineID, char* newMachinePublicIDKey) {
    int ret;
    char* other_machine_name = "KPS";
    int requestSize = SIZE_OF_IDENTITY_STRING + SIZE_OF_IDENTITY_STRING;
    char* requestString = (char*) malloc(requestSize);
    snprintf(requestString, requestSize, "%s:%s", newMachinePublicIDKey, parentTrustedMachineID);
    ocall_pong_enclave_attestation_in_thread(&ret, current_eid, (char*)other_machine_name, strlen(other_machine_name)+1, CREATE_CAPABILITY_KEY_CONSTANT, requestString);
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
void generateIdentity(string& publicID, string& privateID, string prefix) {
    uint32_t val; 
    sgx_read_rand((unsigned char *) &val, 4);
    publicID =  prefix + "SPub" + to_string(val % 100);
    privateID = prefix + "SPriv" + to_string(val % 100);
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

int sendMessageHelper(char* requestingMachineIDKey, char* receivingMachineIDKey, char* event, int numArgs, int payloadType, char* payload) {
    //TODO if modifying this, modify USMsendMessageAPI in app.cpp
    //TODO eventNum should be encrypted and requestingMachineIDKey should be verified with signature
    PRT_MACHINEID receivingMachinePID;
    ocall_print("SecureChildMachine has a PID of:");
    char* temp = (char*) malloc(10);
    snprintf(temp, 5, "%d", PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)]);
    ocall_print(temp);
    receivingMachinePID.machineId = PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)];
    handle_incoming_event(atoi(event), receivingMachinePID, numArgs, payloadType, payload); //TODO update to untrusted send api
}

int decryptAndSendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* encryptedMessage, uint32_t ID_SIZE, uint32_t MAX_ENCRYPTED_MESSAGE) {
    
    char* split = strtok(encryptedMessage, ":");
    char* eventNum = split;
    split = strtok(NULL, ":");
    int numArgs = atoi(split);
    int payloadType = -1;
    char* payload = (char*) malloc(10);
    payload[0] = '\0';
    if (numArgs > 0) {
        split = strtok(NULL, ":");
        payloadType = atoi(split);
        split = strtok(NULL, "\0");
        payload = split;

    }
    sendMessageAPI(requestingMachineIDKey, receivingMachineIDKey, eventNum, numArgs, payloadType, payload, 0, 0, 0);

}

int sendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* event, int numArgs, int payloadType, char* payload, uint32_t ID_SIZE, uint32_t MAX_EVENT_SIZE, uint32_t MAX_PAYLOAD_SIZE) {
    sendMessageHelper(requestingMachineIDKey, receivingMachineIDKey, event, numArgs, payloadType, payload);
}

int sendUntrustedMessageAPI(char* receivingMachineIDKey, char* eventNum, int numArgs, int payloadType, char* payload, uint32_t ID_SIZE, uint32_t MAX_EVENT_SIZE, uint32_t MAX_PAYLOAD_SIZE) {
    sendMessageHelper("", receivingMachineIDKey, eventNum, numArgs, payloadType, payload);
}

extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   return sendCreateMachineNetworkRequest(context, argRefs, "UntrustedCreate", false);
}

void sendSendNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* sendTypeCommand, bool isSecureSend) {
    //TODO if making changes in this protocol, make changes in app.cpp
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;

    ocall_print("Entered Secure Send");

    char* currentMachineIDPublicKey;
    currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str()); 

    PRT_VALUE** P_ToMachine_Payload = argRefs[0];
    PRT_UINT64 sendingToMachinePublicIDPValue = (*P_ToMachine_Payload)->valueUnion.frgn->value;
    char* sendingToMachinePublicID = (char*) sendingToMachinePublicIDPValue;

    if (isSecureSend) {

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
    }
    PRT_VALUE** P_Event_Payload = argRefs[1];
    char* event = (char*) malloc(SIZE_OF_MAX_EVENT_NAME);
    itoa((*P_Event_Payload)->valueUnion.ev , event, 10);

    const int size_of_max_num_args = 10; //TODO if modififying this, modify it in app.cpp

    PRT_VALUE** P_NumEventArgs_Payload = argRefs[2];
    int numArgs = (*P_NumEventArgs_Payload)->valueUnion.nt;
    char* numArgsPayload = (char*) malloc(size_of_max_num_args);
    itoa(numArgs, numArgsPayload, SIZE_OF_MAX_EVENT_PAYLOAD);

    char* eventMessagePayload = (char*) malloc(SIZE_OF_MAX_EVENT_PAYLOAD);

    PRT_VALUE** P_EventMessage_Payload = argRefs[3];
    int eventPayloadType = (*P_EventMessage_Payload)->discriminator;
    char* temp = serializePrtValueToString(*P_EventMessage_Payload);
    memcpy(eventMessagePayload, temp, strlen(temp) + 1);
    free(temp);

    // for (int i = 0; i < numArgs; i++) {
    //     PRT_VALUE** P_EventMessage_Payload = argRefs[i + 3];
    //     char* payload = serializePrtValueToString(*P_EventMessage_Payload);
    //     //TODO we need to encode the type of each payload element. Like the following "PRT_KIND_VALUE_INT:72:PRT_KIND_BOOL:true" etc
    //     if (i == 0) {
    //         char* parameters[] = {payload};
    //         eventMessagePayload = generateCStringFromFormat("%s", parameters, 1);
    //     } else {
    //         char* parameters[] = {eventMessagePayload, payload};
    //         eventMessagePayload = generateCStringFromFormat("%s:%s", parameters, 2);
    //     }
    // }

    int requestSize = 4 + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_MAX_MESSAGE + 1 + size_of_max_num_args + 1 + SIZE_OF_MAX_EVENT_PAYLOAD + 1;
    char* sendRequest = (char*) malloc(requestSize);
    if (isSecureSend) {
        if (numArgs > 0) {
            snprintf(sendRequest, requestSize, "%s:%s:%s:%s:%d:%d:%s", sendTypeCommand, currentMachineIDPublicKey, sendingToMachinePublicID, event, numArgs, eventPayloadType, eventMessagePayload);
        } else  {
            snprintf(sendRequest, requestSize, "%s:%s:%s:%s:0", sendTypeCommand, currentMachineIDPublicKey, sendingToMachinePublicID, event);
        }
    } else {
         if (numArgs > 0) {
            snprintf(sendRequest, requestSize, "%s:%s:%s:%d:%d:%s", sendTypeCommand, sendingToMachinePublicID, event, numArgs, eventPayloadType, eventMessagePayload);
        } else {
            snprintf(sendRequest, requestSize, "%s:%s:%s:0", sendTypeCommand, sendingToMachinePublicID, event);
        }

    }
    
    char* machineNameWrapper[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine is sending out following network request:", machineNameWrapper, 1));      
    ocall_print(sendRequest);
    char* empty;
    int ret_value;
    ocall_network_request(&ret_value, sendRequest, empty, 0);

    char* machineNameWrapper2[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine has succesfully sent message", machineNameWrapper2, 1));

}

extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

    sendSendNetworkRequest(context, argRefs, "UntrustedSend", false);
   
}

extern "C" void P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   
}
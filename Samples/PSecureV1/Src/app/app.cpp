#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include "network_ra.h"
#include "PingPongEnclave.h"
#include <pthread.h> 
#include "enclave_untrusted_host.h"
#include "app.h"
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <map>
#include <tuple>

using namespace std;

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

static PRT_BOOLEAN cooperative = PRT_FALSE;
static int threads = 1;

static PRT_BOOLEAN perf = PRT_FALSE;
static long steps = 0;
static long startTime = 0;
static long perfEndTime = 0;
static const char* parg = NULL;
static const char* workspaceConfig;

unordered_map<int, identityKeyPair> MachinePIDToIdentityDictionary; //USM Dictionary
unordered_map<string, int> USMPublicIdentityKeyToMachinePIDDictionary;
map<PublicMachineChildPair, string> USMPublicIdentityKeyToChildSessionKey;


unordered_set<string> USMAuthorizedTypes; //TODO unhardcode

extern char secure_message[8];

PRT_PROCESS *process;

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


void Log(PRT_STEP step, PRT_MACHINESTATE* senderState, PRT_MACHINEINST *receiver, PRT_VALUE* event, PRT_VALUE* payload)
{ 
    PrtPrintStep(step, senderState, receiver, event, payload);
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
		PRT_STEP_RESULT result = PrtStepProcess((PRT_PROCESS*) process);
		switch (result) {
		case PRT_STEP_TERMINATING:
			break;
		case PRT_STEP_IDLE:
			PrtWaitForWork((PRT_PROCESS*)process);
			break;
		case PRT_STEP_MORE:
			PrtYieldThread();
			break;
		}
	}
}


void generateIdentity(string& publicID, string& privateID, string prefix) {
    uint32_t randNum = rand() % 100;
    randNum = (randNum + 10) % 100;
    if (randNum < 10) {
        randNum = 39;
    }
    // publicID = prefix + "UPub" + to_string(randNum);
    // privateID = prefix + "UPriv" + to_string(randNum);
    publicID = prefix.substr(0, 1) + "UPub" + to_string(randNum) + "ddQMiiDh5wwA4zFBV3VOazgxZ3d3gnD40rQ2g6yrR8MDFdbJUGhm3ozq2hkYZdF0lWOc0EXBlE8bwwlL6VYoQYLAobQMRIqtS5Ytst1zrhq9YiubRypiP6xNS9UcS9dSBryXmdKAAcpke4ri2Ikx4tDUh1TbHr76WCqmOuwXMA9DqphJEdwIPjiOMr3pwYWt12dfVyFEGL5KcVeYajwgCTiQEmbZ7v5eZfZaBf95Ezh2cxPiI4Z1HfjBGmtYuO1aCdV8yKX0bZRNip3Ycmh8LkIhjHTtF3kchbFRVmhz0zdIOHG0HNSuI8x6ga0vSvSReI7hlrEPfrmm6rEVLPQcwtNAgNdMYQtK1qv4igoOErnwFaWMSqKLkkvAF";
    privateID = prefix.substr(0, 1) + "UPri" + to_string(randNum) + "ddQMiiDh5wwA4zFBV3VOazgxZ3d3gnD40rQ2g6yrR8MDFdbJUGhm3ozq2hkYZdF0lWOc0EXBlE8bwwlL6VYoQYLAobQMRIqtS5Ytst1zrhq9YiubRypiP6xNS9UcS9dSBryXmdKAAcpke4ri2Ikx4tDUh1TbHr76WCqmOuwXMA9DqphJEdwIPjiOMr3pwYWt12dfVyFEGL5KcVeYajwgCTiQEmbZ7v5eZfZaBf95Ezh2cxPiI4Z1HfjBGmtYuO1aCdV8yKX0bZRNip3Ycmh8LkIhjHTtF3kchbFRVmhz0zdIOHG0HNSuI8x6ga0vSvSReI7hlrEPfrmm6rEVLPQcwtNAgNdMYQtK1qv4igoOErnwFaWMSqKLkkvAF";
} 

extern "C" PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    return P_UntrustedCreateCoordinator_IMPL(context, argRefs);
}

extern "C" PRT_VALUE* P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    string publicID;
    string privateID;
    generateIdentity(publicID, privateID, string("Initial"));
    //TODO store the privateID
    //TODO register this machine over network

    MachinePIDToIdentityDictionary[currentMachinePID] = make_tuple(publicID, privateID);
    USMPublicIdentityKeyToMachinePIDDictionary[publicID] = currentMachinePID;
}


extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) //TODO modify this to take the type of machine to create as a param
{
    return sendCreateMachineNetworkRequest(context, argRefs, "UntrustedCreate", false);
}

extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) 
{   
    //TODO shivIdentity

    //If we are making changes in here, then make appropiate changes in enclave.cpp
    //TODO we need to attest the other enclave before sending it a message, even if we are sending an untrusted message
    PRT_VALUE** P_ToMachine_Payload = argRefs[0];
    PRT_UINT64 sendingToMachinePublicIDPValue = (*P_ToMachine_Payload)->valueUnion.frgn->value;
    char* sendingToMachinePublicID = (char*) sendingToMachinePublicIDPValue;

    PRT_VALUE** P_Event_Payload = argRefs[1];
    char* event = (char*) malloc(SIZE_OF_MAX_EVENT_NAME);
    itoa((*P_Event_Payload)->valueUnion.ev , event, 10);

    const int size_of_max_num_args = 10; //TODO if modififying this, modify it in enclave.cpp

    // PRT_VALUE** P_NumEventArgs_Payload = argRefs[2];
    // int numArgs = (*P_NumEventArgs_Payload)->valueUnion.nt;
    // char* numArgsPayload = (char*) malloc(size_of_max_num_args);
    // itoa(numArgs, numArgsPayload, SIZE_OF_MAX_EVENT_PAYLOAD);

    PRT_VALUE** P_NumEventArgs_Payload = argRefs[2];
    int numArgs = (*P_NumEventArgs_Payload)->valueUnion.nt;
    char* numArgsPayload = (char*) malloc(size_of_max_num_args);
    itoa(numArgs, numArgsPayload, 10);

    char* eventMessagePayload = (char*) malloc(SIZE_OF_MAX_EVENT_PAYLOAD);

    // for (int i = 0; i < numArgs; i++) {
    PRT_VALUE** P_EventMessage_Payload;
    int eventPayloadType;
    char* eventPayloadTypeString = NULL;
    int eventMessagePayloadSize;
    char* eventMessagePayloadSizeString = NULL;
    if (numArgs > 0) {
        P_EventMessage_Payload = argRefs[3];
        eventPayloadType = (*P_EventMessage_Payload)->discriminator;
        eventPayloadTypeString = (char*) malloc(10);
        itoa(eventPayloadType, eventPayloadTypeString, 10);
        eventMessagePayloadSize = 0;
        char* temp = serializePrtValueToString(*P_EventMessage_Payload, eventMessagePayloadSize);
        memcpy(eventMessagePayload, temp, eventMessagePayloadSize + 1);
        eventMessagePayload[eventMessagePayloadSize] = '\0';
        ocall_print("EVENT MESSAGE PAYLOAD IS");
        ocall_print(eventMessagePayload);
        ocall_print("Length is");
        ocall_print_int(eventMessagePayloadSize);
        safe_free(temp);

        eventMessagePayloadSizeString = (char*) malloc(10);
        itoa(eventMessagePayloadSize, eventMessagePayloadSizeString, 10);

    }
        
    //     //TODO we need to encode the type of each payload element. Like the following "PRT_KIND_VALUE_INT:72:PRT_KIND_BOOL:true" etc
    //     //TODO I assumed only 1 payload for the below
    //     // if (i == 0) {
    //     //     char* parameters[] = {payload};
    //     //     eventMessagePayload = generateCStringFromFormat("%s", parameters, 1);
    //     // } else {
    //     //     char* parameters[] = {eventMessagePayload, payload};
    //     //     eventMessagePayload = generateCStringFromFormat("%s:%s", parameters, 2);
    //     // }
    // }

    // printf("Sending to : %s\n", sendingToMachinePublicID);
    // printf("Sending event : %s\n", event);
    // printf("Sending payload : %s\n", eventMessagePayload);

    

    int requestSize = 130 + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_MAX_MESSAGE + 1 + SIZE_OF_MAX_EVENT_PAYLOAD + 1;
    char* unsecureSendRequest = (char*) malloc(requestSize);
    if (numArgs > 0) {
        char* colon = ":";
        char* concatStrings[] = {"UntrustedSend", colon, sendingToMachinePublicID, colon, event, colon, numArgsPayload, colon, eventPayloadTypeString, colon, eventMessagePayloadSizeString, colon, eventMessagePayload};
        int concatLenghts[] = {strlen("UntrustedSend"), strlen(colon), SGX_RSA3072_KEY_SIZE, strlen(colon), strlen(event), strlen(colon), strlen(numArgsPayload), strlen(colon), strlen(eventPayloadTypeString), strlen(colon), strlen(eventMessagePayloadSizeString), strlen(colon), eventMessagePayloadSize};
        unsecureSendRequest = concatMutipleStringsWithLength(concatStrings, concatLenghts, 13);
        requestSize = returnTotalSizeofLengthArray(concatLenghts, 13) + 1;
        // snprintf(sendRequest, requestSize, "%s:%s:%s:%d:%d:%s", sendTypeCommand, sendingToMachinePublicID, event, numArgs, eventPayloadType, eventMessagePayload);
    } else {
        char* colon = ":";
        char* zero = "0";
        char* concatStrings[] = {"UntrustedSend", colon, sendingToMachinePublicID, colon, event, colon, zero};
        int concatLenghts[] = {strlen("UntrustedSend"), strlen(colon), SGX_RSA3072_KEY_SIZE, strlen(colon), strlen(event), strlen(colon), strlen(zero)};
        unsecureSendRequest = concatMutipleStringsWithLength(concatStrings, concatLenghts, 7);
        requestSize = returnTotalSizeofLengthArray(concatLenghts, 7) + 1;
        // snprintf(sendRequest, requestSize, "%s:%s:%s:0", sendTypeCommand, sendingToMachinePublicID, event);
    }

    // if (numArgs > 0) {
    //     snprintf(unsecureSendRequest, requestSize, "UntrustedSend:%s:%s:%d:%d:%s", sendingToMachinePublicID, event, numArgs, eventPayloadType, eventMessagePayload);
    // } else {
    //     snprintf(unsecureSendRequest, requestSize, "UntrustedSend:%s:%s:0", sendingToMachinePublicID, event);
    // }
    safe_free(event);
    safe_free(eventMessagePayload);
    printf("Untrusted machine is sending out following network request: %s\n", unsecureSendRequest);   
    char* newMachinePublicIDKey = NULL;
    size_t requestSz = requestSize;
    newMachinePublicIDKey = send_network_request_API(unsecureSendRequest, requestSz);
    safe_free(unsecureSendRequest);
    ocall_print("printing pidk");
    ocall_print(newMachinePublicIDKey);
    safe_free(newMachinePublicIDKey);
}


extern "C" PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
    //USMs can only make untrusted requests to create machines
    PRT_VALUE* temp = P_UntrustedCreateCoordinator_IMPL(context, argRefs);
    // printf("VALUE IS : %s", temp->valueUnion.frgn->value);
    // fflush(stdout);
    return temp;// PrtMkIntValue(3);//PrtCloneValue(temp);
}

char* receiveNetworkRequest(char* request, size_t requestSize) {

    return receiveNetworkRequestHelper(request, requestSize, false);

}

//Responsibility of Caller to free return 
char* USMinitializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey) { //TODO shividentity
    printf("USM Initialize Communication API Called!\n");
    //TODO need to verify signature over requestingMachineIDKey
    if (USMPublicIdentityKeyToChildSessionKey.count(make_tuple(string(receivingMachineIDKey), string(requestingMachineIDKey))) == 0) {
        //TODO this logic needs to be diffie hellman authenticated encryption
        string newSessionKey;
        generateSessionKey(newSessionKey);
        USMPublicIdentityKeyToChildSessionKey[make_tuple(receivingMachineIDKey, requestingMachineIDKey)] = newSessionKey;
        printf("Returning correct session key!\n");
        char* returnSessionkey = (char*) malloc(newSessionKey.length() + 1);
        memcpy(returnSessionkey, newSessionKey.c_str(), newSessionKey.length() + 1);
        return returnSessionkey;
    } else {
        char* errorMsg = createStringLiteralMalloced("Already created!");
        printf("ERROR:Session has already been initalized in the past!\n");
        return errorMsg;
    }
    
}

void generateSessionKey(string& newSessionKey) {
    //TODO Make this generate a random key
    int randNum = rand() % 100;
    newSessionKey = "GenSessionKe" + to_string(randNum);
} 

char* USMsendMessageAPI(char* receivingMachineIDKey, char* eventNum, int numArgs, int payloadType, char* payload, int payloadSize) {
    //TODO if modifying this, modify sendUntrustedMessageAPI in enclave.cpp
   PRT_MACHINEID receivingMachinePID;
    printf("Machine receiving message has a PID of:");
    char* temp = (char*) malloc(10);
    // if (NETWORK_DEBUG) {
    //     snprintf(temp, 5, "%d\n", USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)]);
    //     printf(temp);
    //     safe_free(temp);
    //     receivingMachinePID.machineId = USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)];
    // } else {
        snprintf(temp, 5, "%d\n", USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)]);
        printf(temp);
        safe_free(temp);
        receivingMachinePID.machineId = USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)];
    // }
    ocall_print("Inside USMsendMessageAPI");
    // printRSAKey(payload);
    handle_incoming_event(atoi(eventNum), receivingMachinePID, numArgs, payloadType, payload, payloadSize); //TODO shividentity
    return createStringLiteralMalloced("Message successfully sent!/n");
}

// OCall implementations
void ocall_print(const char* str) {
    printf("[o] %s\n", str);
    fflush(stdout);
}

void ocall_print_int(int intPrint) {
    printf("OCALL_PRINT_INT:Value is %d\n", intPrint);
    fflush(stdout);
}


int handle_incoming_events_ping_machine(PRT_UINT32 eventIdentifier) {
    // PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    // PRT_MACHINEID pingId;
    // pingId.machineId = 1;

    // PRT_MACHINEINST* pingMachine = PrtGetMachine(process, PrtMkMachineValue(pingId));
    // PrtSend(NULL, pingMachine, pongEvent, 0);
    // return 0;
}

char* registerMachineWithNetwork(char* newMachineID) {
    //TODO shividentity make compatible
    ocall_print("ChildPublicIDKey size is");
    ocall_print_int(strlen(newMachineID));

    // char* machineKeyWrapper[] = {newMachineID};
    // char* request = generateCStringFromFormat("RegisterMachine:%s:-1", machineKeyWrapper, 1);
    // size_t requestSz = strlen(request) + 1;
    // char* returnValue = send_network_request_API(request, requestSz);
    // safe_free(request);
    // safe_free(returnValue);
    // return returnValue;

    int ret_value;
    char* num = "-1";
    // char* machineKeyWrapper[] = {newMachineID, num};
    
    // char* networkResult = (char*) malloc(100);
    // if (NETWORK_DEBUG) {
    //     char* networkRequest = generateCStringFromFormat("RegisterMachine:%s:%s", machineKeyWrapper, 2);
    //     ocall_network_request(&ret_value, networkRequest, networkResult, strlen(networkRequest) + 1, 100);
    //     safe_free(networkRequest);
    // } else {
        //TODO need to test this request
        char* requestType = "RegisterMachine:";
        char* colon = ":";
        char* concatStrings[] = {requestType, newMachineID, colon, num};
        int concatLenghts[] = {strlen(requestType), SGX_RSA3072_KEY_SIZE, strlen(colon), strlen(num)};
        char* networkRequest = concatMutipleStringsWithLength(concatStrings, concatLenghts, 4);
        int networkRequestSize = returnTotalSizeofLengthArray(concatLenghts, 4) + 1; // +1 for null terminated byte
        char* returnValue = send_network_request_API(networkRequest, networkRequestSize);
                safe_free(networkRequest);

        return returnValue;
        // ocall_network_request(&ret_value, networkRequest, networkResult, networkRequestSize, 100);
    // }
    // safe_free(num);
    // safe_free(networkResult);

}

//Responbility of caller to free return
char* createUSMMachineAPI(char* machineType, int numArgs, int payloadType, char* payload, int payloadSize) {
    //TODO shividentity make compatibile
    startPrtProcessIfNotStarted();
    if (machineTypeIsSecure(machineType)) {
        return "Error: Tried to create SSM inside app!";
    }
    
    //TODO Do we need to verify signature of parentTrustedMachinePublicIDKey?
    int newMachinePID = getNextPID(); 

    string machineTypeString = createString(machineType);
    string usmChildPublicIDKey;
    string usmChildPrivateIDKey;
    generateIdentity(usmChildPublicIDKey, usmChildPrivateIDKey, machineType);
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(usmChildPublicIDKey, usmChildPrivateIDKey);
    USMPublicIdentityKeyToMachinePIDDictionary[usmChildPublicIDKey] = newMachinePID;
    // printf("Added %s to USM dictionary!\n", usmChildPublicIDKey.c_str());

    char* usmChildPublicIDKeyCopy = (char*) malloc(usmChildPublicIDKey.size() + 1);
    memcpy(usmChildPublicIDKeyCopy, usmChildPublicIDKey.c_str(), usmChildPublicIDKey.size() + 1);
    registerMachineWithNetwork(usmChildPublicIDKeyCopy);
    safe_free(usmChildPublicIDKeyCopy);

    char* usmChildPublicIDKeyCopy2 = (char*) malloc(usmChildPublicIDKey.size() + 1);
    memcpy(usmChildPublicIDKeyCopy2, usmChildPublicIDKey.c_str(), usmChildPublicIDKey.size() + 1);

    createMachine(machineType, numArgs, payloadType, payload, payloadSize);

    //Return the publicIDKey of the new machine
    return usmChildPublicIDKeyCopy2;
}

long threadsRunning = 0;
pthread_mutex_t threadsRunning_mutex;

long
get_threadsRunning()
{
    long c;

    pthread_mutex_lock(&threadsRunning_mutex);
        c = threadsRunning;
    pthread_mutex_unlock(&threadsRunning_mutex);
    return (c);
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
        ocall_print("Started Prt Process in App!\n");
        if (cooperative)
        {
            PrtSetSchedulingPolicy(process, PRT_SCHEDULINGPOLICY_COOPERATIVE);
        }
		
        if (cooperative)
        {

            PRT_VALUE *payload = PrtMkNullValue();
            PRT_UINT32 mainMachine = 1; //TODO NOTE: I'm not able to send messages to machines unless they have id of 1. Otherwise I receive 
            // id out of bounds when I call PRT_MACHINEINST* pingMachine = PrtGetMachine(process, PrtMkMachineValue(pingId));
            PRT_BOOLEAN foundMachine = PrtLookupMachineByName("UntrustedInitializer", &mainMachine);
            PrtAssert(foundMachine, "No 'GodUntrusted' machine found!");
            PRT_MACHINEINST* newMachine = PrtMkMachine(process, mainMachine, 1, &payload);  

            // test some multithreading across state machines.
            
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
            
        }

        for (int i = 0; i < program->nMachines; i++) {
            if (!program->machines[i]->isSecure) {
                USMAuthorizedTypes.insert(createString(program->machines[i]->name));
            }  
        }

        PrtUpdateAssertFn(MyAssert);

    }

}

int main(int argc, char const *argv[]) {
    initNetwork();
    initKPS();
    //char* kirat = (char*) malloc(220);
 
    // Place the measurement of the enclave into metadata_info.txt
    system("sgx_sign dump -enclave enclave.signed.so -dumpfile metadata_info.txt");

    char* ret = createUSMMachineAPI("GodUntrusted", 0, 0, "", 0);
    safe_free(ret);

    return 0;
}

extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

}

extern "C" PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

}


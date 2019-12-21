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
    int randNum = rand() % 100;
    publicID = prefix + "UPub" + to_string(randNum);
    privateID = prefix + "UPriv" + to_string(randNum);
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

PRT_VALUE* sendCreateMachineNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* createTypeCommand, bool isSecureCreate) {
    //If making changes here, make relevant changes in enclave.cpp
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    char* requestedNewMachineTypeToCreate = (char*) argRefs[0];

    char* currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str()); 

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
    if (isSecureCreate) {
        if (numArgs == 0) {
            snprintf(createMachineRequest, requestSize, "%s:%s:%s:0", createTypeCommand, currentMachineIDPublicKey, requestedNewMachineTypeToCreate);
        } else {
            snprintf(createMachineRequest, requestSize, "%s:%s:%s:%d:%d:%s", createTypeCommand, currentMachineIDPublicKey, requestedNewMachineTypeToCreate, numArgs, payloadType, payloadString);

        }

    } else {
        if (numArgs == 0) {
            snprintf(createMachineRequest, requestSize, "%s:%s:0", createTypeCommand, requestedNewMachineTypeToCreate);
        } else {
            snprintf(createMachineRequest, requestSize, "%s:%s:%d:%d:%s", createTypeCommand, requestedNewMachineTypeToCreate, numArgs, payloadType, payloadString);

        }
    }
    
    
    char* machineNameWrapper[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine is sending out the following network request:", machineNameWrapper, 1)); //TODO use this method for all future ocall_prints
    ocall_print(createMachineRequest);
    // int ret_value;    
    // ocall_network_request(&ret_value, createMachineRequest, newMachinePublicIDKey, SIZE_OF_IDENTITY_STRING + 1);
    newMachinePublicIDKey = send_network_request_API(createMachineRequest);

    
    char* machineNameWrapper2[] = {currentMachineIDPublicKey};
    ocall_print(generateCStringFromFormat("%s machine has created a new machine with Identity Public Key as:", machineNameWrapper2, 1)); //TODO use this method for all future ocall_prints
    ocall_print(newMachinePublicIDKey);

    // if (isSecureCreate) {

    //     //Now, need to retrieve capabilityKey for this newMachinePublicIDKey and store (thisMachineID, newMachinePublicIDKey) -> capabilityKey
    //     string request = "GetKey:" + string(currentMachineIDPublicKey) + ":" + string(newMachinePublicIDKey);//TODO unhardcode current Machine name
    //     //TODO replace above line with snprintf as did with createMachineRequest, and do this everywhere in code
    //     char* getChildMachineIDRequest = (char*) request.c_str(); 
    //     char* capabilityKey = retrieveCapabilityKeyForChildFromKPS(currentMachineIDPublicKey, newMachinePublicIDKey);//(char*) malloc(SIZE_OF_CAPABILITYKEY); 
    //     //ocall_network_request(&ret_value, getChildMachineIDRequest, capabilityKey, SIZE_OF_CAPABILITYKEY);
        
    //     char* machineNameWrapper3[] = {currentMachineIDPublicKey};
    //     ocall_print(generateCStringFromFormat("%s machine has received capability key for secure child:", machineNameWrapper3, 1)); //TODO use this method for all future ocall_prints
    //     ocall_print(capabilityKey);

    //     PMachineToChildCapabilityKey[make_tuple(currentMachinePID, string(newMachinePublicIDKey))] = string(capabilityKey);

    // }

    //Return the newMachinePublicIDKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, newMachinePublicIDKey);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}


extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) //TODO modify this to take the type of machine to create as a param
{
    return sendCreateMachineNetworkRequest(context, argRefs, "UntrustedCreate", false);
}

extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) 
{   
    //If we are making changes in here, then make appropiate changes in enclave.cpp
    //TODO we need to attest the other enclave before sending it a message, even if we are sending an untrusted message
    PRT_VALUE** P_ToMachine_Payload = argRefs[0];
    PRT_UINT64 sendingToMachinePublicIDPValue = (*P_ToMachine_Payload)->valueUnion.frgn->value;
    char* sendingToMachinePublicID = (char*) sendingToMachinePublicIDPValue;

    PRT_VALUE** P_Event_Payload = argRefs[1];
    char* event = (char*) malloc(SIZE_OF_MAX_EVENT_NAME);
    itoa((*P_Event_Payload)->valueUnion.ev , event, SIZE_OF_MAX_EVENT_NAME);

    const int size_of_max_num_args = 10; //TODO if modififying this, modify it in enclave.cpp

    // PRT_VALUE** P_NumEventArgs_Payload = argRefs[2];
    // int numArgs = (*P_NumEventArgs_Payload)->valueUnion.nt;
    // char* numArgsPayload = (char*) malloc(size_of_max_num_args);
    // itoa(numArgs, numArgsPayload, SIZE_OF_MAX_EVENT_PAYLOAD);

    char* eventMessagePayload = (char*) malloc(SIZE_OF_MAX_EVENT_PAYLOAD);

    // for (int i = 0; i < numArgs; i++) {
        PRT_VALUE** P_EventMessage_Payload = argRefs[3];
        int eventPayloadType = (*P_EventMessage_Payload)->discriminator;
            char* temp = serializePrtValueToString(*P_EventMessage_Payload);
            memcpy(eventMessagePayload, temp, strlen(temp) + 1);
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

    PRT_VALUE** P_NumEventArgs_Payload = argRefs[2];
    int numArgs = (*P_NumEventArgs_Payload)->valueUnion.nt;

    int requestSize = 130 + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_MAX_MESSAGE + 1 + SIZE_OF_MAX_EVENT_PAYLOAD + 1;
    char* unsecureSendRequest = (char*) malloc(requestSize);
    if (numArgs > 0) {
        snprintf(unsecureSendRequest, requestSize, "UntrustedSend:%s:%s:%d:%d:%s", sendingToMachinePublicID, event, numArgs, eventPayloadType, eventMessagePayload);
    } else {
        snprintf(unsecureSendRequest, requestSize, "UntrustedSend:%s:%s:0", sendingToMachinePublicID, event);
    }
    printf("Untrusted machine is sending out following network request: %s\n", unsecureSendRequest);   
    char* newMachinePublicIDKey = send_network_request_API(unsecureSendRequest);


    // // char* empty;
    // // int ret_value;
    // // ocall_network_request(&ret_value, secureSendRequest, empty, 0);


    // // char* networkRequest = "UntrustedCreate:Coordinator";
    // // char* returnMessage = send_network_request_API(networkRequest);
    // // printf("Network Message Confirmation: %s", returnMessage);
    
}


extern "C" void P_SecureSendPingEventToPongEnclave_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    

    const char* current_machine_name = "PingMachine";
    const char* receiving_machine_name = "PongMachine";

    //Make secure payload to be the Ping's event unique identifier
    sprintf(secure_message, "%d", P_EVENT_Ping.value.valueUnion.ev);

    //NOTE: Should we spawn a thread for network requests?
    //Send "network" request to Pong enclave to start the remote attestation channel creation process
    if (ra_network_send_receive(current_machine_name, receiving_machine_name, NULL, NULL) == 0) {
        printf("\nAttestation Succesful! Ping Event has been Sent!\n");

    } else {
        printf("\nERROR IN ATTESTATION. Message not sent!\n");

    }
    
}

extern "C" PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
    //USMs can only make untrusted requests to create machines
    PRT_VALUE* temp = P_UntrustedCreateCoordinator_IMPL(context, argRefs);
    // printf("VALUE IS : %s", temp->valueUnion.frgn->value);
    // fflush(stdout);
    return temp;// PrtMkIntValue(3);//PrtCloneValue(temp);
}

char* receiveNetworkRequest(char* request) {

    char* requestCopy = (char*) malloc(strlen(request) + 1);
    memcpy(requestCopy, request, strlen(request) + 1);

    char* split = strtok(request, ":");
    if (strcmp(split, "Create") == 0) {
        char* newMachineID = (char* ) malloc(SIZE_OF_IDENTITY_STRING);
        split = strtok(NULL, ":");
        char* parentTrustedMachinePublicIDKey = split;
        split = strtok(NULL, ":");
        char* machineType = split;
        split = strtok(NULL, ":");
        int numArgs = atoi(split);
        int payloadType = -1;
        char* payload = (char*) malloc(10);
        payload[0] = '\0';
        if (numArgs > 0) {
            split = strtok(NULL, ":");
            payloadType = atoi(split);
            split = strtok(NULL, ":");
            payload = split;

        }

         if (USMAuthorizedTypes.count(machineType) > 0) {
            return createUSMMachineAPI(machineType, numArgs, payloadType, payload);
        } else {
            return untrusted_enclave1_receiveNetworkRequest(requestCopy);
        }

    }  else if (strcmp(split, "UntrustedCreate") == 0) {

        char* newMachineID = (char* ) malloc(SIZE_OF_IDENTITY_STRING);
        split = strtok(NULL, ":");
        char* machineType = split;
        split = strtok(NULL, ":");
        int numArgs = atoi(split);
        int payloadType = -1;
        char* payload = (char*) malloc(10);
        payload[0] = '\0';
        if (numArgs > 0) {
            split = strtok(NULL, ":");
            payloadType = atoi(split);
            split = strtok(NULL, ":");
            payload = split;

        }

        if (USMAuthorizedTypes.count(machineType) > 0) {
            return createUSMMachineAPI(machineType, numArgs, payloadType, payload);
        } else {
            return untrusted_enclave1_receiveNetworkRequest(requestCopy);
        }

    
    } else if (strcmp(split, "InitComm") == 0) {

        char* newSessionKey = (char* ) malloc(SIZE_OF_SESSION_KEY);
        newSessionKey[0] = '\0';
        split = strtok(NULL, ":");
        char* machineInitializingComm = split;
        split = strtok(NULL, ":");
        char* machineReceivingComm = split;

        if (USMPublicIdentityKeyToMachinePIDDictionary.count(string(machineReceivingComm)) > 0) {
            
            return USMinitializeCommunicationAPI(machineInitializingComm, machineReceivingComm);
        
        } else {
            return untrusted_enclave1_receiveNetworkRequest(requestCopy);
        }
    
    }  else if (strcmp(split, "UntrustedSend") == 0) {

        char* temp;
        split = strtok(NULL, ":");
        char* machineReceivingMessage = split;
        split = strtok(NULL, ":");
        char* eventNum = split;
        split = strtok(NULL, ":");
        int numArgs = atoi(split);
        int payloadType = -1;
        char* payload = (char*) malloc(10);
        payload[0] = '\0';
        if (numArgs > 0) {
            split = strtok(NULL, ":");
            payloadType = atoi(split);
            split = strtok(NULL, ":");
            payload = split;

        }

        string machineReceiveMsgString = string(machineReceivingMessage);
        // printf("Untrusted Send -> machine checking in dictionary is %s\n", machineReceiveMsgString.c_str());
        if (USMPublicIdentityKeyToMachinePIDDictionary.count(string(machineReceivingMessage)) > 0) {
            // printf("Sending Message to USM in app.cpp\n");
            return USMsendMessageAPI(machineReceivingMessage, eventNum, numArgs, payloadType, payload);
            
        } else {
            return untrusted_enclave1_receiveNetworkRequest(requestCopy);
        }

    } else if (strcmp(split, "Send") == 0) {

        char* temp;
        split = strtok(NULL, ":");
        char* machineSendingMessage = split;
        split = strtok(NULL, ":");
        char* machineReceivingMessage = split;

         if (USMPublicIdentityKeyToMachinePIDDictionary.count(string(machineReceivingMessage)) > 0) {

            //TODO need to implement
            return "TODO";
            
        } else {
            return untrusted_enclave1_receiveNetworkRequest(requestCopy);
        }


    } else {
        return "Command Not Found";
    }



}

char* USMinitializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey) {
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
        char* errorMsg = "Already created!";
        printf("ERROR:Session has already been initalized in the past!\n");
        return errorMsg;
    }
    
}

void generateSessionKey(string& newSessionKey) {
    //TODO Make this generate a random key
    int randNum = rand() % 100;
    newSessionKey = "GenSessionKe" + to_string(randNum);
} 

char* USMsendMessageAPI(char* receivingMachineIDKey, char* eventNum, int numArgs, int payloadType, char* payload) {
    //TODO if modifying this, modify sendUntrustedMessageAPI in enclave.cpp
   PRT_MACHINEID receivingMachinePID;
    printf("Machine receiving message has a PID of:");
    char* temp = (char*) malloc(10);
    snprintf(temp, 5, "%d\n", USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)]);
    printf(temp);
    receivingMachinePID.machineId = USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)];
    handle_incoming_event(atoi(eventNum), receivingMachinePID, numArgs, payloadType, payload);
    return "Message successfully sent!/n";
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
    PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    PRT_MACHINEID pingId;
    pingId.machineId = 1;

    PRT_MACHINEINST* pingMachine = PrtGetMachine(process, PrtMkMachineValue(pingId));
    PrtSend(NULL, pingMachine, pongEvent, 0);
    return 0;
}

char* registerMachineWithNetwork(char* newMachineID) {

    char* machineKeyWrapper[] = {newMachineID};
    
    return send_network_request_API(generateCStringFromFormat("RegisterMachine:%s:-1", machineKeyWrapper, 1));

}

char* createUSMMachineAPI(char* machineType, int numArgs, int payloadType, char* payload) {
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

    char* usmChildPublicIDKeyCopy2 = (char*) malloc(usmChildPublicIDKey.size() + 1);
    memcpy(usmChildPublicIDKeyCopy2, usmChildPublicIDKey.c_str(), usmChildPublicIDKey.size() + 1);

    createMachine(machineType, numArgs, payloadType, payload);

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
            //Shiv Hardcoded
            PRT_BOOLEAN foundMachine = PrtLookupMachineByName("GodUntrusted", &mainMachine);
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


        PrtUpdateAssertFn(MyAssert);

    }

}

int main(int argc, char const *argv[]) {

    //Shiv Hardcoded
    USMAuthorizedTypes.insert("ClientWebBrowser");
    USMAuthorizedTypes.insert("GodUntrusted");
    USMAuthorizedTypes.insert("BankHost");

    initNetwork();

    // Place the measurement of the enclave into metadata_info.txt
    system("sgx_sign dump -enclave enclave.signed.so -dumpfile metadata_info.txt");

    createUSMMachineAPI("GodUntrusted", 0, 0, "");

    return 0;
}

extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

}

extern "C" PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

}


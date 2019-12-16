#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include "network_ra.h"
#include "PingPong.h"
#include <pthread.h> 
#include "enclave_untrusted_host.h"
#include "app.h"
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <map>

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

unordered_map<int, string> USMMachinePIDtoPublicIdentityKeyDictionary;
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

int atoi(char *p) {
    int k = 0;
    while (*p) {
        k = (k << 3) + (k << 1) + (*p) - '0';
        p++;
     }
     return k;
}

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        char temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        //swap(*(str+start), *(str+end)); 
        start++; 
        end--; 
    } 
} 

// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 

void generateIdentity(string& publicID, string& privateID) {
    int randNum = rand() % 100;
    publicID = "UntrustedPubl" + to_string(randNum);
    privateID = "UntrustedPriv" + to_string(randNum);
} 

extern "C" PRT_VALUE* P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    string publicID;
    string privateID;
    generateIdentity(publicID, privateID);
    //TODO store the privateID

    USMMachinePIDtoPublicIdentityKeyDictionary[currentMachinePID] = publicID;
    USMPublicIdentityKeyToMachinePIDDictionary[publicID] = currentMachinePID;
}

extern "C" PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    char* currentMachineIDPublicKey;
 
    currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)(USMMachinePIDtoPublicIdentityKeyDictionary[currentMachinePID].c_str())); 
  
    //Return the currentMachineIDPublicKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, currentMachineIDPublicKey);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}


extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) //TODO modify this to take the type of machine to create as a param
{
    char* networkRequest = "UntrustedCreate:Coordinator:1:2:9"; //PRT_VALUE_KIND_INT is 2
    char* newMachinePublicIDKey = send_network_request_API(networkRequest);
    //printf("Network Message Confirmation: %s", returnMessage);

    //Return the newMachinePublicIDKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, newMachinePublicIDKey);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}

extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) 
{   
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
        PRT_VALUE** P_EventMessage_Payload = argRefs[2];
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



    int requestSize = 130 + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_MAX_MESSAGE + 1 + SIZE_OF_MAX_EVENT_PAYLOAD + 1;
    char* unsecureSendRequest = (char*) malloc(requestSize);
    snprintf(unsecureSendRequest, requestSize, "UntrustedSend:%s:%s:%s", sendingToMachinePublicID, event, eventMessagePayload);
    printf("Untrusted machine is sending out following network request: %s\n", unsecureSendRequest);   
    char* newMachinePublicIDKey = send_network_request_API(unsecureSendRequest);


    // // char* empty;
    // // int ret_value;
    // // ocall_network_request(&ret_value, secureSendRequest, empty, 0);


    // // char* networkRequest = "UntrustedCreate:Coordinator";
    // // char* returnMessage = send_network_request_API(networkRequest);
    // // printf("Network Message Confirmation: %s", returnMessage);
    
}

char* serializePrtValueToString(PRT_VALUE* value) {
    //TODO code the rest of the types
    //TODO if modifying this, also modify in app.cpp
    if (value->discriminator == PRT_VALUE_KIND_INT) {
        char* integer = (char*) malloc(10);
        itoa(value->valueUnion.nt, integer, 10);
        return integer;
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
    printf("VALUE IS : %s", temp->valueUnion.frgn->value);
    fflush(stdout);
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
            return createUSMMachine(machineType, numArgs, payloadType, payload);
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
            return createUSMMachine(machineType, numArgs, payloadType, payload);
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

        if (USMPublicIdentityKeyToMachinePIDDictionary.count(machineReceivingComm) > 0) {
            
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
        char* payload = split;

        if (USMPublicIdentityKeyToMachinePIDDictionary.count(machineReceivingMessage) > 0) {

            return USMsendMessageAPI(machineReceivingMessage, eventNum, payload);
            
        } else {
            return untrusted_enclave1_receiveNetworkRequest(requestCopy);
        }

    } else if (strcmp(split, "Send") == 0) {

        char* temp;
        split = strtok(NULL, ":");
        char* machineSendingMessage = split;
        split = strtok(NULL, ":");
        char* machineReceivingMessage = split;
        split = strtok(NULL, ":");
        char* eventNum = split;
        split = strtok(NULL, ":");
        char* numArgs = split;
        split = strtok(NULL, ":");
        char* payload = split;

         if (USMPublicIdentityKeyToMachinePIDDictionary.count(machineReceivingMessage) > 0) {

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

char* USMsendMessageAPI(char* receivingMachineIDKey, char* eventNum, char* payload) {
    //TODO if modifying this, modify sendUntrustedMessageAPI in enclave.cpp
   PRT_MACHINEID receivingMachinePID;
    printf("Machine receiving message has a PID of:");
    char* temp = (char*) malloc(10);
    snprintf(temp, 5, "%d\n", USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)]);
    printf(temp);
    receivingMachinePID.machineId = USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)];
    handle_incoming_event(atoi(eventNum), receivingMachinePID, 1, payload);
    return "Message successfully sent!/n";
}

// OCall implementations
void ocall_print(const char* str) {
    printf("[o] %s\n", str);
    fflush(stdout);
}

void ocall_print_int(int intPrint) {
    printf("Value is: %d\n", intPrint);
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

int handle_incoming_events_ping_machine(PRT_UINT32 eventIdentifier) {
    PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    PRT_MACHINEID pingId;
    pingId.machineId = 1;

    PRT_MACHINEINST* pingMachine = PrtGetMachine(process, PrtMkMachineValue(pingId));
    PrtSend(NULL, pingMachine, pongEvent, 0);
    return 0;
}

char* generateCStringFromFormat(char* format_string, char* strings_to_print[], int num_strings) {
    //NOTE make changes in enclave.cpp as well
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

int getNextPID() {
    return ((PRT_PROCESS_PRIV*)process)->numMachines + 1;
}

char* registerMachineWithNetwork(char* newMachineID) {

    char* machineKeyWrapper[] = {newMachineID};
    
    return send_network_request_API(generateCStringFromFormat("RegisterMachine:%s:-1", machineKeyWrapper, 1));

}

char* createUSMMachine(char* machineType, int numArgs, int payloadType, char* payload) {
    
    //TODO Do we need to verify signature of parentTrustedMachinePublicIDKey?
    int newMachinePID = getNextPID(); 

    string usmChildPublicIDKey;
    string usmChildPrivateIDKey;
    generateIdentity(usmChildPublicIDKey, usmChildPrivateIDKey);
    USMMachinePIDtoPublicIdentityKeyDictionary[newMachinePID] = usmChildPublicIDKey;
    USMPublicIdentityKeyToMachinePIDDictionary[usmChildPublicIDKey] = newMachinePID;

    char* usmChildPublicIDKeyCopy = (char*) malloc(usmChildPublicIDKey.size() + 1);
    memcpy(usmChildPublicIDKeyCopy, usmChildPublicIDKey.c_str(), usmChildPublicIDKey.size() + 1);
    registerMachineWithNetwork(usmChildPublicIDKeyCopy);

    char* usmChildPublicIDKeyCopy2 = (char*) malloc(usmChildPublicIDKey.size() + 1);
    memcpy(usmChildPublicIDKeyCopy2, usmChildPublicIDKey.c_str(), usmChildPublicIDKey.size() + 1);

    createMachine(machineType, numArgs, payloadType, payload);

    //Return the publicIDKey of the new machine
    return usmChildPublicIDKeyCopy2;
}

int createMachine(char* machineType, int numArgs, int payloadType, char* payload) {
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

int main(int argc, char const *argv[]) {

    //TODO unhardcode
    USMAuthorizedTypes.insert("Ping");
    USMAuthorizedTypes.insert("Temp");



        initNetwork();

        // Place the measurement of the enclave into metadata_info.txt
        system("sgx_sign dump -enclave enclave.signed.so -dumpfile metadata_info.txt");

		PRT_GUID processGuid;
		PRT_VALUE *payload;
        PRT_VALUE *payload2;

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
            payload2 = PrtMkNullValue();

		}
		else
		{
			int i = atoi(parg);
			payload = PrtMkIntValue(i);
            payload2 = PrtMkIntValue(i);

            
		}

		PrtUpdateAssertFn(MyAssert);
        ocall_print("after update assert fn!\n");

        PRT_UINT32 mainMachine = 1; //TODO NOTE: I'm not able to send messages to machines unless they have id of 1. Otherwise I receive 
        // id out of bounds when I call PRT_MACHINEINST* pingMachine = PrtGetMachine(process, PrtMkMachineValue(pingId));
		PRT_BOOLEAN foundMachine = PrtLookupMachineByName("Ping", &mainMachine);
		PrtAssert(foundMachine, "No 'Ping' machine found!");
		PRT_MACHINEINST* pingMachine = PrtMkMachine(process, mainMachine, 1, &payload);    
        
        printf("after mk machine!\n");

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
    
    return 0;
}

extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

}

extern "C" PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
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
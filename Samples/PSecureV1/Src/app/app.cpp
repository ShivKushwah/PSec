#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include "network_ra.h"
#include "PingPong.h"
#include <pthread.h> 
#include "pong_enclave_attestation.h"
#include "app.h"
#include <string>
#include <unordered_map> 
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

unordered_map<int, string> MachinePIDtoPublicIdentityKeyDictionary;

int ID_GENERATOR_SEED = 0;

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

void generateIdentity(string& publicID) {
    //TODO Make this generate a random pk sk pair
    publicID = "UntrustedPublic" + to_string(ID_GENERATOR_SEED);
    ID_GENERATOR_SEED += 1;
} 

extern "C" PRT_VALUE* P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    string publicID;
    generateIdentity(publicID);

    MachinePIDtoPublicIdentityKeyDictionary[currentMachinePID] = publicID;
}

extern "C" PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    char* currentMachineIDPublicKey;
 
    currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)(MachinePIDtoPublicIdentityKeyDictionary[currentMachinePID].c_str())); 
  
    //Return the currentMachineIDPublicKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, currentMachineIDPublicKey);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}


extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) //TODO modify this to take the type of machine to create as a param
{
    if (initialize_enclave(&global_eid, "enclave.token", "enclave.signed.so") < 0) { //TODO figure out how to initialize all enclaves. Maybe network_ra should do that as a setup step?
        std::cout << "Fail to initialize enclave." << std::endl;
    }

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

extern "C" void P_InitializePongEnclave_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    //TODO move initalization code in InitializePongEnclave method
    if (initialize_enclave(&global_eid, "enclave.token", "enclave.signed.so") < 0) {
        std::cout << "Fail to initialize enclave." << std::endl;
    }

    int ptr;
    //Start up PrtTrusted inside enclave
    sgx_status_t status = enclave_main(global_eid, &ptr); 
    std::cout << status << std::endl;
    if (status != SGX_SUCCESS) {
        std::cout << "Error in Starting PrtTrusted" << std::endl;
    }
    
    
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

// OCall implementations
void ocall_print(const char* str) {
    printf("[o] %s\n", str);
}

void ocall_print_int(int intPrint) {
    printf("Value is: %d\n", intPrint);
}

int handle_incoming_events_ping_machine(PRT_UINT32 eventIdentifier) {
   // PRT_VALUE* pongEvent = PrtMkEventValue(eventIdentifier);
    PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    PRT_MACHINEID pingId;
    pingId.machineId = 1;

    PRT_MACHINEINST* pingMachine = PrtGetMachine(process, PrtMkMachineValue(pingId));
    PrtSend(NULL, pingMachine, pongEvent, 0);
    return 0;
}

int main(int argc, char const *argv[]) {

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
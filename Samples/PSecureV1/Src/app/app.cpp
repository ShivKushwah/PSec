#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include "network_ra.h"
#include <pthread.h> 
#include "enclave_untrusted_host.h"
#include "app.h"
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <map>
#include <tuple>
#include "sample_libcrypto.h"

using namespace std;

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

sgx_enclave_id_t global_app_eid = 0;

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
map<PublicMachineChildPair, string> PublicIdentityKeyToChildSessionKey;
map<PMachineChildPair, string> PMachineToChildCapabilityKey; //should be empty



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
    if (!NETWORK_DEBUG) {
        char* private_identity_key_raw = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        char* public_identity_key_raw = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        char* private_identity_key = (char*) malloc(sizeof(sgx_rsa3072_key_t));
        char* public_identity_key = (char*) malloc(sizeof(sgx_rsa3072_public_key_t));
        sgx_status_t status = enclave_createRsaKeyPairEcall(global_app_eid, public_identity_key_raw, private_identity_key_raw, public_identity_key, private_identity_key, SGX_RSA3072_KEY_SIZE); 
        if (status != SGX_SUCCESS) {
            ocall_print("APP Error in generating identity keys!");
        // } else  {
        //     ocall_print("KPS able to generate identity keys!");
        }
        publicID = string(public_identity_key_raw, SGX_RSA3072_KEY_SIZE);
        privateID = string(private_identity_key_raw, SGX_RSA3072_KEY_SIZE);

    } else {
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
    MachinePIDToIdentityDictionary[currentMachinePID] = make_tuple(string(publicID.c_str(), SGX_RSA3072_KEY_SIZE), string(privateID.c_str(), SGX_RSA3072_KEY_SIZE));
    USMPublicIdentityKeyToMachinePIDDictionary[string(publicID.c_str(), SGX_RSA3072_KEY_SIZE)] = currentMachinePID;

}


extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) //TODO modify this to take the type of machine to create as a param
{
    return sendCreateMachineNetworkRequest(context, argRefs, "UntrustedCreate", false);
}

extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) 
{   
    //TODO shivIdentity

    sendSendNetworkRequest(context, argRefs, "UntrustedSend", false, false);
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
char* USMinitializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* newSessionKey) { //TODO shividentity
    ocall_print("USM Initialize Communication API Called!");

    int count;
    count = PublicIdentityKeyToChildSessionKey.count(make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE)));
    
    if (count == 0) {
        PublicIdentityKeyToChildSessionKey[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE))] = string(newSessionKey, SIZE_OF_REAL_SESSION_KEY);
        char* successMessage = createStringLiteralMalloced("Success: Session Key Received");
        printf("Received correct session key!\n");
        return successMessage;
    } else {
        char* errorMsg = createStringLiteralMalloced("Already created!");
        printf("ERROR:Session has already been initalized in the past!\n");
        return errorMsg;
    }
    
    
    // printf("USM Initialize Communication API Called!\n");
    // //TODO need to verify signature over requestingMachineIDKey
    // if (PublicIdentityKeyToChildSessionKey.count(make_tuple(string(receivingMachineIDKey), string(requestingMachineIDKey))) == 0) {
    //     //TODO this logic needs to be diffie hellman authenticated encryption
    //     string newSessionKey;
    //     generateSessionKey(newSessionKey);
    //     PublicIdentityKeyToChildSessionKey[make_tuple(receivingMachineIDKey, requestingMachineIDKey)] = newSessionKey;
    //     printf("Returning correct session key!\n");
    //     char* returnSessionkey = (char*) malloc(newSessionKey.length() + 1);
    //     memcpy(returnSessionkey, newSessionKey.c_str(), newSessionKey.length() + 1);
    //     return returnSessionkey;
    // } else {
    //     char* errorMsg = createStringLiteralMalloced("Already created!");
    //     printf("ERROR:Session has already been initalized in the past!\n");
    //     return errorMsg;
    // }
    
}

// void generateSessionKey(string& newSessionKey) {
//     //TODO Make this generate a random key
//     int randNum = rand() % 100;
//     newSessionKey = "GenSessionKe" + to_string(randNum);
// } 

char* newUSMSendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage) {
    char buf[4096];


    ocall_print("entered usm decrypt fn");
    ocall_print("Encrypted Message parameter is ");
    printPayload(encryptedMessage, 1121);
    char* encryptedMessageCopy = NULL;
    encryptedMessageCopy = (char*) malloc(1300);
    memcpy(encryptedMessageCopy, encryptedMessage, 1299);
    encryptedMessageCopy[1299] = '\0';
    printf("encryptedMessageCopy %d,%s",&encryptedMessageCopy, encryptedMessageCopy);
    char* reentrant = NULL;
    char* split = NULL;
    char* encryptedMessageSize = NULL;
    split = strtok(encryptedMessageCopy, ":");
    ocall_print("debug time");
    snprintf(buf, 100, "%s", encryptedMessageCopy);
    buf[101] = '\0';
    printf("buf %d,%s",&buf, buf);
    printf("encryptedMessageCopy %d,%s",&encryptedMessageCopy, encryptedMessageCopy);
    encryptedMessageSize = split;
    ocall_print("encryptedMessageSize is");
    ocall_print(encryptedMessageSize);

    int encryptedMessageSizeInt = atoi(encryptedMessageSize);
    int encryptedMessageSizeIntString = strlen(encryptedMessageSize);
    // char* encryptedMessageCopy = (char*) malloc(encryptedMessageSizeInt);
    // memcpy(encryptedMessageCopy, encryptedMessage, encryptedMessageSizeInt);
    // encryptedMessageCopy[encryptedMessageSizeIntString] = ':';

    ocall_print("encryptedMessageSizeIntString is");
    ocall_print_int(encryptedMessageSizeIntString);
    ocall_print_int(encryptedMessageSizeInt);
    ocall_print_int(atoi(encryptedMessageSize));
    ocall_print("encrypted Messsage is ddd");
    printPayload(encryptedMessage, encryptedMessageSizeInt + 1 + encryptedMessageSizeIntString);
    char* eventNum;
    int numArgs;
    int payloadType;
    char* payload;
    int payloadSize;
    char* next = NULL;

    char* decryptedMessage = NULL;

    if (!NETWORK_DEBUG) {
        int machinePID = USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)];
        // string sendingToMachineCapabilityKeyPayload = MachinePIDtoCapabilityKeyDictionary[machinePID];
        // char* publicCapabilityKeySendingToMachine = retrievePublicCapabilityKey((char*)sendingToMachineCapabilityKeyPayload.c_str());

        string sessionKey = PublicIdentityKeyToChildSessionKey[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE))];

        sgx_aes_ctr_128bit_key_t g_region_key;
        sgx_aes_gcm_128bit_tag_t g_mac;
        memcpy(g_region_key, (char*)sessionKey.c_str(), 16);
        memcpy(g_mac, mac, SIZE_OF_MAC);

        char* actualEncryptedMessage = encryptedMessage + encryptedMessageSizeIntString + 1;
        decryptedMessage = (char*) malloc(encryptedMessageSizeInt);
        ocall_print("malloced");
        ocall_print("session key is");
        printPayload((char*)sessionKey.c_str(), 16);
        ocall_print("iv is");
        printPayload(iv, 12);
        ocall_print("mac is");
        printPayload(mac, 16);
        ocall_print("actual encrypted message is");
        printPayload(actualEncryptedMessage, encryptedMessageSizeInt);
        
        sample_rijndael128GCM_encrypt(&g_region_key, (const uint8_t*) actualEncryptedMessage, encryptedMessageSizeInt, (uint8_t*)decryptedMessage, (const uint8_t*) iv, SIZE_OF_IV, NULL, 0, &g_mac);
        ocall_print("USM decrypted");
        
        printPayload(decryptedMessage, encryptedMessageSizeInt);
        char* checkMyPublicIdentity = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        memcpy(checkMyPublicIdentity, decryptedMessage, SGX_RSA3072_KEY_SIZE);
        if (string(checkMyPublicIdentity, SGX_RSA3072_KEY_SIZE) != string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)) {
            ocall_print("ERROR: Checking Public Identity Key inside Message FAILED in Untrusted Send");
            // return 0;
        }

        sgx_rsa3072_signature_t* decryptedSignature = (sgx_rsa3072_signature_t*) malloc(SGX_RSA3072_KEY_SIZE);
        // char* message = (char*) malloc(atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1); 
        // memcpy(message, decryptedMessage + SGX_RSA3072_KEY_SIZE + 1, atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1);
        char* messageSignedOver = (char*) malloc(encryptedMessageSizeInt - SGX_RSA3072_KEY_SIZE - 1);
        memcpy(messageSignedOver, decryptedMessage, encryptedMessageSizeInt - SGX_RSA3072_KEY_SIZE - 1);
        memcpy(decryptedSignature, decryptedMessage + encryptedMessageSizeInt - SGX_RSA3072_KEY_SIZE, SGX_RSA3072_KEY_SIZE);
        // ocall_print("Lenght of encrypted message is ");
        // ocall_print(encryptedMessageSize);
        // ocall_print("Received Signature:");
        // printRSAKey((char*)decryptedSignature);
        // ocall_print("Signature is over message");
        // printRSAKey(messageSignedOver);
        // ocall_print_int(atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1);
        // ocall_print("Key needed to verify signature is");
        // ocall_print((char*)sendingToMachineCapabilityKeyPayload.c_str());
        // ocall_print("actual key is");
        // printPublicCapabilityKey(publicCapabilityKeySendingToMachine);
        // // printPrivateCapabilityKey(retrievePrivateCapabilityKey((char*)sendingToMachineCapabilityKeyPayload.c_str()));

        // if (verifySignature(messageSignedOver, atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1, decryptedSignature, (sgx_rsa3072_public_key_t*)publicCapabilityKeySendingToMachine)) {
        //     ocall_print("Verifying Signature works!!!!");
        // } else {
        //     ocall_print("Error: Secure Send Signature Verification Failed!");
        //     // return 0;
        // }

        safe_free(checkMyPublicIdentity);
        char* message = (char*) malloc(encryptedMessageSizeInt); 
        memcpy(message, decryptedMessage + SGX_RSA3072_KEY_SIZE + 1, encryptedMessageSizeInt);
        next = message;

    }

    split = strtok_r(next, ":", &reentrant);
    eventNum = split;
    split = strtok_r(NULL, ":", &reentrant);
    ocall_print("num args is");
    ocall_print(split);
    numArgs = atoi(split);
    payloadType = -1;
    // ocall_print("MAC IS");
    // ocall_print(mac);
    payload = (char*) malloc(10);
    payloadSize;
    payload[0] = '\0';
    if (numArgs > 0) {
        split = strtok_r(NULL, ":", &reentrant);
        payloadType = atoi(split);
        split = strtok_r(NULL, ":", &reentrant);;
        payloadSize = atoi(split);
        safe_free(payload);
        payload = split + strlen(split) + 1;

    } else {
        safe_free(payload);
    }

    PRT_MACHINEID receivingMachinePID;
    char* temp = (char*) malloc(10);
    snprintf(temp, 5, "%d\n", USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)]);
    printf(temp);
    safe_free(temp);
    receivingMachinePID.machineId = USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)];



    handle_incoming_event(atoi(eventNum), receivingMachinePID, numArgs, payloadType, payload, payloadSize); //TODO shividentity

    
    // sendMessageAPI(requestingMachineIDKey, receivingMachineIDKey, eventNum, numArgs, payloadType, payload, payloadSize);
    safe_free(decryptedMessage);

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

void ocall_request_user_input(char* user_input, uint32_t max_input_len) {
    fgets(user_input, max_input_len, stdin);
    strtok(user_input, "\n"); //To remove trailing new line in fgets
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
    
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(string(usmChildPublicIDKey.c_str(), SGX_RSA3072_KEY_SIZE), string(usmChildPrivateIDKey.c_str(), SGX_RSA3072_KEY_SIZE));
    USMPublicIdentityKeyToMachinePIDDictionary[string(usmChildPublicIDKey.c_str(), SGX_RSA3072_KEY_SIZE)] = newMachinePID;
  
    // MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(usmChildPublicIDKey, usmChildPrivateIDKey);
    // USMPublicIdentityKeyToMachinePIDDictionary[usmChildPublicIDKey] = newMachinePID;
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

void initApp() {
    global_app_eid = 0;
    string token = "enclaveapp.token";

    if (initialize_enclave(&global_app_eid, token, "enclave.signed.so") < 0) {
        ocall_print("Fail to initialize enclave.");
    }    
}

int main(int argc, char const *argv[]) {
    initNetwork();
    initKPS();
    initApp();
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


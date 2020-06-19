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
#include "network_simulator.h"
#include "sgx_uae_service.h"
#include "sgx_capable.h"

using namespace std;

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_app_eid = 0;

//P Process setup constants
static PRT_BOOLEAN cooperative = PRT_FALSE;
static int threads = 1;
static PRT_BOOLEAN perf = PRT_FALSE;
static long steps = 0;
static long startTime = 0;
static long perfEndTime = 0;
static const char* parg = NULL;
static const char* workspaceConfig;
long threadsRunning = 0;
pthread_mutex_t threadsRunning_mutex;
PRT_PROCESS *process;

//Information about this host machine
char* host_machine_IP_address;
int host_machine_port;

//Information about KPS machine
extern char* KPS_IP_ADDRESS;
extern int KPS_PORT_GENERIC;
extern int KPS_PORT_ATTESTATION;
char* KPS_CERT_LOCATION; 
char* KPS_CERT_KEYS_LOCATION; // will be empty if not KPS process
char* DST_HOST_CERT_LOCATION; // will be empty if KPS process
char* DST_HOST_CERT_KEYS_LOCATION; //will be empty if KPS process

bool isKpsProcess = false;

unordered_map<int, identityKeyPair> MachinePIDToIdentityDictionary; //Map from (this host machine's USM P Process ID) -> its Identity public/private key 
unordered_map<string, int> USMPublicIdentityKeyToMachinePIDDictionary;

map<PublicMachineChildPair, string> PublicIdentityKeyToChildSessionKey; //Map from (this host machine USM, different USM) -> encyption key for messages sent between USMs

map<tuple<string,string>, int> ChildSessionKeyToNonce;

unordered_map<string, string> PublicIdentityKeyToPublicSigningKey; //Map from (encryption key) -> signing key [Needed due to SGX Apis]
unordered_map<string, string> PrivateIdentityKeyToPrivateSigningKey;

unordered_set<string> USMAuthorizedTypes; //Set containing the types of USMs this host machine is authorized to create

map<PMachineChildPair, string> PMachineToChildCapabilityKey; // Should be an empty map - needed for helper.cpp compilation purposes

// Main Function (entry point for distributed host machine and entire application)
// Determine whether this machine is a distributed host or a KPS and execute functionality accordingly
int main(int argc, char const *argv[]) {

    #ifdef HW_MODE_ENABLED
    //Enable SGX hardware mode for this application
    sgx_device_status_t sgx_device_status;
    sgx_status_t sgx_ret = sgx_cap_enable_device(&sgx_device_status);
    if (sgx_ret != SGX_SUCCESS) {
            printf("Failed to get SGX device status.\n");
            //return -1;
    } else {
            switch (sgx_device_status) {
                    case SGX_ENABLED:
                    printf("SGX device is enabled\n");
                    break;
                    case SGX_DISABLED_REBOOT_REQUIRED:
                    printf("SGX device has been enabled. Please reboot your machine.\n");
                    break;
                    case SGX_DISABLED_LEGACY_OS:
                    printf("SGX device can't be enabled on an OS that doesn't support EFI interface.\n");
                    break;
                    case SGX_DISABLED:
                    printf("SGX device not found.\n");
                    break;
                    default:
                    printf("Unexpected error.\n");
                    break;
            }
    }
    #endif

    // bool isKpsProcess = false;
    bool isStartHostMachine = true;
    char* startMachineName;

    //Parse command line arguments
    if (strcmp(argv[1], "isKPSProcess=True") == 0) {
        isKpsProcess = true;
    } else {
        isKpsProcess = false;
    }

    char* split = strtok((char*) argv[2], "=");
    split = split + strlen(split) + 1; //Get ip address and generic port of KPS
    string kpsIPAddress;
    parseIPAddressPortString(split, kpsIPAddress, KPS_PORT_GENERIC);
    KPS_IP_ADDRESS = (char*) malloc(IP_ADDRESS_AND_PORT_STRING_SIZE);
    memcpy(KPS_IP_ADDRESS, (char*)kpsIPAddress.c_str(), strlen((char*)kpsIPAddress.c_str()) + 1);

    KPS_PORT_ATTESTATION = atoi((char*) argv[3]); //Attestation port of KPS

    split = strtok((char*) argv[4], "="); //Get location of KPS root certificate location
    split = split + strlen(split) + 1;
    KPS_CERT_LOCATION = (char*) malloc(100);
    memcpy(KPS_CERT_LOCATION, split, strlen(split));
    KPS_CERT_LOCATION[strlen(split)] = '\0';

    if (isKpsProcess) {

        split = strtok((char*) argv[5], "="); //Get location of KPS root certificate keys location
        split = split + strlen(split) + 1;
        KPS_CERT_KEYS_LOCATION = (char*) malloc(100);
        memcpy(KPS_CERT_KEYS_LOCATION, split, strlen(split));
        KPS_CERT_KEYS_LOCATION[strlen(split)] = '\0';

        int i = 6;
        while (i < argc) {
            split = strtok((char*) argv[i], "=");
            char* machineAddress = split;

            char delim[] = ",]";

            split = split + strlen(split) + 2;

            split = strtok(split, delim);

            while (split != NULL) {
                char* parsedMachineType = split; 
                ocall_print(parsedMachineType);
                ocall_print(machineAddress);
                addRegisteredMachineToKPS(parsedMachineType, machineAddress);
                split = strtok(NULL, delim);
            }


            i++;
        }

    } else {
        char* split = strtok((char*) argv[5], "=");
        char* currentHostMachineAddress = split + strlen(split) + 1;

        split = strtok((char*) argv[6], "="); //Get location of distributed host certificate location
        split = split + strlen(split) + 1;
        DST_HOST_CERT_LOCATION = (char*) malloc(100);
        memcpy(DST_HOST_CERT_LOCATION, split, strlen(split));
        DST_HOST_CERT_LOCATION[strlen(split)] = '\0';

        split = strtok((char*) argv[7], "="); //Get location of distributed host certificate keys location
        split = split + strlen(split) + 1;
        DST_HOST_CERT_KEYS_LOCATION = (char*) malloc(100);
        memcpy(DST_HOST_CERT_KEYS_LOCATION, split, strlen(split));
        DST_HOST_CERT_KEYS_LOCATION[strlen(split)] = '\0';

        if (strcmp(argv[8], "isStartMachine=True") == 0) {
            isStartHostMachine = true;
        } else {
            isStartHostMachine = false;
        }

        if (isStartHostMachine) {
            split = strtok((char*) argv[9], "=");
            startMachineName = split + strlen(split) + 1;
        }

        string currIPAddress;

        parseIPAddressPortString(currentHostMachineAddress, currIPAddress, host_machine_port);
        host_machine_IP_address = (char*) malloc(IP_ADDRESS_AND_PORT_STRING_SIZE);
        memcpy(host_machine_IP_address, (char*)currIPAddress.c_str(), strlen((char*)currIPAddress.c_str()) + 1);
    }
    
    startPrtProcessIfNotStarted();
    initKPS();
    initApp();
    if (!isKpsProcess) {
        // if distributed host machine, start threads that wait for network messages on appropiate ports
        start_socket_network_handler();
        if (isStartHostMachine) {
            char* ret = createUSMMachineAPI(startMachineName, 0, 0, "", 0);
            safe_free(ret);
        } else {
            while (true) {

            }
        }
    } else {
        // Place the measurement of the enclave into metadata_info.txt
        system("sgx_sign dump -enclave enclave.signed.so -dumpfile metadata_info.txt");

        //if KPS process, start threads that wait for attestation and other network messages for KPS and keep main process running forever
        start_socket_attestation_network_handler();
        start_socket_kps_generic_network_handler();
        if (isKpsProcess) {
            while (true) {
                
            }
        }
    }
    return 0;
}

void initApp() {
    global_app_eid = 0;
    string token = "enclaveapp.token";

    if (initialize_enclave(&global_app_eid, token, "enclave.signed.so") < 0) {
        ocall_print("Fail to initialize enclave.");
    }    
}

void start_socket_network_handler() {
    pthread_t thread_id; 
    ocall_print("\n Creating Network Socket Handler Thread\n"); 
    pthread_create(&thread_id, NULL, handle_socket_network_request, NULL);

}

void start_socket_attestation_network_handler() {
    pthread_t thread_id; 
    ocall_print("\n Creating Network Socket Handler Thread\n"); 
    pthread_create(&thread_id, NULL, handle_socket_network_request_attestation, NULL);

}

void start_socket_kps_generic_network_handler() {
    pthread_t thread_id; 
    ocall_print("\n Creating Network KPS Generic Handler Thread\n"); 
    pthread_create(&thread_id, NULL, handle_socket_network_kps_generic_requests, NULL);

}


// P Process Required Setup Methods *******************
void ErrorHandler(PRT_STATUS status, PRT_MACHINEINST *ptr)
{
    if (status == PRT_STATUS_ASSERT)
    {
        ocall_enclave_print("exiting with PRT_STATUS_ASSERT (assertion failure)\n");
    }
    else if (status == PRT_STATUS_EVENT_OVERFLOW)
    {
        ocall_enclave_print("exiting with PRT_STATUS_EVENT_OVERFLOW\n");
    }
    else if (status == PRT_STATUS_EVENT_UNHANDLED)
    {
        ocall_enclave_print("exiting with PRT_STATUS_EVENT_UNHANDLED\n");
    }
    else if (status == PRT_STATUS_QUEUE_OVERFLOW)
    {
        ocall_enclave_print("exiting with PRT_STATUS_QUEUE_OVERFLOW \n");
    }
    else if (status == PRT_STATUS_ILLEGAL_SEND)
    {
        ocall_enclave_print("exiting with PRT_STATUS_ILLEGAL_SEND \n");
    }
    else
    {
        ocall_enclave_print("unexpected PRT_STATUS in ErrorHandler: \n");
    }
    exit(1);

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

long get_threadsRunning() {
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

            // PRT_VALUE *payload = PrtMkNullValue();
            // PRT_UINT32 mainMachine = 1; //TODO NOTE: I'm not able to send messages to machines unless they have id of 1. Otherwise I receive 
            // // id out of bounds when I call PRT_MACHINEINST* pingMachine = PrtGetMachine(process, PrtMkMachineValue(pingId));
            // PRT_BOOLEAN foundMachine = PrtLookupMachineByName("UntrustedInitializer", &mainMachine);
            // PrtAssert(foundMachine, "No 'GodUntrusted' machine found!");
            // PRT_MACHINEINST* newMachine = PrtMkMachine(process, mainMachine, 1, &payload);  

            // // test some multithreading across state machines.
            
            // typedef void *(*start_routine) (void *);
            // pthread_t tid[threads];
            // for (int i = 0; i < threads; i++)
            // {
            //     pthread_create(&tid[i], NULL, (start_routine)RunToIdle, (void*)process);
            // }
            // for (int i = 0; i < threads; i++)
            // {
            //     pthread_join(tid[i], NULL);
            // }
            
        }

        for (int i = 0; i < program->nMachines; i++) {
            if (!program->machines[i]->isSecure) {
                USMAuthorizedTypes.insert(createString(program->machines[i]->name));
            }  
        }

        PrtUpdateAssertFn(MyAssert);

    }

}
//*******************


// OCall implementations *******************
void ocall_get_ip_address_of_current_host(char* ipAddress, int MAX_IP_ADDRESS_SIZE) {
    memcpy(ipAddress, host_machine_IP_address, strlen(host_machine_IP_address) + 1);
}

int ocall_get_port_of_current_host() {
    return host_machine_port;
}

void ocall_get_ip_address_of_kps(char* ipAddress, int MAX_IP_ADDRESS_SIZE) {
    memcpy(ipAddress, KPS_IP_ADDRESS, strlen(KPS_IP_ADDRESS) + 1);
}

int ocall_get_generic_port_of_kps() {
    return KPS_PORT_GENERIC;
}

int ocall_get_attestation_port_of_kps() {
    return KPS_PORT_ATTESTATION;
}

void ocall_print(const char* str) {
    if (ENABLE_OCALL_PRINT) {
        printf("[o] %s\n", str);
        fflush(stdout);
    }
}

void ocall_print_int(int intPrint) {
    if (ENABLE_OCALL_PRINT) {
        printf("OCALL_PRINT_INT:Value is %d\n", intPrint);
        fflush(stdout);
    }
}



void ocall_enclave_print(const char* str) {
    printf("[e] %s", str);
    fflush(stdout);
}

void ocall_print_current_time() {
    milliseconds ms = duration_cast< milliseconds >(
        system_clock::now().time_since_epoch()
    );
    std::cout << ms.count() << std::endl;
}

void ocall_request_user_input(char* user_input, uint32_t max_input_len) {
    fgets(user_input, max_input_len, stdin);
    strtok(user_input, "\n"); //To remove trailing new line in fgets
}

void ocall_kill() {
    exit(1);
}

//*******************

//USM API Functions*******************

// USM create state machine API [other SM is trying to create a new USM hosted by this distributed host]
// Responbility of caller to free return value
char* createUSMMachineAPI(char* machineType, int numArgs, int payloadType, char* payload, int payloadSize) {
    startPrtProcessIfNotStarted();
    if (machineTypeIsSecure(machineType)) {
        return "Error: Tried to create SSM inside app!";
    }
    
    int newMachinePID = getNextPID(); 

    string machineTypeString = createString(machineType);
    string usmChildPublicIDKey;
    string usmChildPrivateIDKey;
    string usmChildPublicSigningKey;
    string usmChildPrivateSigningKey;
    generateIdentity(usmChildPublicIDKey, usmChildPrivateIDKey, machineType, usmChildPublicSigningKey, usmChildPrivateSigningKey);
    
    PublicIdentityKeyToPublicSigningKey[usmChildPublicIDKey] = usmChildPublicSigningKey;
    PrivateIdentityKeyToPrivateSigningKey[usmChildPrivateIDKey] = usmChildPrivateSigningKey;
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(string(usmChildPublicIDKey.c_str(), SGX_RSA3072_KEY_SIZE), string(usmChildPrivateIDKey.c_str(), SGX_RSA3072_KEY_SIZE));
    
    //Associate newly created USM's identity with its P ID so that untrusted distributed host machine knows which USM to forward messages to when receiving a network message
    USMPublicIdentityKeyToMachinePIDDictionary[string(usmChildPublicIDKey.c_str(), SGX_RSA3072_KEY_SIZE)] = newMachinePID; 

    
    char* usmChildPublicIDKeyCopy = (char*) malloc(usmChildPublicIDKey.size() + 1);
    memcpy(usmChildPublicIDKeyCopy, usmChildPublicIDKey.c_str(), usmChildPublicIDKey.size() + 1);
    safe_free(usmChildPublicIDKeyCopy);

    char* usmChildPublicIDKeyCopy2 = (char*) malloc(SGX_RSA3072_KEY_SIZE);
    memcpy(usmChildPublicIDKeyCopy2, usmChildPublicIDKey.c_str(), SGX_RSA3072_KEY_SIZE);

    createPMachine(machineType, numArgs, payloadType, payload, payloadSize);

    char* concatStrings[] = {usmChildPublicIDKeyCopy2, ":", (char*) usmChildPublicSigningKey.c_str()};
    int concatLenghts[] = {SGX_RSA3072_KEY_SIZE, 1, sizeof(sgx_rsa3072_public_key_t)};
    char* returnID = concatMutipleStringsWithLength(concatStrings, concatLenghts, 3);
    int requestSize = returnTotalSizeofLengthArray(concatLenghts, 3) + 1;
    safe_free(usmChildPublicIDKeyCopy2);

    ocall_print("createUSMMachineAPI returning");
    printPayload(returnID, requestSize);

    //Return the publicIDKey of the new machine
    return returnID;
}

// USM initialize communication API [other SM is trying to initialize encrypted channel with USM hosted by this distributed host]
// Responsibility of Caller to free return value
char* USMinitializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* encryptedNewSessionKey) {
    ocall_print("USM Initialize Communication API Called!");

    string requestingMachinePublicSigningKey = string(requestingMachineIDKey + SGX_RSA3072_KEY_SIZE + 1, sizeof(sgx_rsa3072_public_key_t));
    PublicIdentityKeyToPublicSigningKey[string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE)] = requestingMachinePublicSigningKey;

    char* receivingMachinePrivateID = (char*)get<1>(MachinePIDToIdentityDictionary[USMPublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)]]).c_str();
    char* decryptedMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
    enclave_decryptMessageInteralPrivateKeyEcall(global_app_eid ,encryptedNewSessionKey, SGX_RSA3072_KEY_SIZE, receivingMachinePrivateID, decryptedMessage, SGX_RSA3072_KEY_SIZE);
    printPayload(encryptedNewSessionKey, SGX_RSA3072_KEY_SIZE);

    int count;
    count = PublicIdentityKeyToChildSessionKey.count(make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE)));
    
    if (count == 0) {
        PublicIdentityKeyToChildSessionKey[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE))] = string(decryptedMessage, SIZE_OF_REAL_SESSION_KEY);
        ChildSessionKeyToNonce[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(decryptedMessage, SIZE_OF_REAL_SESSION_KEY))] = 0;
        char* successMessage = createStringLiteralMalloced("Success: Session Key Received");
        ocall_print("Received correct session key!\n");
        return successMessage;
    } else {
        char* errorMsg = createStringLiteralMalloced("Already created!");
        ocall_print("ERROR:Session has already been initalized in the past!\n");
        return errorMsg;
    }
    
}

// USM send message API [other SM is trying to send a message through an encrypted channel to USM hosted by this distributed host]
char* USMSendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response) {
    decryptAndSendInternalMessageHelper(requestingMachineIDKey, receivingMachineIDKey, iv, mac, encryptedMessage, response, false);
}

//*******************


//USM P Foreign Functions*******************

// Method for USM to send "Untrusted Create" request across the network
extern "C" PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    return P_UntrustedCreateRequest_IMPL(context, argRefs);
}

// Method for USM to send "Untrusted Create" request across the network
extern "C" PRT_VALUE* P_UntrustedCreateRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) 
{
    return sendCreateMachineNetworkRequest(context, argRefs, "UntrustedCreate", false);
}

// Method for USM to send "Untrusted Send" request across the network
extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) 
{   
    sendSendNetworkRequest(context, argRefs, "UntrustedSend", false, false);
}

//Needs to be empty for compilation with Helper.cpp
extern "C" PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
    // //USMs can only make untrusted requests to create machines
    // return P_UntrustedCreateRequest_IMPL(context, argRefs);
}

//Needs to be empty for compilation with Helper.cpp
extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

}

//Needs to be empty for compilation with Helper.cpp
extern "C" PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

}

//*******************


//USM Other Functions*******************

//Handle incoming network messages
char* receiveNetworkRequest(char* request, size_t requestSize) {
    return receiveNetworkRequestHelper(request, requestSize, false);
}

//Generate public/private identity encryption and signing keys
void generateIdentity(string& publicID, string& privateID, string prefix, string& publicIDSigningKey, string& privateIDSigningKey) {
    if (!NETWORK_DEBUG) {
        char* private_identity_key_raw = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        char* public_identity_key_raw = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        char* private_identity_key = (char*) malloc(sizeof(sgx_rsa3072_key_t));
        char* public_identity_key = (char*) malloc(sizeof(sgx_rsa3072_public_key_t));
        sgx_status_t status = enclave_createRsaKeyPairEcall(global_app_eid, public_identity_key_raw, private_identity_key_raw, public_identity_key, private_identity_key, SGX_RSA3072_KEY_SIZE); 
        if (status != SGX_SUCCESS) {
            ocall_print("APP Error in generating identity keys!");
        }
        publicID = string(public_identity_key_raw, SGX_RSA3072_KEY_SIZE);
        privateID = string(private_identity_key_raw, SGX_RSA3072_KEY_SIZE);
        publicIDSigningKey = string(public_identity_key, sizeof(sgx_rsa3072_public_key_t));
        privateIDSigningKey = string(private_identity_key, sizeof(sgx_rsa3072_key_t));
        ocall_print("APP: Generated following raw public key");
        printPayload(public_identity_key_raw, SGX_RSA3072_KEY_SIZE);
        ocall_print("APP: Generated following public key");
        printPayload(public_identity_key, sizeof(sgx_rsa3072_public_key_t));
    } else {
        //if debug mode, output a fixed identity
        uint32_t randNum = rand() % 100;
        randNum = (randNum + 10) % 100;
        if (randNum < 10) {
            randNum = 39;
        }
        publicID = prefix.substr(0, 1) + "UPub" + to_string(randNum) + "ddQMiiDh5wwA4zFBV3VOazgxZ3d3gnD40rQ2g6yrR8MDFdbJUGhm3ozq2hkYZdF0lWOc0EXBlE8bwwlL6VYoQYLAobQMRIqtS5Ytst1zrhq9YiubRypiP6xNS9UcS9dSBryXmdKAAcpke4ri2Ikx4tDUh1TbHr76WCqmOuwXMA9DqphJEdwIPjiOMr3pwYWt12dfVyFEGL5KcVeYajwgCTiQEmbZ7v5eZfZaBf95Ezh2cxPiI4Z1HfjBGmtYuO1aCdV8yKX0bZRNip3Ycmh8LkIhjHTtF3kchbFRVmhz0zdIOHG0HNSuI8x6ga0vSvSReI7hlrEPfrmm6rEVLPQcwtNAgNdMYQtK1qv4igoOErnwFaWMSqKLkkvAF";
        privateID = prefix.substr(0, 1) + "UPri" + to_string(randNum) + "ddQMiiDh5wwA4zFBV3VOazgxZ3d3gnD40rQ2g6yrR8MDFdbJUGhm3ozq2hkYZdF0lWOc0EXBlE8bwwlL6VYoQYLAobQMRIqtS5Ytst1zrhq9YiubRypiP6xNS9UcS9dSBryXmdKAAcpke4ri2Ikx4tDUh1TbHr76WCqmOuwXMA9DqphJEdwIPjiOMr3pwYWt12dfVyFEGL5KcVeYajwgCTiQEmbZ7v5eZfZaBf95Ezh2cxPiI4Z1HfjBGmtYuO1aCdV8yKX0bZRNip3Ycmh8LkIhjHTtF3kchbFRVmhz0zdIOHG0HNSuI8x6ga0vSvSReI7hlrEPfrmm6rEVLPQcwtNAgNdMYQtK1qv4igoOErnwFaWMSqKLkkvAF";

    }
} 

char* get_measurement(sgx_enclave_id_t eid) {
    //get enclave_hash value
    sgx_target_info_t qe_info;
    sgx_epid_group_id_t p_gid;
    sgx_report_t report;
    sgx_spid_t spid;
    int ret;
    sgx_status_t ecall_ret;

    sgx_init_quote(&qe_info, &p_gid);
    memset(qe_info.reserved1, 0, sizeof qe_info.reserved1);
    memset(qe_info.reserved2, 0, sizeof qe_info.reserved2);
    ecall_ret = enclave_ecall_create_report(eid, &ret, &qe_info, &report);
    if (ecall_ret != SGX_SUCCESS || ret) {
        printf("ecall_create_report: ecall_ret=%x, ret=%x", ecall_ret, ret);
    }

    memset(spid.id, 0x88, sizeof spid.id);
    uint32_t quote_size;
    sgx_get_quote_size(NULL, &quote_size);
    sgx_quote_t *quote = reinterpret_cast<sgx_quote_t *>(malloc(quote_size));
    ecall_ret = sgx_get_quote(&report, SGX_LINKABLE_SIGNATURE, &spid, NULL, NULL,
                                0, NULL, quote, quote_size);
    if (ecall_ret != SGX_SUCCESS) {
        print_error_message((sgx_status_t)ret);
    }

    char* enclave_hash = (char*) malloc(100);
    char* ptr = enclave_hash;

    int i;
    for(i=0;i<32;i++)
    {
        sprintf(ptr, "%02x",report.body.mr_enclave.m[i]);
        ptr += 2;
    }
    ptr[i] = '\0';
    return enclave_hash;
}

//*******************

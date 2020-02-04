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
    return sendCreateMachineNetworkRequest(context, argRefs, "Create", true);
}

extern "C" PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    return P_UntrustedCreateCoordinator_IMPL(context, argRefs);
}

extern "C" PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    sendSendNetworkRequest(context, argRefs, "Send", true, true);
}

//Responsibility of caller to free return
char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey) {
    // ocall_print("IF THIS WORKS THEN WOO BOY");
    int ret;
    char* other_machine_name = "KPS";
    char* requestString;
    int requestStringSize;
    char* concatStrings[] = {currentMachinePublicIDKey, ":", childPublicIDKey};
    int concatLengths[] = {SGX_RSA3072_KEY_SIZE, 1, SGX_RSA3072_KEY_SIZE};
    requestString = concatMutipleStringsWithLength(concatStrings, concatLengths, 3);
    requestStringSize = returnTotalSizeofLengthArray(concatLengths, 3) + 1;
      
    ocall_pong_enclave_attestation_in_thread(&ret, current_eid, (char*)other_machine_name, SGX_RSA3072_KEY_SIZE, RETRIEVE_CAPABLITY_KEY_CONSTANT, requestString, requestStringSize);
    safe_free(requestString);
    char* capabilityKeyPayload = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKeyPayload, g_secret, SIZE_OF_CAPABILITYKEY);
    // ocall_print("WORKS");
    return capabilityKeyPayload;
}
                                        
void UntrustedCreateMachineAPI(sgx_enclave_id_t currentEid, char* machineTypeToCreate, int lengthString, char* returnNewMachinePublicID, int numArgs, int payloadType, char* payloadString, int payloadSize, int ID_SIZE, int PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    current_eid = currentEid;
    char* newMachinePublicIDKey = createMachineHelper(machineTypeToCreate, "", numArgs, payloadType, payloadString, payloadSize, false, enclaveEid);
    //"Return" the publicIDKey of the new machine
    // if (NETWORK_DEBUG) {
    //     memcpy(returnNewMachinePublicID, newMachinePublicIDKey, strlen(newMachinePublicIDKey) + 1);
    // } else {
        memcpy(returnNewMachinePublicID, newMachinePublicIDKey, SGX_RSA3072_KEY_SIZE);
    // }
    safe_free(newMachinePublicIDKey);
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


// Responsibility of caller to free return
char* createMachineHelper(char* machineType, char* parentTrustedMachinePublicIDKey, int numArgs, int payloadType, char* payload, int payloadSize, bool isSecureCreate, sgx_enclave_id_t enclaveEid) {
    startPrtProcessIfNotStarted();

    if (!machineTypeIsSecure(machineType)) {
        return "Error: Tried to Create USM inside enclave!";
    }
    
    //TODO Do we need to verify signature of parentTrustedMachinePublicIDKey?
    string machineTypeToCreateString = createString(machineType);
    string secureChildPublicIDKey;
    string secureChildPrivateIDKey;
    // if (NETWORK_DEBUG) {
    //     generateIdentityDebug(secureChildPublicIDKey, secureChildPrivateIDKey, machineTypeToCreateString);
    // } else {
        // sgx_rsa3072_key_t *private_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t)); //TODO shivfree need to free this and below
        // sgx_rsa3072_public_key_t *public_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
        // void* publicIdentity = NULL;
        // void* privateIdentity = NULL;
        // generateIdentity(public_key, private_key, &publicIdentity, &privateIdentity);
        // secureChildPublicIDKey = string((char*)publicIdentity, SGX_RSA3072_KEY_SIZE);
        // secureChildPrivateIDKey = string((char*)privateIdentity, SGUntrustedCreateX_RSA3072_KEY_SIZE);
        //TODO uncomment above
    if (NETWORK_DEBUG) {
        generateIdentityDebug(secureChildPublicIDKey, secureChildPrivateIDKey, machineTypeToCreateString);
    } else {
        sgx_rsa3072_key_t *private_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t)); //TODO shivfree need to free this and below
        sgx_rsa3072_public_key_t *public_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
        void* publicIdentity = NULL;
        void* privateIdentity = NULL;
        generateIdentity(public_key, private_key, &publicIdentity, &privateIdentity);
        secureChildPublicIDKey = string((char*)publicIdentity, SGX_RSA3072_KEY_SIZE);
        secureChildPrivateIDKey = string((char*)privateIdentity, SGX_RSA3072_KEY_SIZE);
    }
        

    // }   
    char* publicIdKeyCopy = (char*) malloc(secureChildPublicIDKey.length() + 1);
    memcpy(publicIdKeyCopy, (char*)secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    publicIdKeyCopy[secureChildPublicIDKey.length()] = '\0';
    
    // if (NETWORK_DEBUG) {
    //     ocall_add_identity_to_eid_dictionary((char*)publicIdKeyCopy, SIZE_OF_IDENTITY_STRING, enclaveEid);
    // } else {
        ocall_add_identity_to_eid_dictionary((char*)publicIdKeyCopy, SGX_RSA3072_KEY_SIZE, enclaveEid);
    // }
    
    safe_free(publicIdKeyCopy);
    int newMachinePID = getNextPID(); 
    //Store new machine information in enclave's dictionaries
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(secureChildPublicIDKey, secureChildPrivateIDKey);
    PublicIdentityKeyToMachinePIDDictionary[secureChildPublicIDKey] = newMachinePID;

    // if (isSecureCreate) {
        //Contacting KPS for capability key
        char* capabilityKeyPayloadReceived;
        if (isSecureCreate) {
           capabilityKeyPayloadReceived = receiveNewCapabilityKeyFromKPS(parentTrustedMachinePublicIDKey ,(char*)secureChildPublicIDKey.c_str());
        } else {
            capabilityKeyPayloadReceived = receiveNewCapabilityKeyFromKPS((char*)secureChildPublicIDKey.c_str() ,(char*)secureChildPublicIDKey.c_str());
        } 
        ocall_print("Enclave received new capability Key from KPS: ");
        char* publicCapabilityKey = retrievePublicCapabilityKey(capabilityKeyPayloadReceived);
        char* privateCapabilityKey = retrievePrivateCapabilityKey(capabilityKeyPayloadReceived);
        // printRSAKey(publicCapabilityKey);
        // printRSAKey(privateCapabilityKey);
        MachinePIDtoCapabilityKeyDictionary[newMachinePID] = string(capabilityKeyPayloadReceived, SIZE_OF_CAPABILITYKEY);
        PMachineToChildCapabilityKey[make_tuple(newMachinePID, string(secureChildPublicIDKey.c_str(), SGX_RSA3072_KEY_SIZE))] = string(capabilityKeyPayloadReceived, SIZE_OF_CAPABILITYKEY);
        safe_free(publicCapabilityKey);
        safe_free(privateCapabilityKey);
        safe_free(capabilityKeyPayloadReceived);
    // }

    char* secureChildPublicIDKeyCopy = (char*) malloc(secureChildPublicIDKey.size() + 1);
    memcpy(secureChildPublicIDKeyCopy, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    secureChildPublicIDKeyCopy[secureChildPublicIDKey.length()] = '\0';
    registerMachineWithNetwork(secureChildPublicIDKeyCopy);
    safe_free(secureChildPublicIDKeyCopy);

    if (isSecureCreate) {
        createMachine(machineType, numArgs, payloadType, payload, payloadSize);

    } else {
        createMachine(machineType, 0, PRT_VALUE_KIND_INT, "", 0);
    }

    char* returnNewMachinePublicIDKey = (char*) malloc(secureChildPublicIDKey.length() + 1);
    memcpy(returnNewMachinePublicIDKey, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    returnNewMachinePublicIDKey[secureChildPublicIDKey.length()] = '\0';
    return returnNewMachinePublicIDKey;

}


int createMachineAPI(sgx_enclave_id_t currentEid, char* machineType, char* parentTrustedMachinePublicIDKey, char* returnNewMachinePublicIDKey, int numArgs, int payloadType, char* payload, int payloadSize, uint32_t ID_SIZE, uint32_t PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    current_eid = currentEid;
   
    if (!NETWORK_DEBUG) {
         ocall_print("we at create machine api level now");
        ocall_print("printing parentTrustedMachinePublicKey");
        printRSAKey(parentTrustedMachinePublicIDKey);
    }
    
    char* newMachinePublicIDKey = createMachineHelper(machineType, parentTrustedMachinePublicIDKey, numArgs, payloadType, payload, payloadSize, true, enclaveEid);
    //"Return" the publicIDKey of the new machine
    // if (NETWORK_DEBUG){
    //     memcpy(returnNewMachinePublicIDKey, newMachinePublicIDKey, strlen(newMachinePublicIDKey) + 1);
    // } else {
        memcpy(returnNewMachinePublicIDKey, newMachinePublicIDKey, SGX_RSA3072_KEY_SIZE);
    // }
    safe_free(newMachinePublicIDKey);
}

//Responbility of caller to free return
char* receiveNewCapabilityKeyFromKPS(char* parentTrustedMachineID, char* newMachinePublicIDKey) {
    int ret;
    char* other_machine_name = "KPS";
    char* requestString;
    int requestStringSize;
    // if (NETWORK_DEBUG) {    
    //     int requestSize = SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_IDENTITY_STRING + 1;
    //     requestString = (char*) malloc(requestSize);
    //     requestStringSize = requestSize;
    //     snprintf(requestString, requestSize, "%s:%s", newMachinePublicIDKey, parentTrustedMachineID);
    // } else {

        char* concatStrings[] = {newMachinePublicIDKey, ":", parentTrustedMachineID};
        int concatLengths[] = {SGX_RSA3072_KEY_SIZE, 1, SGX_RSA3072_KEY_SIZE};
        requestString = concatMutipleStringsWithLength(concatStrings, concatLengths, 3);
        requestStringSize = returnTotalSizeofLengthArray(concatLengths, 3) + 1;
    // }
    ocall_print("Enclave is asking for creation of new cap key using");
    printRSAKey(newMachinePublicIDKey);
    printRSAKey(parentTrustedMachineID);
    // ocall_print("last one should be same as");
    // printRSAKey(requestString + SGX_RSA3072_KEY_SIZE + 1);
    ocall_pong_enclave_attestation_in_thread(&ret, current_eid, (char*)other_machine_name, SGX_RSA3072_KEY_SIZE, CREATE_CAPABILITY_KEY_CONSTANT, requestString, requestStringSize);
    safe_free(requestString);
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
    char* requestType = "RegisterMachine:";
    char* colon = ":";
    char* concatStrings[] = {requestType, newMachineID, colon, num};
    int concatLenghts[] = {strlen(requestType), SGX_RSA3072_KEY_SIZE, strlen(colon), strlen(num)};
    char* networkRequest = concatMutipleStringsWithLength(concatStrings, concatLenghts, 4);
    int networkRequestSize = returnTotalSizeofLengthArray(concatLenghts, 4) + 1; // +1 for null terminated byte
    ocall_network_request(&ret_value, networkRequest, networkResult, networkRequestSize, 100);
    safe_free(networkRequest);
    safe_free(num);
    safe_free(networkResult);

}

void createRsaKeyPairEcall(char* public_key_raw_out, char* private_key_raw_out, char* public_key_out, char* private_key_out, uint32_t KEY_SIZE) {
    sgx_rsa3072_key_t *private_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    sgx_rsa3072_public_key_t *public_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    void* private_key_raw = NULL;
    void* public_key_raw = NULL;
    createRsaKeyPair(public_key, private_key, &public_key_raw, &private_key_raw);
    memcpy(public_key_raw_out, public_key_raw, SGX_RSA3072_KEY_SIZE);
    memcpy(private_key_raw_out, private_key_raw, SGX_RSA3072_KEY_SIZE);
    memcpy(public_key_out, public_key, sizeof(sgx_rsa3072_public_key_t));
    memcpy(private_key_out, private_key, sizeof(sgx_rsa3072_key_t));
}

//Caller needs to allocate space for public_key and private_key
void createRsaKeyPair(sgx_rsa3072_public_key_t *public_key ,sgx_rsa3072_key_t *private_key, void** public_key_raw, void** private_key_raw) {
    int n_byte_size = SGX_RSA3072_KEY_SIZE;
    int e_byte_size = SGX_RSA3072_PUB_EXP_SIZE;
    unsigned char *p_n = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_d = (unsigned char *)malloc(SGX_RSA3072_PRI_EXP_SIZE);
    unsigned char p_e[] = {0x01, 0x00, 0x01, 0x00}; //65537
    unsigned char *p_p = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_q = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_dmp1 = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_dmq1 = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_iqmp = (unsigned char *)malloc(n_byte_size);
    

    sgx_status_t status = SGX_SUCCESS;
    status = sgx_create_rsa_key_pair(
        n_byte_size,
        e_byte_size,
        p_n,
        p_d,
        p_e,
        p_p,
        p_q,
        p_dmp1,
        p_dmq1,
        p_iqmp
    );
    if (status != SGX_SUCCESS) {
        ocall_print("Rsa Key Pair creation error!");
    } else {
        ocall_print("RSA Generated Succesfully!");
    }

    memcpy(private_key->mod, p_n, n_byte_size);
    memcpy(private_key->d, p_d, n_byte_size);
	memcpy(private_key->e, p_e, e_byte_size);

	memcpy(public_key->mod, p_n, n_byte_size);
	memcpy(public_key->exp, p_e, e_byte_size);

    status = sgx_create_rsa_pub1_key(
                       SGX_RSA3072_KEY_SIZE,
                       SGX_RSA3072_PUB_EXP_SIZE,
                       (const unsigned char*)public_key->mod,
                       (const unsigned char*)public_key->exp,
                       public_key_raw);
    if (status != SGX_SUCCESS) {
        ocall_print("Error in creating void** rsapubkey!");
        if (status == SGX_ERROR_INVALID_PARAMETER) {
            ocall_print("Invalid parameters");
        }
        if (status == SGX_ERROR_UNEXPECTED) {
            ocall_print("Unexpected error");
        }
    } else {
        ocall_print("Able to make void** rsapubkey!");
    }

    status = sgx_create_rsa_priv2_key(
                       SGX_RSA3072_KEY_SIZE,
                       SGX_RSA3072_PUB_EXP_SIZE,
                        p_e,
                        p_p,
                        p_q,
                        p_dmp1,
                        p_dmq1,
                        p_iqmp,
                       private_key_raw);
    if (status != SGX_SUCCESS) {
        ocall_print("Error in creating void** rsaprivkey!");
        if (status == SGX_ERROR_INVALID_PARAMETER) {
            ocall_print("Invalid parameters");
        }
        if (status == SGX_ERROR_UNEXPECTED) {
            ocall_print("Unexpected error");
        }
    } else {
        ocall_print("Able to make void** rsaprivkey!");
        // ocall_print((char*)*public_key_raw);
    }

    // ocall_print("Pub key is");
    // ocall_print((char*) *public_key_raw);

    free(p_n);
	free(p_d);
	free(p_p);
	free(p_q);
	free(p_dmp1);
	free(p_dmq1);
	free(p_iqmp);

}

bool receivePublicKeyPlainText() {

}

char* decryptMessageInteralPrivateKey(char* encryptedData, size_t encryptedDataSize, void* private_key) {

    size_t decrypted_data_length;
    char* decrypted_data = (char*) malloc(MAX_NETWORK_MESSAGE); //TODO note if message is bigger than this size, then we can run into issues

    sgx_status_t status = sgx_rsa_priv_decrypt_sha256(private_key, NULL, &decrypted_data_length, (unsigned char*) encryptedData, encryptedDataSize);

    status = sgx_rsa_priv_decrypt_sha256(private_key, (unsigned char*)decrypted_data, &decrypted_data_length, (unsigned char*) encryptedData, encryptedDataSize);

    if (status != SGX_SUCCESS) {
        ocall_print("Error in decrypting using private key!");
        // ocall_print((char*)**other_party_public_key_raw);
    } else {
        ocall_print("Able to decrytp using private key!");
    }
    // ocall_print_int(strlen(message) + 1);
    // ocall_print_int(encrypted_data_length);
    //decrypted_data[decrypted_data_length] = '\0';
    // ocall_print("Decrypted data is");
    // ocall_print(decrypted_data);
    return decrypted_data;
}

char* encryptMessageExternalPublicKey(char* message, size_t message_length_with_null_byte, void* other_party_public_key_raw, int& output_encrypted_message_length) {

    // ocall_print("Pub key received is");
    // ocall_print((char*) other_party_public_key_raw);

    size_t encrypted_data_length;
    char* encrypted_data = (char*) malloc(SGX_RSA3072_KEY_SIZE); //TODO note if message is bigger than this size, then we can run into issues
    
    sgx_status_t status = sgx_rsa_pub_encrypt_sha256(other_party_public_key_raw, NULL, &encrypted_data_length, (unsigned char*) message, message_length_with_null_byte);

    if (status != SGX_SUCCESS) {
        ocall_print("Error in encrypting using public key!");
        // ocall_print((char*)**other_party_public_key_raw);
        if (status == SGX_ERROR_UNEXPECTED) {
            ocall_print("unexpected error :(");
        } else if (status == SGX_ERROR_INVALID_PARAMETER) {
            ocall_print("invalid parameters");
        }
    } else {
        ocall_print("Encrypted data length will be");
        ocall_print_int(encrypted_data_length);
    }

    // encrypted_data_length = 384*2;

    status = sgx_rsa_pub_encrypt_sha256(other_party_public_key_raw, (unsigned char*) encrypted_data, &encrypted_data_length, (unsigned char*) message, message_length_with_null_byte);

    if (status != SGX_SUCCESS) {
        ocall_print("Error in encrypting using public key!");
        // ocall_print((char*)**other_party_public_key_raw);
        if (status == SGX_ERROR_UNEXPECTED) {
            ocall_print("unexpected error :(");
        } else if (status == SGX_ERROR_INVALID_PARAMETER) {
            ocall_print("invalid parameters");
        }
    } else {
        ocall_print("Able to encrypt using public key!");
    }
    // ocall_print_int(strlen(message) + 1);
    // ocall_print_int(encrypted_data_length);
    // encrypted_data[encrypted_data_length] = '\0';
    output_encrypted_message_length = encrypted_data_length;
    return encrypted_data;
}

bool verifySignature(char* message, int message_size, sgx_rsa3072_signature_t* signature, sgx_rsa3072_public_key_t* public_key) {

    uint8_t* p_data = (uint8_t*) message;
    uint32_t data_size = message_size;
    sgx_rsa_result_t p_result;


    sgx_status_t status = SGX_SUCCESS;
    status = sgx_rsa3072_verify(
        p_data,
        data_size,
        public_key,
        signature,
        &p_result
    );
    if (status != SGX_SUCCESS) {
        ocall_print("Error in verifying signature!");
    } else {
        ocall_print("Able to make call to sgx verify signature!");
    }
    if (p_result == SGX_RSA_INVALID_SIGNATURE) {
        return false;
    } else {
        return true;
    }
}

//Responsibilty of caller to free return
char* generateSessionKeyTest() {
    char* sessionKey = (char*) malloc(SIZE_OF_REAL_SESSION_KEY);
    sgx_read_rand((unsigned char*)sessionKey, SIZE_OF_REAL_SESSION_KEY);
    // sessionKey[98] = '!';
    // sessionKey[99] = '\0';
    // for (int i = 0; i < 99; i ++) {
    //     if (sessionKey[i] == '\0') {
    //         sessionKey[i] ='0';
    //     }
    // }
    return sessionKey;
}

//Responsibilty of caller to free return
char* concatVoid(void* str1, size_t str1_size, void* str2, size_t str2_size) {
    char* returnString = (char*) malloc(str1_size + str2_size + 1);
    memcpy(returnString, (char*)str1, str1_size);
    memcpy(returnString + str1_size , (char*)str2, str2_size);
    returnString[str1_size + str2_size + 1] = '\0';
    return returnString;
}

char* serializeEncryptedMessage(char* encryptedMessage) {
    for (int i = 0; i < SGX_RSA3072_KEY_SIZE; i ++) {
        if (encryptedMessage[i] == '\0') {
            encryptedMessage[i] ='0';
        } else if (encryptedMessage[i] == ':') {
            encryptedMessage[i] ='~';
        }
    }
}

char* checkRawRSAKeySize(char* key) {
    char* temp = (char*) malloc(SGX_RSA3072_KEY_SIZE);
    memcpy(temp, key, SGX_RSA3072_KEY_SIZE);
    return temp;
    // for (int i = 0; i < SGX_RSA3072_KEY_SIZE; i ++) {
    //     if (key[i] == '\0') {
    //         key[i] ='0';
    //     } else if (key[i] == ':') {
    //         key[i] ='~';
    //     }
    // }
    // key[SGX_RSA3072_KEY_SIZE] = '/0';
    // return key;
}

void printSessionKey(char* key) {
    //NOTE if modifying this method, modify it in kps.cpp also
    char* keyCopy = (char*) malloc(SIZE_OF_REAL_SESSION_KEY);
    memcpy(keyCopy, key, SIZE_OF_REAL_SESSION_KEY);
    ocall_print("session key:");
    char* temp = keyCopy;
    for (int i = 0; i < SIZE_OF_REAL_SESSION_KEY; i++) {
        if (temp[i] == '\0') {
            temp[i] = 'D';
        }
    }
    keyCopy[SIZE_OF_REAL_SESSION_KEY - 1] = '\0';
    
    ocall_print(keyCopy);
    safe_free(keyCopy);
}

//publicID and privateID must be allocated by the caller
void generateIdentityDebug(string& publicID, string& privateID, string prefix) {
    uint32_t val; 
    sgx_read_rand((unsigned char *) &val, 4);
    val = (val + 10) % 100;
    if (val < 10) {
        val = 29;
    }
    // publicID =  prefix + "SPub" + to_string(val % 100);
    // publicID = publicID + "qqqqqqqqqqqqqqqqqqqqqqqqqqqq";
    // privateID = prefix + "SPriv" + to_string(val % 100);
    // privateID = privateID + "qqqqqqqqqqqqqqqqqqqqqqqqqqqq";
        publicID = prefix.substr(0, 1) + "SPub" + to_string(val % 100) + "ddQMiiDh5wwA4zFBV3VOazgxZ3d3gnD40rQ2g6yrR8MDFdbJUGhm3ozq2hkYZdF0lWOc0EXBlE8bwwlL6VYoQYLAobQMRIqtS5Ytst1zrhq9YiubRypiP6xNS9UcS9dSBryXmdKAAcpke4ri2Ikx4tDUh1TbHr76WCqmOuwXMA9DqphJEdwIPjiOMr3pwYWt12dfVyFEGL5KcVeYajwgCTiQEmbZ7v5eZfZaBf95Ezh2cxPiI4Z1HfjBGmtYuO1aCdV8yKX0bZRNip3Ycmh8LkIhjHTtF3kchbFRVmhz0zdIOHG0HNSuI8x6ga0vSvSReI7hlrEPfrmm6rEVLPQcwtNAgNdMYQtK1qv4igoOErnwFaWMSqKLkkvAF";
        privateID = prefix.substr(0, 1) + "SPri" + to_string(val % 100) + "ddQMiiDh5wwA4zFBV3VOazgxZ3d3gnD40rQ2g6yrR8MDFdbJUGhm3ozq2hkYZdF0lWOc0EXBlE8bwwlL6VYoQYLAobQMRIqtS5Ytst1zrhq9YiubRypiP6xNS9UcS9dSBryXmdKAAcpke4ri2Ikx4tDUh1TbHr76WCqmOuwXMA9DqphJEdwIPjiOMr3pwYWt12dfVyFEGL5KcVeYajwgCTiQEmbZ7v5eZfZaBf95Ezh2cxPiI4Z1HfjBGmtYuO1aCdV8yKX0bZRNip3Ycmh8LkIhjHTtF3kchbFRVmhz0zdIOHG0HNSuI8x6ga0vSvSReI7hlrEPfrmm6rEVLPQcwtNAgNdMYQtK1qv4igoOErnwFaWMSqKLkkvAF";


    // sgx_rsa3072_key_t *private_capabilityB_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    // sgx_rsa3072_public_key_t *public_capabilityB_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    // void* private_capabilityB_key_raw = NULL;
    // void* public_capabilityB_key_raw = NULL;
    // createRsaKeyPair(public_capabilityB_key, private_capabilityB_key, &public_capabilityB_key_raw, &private_capabilityB_key_raw);
    // ocall_print("capability key is");
    // printRSAKey((char*)public_capabilityB_key_raw);
    // printRSAKey((char*)private_capabilityB_key_raw);

    // sgx_rsa3072_key_t *private_B_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    // sgx_rsa3072_public_key_t *public_B_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    // void* private_B_key_raw = NULL;
    // void* public_B_key_raw = NULL;
    // createRsaKeyPair(public_B_key, private_B_key, &public_B_key_raw, &private_B_key_raw);

    // sgx_rsa3072_key_t *private_A_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    // sgx_rsa3072_public_key_t *public_A_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    // void* private_A_key_raw = NULL;
    // void* public_A_key_raw = NULL;
    // createRsaKeyPair(public_A_key, private_A_key, &public_A_key_raw, &private_A_key_raw);


    // char* secureMessage = "Encrypted Hello!";

    // sgx_rsa3072_signature_t* signatureSecureMessage = signStringMessage(secureMessage, strlen(secureMessage) + 1, private_capabilityB_key);

    // char* sigPrefix = "SIG:";

    // char* temp = concatVoid(secureMessage, strlen(secureMessage), sigPrefix, strlen(sigPrefix));

    // // ocall_print("temp is");
    // // ocall_print(temp);

    // // char* concatMessageWithSig = concatVoid(temp, strlen(temp), signatureSecureMessage, SGX_RSA3072_KEY_SIZE);
    // // ocall_print("Concated message is");
    // // ocall_print(concatMessageWithSig);

    // free(temp);

    // if (verifySignature(secureMessage, strlen(secureMessage) + 1, signatureSecureMessage, public_capabilityB_key)) {
    //     ocall_print("Verifying Signature works!!!!");
    // } else {
    //     ocall_print("Verification Failed!");
    // }
    
    // int encryptedMessageSize;
    // char* encryptedMessage = encryptMessageExternalPublicKey(secureMessage, strlen(secureMessage) + 1, public_B_key_raw, encryptedMessageSize);
    // ocall_print("Encrypted Message is");
    // ocall_print(encryptedMessage);

    // char* decryptedMessage = decryptMessageInteralPrivateKey(encryptedMessage, SGX_RSA3072_KEY_SIZE, private_B_key_raw);
    // ocall_print("Decrypted Message is");
    // ocall_print(decryptedMessage);



    // /////

    // // char* sessionKey = generateSessionKeyTest();
    // // ocall_print("Session Key is");
    // // ocall_print(sessionKey);

    // // char* serializedKey = checkRawRSAKeySize((char*)public_B_key_raw);

    // // ocall_print("THESE SHOULD BE THE SAME");
    // // printRSAKey(serializedKey);
    // // printRSAKey((char*)public_B_key_raw);

    // // int encryptedSessionKeyLength;
    // // char* encryptedSessionKey = encryptMessageExternalPublicKey(sessionKey, 100, serializedKey, encryptedSessionKeyLength);
    // // ocall_print("Encrypted Session Key is");
    // // ocall_print(encryptedSessionKey);

    // // char* network_message = concatVoid(sigPrefix, strlen(sigPrefix), encryptedSessionKey, encryptedSessionKeyLength);
    // // // ocall_print(network_message);
    // // char* reentrant = NULL;
    // // char* split = strtok_r(network_message, ":", &reentrant);
    // // split = network_message + strlen(split) + 1;
    // // ocall_print(split);


    // // // char* split = network_message + 5;// strtok(network_message, ":SIG:");

    // // // split = strtok(NULL, ":SIG:");

    // // decryptedMessage = decryptMessageInteralPrivateKey(split, encryptedSessionKeyLength, private_B_key_raw);
    // // ocall_print("Decrypted SessionKey is");
    // // ocall_print(decryptedMessage);


    // // //test generate identity
    // // // sgx_rsa3072_public_key_t *public_key = NULL;
    // // // sgx_rsa3072_key_t *private_key = NULL;
    // // sgx_rsa3072_key_t *private_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    // // sgx_rsa3072_public_key_t *public_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    // // void* publicIdentity = NULL;
    // // void* privateIdentity = NULL;
    // // generateIdentity(public_key, private_key, &publicIdentity, &privateIdentity);
    // // if (publicIdentity == NULL || public_key == NULL) {
    // //     ocall_print("Generate Identity doesnt' work");
    // // } else {
    // //     ocall_print("generate identity works!");
    // // }


    // //Init Comm Protocol Test
    // char* sessionKey = generateSessionKeyTest();
    // ocall_print("Initial Session Key is");
    // printSessionKey(sessionKey);

    // int encryptedSessionKeyLength;
    // char* encryptedSessionKey = encryptMessageExternalPublicKey(sessionKey, SIZE_OF_REAL_SESSION_KEY, public_A_key_raw, encryptedSessionKeyLength);
    // ocall_print("Encrypted Session key is");
    // printSessionKey(encryptedSessionKey);

    // char* decryptedSessionKey = decryptMessageInteralPrivateKey(encryptedSessionKey, SGX_RSA3072_KEY_SIZE, private_A_key_raw);
    // ocall_print("Decrypted Session key is");
    // printSessionKey(decryptedSessionKey);

    // char* key = (char*) malloc(SIZE_OF_REAL_SESSION_KEY);
    // memcpy(key, sessionKey, SIZE_OF_REAL_SESSION_KEY);

    // //Secure Send Protocol Test

    // //Machine A
    // char* iv = generateIV();
    // secureMessage = "TrustedEventPayload!";
    // int secureMessageSize = strlen(secureMessage);

    // /*sgx_rsa3072_signature_t* */ signatureSecureMessage = signStringMessage(secureMessage, strlen(secureMessage) + 1, private_capabilityB_key);
    // int sizeOfSignature = SGX_RSA3072_KEY_SIZE;
    // char* concatString[] = {secureMessage, (char*)signatureSecureMessage};
    // int concatLengths[] = {secureMessageSize, sizeOfSignature};
    // char* trustedPayload = concatMutipleStringsWithLength(concatString, concatLengths, 2);
    // int trustedPayloadLength = returnTotalSizeofLengthArray(concatLengths, 2) + 1;

    // sgx_aes_ctr_128bit_key_t g_region_key;
    // sgx_aes_gcm_128bit_tag_t g_mac;
    // memcpy(g_region_key, key, 16);

    // encryptedMessage = (char*) malloc(trustedPayloadLength);

    // sgx_status_t status = sgx_rijndael128GCM_encrypt(&g_region_key, (const uint8_t*) trustedPayload, trustedPayloadLength, (uint8_t*)encryptedMessage, (const uint8_t*) iv, SIZE_OF_IV, NULL, 0, &g_mac);
    // ocall_print("Encrypted Message is");
    // ocall_print(encryptedMessage);

    // //Machine B
    // decryptedMessage = (char*) malloc(trustedPayloadLength);
    // status = sgx_rijndael128GCM_decrypt(&g_region_key, (const uint8_t*) encryptedMessage, trustedPayloadLength, (uint8_t*)decryptedMessage, (const uint8_t*) iv, SIZE_OF_IV, NULL, 0, &g_mac);
    
    // sgx_rsa3072_signature_t* decryptedSignature = (sgx_rsa3072_signature_t*) malloc(SGX_RSA3072_KEY_SIZE);
    // char* decryptedTrustedEvent = (char*) malloc(secureMessageSize); //extract size of decrypted message by string parsing into decyrpted message for the size
    // memcpy(decryptedTrustedEvent, decryptedMessage, secureMessageSize);
    // memcpy(decryptedSignature, decryptedMessage + secureMessageSize, SGX_RSA3072_KEY_SIZE);
    // if (verifySignature(decryptedTrustedEvent, strlen(decryptedTrustedEvent) + 1, decryptedSignature, public_capabilityB_key)) {
    //     ocall_print("Verifying Signature works!!!!");
    // } else {
    //     ocall_print("Verification Failed!");
    // }

    // ocall_print("Decrypted Message is");
    // ocall_print(decryptedTrustedEvent);


} 

void decrypt_message_external(                 const sgx_aes_gcm_128bit_key_t *p_key,
                                                const uint8_t *p_src,
                                                uint32_t src_len,
                                                uint8_t *p_dst,
                                                const uint8_t *p_iv,
                                                uint32_t iv_len,
                                                
                                                const sgx_aes_gcm_128bit_tag_t *p_in_mac ) {

    sgx_rijndael128GCM_decrypt(p_key, p_src, src_len, p_dst, p_iv, iv_len, NULL, 0, p_in_mac);

}

void decryptMessageForUSM(char* requestingMachineIDKey, 
                            char* receivingMachineIDKey, 
                            char* iv, 
                            char* mac, 
                            char* encryptedMessage,
                            int machinePid,
                            char* sessionKeyy,
                            char* returnDecryptedMessage,
                            uint32_t IDENTITY_SIZE,
                            uint32_t ENCRYPTED_MESSAGE_SIZE,
                            uint32_t SESSION_KEY_SIZE) {
    ocall_print("entered decrypt fn for USM");
    printPayload(encryptedMessage, ENCRYPTED_MESSAGE_SIZE);
    // ocall_print_int(MAX_ENCRYPTED_MESSAGE);

        // int machinePID = PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)];
        // string sendingToMachineCapabilityKeyPayload = MachinePIDtoCapabilityKeyDictionary[machinePID];
        // char* publicCapabilityKeySendingToMachine = retrievePublicCapabilityKey((char*)sendingToMachineCapabilityKeyPayload.c_str());

        // string sessionKey = PublicIdentityKeyToChildSessionKey[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE))];
        int machinePID = machinePid;
        string sessionKey = string(sessionKeyy, SIZE_OF_SESSION_KEY);
        sgx_aes_ctr_128bit_key_t g_region_key;
        sgx_aes_gcm_128bit_tag_t g_mac;
        memcpy(g_region_key, (char*)sessionKey.c_str(), 16);
        memcpy(g_mac, mac, SIZE_OF_MAC);

        char* actualEncryptedMessage = encryptedMessage;
        sgx_status_t status = sgx_rijndael128GCM_decrypt(&g_region_key, (const uint8_t*) actualEncryptedMessage, ENCRYPTED_MESSAGE_SIZE, (uint8_t*)returnDecryptedMessage, (const uint8_t*) iv, SIZE_OF_IV, NULL, 0, &g_mac);
 
        char* checkMyPublicIdentity = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        memcpy(checkMyPublicIdentity, returnDecryptedMessage, SGX_RSA3072_KEY_SIZE);
        if (string(checkMyPublicIdentity, SGX_RSA3072_KEY_SIZE) != string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)) {
            ocall_print("ERROR: Checking Public Identity Key inside Message FAILED in Untrusted Send");
            // return 0;
        }

        sgx_rsa3072_signature_t* decryptedSignature = (sgx_rsa3072_signature_t*) malloc(SGX_RSA3072_KEY_SIZE);
        // char* message = (char*) malloc(atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1); 
        // memcpy(message, decryptedMessage + SGX_RSA3072_KEY_SIZE + 1, atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1);
        char* messageSignedOver = (char*) malloc(ENCRYPTED_MESSAGE_SIZE - SGX_RSA3072_KEY_SIZE - 1);
        memcpy(messageSignedOver, returnDecryptedMessage, ENCRYPTED_MESSAGE_SIZE - SGX_RSA3072_KEY_SIZE - 1);
        memcpy(decryptedSignature, returnDecryptedMessage + ENCRYPTED_MESSAGE_SIZE - SGX_RSA3072_KEY_SIZE, SGX_RSA3072_KEY_SIZE);
        // // ocall_print("Lenght of encrypted message is ");
        // // ocall_print(encryptedMessageSize);
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


}

void generateIdentity(sgx_rsa3072_public_key_t *public_key, sgx_rsa3072_key_t *private_key, void** publicIdentity, void** privateIdentity) {
    // sgx_rsa3072_key_t *sk = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    // sgx_rsa3072_public_key_t *pk = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    void* sk_raw = NULL;
    void* pk_raw = NULL;
    createRsaKeyPair(public_key, private_key, publicIdentity, privateIdentity);
    // public_key = pk;
    // private_key = sk;
    // publicIdentity = (char*)pk_raw;
    // privateIdentity = (char*)sk_raw;

}


int initializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* newSessionKey, char* returnMessage, uint32_t ID_SIZE, uint32_t SESSION_KEY_SIZE) {
    ocall_print("Initialize Communication API Called!");

    int count;
    count = PublicIdentityKeyToChildSessionKey.count(make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE)));
    
    if (count == 0) {
        PublicIdentityKeyToChildSessionKey[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE))] = string(newSessionKey, SIZE_OF_REAL_SESSION_KEY);
        char* successMessage = "Success: Session Key Received!";
        ocall_print(successMessage);
        printSessionKey(newSessionKey);
        memcpy(returnMessage, successMessage, strlen(successMessage) + 1);
        ocall_print("Returning correct session key!");
        return 0;
    } else {
        char* errorMsg = "Error: Already created session!";
        memcpy(returnMessage, errorMsg, strlen(errorMsg) + 1); 
        ocall_print("ERROR:Session has already been initalized in the past!");
        return 1;
    }
    
}

int sendMessageHelper(char* requestingMachineIDKey, char* receivingMachineIDKey, char* event, int numArgs, int payloadType, char* payload, int payloadSize) {
    //TODO if modifying this, modify USMsendMessageAPI in app.cpp
    //TODO eventNum should be encrypted and requestingMachineIDKey should be verified with signature
    PRT_MACHINEID receivingMachinePID;
    ocall_print("SecureChildMachine has a PID of:");
    char* temp = (char*) malloc(10);
    // if (NETWORK_DEBUG) {
    //     if (PublicIdentityKeyToMachinePIDDictionary.count(string(receivingMachineIDKey)) == 0) {
    //         ocall_print("Key not found");
    //     }
    //     snprintf(temp, 5, "%d", PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)]);
    //     ocall_print(temp);
    //     safe_free(temp);
    //     receivingMachinePID.machineId = PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)];
    // } else {
        if (PublicIdentityKeyToMachinePIDDictionary.count(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)) == 0) {
            ocall_print("Key not found");
        }
        snprintf(temp, 5, "%d", PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)]);
        ocall_print(temp);
        safe_free(temp);
        receivingMachinePID.machineId = PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)];
    // }
    
    handle_incoming_event(atoi(event), receivingMachinePID, numArgs, payloadType, payload, payloadSize); //TODO update to untrusted send api
}

int decryptAndSendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, uint32_t ID_SIZE, uint32_t MAX_ENCRYPTED_MESSAGE) {
    ocall_print("entered decrypt fn");
    ocall_print_int(MAX_ENCRYPTED_MESSAGE);
    printPayload(encryptedMessage, 9);
    char* split = strtok(encryptedMessage, ":");
    char* encryptedMessageSize = split;
    char* eventNum;
    int numArgs;
    int payloadType;
    char* payload;
    int payloadSize;
    char* next = NULL;

    char* decryptedMessage = NULL;

    if (!NETWORK_DEBUG) {
        int machinePID = PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)];
        string sendingToMachineCapabilityKeyPayload = MachinePIDtoCapabilityKeyDictionary[machinePID];
        char* publicCapabilityKeySendingToMachine = retrievePublicCapabilityKey((char*)sendingToMachineCapabilityKeyPayload.c_str());

        string sessionKey = PublicIdentityKeyToChildSessionKey[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE))];

        sgx_aes_ctr_128bit_key_t g_region_key;
        sgx_aes_gcm_128bit_tag_t g_mac;
        memcpy(g_region_key, (char*)sessionKey.c_str(), 16);
        memcpy(g_mac, mac, SIZE_OF_MAC);

        char* actualEncryptedMessage = encryptedMessage + strlen(encryptedMessageSize) + 1;
        decryptedMessage = (char*) malloc(atoi(encryptedMessageSize));
        sgx_status_t status = sgx_rijndael128GCM_decrypt(&g_region_key, (const uint8_t*) actualEncryptedMessage, atoi(encryptedMessageSize), (uint8_t*)decryptedMessage, (const uint8_t*) iv, SIZE_OF_IV, NULL, 0, &g_mac);
 
        char* checkMyPublicIdentity = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        memcpy(checkMyPublicIdentity, decryptedMessage, SGX_RSA3072_KEY_SIZE);
        if (string(checkMyPublicIdentity, SGX_RSA3072_KEY_SIZE) != string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)) {
            ocall_print("ERROR: Checking Public Identity Key inside Message FAILED in Secure Send");
            return 0;
        }

        sgx_rsa3072_signature_t* decryptedSignature = (sgx_rsa3072_signature_t*) malloc(SGX_RSA3072_KEY_SIZE);
        // char* message = (char*) malloc(atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1); 
        // memcpy(message, decryptedMessage + SGX_RSA3072_KEY_SIZE + 1, atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1);
        char* messageSignedOver = (char*) malloc(atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1);
        memcpy(messageSignedOver, decryptedMessage, atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1);
        memcpy(decryptedSignature, decryptedMessage + atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE, SGX_RSA3072_KEY_SIZE);
        // ocall_print("Lenght of encrypted message is ");
        // ocall_print(encryptedMessageSize);
        ocall_print("Received Signature:");
        printRSAKey((char*)decryptedSignature);
        ocall_print("Signature is over message");
        printRSAKey(messageSignedOver);
        ocall_print_int(atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1);
        ocall_print("Key needed to verify signature is");
        ocall_print((char*)sendingToMachineCapabilityKeyPayload.c_str());
        ocall_print("actual key is");
        printPublicCapabilityKey(publicCapabilityKeySendingToMachine);
        // printPrivateCapabilityKey(retrievePrivateCapabilityKey((char*)sendingToMachineCapabilityKeyPayload.c_str()));

        if (verifySignature(messageSignedOver, atoi(encryptedMessageSize) - SGX_RSA3072_KEY_SIZE - 1, decryptedSignature, (sgx_rsa3072_public_key_t*)publicCapabilityKeySendingToMachine)) {
            ocall_print("Verifying Signature works!!!!");
        } else {
            ocall_print("Error: Secure Send Signature Verification Failed!");
            // return 0;
        }

        safe_free(checkMyPublicIdentity);
        char* message = (char*) malloc(atoi(encryptedMessageSize)); 
        memcpy(message, decryptedMessage + SGX_RSA3072_KEY_SIZE + 1, atoi(encryptedMessageSize));
        next = message;

    }

    split = strtok(next, ":");
    eventNum = split;
    split = strtok(NULL, ":");
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
        split = strtok(NULL, ":");
        payloadType = atoi(split);
        split = strtok(NULL, ":");
        payloadSize = atoi(split);
        safe_free(payload);
        payload = split + strlen(split) + 1;

    } else {
        safe_free(payload);
    }
    
    sendMessageAPI(requestingMachineIDKey, receivingMachineIDKey, eventNum, numArgs, payloadType, payload, payloadSize);
    safe_free(decryptedMessage);

}

int sendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* event, int numArgs, int payloadType, char* payload, int payloadSize) {
    sendMessageHelper(requestingMachineIDKey, receivingMachineIDKey, event, numArgs, payloadType, payload, payloadSize);
}

int sendUntrustedMessageAPI(char* receivingMachineIDKey, char* eventNum, int numArgs, int payloadType, char* payload, int payloadSize, uint32_t ID_SIZE, uint32_t MAX_EVENT_SIZE, uint32_t MAX_PAYLOAD_SIZE) {
    sendMessageHelper("", receivingMachineIDKey, eventNum, numArgs, payloadType, payload, payloadSize);
}

extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   return sendCreateMachineNetworkRequest(context, argRefs, "UntrustedCreate", false);
}


extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

    sendSendNetworkRequest(context, argRefs, "UntrustedSend", false, true);
   
}

extern "C" void P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   
}
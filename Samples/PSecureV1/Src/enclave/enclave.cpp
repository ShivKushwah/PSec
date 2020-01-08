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
    sendSendNetworkRequest(context, argRefs, "Send", true);
}

//Responsibility of caller to free return
char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey) {
    int ret;
    char* other_machine_name = "KPS";
    char* requestString;
    if (NETWORK_DEBUG) {
        int requestSize = SIZE_OF_IDENTITY_STRING + SIZE_OF_IDENTITY_STRING;
        requestString = (char*) malloc(requestSize);
        snprintf(requestString, requestSize, "%s:%s", currentMachinePublicIDKey, childPublicIDKey);  
    } else {
        char* concatStrings[] = {currentMachinePublicIDKey, ":", childPublicIDKey};
        int concatLengths[] = {SGX_RSA3072_KEY_SIZE, 1, SGX_RSA3072_KEY_SIZE};
        requestString = concatMutipleStringsWithLength(concatStrings, concatLengths, 3);
        // snprintf(requestString, requestSize, "%s:%s", currentMachinePublicIDKey, childPublicIDKey);  

    }
      
    ocall_pong_enclave_attestation_in_thread(&ret, current_eid, (char*)other_machine_name, SGX_RSA3072_KEY_SIZE, RETRIEVE_CAPABLITY_KEY_CONSTANT, requestString);
    safe_free(requestString);
    char* capabilityKey = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKey, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKey;
}
                                        
void UntrustedCreateMachineAPI(sgx_enclave_id_t currentEid, char* machineTypeToCreate, int lengthString, char* returnNewMachinePublicID, int numArgs, int payloadType, char* payloadString, int ID_SIZE, int PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    current_eid = currentEid;
    char* newMachinePublicIDKey = createMachineHelper(machineTypeToCreate, "", numArgs, payloadType, payloadString, false, enclaveEid);
    //"Return" the publicIDKey of the new machine
    if (NETWORK_DEBUG) {
        memcpy(returnNewMachinePublicID, newMachinePublicIDKey, strlen(newMachinePublicIDKey) + 1);
    } else {
        memcpy(returnNewMachinePublicID, newMachinePublicIDKey, SGX_RSA3072_KEY_SIZE);
    }
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
char* createMachineHelper(char* machineType, char* parentTrustedMachinePublicIDKey, int numArgs, int payloadType, char* payload, bool isSecureCreate, sgx_enclave_id_t enclaveEid) {
    startPrtProcessIfNotStarted();

    if (!machineTypeIsSecure(machineType)) {
        return "Error: Tried to Create USM inside enclave!";
    }
    
    //TODO Do we need to verify signature of parentTrustedMachinePublicIDKey?
    string machineTypeToCreateString = createString(machineType);
    string secureChildPublicIDKey;
    string secureChildPrivateIDKey;
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
    char* publicIdKeyCopy = (char*) malloc(secureChildPublicIDKey.length() + 1);
    memcpy(publicIdKeyCopy, (char*)secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    publicIdKeyCopy[secureChildPublicIDKey.length()] = '\0';

    ocall_add_identity_to_eid_dictionary((char*)publicIdKeyCopy, enclaveEid);
    safe_free(publicIdKeyCopy);
    int newMachinePID = getNextPID(); 
    //Store new machine information in enclave's dictionaries
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(secureChildPublicIDKey, secureChildPrivateIDKey);
    PublicIdentityKeyToMachinePIDDictionary[secureChildPublicIDKey] = newMachinePID;

    if (isSecureCreate) {
        //Contacting KPS for capability key
        char* capabilityKeyReceived = receiveNewCapabilityKeyFromKPS(parentTrustedMachinePublicIDKey ,(char*)secureChildPublicIDKey.c_str());
        ocall_print("Enclave received new capability Key from KPS: ");
        ocall_print(capabilityKeyReceived);
        MachinePIDtoCapabilityKeyDictionary[newMachinePID] = string(capabilityKeyReceived);
        safe_free(capabilityKeyReceived);
    }

    char* secureChildPublicIDKeyCopy = (char*) malloc(secureChildPublicIDKey.size() + 1);
    memcpy(secureChildPublicIDKeyCopy, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    secureChildPublicIDKeyCopy[secureChildPublicIDKey.length()] = '\0';
    registerMachineWithNetwork(secureChildPublicIDKeyCopy);
    safe_free(secureChildPublicIDKeyCopy);

    if (isSecureCreate) {
        createMachine(machineType, numArgs, payloadType, payload);

    } else {
        createMachine(machineType, 0, PRT_VALUE_KIND_INT, "");
    }

    char* returnNewMachinePublicIDKey = (char*) malloc(secureChildPublicIDKey.length() + 1);
    memcpy(returnNewMachinePublicIDKey, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    returnNewMachinePublicIDKey[secureChildPublicIDKey.length()] = '\0';
    return returnNewMachinePublicIDKey;

}


int createMachineAPI(sgx_enclave_id_t currentEid, char* machineType, char* parentTrustedMachinePublicIDKey, char* returnNewMachinePublicIDKey, int numArgs, int payloadType, char* payload, uint32_t ID_SIZE, uint32_t PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    current_eid = currentEid;
    char* newMachinePublicIDKey = createMachineHelper(machineType, parentTrustedMachinePublicIDKey, numArgs, payloadType, payload, true, enclaveEid);
    //"Return" the publicIDKey of the new machine
    if (NETWORK_DEBUG){
        memcpy(returnNewMachinePublicIDKey, newMachinePublicIDKey, strlen(newMachinePublicIDKey) + 1);
    } else {
        memcpy(returnNewMachinePublicIDKey, newMachinePublicIDKey, SGX_RSA3072_KEY_SIZE);
    }
    safe_free(newMachinePublicIDKey);
}

//Responbility of caller to free return
char* receiveNewCapabilityKeyFromKPS(char* parentTrustedMachineID, char* newMachinePublicIDKey) {
    int ret;
    char* other_machine_name = "KPS";
    char* requestString;
    if (NETWORK_DEBUG) {    
        int requestSize = SIZE_OF_IDENTITY_STRING + SIZE_OF_IDENTITY_STRING;
        requestString = (char*) malloc(requestSize);
        snprintf(requestString, requestSize, "%s:%s", newMachinePublicIDKey, parentTrustedMachineID);
    } else {
        int requestSize = SGX_RSA3072_KEY_SIZE + 1 + SGX_RSA3072_KEY_SIZE + 1;
        requestString = (char*) malloc(requestSize);
        memcpy(requestString, newMachinePublicIDKey, SGX_RSA3072_KEY_SIZE);
        memcpy(requestString + SGX_RSA3072_KEY_SIZE, ":", 1);
        memcpy(requestString + SGX_RSA3072_KEY_SIZE + 1, parentTrustedMachineID, SGX_RSA3072_KEY_SIZE);
    }
    ocall_pong_enclave_attestation_in_thread(&ret, current_eid, (char*)other_machine_name, SGX_RSA3072_KEY_SIZE, CREATE_CAPABILITY_KEY_CONSTANT, requestString);
    safe_free(requestString);
    char* capabilityKey = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKey, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKey;
    
}

char* registerMachineWithNetwork(char* newMachineID) {
    //TODO shiv next make this NETWORK DEBUG

    int ret_value;
    char* num = (char*) malloc(10);
    itoa(ENCLAVE_NUMBER, num, 10);
    char* machineKeyWrapper[] = {newMachineID, num};
    
    char* networkResult = (char*) malloc(100);
    if (NETWORK_DEBUG) {
        char* networkRequest = generateCStringFromFormat("RegisterMachine:%s:%s", machineKeyWrapper, 2);
        ocall_network_request(&ret_value, networkRequest, networkResult, 100);
        safe_free(networkRequest);
    } else {
        //TODO need to test this request
        char* requestType = "RegisterMachine:";
        char* temp = concatVoid(requestType, strlen(requestType), newMachineID, SGX_RSA3072_KEY_SIZE);
        char* colon = ":";
        char* temp2 = concatVoid(temp, strlen(requestType) + SGX_RSA3072_KEY_SIZE, colon, strlen(colon));
        char* networkRequest = concatVoid(temp2, strlen(requestType) + SGX_RSA3072_KEY_SIZE + strlen(colon), num, strlen(num));
        safe_free(temp);
        safe_free(temp2);
        ocall_network_request(&ret_value, networkRequest, networkResult, 100);
        safe_free(networkRequest);
    }
    safe_free(num);
    safe_free(networkResult);

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
    decrypted_data[decrypted_data_length] = '\0';
    // ocall_print("Decrypted data is");
    // ocall_print(decrypted_data);
    return decrypted_data;
}

char* encryptMessageExternalPublicKey(char* message, size_t message_length_with_null_byte, void* other_party_public_key_raw, int& output_encrypted_message_length) {

    // ocall_print("Pub key received is");
    // ocall_print((char*) other_party_public_key_raw);

    size_t encrypted_data_length;
    char* encrypted_data = (char*) malloc(MAX_NETWORK_MESSAGE); //TODO note if message is bigger than this size, then we can run into issues
    
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
    encrypted_data[encrypted_data_length] = '\0';
    output_encrypted_message_length = encrypted_data_length;
    return encrypted_data;
}

bool verifySignature(char* message, sgx_rsa3072_signature_t* signature, sgx_rsa3072_public_key_t* public_key) {

    uint8_t* p_data = (uint8_t*) message;
    uint32_t data_size = strlen(message) + 1;
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

//Responsibility of caller to free signature
sgx_rsa3072_signature_t* signStringMessage(char* message, sgx_rsa3072_key_t *private_key) {

    sgx_rsa3072_signature_t* signatureMessage = (sgx_rsa3072_signature_t*) malloc(sizeof(sgx_rsa3072_signature_t));
    uint8_t* p_data = (uint8_t*) message;
    uint32_t data_size = strlen(message) + 1;


    sgx_status_t status = SGX_SUCCESS;
    status = sgx_rsa3072_sign(
        p_data,
        data_size,
        private_key,
        signatureMessage
    );
    if (status != SGX_SUCCESS) {
        ocall_print("Error in signing string!");
    } else {
        ocall_print("Message signed successfully!");
    }
    return signatureMessage;
}

//Responsibilty of caller to free return
char* generateSessionKeyTest() {
    char* sessionKey = (char*) malloc(100);
    sgx_read_rand((unsigned char*)sessionKey, 98);
    sessionKey[98] = '!';
    sessionKey[99] = '\0';
    for (int i = 0; i < 99; i ++) {
        if (sessionKey[i] == '\0') {
            sessionKey[i] ='0';
        }
    }
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

//publicID and privateID must be allocated by the caller
void generateIdentityDebug(string& publicID, string& privateID, string prefix) {
    uint32_t val; 
    sgx_read_rand((unsigned char *) &val, 4);
    publicID =  prefix + "SPub" + to_string(val % 100);
    publicID = publicID + "qqqqqqqqqqqqqqqqqqqqqqqqqqqq";
    privateID = prefix + "SPriv" + to_string(val % 100);
    privateID = privateID + "qqqqqqqqqqqqqqqqqqqqqqqqqqqq";

    sgx_rsa3072_key_t *private_capabilityB_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    sgx_rsa3072_public_key_t *public_capabilityB_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    void* private_capabilityB_key_raw = NULL;
    void* public_capabilityB_key_raw = NULL;
    createRsaKeyPair(public_capabilityB_key, private_capabilityB_key, &public_capabilityB_key_raw, &private_capabilityB_key_raw);
    ocall_print("capability key is");
    ocall_print((char*)public_capabilityB_key_raw);

    sgx_rsa3072_key_t *private_B_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    sgx_rsa3072_public_key_t *public_B_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    void* private_B_key_raw = NULL;
    void* public_B_key_raw = NULL;
    createRsaKeyPair(public_B_key, private_B_key, &public_B_key_raw, &private_B_key_raw);

    sgx_rsa3072_key_t *private_A_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    sgx_rsa3072_public_key_t *public_A_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    void* private_A_key_raw = NULL;
    void* public_A_key_raw = NULL;
    createRsaKeyPair(public_A_key, private_A_key, &public_A_key_raw, &private_A_key_raw);


    char* secureMessage = "Encrypted Hello!";

    sgx_rsa3072_signature_t* signatureSecureMessage = signStringMessage(secureMessage, private_capabilityB_key);

    char* sigPrefix = "SIG:";

    char* temp = concatVoid(secureMessage, strlen(secureMessage), sigPrefix, strlen(sigPrefix));

    // ocall_print("temp is");
    // ocall_print(temp);

    // char* concatMessageWithSig = concatVoid(temp, strlen(temp), signatureSecureMessage, SGX_RSA3072_KEY_SIZE);
    // ocall_print("Concated message is");
    // ocall_print(concatMessageWithSig);

    free(temp);

    if (verifySignature(secureMessage, signatureSecureMessage, public_capabilityB_key)) {
        ocall_print("Verifying Signature works!!!!");
    } else {
        ocall_print("Verification Failed!");
    }
    
    int encryptedMessageSize;
    char* encryptedMessage = encryptMessageExternalPublicKey(secureMessage, strlen(secureMessage) + 1, public_B_key_raw, encryptedMessageSize);
    ocall_print("Encrypted Message is");
    ocall_print(encryptedMessage);

    char* decryptedMessage = decryptMessageInteralPrivateKey(encryptedMessage, encryptedMessageSize, private_B_key_raw);
    ocall_print("Decrypted Message is");
    ocall_print(decryptedMessage);



    /////

    char* sessionKey = generateSessionKeyTest();
    ocall_print("Session Key is");
    ocall_print(sessionKey);

    char* serializedKey = checkRawRSAKeySize((char*)public_B_key_raw);

    int encryptedSessionKeyLength;
    char* encryptedSessionKey = encryptMessageExternalPublicKey(sessionKey, 100, serializedKey, encryptedSessionKeyLength);
    ocall_print("Encrypted Session Key is");
    ocall_print(encryptedSessionKey);

    char* network_message = concatVoid(sigPrefix, strlen(sigPrefix), encryptedSessionKey, encryptedSessionKeyLength);
    // ocall_print(network_message);
    char* reentrant = NULL;
    char* split = strtok_r(network_message, ":", &reentrant);
    split = network_message + strlen(split) + 1;
    ocall_print(split);


    // char* split = network_message + 5;// strtok(network_message, ":SIG:");

    // split = strtok(NULL, ":SIG:");

    decryptedMessage = decryptMessageInteralPrivateKey(split, encryptedSessionKeyLength, private_B_key_raw);
    ocall_print("Decrypted SessionKey is");
    ocall_print(decryptedMessage);


    //test generate identity
    // sgx_rsa3072_public_key_t *public_key = NULL;
    // sgx_rsa3072_key_t *private_key = NULL;
    sgx_rsa3072_key_t *private_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    sgx_rsa3072_public_key_t *public_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    void* publicIdentity = NULL;
    void* privateIdentity = NULL;
    generateIdentity(public_key, private_key, &publicIdentity, &privateIdentity);
    if (publicIdentity == NULL || public_key == NULL) {
        ocall_print("Generate Identity doesnt' work");
    } else {
        ocall_print("generate identity works!");
    }


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
    if (PublicIdentityKeyToMachinePIDDictionary.count(string(receivingMachineIDKey)) == 0) {
        ocall_print("Key not found");
    }
    snprintf(temp, 5, "%d", PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)]);
    ocall_print(temp);
    safe_free(temp);
    receivingMachinePID.machineId = PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey)];
    handle_incoming_event(atoi(event), receivingMachinePID, numArgs, payloadType, payload); //TODO update to untrusted send api
}

int decryptAndSendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* encryptedMessage, uint32_t ID_SIZE, uint32_t MAX_ENCRYPTED_MESSAGE) {
    ocall_print("entered decrypt fn");
    char* split = strtok(encryptedMessage, ":");
    char* eventNum = split;
    split = strtok(NULL, ":");
    int numArgs = atoi(split);
    int payloadType = -1;
    ocall_print("chillin");
    char* payload = (char*) malloc(10);
    payload[0] = '\0';
    if (numArgs > 0) {
        split = strtok(NULL, ":");
        payloadType = atoi(split);
        split = strtok(NULL, "\0");
        safe_free(payload);
        payload = split;

    } else {
        safe_free(payload);
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
            char* printStr = generateCStringFromFormat("%s machine is sending out following network request:", machineNameWrapper, 1);
            ocall_print(printStr);
            safe_free(printStr);
            ocall_print(initComRequest);
            char* newSessionKey = (char*) malloc(SIZE_OF_SESSION_KEY);
            int ret_value;
            ocall_network_request(&ret_value, initComRequest, newSessionKey, SIZE_OF_SESSION_KEY);
            safe_free(initComRequest);
            char* machineNameWrapper2[] = {currentMachineIDPublicKey};
            printStr = generateCStringFromFormat("%s machine has received new session key:", machineNameWrapper2, 1);
            ocall_print(printStr);
            safe_free(printStr);       
            ocall_print(newSessionKey);
            PublicIdentityKeyToChildSessionKey[make_tuple(string(currentMachineIDPublicKey), string(sendingToMachinePublicID))] = string(newSessionKey);
            safe_free(newSessionKey);
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
    safe_free(temp);

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
    char* printStr = generateCStringFromFormat("%s machine is sending out following network request:", machineNameWrapper, 1);
    ocall_print(printStr);
    safe_free(printStr);      
    ocall_print(sendRequest);
    char* empty;
    int ret_value;
    ocall_network_request(&ret_value, sendRequest, empty, 0);
    safe_free(sendRequest);

    char* machineNameWrapper2[] = {currentMachineIDPublicKey};
    printStr = generateCStringFromFormat("%s machine has succesfully sent message", machineNameWrapper2, 1);
    ocall_print(printStr);
    safe_free(printStr);

    safe_free(event);
    safe_free(eventMessagePayload);
    safe_free(numArgsPayload);

    safe_free(currentMachineIDPublicKey);

}

extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

    sendSendNetworkRequest(context, argRefs, "UntrustedSend", false);
   
}

extern "C" void P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   
}
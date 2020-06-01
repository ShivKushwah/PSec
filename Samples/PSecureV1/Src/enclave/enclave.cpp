#include "enclave.h"

const int n_byte_size = SGX_RSA3072_KEY_SIZE;


PRT_PROCESS *process =  NULL;
extern PRT_PROGRAMDECL* program;

sgx_enclave_id_t current_eid;

extern char secure_message[SIZE_OF_MESSAGE]; 
extern char secure_message_attestation_request[SIZE_OF_MESSAGE];
unordered_map<int, identityKeyPair> MachinePIDToIdentityDictionary;
unordered_map<string, int> PublicIdentityKeyToMachinePIDDictionary;
unordered_map<int, string> MachinePIDtoCapabilityKeyDictionary;

unordered_map<string, string> PublicIdentityKeyToPublicSigningKey;
unordered_map<string, string> PrivateIdentityKeyToPrivateSigningKey;

map<PMachineChildPair, string> PMachineToChildCapabilityKey;
map<PublicMachineChildPair, string> PublicIdentityKeyToChildSessionKey;
map<tuple<string, string>, int> ChildSessionKeyToNonce;

bool containsSSMAlready = false;

// P Process Required Setup Methods *******************

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
    abort();


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

extern int Delta;


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

//*******************

//SSM API Functions*******************
void UntrustedCreateMachineAPI(sgx_enclave_id_t currentEid, char* machineTypeToCreate, int lengthString, char* returnNewMachinePublicID, int numArgs, int payloadType, char* payloadString, int payloadSize, int ID_SIZE, int PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    if (containsSSMAlready) {
        memcpy(returnNewMachinePublicID, "ERROR", 6);
        return;
    }
    containsSSMAlready = true;
    
    current_eid = currentEid;
    char* newMachinePublicIDKey = createMachineHelper(machineTypeToCreate, "", numArgs, payloadType, payloadString, payloadSize, false, enclaveEid);
    //"Return" the publicIDKey of the new machine
    memcpy(returnNewMachinePublicID, newMachinePublicIDKey, SIZE_OF_RETURN_ID_AFTER_CREATE_REQUEST);
    safe_free(newMachinePublicIDKey);
}

int createMachineAPI(sgx_enclave_id_t currentEid, char* machineType, char* parentTrustedMachinePublicIDKey, char* returnNewMachinePublicIDKey, int numArgs, int payloadType, char* payload, int payloadSize, uint32_t ID_SIZE, uint32_t PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid) {
    if (containsSSMAlready) {
        memcpy(returnNewMachinePublicIDKey, "ERROR", 6);
        return -1;
    }
    containsSSMAlready = true;
    
    current_eid = currentEid;
   
    if (!NETWORK_DEBUG) {
         ocall_print("we at create machine api level now");
        ocall_print("printing parentTrustedMachinePublicKey");
        printRSAKey(parentTrustedMachinePublicIDKey);
    }
    
    char* newMachinePublicIDKey = createMachineHelper(machineType, parentTrustedMachinePublicIDKey, numArgs, payloadType, payload, payloadSize, true, enclaveEid);
    //"Return" the publicIDKey of the new machine
    memcpy(returnNewMachinePublicIDKey, newMachinePublicIDKey, SIZE_OF_RETURN_ID_AFTER_CREATE_REQUEST);
    safe_free(newMachinePublicIDKey);
}

int initializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* newSessionKey, char* returnMessage, uint32_t ID_SIZE, uint32_t SESSION_KEY_SIZE) {
    ocall_print("Initialize Communication API Called!");

    string requestingMachinePublicSigningKey = string(requestingMachineIDKey + SGX_RSA3072_KEY_SIZE + 1, sizeof(sgx_rsa3072_public_key_t));
    PublicIdentityKeyToPublicSigningKey[string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE)] = requestingMachinePublicSigningKey;

    char* receivingMachinePrivateID = (char*)get<1>(MachinePIDToIdentityDictionary[PublicIdentityKeyToMachinePIDDictionary[string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE)]]).c_str();
    char* decryptedMessage = decryptMessageInteralPrivateKey(newSessionKey, SGX_RSA3072_KEY_SIZE, receivingMachinePrivateID);
    printPayload(newSessionKey, SGX_RSA3072_KEY_SIZE);
    printSessionKey(decryptedMessage);
    int count;
    count = PublicIdentityKeyToChildSessionKey.count(make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE)));
    
    if (count == 0) {
        PublicIdentityKeyToChildSessionKey[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(requestingMachineIDKey, SGX_RSA3072_KEY_SIZE))] = string(decryptedMessage, SIZE_OF_REAL_SESSION_KEY);
        ChildSessionKeyToNonce[make_tuple(string(receivingMachineIDKey, SGX_RSA3072_KEY_SIZE), string(decryptedMessage, SIZE_OF_REAL_SESSION_KEY))] = 0;
        char* successMessage = "Success: Session Key Received!";
        ocall_print(successMessage);
        printSessionKey(decryptedMessage);
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

int decryptAndSendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response, int isSecureSend, uint32_t ID_SIZE, uint32_t MAX_ENCRYPTED_MESSAGE, uint32_t RESPONSE_SIZE) {
    decryptAndSendInternalMessageHelper(requestingMachineIDKey, receivingMachineIDKey, iv, mac, encryptedMessage, response, isSecureSend);
}

//*******************

//SSM P Foreign Functions*******************

extern "C" PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
    return P_CreateMachineSecureChild_IMPL(context, argRefs);
}

extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    return sendCreateMachineNetworkRequest(context, argRefs, "Create", true);
}

extern "C" PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    return P_UntrustedCreateRequest_IMPL(context, argRefs);
}

extern "C" PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    sendSendNetworkRequest(context, argRefs, "Send", true, true);
}

extern "C" PRT_VALUE* P_UntrustedCreateRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
   return sendCreateMachineNetworkRequest(context, argRefs, "UntrustedCreate", false);
}


extern "C" void P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    sendSendNetworkRequest(context, argRefs, "UntrustedSend", false, true);  
}

//*******************

//Ecall Implementation*******************
void eprint(char* printStr) {
    ocall_print(printStr);
}

void createRsaKeyPairEcall(char* public_key_raw_out, char* private_key_raw_out, char* public_key_out, char* private_key_out, uint32_t KEY_SIZE) {
    sgx_rsa3072_key_t *private_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t));
    sgx_rsa3072_public_key_t *public_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
    void* private_key_raw = NULL;
    void* public_key_raw = NULL;
    unsigned char *p_dmp1 = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_dmq1 = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_iqmp = (unsigned char *)malloc(n_byte_size);
    createRsaKeyPair(public_key, private_key, &public_key_raw, &private_key_raw, p_dmp1, p_dmq1, p_iqmp);
    memcpy(public_key_raw_out, public_key_raw, SGX_RSA3072_KEY_SIZE);
    memcpy(private_key_raw_out, private_key_raw, SGX_RSA3072_KEY_SIZE);
    memcpy(public_key_out, public_key, sizeof(sgx_rsa3072_public_key_t));
    memcpy(private_key_out, private_key, sizeof(sgx_rsa3072_key_t));
}

int verifySignatureEcall(char* message, uint32_t MESSAGE_SIZE, char* signature, char* public_key, uint32_t SIZE_OF_SIGNATURE, uint32_t SIZE_OF_PUBLIC_KEY) {
    ocall_print("We are inside VerifySignatureEcall");
    bool ret = verifySignature(message, MESSAGE_SIZE, (sgx_rsa3072_signature_t*) signature, (sgx_rsa3072_public_key_t*) public_key);
    return ret ? 1 : 0;
}

void sgx_read_rand_ecall(char* rand_buffer, uint32_t NUM_BYTES_RAND) {
    sgx_read_rand((unsigned char*)rand_buffer, NUM_BYTES_RAND);
}

void signStringMessageEcall(char* message, int MESSAGE_SIZE, char *private_key, char* signature_out, uint32_t private_key_size, uint32_t signature_size) {
    sgx_rsa3072_signature_t* ret = signStringMessage(message, MESSAGE_SIZE, (sgx_rsa3072_key_t*) private_key);
    memcpy(signature_out, (char*)ret, signature_size);
    safe_free(ret);
}

void encryptMessageExternalPublicKeyEcall(char* message, size_t message_length_with_null_byte, char* other_party_public_key_raw, char* output_encrypted_message, char* other_party_public_key, uint32_t SIZE_OF_KEY_RAW, uint32_t SIZE_OF_KEY) {
    int len;
    char* encryptedMessage = encryptMessageExternalPublicKey(message, message_length_with_null_byte, (void*)other_party_public_key_raw, len, (void*) other_party_public_key);
    memcpy(output_encrypted_message, encryptedMessage, SIZE_OF_KEY);
}

void decryptMessageInteralPrivateKeyEcall(char* encryptedData, size_t encryptedDataSize, char* private_key, char* output_decrypted_message, uint32_t SIZE_OF_KEY) {
    int len;
    char* decryptedMessage = decryptMessageInteralPrivateKey(encryptedData, encryptedDataSize, (void*)private_key);
    memcpy(output_decrypted_message, decryptedMessage, SIZE_OF_KEY);
}

void sgx_rijndael128GCM_decrypt_Ecall(const sgx_aes_gcm_128bit_key_t *p_key,
                                                const uint8_t *p_src,
                                                uint32_t src_len,
                                                uint8_t *p_dst,
                                                const uint8_t *p_iv,
                                                uint32_t iv_len,
                                                const uint8_t *p_aad,
                                                uint32_t aad_len,
                                                const sgx_aes_gcm_128bit_tag_t *p_in_mac) {

    sgx_status_t status = sgx_rijndael128GCM_decrypt(p_key, p_src, src_len, p_dst, p_iv, iv_len, p_aad, aad_len, p_in_mac);
    if (status != SGX_SUCCESS) {
        ocall_print("Error: Decrypting in sgx_rijndael128GCM_decrypt_Ecall");
    }
}

void sgx_rijndael128GCM_encrypt_Ecall(const sgx_aes_gcm_128bit_key_t *p_key,
                                                const uint8_t *p_src,
                                                uint32_t src_len,
                                                uint8_t *p_dst,
                                                const uint8_t *p_iv,
                                                uint32_t iv_len,
                                                const uint8_t *p_aad,
                                                uint32_t aad_len,
                                                sgx_aes_gcm_128bit_tag_t *p_out_mac) {

    sgx_status_t status = sgx_rijndael128GCM_encrypt(p_key, p_src, src_len, p_dst, p_iv, iv_len, p_aad, aad_len, p_out_mac);
    if (status != SGX_SUCCESS) {
        ocall_print("Error: Encrypting in sgx_rijndael128GCM_encrypt_Ecall");
    }
}


void sgx_ecc256_open_context_Ecall(sgx_ecc_state_handle_t* ecc_handle) {
    sgx_status_t status = sgx_ecc256_open_context(ecc_handle);
    if (status != SGX_SUCCESS) {
        ocall_print("Error: in sgx_ecc256_open_context_Ecall");
    }
}

void sgx_ecc256_close_context_Ecall(sgx_ecc_state_handle_t ecc_handle) {
    sgx_status_t status = sgx_ecc256_close_context(ecc_handle);
    if (status != SGX_SUCCESS) {
        ocall_print("Error: in sgx_ecc256_close_context_Ecall");
    }
}

void sgx_ecc256_create_key_pair_Ecall(sgx_ec256_private_t *p_private,
                                        sgx_ec256_public_t *p_public,
                                        sgx_ecc_state_handle_t ecc_handle) {

    sgx_status_t status = sgx_ecc256_create_key_pair(p_private, p_public, ecc_handle);
    if (status != SGX_SUCCESS) {
        ocall_print("Error: Macing in sgx_ecc256_create_key_pair_Ecall");
    }
    
}

void sgx_ecc256_compute_shared_dhkey_Ecall(sgx_ec256_private_t *p_private_b,
                                             sgx_ec256_public_t *p_public_ga,
                                             sgx_ec256_dh_shared_t *p_shared_key,
                                             sgx_ecc_state_handle_t ecc_handle) {
    sgx_status_t status = sgx_ecc256_compute_shared_dhkey(p_private_b, p_public_ga, p_shared_key, ecc_handle);
    if (status != SGX_SUCCESS) {
        ocall_print("Error:  in sgx_ecc256_compute_shared_dhkey");
    }

}

void sgx_ecdsa_sign_Ecall(const uint8_t *p_data, 
                            uint32_t data_size,  
                            sgx_ec256_private_t *p_private, 
                            sgx_ec256_signature_t *p_signature, 
                            sgx_ecc_state_handle_t ecc_handle) {
    sgx_status_t status = sgx_ecdsa_sign(p_data, data_size, p_private, p_signature, ecc_handle);
    if (status != SGX_SUCCESS) {
        ocall_print("Error:  in sgx_ecdsa_sign_Ecall");
    }

}

//*******************

//SSM Other Functions*******************

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

    sgx_rsa3072_key_t *private_key;
    sgx_rsa3072_public_key_t *public_key;
  
    if (NETWORK_DEBUG) {
        private_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t)); //TODO shivfree need to free this and below
        public_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
        generateIdentityDebug(secureChildPublicIDKey, secureChildPrivateIDKey, machineTypeToCreateString);
    } else {
        private_key = (sgx_rsa3072_key_t*)malloc(sizeof(sgx_rsa3072_key_t)); //TODO shivfree need to free this and below
        public_key = (sgx_rsa3072_public_key_t*)malloc(sizeof(sgx_rsa3072_public_key_t));
        void* publicIdentity = NULL;
        void* privateIdentity = NULL;
        unsigned char *p_dmp1 = (unsigned char *)malloc(n_byte_size);
        unsigned char *p_dmq1 = (unsigned char *)malloc(n_byte_size);
        unsigned char *p_iqmp = (unsigned char *)malloc(n_byte_size);
        generateIdentity(public_key, private_key, &publicIdentity, &privateIdentity, p_dmp1, p_dmq1, p_iqmp);
        secureChildPublicIDKey = string((char*)publicIdentity, SGX_RSA3072_KEY_SIZE);
        secureChildPrivateIDKey = string((char*)privateIdentity, SGX_RSA3072_KEY_SIZE);
        PublicIdentityKeyToPublicSigningKey[secureChildPublicIDKey] = string((char*)public_key, sizeof(sgx_rsa3072_public_key_t));
        PrivateIdentityKeyToPrivateSigningKey[secureChildPrivateIDKey] = string((char*)private_key, sizeof(sgx_rsa3072_key_t));
    }
        
    char* publicIdKeyCopy = (char*) malloc(secureChildPublicIDKey.length() + 1);
    memcpy(publicIdKeyCopy, (char*)secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    publicIdKeyCopy[secureChildPublicIDKey.length()] = '\0';
    
    //Associate newly created SSM's identity with this enclave so that untrusted distributed host machine knows which enclave to forward messages to when receiving a network message
    ocall_add_identity_to_eid_dictionary((char*)publicIdKeyCopy, SGX_RSA3072_KEY_SIZE, enclaveEid); 
    
    safe_free(publicIdKeyCopy);
    int newMachinePID = getNextPID(); 
    //Store new machine information in enclave's dictionaries
    MachinePIDToIdentityDictionary[newMachinePID] = make_tuple(secureChildPublicIDKey, secureChildPrivateIDKey);
    PublicIdentityKeyToMachinePIDDictionary[secureChildPublicIDKey] = newMachinePID;

    //Contacting KPS for capability key
    char* capabilityKeyPayloadReceived;
    if (isSecureCreate) {
        capabilityKeyPayloadReceived = receiveNewCapabilityKeyFromKPS(parentTrustedMachinePublicIDKey ,(char*)secureChildPublicIDKey.c_str(), machineType);
    } else {
        capabilityKeyPayloadReceived = receiveNewCapabilityKeyFromKPS((char*)secureChildPublicIDKey.c_str() ,(char*)secureChildPublicIDKey.c_str(), machineType);
    } 
    ocall_print("Enclave received new capability Key from KPS: ");
    char* publicCapabilityKey = retrievePublicCapabilityKey(capabilityKeyPayloadReceived);
    char* privateCapabilityKey = retrievePrivateCapabilityKey(capabilityKeyPayloadReceived);
    MachinePIDtoCapabilityKeyDictionary[newMachinePID] = string(capabilityKeyPayloadReceived, SIZE_OF_CAPABILITYKEY);
    PMachineToChildCapabilityKey[make_tuple(newMachinePID, string(secureChildPublicIDKey.c_str(), SGX_RSA3072_KEY_SIZE))] = string(capabilityKeyPayloadReceived, SIZE_OF_CAPABILITYKEY);
    safe_free(publicCapabilityKey);
    safe_free(privateCapabilityKey);
    safe_free(capabilityKeyPayloadReceived);

    char* secureChildPublicIDKeyCopy = (char*) malloc(secureChildPublicIDKey.size() + 1);
    memcpy(secureChildPublicIDKeyCopy, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    secureChildPublicIDKeyCopy[secureChildPublicIDKey.length()] = '\0';
    safe_free(secureChildPublicIDKeyCopy);

    if (isSecureCreate) {
        createPMachine(machineType, numArgs, payloadType, payload, payloadSize);

    } else {
        createPMachine(machineType, 0, PRT_VALUE_KIND_INT, "", 0);
    }

    char* returnNewMachinePublicIDKey = (char*) malloc(secureChildPublicIDKey.length() + 1);
    memcpy(returnNewMachinePublicIDKey, secureChildPublicIDKey.c_str(), secureChildPublicIDKey.length());
    returnNewMachinePublicIDKey[secureChildPublicIDKey.length()] = '\0';

    char* concatStrings[] = {returnNewMachinePublicIDKey, ":", (char*) public_key};
    int concatLenghts[] = {SGX_RSA3072_KEY_SIZE, 1, sizeof(sgx_rsa3072_public_key_t)};
    char* returnID = concatMutipleStringsWithLength(concatStrings, concatLenghts, 3);
    int requestSize = returnTotalSizeofLengthArray(concatLenghts, 3) + 1;

    safe_free(returnNewMachinePublicIDKey);

    return returnID;

}

//Responsibility of caller to free return
char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey, char* requestedMachineTypeToCreate) {
    int ret;
    char* other_machine_name = "KPS";
    char* requestString;
    int requestStringSize;
    char* sizeOfRequestedMachineTypeString = (char*) malloc(10);
    itoa(strlen(requestedMachineTypeToCreate), sizeOfRequestedMachineTypeString, 10);

    char* concatStrings2[] = {"Retrieve:" , currentMachinePublicIDKey, ":", childPublicIDKey, ":", sizeOfRequestedMachineTypeString, ":", requestedMachineTypeToCreate};
    int concatLengths2[] = {9, SGX_RSA3072_KEY_SIZE, 1, SGX_RSA3072_KEY_SIZE, 1, strlen(sizeOfRequestedMachineTypeString), 1, strlen(requestedMachineTypeToCreate)};
    char* requestStringReal = concatMutipleStringsWithLength(concatStrings2, concatLengths2, 8);
    int requestStringSizeReal = returnTotalSizeofLengthArray(concatLengths2, 8) + 1;
    safe_free(sizeOfRequestedMachineTypeString);

    if (requestStringSizeReal > SIZE_OF_MESSAGE) {
        ocall_print("ERROR: attestation request overflow");
    }

    memcpy(secure_message_attestation_request, requestStringReal, requestStringSizeReal);
      
    ocall_enclave_attestation_in_thread(&ret, current_eid, (char*)other_machine_name, SGX_RSA3072_KEY_SIZE);
    safe_free(requestStringReal);
    char* capabilityKeyPayload = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKeyPayload, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKeyPayload;
}

//Responbility of caller to free return
char* receiveNewCapabilityKeyFromKPS(char* parentTrustedMachineID, char* newMachinePublicIDKey, char* requestedMachineTypeToCreate) {
    int ret;
    char* other_machine_name = "KPS";
    char* requestString;
    int requestStringSize;

    char* sizeOfRequestedMachineTypeString = (char*) malloc(10);
    itoa(strlen(requestedMachineTypeToCreate), sizeOfRequestedMachineTypeString, 10);

    char* concatStrings2[] = {"Create:" , newMachinePublicIDKey, ":", parentTrustedMachineID, ":", sizeOfRequestedMachineTypeString, ":", requestedMachineTypeToCreate};
    int concatLengths2[] = {7, SGX_RSA3072_KEY_SIZE, 1, SGX_RSA3072_KEY_SIZE, 1, strlen(sizeOfRequestedMachineTypeString), 1, strlen(requestedMachineTypeToCreate)};
    char* requestStringReal = concatMutipleStringsWithLength(concatStrings2, concatLengths2, 8);
    int requestStringSizeReal = returnTotalSizeofLengthArray(concatLengths2, 8) + 1;
    safe_free(sizeOfRequestedMachineTypeString);

    if (requestStringSizeReal > SIZE_OF_MESSAGE) {
        ocall_print("ERROR: attestation request overflow");
    }

    memcpy(secure_message_attestation_request, requestStringReal, requestStringSizeReal);

    ocall_print("Enclave is asking for creation of new cap key using");
    printRSAKey(newMachinePublicIDKey);
    printRSAKey(parentTrustedMachineID);
    ocall_print(requestedMachineTypeToCreate);
    ocall_enclave_attestation_in_thread(&ret, current_eid, (char*)other_machine_name, SGX_RSA3072_KEY_SIZE);
    safe_free(requestStringReal);
    char* capabilityKey = (char*) malloc(SIZE_OF_CAPABILITYKEY);
    memcpy(capabilityKey, g_secret, SIZE_OF_CAPABILITYKEY);
    return capabilityKey;
    
}

//Responsibilty of caller to free return
char* concatVoid(void* str1, size_t str1_size, void* str2, size_t str2_size) {
    char* returnString = (char*) malloc(str1_size + str2_size + 1);
    memcpy(returnString, (char*)str1, str1_size);
    memcpy(returnString + str1_size , (char*)str2, str2_size);
    returnString[str1_size + str2_size + 1] = '\0';
    return returnString;
}

//Caller needs to allocate space for public_key and private_key
void createRsaKeyPair(sgx_rsa3072_public_key_t *public_key ,sgx_rsa3072_key_t *private_key, void** public_key_raw, void** private_key_raw, unsigned char *p_dmp1, unsigned char *p_dmq1, unsigned char *p_iqmp) {
    int e_byte_size = SGX_RSA3072_PUB_EXP_SIZE;
    unsigned char *p_n = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_d = (unsigned char *)malloc(SGX_RSA3072_PRI_EXP_SIZE);
    unsigned char p_e[] = {0x01, 0x00, 0x01, 0x00}; //65537
    unsigned char *p_p = (unsigned char *)malloc(n_byte_size);
    unsigned char *p_q = (unsigned char *)malloc(n_byte_size);
    // unsigned char *p_dmp1 = (unsigned char *)malloc(n_byte_size);
    // unsigned char *p_dmq1 = (unsigned char *)malloc(n_byte_size);
    // unsigned char *p_iqmp = (unsigned char *)malloc(n_byte_size);
    

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
    }

    free(p_n);
	free(p_d);
	free(p_p);
	free(p_q);

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
        ocall_print("signature is wrong");
        return false;
    } else {
        return true;
    }
}

//Responsibility of caller to free signature
sgx_rsa3072_signature_t* signStringMessage(char* message, int size, sgx_rsa3072_key_t *private_key) {

    sgx_rsa3072_signature_t* signatureMessage = (sgx_rsa3072_signature_t*) malloc(sizeof(sgx_rsa3072_signature_t));
    uint8_t* p_data = (uint8_t*) message;
    uint32_t data_size = size;

    ocall_print("Inside sign string message!");
    ocall_print("Message size is");
    ocall_print_int(size);


    sgx_status_t status = SGX_ERROR_UNRECOGNIZED_PLATFORM;
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
    char* sessionKey = (char*) malloc(SIZE_OF_REAL_SESSION_KEY);
    sgx_read_rand((unsigned char*)sessionKey, SIZE_OF_REAL_SESSION_KEY);
    return sessionKey;
}

char* checkRawRSAKeySize(char* key) {
    char* temp = (char*) malloc(SGX_RSA3072_KEY_SIZE);
    memcpy(temp, key, SGX_RSA3072_KEY_SIZE);
    return temp;
}

//publicID and privateID must be allocated by the caller
void generateIdentityDebug(string& publicID, string& privateID, string prefix) {
    uint32_t val; 
    sgx_read_rand((unsigned char *) &val, 4);
    val = (val + 10) % 100;
    if (val < 10) {
        val = 29;
    }
    publicID = prefix.substr(0, 1) + "SPub" + to_string(val % 100) + "ddQMiiDh5wwA4zFBV3VOazgxZ3d3gnD40rQ2g6yrR8MDFdbJUGhm3ozq2hkYZdF0lWOc0EXBlE8bwwlL6VYoQYLAobQMRIqtS5Ytst1zrhq9YiubRypiP6xNS9UcS9dSBryXmdKAAcpke4ri2Ikx4tDUh1TbHr76WCqmOuwXMA9DqphJEdwIPjiOMr3pwYWt12dfVyFEGL5KcVeYajwgCTiQEmbZ7v5eZfZaBf95Ezh2cxPiI4Z1HfjBGmtYuO1aCdV8yKX0bZRNip3Ycmh8LkIhjHTtF3kchbFRVmhz0zdIOHG0HNSuI8x6ga0vSvSReI7hlrEPfrmm6rEVLPQcwtNAgNdMYQtK1qv4igoOErnwFaWMSqKLkkvAF";
    privateID = prefix.substr(0, 1) + "SPri" + to_string(val % 100) + "ddQMiiDh5wwA4zFBV3VOazgxZ3d3gnD40rQ2g6yrR8MDFdbJUGhm3ozq2hkYZdF0lWOc0EXBlE8bwwlL6VYoQYLAobQMRIqtS5Ytst1zrhq9YiubRypiP6xNS9UcS9dSBryXmdKAAcpke4ri2Ikx4tDUh1TbHr76WCqmOuwXMA9DqphJEdwIPjiOMr3pwYWt12dfVyFEGL5KcVeYajwgCTiQEmbZ7v5eZfZaBf95Ezh2cxPiI4Z1HfjBGmtYuO1aCdV8yKX0bZRNip3Ycmh8LkIhjHTtF3kchbFRVmhz0zdIOHG0HNSuI8x6ga0vSvSReI7hlrEPfrmm6rEVLPQcwtNAgNdMYQtK1qv4igoOErnwFaWMSqKLkkvAF";

} 

void generateIdentity(sgx_rsa3072_public_key_t *public_key, sgx_rsa3072_key_t *private_key, void** publicIdentity, void** privateIdentity, unsigned char *p_dmp1, unsigned char *p_dmq1, unsigned char *p_iqmp) {
    void* sk_raw = NULL;
    void* pk_raw = NULL;
    createRsaKeyPair(public_key, private_key, publicIdentity, privateIdentity, p_dmp1, p_dmq1, p_iqmp);
}

//*******************
extern int CURRENT_ENCLAVE_EID_NUM;
extern const int ENABLE_ENCLAVE_ATTESTATION_PRINT;


struct Enclave_start_attestation_wrapper_arguments {
    sgx_enclave_id_t currentEid;
    char* machineName;
    //int message_from_machine_to_enclave;
};

char* receiveNetworkRequestHelper(char* request, size_t requestSize, bool isEnclaveUntrustedHost);

int untrusted_enclave_start_attestation(const char* receiving_machine_name, char* optional_message="");

char* untrusted_enclave1_receiveNetworkRequest(char* request, size_t requestSize);
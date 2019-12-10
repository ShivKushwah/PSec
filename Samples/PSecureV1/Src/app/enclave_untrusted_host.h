const int ENABLE_ENCLAVE_ATTESTATION_PRINT = 0;
extern int CURRENT_ENCLAVE_EID_NUM;


struct Enclave_start_attestation_wrapper_arguments {
    char* machineName;
    int message_from_machine_to_enclave;
    char* optional_message;
};

int untrusted_enclave_start_attestation(const char* receiving_machine_name, int message_from_machine_to_enclave, char* optional_message="");

char* untrusted_enclave1_receiveNetworkRequest(char* request);
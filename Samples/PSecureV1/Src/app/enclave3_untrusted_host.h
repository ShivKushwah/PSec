const int ENABLE_ENCLAVE3_ATTESTATION_PRINT = 0;


struct Enclave3_start_attestation_wrapper_arguments {
    char* machineName;
    int message_from_machine_to_enclave;
    char* optional_message;
};

int untrusted_enclave3_start_attestation(const char* receiving_machine_name, int message_from_machine_to_enclave, char* optional_message="");

char* untrusted_enclave3_receiveNetworkRequest(char* request);
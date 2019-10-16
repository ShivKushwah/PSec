struct Enclave_start_attestation_wrapper_arguments {
    char* machineName;
    int receive_message;
};

int enclave_start_attestation(const char* receiving_machine_name, int receive_message);


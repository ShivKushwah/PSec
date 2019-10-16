struct Enclave_start_attestation_wrapper_arguments {
    char* machineName;
    int message_from_machine_to_enclave;
};

int enclave_start_attestation(const char* receiving_machine_name, int message_from_machine_to_enclave);


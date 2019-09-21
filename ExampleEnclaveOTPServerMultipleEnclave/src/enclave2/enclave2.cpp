#include "enclave2_t.h"
#include <sgx_thread.h>



int generate_random_number() {
    ocall_print("Processing random number generation...");
    return 42;
}


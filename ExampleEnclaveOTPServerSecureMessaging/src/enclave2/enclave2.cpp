#include "enclave2_t.h"
#include <sgx_thread.h>
#include <string.h>

#include "Utility_E1.h"

extern char* secret_string;

int atoi(char *p) {
    int k = 0;
    while (*p) {
        k = (k << 3) + (k << 1) + (*p) - '0';
        p++;
     }
     return k;
}

int generate_OTP_code() {
    ocall_print("Generating OTP Code");
    ocall_print_int(atoi(secret_string) + 1);
    return atoi(secret_string) + 1;
}

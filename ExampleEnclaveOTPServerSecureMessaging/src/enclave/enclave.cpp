#include "enclave_t.h"
#include <sgx_thread.h>
#include <string.h>

#include "Utility_Enclave.h"

extern char* string_sent;

int atoi(char *p) {
    int k = 0;
    while (*p) {
        k = (k << 3) + (k << 1) + (*p) - '0';
        p++;
     }
     return k;
}

int verify_OTP_code(int code) {
    ocall_print("Enclave1 is validating OTP Code.");
    if (code == atoi(string_sent) + 1) {
        ocall_print("Code is valid!");
        return 1;
    } else {
        ocall_print("Code is not valid.");
        return 0;
    }
}

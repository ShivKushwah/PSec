#include "enclave_t.h"

int OTP_SECRET = 0;

int save_otp_secret(int secret) {
    OTP_SECRET = secret;
    if (OTP_SECRET == secret) {
        ocall_print("Entered Enclave: Stored Secret Successfully:");
        ocall_print_int(OTP_SECRET);
    }
    return 1;
}

int get_otp_secret() {
    ocall_print("Entered Enclave: Retrieving Secret");
    ocall_print_int(OTP_SECRET);
    return OTP_SECRET;
}

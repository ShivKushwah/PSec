#ifndef SGX_UTILS_H_
#define SGX_UTILS_H_

#include <string.h> 

void print_error_message(sgx_status_t ret);

int initialize_enclave(sgx_enclave_id_t* eid, const char* launch_token_path, const char* enclave_name);

int is_ecall_successful_overload(sgx_status_t sgx_status, const char* err_msg);

int is_ecall_successful(sgx_status_t sgx_status, const char* err_msg, sgx_status_t ecall_return_value);

#endif // SGX_UTILS_H_

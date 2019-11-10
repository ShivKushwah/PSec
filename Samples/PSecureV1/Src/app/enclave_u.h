#ifndef ENCLAVE_U_H__
#define ENCLAVE_U_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include <string.h>
#include "sgx_edger8r.h" /* for sgx_status_t etc. */

#include "sgx_key_exchange.h"

#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

#ifndef OCALL_PRINT_DEFINED__
#define OCALL_PRINT_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_print, (const char* str));
#endif
#ifndef OCALL_PRINT_INT_DEFINED__
#define OCALL_PRINT_INT_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_print_int, (int intPrint));
#endif
#ifndef OCALL_PONG_ENCLAVE_ATTESTATION_IN_THREAD_DEFINED__
#define OCALL_PONG_ENCLAVE_ATTESTATION_IN_THREAD_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_pong_enclave_attestation_in_thread, (char* other_machine_name, uint32_t other_machine_name_size, int message_from_machine_to_enclave, char* optional_message));
#endif
#ifndef OCALL_PING_MACHINE_RECEIVE_ENCRYPTED_MESSAGE_DEFINED__
#define OCALL_PING_MACHINE_RECEIVE_ENCRYPTED_MESSAGE_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_ping_machine_receive_encrypted_message, (uint8_t* p_secret, uint32_t secret_size, uint8_t* p_gcm_mac));
#endif
#ifndef OCALL_NETWORK_REQUEST_DEFINED__
#define OCALL_NETWORK_REQUEST_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_network_request, (char* request, char* response, uint32_t RESPONSE_SIZE));
#endif
#ifndef SGX_OC_CPUIDEX_DEFINED__
#define SGX_OC_CPUIDEX_DEFINED__
void SGX_UBRIDGE(SGX_CDECL, sgx_oc_cpuidex, (int cpuinfo[4], int leaf, int subleaf));
#endif
#ifndef SGX_THREAD_WAIT_UNTRUSTED_EVENT_OCALL_DEFINED__
#define SGX_THREAD_WAIT_UNTRUSTED_EVENT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_wait_untrusted_event_ocall, (const void* self));
#endif
#ifndef SGX_THREAD_SET_UNTRUSTED_EVENT_OCALL_DEFINED__
#define SGX_THREAD_SET_UNTRUSTED_EVENT_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_set_untrusted_event_ocall, (const void* waiter));
#endif
#ifndef SGX_THREAD_SETWAIT_UNTRUSTED_EVENTS_OCALL_DEFINED__
#define SGX_THREAD_SETWAIT_UNTRUSTED_EVENTS_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_setwait_untrusted_events_ocall, (const void* waiter, const void* self));
#endif
#ifndef SGX_THREAD_SET_MULTIPLE_UNTRUSTED_EVENTS_OCALL_DEFINED__
#define SGX_THREAD_SET_MULTIPLE_UNTRUSTED_EVENTS_OCALL_DEFINED__
int SGX_UBRIDGE(SGX_CDECL, sgx_thread_set_multiple_untrusted_events_ocall, (const void** waiters, size_t total));
#endif
#ifndef CREATE_SESSION_OCALL_DEFINED__
#define CREATE_SESSION_OCALL_DEFINED__
sgx_status_t SGX_UBRIDGE(SGX_NOCONVENTION, create_session_ocall, (uint32_t* sid, uint8_t* dh_msg1, uint32_t dh_msg1_size, uint32_t timeout));
#endif
#ifndef EXCHANGE_REPORT_OCALL_DEFINED__
#define EXCHANGE_REPORT_OCALL_DEFINED__
sgx_status_t SGX_UBRIDGE(SGX_NOCONVENTION, exchange_report_ocall, (uint32_t sid, uint8_t* dh_msg2, uint32_t dh_msg2_size, uint8_t* dh_msg3, uint32_t dh_msg3_size, uint32_t timeout));
#endif
#ifndef CLOSE_SESSION_OCALL_DEFINED__
#define CLOSE_SESSION_OCALL_DEFINED__
sgx_status_t SGX_UBRIDGE(SGX_NOCONVENTION, close_session_ocall, (uint32_t sid, uint32_t timeout));
#endif
#ifndef INVOKE_SERVICE_OCALL_DEFINED__
#define INVOKE_SERVICE_OCALL_DEFINED__
sgx_status_t SGX_UBRIDGE(SGX_NOCONVENTION, invoke_service_ocall, (uint8_t* pse_message_req, uint32_t pse_message_req_size, uint8_t* pse_message_resp, uint32_t pse_message_resp_size, uint32_t timeout));
#endif

sgx_status_t enclave_main(sgx_enclave_id_t eid, int* retval);
sgx_status_t enclave_init_ra(sgx_enclave_id_t eid, sgx_status_t* retval, int b_pse, sgx_ra_context_t* p_context);
sgx_status_t enclave_ra_close(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context);
sgx_status_t verify_att_result_mac(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* message, size_t message_size, uint8_t* mac, size_t mac_size);
sgx_status_t put_secret_data(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* p_secret, uint32_t secret_size, uint8_t* gcm_mac);
sgx_status_t encrypt_secure_message(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* return_encrypted_string, uint32_t requested_secret_size, uint8_t* return_payload_tag);
sgx_status_t pong_enclave_request_attestation(sgx_enclave_id_t eid, int* retval, const char* other_machine_name);
sgx_status_t createMachineAPI(sgx_enclave_id_t eid, int* retval, char* machineName, char* parentTrustedMachineID, char* returnNewMachineID, uint32_t ID_SIZE);
sgx_status_t initializeCommunicationAPI(sgx_enclave_id_t eid, int* retval, char* requestingMachineIDKey, char* receivingMachineIDKey, char* returnSessionKey, uint32_t ID_SIZE, uint32_t SESSION_SIZE);
sgx_status_t sendMessageAPI(sgx_enclave_id_t eid, int* retval, char* requestingMachineIDKey, char* receivingMachineIDKey, char* message, uint32_t ID_SIZE, uint32_t MESSAGE_SIZE);
sgx_status_t sgx_ra_get_ga(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, sgx_ec256_public_t* g_a);
sgx_status_t sgx_ra_proc_msg2_trusted(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, const sgx_ra_msg2_t* p_msg2, const sgx_target_info_t* p_qe_target, sgx_report_t* p_report, sgx_quote_nonce_t* p_nonce);
sgx_status_t sgx_ra_get_msg3_trusted(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint32_t quote_size, sgx_report_t* qe_report, sgx_ra_msg3_t* p_msg3, uint32_t msg3_size);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

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
#ifndef OCALL_ENCLAVE_PRINT_DEFINED__
#define OCALL_ENCLAVE_PRINT_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_enclave_print, (const char* str));
#endif
#ifndef OCALL_PRINT_CURRENT_TIME_DEFINED__
#define OCALL_PRINT_CURRENT_TIME_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_print_current_time, (void));
#endif
#ifndef OCALL_PRINT_INT_DEFINED__
#define OCALL_PRINT_INT_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_print_int, (int intPrint));
#endif
#ifndef OCALL_REQUEST_USER_INPUT_DEFINED__
#define OCALL_REQUEST_USER_INPUT_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_request_user_input, (char* user_input, uint32_t INPUT_SIZE));
#endif
#ifndef OCALL_ENCLAVE_ATTESTATION_IN_THREAD_DEFINED__
#define OCALL_ENCLAVE_ATTESTATION_IN_THREAD_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_enclave_attestation_in_thread, (sgx_enclave_id_t currentEid, char* other_machine_name, uint32_t other_machine_name_size));
#endif
#ifndef OCALL_NETWORK_REQUEST_DEFINED__
#define OCALL_NETWORK_REQUEST_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_network_request, (char* request, char* response, uint32_t REQUEST_SIZE, uint32_t RESPONSE_SIZE, char* ipAddress, uint32_t IP_ADDRESS_SIZE, int port));
#endif
#ifndef OCALL_ADD_IDENTITY_TO_EID_DICTIONARY_DEFINED__
#define OCALL_ADD_IDENTITY_TO_EID_DICTIONARY_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_add_identity_to_eid_dictionary, (char* newMachineID, uint32_t ID_SIZE, sgx_enclave_id_t enclave_eid));
#endif
#ifndef OCALL_GET_IP_ADDRESS_OF_CURRENT_HOST_DEFINED__
#define OCALL_GET_IP_ADDRESS_OF_CURRENT_HOST_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_get_ip_address_of_current_host, (char* ipAddress, int MAX_IP_ADDRESS_SIZE));
#endif
#ifndef OCALL_GET_PORT_OF_CURRENT_HOST_DEFINED__
#define OCALL_GET_PORT_OF_CURRENT_HOST_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_get_port_of_current_host, (void));
#endif
#ifndef OCALL_GET_IP_ADDRESS_OF_KPS_DEFINED__
#define OCALL_GET_IP_ADDRESS_OF_KPS_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_get_ip_address_of_kps, (char* ipAddress, int MAX_IP_ADDRESS_SIZE));
#endif
#ifndef OCALL_GET_ATTESTATION_PORT_OF_KPS_DEFINED__
#define OCALL_GET_ATTESTATION_PORT_OF_KPS_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_get_attestation_port_of_kps, (void));
#endif
#ifndef OCALL_GET_GENERIC_PORT_OF_KPS_DEFINED__
#define OCALL_GET_GENERIC_PORT_OF_KPS_DEFINED__
int SGX_UBRIDGE(SGX_NOCONVENTION, ocall_get_generic_port_of_kps, (void));
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

sgx_status_t enclave_enclave_init_ra(sgx_enclave_id_t eid, sgx_status_t* retval, int b_pse, sgx_ra_context_t* p_context);
sgx_status_t enclave_enclave_ra_close(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context);
sgx_status_t enclave_verify_att_result_mac(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* message, size_t message_size, uint8_t* mac, size_t mac_size);
sgx_status_t enclave_put_secret_data(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* p_secret, uint32_t secret_size, uint8_t* gcm_mac);
sgx_status_t enclave_encrypt_secure_message(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* return_encrypted_string, uint32_t requested_secret_size, uint8_t* return_payload_tag);
sgx_status_t enclave_decryptAndSendMessageAPI(sgx_enclave_id_t eid, int* retval, char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response, int isSecureSend, uint32_t ID_SIZE, uint32_t MAX_ENCRYPTED_MESSAGE, uint32_t MAX_RESPONSE_SIZE);
sgx_status_t enclave_createMachineAPI(sgx_enclave_id_t eid, int* retval, sgx_enclave_id_t currentEid, char* machineName, char* parentTrustedMachineID, char* returnNewMachineID, int numArgs, int payloadType, char* payload, int payloadSize, uint32_t ID_SIZE, uint32_t PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid);
sgx_status_t enclave_initializeCommunicationAPI(sgx_enclave_id_t eid, int* retval, char* requestingMachineIDKey, char* receivingMachineIDKey, char* newSessionKey, char* returnMessage, uint32_t ID_SIZE, uint32_t SESSION_SIZE);
sgx_status_t enclave_verifySignatureEcall(sgx_enclave_id_t eid, int* retval, char* message, uint32_t MESSAGE_SIZE, char* signature, char* public_key, uint32_t SIZE_OF_SIGNATURE, uint32_t SIZE_OF_PUBLIC_KEY);
sgx_status_t enclave_signStringMessageEcall(sgx_enclave_id_t eid, char* message, int MESSAGE_SIZE, char* private_key, char* signature_out, uint32_t private_key_size, uint32_t signature_size);
sgx_status_t enclave_UntrustedCreateMachineAPI(sgx_enclave_id_t eid, sgx_enclave_id_t currentEid, char* machineTypeToCreate, int lengthString, char* returnNewMachinePublicID, int numArgs, int payloadType, char* payload, int payload_length, int output_length, int payload_size, sgx_enclave_id_t enclaveEid);
sgx_status_t enclave_encryptMessageExternalPublicKeyEcall(sgx_enclave_id_t eid, char* message, size_t message_length_with_null_byte, char* other_party_public_key_raw, char* output_encrypted_message, char* other_party_public_key, uint32_t SIZE_OF_KEY_RAW, uint32_t SIZE_OF_KEY);
sgx_status_t enclave_decryptMessageInteralPrivateKeyEcall(sgx_enclave_id_t eid, char* message, size_t message_length_with_null_byte, char* other_party_public_key_raw, char* output_encrypted_message, uint32_t SIZE_OF_KEY);
sgx_status_t enclave_createRsaKeyPairEcall(sgx_enclave_id_t eid, char* public_key_raw_out, char* private_key_raw_out, char* public_key_out, char* private_key_out, uint32_t KEY_SIZE);
sgx_status_t enclave_eprint(sgx_enclave_id_t eid, char* printStr);
sgx_status_t enclave_sgx_read_rand_ecall(sgx_enclave_id_t eid, char* rand_buffer, uint32_t NUM_BYTES_RAND);
sgx_status_t enclave_sgx_rijndael128GCM_decrypt_Ecall(sgx_enclave_id_t eid, const sgx_aes_gcm_128bit_key_t* p_key, const uint8_t* p_src, uint32_t src_len, uint8_t* p_dst, const uint8_t* p_iv, uint32_t iv_len, const uint8_t* p_aad, uint32_t aad_len, const sgx_aes_gcm_128bit_tag_t* p_in_mac);
sgx_status_t enclave_sgx_rijndael128GCM_encrypt_Ecall(sgx_enclave_id_t eid, const sgx_aes_gcm_128bit_key_t* p_key, const uint8_t* p_src, uint32_t src_len, uint8_t* p_dst, const uint8_t* p_iv, uint32_t iv_len, const uint8_t* p_aad, uint32_t aad_len, sgx_aes_gcm_128bit_tag_t* p_out_mac);
sgx_status_t enclave_sgx_ra_get_ga(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, sgx_ec256_public_t* g_a);
sgx_status_t enclave_sgx_ra_proc_msg2_trusted(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, const sgx_ra_msg2_t* p_msg2, const sgx_target_info_t* p_qe_target, sgx_report_t* p_report, sgx_quote_nonce_t* p_nonce);
sgx_status_t enclave_sgx_ra_get_msg3_trusted(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint32_t quote_size, sgx_report_t* qe_report, sgx_ra_msg3_t* p_msg3, uint32_t msg3_size);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

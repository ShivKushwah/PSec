#include "enclave_u.h"
#include <errno.h>

typedef struct ms_enclave_init_ra_t {
	sgx_status_t ms_retval;
	int ms_b_pse;
	sgx_ra_context_t* ms_p_context;
} ms_enclave_init_ra_t;

typedef struct ms_enclave_ra_close_t {
	sgx_status_t ms_retval;
	sgx_ra_context_t ms_context;
} ms_enclave_ra_close_t;

typedef struct ms_verify_att_result_mac_t {
	sgx_status_t ms_retval;
	sgx_ra_context_t ms_context;
	uint8_t* ms_message;
	size_t ms_message_size;
	uint8_t* ms_mac;
	size_t ms_mac_size;
} ms_verify_att_result_mac_t;

typedef struct ms_put_secret_data_t {
	sgx_status_t ms_retval;
	sgx_ra_context_t ms_context;
	uint8_t* ms_p_secret;
	uint32_t ms_secret_size;
	uint8_t* ms_gcm_mac;
} ms_put_secret_data_t;

typedef struct ms_encrypt_secure_message_t {
	sgx_status_t ms_retval;
	sgx_ra_context_t ms_context;
	uint8_t* ms_return_encrypted_string;
	uint32_t ms_requested_secret_size;
	uint8_t* ms_return_payload_tag;
} ms_encrypt_secure_message_t;

typedef struct ms_decryptAndSendMessageAPI_t {
	int ms_retval;
	char* ms_requestingMachineIDKey;
	char* ms_receivingMachineIDKey;
	char* ms_iv;
	char* ms_mac;
	char* ms_encryptedMessage;
	char* ms_response;
	int ms_isSecureSend;
	uint32_t ms_ID_SIZE;
	uint32_t ms_MAX_ENCRYPTED_MESSAGE;
	uint32_t ms_MAX_RESPONSE_SIZE;
} ms_decryptAndSendMessageAPI_t;

typedef struct ms_sendUnencryptedMessageAPI_t {
	int ms_retval;
	char* ms_requestingMachineIDKey;
	char* ms_receivingMachineIDKey;
	char* ms_iv;
	char* ms_mac;
	char* ms_encryptedMessage;
	char* ms_response;
	int ms_isSecureSend;
	uint32_t ms_ID_SIZE;
	uint32_t ms_MAX_ENCRYPTED_MESSAGE;
	uint32_t ms_MAX_RESPONSE_SIZE;
} ms_sendUnencryptedMessageAPI_t;

typedef struct ms_createMachineAPI_t {
	int ms_retval;
	sgx_enclave_id_t ms_currentEid;
	char* ms_machineName;
	char* ms_parentTrustedMachineID;
	char* ms_returnNewMachineID;
	int ms_numArgs;
	int ms_payloadType;
	char* ms_payload;
	int ms_payloadSize;
	uint32_t ms_ID_SIZE;
	uint32_t ms_PAYLOAD_SIZE;
	sgx_enclave_id_t ms_enclaveEid;
} ms_createMachineAPI_t;

typedef struct ms_initializeCommunicationAPI_t {
	int ms_retval;
	char* ms_requestingMachineIDKey;
	char* ms_receivingMachineIDKey;
	char* ms_newSessionKey;
	char* ms_returnMessage;
	uint32_t ms_ID_SIZE;
	uint32_t ms_SESSION_SIZE;
} ms_initializeCommunicationAPI_t;

typedef struct ms_verifySignatureEcall_t {
	int ms_retval;
	char* ms_message;
	uint32_t ms_MESSAGE_SIZE;
	char* ms_signature;
	char* ms_public_key;
	uint32_t ms_SIZE_OF_SIGNATURE;
	uint32_t ms_SIZE_OF_PUBLIC_KEY;
} ms_verifySignatureEcall_t;

typedef struct ms_signStringMessageEcall_t {
	char* ms_message;
	int ms_MESSAGE_SIZE;
	char* ms_private_key;
	char* ms_signature_out;
	uint32_t ms_private_key_size;
	uint32_t ms_signature_size;
} ms_signStringMessageEcall_t;

typedef struct ms_UntrustedCreateMachineAPI_t {
	sgx_enclave_id_t ms_currentEid;
	char* ms_machineTypeToCreate;
	int ms_lengthString;
	char* ms_returnNewMachinePublicID;
	int ms_numArgs;
	int ms_payloadType;
	char* ms_payload;
	int ms_payload_length;
	int ms_output_length;
	int ms_payload_size;
	sgx_enclave_id_t ms_enclaveEid;
} ms_UntrustedCreateMachineAPI_t;

typedef struct ms_encryptMessageExternalPublicKeyEcall_t {
	char* ms_message;
	size_t ms_message_length_with_null_byte;
	char* ms_other_party_public_key_raw;
	char* ms_output_encrypted_message;
	char* ms_other_party_public_key;
	uint32_t ms_SIZE_OF_KEY_RAW;
	uint32_t ms_SIZE_OF_KEY;
} ms_encryptMessageExternalPublicKeyEcall_t;

typedef struct ms_decryptMessageInteralPrivateKeyEcall_t {
	char* ms_message;
	size_t ms_message_length_with_null_byte;
	char* ms_other_party_public_key_raw;
	char* ms_output_encrypted_message;
	uint32_t ms_SIZE_OF_KEY;
} ms_decryptMessageInteralPrivateKeyEcall_t;

typedef struct ms_createRsaKeyPairEcall_t {
	char* ms_public_key_raw_out;
	char* ms_private_key_raw_out;
	char* ms_public_key_out;
	char* ms_private_key_out;
	uint32_t ms_KEY_SIZE;
} ms_createRsaKeyPairEcall_t;

typedef struct ms_eprint_t {
	char* ms_printStr;
} ms_eprint_t;

typedef struct ms_sgx_read_rand_ecall_t {
	char* ms_rand_buffer;
	uint32_t ms_NUM_BYTES_RAND;
} ms_sgx_read_rand_ecall_t;

typedef struct ms_sgx_rijndael128GCM_decrypt_Ecall_t {
	const sgx_aes_gcm_128bit_key_t* ms_p_key;
	const uint8_t* ms_p_src;
	uint32_t ms_src_len;
	uint8_t* ms_p_dst;
	const uint8_t* ms_p_iv;
	uint32_t ms_iv_len;
	const uint8_t* ms_p_aad;
	uint32_t ms_aad_len;
	const sgx_aes_gcm_128bit_tag_t* ms_p_in_mac;
} ms_sgx_rijndael128GCM_decrypt_Ecall_t;

typedef struct ms_sgx_rijndael128GCM_encrypt_Ecall_t {
	const sgx_aes_gcm_128bit_key_t* ms_p_key;
	const uint8_t* ms_p_src;
	uint32_t ms_src_len;
	uint8_t* ms_p_dst;
	const uint8_t* ms_p_iv;
	uint32_t ms_iv_len;
	const uint8_t* ms_p_aad;
	uint32_t ms_aad_len;
	sgx_aes_gcm_128bit_tag_t* ms_p_out_mac;
} ms_sgx_rijndael128GCM_encrypt_Ecall_t;

typedef struct ms_sgx_rijndael128_cmac_msg_Ecall_t {
	const sgx_cmac_128bit_key_t* ms_p_key;
	const uint8_t* ms_p_src;
	uint32_t ms_src_len;
	sgx_cmac_128bit_tag_t* ms_p_mac;
} ms_sgx_rijndael128_cmac_msg_Ecall_t;

typedef struct ms_sgx_ecc256_open_context_Ecall_t {
	sgx_ecc_state_handle_t* ms_ecc_handle;
} ms_sgx_ecc256_open_context_Ecall_t;

typedef struct ms_sgx_ecc256_close_context_Ecall_t {
	sgx_ecc_state_handle_t ms_ecc_handle;
} ms_sgx_ecc256_close_context_Ecall_t;

typedef struct ms_sgx_ecc256_create_key_pair_Ecall_t {
	sgx_ec256_private_t* ms_p_private;
	sgx_ec256_public_t* ms_p_public;
	sgx_ecc_state_handle_t ms_ecc_handle;
} ms_sgx_ecc256_create_key_pair_Ecall_t;

typedef struct ms_sgx_ecc256_compute_shared_dhkey_Ecall_t {
	sgx_ec256_private_t* ms_p_private_b;
	sgx_ec256_public_t* ms_p_public_ga;
	sgx_ec256_dh_shared_t* ms_p_shared_key;
	sgx_ecc_state_handle_t ms_ecc_handle;
} ms_sgx_ecc256_compute_shared_dhkey_Ecall_t;

typedef struct ms_sgx_ecdsa_sign_Ecall_t {
	const uint8_t* ms_p_data;
	uint32_t ms_data_size;
	sgx_ec256_private_t* ms_p_private;
	sgx_ec256_signature_t* ms_p_signature;
	sgx_ecc_state_handle_t ms_ecc_handle;
} ms_sgx_ecdsa_sign_Ecall_t;

typedef struct ms_sgx_sha256_init_Ecall_t {
	sgx_sha_state_handle_t* ms_ecc_handle;
} ms_sgx_sha256_init_Ecall_t;

typedef struct ms_sgx_sha256_update_Ecall_t {
	const uint8_t* ms_p_src;
	uint32_t ms_src_len;
	sgx_sha_state_handle_t ms_sha_handle;
} ms_sgx_sha256_update_Ecall_t;

typedef struct ms_sgx_sha256_get_hash_Ecall_t {
	sgx_sha_state_handle_t ms_sha_handle;
	sgx_sha256_hash_t* ms_p_hash;
} ms_sgx_sha256_get_hash_Ecall_t;

typedef struct ms_sgx_sha256_close_Ecall_t {
	sgx_sha_state_handle_t ms_sha_handle;
} ms_sgx_sha256_close_Ecall_t;

typedef struct ms_ecall_create_report_t {
	int ms_retval;
	sgx_target_info_t* ms_quote_enc_info;
	sgx_report_t* ms_report;
} ms_ecall_create_report_t;

typedef struct ms_ecall_validate_SSM_type_hosted_by_this_enclave_t {
	int ms_retval;
	char* ms_SSMTypeQuery;
	int ms_SSMTypeStringLength;
} ms_ecall_validate_SSM_type_hosted_by_this_enclave_t;

typedef struct ms_sgx_ra_get_ga_t {
	sgx_status_t ms_retval;
	sgx_ra_context_t ms_context;
	sgx_ec256_public_t* ms_g_a;
} ms_sgx_ra_get_ga_t;

typedef struct ms_sgx_ra_proc_msg2_trusted_t {
	sgx_status_t ms_retval;
	sgx_ra_context_t ms_context;
	const sgx_ra_msg2_t* ms_p_msg2;
	const sgx_target_info_t* ms_p_qe_target;
	sgx_report_t* ms_p_report;
	sgx_quote_nonce_t* ms_p_nonce;
} ms_sgx_ra_proc_msg2_trusted_t;

typedef struct ms_sgx_ra_get_msg3_trusted_t {
	sgx_status_t ms_retval;
	sgx_ra_context_t ms_context;
	uint32_t ms_quote_size;
	sgx_report_t* ms_qe_report;
	sgx_ra_msg3_t* ms_p_msg3;
	uint32_t ms_msg3_size;
} ms_sgx_ra_get_msg3_trusted_t;

typedef struct ms_ocall_print_t {
	const char* ms_str;
} ms_ocall_print_t;

typedef struct ms_ocall_enclave_print_t {
	const char* ms_str;
} ms_ocall_enclave_print_t;

typedef struct ms_ocall_print_int_t {
	int ms_intPrint;
} ms_ocall_print_int_t;

typedef struct ms_ocall_request_user_input_t {
	char* ms_user_input;
	uint32_t ms_INPUT_SIZE;
} ms_ocall_request_user_input_t;

typedef struct ms_ocall_enclave_attestation_in_thread_t {
	int ms_retval;
	sgx_enclave_id_t ms_currentEid;
	char* ms_other_machine_name;
	uint32_t ms_other_machine_name_size;
} ms_ocall_enclave_attestation_in_thread_t;

typedef struct ms_ocall_network_request_t {
	int ms_retval;
	char* ms_request;
	char* ms_response;
	uint32_t ms_REQUEST_SIZE;
	uint32_t ms_RESPONSE_SIZE;
	char* ms_ipAddress;
	uint32_t ms_IP_ADDRESS_SIZE;
	int ms_port;
} ms_ocall_network_request_t;

typedef struct ms_ocall_add_identity_to_eid_dictionary_t {
	char* ms_newMachineID;
	uint32_t ms_ID_SIZE;
	sgx_enclave_id_t ms_enclave_eid;
} ms_ocall_add_identity_to_eid_dictionary_t;

typedef struct ms_ocall_get_ip_address_of_current_host_t {
	char* ms_ipAddress;
	int ms_MAX_IP_ADDRESS_SIZE;
} ms_ocall_get_ip_address_of_current_host_t;

typedef struct ms_ocall_get_port_of_current_host_t {
	int ms_retval;
} ms_ocall_get_port_of_current_host_t;

typedef struct ms_ocall_get_ip_address_of_kps_t {
	char* ms_ipAddress;
	int ms_MAX_IP_ADDRESS_SIZE;
} ms_ocall_get_ip_address_of_kps_t;

typedef struct ms_ocall_get_attestation_port_of_kps_t {
	int ms_retval;
} ms_ocall_get_attestation_port_of_kps_t;

typedef struct ms_ocall_get_generic_port_of_kps_t {
	int ms_retval;
} ms_ocall_get_generic_port_of_kps_t;

typedef struct ms_sgx_oc_cpuidex_t {
	int* ms_cpuinfo;
	int ms_leaf;
	int ms_subleaf;
} ms_sgx_oc_cpuidex_t;

typedef struct ms_sgx_thread_wait_untrusted_event_ocall_t {
	int ms_retval;
	const void* ms_self;
} ms_sgx_thread_wait_untrusted_event_ocall_t;

typedef struct ms_sgx_thread_set_untrusted_event_ocall_t {
	int ms_retval;
	const void* ms_waiter;
} ms_sgx_thread_set_untrusted_event_ocall_t;

typedef struct ms_sgx_thread_setwait_untrusted_events_ocall_t {
	int ms_retval;
	const void* ms_waiter;
	const void* ms_self;
} ms_sgx_thread_setwait_untrusted_events_ocall_t;

typedef struct ms_sgx_thread_set_multiple_untrusted_events_ocall_t {
	int ms_retval;
	const void** ms_waiters;
	size_t ms_total;
} ms_sgx_thread_set_multiple_untrusted_events_ocall_t;

typedef struct ms_create_session_ocall_t {
	sgx_status_t ms_retval;
	uint32_t* ms_sid;
	uint8_t* ms_dh_msg1;
	uint32_t ms_dh_msg1_size;
	uint32_t ms_timeout;
} ms_create_session_ocall_t;

typedef struct ms_exchange_report_ocall_t {
	sgx_status_t ms_retval;
	uint32_t ms_sid;
	uint8_t* ms_dh_msg2;
	uint32_t ms_dh_msg2_size;
	uint8_t* ms_dh_msg3;
	uint32_t ms_dh_msg3_size;
	uint32_t ms_timeout;
} ms_exchange_report_ocall_t;

typedef struct ms_close_session_ocall_t {
	sgx_status_t ms_retval;
	uint32_t ms_sid;
	uint32_t ms_timeout;
} ms_close_session_ocall_t;

typedef struct ms_invoke_service_ocall_t {
	sgx_status_t ms_retval;
	uint8_t* ms_pse_message_req;
	uint32_t ms_pse_message_req_size;
	uint8_t* ms_pse_message_resp;
	uint32_t ms_pse_message_resp_size;
	uint32_t ms_timeout;
} ms_invoke_service_ocall_t;

static sgx_status_t SGX_CDECL enclave_ocall_print(void* pms)
{
	ms_ocall_print_t* ms = SGX_CAST(ms_ocall_print_t*, pms);
	ocall_print(ms->ms_str);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_enclave_print(void* pms)
{
	ms_ocall_enclave_print_t* ms = SGX_CAST(ms_ocall_enclave_print_t*, pms);
	ocall_enclave_print(ms->ms_str);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_print_current_time(void* pms)
{
	if (pms != NULL) return SGX_ERROR_INVALID_PARAMETER;
	ocall_print_current_time();
	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_print_int(void* pms)
{
	ms_ocall_print_int_t* ms = SGX_CAST(ms_ocall_print_int_t*, pms);
	ocall_print_int(ms->ms_intPrint);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_request_user_input(void* pms)
{
	ms_ocall_request_user_input_t* ms = SGX_CAST(ms_ocall_request_user_input_t*, pms);
	ocall_request_user_input(ms->ms_user_input, ms->ms_INPUT_SIZE);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_enclave_attestation_in_thread(void* pms)
{
	ms_ocall_enclave_attestation_in_thread_t* ms = SGX_CAST(ms_ocall_enclave_attestation_in_thread_t*, pms);
	ms->ms_retval = ocall_enclave_attestation_in_thread(ms->ms_currentEid, ms->ms_other_machine_name, ms->ms_other_machine_name_size);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_network_request(void* pms)
{
	ms_ocall_network_request_t* ms = SGX_CAST(ms_ocall_network_request_t*, pms);
	ms->ms_retval = ocall_network_request(ms->ms_request, ms->ms_response, ms->ms_REQUEST_SIZE, ms->ms_RESPONSE_SIZE, ms->ms_ipAddress, ms->ms_IP_ADDRESS_SIZE, ms->ms_port);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_add_identity_to_eid_dictionary(void* pms)
{
	ms_ocall_add_identity_to_eid_dictionary_t* ms = SGX_CAST(ms_ocall_add_identity_to_eid_dictionary_t*, pms);
	ocall_add_identity_to_eid_dictionary(ms->ms_newMachineID, ms->ms_ID_SIZE, ms->ms_enclave_eid);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_get_ip_address_of_current_host(void* pms)
{
	ms_ocall_get_ip_address_of_current_host_t* ms = SGX_CAST(ms_ocall_get_ip_address_of_current_host_t*, pms);
	ocall_get_ip_address_of_current_host(ms->ms_ipAddress, ms->ms_MAX_IP_ADDRESS_SIZE);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_get_port_of_current_host(void* pms)
{
	ms_ocall_get_port_of_current_host_t* ms = SGX_CAST(ms_ocall_get_port_of_current_host_t*, pms);
	ms->ms_retval = ocall_get_port_of_current_host();

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_get_ip_address_of_kps(void* pms)
{
	ms_ocall_get_ip_address_of_kps_t* ms = SGX_CAST(ms_ocall_get_ip_address_of_kps_t*, pms);
	ocall_get_ip_address_of_kps(ms->ms_ipAddress, ms->ms_MAX_IP_ADDRESS_SIZE);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_get_attestation_port_of_kps(void* pms)
{
	ms_ocall_get_attestation_port_of_kps_t* ms = SGX_CAST(ms_ocall_get_attestation_port_of_kps_t*, pms);
	ms->ms_retval = ocall_get_attestation_port_of_kps();

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_get_generic_port_of_kps(void* pms)
{
	ms_ocall_get_generic_port_of_kps_t* ms = SGX_CAST(ms_ocall_get_generic_port_of_kps_t*, pms);
	ms->ms_retval = ocall_get_generic_port_of_kps();

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_ocall_kill(void* pms)
{
	if (pms != NULL) return SGX_ERROR_INVALID_PARAMETER;
	ocall_kill();
	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_sgx_oc_cpuidex(void* pms)
{
	ms_sgx_oc_cpuidex_t* ms = SGX_CAST(ms_sgx_oc_cpuidex_t*, pms);
	sgx_oc_cpuidex(ms->ms_cpuinfo, ms->ms_leaf, ms->ms_subleaf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_sgx_thread_wait_untrusted_event_ocall(void* pms)
{
	ms_sgx_thread_wait_untrusted_event_ocall_t* ms = SGX_CAST(ms_sgx_thread_wait_untrusted_event_ocall_t*, pms);
	ms->ms_retval = sgx_thread_wait_untrusted_event_ocall(ms->ms_self);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_sgx_thread_set_untrusted_event_ocall(void* pms)
{
	ms_sgx_thread_set_untrusted_event_ocall_t* ms = SGX_CAST(ms_sgx_thread_set_untrusted_event_ocall_t*, pms);
	ms->ms_retval = sgx_thread_set_untrusted_event_ocall(ms->ms_waiter);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_sgx_thread_setwait_untrusted_events_ocall(void* pms)
{
	ms_sgx_thread_setwait_untrusted_events_ocall_t* ms = SGX_CAST(ms_sgx_thread_setwait_untrusted_events_ocall_t*, pms);
	ms->ms_retval = sgx_thread_setwait_untrusted_events_ocall(ms->ms_waiter, ms->ms_self);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_sgx_thread_set_multiple_untrusted_events_ocall(void* pms)
{
	ms_sgx_thread_set_multiple_untrusted_events_ocall_t* ms = SGX_CAST(ms_sgx_thread_set_multiple_untrusted_events_ocall_t*, pms);
	ms->ms_retval = sgx_thread_set_multiple_untrusted_events_ocall(ms->ms_waiters, ms->ms_total);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_create_session_ocall(void* pms)
{
	ms_create_session_ocall_t* ms = SGX_CAST(ms_create_session_ocall_t*, pms);
	ms->ms_retval = create_session_ocall(ms->ms_sid, ms->ms_dh_msg1, ms->ms_dh_msg1_size, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_exchange_report_ocall(void* pms)
{
	ms_exchange_report_ocall_t* ms = SGX_CAST(ms_exchange_report_ocall_t*, pms);
	ms->ms_retval = exchange_report_ocall(ms->ms_sid, ms->ms_dh_msg2, ms->ms_dh_msg2_size, ms->ms_dh_msg3, ms->ms_dh_msg3_size, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_close_session_ocall(void* pms)
{
	ms_close_session_ocall_t* ms = SGX_CAST(ms_close_session_ocall_t*, pms);
	ms->ms_retval = close_session_ocall(ms->ms_sid, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL enclave_invoke_service_ocall(void* pms)
{
	ms_invoke_service_ocall_t* ms = SGX_CAST(ms_invoke_service_ocall_t*, pms);
	ms->ms_retval = invoke_service_ocall(ms->ms_pse_message_req, ms->ms_pse_message_req_size, ms->ms_pse_message_resp, ms->ms_pse_message_resp_size, ms->ms_timeout);

	return SGX_SUCCESS;
}

static const struct {
	size_t nr_ocall;
	void * table[23];
} ocall_table_enclave = {
	23,
	{
		(void*)enclave_ocall_print,
		(void*)enclave_ocall_enclave_print,
		(void*)enclave_ocall_print_current_time,
		(void*)enclave_ocall_print_int,
		(void*)enclave_ocall_request_user_input,
		(void*)enclave_ocall_enclave_attestation_in_thread,
		(void*)enclave_ocall_network_request,
		(void*)enclave_ocall_add_identity_to_eid_dictionary,
		(void*)enclave_ocall_get_ip_address_of_current_host,
		(void*)enclave_ocall_get_port_of_current_host,
		(void*)enclave_ocall_get_ip_address_of_kps,
		(void*)enclave_ocall_get_attestation_port_of_kps,
		(void*)enclave_ocall_get_generic_port_of_kps,
		(void*)enclave_ocall_kill,
		(void*)enclave_sgx_oc_cpuidex,
		(void*)enclave_sgx_thread_wait_untrusted_event_ocall,
		(void*)enclave_sgx_thread_set_untrusted_event_ocall,
		(void*)enclave_sgx_thread_setwait_untrusted_events_ocall,
		(void*)enclave_sgx_thread_set_multiple_untrusted_events_ocall,
		(void*)enclave_create_session_ocall,
		(void*)enclave_exchange_report_ocall,
		(void*)enclave_close_session_ocall,
		(void*)enclave_invoke_service_ocall,
	}
};
sgx_status_t enclave_enclave_init_ra(sgx_enclave_id_t eid, sgx_status_t* retval, int b_pse, sgx_ra_context_t* p_context)
{
	sgx_status_t status;
	ms_enclave_init_ra_t ms;
	ms.ms_b_pse = b_pse;
	ms.ms_p_context = p_context;
	status = sgx_ecall(eid, 0, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_enclave_ra_close(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context)
{
	sgx_status_t status;
	ms_enclave_ra_close_t ms;
	ms.ms_context = context;
	status = sgx_ecall(eid, 1, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_verify_att_result_mac(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* message, size_t message_size, uint8_t* mac, size_t mac_size)
{
	sgx_status_t status;
	ms_verify_att_result_mac_t ms;
	ms.ms_context = context;
	ms.ms_message = message;
	ms.ms_message_size = message_size;
	ms.ms_mac = mac;
	ms.ms_mac_size = mac_size;
	status = sgx_ecall(eid, 2, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_put_secret_data(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* p_secret, uint32_t secret_size, uint8_t* gcm_mac)
{
	sgx_status_t status;
	ms_put_secret_data_t ms;
	ms.ms_context = context;
	ms.ms_p_secret = p_secret;
	ms.ms_secret_size = secret_size;
	ms.ms_gcm_mac = gcm_mac;
	status = sgx_ecall(eid, 3, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_encrypt_secure_message(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint8_t* return_encrypted_string, uint32_t requested_secret_size, uint8_t* return_payload_tag)
{
	sgx_status_t status;
	ms_encrypt_secure_message_t ms;
	ms.ms_context = context;
	ms.ms_return_encrypted_string = return_encrypted_string;
	ms.ms_requested_secret_size = requested_secret_size;
	ms.ms_return_payload_tag = return_payload_tag;
	status = sgx_ecall(eid, 4, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_decryptAndSendMessageAPI(sgx_enclave_id_t eid, int* retval, char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response, int isSecureSend, uint32_t ID_SIZE, uint32_t MAX_ENCRYPTED_MESSAGE, uint32_t MAX_RESPONSE_SIZE)
{
	sgx_status_t status;
	ms_decryptAndSendMessageAPI_t ms;
	ms.ms_requestingMachineIDKey = requestingMachineIDKey;
	ms.ms_receivingMachineIDKey = receivingMachineIDKey;
	ms.ms_iv = iv;
	ms.ms_mac = mac;
	ms.ms_encryptedMessage = encryptedMessage;
	ms.ms_response = response;
	ms.ms_isSecureSend = isSecureSend;
	ms.ms_ID_SIZE = ID_SIZE;
	ms.ms_MAX_ENCRYPTED_MESSAGE = MAX_ENCRYPTED_MESSAGE;
	ms.ms_MAX_RESPONSE_SIZE = MAX_RESPONSE_SIZE;
	status = sgx_ecall(eid, 5, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_sendUnencryptedMessageAPI(sgx_enclave_id_t eid, int* retval, char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response, int isSecureSend, uint32_t ID_SIZE, uint32_t MAX_ENCRYPTED_MESSAGE, uint32_t MAX_RESPONSE_SIZE)
{
	sgx_status_t status;
	ms_sendUnencryptedMessageAPI_t ms;
	ms.ms_requestingMachineIDKey = requestingMachineIDKey;
	ms.ms_receivingMachineIDKey = receivingMachineIDKey;
	ms.ms_iv = iv;
	ms.ms_mac = mac;
	ms.ms_encryptedMessage = encryptedMessage;
	ms.ms_response = response;
	ms.ms_isSecureSend = isSecureSend;
	ms.ms_ID_SIZE = ID_SIZE;
	ms.ms_MAX_ENCRYPTED_MESSAGE = MAX_ENCRYPTED_MESSAGE;
	ms.ms_MAX_RESPONSE_SIZE = MAX_RESPONSE_SIZE;
	status = sgx_ecall(eid, 6, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_createMachineAPI(sgx_enclave_id_t eid, int* retval, sgx_enclave_id_t currentEid, char* machineName, char* parentTrustedMachineID, char* returnNewMachineID, int numArgs, int payloadType, char* payload, int payloadSize, uint32_t ID_SIZE, uint32_t PAYLOAD_SIZE, sgx_enclave_id_t enclaveEid)
{
	sgx_status_t status;
	ms_createMachineAPI_t ms;
	ms.ms_currentEid = currentEid;
	ms.ms_machineName = machineName;
	ms.ms_parentTrustedMachineID = parentTrustedMachineID;
	ms.ms_returnNewMachineID = returnNewMachineID;
	ms.ms_numArgs = numArgs;
	ms.ms_payloadType = payloadType;
	ms.ms_payload = payload;
	ms.ms_payloadSize = payloadSize;
	ms.ms_ID_SIZE = ID_SIZE;
	ms.ms_PAYLOAD_SIZE = PAYLOAD_SIZE;
	ms.ms_enclaveEid = enclaveEid;
	status = sgx_ecall(eid, 7, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_initializeCommunicationAPI(sgx_enclave_id_t eid, int* retval, char* requestingMachineIDKey, char* receivingMachineIDKey, char* newSessionKey, char* returnMessage, uint32_t ID_SIZE, uint32_t SESSION_SIZE)
{
	sgx_status_t status;
	ms_initializeCommunicationAPI_t ms;
	ms.ms_requestingMachineIDKey = requestingMachineIDKey;
	ms.ms_receivingMachineIDKey = receivingMachineIDKey;
	ms.ms_newSessionKey = newSessionKey;
	ms.ms_returnMessage = returnMessage;
	ms.ms_ID_SIZE = ID_SIZE;
	ms.ms_SESSION_SIZE = SESSION_SIZE;
	status = sgx_ecall(eid, 8, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_verifySignatureEcall(sgx_enclave_id_t eid, int* retval, char* message, uint32_t MESSAGE_SIZE, char* signature, char* public_key, uint32_t SIZE_OF_SIGNATURE, uint32_t SIZE_OF_PUBLIC_KEY)
{
	sgx_status_t status;
	ms_verifySignatureEcall_t ms;
	ms.ms_message = message;
	ms.ms_MESSAGE_SIZE = MESSAGE_SIZE;
	ms.ms_signature = signature;
	ms.ms_public_key = public_key;
	ms.ms_SIZE_OF_SIGNATURE = SIZE_OF_SIGNATURE;
	ms.ms_SIZE_OF_PUBLIC_KEY = SIZE_OF_PUBLIC_KEY;
	status = sgx_ecall(eid, 9, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_signStringMessageEcall(sgx_enclave_id_t eid, char* message, int MESSAGE_SIZE, char* private_key, char* signature_out, uint32_t private_key_size, uint32_t signature_size)
{
	sgx_status_t status;
	ms_signStringMessageEcall_t ms;
	ms.ms_message = message;
	ms.ms_MESSAGE_SIZE = MESSAGE_SIZE;
	ms.ms_private_key = private_key;
	ms.ms_signature_out = signature_out;
	ms.ms_private_key_size = private_key_size;
	ms.ms_signature_size = signature_size;
	status = sgx_ecall(eid, 10, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_UntrustedCreateMachineAPI(sgx_enclave_id_t eid, sgx_enclave_id_t currentEid, char* machineTypeToCreate, int lengthString, char* returnNewMachinePublicID, int numArgs, int payloadType, char* payload, int payload_length, int output_length, int payload_size, sgx_enclave_id_t enclaveEid)
{
	sgx_status_t status;
	ms_UntrustedCreateMachineAPI_t ms;
	ms.ms_currentEid = currentEid;
	ms.ms_machineTypeToCreate = machineTypeToCreate;
	ms.ms_lengthString = lengthString;
	ms.ms_returnNewMachinePublicID = returnNewMachinePublicID;
	ms.ms_numArgs = numArgs;
	ms.ms_payloadType = payloadType;
	ms.ms_payload = payload;
	ms.ms_payload_length = payload_length;
	ms.ms_output_length = output_length;
	ms.ms_payload_size = payload_size;
	ms.ms_enclaveEid = enclaveEid;
	status = sgx_ecall(eid, 11, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_encryptMessageExternalPublicKeyEcall(sgx_enclave_id_t eid, char* message, size_t message_length_with_null_byte, char* other_party_public_key_raw, char* output_encrypted_message, char* other_party_public_key, uint32_t SIZE_OF_KEY_RAW, uint32_t SIZE_OF_KEY)
{
	sgx_status_t status;
	ms_encryptMessageExternalPublicKeyEcall_t ms;
	ms.ms_message = message;
	ms.ms_message_length_with_null_byte = message_length_with_null_byte;
	ms.ms_other_party_public_key_raw = other_party_public_key_raw;
	ms.ms_output_encrypted_message = output_encrypted_message;
	ms.ms_other_party_public_key = other_party_public_key;
	ms.ms_SIZE_OF_KEY_RAW = SIZE_OF_KEY_RAW;
	ms.ms_SIZE_OF_KEY = SIZE_OF_KEY;
	status = sgx_ecall(eid, 12, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_decryptMessageInteralPrivateKeyEcall(sgx_enclave_id_t eid, char* message, size_t message_length_with_null_byte, char* other_party_public_key_raw, char* output_encrypted_message, uint32_t SIZE_OF_KEY)
{
	sgx_status_t status;
	ms_decryptMessageInteralPrivateKeyEcall_t ms;
	ms.ms_message = message;
	ms.ms_message_length_with_null_byte = message_length_with_null_byte;
	ms.ms_other_party_public_key_raw = other_party_public_key_raw;
	ms.ms_output_encrypted_message = output_encrypted_message;
	ms.ms_SIZE_OF_KEY = SIZE_OF_KEY;
	status = sgx_ecall(eid, 13, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_createRsaKeyPairEcall(sgx_enclave_id_t eid, char* public_key_raw_out, char* private_key_raw_out, char* public_key_out, char* private_key_out, uint32_t KEY_SIZE)
{
	sgx_status_t status;
	ms_createRsaKeyPairEcall_t ms;
	ms.ms_public_key_raw_out = public_key_raw_out;
	ms.ms_private_key_raw_out = private_key_raw_out;
	ms.ms_public_key_out = public_key_out;
	ms.ms_private_key_out = private_key_out;
	ms.ms_KEY_SIZE = KEY_SIZE;
	status = sgx_ecall(eid, 14, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_eprint(sgx_enclave_id_t eid, char* printStr)
{
	sgx_status_t status;
	ms_eprint_t ms;
	ms.ms_printStr = printStr;
	status = sgx_ecall(eid, 15, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_read_rand_ecall(sgx_enclave_id_t eid, char* rand_buffer, uint32_t NUM_BYTES_RAND)
{
	sgx_status_t status;
	ms_sgx_read_rand_ecall_t ms;
	ms.ms_rand_buffer = rand_buffer;
	ms.ms_NUM_BYTES_RAND = NUM_BYTES_RAND;
	status = sgx_ecall(eid, 16, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_rijndael128GCM_decrypt_Ecall(sgx_enclave_id_t eid, const sgx_aes_gcm_128bit_key_t* p_key, const uint8_t* p_src, uint32_t src_len, uint8_t* p_dst, const uint8_t* p_iv, uint32_t iv_len, const uint8_t* p_aad, uint32_t aad_len, const sgx_aes_gcm_128bit_tag_t* p_in_mac)
{
	sgx_status_t status;
	ms_sgx_rijndael128GCM_decrypt_Ecall_t ms;
	ms.ms_p_key = p_key;
	ms.ms_p_src = p_src;
	ms.ms_src_len = src_len;
	ms.ms_p_dst = p_dst;
	ms.ms_p_iv = p_iv;
	ms.ms_iv_len = iv_len;
	ms.ms_p_aad = p_aad;
	ms.ms_aad_len = aad_len;
	ms.ms_p_in_mac = p_in_mac;
	status = sgx_ecall(eid, 17, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_rijndael128GCM_encrypt_Ecall(sgx_enclave_id_t eid, const sgx_aes_gcm_128bit_key_t* p_key, const uint8_t* p_src, uint32_t src_len, uint8_t* p_dst, const uint8_t* p_iv, uint32_t iv_len, const uint8_t* p_aad, uint32_t aad_len, sgx_aes_gcm_128bit_tag_t* p_out_mac)
{
	sgx_status_t status;
	ms_sgx_rijndael128GCM_encrypt_Ecall_t ms;
	ms.ms_p_key = p_key;
	ms.ms_p_src = p_src;
	ms.ms_src_len = src_len;
	ms.ms_p_dst = p_dst;
	ms.ms_p_iv = p_iv;
	ms.ms_iv_len = iv_len;
	ms.ms_p_aad = p_aad;
	ms.ms_aad_len = aad_len;
	ms.ms_p_out_mac = p_out_mac;
	status = sgx_ecall(eid, 18, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_rijndael128_cmac_msg_Ecall(sgx_enclave_id_t eid, const sgx_cmac_128bit_key_t* p_key, const uint8_t* p_src, uint32_t src_len, sgx_cmac_128bit_tag_t* p_mac)
{
	sgx_status_t status;
	ms_sgx_rijndael128_cmac_msg_Ecall_t ms;
	ms.ms_p_key = p_key;
	ms.ms_p_src = p_src;
	ms.ms_src_len = src_len;
	ms.ms_p_mac = p_mac;
	status = sgx_ecall(eid, 19, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_ecc256_open_context_Ecall(sgx_enclave_id_t eid, sgx_ecc_state_handle_t* ecc_handle)
{
	sgx_status_t status;
	ms_sgx_ecc256_open_context_Ecall_t ms;
	ms.ms_ecc_handle = ecc_handle;
	status = sgx_ecall(eid, 20, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_ecc256_close_context_Ecall(sgx_enclave_id_t eid, sgx_ecc_state_handle_t ecc_handle)
{
	sgx_status_t status;
	ms_sgx_ecc256_close_context_Ecall_t ms;
	ms.ms_ecc_handle = ecc_handle;
	status = sgx_ecall(eid, 21, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_ecc256_create_key_pair_Ecall(sgx_enclave_id_t eid, sgx_ec256_private_t* p_private, sgx_ec256_public_t* p_public, sgx_ecc_state_handle_t ecc_handle)
{
	sgx_status_t status;
	ms_sgx_ecc256_create_key_pair_Ecall_t ms;
	ms.ms_p_private = p_private;
	ms.ms_p_public = p_public;
	ms.ms_ecc_handle = ecc_handle;
	status = sgx_ecall(eid, 22, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_ecc256_compute_shared_dhkey_Ecall(sgx_enclave_id_t eid, sgx_ec256_private_t* p_private_b, sgx_ec256_public_t* p_public_ga, sgx_ec256_dh_shared_t* p_shared_key, sgx_ecc_state_handle_t ecc_handle)
{
	sgx_status_t status;
	ms_sgx_ecc256_compute_shared_dhkey_Ecall_t ms;
	ms.ms_p_private_b = p_private_b;
	ms.ms_p_public_ga = p_public_ga;
	ms.ms_p_shared_key = p_shared_key;
	ms.ms_ecc_handle = ecc_handle;
	status = sgx_ecall(eid, 23, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_ecdsa_sign_Ecall(sgx_enclave_id_t eid, const uint8_t* p_data, uint32_t data_size, sgx_ec256_private_t* p_private, sgx_ec256_signature_t* p_signature, sgx_ecc_state_handle_t ecc_handle)
{
	sgx_status_t status;
	ms_sgx_ecdsa_sign_Ecall_t ms;
	ms.ms_p_data = p_data;
	ms.ms_data_size = data_size;
	ms.ms_p_private = p_private;
	ms.ms_p_signature = p_signature;
	ms.ms_ecc_handle = ecc_handle;
	status = sgx_ecall(eid, 24, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_sha256_init_Ecall(sgx_enclave_id_t eid, sgx_sha_state_handle_t* ecc_handle)
{
	sgx_status_t status;
	ms_sgx_sha256_init_Ecall_t ms;
	ms.ms_ecc_handle = ecc_handle;
	status = sgx_ecall(eid, 25, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_sha256_update_Ecall(sgx_enclave_id_t eid, const uint8_t* p_src, uint32_t src_len, sgx_sha_state_handle_t sha_handle)
{
	sgx_status_t status;
	ms_sgx_sha256_update_Ecall_t ms;
	ms.ms_p_src = p_src;
	ms.ms_src_len = src_len;
	ms.ms_sha_handle = sha_handle;
	status = sgx_ecall(eid, 26, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_sha256_get_hash_Ecall(sgx_enclave_id_t eid, sgx_sha_state_handle_t sha_handle, sgx_sha256_hash_t* p_hash)
{
	sgx_status_t status;
	ms_sgx_sha256_get_hash_Ecall_t ms;
	ms.ms_sha_handle = sha_handle;
	ms.ms_p_hash = p_hash;
	status = sgx_ecall(eid, 27, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_sgx_sha256_close_Ecall(sgx_enclave_id_t eid, sgx_sha_state_handle_t sha_handle)
{
	sgx_status_t status;
	ms_sgx_sha256_close_Ecall_t ms;
	ms.ms_sha_handle = sha_handle;
	status = sgx_ecall(eid, 28, &ocall_table_enclave, &ms);
	return status;
}

sgx_status_t enclave_ecall_create_report(sgx_enclave_id_t eid, int* retval, sgx_target_info_t* quote_enc_info, sgx_report_t* report)
{
	sgx_status_t status;
	ms_ecall_create_report_t ms;
	ms.ms_quote_enc_info = quote_enc_info;
	ms.ms_report = report;
	status = sgx_ecall(eid, 29, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_ecall_validate_SSM_type_hosted_by_this_enclave(sgx_enclave_id_t eid, int* retval, char* SSMTypeQuery, int SSMTypeStringLength)
{
	sgx_status_t status;
	ms_ecall_validate_SSM_type_hosted_by_this_enclave_t ms;
	ms.ms_SSMTypeQuery = SSMTypeQuery;
	ms.ms_SSMTypeStringLength = SSMTypeStringLength;
	status = sgx_ecall(eid, 30, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_sgx_ra_get_ga(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, sgx_ec256_public_t* g_a)
{
	sgx_status_t status;
	ms_sgx_ra_get_ga_t ms;
	ms.ms_context = context;
	ms.ms_g_a = g_a;
	status = sgx_ecall(eid, 31, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_sgx_ra_proc_msg2_trusted(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, const sgx_ra_msg2_t* p_msg2, const sgx_target_info_t* p_qe_target, sgx_report_t* p_report, sgx_quote_nonce_t* p_nonce)
{
	sgx_status_t status;
	ms_sgx_ra_proc_msg2_trusted_t ms;
	ms.ms_context = context;
	ms.ms_p_msg2 = p_msg2;
	ms.ms_p_qe_target = p_qe_target;
	ms.ms_p_report = p_report;
	ms.ms_p_nonce = p_nonce;
	status = sgx_ecall(eid, 32, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t enclave_sgx_ra_get_msg3_trusted(sgx_enclave_id_t eid, sgx_status_t* retval, sgx_ra_context_t context, uint32_t quote_size, sgx_report_t* qe_report, sgx_ra_msg3_t* p_msg3, uint32_t msg3_size)
{
	sgx_status_t status;
	ms_sgx_ra_get_msg3_trusted_t ms;
	ms.ms_context = context;
	ms.ms_quote_size = quote_size;
	ms.ms_qe_report = qe_report;
	ms.ms_p_msg3 = p_msg3;
	ms.ms_msg3_size = msg3_size;
	status = sgx_ecall(eid, 33, &ocall_table_enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}


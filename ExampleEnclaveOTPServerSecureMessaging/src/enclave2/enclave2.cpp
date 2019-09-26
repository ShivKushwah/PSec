#include "enclave2_t.h"
#include <sgx_thread.h>
#include <string.h>

#include "Utility_E1.h"

//NOTE: Change not persisted in other file
char* secret_string = (char*) malloc(20);

int atoi(char *p) {
    int k = 0;
    while (*p) {
        k = (k << 3) + (k << 1) + (*p) - '0';
        p++;
     }
     return k;
}


int generate_random_number() {
    ocall_print("Processing random number generation...");
    return 42;
}

int generate_OTP_code() {
    return atoi(secret_string) + 1;
}

// Enclave Message Exchange
/*
 * Copyright (C) 2011-2019 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#include "sgx_trts.h"
#include "sgx_utils.h"
//#include "EnclaveMessageExchange.h"
#include "sgx_eid.h"
#include "error_codes.h"
#include "sgx_ecp_types.h"
#include "sgx_thread.h"
#include <string.h>

//#include <map>
#include "dh_session_protocol.h"
#include "sgx_dh.h"
#include "sgx_tcrypto.h"
//#include "LocalAttestationCode_t.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32_t enclave_to_enclave_call_dispatcher(char* decrypted_data, size_t decrypted_data_length, char** resp_buffer, size_t* resp_length);
uint32_t message_exchange_response_generator(char* decrypted_data, char** resp_buffer, size_t* resp_length);
uint32_t verify_peer_enclave_trust(sgx_dh_session_enclave_identity_t* peer_enclave_identity);

#ifdef __cplusplus
}
#endif

#define MAX_SESSION_COUNT  16

//number of open sessions
uint32_t g_session_count = 0;

ATTESTATION_STATUS generate_session_id(uint32_t *session_id);

//Array of open session ids
session_id_tracker_t *g_session_id_tracker[MAX_SESSION_COUNT];

//Map between the source enclave id and the session information associated with that particular session
//std::map<sgx_enclave_id_t, dh_session_t>g_dest_session_info_map;
sgx_enclave_id_t source_enclave_id;
dh_session_t source_session_t;

//Close a current session
ATTESTATION_STATUS close_session_enclave2(sgx_enclave_id_t src_enclave_id,
                        sgx_enclave_id_t dest_enclave_id)
{
    sgx_status_t status;

    uint32_t retstatus;

    //Ocall to ask the destination enclave to end the session
    status = end_session_ocall(&retstatus, src_enclave_id, dest_enclave_id);
    if (status == SGX_SUCCESS)
    {
        if ((ATTESTATION_STATUS)retstatus != SUCCESS)
            return ((ATTESTATION_STATUS)retstatus);
    }
    else
    {
        return ATTESTATION_SE_ERROR;
    }
    return SUCCESS;
}

//Create a session with the destination enclave
ATTESTATION_STATUS create_session(sgx_enclave_id_t src_enclave_id,
                         sgx_enclave_id_t dest_enclave_id,
                         dh_session_t *session_info)
{
    sgx_dh_msg1_t dh_msg1;            //Diffie-Hellman Message 1
    sgx_key_128bit_t dh_aek;        // Session Key
    sgx_dh_msg2_t dh_msg2;            //Diffie-Hellman Message 2
    sgx_dh_msg3_t dh_msg3;            //Diffie-Hellman Message 3
    uint32_t session_id;
    uint32_t retstatus;
    sgx_status_t status = SGX_SUCCESS;
    sgx_dh_session_t sgx_dh_session;
    sgx_dh_session_enclave_identity_t responder_identity;

    if(!session_info)
    {
        return INVALID_PARAMETER_ERROR;
    }

    memset(&dh_aek,0, sizeof(sgx_key_128bit_t));
    memset(&dh_msg1, 0, sizeof(sgx_dh_msg1_t));
    memset(&dh_msg2, 0, sizeof(sgx_dh_msg2_t));
    memset(&dh_msg3, 0, sizeof(sgx_dh_msg3_t));
    memset(session_info, 0, sizeof(dh_session_t));

    //Intialize the session as a session initiator
    status = sgx_dh_init_session(SGX_DH_SESSION_INITIATOR, &sgx_dh_session);
    if(SGX_SUCCESS != status)
    {
            return status;
    }
    
    //Ocall to request for a session with the destination enclave and obtain session id and Message 1 if successful
    status = session_request_ocall(&retstatus, src_enclave_id, dest_enclave_id, &dh_msg1, &session_id);
    if (status == SGX_SUCCESS)
    {
        if ((ATTESTATION_STATUS)retstatus != SUCCESS)
            return ((ATTESTATION_STATUS)retstatus);
    }
    else
    {
        return ATTESTATION_SE_ERROR;
    }
    //Process the message 1 obtained from desination enclave and generate message 2
    status = sgx_dh_initiator_proc_msg1(&dh_msg1, &dh_msg2, &sgx_dh_session);
    if(SGX_SUCCESS != status)
    {
         return status;
    }

    //Send Message 2 to Destination Enclave and get Message 3 in return
    status = exchange_report_ocall(&retstatus, src_enclave_id, dest_enclave_id, &dh_msg2, &dh_msg3, session_id);
    if (status == SGX_SUCCESS)
    {
        if ((ATTESTATION_STATUS)retstatus != SUCCESS)
            return ((ATTESTATION_STATUS)retstatus);
    }
    else
    {
        return ATTESTATION_SE_ERROR;
    }

    //Process Message 3 obtained from the destination enclave
    status = sgx_dh_initiator_proc_msg3(&dh_msg3, &sgx_dh_session, &dh_aek, &responder_identity);
    if(SGX_SUCCESS != status)
    {
        return status;
    }

    // Verify the identity of the destination enclave
    if(verify_peer_enclave_trust(&responder_identity) != SUCCESS)
    {
        return INVALID_SESSION;
    }

    memcpy(session_info->active.AEK, &dh_aek, sizeof(sgx_key_128bit_t));
    session_info->session_id = session_id;
    session_info->active.counter = 0;
    session_info->status = ACTIVE;
    memset(&dh_aek,0, sizeof(sgx_key_128bit_t));
    return status;
}

//Handle the request from Source Enclave for a session
ATTESTATION_STATUS session_request_enclave2(sgx_enclave_id_t src_enclave_id,
                          sgx_dh_msg1_t *dh_msg1,
                          uint32_t *session_id )
{
    dh_session_t session_info;
    sgx_dh_session_t sgx_dh_session;
    sgx_status_t status = SGX_SUCCESS;

    if(!session_id || !dh_msg1)
    {
        return INVALID_PARAMETER_ERROR;
    }
    //Intialize the session as a session responder
    status = sgx_dh_init_session(SGX_DH_SESSION_RESPONDER, &sgx_dh_session);
    if(SGX_SUCCESS != status)
    {
        return status;
    }
    
    //get a new SessionID
    if ((status = (sgx_status_t)generate_session_id(session_id)) != SUCCESS)
        return status; //no more sessions available

    //Allocate memory for the session id tracker
    g_session_id_tracker[*session_id] = (session_id_tracker_t *)malloc(sizeof(session_id_tracker_t));
    if(!g_session_id_tracker[*session_id])
    {
        return MALLOC_ERROR;
    }

    memset(g_session_id_tracker[*session_id], 0, sizeof(session_id_tracker_t));
    g_session_id_tracker[*session_id]->session_id = *session_id;
    session_info.status = IN_PROGRESS;

    //Generate Message1 that will be returned to Source Enclave
    status = sgx_dh_responder_gen_msg1((sgx_dh_msg1_t*)dh_msg1, &sgx_dh_session);
    if(SGX_SUCCESS != status)
    {
        SAFE_FREE(g_session_id_tracker[*session_id]);
        return status;
    }
    memcpy(&session_info.in_progress.dh_session, &sgx_dh_session, sizeof(sgx_dh_session_t));
    //Store the session information under the correspoding source enlave id key
    source_enclave_id = src_enclave_id;
    source_session_t = session_info;
    //g_dest_session_info_map.insert(std::pair<sgx_enclave_id_t, dh_session_t>(, ));
    
    return status;
}

//Verify Message 2, generate Message3 and exchange Message 3 with Source Enclave
ATTESTATION_STATUS exchange_report_enclave2(sgx_enclave_id_t src_enclave_id,
                          sgx_dh_msg2_t *dh_msg2,
                          sgx_dh_msg3_t *dh_msg3,
                          uint32_t session_id)
{

    sgx_key_128bit_t dh_aek;   // Session key
    dh_session_t *session_info;
    ATTESTATION_STATUS status = SUCCESS;
    sgx_dh_session_t sgx_dh_session;
    sgx_dh_session_enclave_identity_t initiator_identity;

    if(!dh_msg2 || !dh_msg3)
    {
        return INVALID_PARAMETER_ERROR;
    }

    memset(&dh_aek,0, sizeof(sgx_key_128bit_t));
    do
    {
        //Retreive the session information for the corresponding source enclave id
        if (src_enclave_id == source_enclave_id) {
            session_info = (dh_session_t*) &source_session_t;

        } else {
            status = INVALID_SESSION;
            break; 
        }
        // std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_dest_session_info_map.find(src_enclave_id);
        // if(it != g_dest_session_info_map.end())
        // {
        // }
        // else
        // {
            
        // }

        if(session_info->status != IN_PROGRESS)
        {
            status = INVALID_SESSION;
            break;
        }

        memcpy(&sgx_dh_session, &session_info->in_progress.dh_session, sizeof(sgx_dh_session_t));

        dh_msg3->msg3_body.additional_prop_length = 0;
        //Process message 2 from source enclave and obtain message 3
        sgx_status_t se_ret = sgx_dh_responder_proc_msg2(dh_msg2, 
                                                       dh_msg3, 
                                                       &sgx_dh_session, 
                                                       &dh_aek, 
                                                       &initiator_identity);
        if(SGX_SUCCESS != se_ret)
        {
            status = se_ret;
            break;
        }

        //Verify source enclave's trust
          if(verify_peer_enclave_trust(&initiator_identity) != SUCCESS)
        {
            return INVALID_SESSION;
        }

        //save the session ID, status and initialize the session nonce
        session_info->session_id = session_id;
        session_info->status = ACTIVE;
        session_info->active.counter = 0;
        memcpy(session_info->active.AEK, &dh_aek, sizeof(sgx_key_128bit_t));
        memset(&dh_aek,0, sizeof(sgx_key_128bit_t));
        g_session_count++;
    }while(0);

    if(status != SUCCESS)
    {
        end_session_enclave2(src_enclave_id);
    }

    return status;
}

//Request for the response size, send the request message to the destination enclave and receive the response message back
ATTESTATION_STATUS send_request_receive_response(sgx_enclave_id_t src_enclave_id,
                                  sgx_enclave_id_t dest_enclave_id,
                                  dh_session_t *session_info,
                                  char *inp_buff,
                                  size_t inp_buff_len,
                                  size_t max_out_buff_size,
                                  char **out_buff,
                                  size_t* out_buff_len)
{
    const uint8_t* plaintext;
    uint32_t plaintext_length;
    sgx_status_t status;
    uint32_t retstatus;
    secure_message_t* req_message;
    secure_message_t* resp_message;
    uint8_t *decrypted_data;
    uint32_t decrypted_data_length;
    uint32_t plain_text_offset;
    uint8_t l_tag[TAG_SIZE];
    size_t max_resp_message_length;
    plaintext = (const uint8_t*)(" ");
    plaintext_length = 0;

    if(!session_info || !inp_buff)
    {
        return INVALID_PARAMETER_ERROR;
    }
    //Check if the nonce for the session has not exceeded 2^32-2 if so end session and start a new session
    if(session_info->active.counter == ((uint32_t) - 2))
    {
        close_session_enclave2(src_enclave_id, dest_enclave_id);
        create_session(src_enclave_id, dest_enclave_id, session_info);
    }

    //Allocate memory for the AES-GCM request message
    req_message = (secure_message_t*)malloc(sizeof(secure_message_t)+ inp_buff_len);
    if(!req_message)
    {
        return MALLOC_ERROR;
    }

    memset(req_message,0,sizeof(secure_message_t)+ inp_buff_len);
    const uint32_t data2encrypt_length = (uint32_t)inp_buff_len;
    //Set the payload size to data to encrypt length
    req_message->message_aes_gcm_data.payload_size = data2encrypt_length;

    //Use the session nonce as the payload IV
    memcpy(req_message->message_aes_gcm_data.reserved,&session_info->active.counter,sizeof(session_info->active.counter));

    //Set the session ID of the message to the current session id
    req_message->session_id = session_info->session_id;

    //Prepare the request message with the encrypted payload
    status = sgx_rijndael128GCM_encrypt(&session_info->active.AEK, (uint8_t*)inp_buff, data2encrypt_length,
                (uint8_t *) (&(req_message->message_aes_gcm_data.payload)),
                (uint8_t *)(&(req_message->message_aes_gcm_data.reserved)),
                sizeof(req_message->message_aes_gcm_data.reserved), plaintext, plaintext_length, 
                &(req_message->message_aes_gcm_data.payload_tag));

    if(SGX_SUCCESS != status)
    {
        SAFE_FREE(req_message);
        return status;
    }
    
    //Allocate memory for the response payload to be copied
    *out_buff = (char*)malloc(max_out_buff_size);
    if(!*out_buff)
    {
        SAFE_FREE(req_message);
        return MALLOC_ERROR;
    }

    memset(*out_buff, 0, max_out_buff_size);

    //Allocate memory for the response message
    resp_message = (secure_message_t*)malloc(sizeof(secure_message_t)+ max_out_buff_size);
    if(!resp_message)
    {
        SAFE_FREE(req_message);
        return MALLOC_ERROR;
    }

    memset(resp_message, 0, sizeof(secure_message_t)+ max_out_buff_size);

    //Ocall to send the request to the Destination Enclave and get the response message back
    status = send_request_ocall(&retstatus, src_enclave_id, dest_enclave_id, req_message,
                                (sizeof(secure_message_t)+ inp_buff_len), max_out_buff_size,
                                resp_message, (sizeof(secure_message_t)+ max_out_buff_size));
    if (status == SGX_SUCCESS)
    {
        if ((ATTESTATION_STATUS)retstatus != SUCCESS)
        {
            SAFE_FREE(req_message);
            SAFE_FREE(resp_message);
            return ((ATTESTATION_STATUS)retstatus);
        }
    }
    else
    {
        SAFE_FREE(req_message);
        SAFE_FREE(resp_message);
        return ATTESTATION_SE_ERROR;
    }

    max_resp_message_length = sizeof(secure_message_t)+ max_out_buff_size;

    if(sizeof(resp_message) > max_resp_message_length)
    {
        SAFE_FREE(req_message);
        SAFE_FREE(resp_message);
        return INVALID_PARAMETER_ERROR;
    }

    //Code to process the response message from the Destination Enclave

    decrypted_data_length = resp_message->message_aes_gcm_data.payload_size;
    plain_text_offset = decrypted_data_length;
    decrypted_data = (uint8_t*)malloc(decrypted_data_length);
    if(!decrypted_data)
    {
        SAFE_FREE(req_message);
        SAFE_FREE(resp_message);
        return MALLOC_ERROR;
    }
    memset(&l_tag, 0, 16);

    memset(decrypted_data, 0, decrypted_data_length);

    //Decrypt the response message payload
    status = sgx_rijndael128GCM_decrypt(&session_info->active.AEK, resp_message->message_aes_gcm_data.payload, 
                decrypted_data_length, decrypted_data,
                (uint8_t *)(&(resp_message->message_aes_gcm_data.reserved)),
                sizeof(resp_message->message_aes_gcm_data.reserved), &(resp_message->message_aes_gcm_data.payload[plain_text_offset]), plaintext_length, 
                &resp_message->message_aes_gcm_data.payload_tag);
    
    if(SGX_SUCCESS != status)
    {
        SAFE_FREE(req_message);
        SAFE_FREE(decrypted_data);
        SAFE_FREE(resp_message);
        return status;
    }

    // Verify if the nonce obtained in the response is equal to the session nonce + 1 (Prevents replay attacks)
    if(*(resp_message->message_aes_gcm_data.reserved) != (session_info->active.counter + 1 ))
    {
        SAFE_FREE(req_message);
        SAFE_FREE(resp_message);
        SAFE_FREE(decrypted_data);
        return INVALID_PARAMETER_ERROR;
    }

        //Update the value of the session nonce in the source enclave
    session_info->active.counter = session_info->active.counter + 1;

    memcpy(out_buff_len, &decrypted_data_length, sizeof(decrypted_data_length));
    memcpy(*out_buff, decrypted_data, decrypted_data_length);

    SAFE_FREE(decrypted_data);
    SAFE_FREE(req_message);
    SAFE_FREE(resp_message);
    return SUCCESS;


}

//Process the request from the Source enclave and send the response message back to the Source enclave
ATTESTATION_STATUS generate_response_enclave2(sgx_enclave_id_t src_enclave_id,
                                     secure_message_t* req_message,
                                     size_t req_message_size,
                                     size_t max_payload_size,
                                     secure_message_t* resp_message,
                                     size_t resp_message_size)
{
    const uint8_t* plaintext;
    uint32_t plaintext_length;
    uint8_t *decrypted_data;
    uint32_t decrypted_data_length;
    uint32_t plain_text_offset;
    ms_in_msg_exchange_t * ms;
    size_t resp_data_length;
    size_t resp_message_calc_size;
    char* resp_data;
    uint8_t l_tag[TAG_SIZE];
    size_t header_size, expected_payload_size;
    dh_session_t *session_info;
    secure_message_t* temp_resp_message;
    uint32_t ret;
    sgx_status_t status;

    plaintext = (const uint8_t*)(" ");
    plaintext_length = 0;

    if(!req_message || !resp_message)
    {
        return INVALID_PARAMETER_ERROR;
    }

    if (src_enclave_id == source_enclave_id) {
            session_info = (dh_session_t*)&source_session_t;

        } else {
            return INVALID_SESSION;
        }

    //Get the session information from the map corresponding to the source enclave id
    // std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_dest_session_info_map.find(src_enclave_id);
    // if(it != g_dest_session_info_map.end())
    // {
    //     session_info = &it->second;
    // }
    // else
    // {
    //     return INVALID_SESSION;
    // }

    if(session_info->status != ACTIVE)
    {
        return INVALID_SESSION;
    }

    //Set the decrypted data length to the payload size obtained from the message
    decrypted_data_length = req_message->message_aes_gcm_data.payload_size;

    header_size = sizeof(secure_message_t);
    expected_payload_size = req_message_size - header_size;

    //Verify the size of the payload
    if(expected_payload_size != decrypted_data_length)
        return INVALID_PARAMETER_ERROR;

    memset(&l_tag, 0, 16);
    plain_text_offset = decrypted_data_length;
    decrypted_data = (uint8_t*)malloc(decrypted_data_length);
    if(!decrypted_data)
    {
            return MALLOC_ERROR;
    }

    memset(decrypted_data, 0, decrypted_data_length);

    //Decrypt the request message payload from source enclave
    status = sgx_rijndael128GCM_decrypt(&session_info->active.AEK, req_message->message_aes_gcm_data.payload, 
                decrypted_data_length, decrypted_data,
                (uint8_t *)(&(req_message->message_aes_gcm_data.reserved)),
                sizeof(req_message->message_aes_gcm_data.reserved), &(req_message->message_aes_gcm_data.payload[plain_text_offset]), plaintext_length, 
                &req_message->message_aes_gcm_data.payload_tag);

    if(SGX_SUCCESS != status)
    {
        SAFE_FREE(decrypted_data);
        return status;
    }

    //Casting the decrypted data to the marshaling structure type to obtain type of request (generic message exchange/enclave to enclave call)
    ms = (ms_in_msg_exchange_t *)decrypted_data;


    // Verify if the nonce obtained in the request is equal to the session nonce
    if((uint32_t)*(req_message->message_aes_gcm_data.reserved) != session_info->active.counter || *(req_message->message_aes_gcm_data.reserved) > ((2^32)-2))
    {
        SAFE_FREE(decrypted_data);
        return INVALID_PARAMETER_ERROR;
    }

    if(ms->msg_type == MESSAGE_EXCHANGE)
    {
        //Call the generic secret response generator for message exchange
        ret = message_exchange_response_generator((char*)decrypted_data, &resp_data, &resp_data_length);
        if(ret !=0)
        {
            SAFE_FREE(decrypted_data);
            SAFE_FREE(resp_data);
            return INVALID_SESSION;
        }
    }
    else if(ms->msg_type == ENCLAVE_TO_ENCLAVE_CALL)
    {
        //Call the destination enclave's dispatcher to call the appropriate function in the destination enclave
        ret = enclave_to_enclave_call_dispatcher((char*)decrypted_data, decrypted_data_length, &resp_data, &resp_data_length);
        if(ret !=0)
        {
            SAFE_FREE(decrypted_data);
            SAFE_FREE(resp_data);
            return INVALID_SESSION;
        }
    }
    else
    {
        SAFE_FREE(decrypted_data);
        return INVALID_REQUEST_TYPE_ERROR;
    }
    

    if(resp_data_length > max_payload_size)
    {
        SAFE_FREE(resp_data);
        SAFE_FREE(decrypted_data);
        return OUT_BUFFER_LENGTH_ERROR;
    }

    resp_message_calc_size = sizeof(secure_message_t)+ resp_data_length;

    if(resp_message_calc_size > resp_message_size)
    {
        SAFE_FREE(resp_data);
        SAFE_FREE(decrypted_data);
        return OUT_BUFFER_LENGTH_ERROR;
    }

    //Code to build the response back to the Source Enclave
    temp_resp_message = (secure_message_t*)malloc(resp_message_calc_size);
    if(!temp_resp_message)
    {
            SAFE_FREE(resp_data);
            SAFE_FREE(decrypted_data);
            return MALLOC_ERROR;
    }

    memset(temp_resp_message,0,sizeof(secure_message_t)+ resp_data_length);
    const uint32_t data2encrypt_length = (uint32_t)resp_data_length;
    temp_resp_message->session_id = session_info->session_id;
    temp_resp_message->message_aes_gcm_data.payload_size = data2encrypt_length;

    //Increment the Session Nonce (Replay Protection)
    session_info->active.counter = session_info->active.counter + 1;

    //Set the response nonce as the session nonce
    memcpy(&temp_resp_message->message_aes_gcm_data.reserved,&session_info->active.counter,sizeof(session_info->active.counter));

    //Prepare the response message with the encrypted payload
    status = sgx_rijndael128GCM_encrypt(&session_info->active.AEK, (uint8_t*)resp_data, data2encrypt_length,
                (uint8_t *)(&(temp_resp_message->message_aes_gcm_data.payload)),
                (uint8_t *)(&(temp_resp_message->message_aes_gcm_data.reserved)),
                sizeof(temp_resp_message->message_aes_gcm_data.reserved), plaintext, plaintext_length, 
                &(temp_resp_message->message_aes_gcm_data.payload_tag));

    if(SGX_SUCCESS != status)
    {
        SAFE_FREE(resp_data);
        SAFE_FREE(decrypted_data);
        SAFE_FREE(temp_resp_message);
        return status;
    }

    memset(resp_message, 0, sizeof(secure_message_t)+ resp_data_length);
    memcpy(resp_message, temp_resp_message, sizeof(secure_message_t)+ resp_data_length);

    SAFE_FREE(decrypted_data);
    SAFE_FREE(resp_data);
    SAFE_FREE(temp_resp_message);

    return SUCCESS;
}



//Respond to the request from the Source Enclave to close the session
ATTESTATION_STATUS end_session_enclave2(sgx_enclave_id_t src_enclave_id)
{
    ATTESTATION_STATUS status = SUCCESS;
    int i;
    dh_session_t session_info;
    uint32_t session_id;

    if (src_enclave_id == source_enclave_id) {
            session_info = source_session_t;

        } else {
            status = INVALID_SESSION;
        }

    // //Get the session information from the map corresponding to the source enclave id
    // std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_dest_session_info_map.find(src_enclave_id);
    // if(it != g_dest_session_info_map.end())
    // {
    //     session_info = it->second;
    // }
    // else
    // {
    //     return INVALID_SESSION;
    // }

    session_id = session_info.session_id;
    //Erase the session information for the current session
    source_enclave_id = 0;
    //g_dest_session_info_map.erase(src_enclave_id);

    //Update the session id tracker
    if (g_session_count > 0)
    {
        //check if session exists
        for (i=1; i <= MAX_SESSION_COUNT; i++)
        {
            if(g_session_id_tracker[i-1] != NULL && g_session_id_tracker[i-1]->session_id == session_id)
            {
                memset(g_session_id_tracker[i-1], 0, sizeof(session_id_tracker_t));
                SAFE_FREE(g_session_id_tracker[i-1]);
                g_session_count--;
                break;
            }
        }
    }

    return status;

}


//Returns a new sessionID for the source destination session
ATTESTATION_STATUS generate_session_id(uint32_t *session_id)
{
    ATTESTATION_STATUS status = SUCCESS;

    if(!session_id)
    {
        return INVALID_PARAMETER_ERROR;
    }
    //if the session structure is untintialized, set that as the next session ID
    for (int i = 0; i < MAX_SESSION_COUNT; i++)
    {
        if (g_session_id_tracker[i] == NULL)
        {
            *session_id = i;
            return status;
        }
    }

    status = NO_AVAILABLE_SESSION_ERROR;

    return status;

}



//------------ enclave1.cpp


#define UNUSED(val) (void)(val)

//std::map<sgx_enclave_id_t, dh_session_t>g_src_session_info_map;
sgx_enclave_id_t destination_enclave_id;
dh_session_t destination_enclave_session;

static uint32_t e1_foo1_wrapper(ms_in_msg_exchange_t *ms, size_t param_lenth, char** resp_buffer, size_t* resp_length);

//Function pointer table containing the list of functions that the enclave exposes
const struct {
    size_t num_funcs;
    const void* table[1];
} func_table = {
    1,
    {
        (const void*)e1_foo1_wrapper,
    }
};

//Makes use of the sample code function to establish a secure channel with the destination enclave (Test Vector)
uint32_t test_create_session_enclave2(sgx_enclave_id_t src_enclave_id,
                         sgx_enclave_id_t dest_enclave_id)
{
    ATTESTATION_STATUS ke_status = SUCCESS;
    dh_session_t dest_session_info;

    //Core reference code function for creating a session
    ke_status = create_session(src_enclave_id, dest_enclave_id, &dest_session_info);

    //Insert the session information into the map under the corresponding destination enclave id
    if(ke_status == SUCCESS)
    {
        destination_enclave_id = dest_enclave_id;
        destination_enclave_session =dest_session_info;
        // g_src_session_info_map.insert(std::pair<sgx_enclave_id_t, dh_session_t>(dest_enclave_id, dest_session_info));
    }
    memset(&dest_session_info, 0, sizeof(dh_session_t));
    return ke_status;
}

//Makes use of the sample code function to do an enclave to enclave call (Test Vector)
uint32_t test_enclave_to_enclave_call_enclave2(sgx_enclave_id_t src_enclave_id,
                                          sgx_enclave_id_t dest_enclave_id)
{
    ATTESTATION_STATUS ke_status = SUCCESS;
    uint32_t var1,var2;
    uint32_t target_fn_id, msg_type;
    char* marshalled_inp_buff;
    size_t marshalled_inp_buff_len;
    char* out_buff;
    size_t out_buff_len;
    dh_session_t *dest_session_info;
    size_t max_out_buff_size;
    char* retval;

    var1 = 0x4;
    var2 = 0x5;
    target_fn_id = 0;
    msg_type = ENCLAVE_TO_ENCLAVE_CALL;
    max_out_buff_size = 50;

    //Marshals the input parameters for calling function foo1 in Enclave2 into a input buffer
    ke_status = marshal_input_parameters_e2_foo1(target_fn_id, msg_type, var1, var2, &marshalled_inp_buff, &marshalled_inp_buff_len);
    if(ke_status != SUCCESS)
    {
        return ke_status;
    }

    if (destination_enclave_id == dest_enclave_id) {
        dest_session_info = &destination_enclave_session;

    } else {
        SAFE_FREE(marshalled_inp_buff);
        return INVALID_SESSION;
    }

    // //Search the map for the session information associated with the destination enclave id of Enclave2 passed in
    // std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_src_session_info_map.find(dest_enclave_id);
    // if(it != g_src_session_info_map.end())
    // {
    //       dest_session_info = &it->second;
    // }
    // else
    // {
    //     SAFE_FREE(marshalled_inp_buff);
    //     return INVALID_SESSION;
    // }

    //Core Reference Code function
    ke_status = send_request_receive_response(src_enclave_id, dest_enclave_id, dest_session_info, marshalled_inp_buff,
                                            marshalled_inp_buff_len, max_out_buff_size, &out_buff, &out_buff_len);


    if(ke_status != SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(out_buff);
        return ke_status;
    }

    //Un-marshal the return value and output parameters from foo1 of Enclave 2
    ke_status = unmarshal_retval_and_output_parameters_e2_foo1(out_buff, &retval);
    if(ke_status != SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(out_buff);
        return ke_status;
    }

    SAFE_FREE(marshalled_inp_buff);
    SAFE_FREE(out_buff);
    SAFE_FREE(retval);
    return SUCCESS;
}

//Makes use of the sample code function to do a generic secret message exchange (Test Vector)
uint32_t test_message_exchange_enclave2(sgx_enclave_id_t src_enclave_id,
                               sgx_enclave_id_t dest_enclave_id, 
                               char* message, int messagelen)
{
    ATTESTATION_STATUS ke_status = SUCCESS;
    uint32_t target_fn_id, msg_type;
    char* marshalled_inp_buff;
    size_t marshalled_inp_buff_len;
    char* out_buff;
    size_t out_buff_len;
    dh_session_t *dest_session_info;
    size_t max_out_buff_size;
    char* secret_response;
    uint32_t secret_data;

    target_fn_id = 0;
    msg_type = MESSAGE_EXCHANGE;
    max_out_buff_size = 50;
    secret_data = 0x12345678; //Secret Data here is shown only for purpose of demonstration.

    //Marshals the secret data into a buffer
    // ke_status = marshal_message_exchange_request(target_fn_id, msg_type, secret_data, &marshalled_inp_buff, &marshalled_inp_buff_len);
    // if(ke_status != SUCCESS)
    // {
    //     return ke_status;
    // }
    char str[messagelen + 1];
    memcpy(str, message, messagelen);
    str[messagelen] = '\0';
    ke_status = marshal_message_exchange_request3(target_fn_id, msg_type, str, &marshalled_inp_buff, &marshalled_inp_buff_len);
    if(ke_status != SUCCESS)
    {
        return ke_status;
    }

    if (destination_enclave_id == dest_enclave_id) {
        dest_session_info = &destination_enclave_session;

    } else {
        SAFE_FREE(marshalled_inp_buff);
        return INVALID_SESSION;
    }
   
    // //Search the map for the session information associated with the destination enclave id passed in
    // std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_src_session_info_map.find(dest_enclave_id);
    // if(it != g_src_session_info_map.end())
    // {
    //      dest_session_info = &it->second;
    // }
    // else
    // {
    //     SAFE_FREE(marshalled_inp_buff);
    //     return INVALID_SESSION;
    // }

    // char* temp_in_buf = malloc(20);
    // temp_in_buf[0] = 'b';
    // temp_in_buf[1] = 'r';
    // temp_in_buf[2] = 'e';
    // temp_in_buf[3] = '\0';





    //Core Reference Code function
    ke_status = send_request_receive_response(src_enclave_id, dest_enclave_id, dest_session_info, marshalled_inp_buff,
                                                marshalled_inp_buff_len, max_out_buff_size, &out_buff, &out_buff_len);
    if(ke_status != SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(out_buff);
        return ke_status;
    }

    //Un-marshal the secret response data
    ke_status = umarshal_message_exchange_response(out_buff, &secret_response);
    if(ke_status != SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(out_buff);
        return ke_status;
    }

    SAFE_FREE(marshalled_inp_buff);
    SAFE_FREE(out_buff);
    SAFE_FREE(secret_response);
    return SUCCESS;
}


//Makes use of the sample code function to close a current session
uint32_t test_close_session_enclave2(sgx_enclave_id_t src_enclave_id,
                                sgx_enclave_id_t dest_enclave_id)
{
    dh_session_t dest_session_info;
    ATTESTATION_STATUS ke_status = SUCCESS;

    if (destination_enclave_id == dest_enclave_id) {
        dest_session_info = destination_enclave_session;

    } else {
        return NULL;
    }
    // //Search the map for the session information associated with the destination enclave id passed in
    // std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_src_session_info_map.find(dest_enclave_id);
    // if(it != g_src_session_info_map.end())
    // {
    //     dest_session_info = it->second;
    // }
    // else
    // {
    //     return NULL;
    // }

    //Core reference code function for closing a session
    ke_status = close_session_enclave2(src_enclave_id, dest_enclave_id);

    //Erase the session information associated with the destination enclave id
    destination_enclave_id = 0;
    // g_src_session_info_map.erase(dest_enclave_id);
    return ke_status;
}

//Function that is used to verify the trust of the other enclave
//Each enclave can have its own way verifying the peer enclave identity
extern "C" uint32_t verify_peer_enclave_trust(sgx_dh_session_enclave_identity_t* peer_enclave_identity)
{
    if(!peer_enclave_identity)
    {
        return INVALID_PARAMETER_ERROR;
    }
    if(peer_enclave_identity->isv_prod_id != 0 || !(peer_enclave_identity->attributes.flags & SGX_FLAGS_INITTED))
        // || peer_enclave_identity->attributes.xfrm !=3)// || peer_enclave_identity->mr_signer != xx //TODO: To be hardcoded with values to check
    {
        return ENCLAVE_TRUST_ERROR;
    }
    else
    {
        return SUCCESS;
    }
}


//Dispatcher function that calls the approriate enclave function based on the function id
//Each enclave can have its own way of dispatching the calls from other enclave
extern "C" uint32_t enclave_to_enclave_call_dispatcher(char* decrypted_data,
                                                       size_t decrypted_data_length,
                                                       char** resp_buffer,
                                                       size_t* resp_length)
{
    ms_in_msg_exchange_t *ms;
    uint32_t (*fn1)(ms_in_msg_exchange_t *ms, size_t, char**, size_t*);
    if(!decrypted_data || !resp_length)
    {
        return INVALID_PARAMETER_ERROR;
    }
    ms = (ms_in_msg_exchange_t *)decrypted_data;
    if(ms->target_fn_id >= func_table.num_funcs)
    {
        return INVALID_PARAMETER_ERROR;
    }
    fn1 = (uint32_t (*)(ms_in_msg_exchange_t*, size_t, char**, size_t*))func_table.table[ms->target_fn_id];
    return fn1(ms, decrypted_data_length, resp_buffer, resp_length);
}

//Operates on the input secret and generates the output secret
uint32_t get_message_exchange_response(uint32_t inp_secret_data)
{
    uint32_t secret_response;

    //User should use more complex encryption method to protect their secret, below is just a simple example
    secret_response = inp_secret_data & 0x11111111; 

    return secret_response;

}

//Generates the response from the request message
extern "C" uint32_t message_exchange_response_generator(char* decrypted_data,
                                              char** resp_buffer,
                                              size_t* resp_length)
{
    ms_in_msg_exchange_t *ms;
    uint32_t inp_secret_data;
    char* inp_really_secret_data = (char*) malloc(20);
    uint32_t out_secret_data;
    if(!decrypted_data || !resp_length)
    {
        return INVALID_PARAMETER_ERROR;
    }
    ms = (ms_in_msg_exchange_t *)decrypted_data;

    // if(umarshal_message_exchange_request(&inp_secret_data,ms) != SUCCESS)
    //     return ATTESTATION_ERROR;
    if(umarshal_message_exchange_request3(inp_really_secret_data,ms) != SUCCESS)
        return ATTESTATION_ERROR;
    ocall_print("\nENCLAVE2 RECEIVED MESSAGE: ");
    ocall_print(inp_really_secret_data);

    //TODO: figure out a way to not just store string, NOTE: Change not persisted in other file
    memcpy(secret_string, inp_really_secret_data, strlen(inp_really_secret_data));
    secret_string[strlen(inp_really_secret_data)] = '\0';


    out_secret_data = get_message_exchange_response(inp_secret_data);

    if(marshal_message_exchange_response(resp_buffer, resp_length, out_secret_data) != SUCCESS)
        return MALLOC_ERROR;

    return SUCCESS;

}


static uint32_t e1_foo1(external_param_struct_t *p_struct_var)
{
    if(!p_struct_var)
    {
        return INVALID_PARAMETER_ERROR;
    }
    (p_struct_var->var1)++;
    (p_struct_var->var2)++;
    (p_struct_var->p_internal_struct->ivar1)++;
    (p_struct_var->p_internal_struct->ivar2)++;

    return (p_struct_var->var1 + p_struct_var->var2 + p_struct_var->p_internal_struct->ivar1 + p_struct_var->p_internal_struct->ivar2);
}

//Function which is executed on request from the source enclave
static uint32_t e1_foo1_wrapper(ms_in_msg_exchange_t *ms,
                    size_t param_lenth,
                    char** resp_buffer,
                    size_t* resp_length)
{
    UNUSED(param_lenth);

    uint32_t ret;
    size_t len_data, len_ptr_data;
    external_param_struct_t *p_struct_var;
    internal_param_struct_t internal_struct_var;

    if(!ms || !resp_length)
    {
        return INVALID_PARAMETER_ERROR;
    }

    p_struct_var = (external_param_struct_t*)malloc(sizeof(external_param_struct_t));
    if(!p_struct_var)
        return MALLOC_ERROR;

    p_struct_var->p_internal_struct = &internal_struct_var;

    if(unmarshal_input_parameters_e1_foo1(p_struct_var, ms) != SUCCESS)//can use the stack
    {
        SAFE_FREE(p_struct_var);
        return ATTESTATION_ERROR;
    }

    ret = e1_foo1(p_struct_var);

    len_data = sizeof(external_param_struct_t) - sizeof(p_struct_var->p_internal_struct);
    len_ptr_data = sizeof(internal_struct_var);

    if(marshal_retval_and_output_parameters_e1_foo1(resp_buffer, resp_length, ret, p_struct_var, len_data, len_ptr_data) != SUCCESS)
    {
        SAFE_FREE(p_struct_var);
        return MALLOC_ERROR;
    }
    SAFE_FREE(p_struct_var);
    return SUCCESS;
}

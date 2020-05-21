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

// This sample is confined to the communication between a SGX client platform
// and an ISV Application Server. 

#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"

#include <unordered_map> 


#include <stdio.h>
#include <limits.h>
#include <unistd.h>
// Needed for definition of remote attestation messages.
#include "remote_attestation_result.h"

// Needed to call untrusted key exchange library APIs, i.e. sgx_ra_proc_msg2.
#include "sgx_ukey_exchange.h"

// Needed to get service provider's information, in your real project, you will
// need to talk to real server.
#include "network_ra.h"

// Needed to create enclave and do ecall.
#include "sgx_urts.h"

// Needed to query extended epid group id.
#include "sgx_uae_service.h"
#include "enclave_untrusted_host.h"
#include "kps.h"

#include "network_simulator.h"

#include <sstream>

#ifndef SAFE_FREE
#define SAFE_FREE(ptr) {if (NULL != (ptr)) {free(ptr); (ptr) = NULL;}}
#endif

// In addition to generating and sending messages, this application
// can use pre-generated messages to verify the generation of
// messages and the information flow.
#include "sample_messages.h"

extern sgx_enclave_id_t global_eid;
int CURRENT_ENCLAVE_EID_NUM = 0;

unordered_map<string, sgx_enclave_id_t> PublicIdentityKeyToEidDictionary;

extern char* KPS_IP_ADDRESS;
extern int KPS_PORT_ATTESTATION;
extern int KPS_PORT_GENERIC;


#define ENCLAVE_PATH "isv_enclave.signed.so"

// uint8_t* msg1_samples[] = { msg1_sample1, msg1_sample2 };
// uint8_t* msg2_samples[] = { msg2_sample1, msg2_sample2 };
// uint8_t* msg3_samples[] = { msg3_sample1, msg3_sample2 };
// uint8_t* attestation_msg_samples[] =
//     { attestation_msg_sample1, attestation_msg_sample2};

// Some utility functions to output some of the data structures passed between
// the ISV app and the remote attestation service provider.
inline void PRINT_BYTE_ARRAY(
    FILE *file, void *mem, uint32_t len)
{
    if(!mem || !len)
    {
        fprintf(file, "\n( null )\n");
        return;
    }
    uint8_t *array = (uint8_t *)mem;
    fprintf(file, "%u bytes:\n{\n", len);
    uint32_t i = 0;
    for(i = 0; i < len - 1; i++)
    {
        fprintf(file, "0x%x, ", array[i]);
        if(i % 8 == 7) fprintf(file, "\n");
    }
    fprintf(file, "0x%x ", array[i]);
    fprintf(file, "\n}\n");
}


inline void PRINT_ATTESTATION_SERVICE_RESPONSE(
    FILE *file,
    ra_samp_response_header_t *response)
{
    if(!response)
    {
        fprintf(file, "\t\n( null )\n");
        return;
    }

    fprintf(file, "RESPONSE TYPE:   0x%x\n", response->type);
    fprintf(file, "RESPONSE STATUS: 0x%x 0x%x\n", response->status[0],
            response->status[1]);
    fprintf(file, "RESPONSE BODY SIZE: %u\n", response->size);

    if(response->type == TYPE_RA_MSG2)
    {
        sgx_ra_msg2_t* p_msg2_body = (sgx_ra_msg2_t*)(response->body);

        fprintf(file, "MSG2 gb - ");
        PRINT_BYTE_ARRAY(file, &(p_msg2_body->g_b), sizeof(p_msg2_body->g_b));

        fprintf(file, "MSG2 spid - ");
        PRINT_BYTE_ARRAY(file, &(p_msg2_body->spid), sizeof(p_msg2_body->spid));

        fprintf(file, "MSG2 quote_type : %hx\n", p_msg2_body->quote_type);

        fprintf(file, "MSG2 kdf_id : %hx\n", p_msg2_body->kdf_id);

        fprintf(file, "MSG2 sign_gb_ga - ");
        PRINT_BYTE_ARRAY(file, &(p_msg2_body->sign_gb_ga),
                         sizeof(p_msg2_body->sign_gb_ga));

        fprintf(file, "MSG2 mac - ");
        PRINT_BYTE_ARRAY(file, &(p_msg2_body->mac), sizeof(p_msg2_body->mac));

        fprintf(file, "MSG2 sig_rl - ");
        PRINT_BYTE_ARRAY(file, &(p_msg2_body->sig_rl),
                         p_msg2_body->sig_rl_size);
    }
    else if(response->type == TYPE_RA_ATT_RESULT)
    {
        sample_ra_att_result_msg_t *p_att_result =
            (sample_ra_att_result_msg_t *)(response->body);
        fprintf(file, "ATTESTATION RESULT MSG platform_info_blob - ");
        PRINT_BYTE_ARRAY(file, &(p_att_result->platform_info_blob),
                         sizeof(p_att_result->platform_info_blob));

        fprintf(file, "ATTESTATION RESULT MSG mac - ");
        PRINT_BYTE_ARRAY(file, &(p_att_result->mac), sizeof(p_att_result->mac));

        fprintf(file, "ATTESTATION RESULT MSG secret.payload_tag - %u bytes\n",
                p_att_result->secret.payload_size);

        fprintf(file, "ATTESTATION RESULT MSG secret.payload - ");
        PRINT_BYTE_ARRAY(file, p_att_result->secret.payload,
                p_att_result->secret.payload_size);
    }
    else
    {
        fprintf(file, "\nERROR in printing out the response. "
                       "Response of type not supported %d\n", response->type);
    }
}

//TODO prevent memory leaks
char* serialize_ra_network_headers(const char *sending_machine_name, 
    const char *receiving_machine_name,
    const ra_samp_request_header_t *p_req,
    Encrypted_Message optional_Message,
    int& returnSize) {

    
    int size_p_req;
    char* p_req_size_string = (char*) malloc(10);
    if(p_req == NULL) {
        size_p_req = 0;
        strncpy(p_req_size_string, "0", 2);
    } else {
        size_p_req = p_req->size;
        itoa(p_req->size, p_req_size_string, 10);
    }

    char* p_req_serial = (char*) malloc(sizeof(ra_samp_request_header_t) + size_p_req);
    if (p_req != NULL) {
        memcpy(p_req_serial, (char*)p_req, sizeof(ra_samp_request_header_t) + size_p_req);
    }

    char* optional_Message_Serialized;
    int optional_Message_size;
    
    if (optional_Message.secret_size == 0) {

        optional_Message_Serialized = "0";
        optional_Message_size = 1;
    

    } else {
        char* secret_size_string = (char*) malloc(10);
        itoa(optional_Message.secret_size, secret_size_string, 10);

        char* encrypted_message_string = (char*) malloc(optional_Message.secret_size);
        memcpy(encrypted_message_string, optional_Message.encrypted_message, optional_Message.secret_size);

        char* payload_tag_string = (char*) malloc(16);
        memcpy(payload_tag_string, optional_Message.payload_tag, 16);

        char* concatStrings[] = {secret_size_string, ":", encrypted_message_string, ":", payload_tag_string};
        int concatLengths[] = {strlen(secret_size_string), 1, optional_Message.secret_size, 1, 16};
        optional_Message_Serialized = concatMutipleStringsWithLength(concatStrings, concatLengths, 5);
        optional_Message_size = returnTotalSizeofLengthArray(concatLengths, 5);

    }

    char* concatStrings[] = {(char*)sending_machine_name, ":", (char*)receiving_machine_name, ":", p_req_size_string, ":",  p_req_serial, ":", optional_Message_Serialized};
    int concatLengths[] = {strlen(sending_machine_name), 1, strlen(receiving_machine_name), 1, strlen(p_req_size_string), 1, sizeof(ra_samp_request_header_t) + size_p_req, 1, optional_Message_size};
    char* serializedString = concatMutipleStringsWithLength(concatStrings, concatLengths, 9);
    returnSize = returnTotalSizeofLengthArray(concatLengths, 9) + 1;

    return serializedString;


}

char* make_socket_attestation_send_request(char* request, int requestSize) {
    char* net_request = (char*) malloc(requestSize);
    memcpy(net_request, request, requestSize);

    char* copied_response;
    int responseSize;
    return network_socket_sender(request, requestSize, KPS_IP_ADDRESS, strlen(KPS_IP_ADDRESS), KPS_PORT_ATTESTATION);
    // char* net_response = handle_socket_attestation_request(net_request, responseSize);
    // copied_response = (char*) malloc(responseSize);
    // memcpy(copied_response, net_response, responseSize);
    
    // return (char*) copied_response;

}


ra_samp_response_header_t* send_attestation_network_request(const char *sending_machine_name, 
    const char *receiving_machine_name,
    const ra_samp_request_header_t *p_req,
    Encrypted_Message optional_Message,
    int& ret, bool expectingResponse) {

    ra_samp_response_header_t *p_msg0_resp_full = NULL;

    
    int returnSize;
    // ocall_print("serializing");
    // ocall_print_int(p_req->size);
    char* serializedString = serialize_ra_network_headers(sending_machine_name, receiving_machine_name, p_req, optional_Message, returnSize);
    p_msg0_resp_full = (ra_samp_response_header_t*)make_socket_attestation_send_request(serializedString, returnSize);
    ret = 0;
    
    // RA_network_serialization_headers* deseralized = deserialize_ra_network_headers(serializedString);


    // const ra_samp_request_header_t *p_req = (const ra_samp_request_header_t *) malloc(sizeof(const ra_samp_request_header_t));
    // memcpy(p_req, );

    // ret = ra_network_send_receive(deseralized->sending_machine_name,
    //         deseralized->receiving_machine_name,
    //         deseralized->p_req,
    //         &p_msg0_resp_full, deseralized->optional_Message);
    int size;
    if (expectingResponse) {
        size = p_msg0_resp_full->size;
        ocall_print("size of ra is ");
        ocall_print_int(size);
    } else {
        size = 0;
    }
    ra_samp_response_header_t *return_resp = (ra_samp_response_header_t*) malloc(sizeof(ra_samp_response_header_t) + size);
    // return_resp->type = p_msg0_resp_full->type;
    // return_resp->status = (uint8_t [2]) malloc(2);
    // for (int i = 0; i < 2; i++) {
    //     return_resp->status[i] = p_msg0_resp_full->status[i];
    // }
    // return_resp->size = p_msg0_resp_full->size;
    // return_resp->align = (uint8_t*) malloc(1);
    // return_resp->align[0] = p_msg0_resp_full->align[0];
    // return_resp->body = (uint8_t*) malloc(return_resp->size);
    // for (int i = 0; i < return_resp->size; i++) {
    //     return_resp->body[i] = p_msg0_resp_full->body[i];
    // }

    if (expectingResponse) {
        memcpy(return_resp, p_msg0_resp_full, sizeof(ra_samp_response_header_t));

        for (int i = 0; i < size; i++) {
            return_resp->body[i] = p_msg0_resp_full->body[i];
        }
    }

    return return_resp;

}


// This sample code doesn't have any recovery/retry mechanisms for the remote
// attestation. Since the enclave can be lost due S3 transitions, apps
// susceptible to S3 transitions should have logic to restart attestation in
// these scenarios.
// This method makes network_ra call to have the pong enclave attest to the ping machine
inline int pong_enclave_start_attestation(sgx_enclave_id_t currentEid, const char* receiving_machine_name) {
    int ret = 0;
    ra_samp_request_header_t *p_msg0_full = NULL;
    ra_samp_response_header_t *p_msg0_resp_full = NULL;
    ra_samp_request_header_t *p_msg1_full = NULL;
    ra_samp_response_header_t *p_msg2_full = NULL;
    sgx_ra_msg3_t *p_msg3 = NULL;
    ra_samp_response_header_t* p_att_result_msg_full = NULL;
    // ocall_print("Receiving Machine Name is ");
    // ocall_print(receiving_machine_name);
    sgx_enclave_id_t enclave_id = currentEid; //TODO the change from global_eid to this is causing this to fail
    int enclave_lost_retry_time = 1;
    int busy_retry_time = 4;
    sgx_ra_context_t context = INT_MAX;
    sgx_status_t status = SGX_SUCCESS;
    ra_samp_request_header_t* p_msg3_full = NULL;
    char* current_machine_name = "PongMachine";

    int32_t verify_index = -1;
    int32_t verification_samples = sizeof(msg1_samples)/sizeof(msg1_samples[0]);

    FILE* OUTPUT;
    if (ENABLE_ENCLAVE_ATTESTATION_PRINT) {
        OUTPUT = stdout;
    } else {
        OUTPUT = fopen ("temper.txt" , "w");
    }

// #define VERIFICATION_INDEX_IS_VALID() (verify_index > 0 && \
//                                        verify_index <= verification_samples)
// #define GET_VERIFICATION_ARRAY_INDEX() (verify_index-1)

//     if(argc > 1)
//     {

//         verify_index = atoi(argv[1]);

//         if( VERIFICATION_INDEX_IS_VALID())
//         {
//             fprintf(OUTPUT, "\nVerifying precomputed attestation messages "
//                             "using precomputed values# %d\n", verify_index);
//         }
//         else
//         {
//             fprintf(OUTPUT, "\nValid invocations are:\n");
//             fprintf(OUTPUT, "\n\tisv_app\n");
//             fprintf(OUTPUT, "\n\tisv_app <verification index>\n");
//             fprintf(OUTPUT, "\nValid indices are [1 - %d]\n",
//                     verification_samples);
//             fprintf(OUTPUT, "\nUsing a verification index uses precomputed "
//                     "messages to assist debugging the remote attestation "
//                     "service provider.\n");
//             return -1;
//         }
//     }

    // Preparation for remote attestation by configuring extended epid group id.
    {
        uint32_t extended_epid_group_id = 0;
        ret = sgx_get_extended_epid_group_id(&extended_epid_group_id);
        if (SGX_SUCCESS != ret)
        {
            ret = -1;
            fprintf(OUTPUT, "\nError, call sgx_get_extended_epid_group_id fail [%s].",
                __FUNCTION__);
            return ret;
        }
        fprintf(OUTPUT, "\nCall sgx_get_extended_epid_group_id success.");

        p_msg0_full = (ra_samp_request_header_t*)
            malloc(sizeof(ra_samp_request_header_t)
            +sizeof(uint32_t));
        if (NULL == p_msg0_full)
        {
            ret = -1;
            goto CLEANUP;
        }
        p_msg0_full->type = TYPE_RA_MSG0;
        p_msg0_full->size = sizeof(uint32_t);

        *(uint32_t*)((uint8_t*)p_msg0_full + sizeof(ra_samp_request_header_t)) = extended_epid_group_id;
        {

            fprintf(OUTPUT, "\nMSG0 body generated -\n");

            PRINT_BYTE_ARRAY(OUTPUT, p_msg0_full->body, p_msg0_full->size);

        }
        // The ISV application sends msg0 to the SP.
        // The ISV decides whether to support this extended epid group id.
        fprintf(OUTPUT, "\nSending msg0 to remote attestation service provider.\n");

        // ret = ra_network_send_receive(current_machine_name,
        //     receiving_machine_name,
        //     p_msg0_full,
        //     &p_msg0_resp_full);
        
        p_msg0_resp_full = send_attestation_network_request(current_machine_name,
            receiving_machine_name,
            p_msg0_full, default_Encrypted_Message, ret, false);
        if (ret != 0)
        {
            fprintf(OUTPUT, "\nError, ra_network_send_receive for msg0 failed "
                "[%s].", __FUNCTION__);
            goto CLEANUP;
        }
        fprintf(OUTPUT, "\nSent MSG0 to remote attestation service.\n");
    }
    // Remote attestation will be initiated the ISV server challenges the ISV
    // app or if the ISV app detects it doesn't have the credentials
    // (shared secret) from a previous attestation required for secure
    // communication with the server.
    {
        // ISV application creates the ISV enclave.
        do
        {
            ret = 0;
            //int ret = initialize_enclave(&enclave_id, "enclave.token", "enclave.signed.so");  
            // ret = sgx_create_enclave(_T(ENCLAVE_PATH),
            //                          SGX_DEBUG_FLAG,
            //                          NULL,
            //                          NULL,
            //                          &enclave_id, NULL);
            if(0 != ret)
            {
                ret = -1;
                fprintf(OUTPUT, "\nError, call sgx_create_enclave fail [%s].",
                        __FUNCTION__);
                goto CLEANUP;
            }
            //fprintf(OUTPUT, "\nCall sgx_create_enclave success.");
            ret = enclave_enclave_init_ra(enclave_id,
                                  &status,
                                  false,
                                  &context);
        //Ideally, this check would be around the full attestation flow.
        } while (SGX_ERROR_ENCLAVE_LOST == ret && enclave_lost_retry_time--);

        if(SGX_SUCCESS != ret || status)
        {
            fprintf(OUTPUT, "\nError, call enclave_init_ra fail [%s].",
                    __FUNCTION__);
            printf("App: error %#x.\n", ret);
            ret = -1;


            goto CLEANUP;
        }
        fprintf(OUTPUT, "\nCall enclave_init_ra success.");

        // isv application call uke sgx_ra_get_msg1
        p_msg1_full = (ra_samp_request_header_t*)
                      malloc(sizeof(ra_samp_request_header_t)
                             + sizeof(sgx_ra_msg1_t));
        if(NULL == p_msg1_full)
        {
            ret = -1;
            goto CLEANUP;
        }
        p_msg1_full->type = TYPE_RA_MSG1;
        p_msg1_full->size = sizeof(sgx_ra_msg1_t);
        do
        {
            ret = sgx_ra_get_msg1(context, enclave_id, enclave_sgx_ra_get_ga,
                                  (sgx_ra_msg1_t*)((uint8_t*)p_msg1_full
                                  + sizeof(ra_samp_request_header_t)));
            sleep(3); // Wait 3s between retries
        } while (SGX_ERROR_BUSY == ret && busy_retry_time--);
        if(SGX_SUCCESS != ret)
        {
            ret = -1;
            fprintf(OUTPUT, "\nError, call sgx_ra_get_msg1 fail [%s].",
                    __FUNCTION__);
            goto CLEANUP;
        }
        else
        {
            fprintf(OUTPUT, "\nCall sgx_ra_get_msg1 success.\n");

            fprintf(OUTPUT, "\nMSG1 body generated -\n");

            PRINT_BYTE_ARRAY(OUTPUT, p_msg1_full->body, p_msg1_full->size);

        }

        // if(VERIFICATION_INDEX_IS_VALID())
        // {

        //     memcpy_s(p_msg1_full->body, p_msg1_full->size,
        //              msg1_samples[GET_VERIFICATION_ARRAY_INDEX()],
        //              p_msg1_full->size);

        //     fprintf(OUTPUT, "\nInstead of using the recently generated MSG1, "
        //                     "we will use the following precomputed MSG1 -\n");

        //     PRINT_BYTE_ARRAY(OUTPUT, p_msg1_full->body, p_msg1_full->size);
        // }


        // The ISV application sends msg1 to the SP to get msg2,
        // msg2 needs to be freed when no longer needed.
        // The ISV decides whether to use linkable or unlinkable signatures.
        fprintf(OUTPUT, "\nSending msg1 to remote attestation service provider."
                        "Expecting msg2 back.\n");


        // ret = ra_network_send_receive(current_machine_name,
        //                               receiving_machine_name,
        //                               p_msg1_full,
        //                               &p_msg2_full);
        p_msg2_full = send_attestation_network_request(current_machine_name,
                                      receiving_machine_name,
                                      p_msg1_full,
                                        default_Encrypted_Message, ret, true);

        if(ret != 0 || !p_msg2_full)
        {
            fprintf(OUTPUT, "\nError, ra_network_send_receive for msg1 failed "
                            "[%s].", __FUNCTION__);
            // if(VERIFICATION_INDEX_IS_VALID())
            // {
            //     fprintf(OUTPUT, "\nBecause we are in verification mode we will "
            //                     "ignore this error.\n");
            //     fprintf(OUTPUT, "\nInstead, we will pretend we received the "
            //                     "following MSG2 - \n");

            //     SAFE_FREE(p_msg2_full);
            //     ra_samp_response_header_t* precomputed_msg2 =
            //         (ra_samp_response_header_t*)msg2_samples[
            //             GET_VERIFICATION_ARRAY_INDEX()];
            //     const size_t msg2_full_size = sizeof(ra_samp_response_header_t)
            //                                   +  precomputed_msg2->size;
            //     p_msg2_full =
            //         (ra_samp_response_header_t*)malloc(msg2_full_size);
            //     if(NULL == p_msg2_full)
            //     {
            //         ret = -1;
            //         goto CLEANUP;
            //     }
            //     memcpy_s(p_msg2_full, msg2_full_size, precomputed_msg2,
            //              msg2_full_size);

            //     PRINT_BYTE_ARRAY(OUTPUT, p_msg2_full,
            //                      (uint32_t)sizeof(ra_samp_response_header_t)
            //                      + p_msg2_full->size);
            // }
            // else
            // {
                goto CLEANUP;
            // }
        }
        else
        {
            // Successfully sent msg1 and received a msg2 back.
            // Time now to check msg2.
            if(TYPE_RA_MSG2 != p_msg2_full->type)
            {

                fprintf(OUTPUT, "\nError, didn't get MSG2 in response to MSG1. "
                                "[%s].", __FUNCTION__);

                // if(VERIFICATION_INDEX_IS_VALID())
                // {
                //     fprintf(OUTPUT, "\nBecause we are in verification mode we "
                //                     "will ignore this error.");
                // }
                // else
                // {
                    goto CLEANUP;
                // }
            }

            fprintf(OUTPUT, "\nSent MSG1 to remote attestation service "
                            "provider. Received the following MSG2:\n");
            PRINT_BYTE_ARRAY(OUTPUT, p_msg2_full,
                             (uint32_t)sizeof(ra_samp_response_header_t)
                             + p_msg2_full->size);

            fprintf(OUTPUT, "\nA more descriptive representation of MSG2:\n");
            PRINT_ATTESTATION_SERVICE_RESPONSE(OUTPUT, p_msg2_full);

            // if( VERIFICATION_INDEX_IS_VALID() )
            // {
            //     // The response should match the precomputed MSG2:
            //     ra_samp_response_header_t* precomputed_msg2 =
            //         (ra_samp_response_header_t *)
            //         msg2_samples[GET_VERIFICATION_ARRAY_INDEX()];
            //     if(MSG2_BODY_SIZE !=
            //         sizeof(ra_samp_response_header_t) + p_msg2_full->size ||
            //         memcmp( precomputed_msg2, p_msg2_full,
            //             sizeof(ra_samp_response_header_t) + p_msg2_full->size))
            //     {
            //         fprintf(OUTPUT, "\nVerification ERROR. Our precomputed "
            //                         "value for MSG2 does NOT match.\n");
            //         fprintf(OUTPUT, "\nPrecomputed value for MSG2:\n");
            //         PRINT_BYTE_ARRAY(OUTPUT, precomputed_msg2,
            //                          (uint32_t)sizeof(ra_samp_response_header_t)
            //                          + precomputed_msg2->size);
            //         fprintf(OUTPUT, "\nA more descriptive representation "
            //                         "of precomputed value for MSG2:\n");
            //         PRINT_ATTESTATION_SERVICE_RESPONSE(OUTPUT,
            //                                            precomputed_msg2);
            //     }
            //     else
            //     {
            //         fprintf(OUTPUT, "\nVerification COMPLETE. Remote "
            //                         "attestation service provider generated a "
            //                         "matching MSG2.\n");
            //     }
            // }

        }

        sgx_ra_msg2_t* p_msg2_body = (sgx_ra_msg2_t*)((uint8_t*)p_msg2_full
                                      + sizeof(ra_samp_response_header_t));


        uint32_t msg3_size = 0;
        // if( VERIFICATION_INDEX_IS_VALID())
        // {
        //     // We cannot generate a valid MSG3 using the precomputed messages
        //     // we have been using. We will use the precomputed msg3 instead.
        //     msg3_size = MSG3_BODY_SIZE;
        //     p_msg3 = (sgx_ra_msg3_t*)malloc(msg3_size);
        //     if(NULL == p_msg3)
        //     {
        //         ret = -1;
        //         goto CLEANUP;
        //     }
        //     memcpy_s(p_msg3, msg3_size,
        //              msg3_samples[GET_VERIFICATION_ARRAY_INDEX()], msg3_size);
        //     fprintf(OUTPUT, "\nBecause MSG1 was a precomputed value, the MSG3 "
        //                     "we use will also be. PRECOMPUTED MSG3 - \n");
        // }
        // else
        // {
            busy_retry_time = 2;
            // The ISV app now calls uKE sgx_ra_proc_msg2,
            // The ISV app is responsible for freeing the returned p_msg3!!
            do
            {
                ret = sgx_ra_proc_msg2(context,
                                   enclave_id,
                                   enclave_sgx_ra_proc_msg2_trusted,
                                   enclave_sgx_ra_get_msg3_trusted,
                                   p_msg2_body,
                                   p_msg2_full->size,
                                   &p_msg3,
                                   &msg3_size);
            } while (SGX_ERROR_BUSY == ret && busy_retry_time--);
            if(!p_msg3)
            {
                fprintf(OUTPUT, "\nError, call sgx_ra_proc_msg2 fail. "
                                "p_msg3 = 0x%p [%s].", p_msg3, __FUNCTION__);
                ret = -1;
                goto CLEANUP;
            }
            if(SGX_SUCCESS != (sgx_status_t)ret)
            {
                fprintf(OUTPUT, "\nError, call sgx_ra_proc_msg2 fail. "
                                "ret = 0x%08x [%s].", ret, __FUNCTION__);
                ret = -1;
                goto CLEANUP;
            }
            else
            {
                fprintf(OUTPUT, "\nCall sgx_ra_proc_msg2 success.\n");
                fprintf(OUTPUT, "\nMSG3 - \n");
            }
        // }

        PRINT_BYTE_ARRAY(OUTPUT, p_msg3, msg3_size);

        p_msg3_full = (ra_samp_request_header_t*)malloc(
                       sizeof(ra_samp_request_header_t) + msg3_size);
        if(NULL == p_msg3_full)
        {
            ret = -1;
            goto CLEANUP;
        }
        p_msg3_full->type = TYPE_RA_MSG3;
        p_msg3_full->size = msg3_size;
        if(memcpy_s(p_msg3_full->body, msg3_size, p_msg3, msg3_size))
        {
            fprintf(OUTPUT,"\nError: INTERNAL ERROR - memcpy failed in [%s].",
                    __FUNCTION__);
            ret = -1;
            goto CLEANUP;
        }

        // The ISV application sends msg3 to the SP to get the attestation
        // result message, attestation result message needs to be freed when
        // no longer needed. The ISV service provider decides whether to use
        // linkable or unlinkable signatures. The format of the attestation
        // result is up to the service provider. This format is used for
        // demonstration.  Note that the attestation result message makes use
        // of both the MK for the MAC and the SK for the secret. These keys are
        // established from the SIGMA secure channel binding.
        // struct Encrypted_Message temp = {(uint8_t*)&message_from_machine_to_enclave, 0, NULL};
        //TODO change name from encrypted_message to like normal message? idk tho

        // ret = ra_network_send_receive(current_machine_name,
        //                               receiving_machine_name,
        //                               p_msg3_full,
        //                               &p_att_result_msg_full,
        //                               temp,
        //                             optional_message);
        p_att_result_msg_full = send_attestation_network_request(current_machine_name,
                                      receiving_machine_name,
                                      p_msg3_full,
                                        default_Encrypted_Message, ret, true);
        if(ret || !p_att_result_msg_full)
        {
            ret = -1;
            fprintf(OUTPUT, "\nError, sending msg3 failed [%s].", __FUNCTION__);
            goto CLEANUP;
        }


        sample_ra_att_result_msg_t * p_att_result_msg_body =
            (sample_ra_att_result_msg_t *)((uint8_t*)p_att_result_msg_full
                                           + sizeof(ra_samp_response_header_t));
        if(TYPE_RA_ATT_RESULT != p_att_result_msg_full->type)
        {
            ret = -1;
            fprintf(OUTPUT, "\nError. Sent MSG3 successfully, but the message "
                            "received was NOT of type att_msg_result. Type = "
                            "%d. [%s].", p_att_result_msg_full->type,
                             __FUNCTION__);
            goto CLEANUP;
        }
        else
        {
            fprintf(OUTPUT, "\nSent MSG3 successfully. Received an attestation "
                            "result message back\n.");
            // if( VERIFICATION_INDEX_IS_VALID() )
            // {
            //     if(ATTESTATION_MSG_BODY_SIZE != p_att_result_msg_full->size ||
            //         memcmp(p_att_result_msg_full->body,
            //             attestation_msg_samples[GET_VERIFICATION_ARRAY_INDEX()],
            //             p_att_result_msg_full->size) )
            //     {
            //         fprintf(OUTPUT, "\nSent MSG3 successfully. Received an "
            //                         "attestation result message back that did "
            //                         "NOT match the expected value.\n");
            //         fprintf(OUTPUT, "\nEXPECTED ATTESTATION RESULT -");
            //         PRINT_BYTE_ARRAY(OUTPUT,
            //             attestation_msg_samples[GET_VERIFICATION_ARRAY_INDEX()],
            //             ATTESTATION_MSG_BODY_SIZE);
            //     }
            // }
        }

        fprintf(OUTPUT, "\nATTESTATION RESULT RECEIVED - ");
        PRINT_BYTE_ARRAY(OUTPUT, p_att_result_msg_full->body,
                         p_att_result_msg_full->size);


        // if( VERIFICATION_INDEX_IS_VALID() )
        // {
        //     fprintf(OUTPUT, "\nBecause we used precomputed values for the "
        //                     "messages, the attestation result message will "
        //                     "not pass further verification tests, so we will "
        //                     "skip them.\n");
        //     goto CLEANUP;
        // }

        // Check the MAC using MK on the attestation result message.
        // The format of the attestation result message is ISV specific.
        // This is a simple form for demonstration. In a real product,
        // the ISV may want to communicate more information.
        ret = enclave_verify_att_result_mac(enclave_id,
                &status,
                context,
                (uint8_t*)&p_att_result_msg_body->platform_info_blob,
                sizeof(ias_platform_info_blob_t),
                (uint8_t*)&p_att_result_msg_body->mac,
                sizeof(sgx_mac_t));
        if((SGX_SUCCESS != ret) ||
           (SGX_SUCCESS != status))
        {
            ret = -1;
            fprintf(OUTPUT, "\nError: INTEGRITY FAILED - attestation result "
                            "message MK based cmac failed in [%s].",
                            __FUNCTION__);
            goto CLEANUP;
        }

        bool attestation_passed = true;
        // Check the attestation result for pass or fail.
        // Whether attestation passes or fails is a decision made by the ISV Server.
        // When the ISV server decides to trust the enclave, then it will return success.
        // When the ISV server decided to not trust the enclave, then it will return failure.
        if(0 != p_att_result_msg_full->status[0]
           || 0 != p_att_result_msg_full->status[1])
        {
            fprintf(OUTPUT, "\nError, attestation result message MK based cmac "
                            "failed in [%s].", __FUNCTION__);
            attestation_passed = false;
        }

        // The attestation result message should contain a field for the Platform
        // Info Blob (PIB).  The PIB is returned by attestation server in the attestation report.
        // It is not returned in all cases, but when it is, the ISV app
        // should pass it to the blob analysis API called sgx_report_attestation_status()
        // along with the trust decision from the ISV server.
        // The ISV application will take action based on the update_info.
        // returned in update_info by the API.  
        // This call is stubbed out for the sample.
        // 
        // sgx_update_info_bit_t update_info;
        // ret = sgx_report_attestation_status(
        //     &p_att_result_msg_body->platform_info_blob,
        //     attestation_passed ? 0 : 1, &update_info);

        // Get the shared secret sent by the server using SK (if attestation
        // passed)
        if(attestation_passed)
        {
            //If Ping machine wants to send the enclave a secure message
            // if (message_from_machine_to_enclave) { // message_from_machine_to_enclave == 1 or == 2
                // ret = enclave_put_secret_data(enclave_id,
                //                     &status,
                //                     context,
                //                     p_att_result_msg_body->secret.payload,
                //                     p_att_result_msg_body->secret.payload_size,
                //                     p_att_result_msg_body->secret.payload_tag);
                // if((SGX_SUCCESS != ret)  || (SGX_SUCCESS != status))
                // {
                //     fprintf(OUTPUT, "\nError, attestation result message secret "
                //                     "using SK based AESGCM failed in [%s]. ret = "
                //                     "0x%0x. status = 0x%0x", __FUNCTION__, ret,
                //                     status);
                //     goto CLEANUP;
                // }

                //TODO Comment this case out since only KPS sends messages to us, not us to KPS
                //TODO think about use case where we don't want anyone knowing our requests so we
                //first perform attestaion to get secure channel, get a session ID, and then send our
                //request to create the capability Key and stuff
                uint8_t payload_tag[16];
                uint8_t* encrypted_string = (uint8_t *) malloc(sizeof(uint8_t) * SIZE_OF_MESSAGE);
                uint32_t secret_size = SIZE_OF_MESSAGE;

                ra_samp_response_header_t *resp_1 = NULL;

                //Encrypt message using enclave
                ret = enclave_encrypt_secure_message(enclave_id,
                                    &status,
                                    context,
                                    encrypted_string,
                                    secret_size,
                                    payload_tag);
                //TODO: Do we need to pad message?

                //Send encrypted message to Ping machine
                struct Encrypted_Message emsg = {encrypted_string, secret_size, payload_tag};

                // ret = ra_network_send_receive(current_machine_name,
                //                       receiving_machine_name,
                //                       NULL,
                //                       NULL,
                //                       emsg);
                resp_1 = send_attestation_network_request(current_machine_name,
                                      receiving_machine_name,
                                      NULL, 
                                        emsg, ret, true);
                ocall_print("Received secret message from KPS");
                printPayload((char*)resp_1->body, resp_1->size);
                // ocall_print((char*)resp_1->body);
                char* responseCopy = (char*) malloc(resp_1->size);
                memcpy(responseCopy, resp_1->body, resp_1->size);
                char* split = strtok(responseCopy, ":");
                int encryptedMessageSize = atoi(split);
                char* encyptedMessage = (char*) malloc(encryptedMessageSize);
                memcpy(encyptedMessage, responseCopy + strlen(split) + 1, encryptedMessageSize);
                uint8_t payload_tag_encrypted[16];
                memcpy((char*) payload_tag_encrypted, responseCopy + strlen(split) + 1 + encryptedMessageSize + 1, 16);

                ret = enclave_put_secret_data(enclave_id,
                                    &status,
                                    context,
                                    (uint8_t *)encyptedMessage,
                                    encryptedMessageSize,
                                    payload_tag_encrypted);
                if((SGX_SUCCESS != ret)  || (SGX_SUCCESS != status))
                {
                    ocall_print("Error: attesttion failure");
                    fprintf(OUTPUT, "\nError, attestation result message secret "
                                    "using SK based AESGCM failed in [%s]. ret = "
                                    "0x%0x. status = 0x%0x", __FUNCTION__, ret,
                                    status);
                    goto CLEANUP;
                }




            // }
            //If Pong enclave wants to send a secure message to Ping machine
            // } else { //if message_from_machine_to_enclave == 0
            //     //TODO Comment this case out since only KPS sends messages to us, not us to KPS
            //     //TODO think about use case where we don't want anyone knowing our requests so we
            //     //first perform attestaion to get secure channel, get a session ID, and then send our
            //     //request to create the capability Key and stuff
            //     uint8_t payload_tag[16];
            //     uint8_t* encrypted_string = (uint8_t *) malloc(sizeof(uint8_t) * SIZE_OF_MESSAGE);
            //     uint32_t secret_size = SIZE_OF_MESSAGE;

            //     //Encrypt message using enclave
            //     ret = enclave_encrypt_secure_message(enclave_id,
            //                         &status,
            //                         context,
            //                         encrypted_string,
            //                         secret_size,
            //                         payload_tag);
            //     //TODO: Do we need to pad message?

            //     //Send encrypted message to Ping machine
            //     struct Encrypted_Message emsg = {encrypted_string, secret_size, payload_tag};

            //     // ret = ra_network_send_receive(current_machine_name,
            //     //                       receiving_machine_name,
            //     //                       NULL,
            //     //                       NULL,
            //     //                       emsg);
            //     mock_net(current_machine_name,
            //                           receiving_machine_name,
            //                           NULL, 
            //                             emsg, ret, false);
                
            // }
        }
        fprintf(OUTPUT, "\nSecret successfully received from server.");
        fprintf(OUTPUT, "\nRemote attestation success!");
    }

CLEANUP:
    // Clean-up
    // Need to close the RA key state.
    if(INT_MAX != context)
    {
        int ret_save = ret;
        ret = enclave_enclave_ra_close(enclave_id, &status, context); 
        if(SGX_SUCCESS != ret || status)
        {
            ret = -1;
            fprintf(OUTPUT, "\nError, call enclave_ra_close fail [%s].",
                    __FUNCTION__);
        }
        else
        {
            // enclave_ra_close was successful, let's restore the value that
            // led us to this point in the code.
            ret = ret_save;
        }
        fprintf(OUTPUT, "\nCall enclave_ra_close success.");
    }

    // sgx_destroy_enclave(enclave_id); NOTE: I commented this out


    ra_free_network_response_buffer(p_msg0_resp_full);
    ra_free_network_response_buffer(p_msg2_full);
    ra_free_network_response_buffer(p_att_result_msg_full);

    // p_msg3 is malloc'd by the untrusted KE library. App needs to free.
    SAFE_FREE(p_msg3);
    SAFE_FREE(p_msg3_full);
    SAFE_FREE(p_msg1_full);
    SAFE_FREE(p_msg0_full);
    // printf("\nEnter a character before exit ...\n");
    // getchar();
    return ret;
}


inline void* pong_enclave_attestation_thread(void* parameters) { //message_from_machine_to_enclave should be true when the enclave is receiving the message
                                                          //false when the enclave wants to send a message
    struct Enclave_start_attestation_wrapper_arguments* p = (struct Enclave_start_attestation_wrapper_arguments*)parameters;
    return (void*) pong_enclave_start_attestation(p->currentEid, p->machineName);
}

char* enclave_attestation_network_serializer(sgx_enclave_id_t currentEid, char* other_machine_name, uint32_t size, int message_from_machine_to_enclave, int& returnSize) {
    char* message_from_machine_to_enclaveString = (char*) malloc(10);

    std::ostringstream oss;
    oss << currentEid;
    string eidStringObject = oss.str();
    char* eidString = (char*)eidStringObject.c_str();

    itoa((int) message_from_machine_to_enclave, message_from_machine_to_enclaveString, 10);

    char* concatStrings[] = {eidString, ":", other_machine_name, ":", message_from_machine_to_enclaveString};
    int concatLengths[] = {strlen(eidString), 1, strlen(other_machine_name), 1, strlen(message_from_machine_to_enclaveString)};
    char* serializedString = concatMutipleStringsWithLength(concatStrings, concatLengths, 5);
    returnSize = returnTotalSizeofLengthArray(concatLengths, 5) + 1;
    ocall_print("Attestation Serializer:");
    printPayload(serializedString, returnSize);
    safe_free(message_from_machine_to_enclaveString);
    return serializedString;

}

struct Enclave_start_attestation_wrapper_arguments* enclave_attestation_network_deserializer(char* serializedString) {
    
    char* split = strtok(serializedString, ":");
    char* eidString = split;
    sgx_enclave_id_t currentEid;
    std::istringstream iss(split);
    iss >> currentEid;
    split = strtok(NULL, ":");
    char* other_machine_name = (char*) malloc(strlen(split) + 1);
    strncpy(other_machine_name, split, strlen(split) + 1);
    // split = strtok(NULL, ":");
    // int message_from_machine_to_enclave = atoi(split);
    struct Enclave_start_attestation_wrapper_arguments* parameters = (struct Enclave_start_attestation_wrapper_arguments*) malloc(sizeof(struct Enclave_start_attestation_wrapper_arguments));
    //{currentEid, other_machine_name, message_from_machine_to_enclave, optionalMessage};
    parameters->currentEid = currentEid;
    parameters->machineName = other_machine_name;
    // parameters->message_from_machine_to_enclave = message_from_machine_to_enclave;

    return parameters;

}

int ocall_pong_enclave_attestation_in_thread(sgx_enclave_id_t currentEid, char* other_machine_name, uint32_t size) {

    struct Enclave_start_attestation_wrapper_arguments parameters = {currentEid, other_machine_name};
    // struct Enclave_start_attestation_wrapper_arguments* parameters;// = {currentEid, other_machine_name, message_from_machine_to_enclave, optional_message};
    // int sizeOfSerializedString = 0;
    // char* serializedString = enclave_attestation_network_serializer(currentEid, other_machine_name, size, message_from_machine_to_enclave, sizeOfSerializedString);
    // parameters = enclave_attestation_network_deserializer(serializedString);

    // ocall_print("inside ocall_pong_enclave_attestation_in_thread");
    // printRSAKey(optional_message);
    // ocall_print("same as");
    // printRSAKey(optional_message + SGX_RSA3072_KEY_SIZE + 1);
    void* thread_ret;
    pthread_t thread_id; 
    ocall_print("\n Calling Attestation Thread\n"); 
    // pthread_create(&thread_id, NULL, pong_enclave_attestation_thread, (void*) parameters);
    pthread_create(&thread_id, NULL, pong_enclave_attestation_thread, (void*) (&parameters));

    //TODO look into not calling pthread_join but actually let this run asynchoronous
    pthread_join(thread_id, &thread_ret); 
    ocall_print("\n Finished Attestation Thread\n");

    return 0;

}

int ocall_network_request(char* request, char* response, uint32_t REQUEST_SIZE, uint32_t RESPONSE_SIZE, char* ipAddress, uint32_t IP_ADDRESS_SIZE, int port) {
    // ocall_print("GUUUUGY");
    ocall_print("Network Request is :");
    ocall_print(request);
    fflush(stdout);


    // char* result = network_socket_sender(request, REQUEST_SIZE, RESPONSE_SIZE);
    char* result = network_socket_sender(request, REQUEST_SIZE, ipAddress, IP_ADDRESS_SIZE, port);


    // char* result = send_network_request_API(request, REQUEST_SIZE);


    // if (RESPONSE_SIZE == 0) {
    //     return 1;
    // }

    ocall_print("Network Response is :");
    ocall_print(result);
    // if (result == NULL || result[0] == '\0') {
    //     printf("ERROR. No Message Received!\n");
    //     return 0;
    // }
    // else if (strlen(result) + 1 > RESPONSE_SIZE) {
    //     printf("ERROR. Message too big!\n");
    // }
    // if (NETWORK_DEBUG) {
    //     memcpy(response, result, strlen(result) + 1);
    // } else {
        memcpy(response, result, RESPONSE_SIZE);
    // }
    
    safe_free(result);
    return 1;

}


char* untrusted_enclave_host_receiveNetworkRequest(char* request, size_t requestSize) { //TODO have network ra forward to this

    return receiveNetworkRequestHelper(request, requestSize, true);

}


void ocall_add_identity_to_eid_dictionary(char* newMachineID, uint32_t ID_SIZE, sgx_enclave_id_t enclave_eid) {
        // if (NETWORK_DEBUG) {
        //     string identityString = string(newMachineID);
        //     PublicIdentityKeyToEidDictionary[identityString] = enclave_eid;
        // } else {
            string identityString = string(newMachineID, ID_SIZE);
            PublicIdentityKeyToEidDictionary[identityString] = enclave_eid;
        // }
        
        // ocall_print(newMachineID);
        // ocall_print("has enclave ID");
        // ocall_print_int(enclave_eid);
}


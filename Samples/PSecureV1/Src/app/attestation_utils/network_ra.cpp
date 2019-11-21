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

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "network_ra.h"
#include "ping_attestation.h"
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"

extern sgx_enclave_id_t global_eid;


// Used to send requests to the service provider sample.  It
// simulates network communication between the ISV app and the
// ISV service provider.  This would be modified in a real
// product to use the proper IP communication.
//
// @param receiving_machine_name String name of the server URL
// @param p_req Pointer to the message to be sent.
// @param p_resp Pointer to a pointer of the response message.

// @return int
//TODO consolidate this and the other network call method
int ra_network_send_receive(const char *sending_machine_name, 
    const char *receiving_machine_name,
    const ra_samp_request_header_t *p_req,
    ra_samp_response_header_t **p_resp,
    Encrypted_Message optional_Message,
    char* plain_text_message)
{
    //Request to KPS to initialize attestation channel
    if (strcmp(receiving_machine_name, "KPS") == 0 && optional_Message.secret_size == 0) {
        int ret = 0;
        ra_samp_response_header_t* p_resp_msg;

        if((NULL == receiving_machine_name) ||
            (NULL == p_req) ||
            (NULL == p_resp))
        {
            return -1;
        }

        switch(p_req->type)
        {

        case TYPE_RA_MSG0:
            ret = sp_ra_proc_msg0_req((const sample_ra_msg0_t*)((size_t)p_req
                + sizeof(ra_samp_request_header_t)),
                p_req->size);
            if (0 != ret)
            {
                fprintf(stderr, "\nError, call sp_ra_proc_msg1_req fail [%s].",
                    __FUNCTION__);
            }
            break;

        case TYPE_RA_MSG1:
            ret = sp_ra_proc_msg1_req((const sample_ra_msg1_t*)((size_t)p_req
                + sizeof(ra_samp_request_header_t)),
                p_req->size,
                &p_resp_msg);
            if(0 != ret)
            {
                fprintf(stderr, "\nError, call sp_ra_proc_msg1_req fail [%s].",
                    __FUNCTION__);
            }
            else
            {
                *p_resp = p_resp_msg;
            }
            break;

        case TYPE_RA_MSG3:
            ret =sp_ra_proc_msg3_req((const sample_ra_msg3_t*)((size_t)p_req +
                sizeof(ra_samp_request_header_t)),
                p_req->size,
                &p_resp_msg,
                *(optional_Message.encrypted_message),
                plain_text_message);
            if(0 != ret)
            {
                fprintf(stderr, "\nError, call sp_ra_proc_msg3_req fail [%s].",
                    __FUNCTION__);
            }
            else
            {
                *p_resp = p_resp_msg;
            }
            break;

        default:
            ret = -1;
            fprintf(stderr, "\nError, unknown ra message type. Type = %d [%s].",
                p_req->type, __FUNCTION__);
            break;
        }

        return ret;

     //Request to KPS to send encrypted data based on previous secure channel
     } else if (strcmp(receiving_machine_name, "KPS") == 0 && optional_Message.secret_size > 0) {
         ocall_ping_machine_receive_encrypted_message(
                                (uint8_t*)optional_Message.encrypted_message, 
                                optional_Message.secret_size,
                                 optional_Message.payload_tag);

    //Request to PongMachine to initialize a secure attestation channel
    } else if (strcmp(receiving_machine_name, "PongMachine") == 0) {
        int ptr;
        sgx_status_t status = pong_enclave_request_attestation(global_eid, &ptr, sending_machine_name);
        if (status == SGX_SUCCESS && ptr == 0) {
            return ptr;
        } else {
            printf("\nEnclave Request Attestation SGX Error!\n");
        }
    } else {
        return -1;
    }
}

// Used to free the response messages.  In the sample code, the
// response messages are allocated by the SP code.
//
//
// @param resp Pointer to the response buffer to be freed.

void ra_free_network_response_buffer(ra_samp_response_header_t *resp)
{
    if(resp!=NULL)
    {
        free(resp);
    }
}

char* network_request_logic(char* request) { //TODO Make this function generalizable for multiple enclaves and machines

    // printf("Network Request Received: %s", request);

    char* split = strtok(request, ":");
    if (strcmp(split, "Create") == 0) {
        char* newMachineID = (char* ) malloc(SIZE_OF_IDENTITY_STRING);
        split = strtok(NULL, ":");
        char* parentTrustedMachinePublicIDKey = split;
        split = strtok(NULL, ":");
        char* machineType = split;
        split = strtok(NULL, ":");
        int numArgs = atoi(split);
        split = strtok(NULL, ":");
        char* payload = split;

        int ptr;
        //TODO make it so that you know which enclave to call createMachineAPI on since there may be multiple enclaves
        //TODO actually make this call a method in untrusted host (pong_enclave_attestation.cpp)
        // application of this enclave and have that make an ecall to createMachineAPi
        sgx_status_t status = createMachineAPI(global_eid, &ptr, machineType, parentTrustedMachinePublicIDKey, newMachineID, numArgs, payload, SIZE_OF_IDENTITY_STRING, SIZE_OF_MAX_EVENT_PAYLOAD);

        return newMachineID;
    // }  else if (strcmp(split, "GetKey") == 0) {
    //     //TODO move this segmant of code into other ra method because attestation needs to occur first and then call retrieveCapabilityKey
    //     //TODO move this and use the messageFromMachine int
    //     //TODO might need to verify the currentMachineIDs signagure before we call attestation, so we need to do that first?
    //     split = strtok(NULL, ":");
    //     char currentMachineID[SIZE_OF_IDENTITY_STRING];
    //     //TODO add check that split is not too big
    //     memcpy(currentMachineID, split, strlen(split) + 1);
    //     split = strtok(NULL, ":");
    //     char childMachineID[SIZE_OF_IDENTITY_STRING];
    //     memcpy(childMachineID, split, strlen(split) + 1);
    //     return retrieveCapabilityKey(currentMachineID, childMachineID);

    
    }  else if (strcmp(split, "UntrustedCreate") == 0) {

        char* newMachineID = (char* ) malloc(SIZE_OF_IDENTITY_STRING);
        split = "Coordinator";//strtok(NULL, ":");
        char* machineType = split;

        //TODO actually make this call a method in untrusted host (pong_enclave_attestation.cpp)
        sgx_status_t status = UntrustedCreateMachineAPI(global_eid, machineType, 30, newMachineID, SIZE_OF_IDENTITY_STRING);
        return newMachineID;

    
    } else if (strcmp(split, "InitComm") == 0) {

        char* newSessionKey = (char* ) malloc(SIZE_OF_SESSION_KEY);
        split = strtok(NULL, ":");
        char* machineInitializingComm = split;
        split = strtok(NULL, ":");
        char* machineReceivingComm = split;

        int ptr;
        //TODO actually make this call a method in untrusted host (pong_enclave_attestation.cpp)
        sgx_status_t status = initializeCommunicationAPI(global_eid, &ptr, machineInitializingComm,machineReceivingComm, newSessionKey, SIZE_OF_IDENTITY_STRING, SIZE_OF_SESSION_KEY);
        return newSessionKey;

    
    }  else if (strcmp(split, "UntrustedSend") == 0) {

        char* temp;
        split = strtok(NULL, ":");
        char* machineReceivingMessage = split;
        split = strtok(NULL, ":");
        char* eventNum = split;
        split = strtok(NULL, ":");
        char* payload = split;

        int ptr;
        //TODO actually make this call a method in untrusted host (pong_enclave_attestation.cpp)
        sgx_status_t status = sendUntrustedMessageAPI(global_eid, &ptr, machineReceivingMessage, eventNum, payload, SIZE_OF_IDENTITY_STRING, SIZE_OF_MAX_EVENT_NAME, SIZE_OF_MAX_EVENT_PAYLOAD);
        return temp;

    } else if (strcmp(split, "Send") == 0) {

        char* temp;
        split = strtok(NULL, ":");
        char* machineSendingMessage = split;
        split = strtok(NULL, ":");
        char* machineReceivingMessage = split;
        split = strtok(NULL, ":");
        char* eventNum = split;
        split = strtok(NULL, ":");
        char* numArgs = split;
        split = strtok(NULL, ":");
        char* payload = split;

        int ptr;
        //TODO actually make this call a method in untrusted host (pong_enclave_attestation.cpp)
        sgx_status_t status = sendMessageAPI(global_eid, &ptr, machineSendingMessage,machineReceivingMessage, eventNum, numArgs, payload, SIZE_OF_IDENTITY_STRING, SIZE_OF_MAX_EVENT_NAME, SIZE_OF_MAX_EVENT_PAYLOAD);
        return temp;


    } else {
        return "Command Not Found";
    }
}


void* network_request_thread_wrapper(void* request) {
    return (void*) network_request_logic((char*) request);
}

//TODO change this API to take in who is sending the request
char* send_network_request_API(char* request) {
    char* requestCopy = (char*) malloc(strlen(request) + 1);
    // printf("Request: %s", request);
    memcpy( requestCopy, request, strlen(request) + 1);
    // printf("Request Copy: %s", requestCopy);

    void* thread_ret;
    pthread_t thread_id; 
    printf("\n Calling Network Request Thread\n"); 
    pthread_create(&thread_id, NULL, network_request_thread_wrapper, (void*) requestCopy);
    //TODO look into not calling pthread_join but actually let this run asynchoronous
    pthread_join(thread_id, &thread_ret); 
    printf("\n Finished Network Request Thread\n"); 

    return (char*) thread_ret;

}


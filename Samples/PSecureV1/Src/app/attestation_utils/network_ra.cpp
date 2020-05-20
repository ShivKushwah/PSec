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
#include "kps.h"
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include <unordered_map> 
#include "enclave_untrusted_host.h"


extern sgx_enclave_id_t global_eid;


unordered_map<string, int> MachineTypeToSecurityStatusOfMachine; //Map that contains all valid machines types as well as whether the machine type is SSM or USM
// unordered_map<string, int> MachinePublicIDToEnclaveNum; //Maps SSM identity -> the enclave on this machine in which it is hosted

//This method takes in a network payload and creates a thread to process the request
char* send_network_request_API(char* request, size_t requestSize) {
    char* requestCopy = (char*) malloc(requestSize);
    memcpy(requestCopy, request, requestSize);
    struct Network_Request_Wrapper parameters = {requestCopy, requestSize};

    void* thread_ret;
    pthread_t thread_id; 
    ocall_print("\n Calling Network Request Thread\n"); 
    pthread_create(&thread_id, NULL, network_request_thread_wrapper, (void*) &parameters);
    //TODO look into not calling pthread_join but actually let this run asynchoronously
    pthread_join(thread_id, &thread_ret); 
    ocall_print("\n Finished Network Request Thread\n"); 
    safe_free(requestCopy);

    return (char*) thread_ret;

}

void* network_request_thread_wrapper(void* parameters) {
    struct Network_Request_Wrapper* p = (struct Network_Request_Wrapper*)parameters;
    return (void*) network_request_logic(p->request, p->requestSize);
}

// 
char* network_request_logic(char* request, size_t requestSize) { 
    ocall_print("Network Request Received:");
    ocall_print(request);

    char* requestCopy = (char*) malloc(requestSize);
    memcpy(requestCopy, request, requestSize); 
    //NOTE Since I didn't update MAX_NETWORK_MESSAGE, this caused a weird memory bug last time when I increased size of public identity key

    char* split = strtok(requestCopy, ":");

    //if the incoming message is a "Create" message
    if (strcmp(split, "Create") == 0) {

        char* machineType;
        char* parentTrustedMachinePublicIDKey = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        memcpy(parentTrustedMachinePublicIDKey, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
        char* nextIndex = requestCopy + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1;

        char* newTokenizerString = (char*) malloc(SIZE_OF_MAX_EVENT_PAYLOAD);
        memcpy(newTokenizerString, nextIndex, SIZE_OF_MAX_EVENT_PAYLOAD);

        split = strtok(newTokenizerString, ":");
        machineType = split;
        
        ocall_print("machine type requested is :");
        ocall_print(machineType);
        
        //If this is a valid machine type
        if (MachineTypeToSecurityStatusOfMachine.count(string(machineType)) == 1) {

            return forward_request(request, requestSize);

        } else {
            return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        }

    
    }  else if (strcmp(split, "UntrustedCreate") == 0) {

        split = strtok(NULL, ":");
        char* machineType = split;
        ocall_print("machine type requested is :");
        ocall_print(machineType);
        if (MachineTypeToSecurityStatusOfMachine.count(string(machineType)) == 1) {

            return forward_request(request, requestSize);

        } else {
            return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        }
    
    } else if (strcmp(split, "InitComm") == 0) {

        char* machineInitializingComm;
        char* machineReceivingComm;

        // if (NETWORK_DEBUG) {
        //     split = strtok(NULL, ":");
        //     machineInitializingComm = split;
        //     split = strtok(NULL, ":");
        //     machineReceivingComm = split;
        //     ocall_print("machine Receiving comm is :");
        //     ocall_print(machineReceivingComm);
        // } else {
            // machineInitializingComm = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            // memcpy(machineInitializingComm, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            // machineReceivingComm = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            // memcpy(machineReceivingComm, request + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1, SGX_RSA3072_KEY_SIZE);
            // ocall_print("machine Receiving comm is :");
            // printRSAKey(machineReceivingComm);
            machineInitializingComm = (char*) malloc(SIZE_OF_RETURN_ID_AFTER_CREATE_REQUEST);
            memcpy(machineInitializingComm, request + strlen(split) + 1, SIZE_OF_RETURN_ID_AFTER_CREATE_REQUEST);
            machineReceivingComm = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingComm, request + strlen(split) + 1 + SIZE_OF_RETURN_ID_AFTER_CREATE_REQUEST + 1, SGX_RSA3072_KEY_SIZE);
            ocall_print("machine Receiving comm is :");
            printRSAKey(machineReceivingComm);
        // }

        
        // int count;
        // // if (NETWORK_DEBUG) {
        // //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingComm));
        // // } else {
        //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingComm, SGX_RSA3072_KEY_SIZE));
        // // }


        // if (count == 1) {
            // if (NETWORK_DEBUG)  {
            //     return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingComm)]);
            // } else {
                return forward_request(request, requestSize);
            // }

        // } else {
        //     ocall_print("Could not find in MachinePublicIDToEnclaveNum");
        //     printPayload(machineReceivingComm, SGX_RSA3072_KEY_SIZE);
        //     return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        // }

    
    }  else if (strcmp(split, "UntrustedSend") == 0) {

        char* machineSendingMessage;
        char* machineReceivingMessage;
        
            machineSendingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineSendingMessage, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            machineReceivingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingMessage, request + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1, SGX_RSA3072_KEY_SIZE);
            ocall_print("machine Receiving message is :");
            printRSAKey(machineReceivingMessage);

        // char* machineReceivingMessage;

        // // if (NETWORK_DEBUG) {
        // //     split = strtok(NULL, ":");
        // //     machineReceivingMessage = split;
        // //     ocall_print("machine Receiving message is :");
        // //     ocall_print(machineReceivingMessage);
        // // } else {
        //     machineReceivingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        //     memcpy(machineReceivingMessage, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
        //     ocall_print("machine Receiving message is :");
        //     printRSAKey(machineReceivingMessage);
        // }

        // int count;
        // // if (NETWORK_DEBUG) {
        // //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingMessage));
        // // } else {
        //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE));
        // // }
        

        // if (count == 1) {
            // if (NETWORK_DEBUG) {
            //     return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingMessage)]);
            // } else {

                return forward_request(request, requestSize);
            // }

        // } else {
        //     return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        // }

    } else if (strcmp(split, "Send") == 0) {

        char* machineSendingMessage;
        char* machineReceivingMessage;

            machineSendingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineSendingMessage, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            machineReceivingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingMessage, request + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1, SGX_RSA3072_KEY_SIZE);
            ocall_print("machine Receiving message is :");
            printRSAKey(machineReceivingMessage);
        // }

        // int count;
        // // if (NETWORK_DEBUG) {
        // //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingMessage));
        // // } else {
        //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE));
        // // }
        

        // if (count == 1) {
            // if (NETWORK_DEBUG) {
            //     return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingMessage)]);
            // } else {
                return forward_request(request, requestSize);
            // }

        // } else {
        //     return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        // }

    } else {
        return createStringLiteralMalloced("Command Not Found");
    }
}

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
    Encrypted_Message optional_Message)
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
                &p_resp_msg);
                //3);
                // *(optional_Message.encrypted_message));
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
        ra_samp_response_header_t* p_resp_msg = kps_exchange_capability_key(
                                (uint8_t*)optional_Message.encrypted_message, 
                                optional_Message.secret_size,
                                 optional_Message.payload_tag);
        
        *p_resp = p_resp_msg;

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
        safe_free(resp);
    }
}

char* forward_request(char* request, size_t requestSize) {
    return receiveNetworkRequest(request, requestSize);
    // if (redirect == 0 || redirect == -1) { //if it is a USM or a valid SSM
    //     return receiveNetworkRequest(request, requestSize);
    // } else {
    //     return createStringLiteralMalloced("ERROR:Request not forwarded!");
    // }
}

void network_request_logic_ocall(char* request, size_t requestSize) {
    //just for local RegisterMachine
    network_request_logic(request, requestSize);
}

// Initialize MachineTypeToSecurityStatusOfMachine map and start P Process if not started 
void initNetwork() {
    startPrtProcessIfNotStarted();

    for (int i = 0; i < program->nMachines; i++) {
        if (program->machines[i]->isSecure) {
            MachineTypeToSecurityStatusOfMachine[createString(program->machines[i]->name)] = 0;
        } else {
            MachineTypeToSecurityStatusOfMachine[createString(program->machines[i]->name)] = -1;
        }
    }
}


//TODO prevent memory leaks
struct RA_network_serialization_headers* deserialize_ra_network_headers(char* serialized_string) {

    struct RA_network_serialization_headers* returnHeaders = ( struct RA_network_serialization_headers*) malloc(sizeof(struct RA_network_serialization_headers));

    char* split = strtok(serialized_string , ":");

    char* sending_machine_name = split;
    returnHeaders->sending_machine_name = (char*) malloc(strlen(sending_machine_name) + 1);
    strncpy(returnHeaders->sending_machine_name, sending_machine_name, strlen(sending_machine_name) + 1);

    split = strtok(NULL , ":");
    char* receiving_machine_name = split;
    returnHeaders->receiving_machine_name = (char*) malloc(strlen(receiving_machine_name) + 1);
    strncpy(returnHeaders->receiving_machine_name, receiving_machine_name, strlen(receiving_machine_name) + 1);

    split = strtok(NULL , ":");
    char* p_req_size_string = split;
    int p_req_size = atoi(split);
    ra_samp_request_header_t* p_req_serial = (ra_samp_request_header_t*) malloc(sizeof(ra_samp_request_header_t) + p_req_size);
    if (p_req_size != 0) {
        memcpy((char*)p_req_serial, serialized_string + strlen(sending_machine_name) + 1 + strlen(receiving_machine_name) + 1 + strlen(p_req_size_string) + 1, sizeof(ra_samp_request_header_t) + p_req_size);

    } else {
        p_req_serial = NULL;
    }
    returnHeaders->p_req = p_req_serial;

    split = serialized_string + strlen(sending_machine_name) + 1 + strlen(receiving_machine_name) + 1 + strlen(p_req_size_string) + 1 + sizeof(ra_samp_request_header_t) + p_req_size + 1;
    char* optionalMessageSizeString  = strtok(split, ":");
    int optionalMessageSize = atoi(optionalMessageSizeString);

    
    if (optionalMessageSizeString == 0) {
        returnHeaders->optional_Message.encrypted_message = NULL;
        returnHeaders->optional_Message.secret_size = 0;
        returnHeaders->optional_Message.payload_tag = NULL;

    } else {
        returnHeaders->optional_Message.encrypted_message = (uint8_t*) malloc(optionalMessageSize);
        returnHeaders->optional_Message.secret_size = optionalMessageSize;
        returnHeaders->optional_Message.payload_tag = (uint8_t*) malloc(16);

        memcpy(returnHeaders->optional_Message.encrypted_message, split + strlen(optionalMessageSizeString) + 1, optionalMessageSize);
        memcpy(returnHeaders->optional_Message.payload_tag, split + strlen(optionalMessageSizeString) + 1 + optionalMessageSize + 1, 16);

    }

    return returnHeaders;


}

char* handle_socket_attestation_request(char* serializedString, int& responseSize) {
    RA_network_serialization_headers* deseralized = deserialize_ra_network_headers(serializedString);

    ra_samp_response_header_t *p_msg0_resp_full = NULL;

    // const ra_samp_request_header_t *p_req = (const ra_samp_request_header_t *) malloc(sizeof(const ra_samp_request_header_t));
    // memcpy(p_req, );

    int ret = ra_network_send_receive(deseralized->sending_machine_name,
            deseralized->receiving_machine_name,
            deseralized->p_req,
            &p_msg0_resp_full, deseralized->optional_Message);
    int size;
    if (p_msg0_resp_full != NULL) {
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

    if (p_msg0_resp_full != NULL) {
        memcpy(return_resp, p_msg0_resp_full, sizeof(ra_samp_response_header_t));

        for (int i = 0; i < size; i++) {
            return_resp->body[i] = p_msg0_resp_full->body[i];
        }
    }

    responseSize = sizeof(ra_samp_response_header_t) + size;

    return (char*)return_resp;


}

char* handle_socket_kps_generic_request(char* serializedString, int& responseSize) {
    ocall_print("KPS Network Request Received:");
    ocall_print(serializedString);

    char* response;

    char* split = strtok(serializedString, ":");
    char* kps = split;
    split = strtok(NULL, ":");
    if (strcmp(split, "IPRequestMachineType") == 0) {
        char* machineType = strtok(NULL, ":");
        response = queryIPAddressForMachineType(machineType, responseSize);
    } else {
        response = createStringLiteralMalloced("ERROR: Kps unsupported operation!");
        responseSize = strlen(response) + 1;
    }

    return response;
    
}

char* createStringLiteralMalloced(char* stringLiteral) {
    //TODO if modifying here, modify in helper.cpp
    char* malloced = (char*) malloc(99999);//strlen(stringLiteral));
    strncpy(malloced, stringLiteral, strlen(stringLiteral) + 1);
    return malloced;

}

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


unordered_map<string, int> TypeOfMachineToEnclaveNum;
unordered_map<string, int> MachinePublicIDToEnclaveNum;



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

char* forward_request(char* request, size_t requestSize, int redirect) {
    if (redirect == 0 || redirect == -1) {
        return receiveNetworkRequest(request, requestSize);
    // } else if (redirect == 1) {
    //     return untrusted_enclave2_receiveNetworkRequest(request);
    // } else if (redirect == 2) {
    //     return untrusted_enclave3_receiveNetworkRequest(request);
    } else {
        return createStringLiteralMalloced("ERROR:Request not forwarded!");
    }
}

char* network_request_logic(char* request, size_t requestSize) { //TODO Make this function generalizable for multiple enclaves and machines
    printf("Network Request Received: %s\n", request);

    char* requestCopy = (char*) malloc(requestSize);
    memcpy(requestCopy, request, requestSize); //NOTE Since I didn't update MAX_NETWORK_MESSAGE, this caused a weird memory bug last time when I increased size of public identity key

    char* split = strtok(requestCopy, ":");
    if (strcmp(split, "Create") == 0) {

        char* machineType;

        // if (NETWORK_DEBUG) {
        //     split = strtok(NULL, ":");
        //     char* parentTrustedMachinePublicIDKey = split;
        //     split = strtok(NULL, ":");
        //     machineType = split;
        // } else {
            char* parentTrustedMachinePublicIDKey = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(parentTrustedMachinePublicIDKey, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            char* nextIndex = requestCopy + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1;

            char* newTokenizerString = (char*) malloc(strlen(nextIndex) + 1);
            strncpy(newTokenizerString, nextIndex, strlen(nextIndex) + 1);

            split = strtok(newTokenizerString, ":");
            machineType = split;
            
            ocall_print("machine type requested is :");
            ocall_print(machineType);
        // }
        
        if (TypeOfMachineToEnclaveNum.count(string(machineType)) == 1) {

            return forward_request(request, requestSize, TypeOfMachineToEnclaveNum[machineType]);

        } else {
            return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        }

    
    }  else if (strcmp(split, "UntrustedCreate") == 0) {

        split = strtok(NULL, ":");
        char* machineType = split;
        ocall_print("machine type requested is :");
        ocall_print(machineType);
        if (TypeOfMachineToEnclaveNum.count(string(machineType)) == 1) {

            return forward_request(request, requestSize, TypeOfMachineToEnclaveNum[machineType]);

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
            machineInitializingComm = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineInitializingComm, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            machineReceivingComm = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingComm, request + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1, SGX_RSA3072_KEY_SIZE);
            ocall_print("machine Receiving comm is :");
            printRSAKey(machineReceivingComm);
        // }

        
        int count;
        // if (NETWORK_DEBUG) {
        //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingComm));
        // } else {
            count = MachinePublicIDToEnclaveNum.count(string(machineReceivingComm, SGX_RSA3072_KEY_SIZE));
        // }


        if (count == 1) {
            // if (NETWORK_DEBUG)  {
            //     return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingComm)]);
            // } else {
                return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingComm, SGX_RSA3072_KEY_SIZE)]);
            // }

        } else {
            return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        }

    
    }  else if (strcmp(split, "UntrustedSend") == 0) {

        char* machineReceivingMessage;

        // if (NETWORK_DEBUG) {
        //     split = strtok(NULL, ":");
        //     machineReceivingMessage = split;
        //     ocall_print("machine Receiving message is :");
        //     ocall_print(machineReceivingMessage);
        // } else {
            machineReceivingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingMessage, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            ocall_print("machine Receiving message is :");
            printRSAKey(machineReceivingMessage);
        // }

        int count;
        // if (NETWORK_DEBUG) {
        //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingMessage));
        // } else {
            count = MachinePublicIDToEnclaveNum.count(string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE));
        // }
        

        if (count == 1) {
            // if (NETWORK_DEBUG) {
            //     return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingMessage)]);
            // } else {
                return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE)]);
            // }

        } else {
            return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        }

    } else if (strcmp(split, "Send") == 0) {

        char* machineSendingMessage;
        char* machineReceivingMessage;

        // if (NETWORK_DEBUG) {
        //     split = strtok(NULL, ":");
        //     machineSendingMessage = split;
        //     split = strtok(NULL, ":");
        //     machineReceivingMessage = split;
        //     ocall_print("machine Receiving message is :");
        //     ocall_print(machineReceivingMessage);
        // } else {
            machineSendingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineSendingMessage, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            machineReceivingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingMessage, request + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1, SGX_RSA3072_KEY_SIZE);
            ocall_print("machine Receiving message is :");
            printRSAKey(machineReceivingMessage);
        // }

        int count;
        // if (NETWORK_DEBUG) {
        //     count = MachinePublicIDToEnclaveNum.count(string(machineReceivingMessage));
        // } else {
            count = MachinePublicIDToEnclaveNum.count(string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE));
        // }
        

        if (count == 1) {
            // if (NETWORK_DEBUG) {
            //     return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingMessage)]);
            // } else {
                return forward_request(request, requestSize, MachinePublicIDToEnclaveNum[string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE)]);
            // }

        } else {
            return createStringLiteralMalloced("ERROR:Machine Type Not Found!");
        }

    } else if (strcmp(split, "RegisterMachine") == 0) { //When a new machine is created, its public ID key should be registered with network_ra so that network knows who to forward the message to
        //TODO allow USMs to be registered as well, maybe make them be -1 ?
        char* publicIDRegister = NULL;
        char* enclaveNumRegister = NULL;
        // if (NETWORK_DEBUG) {
        //     split = strtok(NULL, ":");
        //     publicIDRegister = split;
        //     split = strtok(NULL, ":");
        //     enclaveNumRegister = split;
        //     if (enclaveNumRegister != NULL && enclaveNumRegister[0] != '\0' && enclaveNumRegister[0] == '-') {
        //         MachinePublicIDToEnclaveNum[string(publicIDRegister)] = -1;
        //     } else {
        //         MachinePublicIDToEnclaveNum[string(publicIDRegister)] = atoi(enclaveNumRegister);
        //     }
        // } else {
            publicIDRegister = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(publicIDRegister, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            enclaveNumRegister = (char*) malloc(10);
            strncpy(enclaveNumRegister, request + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1, 10);
            if (enclaveNumRegister != NULL && enclaveNumRegister[0] != '\0' && enclaveNumRegister[0] == '-') {
                MachinePublicIDToEnclaveNum[string(publicIDRegister, SGX_RSA3072_KEY_SIZE)] = -1;
            } else {
                MachinePublicIDToEnclaveNum[string(publicIDRegister, SGX_RSA3072_KEY_SIZE)] = atoi(enclaveNumRegister);
            }
            safe_free(publicIDRegister);
            safe_free(enclaveNumRegister);
        // }

        return createStringLiteralMalloced("Success!");


    } else {
        return createStringLiteralMalloced("Command Not Found");
    }
}

void initNetwork() {
    //NOTE -1 means untrusted machine
    startPrtProcessIfNotStarted();
    for (int i = 0; i < program->nMachines; i++) {
            if (program->machines[i]->isSecure) {
                TypeOfMachineToEnclaveNum[createString(program->machines[i]->name)] = 0;
            } else {
                TypeOfMachineToEnclaveNum[createString(program->machines[i]->name)] = -1;
            }
        }
    // TypeOfMachineToEnclaveNum[string("GodMachine")] = 0;
    // TypeOfMachineToEnclaveNum[string("BankEnclave")] = 0; 
    // TypeOfMachineToEnclaveNum[string("ClientEnclave")] = 0; 
    // TypeOfMachineToEnclaveNum[string("GodUntrusted")] = -1; 
    // TypeOfMachineToEnclaveNum[string("BankHost")] = -1; 
    // TypeOfMachineToEnclaveNum[string("ClientWebBrowser")] = -1; 

}


void* network_request_thread_wrapper(void* parameters) {
    struct Network_Request_Wrapper* p = (struct Network_Request_Wrapper*)parameters;
    return (void*) network_request_logic(p->request, p->requestSize);
}

//TODO change this API to take in who is sending the request
char* send_network_request_API(char* request, size_t requestSize) {
    char* requestCopy = (char*) malloc(requestSize);
    // printf("Request: %s", request);
    memcpy(requestCopy, request, requestSize);
    // printf("Request Copy: %s", requestCopy);

    struct Network_Request_Wrapper parameters = {requestCopy, requestSize};

    void* thread_ret;
    pthread_t thread_id; 
    printf("\n Calling Network Request Thread\n"); 
    pthread_create(&thread_id, NULL, network_request_thread_wrapper, (void*) &parameters);
    //TODO look into not calling pthread_join but actually let this run asynchoronous
    pthread_join(thread_id, &thread_ret); 
    printf("\n Finished Network Request Thread\n"); 
    safe_free(requestCopy);

    return (char*) thread_ret;

}

char* createStringLiteralMalloced(char* stringLiteral) {
    //TODO if modifying here, modify in helper.cpp
    char* malloced = (char*) malloc(strlen(stringLiteral));
    strncpy(malloced, stringLiteral, strlen(stringLiteral) + 1);
    return malloced;

}

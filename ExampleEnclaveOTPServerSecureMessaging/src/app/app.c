#include "stdio.h"
#include "enclave_u.h"
#include "enclave2_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include "OTPServer.h"

static PRT_BOOLEAN cooperative = PRT_FALSE;
static int threads = 1;

static PRT_BOOLEAN perf = PRT_FALSE;
static long steps = 0;
static long startTime = 0;
static long perfEndTime = 0;
static const char* parg = NULL;
static const char* workspaceConfig;

extern int Delta;

// UNTRUSTED

sgx_enclave_id_t destination_enclave_id;
uint32_t destination_enclave_num;
//TODO: Hardcoded (for enclave1 -> enclave2) for now, need to implement Map in c code

// END UNTRUSTED

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

sgx_enclave_id_t global_eid2 = 0;


void ErrorHandler(PRT_STATUS status, PRT_MACHINEINST *ptr)
{
    if (status == PRT_STATUS_ASSERT)
    {
        ocall_print("exiting with PRT_STATUS_ASSERT (assertion failure)\n");
        // exit(1);
    }
    else if (status == PRT_STATUS_EVENT_OVERFLOW)
    {
        ocall_print("exiting with PRT_STATUS_EVENT_OVERFLOW\n");
        // exit(1);
    }
    else if (status == PRT_STATUS_EVENT_UNHANDLED)
    {
        ocall_print("exiting with PRT_STATUS_EVENT_UNHANDLED\n");
        // exit(1);
    }
    else if (status == PRT_STATUS_QUEUE_OVERFLOW)
    {
        ocall_print("exiting with PRT_STATUS_QUEUE_OVERFLOW \n");
        // exit(1);
    }
    else if (status == PRT_STATUS_ILLEGAL_SEND)
    {
        ocall_print("exiting with PRT_STATUS_ILLEGAL_SEND \n");
        // exit(1);
    }
    else
    {
        ocall_print("unexpected PRT_STATUS in ErrorHandler: \n");
        // exit(2);
    }

}


void Log(PRT_STEP step, PRT_MACHINESTATE* senderState, PRT_MACHINEINST *receiver, PRT_VALUE* event, PRT_VALUE* payload)
{ 
    PrtPrintStep(step, senderState, receiver, event, payload);
}

void MyAssert(PRT_INT32 condition, PRT_CSTRING message)
{
	if (condition != 0)
	{
		return;
	}
	else if (message == NULL)
	{
		ocall_print("ASSERT");
	}
	else
	{
		ocall_print("ASSERT: ");
        ocall_print(message);
	}
	// exit(1);
}


static void RunToIdle(void* process)
{
    // In the tester we run the state machines until there is no more work to do then we exit
    // instead of blocking indefinitely.  This is then equivalent of the non-cooperative case
    // where we PrtRunStateMachine once (inside PrtMkMachine).  So we do NOT call PrtWaitForWork.
    
    PRT_PROCESS_PRIV* privateProcess = (PRT_PROCESS_PRIV*)process;
	while (privateProcess->terminating == PRT_FALSE)
	{
		PRT_STEP_RESULT result = PrtStepProcess((PRT_PROCESS*) process);
		switch (result) {
		case PRT_STEP_TERMINATING:
			break;
		case PRT_STEP_IDLE:
			PrtWaitForWork((PRT_PROCESS*)process);
			break;
		case PRT_STEP_MORE:
			PrtYieldThread();
			break;
		}
	}
}



// OCall implementations
void ocall_print(const char* str) {
    printf("%s\n", str);
}

void ocall_print_int(int print_int) {
    printf("%d\n", print_int);
}

int main(int argc, char const *argv[]) {

    PRT_DBG_START_MEM_BALANCED_REGION
        {
            PRT_PROCESS *process;
            PRT_GUID processGuid;
            PRT_VALUE *payload;

            processGuid.data1 = 1;
            processGuid.data2 = 0;
            processGuid.data3 = 0;
            processGuid.data4 = 0;
            process = PrtStartProcess(processGuid, &P_GEND_IMPL_DefaultImpl, ErrorHandler, Log);
            ocall_print("Process started!\n");
            if (cooperative)
            {
                PrtSetSchedulingPolicy(process, PRT_SCHEDULINGPOLICY_COOPERATIVE);
            }
            if (parg == NULL)
            {
                payload = PrtMkNullValue();
            }
            else
            {
                int i = atoi(parg);
                payload = PrtMkIntValue(i);
            }

            PrtUpdateAssertFn(MyAssert);
            ocall_print("update assert fn executed!\n");

            PRT_UINT32 mainMachine = 0;
            PRT_BOOLEAN foundMachine = PrtLookupMachineByName("IntializerMachine", &mainMachine);
            PrtAssert(foundMachine, "No 'Main' machine found!");
            PrtMkMachine(process, mainMachine, 1, &payload);
            ocall_print("mk machine command executed!\n");
            PrtFreeValue(payload);
            PrtStopProcess(process);
        }
        PRT_DBG_END_MEM_BALANCED_REGION

    return 0;
}

////--- untrusted mesaging

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


// #include "sgx_eid.h"
#include "error_codes.h"
#include "datatypes.h"
// #include "sgx_urts.h"
// #include "UntrustedEnclaveMessageExchange.h"
#include "sgx_dh.h"
//#include <map>



// std::map<sgx_enclave_id_t, uint32_t>g_enclave_id_map;

//Makes an sgx_ecall to the destination enclave to get session id and message1
ATTESTATION_STATUS session_request_ocall(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, sgx_dh_msg1_t* dh_msg1, uint32_t* session_id)
{
	uint32_t status = 0;
	sgx_status_t ret = SGX_SUCCESS;
	uint32_t temp_enclave_no;

	if (destination_enclave_id == dest_enclave_id) {
		temp_enclave_no = destination_enclave_num;

	} else {
		return INVALID_SESSION;

	}

	// std::map<sgx_enclave_id_t, uint32_t>::iterator it = g_enclave_id_map.find(dest_enclave_id);
    // if(it != g_enclave_id_map.end())
	// {
	// 	temp_enclave_no = it->second;
	// }
    // else
	// {
	// 	return INVALID_SESSION;
	// }


	switch(temp_enclave_no)
	{
		case 1:
			ret = session_request(dest_enclave_id, &status, src_enclave_id, dh_msg1, session_id);
			break;
		case 2:
			ret = session_request_enclave2(dest_enclave_id, &status, src_enclave_id, dh_msg1, session_id);
			break;
	}
	if (ret == SGX_SUCCESS)
		return (ATTESTATION_STATUS)status;
	else	
	    return INVALID_SESSION;

}
//Makes an sgx_ecall to the destination enclave sends message2 from the source enclave and gets message 3 from the destination enclave
ATTESTATION_STATUS exchange_report_ocall(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, sgx_dh_msg2_t *dh_msg2, sgx_dh_msg3_t *dh_msg3, uint32_t session_id)
{
	uint32_t status = 0;
	sgx_status_t ret = SGX_SUCCESS;
	uint32_t temp_enclave_no;

	if (destination_enclave_id == dest_enclave_id) {
		temp_enclave_no = destination_enclave_num;

	} else {
		return INVALID_SESSION;

	}

	// std::map<sgx_enclave_id_t, uint32_t>::iterator it = g_enclave_id_map.find(dest_enclave_id);
    // if(it != g_enclave_id_map.end())
	// {
	// 	temp_enclave_no = it->second;
	// }
    // else
	// {
	// 	return INVALID_SESSION;
	// }


	switch(temp_enclave_no)
	{
		case 1:
			ret = exchange_report(dest_enclave_id, &status, src_enclave_id, dh_msg2, dh_msg3, session_id);
			break;
		case 2:
			ret = exchange_report_enclave2(dest_enclave_id, &status, src_enclave_id, dh_msg2, dh_msg3, session_id);
			break;
	}
	if (ret == SGX_SUCCESS)
		return (ATTESTATION_STATUS)status;
	else	
	    return INVALID_SESSION;

}

//Make an sgx_ecall to the destination enclave function that generates the actual response
ATTESTATION_STATUS send_request_ocall(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id,secure_message_t* req_message, size_t req_message_size, size_t max_payload_size, secure_message_t* resp_message, size_t resp_message_size)
{
	uint32_t status = 0;
    sgx_status_t ret = SGX_SUCCESS;
	uint32_t temp_enclave_no;

	if (destination_enclave_id == dest_enclave_id) {
		temp_enclave_no = destination_enclave_num;

	} else {
		return INVALID_SESSION;

	}

	// std::map<sgx_enclave_id_t, uint32_t>::iterator it = g_enclave_id_map.find(dest_enclave_id);
    // if(it != g_enclave_id_map.end())
	// {
	// 	temp_enclave_no = it->second;
	// }
    // else
	// {
	// 	return INVALID_SESSION;
	// }



	switch(temp_enclave_no)
	{
		case 1:
			ret = generate_response(dest_enclave_id, &status, src_enclave_id, req_message, req_message_size, max_payload_size, resp_message, resp_message_size);
			break;
		case 2:
			ret = generate_response_enclave2(dest_enclave_id, &status, src_enclave_id, req_message, req_message_size, max_payload_size, resp_message, resp_message_size);
			break;
	}
	if (ret == SGX_SUCCESS)
		return (ATTESTATION_STATUS)status;
	else	
	    return INVALID_SESSION;

}

//Make an sgx_ecall to the destination enclave to close the session
ATTESTATION_STATUS end_session_ocall(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id)
{
	uint32_t status = 0;
	sgx_status_t ret = SGX_SUCCESS;
	uint32_t temp_enclave_no;

	if (destination_enclave_id == dest_enclave_id) {
		temp_enclave_no = destination_enclave_num;

	} else {
		return INVALID_SESSION;

	}

	// std::map<sgx_enclave_id_t, uint32_t>::iterator it = g_enclave_id_map.find(dest_enclave_id);
    // if(it != g_enclave_id_map.end())
	// {
	// 	temp_enclave_no = it->second;
	// }
    // else
	// {
	// 	return INVALID_SESSION;
	// }



	switch(temp_enclave_no)
	{
		case 1:
			ret = end_session(dest_enclave_id, &status, src_enclave_id);
			break;
		case 2:
			ret = end_session_enclave2(dest_enclave_id, &status, src_enclave_id);
			break;
	}
	if (ret == SGX_SUCCESS)
		return (ATTESTATION_STATUS)status;
	else	
	    return INVALID_SESSION;

}


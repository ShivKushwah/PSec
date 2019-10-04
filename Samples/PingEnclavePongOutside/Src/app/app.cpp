#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"
#include "PingPong.h"

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

static PRT_BOOLEAN cooperative = PRT_FALSE;
static int threads = 1;

static PRT_BOOLEAN perf = PRT_FALSE;
static long steps = 0;
static long startTime = 0;
static long perfEndTime = 0;
static const char* parg = NULL;
static const char* workspaceConfig;


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
    printf("[o] %s\n", str);
}

int main(int argc, char const *argv[]) {


    PRT_PROCESS *process;
		PRT_GUID processGuid;
		PRT_VALUE *payload;
        		PRT_VALUE *payload2;


		processGuid.data1 = 1;
		processGuid.data2 = 0;
		processGuid.data3 = 0;
		processGuid.data4 = 0;
		process = PrtStartProcess(processGuid, &P_GEND_IMPL_DefaultImpl, ErrorHandler, Log);
        ocall_print("after start process!\n");
        if (cooperative)
        {
            PrtSetSchedulingPolicy(process, PRT_SCHEDULINGPOLICY_COOPERATIVE);
        }
		if (parg == NULL)
		{
			payload = PrtMkNullValue();
            payload2 = PrtMkNullValue();

		}
		else
		{
			int i = atoi(parg);
			payload = PrtMkIntValue(i);
            payload2 = PrtMkIntValue(i);

            
		}

        //payload2 = PrtMkIntValue(7);

		PrtUpdateAssertFn(MyAssert);
        ocall_print("after update assert fn!\n");

        // PRT_UINT32 mainMachine2 = 1;
		// PRT_BOOLEAN foundMachine2 = PrtLookupMachineByName("Pong", &mainMachine2);
		// PrtAssert(foundMachine2, "No 'Pong' machine found!");
		// PRT_MACHINEINST* pongMachine = PrtMkMachine(process, mainMachine2, 1, &payload2);

        // PRT_MACHINEID id2;
        // id2.machineId = mainMachine2;
	    // id2.processId = processGuid;


        // payload = PrtMkMachineValue(id2);

        PRT_UINT32 mainMachine = 0;
		PRT_BOOLEAN foundMachine = PrtLookupMachineByName("Ping", &mainMachine);
		PrtAssert(foundMachine, "No 'Ping' machine found!");
		PRT_MACHINEINST* pingMachine = PrtMkMachine(process, mainMachine, 1, &payload);

        PRT_VALUE *pongPayload = PrtMkNullValue();
        PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
        //PRT_MACHINESTATE state;
	    //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, (PRT_MACHINESTATE*)&state);
        PrtSend(NULL, pingMachine, pongEvent, 0);
    
        
        printf("after mk machine!\n");

        if (cooperative)
        {
            // test some multithreading across state machines.
            /*
            typedef void *(*start_routine) (void *);
            pthread_t tid[threads];
            for (int i = 0; i < threads; i++)
            {
                pthread_create(&tid[i], NULL, (start_routine)RunToIdle, (void*)process);
            }
            for (int i = 0; i < threads; i++)
            {
                pthread_join(tid[i], NULL);
            }
            */
        }
        //PrtFreeValue(pongPayload);
                //PrtFreeValue(pongEvent);


		PrtFreeValue(payload);
		PrtStopProcess(process);







    // PRT_DBG_START_MEM_BALANCED_REGION
    //     {
    //        PRT_PROCESS *process;
	// 	PRT_GUID processGuid;
	// 	PRT_VALUE *payload;
    //     		PRT_VALUE *payload2;


	// 	processGuid.data1 = 1;
	// 	processGuid.data2 = 0;
	// 	processGuid.data3 = 0;
	// 	processGuid.data4 = 0;
	// 	process = PrtStartProcess(processGuid, &P_GEND_IMPL_DefaultImpl, ErrorHandler, Log);
    //     ocall_print("after start process!\n");
    //     if (cooperative)
    //     {
    //         PrtSetSchedulingPolicy(process, PRT_SCHEDULINGPOLICY_COOPERATIVE);
    //     }
	// 	if (parg == NULL)
	// 	{
	// 		payload = PrtMkNullValue();
    //         payload2 = PrtMkNullValue();

	// 	}
	// 	else
	// 	{
	// 		int i = atoi(parg);
	// 		payload = PrtMkIntValue(i);
    //         payload2 = PrtMkIntValue(i);

            
	// 	}

    //     //payload2 = PrtMkIntValue(7);

	// 	PrtUpdateAssertFn(MyAssert);
    //     ocall_print("after update assert fn!\n");

    //     PRT_UINT32 mainMachine2 = 1;
	// 	PRT_BOOLEAN foundMachine2 = PrtLookupMachineByName("Pong", &mainMachine2);
	// 	PrtAssert(foundMachine2, "No 'Pong' machine found!");
	// 	PrtMkMachine(process, mainMachine2, 1, &payload2);

    //     PRT_MACHINEID id;
    //     id.machineId = mainMachine2;
	//     id.processId = processGuid;


    //     payload = PrtMkMachineValue(id);

    //     PRT_UINT32 mainMachine = 0;
	// 	PRT_BOOLEAN foundMachine = PrtLookupMachineByName("Ping", &mainMachine);
	// 	PrtAssert(foundMachine, "No 'Ping' machine found!");
	// 	PrtMkMachine(process, mainMachine, 1, &payload);
        
    //     ocall_print("after mk machine!\n");

    //         ocall_print("mk machine command executed!\n");
    //         PrtFreeValue(payload);
    //         PrtStopProcess(process);
    //     }
    //     PRT_DBG_END_MEM_BALANCED_REGION




    // if (initialize_enclave(&global_eid, "enclave.token", "enclave.signed.so") < 0) {
    //     std::cout << "Fail to initialize enclave." << std::endl;
    //     return 1;
    // }
    // int ptr;
    // sgx_status_t status = enclave_main(global_eid, &ptr);
    // std::cout << status << std::endl;
    // if (status != SGX_SUCCESS) {
    //     std::cout << "noob" << std::endl;
    // }
    return 0;
}

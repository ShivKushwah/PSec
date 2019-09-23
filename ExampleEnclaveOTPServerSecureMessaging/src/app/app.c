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


// Custom P function implementation (ForeignTypes)
void P_SaveOTPSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE** P_VAR_payload = argRefs[0];
    int secret = PrtPrimGetInt(*P_VAR_payload);

	printf("Entering Enclave to Save OTP Secret:\n");

    if (initialize_enclave(&global_eid, "enclave.token", "enclave.signed.so") < 0) {
        printf("Failed to initialize Enclave \n");
        return 1;
    }
    int ptr;
    sgx_status_t status = save_otp_secret(global_eid, &ptr, secret);
    if (status != SGX_SUCCESS) {
        printf("ENCLAVE ERROR\n");
    }
    if (ptr == 1) {
        printf("Exited Enclave Successfully\n");
    }
}

PRT_VALUE* P_GetOTPSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

    printf("Entering Enclave to retrieve OTP secret:\n");

    int ptr;
    sgx_status_t status = get_otp_secret(global_eid, &ptr);
    if (status != SGX_SUCCESS) {
        printf("Enclave Error!\n");
    }

    printf("Exited Enclave Successfully\n");

    return PrtMkIntValue(ptr);
}

void P_EnclaveCallTwo_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

    printf("Entering Enclave2:\n");

    if (initialize_enclave(&global_eid2, "enclave2.token", "enclave2.signed.so") < 0) {
        printf("Failed to initialize Enclave 2 \n");
        return 1;
    }
    int ptr;
    sgx_status_t status = generate_random_number(global_eid2, &ptr);
    if (status != SGX_SUCCESS) {
        printf("Enclave2 Error!\n");
    }

    printf("Exited Enclave 2 Successfully\n");
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

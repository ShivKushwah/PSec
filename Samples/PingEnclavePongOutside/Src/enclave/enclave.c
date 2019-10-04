#include "PingPongEnclave.h"
//#include "PingPong.c"

		PRT_PROCESS *process;
        PRT_MACHINEINST* pongMachine;
                PRT_MACHINEINST* pingMachine;




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



static PRT_BOOLEAN cooperative = PRT_FALSE;
static int threads = 1;

// todo: make tester useful for performance testing also, not finished yet...
static PRT_BOOLEAN perf = PRT_FALSE;
static long steps = 0;
static long startTime = 0;
static long perfEndTime = 0;
static const char* parg = NULL;
static const char* workspaceConfig;

void Log(PRT_STEP step, PRT_MACHINESTATE* senderState, PRT_MACHINEINST *receiver, PRT_VALUE* event, PRT_VALUE* payload)
{ 
    PrtPrintStep(step, senderState, receiver, event, payload);
}

static void PrintUsage(void)
{
    ocall_print("Usage: Tester [options]\n");
    ocall_print("This program tests the compiled state machine in program.c and program.h\n");
    ocall_print("Options:\n");
	ocall_print("	-w [path]		[path] represents the path to the workspace config file\n");
    ocall_print("   -cooperative     run state machine with the cooperative scheduler\n");
	ocall_print("   -threads [n]     run P using multiple threads\n");
	ocall_print("   -perf [n]        run performance test that outputs #steps every 10 seconds, terminating after n seconds\n");
	ocall_print("   -arg [x]         pass argument 'x' to P main machine\n");
}

static void RunPerfTest()
{

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
		PRT_STEP_RESULT result = PrtStepProcess(process);
		switch (result) {
		case PRT_STEP_TERMINATING:
			break;
		case PRT_STEP_IDLE:
			PrtWaitForWork(process);
			break;
		case PRT_STEP_MORE:
			PrtYieldThread();
			break;
		}
	}
}

void P_SecureReceive_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{

    //  PRT_VALUE *pongPayload = PrtMkNullValue();
    //     PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    //             PRT_VALUE* pingEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Ping.value));
    //     PRT_MACHINEID pongId;
    //     pongId.machineId = 1;

    //     PRT_MACHINEINST* pongMachine = PrtGetMachine(process, PrtMkMachineValue(pongId));
    //     //PRT_MACHINESTATE state;
	//     //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, (PRT_MACHINESTATE*)&state);
    //     PrtSend(NULL, pongMachine, pingEvent, 0);

     


    //  PRT_VALUE *pongPayload = PrtMkNullValue();
    //     PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    //     //PRT_MACHINESTATE state;
	//     //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, (PRT_MACHINESTATE*)&state);
    //     PRT_MACHINEID pingId;
    //     pingId.machineId = 0;

    

    //    PRT_MACHINEINST* pingMachine = context;//PrtGetMachine(process, PrtMkMachineValue(pingId));
    //     PrtSend(NULL, pingMachine, pongEvent, 0);

    // PRT_VALUE *pongPayload = PrtMkNullValue();
    //     PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    //     //PRT_MACHINESTATE state;
	//     //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, (PRT_MACHINESTATE*)&state);
    //     PrtSend(NULL, context, pongEvent, 0);
    
   
}

int send_ping_enclave(void) {

     PRT_VALUE *pongPayload = PrtMkNullValue();
        PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
                PRT_VALUE* pingEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Ping.value));
        PRT_MACHINEID pongId;
        pongId.machineId = 1;

        PRT_MACHINEINST* pongMachine = PrtGetMachine(process, PrtMkMachineValue(pongId));
        //PRT_MACHINESTATE state;
	    //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, (PRT_MACHINESTATE*)&state);
        PrtSend(NULL, pongMachine, pingEvent, 0);

   

    // PRT_VALUE *pongPayload = PrtMkNullValue();
    //     PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    //     //PRT_MACHINESTATE state;
	//     //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, (PRT_MACHINESTATE*)&state);
    //     PRT_MACHINEID pingId;
    //     pingId.machineId = 0;

    

    //   // PRT_MACHINEINST* pingMachine = context;//PrtGetMachine(process, PrtMkMachineValue(pingId));
    //     PrtSend(NULL, pingMachine, pongEvent, 0);

    // PRT_VALUE *pongPayload = PrtMkNullValue();
    //     PRT_VALUE* pingEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Ping.value));
    //     //PRT_MACHINESTATE state;
	//     //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, (PRT_MACHINESTATE*)&state);
    // //     PRT_MACHINEID pingId;
    // //     pingId.machineId = 0;

    

    // //    PRT_MACHINEINST* pingMachine = PrtGetMachine(process, PrtMkMachineValue(pingId));
    //     PrtSend(NULL, pongMachine, pingEvent, 0);

    // PRT_VALUE *pongPayload = PrtMkNullValue();
    //     PRT_VALUE* pongEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Pong.value));
    //             PRT_VALUE* pingEvent = PrtMkEventValue(PrtPrimGetEvent(&P_EVENT_Ping.value));
    //     PRT_MACHINEID pongId;
    //     pongId.machineId = 1;

    //     PRT_MACHINEINST* pongMachine = PrtGetMachine(process, PrtMkMachineValue(pongId));
    //     //PRT_MACHINESTATE state;
	//     //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, (PRT_MACHINESTATE*)&state);
    //     PrtSend(NULL, pongMachine, pingEvent, 0);

        return 0;


}


extern int Delta;

int enclave_main(void)
{
    ocall_print("hello, world!\n");
	//PRT_DBG_START_MEM_BALANCED_REGION
	//{
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

        PRT_UINT32 mainMachine2 = 1;
		PRT_BOOLEAN foundMachine2 = PrtLookupMachineByName("Pong", &mainMachine2);
		PrtAssert(foundMachine2, "No 'Pong' machine found!");
		pongMachine = PrtMkMachine(process, mainMachine2, 1, &payload2);

        PRT_MACHINEID id2;
        id2.machineId = mainMachine2;
	    id2.processId = processGuid;


        // payload = PrtMkMachineValue(id2);

        PRT_UINT32 mainMachine = 0;
		PRT_BOOLEAN foundMachine = PrtLookupMachineByName("Ping", &mainMachine);
		PrtAssert(foundMachine, "No 'Ping' machine found!");
		 pingMachine = PrtMkMachine(process, mainMachine, 1, &payload);

        PRT_VALUE *pongPayload = PrtMkNullValue();
        PRT_VALUE* pongEvent = &P_EVENT_Pong.value;
        //PRT_VALUE* state = &P_STATE_Ping_Ping_WaitPong.value;
        //PRT_MACHINESTATE state;
	    //PrtGetMachineState((PRT_MACHINEINST*)pongMachine, &state);

        // PrtSendPrivate(&state, pingMachine, pongEvent, pongPayload); //THis line works but crashes program. Maybe becuase of NULL?

        PRT_MACHINEID id;
        id.machineId = mainMachine;
	    id.processId = processGuid;


        PRT_VALUE *pingPayload = PrtMkNullValue();
        PRT_VALUE* pingEvent = &P_EVENT_Ping.value;
       // int bro = PrtMapGet(((PRT_MACHINEINST_PRIV*)pongMachine)->recvMap, PrtMkMachineValue(id2))->valueUnion.nt;
        //ocall_print("KRIAT: %d", bro);
        //PrtEnqueueInOrder(PrtMkMachineValue(id2), 0,pingMachine, pongEvent, pongPayload);
               // PrtEnqueueInOrder(PrtMkMachineValue(id2), 1,pongMachine, pingEvent, pingPayload); //seqNum by PrtMapGet?


        
        ocall_print("after mk machine!\n");

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


		//PrtFreeValue(payload);
		//PrtStopProcess(process);
	//}
	//PRT_DBG_END_MEM_BALANCED_REGION

	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	//_CrtDumpMemoryLeaks();
}

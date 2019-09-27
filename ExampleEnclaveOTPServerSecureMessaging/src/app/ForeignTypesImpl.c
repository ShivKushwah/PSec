#include "OTPServer.h"
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"

extern sgx_enclave_id_t global_eid;
extern sgx_enclave_id_t global_eid2;

extern sgx_enclave_id_t destination_enclave_id;
extern uint32_t destination_enclave_num;

PRT_VALUE* P_EnclaveOneInitialize_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    if (initialize_enclave(&global_eid, "enclave.token", "enclave.signed.so") < 0) {
        printf("Failed to initialize Enclave 1 \n");
    }
   
}


PRT_VALUE* P_EnclaveTwoInitialize_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    if (initialize_enclave(&global_eid2, "enclave2.token", "enclave2.signed.so") < 0) {
        printf("Failed to initialize Enclave 2 \n");
    }
   
}

void P_EnclaveOneSendSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    char* secret = "12344";

    printf("Entering Enclave1 to send Secret to Enclave2:\n");

    destination_enclave_id = global_eid2;
    destination_enclave_num = 2;
    //TODO: Hardcoded for now, need to implement Map in c code

    uint32_t ret_status;
    sgx_status_t status;

    status = test_create_session(global_eid, &ret_status, global_eid, global_eid2);
    if (status!=SGX_SUCCESS)
    {
        printf("Enclave1_test_create_session Ecall failed: Error code is %x", status);
    }
    else
    {
        if(ret_status==0)
        {
            printf("\nSecure Channel Establishment between Source (E1) and Destination (E2) Enclaves successful !!!");
        }
        else
        {
            printf("\nSession establishment and key exchange failure between Source (E1) and Destination (E2): Error code is %x", ret_status);
        }
    }
    //Test message exchange between Enclave1(Source) and Enclave2(Destination)
    status = test_message_exchange(global_eid, &ret_status, global_eid, global_eid2, secret, 6);
    if (status!=SGX_SUCCESS)
    {
        printf("Enclave1_test_message_exchange Ecall failed: Error code is %x", status);
    }
    else
    {
        if(ret_status==0)
        {
            printf("\nMessage Exchange between Source (E1) and Destination (E2) Enclaves successful !!!");
        }
        else
        {
            printf("\nMessage Exchange failure between Source (E1) and Destination (E2): Error code is %x", ret_status);
        }
    }


    //Test Closing Session between Enclave1(Source) and Enclave2(Destination)
    status = test_close_session(global_eid, &ret_status, global_eid, global_eid2);
    if (status!=SGX_SUCCESS)
    {
        printf("Enclave1_test_close_session Ecall failed: Error code is %x", status);
    }
    else
    {
        if(ret_status==0)
        {
            printf("\nClose Session between Source (E1) and Destination (E2) Enclaves successful !!!\n");
        }
        else
        {
            printf("\nClose session failure between Source (E1) and Destination (E2): Error code is %x", ret_status);
        }
    }

    printf("Exited Enclave 1 Successfully\n");     
}

PRT_VALUE* P_EnclaveOneVerifyOTPCode_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE** P_VAR_payload = argRefs[0];
    int code = PrtPrimGetInt(*P_VAR_payload);

    printf("Entering Enclave1 to verify OTP Code:\n");
    int ptr;
    sgx_status_t status = verify_OTP_code(global_eid, &ptr, code);
    if (status != SGX_SUCCESS) {
        printf("Enclave1 Error!\n");
    }

    printf("Exited Enclave 1 Successfully\n");  
    return PrtMkIntValue(ptr);
   
}


PRT_VALUE* P_EnclaveTwoGenerateOTPCode_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    printf("Entering Enclave2 to generate OTP Code:\n");

    int ptr;
    sgx_status_t status = generate_OTP_code(global_eid2, &ptr);
    if (status != SGX_SUCCESS) {
        printf("Enclave2 Error!\n");
    }

    printf("Exited Enclave 2 Successfully\n");  
    return PrtMkIntValue(ptr);
   
}
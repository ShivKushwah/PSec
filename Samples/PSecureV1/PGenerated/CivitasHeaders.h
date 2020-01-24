#pragma once
#ifndef P_CIVITASHEADERS_H_
#define P_CIVITASHEADERS_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_BankPublicIDEvent;
    extern PRT_EVENTDECL P_EVENT_PublicIDEvent;
    extern PRT_EVENTDECL P_EVENT_MasterSecretEvent;
    extern PRT_EVENTDECL P_EVENT_GenerateOTPCodeEvent;
    extern PRT_EVENTDECL P_EVENT_OTPCodeEvent;
    extern PRT_EVENTDECL P_EVENT_MapEvent;
    extern PRT_EVENTDECL P_EVENT_AuthenticateRequest;
    extern PRT_EVENTDECL P_EVENT_AuthSuccess;
    extern PRT_EVENTDECL P_EVENT_AuthFailure;
    extern PRT_INTERFACEDECL P_I_InitializerMachine;
    extern PRT_MACHINEDECL P_MACHINE_InitializerMachine;
    extern PRT_TYPE* P_TYPEDEF_StringType;
    extern PRT_TYPE* P_TYPEDEF_machine_handle;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_CIVITASHEADERS_H_

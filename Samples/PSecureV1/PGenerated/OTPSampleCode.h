#pragma once
#ifndef P_OTPSAMPLECODE_H_
#define P_OTPSAMPLECODE_H_
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
    extern PRT_INTERFACEDECL P_I_UntrustedInitializer;
    extern PRT_INTERFACEDECL P_I_TrustedInitializer;
    extern PRT_INTERFACEDECL P_I_BankEnclave;
    extern PRT_INTERFACEDECL P_I_ClientEnclave;
    extern PRT_INTERFACEDECL P_I_ClientWebBrowser;
    extern PRT_MACHINEDECL P_MACHINE_UntrustedInitializer;
    extern PRT_MACHINEDECL P_MACHINE_TrustedInitializer;
    extern PRT_MACHINEDECL P_MACHINE_BankEnclave;
    extern PRT_MACHINEDECL P_MACHINE_ClientEnclave;
    extern PRT_MACHINEDECL P_MACHINE_ClientWebBrowser;
    extern PRT_TYPE* P_TYPEDEF_StringType;
    extern PRT_TYPE* P_TYPEDEF_machine_handle;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_OTPSAMPLECODE_H_

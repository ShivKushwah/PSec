#pragma once
#ifndef P_HEALTHANALYSISCLIENT_H_
#define P_HEALTHANALYSISCLIENT_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDSecureHealthAnalyzerIDEvent;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDReceiveUserEnclaveIDEvent;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDUserEnclaveIDEvent;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDHealthInfoEvent;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDHealthInfoResultEvent;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDSecureHealthAnalyzerIDEvent;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDProvisionUserEnclave;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDHealthInfoEvent;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDHealthInfoResultEvent;
    extern PRT_FUNDECL P_FUNCTION_seal;
    extern PRT_INTERFACEDECL P_I_UserEnclave;
    extern PRT_INTERFACEDECL P_I_User;
    extern PRT_INTERFACEDECL P_I_UntrustedInitializer;
    extern PRT_INTERFACEDECL P_I_TrustedInitializer;
    extern PRT_INTERFACEDECL P_I_SecureHealthAnalyzer;
    extern PRT_INTERFACEDECL P_I_awsMLHost;
    extern PRT_MACHINEDECL P_MACHINE_UserEnclave;
    extern PRT_MACHINEDECL P_MACHINE_User;
    extern PRT_MACHINEDECL P_MACHINE_UntrustedInitializer;
    extern PRT_MACHINEDECL P_MACHINE_TrustedInitializer;
    extern PRT_MACHINEDECL P_MACHINE_SecureHealthAnalyzer;
    extern PRT_MACHINEDECL P_MACHINE_awsMLHost;
    extern PRT_TYPE* P_TYPEDEF_StringType;
    extern PRT_TYPE* P_TYPEDEF_machine_handle;
    extern PRT_TYPE* P_TYPEDEF_capability;
    extern PRT_TYPE* P_TYPEDEF_secure_machine_handle;
    extern PRT_TYPE* P_TYPEDEF_secure_StringType;
    extern PRT_TYPE* P_TYPEDEF_sealed_data;
    extern PRT_TYPE* P_TYPEDEF_sealed_data_key;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_HEALTHANALYSISCLIENT_H_

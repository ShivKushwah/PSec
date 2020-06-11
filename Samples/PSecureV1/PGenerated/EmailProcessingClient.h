#pragma once
#ifndef P_EMAILPROCESSINGCLIENT_H_
#define P_EMAILPROCESSINGCLIENT_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDEmailEnclaveIDEvent;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDEmailBodyEvent;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDSpamResultEvent;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDSecureSpamFilterIDEvent;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDProvisionEmailUserEnclave;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDEmailBodyEvent;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDSpamResultEvent;
    extern PRT_FUNDECL P_FUNCTION_seal;
    extern PRT_INTERFACEDECL P_I_EmailUserEnclave;
    extern PRT_INTERFACEDECL P_I_EmailUser;
    extern PRT_INTERFACEDECL P_I_UntrustedInitializer;
    extern PRT_INTERFACEDECL P_I_TrustedInitializer;
    extern PRT_INTERFACEDECL P_I_SecureSpamFilter;
    extern PRT_MACHINEDECL P_MACHINE_EmailUserEnclave;
    extern PRT_MACHINEDECL P_MACHINE_EmailUser;
    extern PRT_MACHINEDECL P_MACHINE_UntrustedInitializer;
    extern PRT_MACHINEDECL P_MACHINE_TrustedInitializer;
    extern PRT_MACHINEDECL P_MACHINE_SecureSpamFilter;
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

#endif // P_EMAILPROCESSINGCLIENT_H_

#pragma once
#ifndef P_PINGPONGENCLAVE_H_
#define P_PINGPONGENCLAVE_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_Ping;
    extern PRT_EVENTDECL P_EVENT_Pong;
    extern PRT_EVENTDECL P_EVENT_UntrustedEventFromPing;
    extern PRT_EVENTDECL P_EVENT_Success;
    extern PRT_INTERFACEDECL P_I_GodUntrusted;
    extern PRT_INTERFACEDECL P_I_GodMachine;
    extern PRT_INTERFACEDECL P_I_BankEnclave;
    extern PRT_INTERFACEDECL P_I_ClientEnclave;
    extern PRT_INTERFACEDECL P_I_ClientWebBrowser;
    extern PRT_INTERFACEDECL P_I_ServerHost;
    extern PRT_MACHINEDECL P_MACHINE_GodUntrusted;
    extern PRT_MACHINEDECL P_MACHINE_GodMachine;
    extern PRT_MACHINEDECL P_MACHINE_BankEnclave;
    extern PRT_MACHINEDECL P_MACHINE_ClientEnclave;
    extern PRT_MACHINEDECL P_MACHINE_ClientWebBrowser;
    extern PRT_MACHINEDECL P_MACHINE_ServerHost;
    extern PRT_TYPE* P_TYPEDEF_StringType;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_PINGPONGENCLAVE_H_

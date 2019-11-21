#pragma once
#ifndef P_PINGPONG_H_
#define P_PINGPONG_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_Ping;
    extern PRT_EVENTDECL P_EVENT_Pong;
    extern PRT_EVENTDECL P_EVENT_UntrustedEventFromPing;
    extern PRT_EVENTDECL P_EVENT_Success;
    extern PRT_INTERFACEDECL P_I_Ping;
    extern PRT_INTERFACEDECL P_I_Temp;
    extern PRT_MACHINEDECL P_MACHINE_Ping;
    extern PRT_MACHINEDECL P_MACHINE_Temp;
    extern PRT_TYPE* P_TYPEDEF_StringType;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_PINGPONG_H_

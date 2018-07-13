#pragma once
#ifndef P_PINGPONG_H_
#define P_PINGPONG_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_Ping;
    extern PRT_EVENTDECL P_EVENT_Pong;
    extern PRT_EVENTDECL P_EVENT_Success;
    extern PRT_INTERFACEDECL P_I_Main;
    extern PRT_INTERFACEDECL P_I_PONG;
    extern PRT_MACHINEDECL P_MACHINE_Main;
    extern PRT_MACHINEDECL P_MACHINE_PONG;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_PINGPONG_H_

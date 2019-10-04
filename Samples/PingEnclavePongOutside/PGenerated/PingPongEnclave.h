#pragma once
#ifndef P_PINGPONGENCLAVE_H_
#define P_PINGPONGENCLAVE_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_Ping;
    extern PRT_EVENTDECL P_EVENT_Pong;
    extern PRT_EVENTDECL P_EVENT_Success;
    extern PRT_INTERFACEDECL P_I_Pong;
    extern PRT_MACHINEDECL P_MACHINE_Pong;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_PINGPONGENCLAVE_H_

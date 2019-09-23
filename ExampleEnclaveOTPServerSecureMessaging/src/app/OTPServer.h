#pragma once
#ifndef P_OTPSERVER_H_
#define P_OTPSERVER_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_OTPSecretMsg;
    extern PRT_EVENTDECL P_EVENT_OTPSecretReceived;
    extern PRT_EVENTDECL P_EVENT_OTPCodeMsg;
    extern PRT_EVENTDECL P_EVENT_OTPCodeValidated;
    extern PRT_EVENTDECL P_EVENT_OTPCodeFailed;
    extern PRT_INTERFACEDECL P_I_BANK_SERVER;
    extern PRT_INTERFACEDECL P_I_CLIENT_OTP_GENERATOR;
    extern PRT_INTERFACEDECL P_I_IntializerMachine;
    extern PRT_MACHINEDECL P_MACHINE_BANK_SERVER;
    extern PRT_MACHINEDECL P_MACHINE_CLIENT_OTP_GENERATOR;
    extern PRT_MACHINEDECL P_MACHINE_IntializerMachine;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_OTPSERVER_H_

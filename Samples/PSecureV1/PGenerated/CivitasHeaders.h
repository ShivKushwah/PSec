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
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDGetVotingSSM;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDReceiveVotingSSM;
    extern PRT_EVENTDECL P_EVENT_UNTRUSTEDVoteRequest;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeStartElection;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeVote;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeAddItem;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeRespAddItem;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeRespConfirmVote;
    extern PRT_EVENTDECL P_EVENT_eCloseElection;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeGetLog;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeRespGetLog;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeAllVotes;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeElectionResults;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeRespElectionResults;
    extern PRT_EVENTDECL P_EVENT_TRUSTEDeGetElectionResults;
    extern PRT_INTERFACEDECL P_I_InitializerMachine;
    extern PRT_INTERFACEDECL P_I_SecureSupervisorMachine;
    extern PRT_INTERFACEDECL P_I_VotingUSM;
    extern PRT_INTERFACEDECL P_I_SecureBulletinBoardMachine;
    extern PRT_INTERFACEDECL P_I_SecureBallotBoxMachine;
    extern PRT_INTERFACEDECL P_I_SecureTamperEvidentLogMachine;
    extern PRT_INTERFACEDECL P_I_SecureTabulationTellerMachine;
    extern PRT_INTERFACEDECL P_I_SecureVotingClientMachine;
    extern PRT_MACHINEDECL P_MACHINE_InitializerMachine;
    extern PRT_MACHINEDECL P_MACHINE_SecureSupervisorMachine;
    extern PRT_MACHINEDECL P_MACHINE_VotingUSM;
    extern PRT_MACHINEDECL P_MACHINE_SecureBulletinBoardMachine;
    extern PRT_MACHINEDECL P_MACHINE_SecureBallotBoxMachine;
    extern PRT_MACHINEDECL P_MACHINE_SecureTamperEvidentLogMachine;
    extern PRT_MACHINEDECL P_MACHINE_SecureTabulationTellerMachine;
    extern PRT_MACHINEDECL P_MACHINE_SecureVotingClientMachine;
    extern PRT_TYPE* P_TYPEDEF_StringType;
    extern PRT_TYPE* P_TYPEDEF_machine_handle;
    extern PRT_TYPE* P_TYPEDEF_capability;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_CIVITASHEADERS_H_

#include "CivitasHeaders.h"

// Type universe for program:
static PRT_STRING P_NMDTUP_N[] = { "requestingMachine", "username" };
extern PRT_UINT64 P_MKDEF_machine_handle_IMPL(void);
extern PRT_UINT64 P_CLONE_machine_handle_IMPL(PRT_UINT64);
extern void P_FREE_machine_handle_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_machine_handle_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_machine_handle_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_machine_handle_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_machine_handle = {
    0U,
    "machine_handle",
    P_MKDEF_machine_handle_IMPL,
    P_CLONE_machine_handle_IMPL,
    P_FREE_machine_handle_IMPL,
    P_GETHASHCODE_machine_handle_IMPL,
    P_ISEQUAL_machine_handle_IMPL,
    P_TOSTRING_machine_handle_IMPL,
};
PRT_TYPE P_GEND_TYPE_machine_handle = { PRT_KIND_FOREIGN, { .foreignType = &P_machine_handle } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_TYPE* P_NMDTUP_T[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP = { 2U, P_NMDTUP_N, P_NMDTUP_T };
static PRT_TYPE P_GEND_TYPE_T2machine_handlei = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP } };
extern PRT_UINT64 P_MKDEF_StringType_IMPL(void);
extern PRT_UINT64 P_CLONE_StringType_IMPL(PRT_UINT64);
extern void P_FREE_StringType_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_StringType_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_StringType_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_StringType_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_StringType = {
    0U,
    "StringType",
    P_MKDEF_StringType_IMPL,
    P_CLONE_StringType_IMPL,
    P_FREE_StringType_IMPL,
    P_GETHASHCODE_StringType_IMPL,
    P_ISEQUAL_StringType_IMPL,
    P_TOSTRING_StringType_IMPL,
};
PRT_TYPE P_GEND_TYPE_StringType = { PRT_KIND_FOREIGN, { .foreignType = &P_StringType } };
static PRT_STRING P_NMDTUP_N_1[] = { "username_attempt", "password_attempt", "vote" };
static PRT_TYPE* P_NMDTUP_T_1[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_1 = { 3U, P_NMDTUP_N_1, P_NMDTUP_T_1 };
static PRT_TYPE P_GEND_TYPE_T3iii = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_1 } };
static PRT_STRING P_NMDTUP_N_2[] = { "credential", "vote", "requestingMachine", "requestingMachineCapability" };
extern PRT_UINT64 P_MKDEF_capability_IMPL(void);
extern PRT_UINT64 P_CLONE_capability_IMPL(PRT_UINT64);
extern void P_FREE_capability_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_capability_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_capability_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_capability_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_capability = {
    0U,
    "capability",
    P_MKDEF_capability_IMPL,
    P_CLONE_capability_IMPL,
    P_FREE_capability_IMPL,
    P_GETHASHCODE_capability_IMPL,
    P_ISEQUAL_capability_IMPL,
    P_TOSTRING_capability_IMPL,
};
PRT_TYPE P_GEND_TYPE_capability = { PRT_KIND_FOREIGN, { .foreignType = &P_capability } };
static PRT_TYPE* P_NMDTUP_T_2[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i, &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_capability };
static PRT_NMDTUPTYPE P_NMDTUP_2 = { 4U, P_NMDTUP_N_2, P_NMDTUP_T_2 };
static PRT_TYPE P_GEND_TYPE_T4iimachine_handlecapability = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_2 } };
static PRT_STRING P_NMDTUP_N_3[] = { "credential", "vote" };
static PRT_TYPE* P_NMDTUP_T_3[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_3 = { 2U, P_NMDTUP_N_3, P_NMDTUP_T_3 };
static PRT_TYPE P_GEND_TYPE_T2ii = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_3 } };
static PRT_TYPE P_GEND_TYPE_b = { PRT_KIND_BOOL, { NULL } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_SEQTYPE P_SEQTYPE = { &P_GEND_TYPE_T2ii };
static PRT_TYPE P_GEND_TYPE_ST2ii = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE } };
static PRT_STRING P_NMDTUP_N_4[] = { "ballotID", "votes" };
static PRT_TYPE* P_NMDTUP_T_4[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_ST2ii };
static PRT_NMDTUPTYPE P_NMDTUP_4 = { 2U, P_NMDTUP_N_4, P_NMDTUP_T_4 };
static PRT_TYPE P_GEND_TYPE_T2iST2ii = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_4 } };
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_MKiVi = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };
static PRT_STRING P_NMDTUP_N_5[] = { "allVotes", "whoWon" };
static PRT_TYPE* P_NMDTUP_T_5[] = { &P_GEND_TYPE_MKiVi, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_5 = { 2U, P_NMDTUP_N_5, P_NMDTUP_T_5 };
static PRT_TYPE P_GEND_TYPE_T2MKiVii = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_5 } };
static PRT_STRING P_NMDTUP_N_6[] = { "requestingMachine", "requestingMachineCapability" };
static PRT_TYPE* P_NMDTUP_T_6[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_capability };
static PRT_NMDTUPTYPE P_NMDTUP_6 = { 2U, P_NMDTUP_N_6, P_NMDTUP_T_6 };
static PRT_TYPE P_GEND_TYPE_T2machine_handlecapability = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_6 } };
static PRT_STRING P_NMDTUP_N_7[] = { "parent", "username", "password" };
static PRT_TYPE* P_NMDTUP_T_7[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_7 = { 3U, P_NMDTUP_N_7, P_NMDTUP_T_7 };
static PRT_TYPE P_GEND_TYPE_T3machine_handleii = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_7 } };
static PRT_STRING P_NMDTUP_N_8[] = { "bBoard", "bBoardCapability" };
static PRT_TYPE* P_NMDTUP_T_8[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_capability };
static PRT_NMDTUPTYPE P_NMDTUP_8 = { 2U, P_NMDTUP_N_8, P_NMDTUP_T_8 };
static PRT_TYPE P_GEND_TYPE_T2machine_handlecapability_1 = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_8 } };
static PRT_STRING P_NMDTUP_N_9[] = { "parentMachine", "parentCapability" };
static PRT_TYPE* P_NMDTUP_T_9[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_capability };
static PRT_NMDTUPTYPE P_NMDTUP_9 = { 2U, P_NMDTUP_N_9, P_NMDTUP_T_9 };
static PRT_TYPE P_GEND_TYPE_T2machine_handlecapability_2 = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_9 } };
static PRT_STRING P_NMDTUP_N_10[] = { "ballotBox", "bulletinBoard", "username", "password", "ballotBoxCapability", "bulletinBoardCapability" };
static PRT_TYPE* P_NMDTUP_T_10[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_i, &P_GEND_TYPE_i, &P_GEND_TYPE_capability, &P_GEND_TYPE_capability };
static PRT_NMDTUPTYPE P_NMDTUP_10 = { 6U, P_NMDTUP_N_10, P_NMDTUP_T_10 };
static PRT_TYPE P_GEND_TYPE_T6machine_handlemachine_handleiicapabilitycapability = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_10 } };
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TUPTYPE P_TUP = { 2U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T2ii_1 = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
static PRT_SEQTYPE P_SEQTYPE_1 = { &P_GEND_TYPE_T2ii_1 };
static PRT_TYPE P_GEND_TYPE_ST2ii_1 = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_1 } };
static PRT_SEQTYPE P_SEQTYPE_2 = { &P_GEND_TYPE_machine_handle };
static PRT_TYPE P_GEND_TYPE_Smachine_handle = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_2 } };
static PRT_SEQTYPE P_SEQTYPE_3 = { &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_Si = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_3 } };

// Function implementation prototypes:
PRT_VALUE* P_PrintKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintPCapability_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetCapability_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_SaveCapability_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetUserInput_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_2;

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_3;

PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_4;

PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_5;

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_6;

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_7;

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_8;

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_9;

PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_10;

PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_11;

PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_12;

PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_13;

PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_14;

PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_15;

PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_16;

PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_17;

PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_18;

PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_19;

PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_20;

PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_21;

PRT_VALUE* P_Anon_IMPL_22(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_22;

PRT_VALUE* P_Anon_IMPL_23(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_23;


PRT_EVENTDECL P_EVENT_UNTRUSTEDGetVotingSSM = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDGetVotingSSM",
    4294967295U,
    &P_GEND_TYPE_T2machine_handlei
};

PRT_EVENTDECL P_EVENT_StrEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "StrEvent",
    4294967295U,
    &P_GEND_TYPE_StringType
};

PRT_EVENTDECL P_EVENT_UNTRUSTEDReceiveVotingSSM = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDReceiveVotingSSM",
    4294967295U,
    &P_GEND_TYPE_machine_handle
};

PRT_EVENTDECL P_EVENT_UNTRUSTEDVoteRequest = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDVoteRequest",
    4294967295U,
    &P_GEND_TYPE_T3iii
};

PRT_EVENTDECL P_EVENT_TRUSTEDeStartElection = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeStartElection",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_TRUSTEDeVote = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeVote",
    4294967295U,
    &P_GEND_TYPE_T4iimachine_handlecapability
};

PRT_EVENTDECL P_EVENT_TRUSTEDeAddItem = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeAddItem",
    4294967295U,
    &P_GEND_TYPE_T2ii
};

PRT_EVENTDECL P_EVENT_TRUSTEDeRespAddItem = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeRespAddItem",
    4294967295U,
    &P_GEND_TYPE_b
};

PRT_EVENTDECL P_EVENT_TRUSTEDeRespConfirmVote = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeRespConfirmVote",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_eCloseElection = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eCloseElection",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_TRUSTEDeGetLog = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeGetLog",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_TRUSTEDeRespGetLog = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeRespGetLog",
    4294967295U,
    &P_GEND_TYPE_ST2ii
};

PRT_EVENTDECL P_EVENT_TRUSTEDeAllVotes = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeAllVotes",
    4294967295U,
    &P_GEND_TYPE_T2iST2ii
};

PRT_EVENTDECL P_EVENT_TRUSTEDeElectionResults = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeElectionResults",
    4294967295U,
    &P_GEND_TYPE_MKiVi
};

PRT_EVENTDECL P_EVENT_TRUSTEDeRespElectionResults = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeRespElectionResults",
    4294967295U,
    &P_GEND_TYPE_T2MKiVii
};

PRT_EVENTDECL P_EVENT_TRUSTEDeGetElectionResults = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDeGetElectionResults",
    4294967295U,
    &P_GEND_TYPE_T2machine_handlecapability
};

PRT_FUNDECL P_FUNCTION_PrintKey =
{
    "PrintKey",
    &P_PrintKey_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_PrintPCapability =
{
    "PrintPCapability",
    &P_PrintPCapability_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_PrintString =
{
    "PrintString",
    &P_PrintString_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetThis =
{
    "GetThis",
    &P_GetThis_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_CreateMachineSecureChild =
{
    "CreateMachineSecureChild",
    &P_CreateMachineSecureChild_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_CreateSecureMachineRequest =
{
    "CreateSecureMachineRequest",
    &P_CreateSecureMachineRequest_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_CreateUSMMachineRequest =
{
    "CreateUSMMachineRequest",
    &P_CreateUSMMachineRequest_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetCapability =
{
    "GetCapability",
    &P_GetCapability_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_SaveCapability =
{
    "SaveCapability",
    &P_SaveCapability_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetUserInput =
{
    "GetUserInput",
    &P_GetUserInput_IMPL,
    NULL
};


PRT_EVENTDECL* P_InitializerMachine_RECV_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_InitializerMachine_RECV =
{
    17U,
    P_InitializerMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_InitializerMachine =
{
    0U,
    "InitializerMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_InitializerMachine_RECV
};

PRT_EVENTDECL* P_SecureSupervisorMachine_RECV_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSupervisorMachine_RECV =
{
    17U,
    P_SecureSupervisorMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureSupervisorMachine =
{
    1U,
    "SecureSupervisorMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_SecureSupervisorMachine_RECV
};

PRT_EVENTDECL* P_VotingUSM_RECV_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VotingUSM_RECV =
{
    17U,
    P_VotingUSM_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_VotingUSM =
{
    2U,
    "VotingUSM",
    &P_GEND_TYPE_T3machine_handleii,
    &P_EVENTSET_VotingUSM_RECV
};

PRT_EVENTDECL* P_SecureBulletinBoardMachine_RECV_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBulletinBoardMachine_RECV =
{
    17U,
    P_SecureBulletinBoardMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureBulletinBoardMachine =
{
    3U,
    "SecureBulletinBoardMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_SecureBulletinBoardMachine_RECV
};

PRT_EVENTDECL* P_SecureBallotBoxMachine_RECV_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBallotBoxMachine_RECV =
{
    17U,
    P_SecureBallotBoxMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureBallotBoxMachine =
{
    4U,
    "SecureBallotBoxMachine",
    &P_GEND_TYPE_T2machine_handlecapability_1,
    &P_EVENTSET_SecureBallotBoxMachine_RECV
};

PRT_EVENTDECL* P_SecureTamperEvidentLogMachine_RECV_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTamperEvidentLogMachine_RECV =
{
    17U,
    P_SecureTamperEvidentLogMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureTamperEvidentLogMachine =
{
    5U,
    "SecureTamperEvidentLogMachine",
    &P_GEND_TYPE_T2machine_handlecapability_2,
    &P_EVENTSET_SecureTamperEvidentLogMachine_RECV
};

PRT_EVENTDECL* P_SecureTabulationTellerMachine_RECV_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTabulationTellerMachine_RECV =
{
    17U,
    P_SecureTabulationTellerMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureTabulationTellerMachine =
{
    6U,
    "SecureTabulationTellerMachine",
    &P_GEND_TYPE_T2machine_handlecapability_1,
    &P_EVENTSET_SecureTabulationTellerMachine_RECV
};

PRT_EVENTDECL* P_SecureVotingClientMachine_RECV_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureVotingClientMachine_RECV =
{
    17U,
    P_SecureVotingClientMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureVotingClientMachine =
{
    7U,
    "SecureVotingClientMachine",
    &P_GEND_TYPE_T6machine_handlemachine_handleiicapabilitycapability,
    &P_EVENTSET_SecureVotingClientMachine_RECV
};

PRT_VARDECL P_InitializerMachine_VARS[] = {
    { "supervisor", &P_GEND_TYPE_machine_handle },
    { "votingMachine", &P_GEND_TYPE_machine_handle },
    { "votingMachine2", &P_GEND_TYPE_machine_handle }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS =
{
    0U,
    P_Init_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS =
{
    0U,
    P_Init_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS =
{
    0U,
    P_Init_DOS_INNER,
    NULL
};

#define P_STATE_InitializerMachine_Init \
{ \
    "InitializerMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS, \
    &P_EVENTSET_Init_TRANS, \
    &P_EVENTSET_Init_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_InitializerMachine_STATES[] = { P_STATE_InitializerMachine_Init };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    _P_GEN_funargs[0] = "SecureSupervisorMachine";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_1 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_1);
        *P_LVALUE_1 = PTMP_tmp0;
        PTMP_tmp0 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtCloneValue((&P_LIT_INT32));
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtCloneValue((&P_LIT_INT32));
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = (PrtMkTuple(&P_GEND_TYPE_T3machine_handleii, &(PTMP_tmp1), &(PTMP_tmp2), &(PTMP_tmp3)));
    
    _P_GEN_funargs[0] = "VotingUSM";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp4);
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_7 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_7);
        *P_LVALUE_7 = PTMP_tmp5;
        PTMP_tmp5 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue((&P_LIT_INT32_1));
    
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue((&P_LIT_INT32_1));
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = (PrtMkTuple(&P_GEND_TYPE_T3machine_handleii, &(PTMP_tmp6), &(PTMP_tmp7), &(PTMP_tmp8)));
    
    _P_GEN_funargs[0] = "VotingUSM";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp9);
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_13 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_13);
        *P_LVALUE_13 = PTMP_tmp10;
        PTMP_tmp10 = NULL;
    }
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL
};


PRT_FUNDECL* P_InitializerMachine_METHODS[] = { &P_FUNCTION_Anon };

PRT_EVENTDECL* P_InitializerMachine_RECV_INNER_1[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_InitializerMachine_RECV_1 =
{
    17U,
    P_InitializerMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_InitializerMachine_SEND_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_InitializerMachine_SEND =
{
    17U,
    P_InitializerMachine_SEND_INNER,
    NULL
};

PRT_UINT32 P_InitializerMachine_CREATES_ARR[] = { 1, 2 };
PRT_INTERFACESETDECL P_InitializerMachine_CREATES = { 2, P_InitializerMachine_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_InitializerMachine = 
{
    0U,
    "InitializerMachine",
    &P_EVENTSET_InitializerMachine_RECV_1,
    &P_EVENTSET_InitializerMachine_SEND,
    &P_InitializerMachine_CREATES,
    3U,
    1U,
    1U,
    4294967295U,
    0U,
    P_InitializerMachine_VARS,
    P_InitializerMachine_STATES,
    P_InitializerMachine_METHODS,
    PRT_FALSE
};

PRT_VARDECL P_SecureSupervisorMachine_VARS[] = {
    { "bBoard", &P_GEND_TYPE_machine_handle },
    { "bBox", &P_GEND_TYPE_machine_handle },
    { "tTeller", &P_GEND_TYPE_machine_handle },
    { "username_passwords", &P_GEND_TYPE_ST2ii_1 },
    { "votingClients", &P_GEND_TYPE_Smachine_handle },
    { "i", &P_GEND_TYPE_i },
    { "tempMachineHandle", &P_GEND_TYPE_machine_handle }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_1 =
{
    0U,
    P_Init_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_1 =
{
    0U,
    P_Init_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_1 =
{
    0U,
    P_Init_DOS_INNER_1,
    NULL
};

#define P_STATE_SecureSupervisorMachine_Init \
{ \
    "SecureSupervisorMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_1, \
    &P_EVENTSET_Init_TRANS_1, \
    &P_EVENTSET_Init_DOS_1, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_1, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitToSendVotingClientMachines_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitToSendVotingClientMachines_DEFERS =
{
    0U,
    P_WaitToSendVotingClientMachines_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitToSendVotingClientMachines_TRANS_INNER[] = { &P_EVENT_UNTRUSTEDGetVotingSSM };
PRT_EVENTSETDECL P_EVENTSET_WaitToSendVotingClientMachines_TRANS =
{
    1U,
    P_WaitToSendVotingClientMachines_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitToSendVotingClientMachines_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitToSendVotingClientMachines_DOS =
{
    0U,
    P_WaitToSendVotingClientMachines_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 1, &P_EVENT_UNTRUSTEDGetVotingSSM, 2, &_P_NO_OP }
};

#define P_STATE_SecureSupervisorMachine_WaitToSendVotingClientMachines \
{ \
    "SecureSupervisorMachine.WaitToSendVotingClientMachines", \
    1U, \
    0U, \
    &P_EVENTSET_WaitToSendVotingClientMachines_DEFERS, \
    &P_EVENTSET_WaitToSendVotingClientMachines_TRANS, \
    &P_EVENTSET_WaitToSendVotingClientMachines_DOS, \
    P_TRANS, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_SendVotingSSM_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SendVotingSSM_DEFERS =
{
    0U,
    P_SendVotingSSM_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_SendVotingSSM_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SendVotingSSM_TRANS =
{
    0U,
    P_SendVotingSSM_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_SendVotingSSM_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SendVotingSSM_DOS =
{
    0U,
    P_SendVotingSSM_DOS_INNER,
    NULL
};

#define P_STATE_SecureSupervisorMachine_SendVotingSSM \
{ \
    "SecureSupervisorMachine.SendVotingSSM", \
    0U, \
    0U, \
    &P_EVENTSET_SendVotingSSM_DEFERS, \
    &P_EVENTSET_SendVotingSSM_TRANS, \
    &P_EVENTSET_SendVotingSSM_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureSupervisorMachine_STATES[] = { P_STATE_SecureSupervisorMachine_Init, P_STATE_SecureSupervisorMachine_WaitToSendVotingClientMachines, P_STATE_SecureSupervisorMachine_SendVotingSSM };

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8_1 = NULL;
    PRT_VALUE* PTMP_tmp9_1 = NULL;
    PRT_VALUE* PTMP_tmp10_1 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    PRT_VALUE* PTMP_tmp17 = NULL;
    PRT_VALUE* PTMP_tmp18 = NULL;
    PRT_VALUE* PTMP_tmp19 = NULL;
    PRT_VALUE* PTMP_tmp20 = NULL;
    PRT_VALUE* PTMP_tmp21 = NULL;
    PRT_VALUE* PTMP_tmp22 = NULL;
    PRT_VALUE* PTMP_tmp23 = NULL;
    PRT_VALUE* PTMP_tmp24 = NULL;
    PRT_VALUE* PTMP_tmp25 = NULL;
    PRT_VALUE* PTMP_tmp26 = NULL;
    PRT_VALUE* PTMP_tmp27 = NULL;
    PRT_VALUE* PTMP_tmp28 = NULL;
    PRT_VALUE* PTMP_tmp29 = NULL;
    PRT_VALUE* PTMP_tmp30 = NULL;
    PRT_VALUE* PTMP_tmp31 = NULL;
    PRT_VALUE* PTMP_tmp32 = NULL;
    PRT_VALUE* PTMP_tmp33 = NULL;
    PRT_VALUE* PTMP_tmp34 = NULL;
    PRT_VALUE* PTMP_tmp35 = NULL;
    PRT_VALUE* PTMP_tmp36 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    _P_GEN_funargs[0] = "SecureBulletinBoardMachine";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_15 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_15);
        *P_LVALUE_15 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_18);
    *P_LVALUE_18 = ((_P_GEN_funargs[0] = &(PTMP_tmp2_1)), (_P_GEN_funval = P_GetCapability_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp2_1), PTMP_tmp2_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = (PrtMkTuple(&P_GEND_TYPE_T2machine_handlecapability_1, &(PTMP_tmp1_1), &(PTMP_tmp3_1)));
    
    _P_GEN_funargs[0] = "SecureBallotBoxMachine";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp4_1);
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_21 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_21);
        *P_LVALUE_21 = PTMP_tmp5_1;
        PTMP_tmp5_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[3]));
    
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp7_1);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = PrtCloneValue((&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp8_1);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = PrtCloneValue((&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp9_1);
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = (PrtMkTuple(&P_GEND_TYPE_T2ii_1, &(PTMP_tmp7_1), &(PTMP_tmp8_1)));
    
    PrtSeqInsertEx(p_this->varValues[3], PTMP_tmp6_1, PTMP_tmp9_1, PRT_FALSE);
    *(&(PTMP_tmp9_1)) = NULL;
    
    PRT_VALUE** P_LVALUE_26 = &(PTMP_tmp10_1);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[3]));
    
    PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp11);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = PrtCloneValue((&P_LIT_INT32_3));
    
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp12);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = PrtCloneValue((&P_LIT_INT32_3));
    
    PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp13);
    PrtFreeValue(*P_LVALUE_29);
    *P_LVALUE_29 = (PrtMkTuple(&P_GEND_TYPE_T2ii_1, &(PTMP_tmp11), &(PTMP_tmp12)));
    
    PrtSeqInsertEx(p_this->varValues[3], PTMP_tmp10_1, PTMP_tmp13, PRT_FALSE);
    *(&(PTMP_tmp13)) = NULL;
    
    PRT_VALUE** P_LVALUE_30 = &(p_this->varValues[5]);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtCloneValue((&P_LIT_INT32_4));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp14);
        PrtFreeValue(*P_LVALUE_31);
        *P_LVALUE_31 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[3]));
        
        PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp15);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[5]) < PrtPrimGetInt(PTMP_tmp14));
        
        PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp16);
        PrtFreeValue(*P_LVALUE_33);
        *P_LVALUE_33 = PrtCloneValue(PTMP_tmp15);
        
        if (PrtPrimGetBool(PTMP_tmp16))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_34 = &(PTMP_tmp17);
        PrtFreeValue(*P_LVALUE_34);
        *P_LVALUE_34 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp18);
        PrtFreeValue(*P_LVALUE_35);
        *P_LVALUE_35 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp19);
        PrtFreeValue(*P_LVALUE_36);
        *P_LVALUE_36 = PrtSeqGet(p_this->varValues[3], p_this->varValues[5]);
        
        PRT_VALUE** P_LVALUE_37 = &(PTMP_tmp20);
        PrtFreeValue(*P_LVALUE_37);
        *P_LVALUE_37 = PrtTupleGet(PTMP_tmp19, 0);
        
        PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp21);
        PrtFreeValue(*P_LVALUE_38);
        *P_LVALUE_38 = PrtSeqGet(p_this->varValues[3], p_this->varValues[5]);
        
        PRT_VALUE** P_LVALUE_39 = &(PTMP_tmp22);
        PrtFreeValue(*P_LVALUE_39);
        *P_LVALUE_39 = PrtTupleGet(PTMP_tmp21, 1);
        
        PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp23);
        PrtFreeValue(*P_LVALUE_40);
        *P_LVALUE_40 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_41 = &(PTMP_tmp24);
        PrtFreeValue(*P_LVALUE_41);
        *P_LVALUE_41 = ((_P_GEN_funargs[0] = &(PTMP_tmp23)), (_P_GEN_funval = P_GetCapability_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp23), PTMP_tmp23 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_1;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_1;
        }
        
        PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp25);
        PrtFreeValue(*P_LVALUE_42);
        *P_LVALUE_42 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp26);
        PrtFreeValue(*P_LVALUE_43);
        *P_LVALUE_43 = ((_P_GEN_funargs[0] = &(PTMP_tmp25)), (_P_GEN_funval = P_GetCapability_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp25), PTMP_tmp25 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_1;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_1;
        }
        
        PRT_VALUE** P_LVALUE_44 = &(PTMP_tmp27);
        PrtFreeValue(*P_LVALUE_44);
        *P_LVALUE_44 = (PrtMkTuple(&P_GEND_TYPE_T6machine_handlemachine_handleiicapabilitycapability, &(PTMP_tmp17), &(PTMP_tmp18), &(PTMP_tmp20), &(PTMP_tmp22), &(PTMP_tmp24), &(PTMP_tmp26)));
        
        _P_GEN_funargs[0] = "SecureVotingClientMachine";
        _P_GEN_funargs[1] = "1";
        _P_GEN_funargs[2] = &(PTMP_tmp27);
        PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp28);
        PrtFreeValue(*P_LVALUE_45);
        *P_LVALUE_45 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_1;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_1;
        }
        
        {
            PRT_VALUE** P_LVALUE_46 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_46);
            *P_LVALUE_46 = PTMP_tmp28;
            PTMP_tmp28 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp29);
        PrtFreeValue(*P_LVALUE_47);
        *P_LVALUE_47 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[4]));
        
        PRT_VALUE** P_LVALUE_48 = &(PTMP_tmp30);
        PrtFreeValue(*P_LVALUE_48);
        *P_LVALUE_48 = PrtCloneValue(p_this->varValues[6]);
        
        PrtSeqInsertEx(p_this->varValues[4], PTMP_tmp29, PTMP_tmp30, PRT_FALSE);
        *(&(PTMP_tmp30)) = NULL;
        
        PRT_VALUE** P_LVALUE_49 = &(PTMP_tmp31);
        PrtFreeValue(*P_LVALUE_49);
        *P_LVALUE_49 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[5]) + PrtPrimGetInt((&P_LIT_INT32_3)));
        
        {
            PRT_VALUE** P_LVALUE_50 = &(p_this->varValues[5]);
            PrtFreeValue(*P_LVALUE_50);
            *P_LVALUE_50 = PTMP_tmp31;
            PTMP_tmp31 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp32);
    PrtFreeValue(*P_LVALUE_51);
    *P_LVALUE_51 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp33);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = ((_P_GEN_funargs[0] = &(PTMP_tmp32)), (_P_GEN_funval = P_GetCapability_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp32), PTMP_tmp32 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    _P_GEN_funargs[0] = &(PTMP_tmp33);
    PrtFreeValue(P_PrintPCapability_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp33);
    PTMP_tmp33 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp34);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp35);
    PrtFreeValue(*P_LVALUE_54);
    *P_LVALUE_54 = PrtCloneValue((&P_EVENT_TRUSTEDeStartElection.value));
    
    PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp36);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtCloneValue((&P_LIT_INT32_2));
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32_3));
    _P_GEN_funargs[0] = &(PTMP_tmp34);
    _P_GEN_funargs[1] = &(PTMP_tmp35);
    _P_GEN_funargs[2] = &(P_PTMP_tmp);
    _P_GEN_funargs[3] = &(PTMP_tmp36);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8_1); PTMP_tmp8_1 = NULL;
    PrtFreeValue(PTMP_tmp9_1); PTMP_tmp9_1 = NULL;
    PrtFreeValue(PTMP_tmp10_1); PTMP_tmp10_1 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    PrtFreeValue(PTMP_tmp17); PTMP_tmp17 = NULL;
    PrtFreeValue(PTMP_tmp18); PTMP_tmp18 = NULL;
    PrtFreeValue(PTMP_tmp19); PTMP_tmp19 = NULL;
    PrtFreeValue(PTMP_tmp20); PTMP_tmp20 = NULL;
    PrtFreeValue(PTMP_tmp21); PTMP_tmp21 = NULL;
    PrtFreeValue(PTMP_tmp22); PTMP_tmp22 = NULL;
    PrtFreeValue(PTMP_tmp23); PTMP_tmp23 = NULL;
    PrtFreeValue(PTMP_tmp24); PTMP_tmp24 = NULL;
    PrtFreeValue(PTMP_tmp25); PTMP_tmp25 = NULL;
    PrtFreeValue(PTMP_tmp26); PTMP_tmp26 = NULL;
    PrtFreeValue(PTMP_tmp27); PTMP_tmp27 = NULL;
    PrtFreeValue(PTMP_tmp28); PTMP_tmp28 = NULL;
    PrtFreeValue(PTMP_tmp29); PTMP_tmp29 = NULL;
    PrtFreeValue(PTMP_tmp30); PTMP_tmp30 = NULL;
    PrtFreeValue(PTMP_tmp31); PTMP_tmp31 = NULL;
    PrtFreeValue(PTMP_tmp32); PTMP_tmp32 = NULL;
    PrtFreeValue(PTMP_tmp33); PTMP_tmp33 = NULL;
    PrtFreeValue(PTMP_tmp34); PTMP_tmp34 = NULL;
    PrtFreeValue(PTMP_tmp35); PTMP_tmp35 = NULL;
    PrtFreeValue(PTMP_tmp36); PTMP_tmp36 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_2 = NULL;
    PRT_VALUE* PTMP_tmp7_2 = NULL;
    PRT_VALUE* PTMP_tmp8_2 = NULL;
    PRT_VALUE* PTMP_tmp9_2 = NULL;
    PRT_VALUE* PTMP_tmp10_2 = NULL;
    PRT_VALUE* PTMP_tmp11_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_1 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_56 = &(p_this->varValues[5]);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = PrtCloneValue((&P_LIT_INT32_5));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_1)))
    {
        PRT_VALUE** P_LVALUE_57 = &(PTMP_tmp0_2);
        PrtFreeValue(*P_LVALUE_57);
        *P_LVALUE_57 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[3]));
        
        PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp1_2);
        PrtFreeValue(*P_LVALUE_58);
        *P_LVALUE_58 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[5]) < PrtPrimGetInt(PTMP_tmp0_2));
        
        PRT_VALUE** P_LVALUE_59 = &(PTMP_tmp2_2);
        PrtFreeValue(*P_LVALUE_59);
        *P_LVALUE_59 = PrtCloneValue(PTMP_tmp1_2);
        
        if (PrtPrimGetBool(PTMP_tmp2_2))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_60 = &(PTMP_tmp3_2);
        PrtFreeValue(*P_LVALUE_60);
        *P_LVALUE_60 = PrtSeqGet(p_this->varValues[3], p_this->varValues[5]);
        
        PRT_VALUE** P_LVALUE_61 = &(PTMP_tmp4_2);
        PrtFreeValue(*P_LVALUE_61);
        *P_LVALUE_61 = PrtTupleGet(PTMP_tmp3_2, 0);
        
        PRT_VALUE** P_LVALUE_62 = &(PTMP_tmp5_2);
        PrtFreeValue(*P_LVALUE_62);
        *P_LVALUE_62 = PrtTupleGet(*P_VAR_payload, 1);
        
        PRT_VALUE** P_LVALUE_63 = &(PTMP_tmp6_2);
        PrtFreeValue(*P_LVALUE_63);
        *P_LVALUE_63 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp4_2, PTMP_tmp5_2));
        
        if (PrtPrimGetBool(PTMP_tmp6_2))
        {
            PrtPrintf("Sending the correct one!");
            
            PRT_VALUE** P_LVALUE_64 = &(PTMP_tmp7_2);
            PrtFreeValue(*P_LVALUE_64);
            *P_LVALUE_64 = PrtTupleGet(*P_VAR_payload, 0);
            
            PRT_VALUE** P_LVALUE_65 = &(PTMP_tmp8_2);
            PrtFreeValue(*P_LVALUE_65);
            *P_LVALUE_65 = PrtCloneValue(PTMP_tmp7_2);
            
            PRT_VALUE** P_LVALUE_66 = &(PTMP_tmp9_2);
            PrtFreeValue(*P_LVALUE_66);
            *P_LVALUE_66 = PrtCloneValue((&P_EVENT_UNTRUSTEDReceiveVotingSSM.value));
            
            PRT_VALUE** P_LVALUE_67 = &(PTMP_tmp10_2);
            PrtFreeValue(*P_LVALUE_67);
            *P_LVALUE_67 = PrtSeqGet(p_this->varValues[4], p_this->varValues[5]);
            
            PRT_VALUE* P_PTMP_tmp_1 = PrtCloneValue(&(P_LIT_INT32_6));
            _P_GEN_funargs[0] = &(PTMP_tmp8_2);
            _P_GEN_funargs[1] = &(PTMP_tmp9_2);
            _P_GEN_funargs[2] = &(P_PTMP_tmp_1);
            _P_GEN_funargs[3] = &(PTMP_tmp10_2);
            PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_2;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_2;
            }
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_68 = &(PTMP_tmp11_1);
        PrtFreeValue(*P_LVALUE_68);
        *P_LVALUE_68 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[5]) + PrtPrimGetInt((&P_LIT_INT32_6)));
        
        {
            PRT_VALUE** P_LVALUE_69 = &(p_this->varValues[5]);
            PrtFreeValue(*P_LVALUE_69);
            *P_LVALUE_69 = PTMP_tmp11_1;
            PTMP_tmp11_1 = NULL;
        }
        
    }
    
    
    PrtGoto(p_this, 1U, 0);
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_2); PTMP_tmp6_2 = NULL;
    PrtFreeValue(PTMP_tmp7_2); PTMP_tmp7_2 = NULL;
    PrtFreeValue(PTMP_tmp8_2); PTMP_tmp8_2 = NULL;
    PrtFreeValue(PTMP_tmp9_2); PTMP_tmp9_2 = NULL;
    PrtFreeValue(PTMP_tmp10_2); PTMP_tmp10_2 = NULL;
    PrtFreeValue(PTMP_tmp11_1); PTMP_tmp11_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_T2machine_handlei
};


PRT_FUNDECL* P_SecureSupervisorMachine_METHODS[] = { &P_FUNCTION_Anon_1, &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_SecureSupervisorMachine_RECV_INNER_1[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSupervisorMachine_RECV_1 =
{
    17U,
    P_SecureSupervisorMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureSupervisorMachine_SEND_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSupervisorMachine_SEND =
{
    17U,
    P_SecureSupervisorMachine_SEND_INNER,
    NULL
};

PRT_UINT32 P_SecureSupervisorMachine_CREATES_ARR[] = { 4, 3, 7 };
PRT_INTERFACESETDECL P_SecureSupervisorMachine_CREATES = { 3, P_SecureSupervisorMachine_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_SecureSupervisorMachine = 
{
    1U,
    "SecureSupervisorMachine",
    &P_EVENTSET_SecureSupervisorMachine_RECV_1,
    &P_EVENTSET_SecureSupervisorMachine_SEND,
    &P_SecureSupervisorMachine_CREATES,
    7U,
    3U,
    2U,
    4294967295U,
    0U,
    P_SecureSupervisorMachine_VARS,
    P_SecureSupervisorMachine_STATES,
    P_SecureSupervisorMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_VotingUSM_VARS[] = {
    { "supervisor", &P_GEND_TYPE_machine_handle },
    { "votingSecureMachine", &P_GEND_TYPE_machine_handle },
    { "username", &P_GEND_TYPE_i },
    { "password", &P_GEND_TYPE_i },
    { "vote", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_2 =
{
    0U,
    P_Init_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_2[] = { &P_EVENT_UNTRUSTEDReceiveVotingSSM };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_2 =
{
    1U,
    P_Init_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_2 =
{
    0U,
    P_Init_DOS_INNER_2,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 0, &P_EVENT_UNTRUSTEDReceiveVotingSSM, 1, &_P_NO_OP }
};

#define P_STATE_VotingUSM_Init \
{ \
    "VotingUSM.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_2, \
    &P_EVENTSET_Init_TRANS_2, \
    &P_EVENTSET_Init_DOS_2, \
    P_TRANS_1, \
    NULL, \
    &P_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Vote_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Vote_DEFERS =
{
    0U,
    P_Vote_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Vote_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Vote_TRANS =
{
    0U,
    P_Vote_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Vote_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Vote_DOS =
{
    0U,
    P_Vote_DOS_INNER,
    NULL
};

#define P_STATE_VotingUSM_Vote \
{ \
    "VotingUSM.Vote", \
    0U, \
    0U, \
    &P_EVENTSET_Vote_DEFERS, \
    &P_EVENTSET_Vote_TRANS, \
    &P_EVENTSET_Vote_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Done_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DEFERS =
{
    0U,
    P_Done_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Done_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_TRANS =
{
    0U,
    P_Done_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Done_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DOS =
{
    0U,
    P_Done_DOS_INNER,
    NULL
};

#define P_STATE_VotingUSM_Done \
{ \
    "VotingUSM.Done", \
    0U, \
    0U, \
    &P_EVENTSET_Done_DEFERS, \
    &P_EVENTSET_Done_TRANS, \
    &P_EVENTSET_Done_DOS, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_VotingUSM_STATES[] = { P_STATE_VotingUSM_Init, P_STATE_VotingUSM_Vote, P_STATE_VotingUSM_Done };

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_3 = NULL;
    PRT_VALUE* PTMP_tmp5_3 = NULL;
    PRT_VALUE* PTMP_tmp6_3 = NULL;
    PRT_VALUE* PTMP_tmp7_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_7 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_70 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_70);
    *P_LVALUE_70 = PrtTupleGet(*P_VAR_payload_1, 0);
    
    {
        PRT_VALUE** P_LVALUE_71 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_71);
        *P_LVALUE_71 = PTMP_tmp0_3;
        PTMP_tmp0_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_72 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_72);
    *P_LVALUE_72 = PrtTupleGet(*P_VAR_payload_1, 1);
    
    {
        PRT_VALUE** P_LVALUE_73 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_73);
        *P_LVALUE_73 = PTMP_tmp1_3;
        PTMP_tmp1_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_74 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_74);
    *P_LVALUE_74 = PrtTupleGet(*P_VAR_payload_1, 2);
    
    {
        PRT_VALUE** P_LVALUE_75 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_75);
        *P_LVALUE_75 = PTMP_tmp2_3;
        PTMP_tmp2_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_76 = &(PTMP_tmp3_3);
    PrtFreeValue(*P_LVALUE_76);
    *P_LVALUE_76 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_77 = &(PTMP_tmp4_3);
    PrtFreeValue(*P_LVALUE_77);
    *P_LVALUE_77 = PrtCloneValue((&P_EVENT_UNTRUSTEDGetVotingSSM.value));
    
    PRT_VALUE** P_LVALUE_78 = &(PTMP_tmp5_3);
    PrtFreeValue(*P_LVALUE_78);
    *P_LVALUE_78 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    PRT_VALUE** P_LVALUE_79 = &(PTMP_tmp6_3);
    PrtFreeValue(*P_LVALUE_79);
    *P_LVALUE_79 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_80 = &(PTMP_tmp7_3);
    PrtFreeValue(*P_LVALUE_80);
    *P_LVALUE_80 = (PrtMkTuple(&P_GEND_TYPE_T2machine_handlei, &(PTMP_tmp5_3), &(PTMP_tmp6_3)));
    
    PRT_VALUE* P_PTMP_tmp_2 = PrtCloneValue(&(P_LIT_INT32_7));
    _P_GEN_funargs[0] = &(PTMP_tmp3_3);
    _P_GEN_funargs[1] = &(PTMP_tmp4_3);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_2);
    _P_GEN_funargs[3] = &(PTMP_tmp7_3);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
p_return_3: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_3); PTMP_tmp4_3 = NULL;
    PrtFreeValue(PTMP_tmp5_3); PTMP_tmp5_3 = NULL;
    PrtFreeValue(PTMP_tmp6_3); PTMP_tmp6_3 = NULL;
    PrtFreeValue(PTMP_tmp7_3); PTMP_tmp7_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_T3machine_handleii
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    PRT_VALUE* PTMP_tmp3_4 = NULL;
    PRT_VALUE* PTMP_tmp4_4 = NULL;
    PRT_VALUE* PTMP_tmp5_4 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_8 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_81 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_81);
    *P_LVALUE_81 = PrtCloneValue(*P_VAR_payload_2);
    
    PRT_VALUE** P_LVALUE_82 = &(p_this->varValues[4]);
    PrtFreeValue(*P_LVALUE_82);
    *P_LVALUE_82 = PrtCloneValue((&P_LIT_INT32_8));
    
    PRT_VALUE** P_LVALUE_83 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_83);
    *P_LVALUE_83 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_84 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_84);
    *P_LVALUE_84 = PrtCloneValue((&P_EVENT_UNTRUSTEDVoteRequest.value));
    
    PRT_VALUE** P_LVALUE_85 = &(PTMP_tmp2_4);
    PrtFreeValue(*P_LVALUE_85);
    *P_LVALUE_85 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_86 = &(PTMP_tmp3_4);
    PrtFreeValue(*P_LVALUE_86);
    *P_LVALUE_86 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_87 = &(PTMP_tmp4_4);
    PrtFreeValue(*P_LVALUE_87);
    *P_LVALUE_87 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_88 = &(PTMP_tmp5_4);
    PrtFreeValue(*P_LVALUE_88);
    *P_LVALUE_88 = (PrtMkTuple(&P_GEND_TYPE_T3iii, &(PTMP_tmp2_4), &(PTMP_tmp3_4), &(PTMP_tmp4_4)));
    
    PRT_VALUE* P_PTMP_tmp_3 = PrtCloneValue(&(P_LIT_INT32_8));
    _P_GEN_funargs[0] = &(PTMP_tmp0_4);
    _P_GEN_funargs[1] = &(PTMP_tmp1_4);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_3);
    _P_GEN_funargs[3] = &(PTMP_tmp5_4);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PrtGoto(p_this, 2U, 0);
    
p_return_4: ;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    PrtFreeValue(PTMP_tmp3_4); PTMP_tmp3_4 = NULL;
    PrtFreeValue(PTMP_tmp4_4); PTMP_tmp4_4 = NULL;
    PrtFreeValue(PTMP_tmp5_4); PTMP_tmp5_4 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    &P_GEND_TYPE_machine_handle
};


PRT_FUNDECL* P_VotingUSM_METHODS[] = { &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4 };

PRT_EVENTDECL* P_VotingUSM_RECV_INNER_1[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VotingUSM_RECV_1 =
{
    17U,
    P_VotingUSM_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_VotingUSM_SEND_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VotingUSM_SEND =
{
    17U,
    P_VotingUSM_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_VotingUSM = 
{
    2U,
    "VotingUSM",
    &P_EVENTSET_VotingUSM_RECV_1,
    &P_EVENTSET_VotingUSM_SEND,
    NULL,
    5U,
    3U,
    2U,
    4294967295U,
    0U,
    P_VotingUSM_VARS,
    P_VotingUSM_STATES,
    P_VotingUSM_METHODS,
    PRT_FALSE
};

PRT_VARDECL P_SecureBulletinBoardMachine_VARS[] = {
    { "electionResults", &P_GEND_TYPE_MKiVi },
    { "electionResultsKeys", &P_GEND_TYPE_Si },
    { "i", &P_GEND_TYPE_i },
    { "countCandidate0", &P_GEND_TYPE_i },
    { "countCandidate1", &P_GEND_TYPE_i },
    { "winner", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_3[] = { &P_EVENT_TRUSTEDeGetElectionResults };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_3 =
{
    1U,
    P_Init_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_3 =
{
    0U,
    P_Init_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_3[] = { &P_EVENT_TRUSTEDeElectionResults };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_3 =
{
    1U,
    P_Init_DOS_INNER_3,
    NULL
};

PRT_DODECL P_DOS[] =
{
    { 0, &P_EVENT_TRUSTEDeElectionResults, &P_FUNCTION_Anon_5 }
};

#define P_STATE_SecureBulletinBoardMachine_Init \
{ \
    "SecureBulletinBoardMachine.Init", \
    0U, \
    1U, \
    &P_EVENTSET_Init_DEFERS_3, \
    &P_EVENTSET_Init_TRANS_3, \
    &P_EVENTSET_Init_DOS_3, \
    NULL, \
    P_DOS, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_SendResults_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SendResults_DEFERS =
{
    0U,
    P_SendResults_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_SendResults_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SendResults_TRANS =
{
    0U,
    P_SendResults_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_SendResults_DOS_INNER[] = { &P_EVENT_TRUSTEDeGetElectionResults };
PRT_EVENTSETDECL P_EVENTSET_SendResults_DOS =
{
    1U,
    P_SendResults_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_1[] =
{
    { 1, &P_EVENT_TRUSTEDeGetElectionResults, &P_FUNCTION_Anon_6 }
};

#define P_STATE_SecureBulletinBoardMachine_SendResults \
{ \
    "SecureBulletinBoardMachine.SendResults", \
    0U, \
    1U, \
    &P_EVENTSET_SendResults_DEFERS, \
    &P_EVENTSET_SendResults_TRANS, \
    &P_EVENTSET_SendResults_DOS, \
    NULL, \
    P_DOS_1, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureBulletinBoardMachine_STATES[] = { P_STATE_SecureBulletinBoardMachine_Init, P_STATE_SecureBulletinBoardMachine_SendResults };

PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_89 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_89);
    *P_LVALUE_89 = PrtCloneValue(*P_VAR_payload_3);
    
    PrtGoto(p_this, 1U, 0);
    
p_return_5: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_MKiVi
};


PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_4 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_5 = NULL;
    PRT_VALUE* PTMP_tmp2_5 = NULL;
    PRT_VALUE* PTMP_tmp3_5 = NULL;
    PRT_VALUE* PTMP_tmp4_5 = NULL;
    PRT_VALUE* PTMP_tmp5_5 = NULL;
    PRT_VALUE* PTMP_tmp6_4 = NULL;
    PRT_VALUE* PTMP_tmp7_4 = NULL;
    PRT_VALUE* PTMP_tmp8_3 = NULL;
    PRT_VALUE* PTMP_tmp9_3 = NULL;
    PRT_VALUE* PTMP_tmp10_3 = NULL;
    PRT_VALUE* PTMP_tmp11_2 = NULL;
    PRT_VALUE* PTMP_tmp12_1 = NULL;
    PRT_VALUE* PTMP_tmp13_1 = NULL;
    PRT_VALUE* PTMP_tmp14_1 = NULL;
    PRT_VALUE* PTMP_tmp15_1 = NULL;
    PRT_VALUE* PTMP_tmp16_1 = NULL;
    PRT_VALUE* PTMP_tmp17_1 = NULL;
    PRT_VALUE* PTMP_tmp18_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_9 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_10 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_11 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_BOOLEAN_2 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_90 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_90);
    *P_LVALUE_90 = PrtTupleGet(*P_VAR_payload_4, 1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_5);
    PrtFreeValue(P_SaveCapability_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_5);
    PTMP_tmp0_5 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PRT_VALUE** P_LVALUE_91 = &(PTMP_tmp1_5);
    PrtFreeValue(*P_LVALUE_91);
    *P_LVALUE_91 = PrtMapGetKeys(p_this->varValues[0]);
    
    {
        PRT_VALUE** P_LVALUE_92 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_92);
        *P_LVALUE_92 = PTMP_tmp1_5;
        PTMP_tmp1_5 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_93 = &(p_this->varValues[2]);
    PrtFreeValue(*P_LVALUE_93);
    *P_LVALUE_93 = PrtCloneValue((&P_LIT_INT32_9));
    
    PRT_VALUE** P_LVALUE_94 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_94);
    *P_LVALUE_94 = PrtCloneValue((&P_LIT_INT32_9));
    
    PRT_VALUE** P_LVALUE_95 = &(p_this->varValues[4]);
    PrtFreeValue(*P_LVALUE_95);
    *P_LVALUE_95 = PrtCloneValue((&P_LIT_INT32_9));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_2)))
    {
        PRT_VALUE** P_LVALUE_96 = &(PTMP_tmp2_5);
        PrtFreeValue(*P_LVALUE_96);
        *P_LVALUE_96 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_97 = &(PTMP_tmp3_5);
        PrtFreeValue(*P_LVALUE_97);
        *P_LVALUE_97 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[2]) < PrtPrimGetInt(PTMP_tmp2_5));
        
        PRT_VALUE** P_LVALUE_98 = &(PTMP_tmp4_5);
        PrtFreeValue(*P_LVALUE_98);
        *P_LVALUE_98 = PrtCloneValue(PTMP_tmp3_5);
        
        if (PrtPrimGetBool(PTMP_tmp4_5))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_99 = &(PTMP_tmp5_5);
        PrtFreeValue(*P_LVALUE_99);
        *P_LVALUE_99 = PrtSeqGet(p_this->varValues[1], p_this->varValues[2]);
        
        PRT_VALUE** P_LVALUE_100 = &(PTMP_tmp6_4);
        PrtFreeValue(*P_LVALUE_100);
        *P_LVALUE_100 = PrtMapGet(p_this->varValues[0], PTMP_tmp5_5);
        
        PRT_VALUE** P_LVALUE_101 = &(PTMP_tmp7_4);
        PrtFreeValue(*P_LVALUE_101);
        *P_LVALUE_101 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp6_4, (&P_LIT_INT32_9)));
        
        if (PrtPrimGetBool(PTMP_tmp7_4))
        {
            PRT_VALUE** P_LVALUE_102 = &(PTMP_tmp8_3);
            PrtFreeValue(*P_LVALUE_102);
            *P_LVALUE_102 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[3]) + PrtPrimGetInt((&P_LIT_INT32_10)));
            
            {
                PRT_VALUE** P_LVALUE_103 = &(p_this->varValues[3]);
                PrtFreeValue(*P_LVALUE_103);
                *P_LVALUE_103 = PTMP_tmp8_3;
                PTMP_tmp8_3 = NULL;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_104 = &(PTMP_tmp9_3);
            PrtFreeValue(*P_LVALUE_104);
            *P_LVALUE_104 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[4]) + PrtPrimGetInt((&P_LIT_INT32_10)));
            
            {
                PRT_VALUE** P_LVALUE_105 = &(p_this->varValues[4]);
                PrtFreeValue(*P_LVALUE_105);
                *P_LVALUE_105 = PTMP_tmp9_3;
                PTMP_tmp9_3 = NULL;
            }
            
        }
        
        
        PrtPrintf("Incrementing candidate!");
        
        PRT_VALUE** P_LVALUE_106 = &(PTMP_tmp10_3);
        PrtFreeValue(*P_LVALUE_106);
        *P_LVALUE_106 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[2]) + PrtPrimGetInt((&P_LIT_INT32_10)));
        
        {
            PRT_VALUE** P_LVALUE_107 = &(p_this->varValues[2]);
            PrtFreeValue(*P_LVALUE_107);
            *P_LVALUE_107 = PTMP_tmp10_3;
            PTMP_tmp10_3 = NULL;
        }
        
    }
    
    
    PrtFormatPrintf("Count 0 - ", 1, p_this->varValues[3], 1, 0, "");
    
    PrtFormatPrintf("Count 1 - ", 1, p_this->varValues[4], 1, 0, "");
    
    PRT_VALUE** P_LVALUE_108 = &(PTMP_tmp11_2);
    PrtFreeValue(*P_LVALUE_108);
    *P_LVALUE_108 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[3]) > PrtPrimGetInt(p_this->varValues[4]));
    
    if (PrtPrimGetBool(PTMP_tmp11_2))
    {
        PRT_VALUE** P_LVALUE_109 = &(p_this->varValues[5]);
        PrtFreeValue(*P_LVALUE_109);
        *P_LVALUE_109 = PrtCloneValue((&P_LIT_INT32_9));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_110 = &(PTMP_tmp12_1);
        PrtFreeValue(*P_LVALUE_110);
        *P_LVALUE_110 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[4]) > PrtPrimGetInt(p_this->varValues[3]));
        
        if (PrtPrimGetBool(PTMP_tmp12_1))
        {
            PRT_VALUE** P_LVALUE_111 = &(p_this->varValues[5]);
            PrtFreeValue(*P_LVALUE_111);
            *P_LVALUE_111 = PrtCloneValue((&P_LIT_INT32_10));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_112 = &(p_this->varValues[5]);
            PrtFreeValue(*P_LVALUE_112);
            *P_LVALUE_112 = PrtCloneValue((&P_LIT_INT32_11));
            
        }
        
        
    }
    
    
    PRT_VALUE** P_LVALUE_113 = &(PTMP_tmp13_1);
    PrtFreeValue(*P_LVALUE_113);
    *P_LVALUE_113 = PrtTupleGet(*P_VAR_payload_4, 0);
    
    PRT_VALUE** P_LVALUE_114 = &(PTMP_tmp14_1);
    PrtFreeValue(*P_LVALUE_114);
    *P_LVALUE_114 = PrtCloneValue(PTMP_tmp13_1);
    
    PRT_VALUE** P_LVALUE_115 = &(PTMP_tmp15_1);
    PrtFreeValue(*P_LVALUE_115);
    *P_LVALUE_115 = PrtCloneValue((&P_EVENT_TRUSTEDeRespElectionResults.value));
    
    PRT_VALUE** P_LVALUE_116 = &(PTMP_tmp16_1);
    PrtFreeValue(*P_LVALUE_116);
    *P_LVALUE_116 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_117 = &(PTMP_tmp17_1);
    PrtFreeValue(*P_LVALUE_117);
    *P_LVALUE_117 = PrtCloneValue(p_this->varValues[5]);
    
    PRT_VALUE** P_LVALUE_118 = &(PTMP_tmp18_1);
    PrtFreeValue(*P_LVALUE_118);
    *P_LVALUE_118 = (PrtMkTuple(&P_GEND_TYPE_T2MKiVii, &(PTMP_tmp16_1), &(PTMP_tmp17_1)));
    
    PRT_VALUE* P_PTMP_tmp_4 = PrtCloneValue(&(P_LIT_INT32_10));
    _P_GEN_funargs[0] = &(PTMP_tmp14_1);
    _P_GEN_funargs[1] = &(PTMP_tmp15_1);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_4);
    _P_GEN_funargs[3] = &(PTMP_tmp18_1);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_5); PTMP_tmp1_5 = NULL;
    PrtFreeValue(PTMP_tmp2_5); PTMP_tmp2_5 = NULL;
    PrtFreeValue(PTMP_tmp3_5); PTMP_tmp3_5 = NULL;
    PrtFreeValue(PTMP_tmp4_5); PTMP_tmp4_5 = NULL;
    PrtFreeValue(PTMP_tmp5_5); PTMP_tmp5_5 = NULL;
    PrtFreeValue(PTMP_tmp6_4); PTMP_tmp6_4 = NULL;
    PrtFreeValue(PTMP_tmp7_4); PTMP_tmp7_4 = NULL;
    PrtFreeValue(PTMP_tmp8_3); PTMP_tmp8_3 = NULL;
    PrtFreeValue(PTMP_tmp9_3); PTMP_tmp9_3 = NULL;
    PrtFreeValue(PTMP_tmp10_3); PTMP_tmp10_3 = NULL;
    PrtFreeValue(PTMP_tmp11_2); PTMP_tmp11_2 = NULL;
    PrtFreeValue(PTMP_tmp12_1); PTMP_tmp12_1 = NULL;
    PrtFreeValue(PTMP_tmp13_1); PTMP_tmp13_1 = NULL;
    PrtFreeValue(PTMP_tmp14_1); PTMP_tmp14_1 = NULL;
    PrtFreeValue(PTMP_tmp15_1); PTMP_tmp15_1 = NULL;
    PrtFreeValue(PTMP_tmp16_1); PTMP_tmp16_1 = NULL;
    PrtFreeValue(PTMP_tmp17_1); PTMP_tmp17_1 = NULL;
    PrtFreeValue(PTMP_tmp18_1); PTMP_tmp18_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    &P_GEND_TYPE_T2machine_handlecapability
};


PRT_FUNDECL* P_SecureBulletinBoardMachine_METHODS[] = { &P_FUNCTION_Anon_5, &P_FUNCTION_Anon_6 };

PRT_EVENTDECL* P_SecureBulletinBoardMachine_RECV_INNER_1[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBulletinBoardMachine_RECV_1 =
{
    17U,
    P_SecureBulletinBoardMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureBulletinBoardMachine_SEND_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBulletinBoardMachine_SEND =
{
    17U,
    P_SecureBulletinBoardMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_SecureBulletinBoardMachine = 
{
    3U,
    "SecureBulletinBoardMachine",
    &P_EVENTSET_SecureBulletinBoardMachine_RECV_1,
    &P_EVENTSET_SecureBulletinBoardMachine_SEND,
    NULL,
    6U,
    2U,
    2U,
    4294967295U,
    0U,
    P_SecureBulletinBoardMachine_VARS,
    P_SecureBulletinBoardMachine_STATES,
    P_SecureBulletinBoardMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_SecureBallotBoxMachine_VARS[] = {
    { "bulletinBoard", &P_GEND_TYPE_machine_handle },
    { "tabulationTeller", &P_GEND_TYPE_machine_handle },
    { "appendOnlyLog", &P_GEND_TYPE_machine_handle },
    { "numberOfTotalVotes", &P_GEND_TYPE_i },
    { "currentNumberOfVotes", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_4[] = { &P_EVENT_TRUSTEDeVote };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_4 =
{
    1U,
    P_Init_DEFERS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_4[] = { &P_EVENT_TRUSTEDeStartElection };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_4 =
{
    1U,
    P_Init_TRANS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_4 =
{
    0U,
    P_Init_DOS_INNER_4,
    NULL
};

PRT_TRANSDECL P_TRANS_2[] =
{
    { 0, &P_EVENT_TRUSTEDeStartElection, 1, &_P_NO_OP }
};

#define P_STATE_SecureBallotBoxMachine_Init \
{ \
    "SecureBallotBoxMachine.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_4, \
    &P_EVENTSET_Init_TRANS_4, \
    &P_EVENTSET_Init_DOS_4, \
    P_TRANS_2, \
    NULL, \
    &P_FUNCTION_Anon_7, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitForVotes_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForVotes_DEFERS =
{
    0U,
    P_WaitForVotes_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForVotes_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForVotes_TRANS =
{
    0U,
    P_WaitForVotes_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForVotes_DOS_INNER[] = { &P_EVENT_TRUSTEDeVote };
PRT_EVENTSETDECL P_EVENTSET_WaitForVotes_DOS =
{
    1U,
    P_WaitForVotes_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_2[] =
{
    { 1, &P_EVENT_TRUSTEDeVote, &P_FUNCTION_Anon_9 }
};

#define P_STATE_SecureBallotBoxMachine_WaitForVotes \
{ \
    "SecureBallotBoxMachine.WaitForVotes", \
    0U, \
    1U, \
    &P_EVENTSET_WaitForVotes_DEFERS, \
    &P_EVENTSET_WaitForVotes_TRANS, \
    &P_EVENTSET_WaitForVotes_DOS, \
    NULL, \
    P_DOS_2, \
    &P_FUNCTION_Anon_8, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_VoteCounting_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_VoteCounting_DEFERS =
{
    0U,
    P_VoteCounting_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_VoteCounting_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_VoteCounting_TRANS =
{
    0U,
    P_VoteCounting_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_VoteCounting_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_VoteCounting_DOS =
{
    0U,
    P_VoteCounting_DOS_INNER,
    NULL
};

#define P_STATE_SecureBallotBoxMachine_VoteCounting \
{ \
    "SecureBallotBoxMachine.VoteCounting", \
    0U, \
    0U, \
    &P_EVENTSET_VoteCounting_DEFERS, \
    &P_EVENTSET_VoteCounting_TRANS, \
    &P_EVENTSET_VoteCounting_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_10, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureBallotBoxMachine_STATES[] = { P_STATE_SecureBallotBoxMachine_Init, P_STATE_SecureBallotBoxMachine_WaitForVotes, P_STATE_SecureBallotBoxMachine_VoteCounting };

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_5 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    PRT_VALUE* PTMP_tmp1_6 = NULL;
    PRT_VALUE* PTMP_tmp2_6 = NULL;
    PRT_VALUE* PTMP_tmp3_6 = NULL;
    PRT_VALUE* PTMP_tmp4_6 = NULL;
    PRT_VALUE* PTMP_tmp5_6 = NULL;
    PRT_VALUE* PTMP_tmp6_5 = NULL;
    PRT_VALUE* PTMP_tmp7_5 = NULL;
    PRT_VALUE* PTMP_tmp8_4 = NULL;
    PRT_VALUE* PTMP_tmp9_4 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_119 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_119);
    *P_LVALUE_119 = PrtTupleGet(*P_VAR_payload_5, 0);
    
    {
        PRT_VALUE** P_LVALUE_120 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_120);
        *P_LVALUE_120 = PTMP_tmp0_6;
        PTMP_tmp0_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_121 = &(PTMP_tmp1_6);
    PrtFreeValue(*P_LVALUE_121);
    *P_LVALUE_121 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    PRT_VALUE** P_LVALUE_122 = &(PTMP_tmp2_6);
    PrtFreeValue(*P_LVALUE_122);
    *P_LVALUE_122 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    PRT_VALUE** P_LVALUE_123 = &(PTMP_tmp3_6);
    PrtFreeValue(*P_LVALUE_123);
    *P_LVALUE_123 = ((_P_GEN_funargs[0] = &(PTMP_tmp2_6)), (_P_GEN_funval = P_GetCapability_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp2_6), PTMP_tmp2_6 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    PRT_VALUE** P_LVALUE_124 = &(PTMP_tmp4_6);
    PrtFreeValue(*P_LVALUE_124);
    *P_LVALUE_124 = (PrtMkTuple(&P_GEND_TYPE_T2machine_handlecapability_2, &(PTMP_tmp1_6), &(PTMP_tmp3_6)));
    
    _P_GEN_funargs[0] = "SecureTamperEvidentLogMachine";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp4_6);
    PRT_VALUE** P_LVALUE_125 = &(PTMP_tmp5_6);
    PrtFreeValue(*P_LVALUE_125);
    *P_LVALUE_125 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    {
        PRT_VALUE** P_LVALUE_126 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_126);
        *P_LVALUE_126 = PTMP_tmp5_6;
        PTMP_tmp5_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_127 = &(PTMP_tmp6_5);
    PrtFreeValue(*P_LVALUE_127);
    *P_LVALUE_127 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_128 = &(PTMP_tmp7_5);
    PrtFreeValue(*P_LVALUE_128);
    *P_LVALUE_128 = PrtTupleGet(*P_VAR_payload_5, 1);
    
    PRT_VALUE** P_LVALUE_129 = &(PTMP_tmp8_4);
    PrtFreeValue(*P_LVALUE_129);
    *P_LVALUE_129 = (PrtMkTuple(&P_GEND_TYPE_T2machine_handlecapability_1, &(PTMP_tmp6_5), &(PTMP_tmp7_5)));
    
    _P_GEN_funargs[0] = "SecureTabulationTellerMachine";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp8_4);
    PRT_VALUE** P_LVALUE_130 = &(PTMP_tmp9_4);
    PrtFreeValue(*P_LVALUE_130);
    *P_LVALUE_130 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    {
        PRT_VALUE** P_LVALUE_131 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_131);
        *P_LVALUE_131 = PTMP_tmp9_4;
        PTMP_tmp9_4 = NULL;
    }
    
p_return_7: ;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    PrtFreeValue(PTMP_tmp1_6); PTMP_tmp1_6 = NULL;
    PrtFreeValue(PTMP_tmp2_6); PTMP_tmp2_6 = NULL;
    PrtFreeValue(PTMP_tmp3_6); PTMP_tmp3_6 = NULL;
    PrtFreeValue(PTMP_tmp4_6); PTMP_tmp4_6 = NULL;
    PrtFreeValue(PTMP_tmp5_6); PTMP_tmp5_6 = NULL;
    PrtFreeValue(PTMP_tmp6_5); PTMP_tmp6_5 = NULL;
    PrtFreeValue(PTMP_tmp7_5); PTMP_tmp7_5 = NULL;
    PrtFreeValue(PTMP_tmp8_4); PTMP_tmp8_4 = NULL;
    PrtFreeValue(PTMP_tmp9_4); PTMP_tmp9_4 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_T2machine_handlecapability_1
};


PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_6 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_12 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_132 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_132);
    *P_LVALUE_132 = PrtCloneValue(*P_VAR_payload_6);
    
    PRT_VALUE** P_LVALUE_133 = &(p_this->varValues[4]);
    PrtFreeValue(*P_LVALUE_133);
    *P_LVALUE_133 = PrtCloneValue((&P_LIT_INT32_12));
    
p_return_8: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_8,
    &P_GEND_TYPE_i
};


PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_7 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_7 = NULL;
    PRT_VALUE* PTMP_tmp1_7 = NULL;
    PRT_VALUE* PTMP_tmp2_7 = NULL;
    PRT_VALUE* PTMP_tmp3_7 = NULL;
    PRT_VALUE* PTMP_tmp4_7 = NULL;
    PRT_VALUE* PTMP_tmp5_7 = NULL;
    PRT_VALUE* PTMP_tmp6_6 = NULL;
    PRT_VALUE* PTMP_tmp7_6 = NULL;
    PRT_VALUE* PTMP_tmp8_5 = NULL;
    PRT_VALUE* PTMP_tmp9_5 = NULL;
    PRT_VALUE* PTMP_tmp10_4 = NULL;
    PRT_VALUE* P_VAR_P_payload = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_13 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_134 = &(PTMP_tmp0_7);
    PrtFreeValue(*P_LVALUE_134);
    *P_LVALUE_134 = PrtTupleGet(*P_VAR_payload_7, 3);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_7);
    PrtFreeValue(P_SaveCapability_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_7);
    PTMP_tmp0_7 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_9;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_9;
    }
    
    PRT_VALUE** P_LVALUE_135 = &(PTMP_tmp1_7);
    PrtFreeValue(*P_LVALUE_135);
    *P_LVALUE_135 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_136 = &(PTMP_tmp2_7);
    PrtFreeValue(*P_LVALUE_136);
    *P_LVALUE_136 = PrtCloneValue((&P_EVENT_TRUSTEDeAddItem.value));
    
    PRT_VALUE** P_LVALUE_137 = &(PTMP_tmp3_7);
    PrtFreeValue(*P_LVALUE_137);
    *P_LVALUE_137 = PrtTupleGet(*P_VAR_payload_7, 0);
    
    PRT_VALUE** P_LVALUE_138 = &(PTMP_tmp4_7);
    PrtFreeValue(*P_LVALUE_138);
    *P_LVALUE_138 = PrtTupleGet(*P_VAR_payload_7, 1);
    
    PRT_VALUE** P_LVALUE_139 = &(PTMP_tmp5_7);
    PrtFreeValue(*P_LVALUE_139);
    *P_LVALUE_139 = (PrtMkTuple(&P_GEND_TYPE_T2ii, &(PTMP_tmp3_7), &(PTMP_tmp4_7)));
    
    PRT_VALUE* P_PTMP_tmp_5 = PrtCloneValue(&(P_LIT_INT32_13));
    _P_GEN_funargs[0] = &(PTMP_tmp1_7);
    _P_GEN_funargs[1] = &(PTMP_tmp2_7);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_5);
    _P_GEN_funargs[3] = &(PTMP_tmp5_7);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_9;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_9;
    }
    
    PRT_UINT32 P_allowedEventIds[] = { 2 };
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    PRT_UINT32 P_eventId = PrtReceiveAsync(1U, P_allowedEventIds, &P_VAR_P_payload);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_9;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_9;
    }
    switch (P_eventId) {
        case 2: {
            PRT_VALUE** P_VAR_result = &P_VAR_P_payload;
            PRT_VALUE P_LIT_INT32_14 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
            PRT_VALUE P_LIT_INT32_15 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
                        if (PrtPrimGetBool(*P_VAR_result))
            {
                PRT_VALUE** P_LVALUE_140 = &(PTMP_tmp6_6);
                PrtFreeValue(*P_LVALUE_140);
                *P_LVALUE_140 = PrtTupleGet(*P_VAR_payload_7, 2);
                
                PRT_VALUE** P_LVALUE_141 = &(PTMP_tmp7_6);
                PrtFreeValue(*P_LVALUE_141);
                *P_LVALUE_141 = PrtCloneValue(PTMP_tmp6_6);
                
                PRT_VALUE** P_LVALUE_142 = &(PTMP_tmp8_5);
                PrtFreeValue(*P_LVALUE_142);
                *P_LVALUE_142 = PrtCloneValue((&P_EVENT_TRUSTEDeRespConfirmVote.value));
                
                PRT_VALUE* P_PTMP_tmp_6 = PrtCloneValue(&(P_LIT_INT32_14));
                _P_GEN_funargs[0] = &(PTMP_tmp7_6);
                _P_GEN_funargs[1] = &(PTMP_tmp8_5);
                _P_GEN_funargs[2] = &(P_PTMP_tmp_6);
                PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_9;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_9;
                }
                
                PRT_VALUE** P_LVALUE_143 = &(PTMP_tmp9_5);
                PrtFreeValue(*P_LVALUE_143);
                *P_LVALUE_143 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[4]) + PrtPrimGetInt((&P_LIT_INT32_15)));
                
                {
                    PRT_VALUE** P_LVALUE_144 = &(p_this->varValues[4]);
                    PrtFreeValue(*P_LVALUE_144);
                    *P_LVALUE_144 = PTMP_tmp9_5;
                    PTMP_tmp9_5 = NULL;
                }
                
            }
            
            else
            {
            }
            
            
            p_return_10: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    
    PRT_VALUE** P_LVALUE_145 = &(PTMP_tmp10_4);
    PrtFreeValue(*P_LVALUE_145);
    *P_LVALUE_145 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[4]) >= PrtPrimGetInt(p_this->varValues[3]));
    
    if (PrtPrimGetBool(PTMP_tmp10_4))
    {
        PrtGoto(p_this, 2U, 0);
        
    }
    
    else
    {
    }
    
    
p_return_9: ;
    PrtFreeValue(PTMP_tmp0_7); PTMP_tmp0_7 = NULL;
    PrtFreeValue(PTMP_tmp1_7); PTMP_tmp1_7 = NULL;
    PrtFreeValue(PTMP_tmp2_7); PTMP_tmp2_7 = NULL;
    PrtFreeValue(PTMP_tmp3_7); PTMP_tmp3_7 = NULL;
    PrtFreeValue(PTMP_tmp4_7); PTMP_tmp4_7 = NULL;
    PrtFreeValue(PTMP_tmp5_7); PTMP_tmp5_7 = NULL;
    PrtFreeValue(PTMP_tmp6_6); PTMP_tmp6_6 = NULL;
    PrtFreeValue(PTMP_tmp7_6); PTMP_tmp7_6 = NULL;
    PrtFreeValue(PTMP_tmp8_5); PTMP_tmp8_5 = NULL;
    PrtFreeValue(PTMP_tmp9_5); PTMP_tmp9_5 = NULL;
    PrtFreeValue(PTMP_tmp10_4); PTMP_tmp10_4 = NULL;
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_9 =
{
    NULL,
    &P_Anon_IMPL_9,
    &P_GEND_TYPE_T4iimachine_handlecapability
};


PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_8 = NULL;
    PRT_VALUE* PTMP_tmp1_8 = NULL;
    PRT_VALUE* PTMP_tmp2_8 = NULL;
    PRT_VALUE* PTMP_tmp3_8 = NULL;
    PRT_VALUE* PTMP_tmp4_8 = NULL;
    PRT_VALUE* PTMP_tmp5_8 = NULL;
    PRT_VALUE* PTMP_tmp6_7 = NULL;
    PRT_VALUE* P_VAR_P_payload_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_16 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_146 = &(PTMP_tmp0_8);
    PrtFreeValue(*P_LVALUE_146);
    *P_LVALUE_146 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_147 = &(PTMP_tmp1_8);
    PrtFreeValue(*P_LVALUE_147);
    *P_LVALUE_147 = PrtCloneValue((&P_EVENT_TRUSTEDeGetLog.value));
    
    PRT_VALUE* P_PTMP_tmp_7 = PrtCloneValue(&(P_LIT_INT32_16));
    _P_GEN_funargs[0] = &(PTMP_tmp0_8);
    _P_GEN_funargs[1] = &(PTMP_tmp1_8);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_7);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_11;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_11;
    }
    
    PRT_UINT32 P_allowedEventIds_1[] = { 3 };
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    PRT_UINT32 P_eventId_1 = PrtReceiveAsync(1U, P_allowedEventIds_1, &P_VAR_P_payload_1);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_11;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_11;
    }
    switch (P_eventId_1) {
        case 3: {
            PRT_VALUE** P_VAR_payload_8 = &P_VAR_P_payload_1;
            PRT_VALUE P_LIT_INT32_17 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
            PRT_VALUE P_LIT_INT32_18 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
                        PrtPrintf("Sending votes to Secure Tabulation teller");
            
            PRT_VALUE** P_LVALUE_148 = &(PTMP_tmp2_8);
            PrtFreeValue(*P_LVALUE_148);
            *P_LVALUE_148 = PrtCloneValue(p_this->varValues[1]);
            
            PRT_VALUE** P_LVALUE_149 = &(PTMP_tmp3_8);
            PrtFreeValue(*P_LVALUE_149);
            *P_LVALUE_149 = PrtCloneValue((&P_EVENT_TRUSTEDeAllVotes.value));
            
            PRT_VALUE** P_LVALUE_150 = &(PTMP_tmp4_8);
            PrtFreeValue(*P_LVALUE_150);
            *P_LVALUE_150 = PrtCloneValue((&P_LIT_INT32_17));
            
            PRT_VALUE** P_LVALUE_151 = &(PTMP_tmp5_8);
            PrtFreeValue(*P_LVALUE_151);
            *P_LVALUE_151 = PrtCloneValue(*P_VAR_payload_8);
            
            PRT_VALUE** P_LVALUE_152 = &(PTMP_tmp6_7);
            PrtFreeValue(*P_LVALUE_152);
            *P_LVALUE_152 = (PrtMkTuple(&P_GEND_TYPE_T2iST2ii, &(PTMP_tmp4_8), &(PTMP_tmp5_8)));
            
            PRT_VALUE* P_PTMP_tmp_8 = PrtCloneValue(&(P_LIT_INT32_18));
            _P_GEN_funargs[0] = &(PTMP_tmp2_8);
            _P_GEN_funargs[1] = &(PTMP_tmp3_8);
            _P_GEN_funargs[2] = &(P_PTMP_tmp_8);
            _P_GEN_funargs[3] = &(PTMP_tmp6_7);
            PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_11;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_11;
            }
            
            p_return_12: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    
p_return_11: ;
    PrtFreeValue(PTMP_tmp0_8); PTMP_tmp0_8 = NULL;
    PrtFreeValue(PTMP_tmp1_8); PTMP_tmp1_8 = NULL;
    PrtFreeValue(PTMP_tmp2_8); PTMP_tmp2_8 = NULL;
    PrtFreeValue(PTMP_tmp3_8); PTMP_tmp3_8 = NULL;
    PrtFreeValue(PTMP_tmp4_8); PTMP_tmp4_8 = NULL;
    PrtFreeValue(PTMP_tmp5_8); PTMP_tmp5_8 = NULL;
    PrtFreeValue(PTMP_tmp6_7); PTMP_tmp6_7 = NULL;
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_10 =
{
    NULL,
    &P_Anon_IMPL_10,
    NULL
};


PRT_FUNDECL* P_SecureBallotBoxMachine_METHODS[] = { &P_FUNCTION_Anon_7, &P_FUNCTION_Anon_8, &P_FUNCTION_Anon_9, &P_FUNCTION_Anon_10 };

PRT_EVENTDECL* P_SecureBallotBoxMachine_RECV_INNER_1[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBallotBoxMachine_RECV_1 =
{
    17U,
    P_SecureBallotBoxMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureBallotBoxMachine_SEND_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBallotBoxMachine_SEND =
{
    17U,
    P_SecureBallotBoxMachine_SEND_INNER,
    NULL
};

PRT_UINT32 P_SecureBallotBoxMachine_CREATES_ARR[] = { 6, 5 };
PRT_INTERFACESETDECL P_SecureBallotBoxMachine_CREATES = { 2, P_SecureBallotBoxMachine_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_SecureBallotBoxMachine = 
{
    4U,
    "SecureBallotBoxMachine",
    &P_EVENTSET_SecureBallotBoxMachine_RECV_1,
    &P_EVENTSET_SecureBallotBoxMachine_SEND,
    &P_SecureBallotBoxMachine_CREATES,
    5U,
    3U,
    4U,
    4294967295U,
    0U,
    P_SecureBallotBoxMachine_VARS,
    P_SecureBallotBoxMachine_STATES,
    P_SecureBallotBoxMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_SecureTamperEvidentLogMachine_VARS[] = {
    { "log", &P_GEND_TYPE_ST2ii },
    { "parent", &P_GEND_TYPE_machine_handle }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_5[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_5 =
{
    0U,
    P_Init_DEFERS_INNER_5,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_5[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_5 =
{
    0U,
    P_Init_TRANS_INNER_5,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_5[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_5 =
{
    0U,
    P_Init_DOS_INNER_5,
    NULL
};

#define P_STATE_SecureTamperEvidentLogMachine_Init \
{ \
    "SecureTamperEvidentLogMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_5, \
    &P_EVENTSET_Init_TRANS_5, \
    &P_EVENTSET_Init_DOS_5, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_11, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitForRequests_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForRequests_DEFERS =
{
    0U,
    P_WaitForRequests_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForRequests_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForRequests_TRANS =
{
    0U,
    P_WaitForRequests_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForRequests_DOS_INNER[] = { &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeGetLog };
PRT_EVENTSETDECL P_EVENTSET_WaitForRequests_DOS =
{
    2U,
    P_WaitForRequests_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_3[] =
{
    { 1, &P_EVENT_TRUSTEDeAddItem, &P_FUNCTION_Anon_12 },
    { 1, &P_EVENT_TRUSTEDeGetLog, &P_FUNCTION_Anon_13 }
};

#define P_STATE_SecureTamperEvidentLogMachine_WaitForRequests \
{ \
    "SecureTamperEvidentLogMachine.WaitForRequests", \
    0U, \
    2U, \
    &P_EVENTSET_WaitForRequests_DEFERS, \
    &P_EVENTSET_WaitForRequests_TRANS, \
    &P_EVENTSET_WaitForRequests_DOS, \
    NULL, \
    P_DOS_3, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureTamperEvidentLogMachine_STATES[] = { P_STATE_SecureTamperEvidentLogMachine_Init, P_STATE_SecureTamperEvidentLogMachine_WaitForRequests };

PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_9 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_9 = NULL;
    PRT_VALUE* PTMP_tmp1_9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_153 = &(PTMP_tmp0_9);
    PrtFreeValue(*P_LVALUE_153);
    *P_LVALUE_153 = PrtTupleGet(*P_VAR_payload_9, 0);
    
    {
        PRT_VALUE** P_LVALUE_154 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_154);
        *P_LVALUE_154 = PTMP_tmp0_9;
        PTMP_tmp0_9 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_155 = &(PTMP_tmp1_9);
    PrtFreeValue(*P_LVALUE_155);
    *P_LVALUE_155 = PrtTupleGet(*P_VAR_payload_9, 1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp1_9);
    PrtFreeValue(P_SaveCapability_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp1_9);
    PTMP_tmp1_9 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_13;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_13;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_13: ;
    PrtFreeValue(PTMP_tmp0_9); PTMP_tmp0_9 = NULL;
    PrtFreeValue(PTMP_tmp1_9); PTMP_tmp1_9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_11 =
{
    NULL,
    &P_Anon_IMPL_11,
    &P_GEND_TYPE_T2machine_handlecapability_2
};


PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_10 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_10 = NULL;
    PRT_VALUE* PTMP_tmp1_10 = NULL;
    PRT_VALUE* PTMP_tmp2_9 = NULL;
    PRT_VALUE* PTMP_tmp3_9 = NULL;
    PRT_VALUE* PTMP_tmp4_9 = NULL;
    PRT_VALUE* PTMP_tmp5_9 = NULL;
    PRT_VALUE* PTMP_tmp6_8 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_19 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_3 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_156 = &(PTMP_tmp0_10);
    PrtFreeValue(*P_LVALUE_156);
    *P_LVALUE_156 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[0]));
    
    PRT_VALUE** P_LVALUE_157 = &(PTMP_tmp1_10);
    PrtFreeValue(*P_LVALUE_157);
    *P_LVALUE_157 = PrtTupleGet(*P_VAR_payload_10, 0);
    
    PRT_VALUE** P_LVALUE_158 = &(PTMP_tmp2_9);
    PrtFreeValue(*P_LVALUE_158);
    *P_LVALUE_158 = PrtTupleGet(*P_VAR_payload_10, 1);
    
    PRT_VALUE** P_LVALUE_159 = &(PTMP_tmp3_9);
    PrtFreeValue(*P_LVALUE_159);
    *P_LVALUE_159 = (PrtMkTuple(&P_GEND_TYPE_T2ii, &(PTMP_tmp1_10), &(PTMP_tmp2_9)));
    
    PrtSeqInsertEx(p_this->varValues[0], PTMP_tmp0_10, PTMP_tmp3_9, PRT_FALSE);
    *(&(PTMP_tmp3_9)) = NULL;
    
    PRT_VALUE** P_LVALUE_160 = &(PTMP_tmp4_9);
    PrtFreeValue(*P_LVALUE_160);
    *P_LVALUE_160 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_161 = &(PTMP_tmp5_9);
    PrtFreeValue(*P_LVALUE_161);
    *P_LVALUE_161 = PrtCloneValue((&P_EVENT_TRUSTEDeRespAddItem.value));
    
    PRT_VALUE** P_LVALUE_162 = &(PTMP_tmp6_8);
    PrtFreeValue(*P_LVALUE_162);
    *P_LVALUE_162 = PrtCloneValue((&P_LIT_BOOLEAN_3));
    
    PRT_VALUE* P_PTMP_tmp_9 = PrtCloneValue(&(P_LIT_INT32_19));
    _P_GEN_funargs[0] = &(PTMP_tmp4_9);
    _P_GEN_funargs[1] = &(PTMP_tmp5_9);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_9);
    _P_GEN_funargs[3] = &(PTMP_tmp6_8);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
p_return_14: ;
    PrtFreeValue(PTMP_tmp0_10); PTMP_tmp0_10 = NULL;
    PrtFreeValue(PTMP_tmp1_10); PTMP_tmp1_10 = NULL;
    PrtFreeValue(PTMP_tmp2_9); PTMP_tmp2_9 = NULL;
    PrtFreeValue(PTMP_tmp3_9); PTMP_tmp3_9 = NULL;
    PrtFreeValue(PTMP_tmp4_9); PTMP_tmp4_9 = NULL;
    PrtFreeValue(PTMP_tmp5_9); PTMP_tmp5_9 = NULL;
    PrtFreeValue(PTMP_tmp6_8); PTMP_tmp6_8 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_12 =
{
    NULL,
    &P_Anon_IMPL_12,
    &P_GEND_TYPE_T2ii
};


PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_11 = NULL;
    PRT_VALUE* PTMP_tmp1_11 = NULL;
    PRT_VALUE* PTMP_tmp2_10 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_20 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PrtPrintf("Is issue here?");
    
    PRT_VALUE** P_LVALUE_163 = &(PTMP_tmp0_11);
    PrtFreeValue(*P_LVALUE_163);
    *P_LVALUE_163 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_164 = &(PTMP_tmp1_11);
    PrtFreeValue(*P_LVALUE_164);
    *P_LVALUE_164 = PrtCloneValue((&P_EVENT_TRUSTEDeRespGetLog.value));
    
    PRT_VALUE** P_LVALUE_165 = &(PTMP_tmp2_10);
    PrtFreeValue(*P_LVALUE_165);
    *P_LVALUE_165 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE* P_PTMP_tmp_10 = PrtCloneValue(&(P_LIT_INT32_20));
    _P_GEN_funargs[0] = &(PTMP_tmp0_11);
    _P_GEN_funargs[1] = &(PTMP_tmp1_11);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_10);
    _P_GEN_funargs[3] = &(PTMP_tmp2_10);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    
p_return_15: ;
    PrtFreeValue(PTMP_tmp0_11); PTMP_tmp0_11 = NULL;
    PrtFreeValue(PTMP_tmp1_11); PTMP_tmp1_11 = NULL;
    PrtFreeValue(PTMP_tmp2_10); PTMP_tmp2_10 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_13 =
{
    NULL,
    &P_Anon_IMPL_13,
    NULL
};


PRT_FUNDECL* P_SecureTamperEvidentLogMachine_METHODS[] = { &P_FUNCTION_Anon_11, &P_FUNCTION_Anon_12, &P_FUNCTION_Anon_13 };

PRT_EVENTDECL* P_SecureTamperEvidentLogMachine_RECV_INNER_1[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTamperEvidentLogMachine_RECV_1 =
{
    17U,
    P_SecureTamperEvidentLogMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureTamperEvidentLogMachine_SEND_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTamperEvidentLogMachine_SEND =
{
    17U,
    P_SecureTamperEvidentLogMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_SecureTamperEvidentLogMachine = 
{
    5U,
    "SecureTamperEvidentLogMachine",
    &P_EVENTSET_SecureTamperEvidentLogMachine_RECV_1,
    &P_EVENTSET_SecureTamperEvidentLogMachine_SEND,
    NULL,
    2U,
    2U,
    3U,
    4294967295U,
    0U,
    P_SecureTamperEvidentLogMachine_VARS,
    P_SecureTamperEvidentLogMachine_STATES,
    P_SecureTamperEvidentLogMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_SecureTabulationTellerMachine_VARS[] = {
    { "bulletinBoard", &P_GEND_TYPE_machine_handle },
    { "allVotes", &P_GEND_TYPE_ST2ii }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_6[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_6 =
{
    0U,
    P_Init_DEFERS_INNER_6,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_6[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_6 =
{
    0U,
    P_Init_TRANS_INNER_6,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_6[] = { &P_EVENT_TRUSTEDeAllVotes };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_6 =
{
    1U,
    P_Init_DOS_INNER_6,
    NULL
};

PRT_DODECL P_DOS_4[] =
{
    { 0, &P_EVENT_TRUSTEDeAllVotes, &P_FUNCTION_Anon_15 }
};

#define P_STATE_SecureTabulationTellerMachine_Init \
{ \
    "SecureTabulationTellerMachine.Init", \
    0U, \
    1U, \
    &P_EVENTSET_Init_DEFERS_6, \
    &P_EVENTSET_Init_TRANS_6, \
    &P_EVENTSET_Init_DOS_6, \
    NULL, \
    P_DOS_4, \
    &P_FUNCTION_Anon_14, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_DoTally_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_DoTally_DEFERS =
{
    0U,
    P_DoTally_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_DoTally_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_DoTally_TRANS =
{
    0U,
    P_DoTally_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_DoTally_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_DoTally_DOS =
{
    0U,
    P_DoTally_DOS_INNER,
    NULL
};

#define P_STATE_SecureTabulationTellerMachine_DoTally \
{ \
    "SecureTabulationTellerMachine.DoTally", \
    0U, \
    0U, \
    &P_EVENTSET_DoTally_DEFERS, \
    &P_EVENTSET_DoTally_TRANS, \
    &P_EVENTSET_DoTally_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_16, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureTabulationTellerMachine_STATES[] = { P_STATE_SecureTabulationTellerMachine_Init, P_STATE_SecureTabulationTellerMachine_DoTally };

PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_11 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_12 = NULL;
    PRT_VALUE* PTMP_tmp1_12 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_166 = &(PTMP_tmp0_12);
    PrtFreeValue(*P_LVALUE_166);
    *P_LVALUE_166 = PrtTupleGet(*P_VAR_payload_11, 0);
    
    {
        PRT_VALUE** P_LVALUE_167 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_167);
        *P_LVALUE_167 = PTMP_tmp0_12;
        PTMP_tmp0_12 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_168 = &(PTMP_tmp1_12);
    PrtFreeValue(*P_LVALUE_168);
    *P_LVALUE_168 = PrtTupleGet(*P_VAR_payload_11, 1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp1_12);
    PrtFreeValue(P_SaveCapability_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp1_12);
    PTMP_tmp1_12 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
p_return_16: ;
    PrtFreeValue(PTMP_tmp0_12); PTMP_tmp0_12 = NULL;
    PrtFreeValue(PTMP_tmp1_12); PTMP_tmp1_12 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_14 =
{
    NULL,
    &P_Anon_IMPL_14,
    &P_GEND_TYPE_T2machine_handlecapability_1
};


PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_12 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_13 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_169 = &(PTMP_tmp0_13);
    PrtFreeValue(*P_LVALUE_169);
    *P_LVALUE_169 = PrtTupleGet(*P_VAR_payload_12, 1);
    
    {
        PRT_VALUE** P_LVALUE_170 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_170);
        *P_LVALUE_170 = PTMP_tmp0_13;
        PTMP_tmp0_13 = NULL;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_17: ;
    PrtFreeValue(PTMP_tmp0_13); PTMP_tmp0_13 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_15 =
{
    NULL,
    &P_Anon_IMPL_15,
    &P_GEND_TYPE_T2iST2ii
};


PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_result_1 = PrtMkDefaultValue(&P_GEND_TYPE_MKiVi);
    PRT_VALUE* P_VAR_i = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_14 = NULL;
    PRT_VALUE* PTMP_tmp1_13 = NULL;
    PRT_VALUE* PTMP_tmp2_11 = NULL;
    PRT_VALUE* PTMP_tmp3_10 = NULL;
    PRT_VALUE* PTMP_tmp4_10 = NULL;
    PRT_VALUE* PTMP_tmp5_10 = NULL;
    PRT_VALUE* PTMP_tmp6_9 = NULL;
    PRT_VALUE* PTMP_tmp7_7 = NULL;
    PRT_VALUE* PTMP_tmp8_6 = NULL;
    PRT_VALUE* PTMP_tmp9_6 = NULL;
    PRT_VALUE* PTMP_tmp10_5 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_21 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_22 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_4 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_171 = &(P_VAR_i);
    PrtFreeValue(*P_LVALUE_171);
    *P_LVALUE_171 = PrtCloneValue((&P_LIT_INT32_21));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_4)))
    {
        PRT_VALUE** P_LVALUE_172 = &(PTMP_tmp0_14);
        PrtFreeValue(*P_LVALUE_172);
        *P_LVALUE_172 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_173 = &(PTMP_tmp1_13);
        PrtFreeValue(*P_LVALUE_173);
        *P_LVALUE_173 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_i) < PrtPrimGetInt(PTMP_tmp0_14));
        
        PRT_VALUE** P_LVALUE_174 = &(PTMP_tmp2_11);
        PrtFreeValue(*P_LVALUE_174);
        *P_LVALUE_174 = PrtCloneValue(PTMP_tmp1_13);
        
        if (PrtPrimGetBool(PTMP_tmp2_11))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_175 = &(PTMP_tmp3_10);
        PrtFreeValue(*P_LVALUE_175);
        *P_LVALUE_175 = PrtSeqGet(p_this->varValues[1], P_VAR_i);
        
        PRT_VALUE** P_LVALUE_176 = &(PTMP_tmp4_10);
        PrtFreeValue(*P_LVALUE_176);
        *P_LVALUE_176 = PrtTupleGet(PTMP_tmp3_10, 0);
        
        PRT_VALUE** P_LVALUE_177 = &(PTMP_tmp5_10);
        PrtFreeValue(*P_LVALUE_177);
        *P_LVALUE_177 = PrtSeqGet(p_this->varValues[1], P_VAR_i);
        
        PRT_VALUE** P_LVALUE_178 = &(PTMP_tmp6_9);
        PrtFreeValue(*P_LVALUE_178);
        *P_LVALUE_178 = PrtTupleGet(PTMP_tmp5_10, 1);
        
        {
            PRT_VALUE** P_LVALUE_179 = &(*(PrtMapGetLValue(P_VAR_result_1, PTMP_tmp4_10, PRT_TRUE, &P_GEND_TYPE_MKiVi)));
            PrtFreeValue(*P_LVALUE_179);
            *P_LVALUE_179 = PTMP_tmp6_9;
            PTMP_tmp6_9 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_180 = &(PTMP_tmp7_7);
        PrtFreeValue(*P_LVALUE_180);
        *P_LVALUE_180 = PrtMkIntValue(PrtPrimGetInt(P_VAR_i) + PrtPrimGetInt((&P_LIT_INT32_22)));
        
        {
            PRT_VALUE** P_LVALUE_181 = &(P_VAR_i);
            PrtFreeValue(*P_LVALUE_181);
            *P_LVALUE_181 = PTMP_tmp7_7;
            PTMP_tmp7_7 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_182 = &(PTMP_tmp8_6);
    PrtFreeValue(*P_LVALUE_182);
    *P_LVALUE_182 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_183 = &(PTMP_tmp9_6);
    PrtFreeValue(*P_LVALUE_183);
    *P_LVALUE_183 = PrtCloneValue((&P_EVENT_TRUSTEDeElectionResults.value));
    
    PRT_VALUE** P_LVALUE_184 = &(PTMP_tmp10_5);
    PrtFreeValue(*P_LVALUE_184);
    *P_LVALUE_184 = PrtCloneValue(P_VAR_result_1);
    
    PRT_VALUE* P_PTMP_tmp_11 = PrtCloneValue(&(P_LIT_INT32_22));
    _P_GEN_funargs[0] = &(PTMP_tmp8_6);
    _P_GEN_funargs[1] = &(PTMP_tmp9_6);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_11);
    _P_GEN_funargs[3] = &(PTMP_tmp10_5);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_18;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_18;
    }
    
p_return_18: ;
    PrtFreeValue(P_VAR_result_1); P_VAR_result_1 = NULL;
    PrtFreeValue(P_VAR_i); P_VAR_i = NULL;
    PrtFreeValue(PTMP_tmp0_14); PTMP_tmp0_14 = NULL;
    PrtFreeValue(PTMP_tmp1_13); PTMP_tmp1_13 = NULL;
    PrtFreeValue(PTMP_tmp2_11); PTMP_tmp2_11 = NULL;
    PrtFreeValue(PTMP_tmp3_10); PTMP_tmp3_10 = NULL;
    PrtFreeValue(PTMP_tmp4_10); PTMP_tmp4_10 = NULL;
    PrtFreeValue(PTMP_tmp5_10); PTMP_tmp5_10 = NULL;
    PrtFreeValue(PTMP_tmp6_9); PTMP_tmp6_9 = NULL;
    PrtFreeValue(PTMP_tmp7_7); PTMP_tmp7_7 = NULL;
    PrtFreeValue(PTMP_tmp8_6); PTMP_tmp8_6 = NULL;
    PrtFreeValue(PTMP_tmp9_6); PTMP_tmp9_6 = NULL;
    PrtFreeValue(PTMP_tmp10_5); PTMP_tmp10_5 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_16 =
{
    NULL,
    &P_Anon_IMPL_16,
    NULL
};


PRT_FUNDECL* P_SecureTabulationTellerMachine_METHODS[] = { &P_FUNCTION_Anon_14, &P_FUNCTION_Anon_15, &P_FUNCTION_Anon_16 };

PRT_EVENTDECL* P_SecureTabulationTellerMachine_RECV_INNER_1[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTabulationTellerMachine_RECV_1 =
{
    17U,
    P_SecureTabulationTellerMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureTabulationTellerMachine_SEND_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTabulationTellerMachine_SEND =
{
    17U,
    P_SecureTabulationTellerMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_SecureTabulationTellerMachine = 
{
    6U,
    "SecureTabulationTellerMachine",
    &P_EVENTSET_SecureTabulationTellerMachine_RECV_1,
    &P_EVENTSET_SecureTabulationTellerMachine_SEND,
    NULL,
    2U,
    2U,
    3U,
    4294967295U,
    0U,
    P_SecureTabulationTellerMachine_VARS,
    P_SecureTabulationTellerMachine_STATES,
    P_SecureTabulationTellerMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_SecureVotingClientMachine_VARS[] = {
    { "credential", &P_GEND_TYPE_i },
    { "ballotBox", &P_GEND_TYPE_machine_handle },
    { "bulletinBoard", &P_GEND_TYPE_machine_handle },
    { "username", &P_GEND_TYPE_i },
    { "password", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_7[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_7 =
{
    0U,
    P_Init_DEFERS_INNER_7,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_7[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_7 =
{
    0U,
    P_Init_TRANS_INNER_7,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_7[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_7 =
{
    0U,
    P_Init_DOS_INNER_7,
    NULL
};

#define P_STATE_SecureVotingClientMachine_Init \
{ \
    "SecureVotingClientMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_7, \
    &P_EVENTSET_Init_TRANS_7, \
    &P_EVENTSET_Init_DOS_7, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_17, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitForVote_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForVote_DEFERS =
{
    0U,
    P_WaitForVote_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForVote_TRANS_INNER[] = { &P_EVENT_UNTRUSTEDVoteRequest };
PRT_EVENTSETDECL P_EVENTSET_WaitForVote_TRANS =
{
    1U,
    P_WaitForVote_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForVote_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForVote_DOS =
{
    0U,
    P_WaitForVote_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_3[] =
{
    { 1, &P_EVENT_UNTRUSTEDVoteRequest, 2, &_P_NO_OP }
};

#define P_STATE_SecureVotingClientMachine_WaitForVote \
{ \
    "SecureVotingClientMachine.WaitForVote", \
    1U, \
    0U, \
    &P_EVENTSET_WaitForVote_DEFERS, \
    &P_EVENTSET_WaitForVote_TRANS, \
    &P_EVENTSET_WaitForVote_DOS, \
    P_TRANS_3, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_AcceptVote_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_AcceptVote_DEFERS =
{
    0U,
    P_AcceptVote_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_AcceptVote_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_AcceptVote_TRANS =
{
    0U,
    P_AcceptVote_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_AcceptVote_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_AcceptVote_DOS =
{
    0U,
    P_AcceptVote_DOS_INNER,
    NULL
};

#define P_STATE_SecureVotingClientMachine_AcceptVote \
{ \
    "SecureVotingClientMachine.AcceptVote", \
    0U, \
    0U, \
    &P_EVENTSET_AcceptVote_DEFERS, \
    &P_EVENTSET_AcceptVote_TRANS, \
    &P_EVENTSET_AcceptVote_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_18, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_SubmitVote_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SubmitVote_DEFERS =
{
    0U,
    P_SubmitVote_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_SubmitVote_TRANS_INNER[] = { &P_EVENT_TRUSTEDeRespConfirmVote };
PRT_EVENTSETDECL P_EVENTSET_SubmitVote_TRANS =
{
    1U,
    P_SubmitVote_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_SubmitVote_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SubmitVote_DOS =
{
    0U,
    P_SubmitVote_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_4[] =
{
    { 3, &P_EVENT_TRUSTEDeRespConfirmVote, 4, &P_FUNCTION_Anon_20 }
};

#define P_STATE_SecureVotingClientMachine_SubmitVote \
{ \
    "SecureVotingClientMachine.SubmitVote", \
    1U, \
    0U, \
    &P_EVENTSET_SubmitVote_DEFERS, \
    &P_EVENTSET_SubmitVote_TRANS, \
    &P_EVENTSET_SubmitVote_DOS, \
    P_TRANS_4, \
    NULL, \
    &P_FUNCTION_Anon_19, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_ValidateResults_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ValidateResults_DEFERS =
{
    0U,
    P_ValidateResults_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_ValidateResults_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ValidateResults_TRANS =
{
    0U,
    P_ValidateResults_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_ValidateResults_DOS_INNER[] = { &P_EVENT_TRUSTEDeRespElectionResults };
PRT_EVENTSETDECL P_EVENTSET_ValidateResults_DOS =
{
    1U,
    P_ValidateResults_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_5[] =
{
    { 4, &P_EVENT_TRUSTEDeRespElectionResults, &P_FUNCTION_Anon_22 }
};

#define P_STATE_SecureVotingClientMachine_ValidateResults \
{ \
    "SecureVotingClientMachine.ValidateResults", \
    0U, \
    1U, \
    &P_EVENTSET_ValidateResults_DEFERS, \
    &P_EVENTSET_ValidateResults_TRANS, \
    &P_EVENTSET_ValidateResults_DOS, \
    NULL, \
    P_DOS_5, \
    &P_FUNCTION_Anon_21, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Done_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DEFERS_1 =
{
    0U,
    P_Done_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Done_TRANS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_TRANS_1 =
{
    0U,
    P_Done_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Done_DOS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DOS_1 =
{
    0U,
    P_Done_DOS_INNER_1,
    NULL
};

#define P_STATE_SecureVotingClientMachine_Done \
{ \
    "SecureVotingClientMachine.Done", \
    0U, \
    0U, \
    &P_EVENTSET_Done_DEFERS_1, \
    &P_EVENTSET_Done_TRANS_1, \
    &P_EVENTSET_Done_DOS_1, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_23, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureVotingClientMachine_STATES[] = { P_STATE_SecureVotingClientMachine_Init, P_STATE_SecureVotingClientMachine_WaitForVote, P_STATE_SecureVotingClientMachine_AcceptVote, P_STATE_SecureVotingClientMachine_SubmitVote, P_STATE_SecureVotingClientMachine_ValidateResults, P_STATE_SecureVotingClientMachine_Done };

PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_13 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_15 = NULL;
    PRT_VALUE* PTMP_tmp1_14 = NULL;
    PRT_VALUE* PTMP_tmp2_12 = NULL;
    PRT_VALUE* PTMP_tmp3_11 = NULL;
    PRT_VALUE* PTMP_tmp4_11 = NULL;
    PRT_VALUE* PTMP_tmp5_11 = NULL;
    PRT_VALUE* PTMP_tmp6_10 = NULL;
    PRT_VALUE* PTMP_tmp7_8 = NULL;
    PRT_VALUE* PTMP_tmp8_7 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_185 = &(PTMP_tmp0_15);
    PrtFreeValue(*P_LVALUE_185);
    *P_LVALUE_185 = PrtTupleGet(*P_VAR_payload_13, 2);
    
    PRT_VALUE** P_LVALUE_186 = &(PTMP_tmp1_14);
    PrtFreeValue(*P_LVALUE_186);
    *P_LVALUE_186 = PrtTupleGet(*P_VAR_payload_13, 3);
    
    PRT_VALUE** P_LVALUE_187 = &(PTMP_tmp2_12);
    PrtFreeValue(*P_LVALUE_187);
    *P_LVALUE_187 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp0_15) + PrtPrimGetInt(PTMP_tmp1_14));
    
    {
        PRT_VALUE** P_LVALUE_188 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_188);
        *P_LVALUE_188 = PTMP_tmp2_12;
        PTMP_tmp2_12 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_189 = &(PTMP_tmp3_11);
    PrtFreeValue(*P_LVALUE_189);
    *P_LVALUE_189 = PrtTupleGet(*P_VAR_payload_13, 2);
    
    {
        PRT_VALUE** P_LVALUE_190 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_190);
        *P_LVALUE_190 = PTMP_tmp3_11;
        PTMP_tmp3_11 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_191 = &(PTMP_tmp4_11);
    PrtFreeValue(*P_LVALUE_191);
    *P_LVALUE_191 = PrtTupleGet(*P_VAR_payload_13, 3);
    
    {
        PRT_VALUE** P_LVALUE_192 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_192);
        *P_LVALUE_192 = PTMP_tmp4_11;
        PTMP_tmp4_11 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_193 = &(PTMP_tmp5_11);
    PrtFreeValue(*P_LVALUE_193);
    *P_LVALUE_193 = PrtTupleGet(*P_VAR_payload_13, 0);
    
    {
        PRT_VALUE** P_LVALUE_194 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_194);
        *P_LVALUE_194 = PTMP_tmp5_11;
        PTMP_tmp5_11 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_195 = &(PTMP_tmp6_10);
    PrtFreeValue(*P_LVALUE_195);
    *P_LVALUE_195 = PrtTupleGet(*P_VAR_payload_13, 1);
    
    {
        PRT_VALUE** P_LVALUE_196 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_196);
        *P_LVALUE_196 = PTMP_tmp6_10;
        PTMP_tmp6_10 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_197 = &(PTMP_tmp7_8);
    PrtFreeValue(*P_LVALUE_197);
    *P_LVALUE_197 = PrtTupleGet(*P_VAR_payload_13, 4);
    
    _P_GEN_funargs[0] = &(PTMP_tmp7_8);
    PrtFreeValue(P_SaveCapability_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp7_8);
    PTMP_tmp7_8 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_19;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_19;
    }
    
    PRT_VALUE** P_LVALUE_198 = &(PTMP_tmp8_7);
    PrtFreeValue(*P_LVALUE_198);
    *P_LVALUE_198 = PrtTupleGet(*P_VAR_payload_13, 5);
    
    _P_GEN_funargs[0] = &(PTMP_tmp8_7);
    PrtFreeValue(P_SaveCapability_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp8_7);
    PTMP_tmp8_7 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_19;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_19;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_19: ;
    PrtFreeValue(PTMP_tmp0_15); PTMP_tmp0_15 = NULL;
    PrtFreeValue(PTMP_tmp1_14); PTMP_tmp1_14 = NULL;
    PrtFreeValue(PTMP_tmp2_12); PTMP_tmp2_12 = NULL;
    PrtFreeValue(PTMP_tmp3_11); PTMP_tmp3_11 = NULL;
    PrtFreeValue(PTMP_tmp4_11); PTMP_tmp4_11 = NULL;
    PrtFreeValue(PTMP_tmp5_11); PTMP_tmp5_11 = NULL;
    PrtFreeValue(PTMP_tmp6_10); PTMP_tmp6_10 = NULL;
    PrtFreeValue(PTMP_tmp7_8); PTMP_tmp7_8 = NULL;
    PrtFreeValue(PTMP_tmp8_7); PTMP_tmp8_7 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_17 =
{
    NULL,
    &P_Anon_IMPL_17,
    &P_GEND_TYPE_T6machine_handlemachine_handleiicapabilitycapability
};


PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_14 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_16 = NULL;
    PRT_VALUE* PTMP_tmp1_15 = NULL;
    PRT_VALUE* PTMP_tmp2_13 = NULL;
    PRT_VALUE* PTMP_tmp3_12 = NULL;
    PRT_VALUE* PTMP_tmp4_12 = NULL;
    PRT_VALUE* PTMP_tmp5_12 = NULL;
    PRT_VALUE* PTMP_tmp6_11 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_199 = &(PTMP_tmp0_16);
    PrtFreeValue(*P_LVALUE_199);
    *P_LVALUE_199 = PrtTupleGet(*P_VAR_payload_14, 0);
    
    PRT_VALUE** P_LVALUE_200 = &(PTMP_tmp1_15);
    PrtFreeValue(*P_LVALUE_200);
    *P_LVALUE_200 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp0_16, p_this->varValues[3]));
    
    PRT_VALUE** P_LVALUE_201 = &(PTMP_tmp4_12);
    PrtFreeValue(*P_LVALUE_201);
    *P_LVALUE_201 = PrtCloneValue(PTMP_tmp1_15);
    
    if (PrtPrimGetBool(PTMP_tmp4_12))
    {
        PRT_VALUE** P_LVALUE_202 = &(PTMP_tmp2_13);
        PrtFreeValue(*P_LVALUE_202);
        *P_LVALUE_202 = PrtTupleGet(*P_VAR_payload_14, 1);
        
        PRT_VALUE** P_LVALUE_203 = &(PTMP_tmp3_12);
        PrtFreeValue(*P_LVALUE_203);
        *P_LVALUE_203 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp2_13, p_this->varValues[4]));
        
        PRT_VALUE** P_LVALUE_204 = &(PTMP_tmp4_12);
        PrtFreeValue(*P_LVALUE_204);
        *P_LVALUE_204 = PrtCloneValue(PTMP_tmp3_12);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp4_12))
    {
        PRT_VALUE** P_LVALUE_205 = &(PTMP_tmp5_12);
        PrtFreeValue(*P_LVALUE_205);
        *P_LVALUE_205 = PrtTupleGet(*P_VAR_payload_14, 2);
        
        PRT_VALUE** P_LVALUE_206 = &(PTMP_tmp6_11);
        PrtFreeValue(*P_LVALUE_206);
        *P_LVALUE_206 = PrtCloneValue(PTMP_tmp5_12);
        
        PrtGoto(p_this, 3U, 1, &(PTMP_tmp6_11));
        
    }
    
    else
    {
        PrtGoto(p_this, 1U, 0);
        
    }
    
    
p_return_20: ;
    PrtFreeValue(PTMP_tmp0_16); PTMP_tmp0_16 = NULL;
    PrtFreeValue(PTMP_tmp1_15); PTMP_tmp1_15 = NULL;
    PrtFreeValue(PTMP_tmp2_13); PTMP_tmp2_13 = NULL;
    PrtFreeValue(PTMP_tmp3_12); PTMP_tmp3_12 = NULL;
    PrtFreeValue(PTMP_tmp4_12); PTMP_tmp4_12 = NULL;
    PrtFreeValue(PTMP_tmp5_12); PTMP_tmp5_12 = NULL;
    PrtFreeValue(PTMP_tmp6_11); PTMP_tmp6_11 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_18 =
{
    NULL,
    &P_Anon_IMPL_18,
    &P_GEND_TYPE_T3iii
};


PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_vote = argRefs[0];
    PRT_VALUE* PTMP_tmp0_17 = NULL;
    PRT_VALUE* PTMP_tmp1_16 = NULL;
    PRT_VALUE* PTMP_tmp2_14 = NULL;
    PRT_VALUE* PTMP_tmp3_13 = NULL;
    PRT_VALUE* PTMP_tmp4_13 = NULL;
    PRT_VALUE* PTMP_tmp5_13 = NULL;
    PRT_VALUE* PTMP_tmp6_12 = NULL;
    PRT_VALUE* PTMP_tmp7_9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_23 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_207 = &(PTMP_tmp0_17);
    PrtFreeValue(*P_LVALUE_207);
    *P_LVALUE_207 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_208 = &(PTMP_tmp1_16);
    PrtFreeValue(*P_LVALUE_208);
    *P_LVALUE_208 = PrtCloneValue((&P_EVENT_TRUSTEDeVote.value));
    
    PRT_VALUE** P_LVALUE_209 = &(PTMP_tmp2_14);
    PrtFreeValue(*P_LVALUE_209);
    *P_LVALUE_209 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_210 = &(PTMP_tmp3_13);
    PrtFreeValue(*P_LVALUE_210);
    *P_LVALUE_210 = PrtCloneValue(*P_VAR_vote);
    
    PRT_VALUE** P_LVALUE_211 = &(PTMP_tmp4_13);
    PrtFreeValue(*P_LVALUE_211);
    *P_LVALUE_211 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_21;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_21;
    }
    
    PRT_VALUE** P_LVALUE_212 = &(PTMP_tmp5_13);
    PrtFreeValue(*P_LVALUE_212);
    *P_LVALUE_212 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_21;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_21;
    }
    
    PRT_VALUE** P_LVALUE_213 = &(PTMP_tmp6_12);
    PrtFreeValue(*P_LVALUE_213);
    *P_LVALUE_213 = ((_P_GEN_funargs[0] = &(PTMP_tmp5_13)), (_P_GEN_funval = P_GetCapability_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp5_13), PTMP_tmp5_13 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_21;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_21;
    }
    
    PRT_VALUE** P_LVALUE_214 = &(PTMP_tmp7_9);
    PrtFreeValue(*P_LVALUE_214);
    *P_LVALUE_214 = (PrtMkTuple(&P_GEND_TYPE_T4iimachine_handlecapability, &(PTMP_tmp2_14), &(PTMP_tmp3_13), &(PTMP_tmp4_13), &(PTMP_tmp6_12)));
    
    PRT_VALUE* P_PTMP_tmp_12 = PrtCloneValue(&(P_LIT_INT32_23));
    _P_GEN_funargs[0] = &(PTMP_tmp0_17);
    _P_GEN_funargs[1] = &(PTMP_tmp1_16);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_12);
    _P_GEN_funargs[3] = &(PTMP_tmp7_9);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_21;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_21;
    }
    
p_return_21: ;
    PrtFreeValue(PTMP_tmp0_17); PTMP_tmp0_17 = NULL;
    PrtFreeValue(PTMP_tmp1_16); PTMP_tmp1_16 = NULL;
    PrtFreeValue(PTMP_tmp2_14); PTMP_tmp2_14 = NULL;
    PrtFreeValue(PTMP_tmp3_13); PTMP_tmp3_13 = NULL;
    PrtFreeValue(PTMP_tmp4_13); PTMP_tmp4_13 = NULL;
    PrtFreeValue(PTMP_tmp5_13); PTMP_tmp5_13 = NULL;
    PrtFreeValue(PTMP_tmp6_12); PTMP_tmp6_12 = NULL;
    PrtFreeValue(PTMP_tmp7_9); PTMP_tmp7_9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_19 =
{
    NULL,
    &P_Anon_IMPL_19,
    &P_GEND_TYPE_i
};


PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("Vote successfully submitted to the ballot box");
    
p_return_22: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_20 =
{
    NULL,
    &P_Anon_IMPL_20,
    NULL
};


PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_18 = NULL;
    PRT_VALUE* PTMP_tmp1_17 = NULL;
    PRT_VALUE* PTMP_tmp2_15 = NULL;
    PRT_VALUE* PTMP_tmp3_14 = NULL;
    PRT_VALUE* PTMP_tmp4_14 = NULL;
    PRT_VALUE* PTMP_tmp5_14 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_24 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_215 = &(PTMP_tmp0_18);
    PrtFreeValue(*P_LVALUE_215);
    *P_LVALUE_215 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_216 = &(PTMP_tmp1_17);
    PrtFreeValue(*P_LVALUE_216);
    *P_LVALUE_216 = PrtCloneValue((&P_EVENT_TRUSTEDeGetElectionResults.value));
    
    PRT_VALUE** P_LVALUE_217 = &(PTMP_tmp2_15);
    PrtFreeValue(*P_LVALUE_217);
    *P_LVALUE_217 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_23;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_23;
    }
    
    PRT_VALUE** P_LVALUE_218 = &(PTMP_tmp3_14);
    PrtFreeValue(*P_LVALUE_218);
    *P_LVALUE_218 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_23;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_23;
    }
    
    PRT_VALUE** P_LVALUE_219 = &(PTMP_tmp4_14);
    PrtFreeValue(*P_LVALUE_219);
    *P_LVALUE_219 = ((_P_GEN_funargs[0] = &(PTMP_tmp3_14)), (_P_GEN_funval = P_GetCapability_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp3_14), PTMP_tmp3_14 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_23;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_23;
    }
    
    PRT_VALUE** P_LVALUE_220 = &(PTMP_tmp5_14);
    PrtFreeValue(*P_LVALUE_220);
    *P_LVALUE_220 = (PrtMkTuple(&P_GEND_TYPE_T2machine_handlecapability, &(PTMP_tmp2_15), &(PTMP_tmp4_14)));
    
    PRT_VALUE* P_PTMP_tmp_13 = PrtCloneValue(&(P_LIT_INT32_24));
    _P_GEN_funargs[0] = &(PTMP_tmp0_18);
    _P_GEN_funargs[1] = &(PTMP_tmp1_17);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_13);
    _P_GEN_funargs[3] = &(PTMP_tmp5_14);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_23;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_23;
    }
    
p_return_23: ;
    PrtFreeValue(PTMP_tmp0_18); PTMP_tmp0_18 = NULL;
    PrtFreeValue(PTMP_tmp1_17); PTMP_tmp1_17 = NULL;
    PrtFreeValue(PTMP_tmp2_15); PTMP_tmp2_15 = NULL;
    PrtFreeValue(PTMP_tmp3_14); PTMP_tmp3_14 = NULL;
    PrtFreeValue(PTMP_tmp4_14); PTMP_tmp4_14 = NULL;
    PrtFreeValue(PTMP_tmp5_14); PTMP_tmp5_14 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_21 =
{
    NULL,
    &P_Anon_IMPL_21,
    NULL
};


PRT_VALUE* P_Anon_IMPL_22(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_15 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_19 = NULL;
    PRT_VALUE* PTMP_tmp1_18 = NULL;
    PRT_VALUE* PTMP_tmp2_16 = NULL;
    PRT_VALUE* PTMP_tmp3_15 = NULL;
    PRT_VALUE* PTMP_tmp4_15 = NULL;
    PRT_VALUE* PTMP_tmp5_15 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_221 = &(PTMP_tmp0_19);
    PrtFreeValue(*P_LVALUE_221);
    *P_LVALUE_221 = PrtTupleGet(*P_VAR_payload_15, 0);
    
    PRT_VALUE** P_LVALUE_222 = &(PTMP_tmp1_18);
    PrtFreeValue(*P_LVALUE_222);
    *P_LVALUE_222 = PrtMkBoolValue(PrtMapExists(PTMP_tmp0_19, p_this->varValues[0]));;
    
    PRT_VALUE** P_LVALUE_223 = &(PTMP_tmp2_16);
    PrtFreeValue(*P_LVALUE_223);
    *P_LVALUE_223 = PrtMkBoolValue(!PrtPrimGetBool(PTMP_tmp1_18));
    
    if (PrtPrimGetBool(PTMP_tmp2_16))
    {
        PrtPrintf("ERROR");
        
        PrtPrintf("My vote not found!!");
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_224 = &(PTMP_tmp3_15);
        PrtFreeValue(*P_LVALUE_224);
        *P_LVALUE_224 = PrtTupleGet(*P_VAR_payload_15, 0);
        
        PRT_VALUE** P_LVALUE_225 = &(PTMP_tmp4_15);
        PrtFreeValue(*P_LVALUE_225);
        *P_LVALUE_225 = PrtMapGet(PTMP_tmp3_15, p_this->varValues[0]);
        
        PrtFormatPrintf("Your vote for ", 1, PTMP_tmp4_15, 1, 0, " was counted");
        
    }
    
    
    PRT_VALUE** P_LVALUE_226 = &(PTMP_tmp5_15);
    PrtFreeValue(*P_LVALUE_226);
    *P_LVALUE_226 = PrtTupleGet(*P_VAR_payload_15, 1);
    
    PrtFormatPrintf("", 1, PTMP_tmp5_15, 1, 0, " won the election");
    
    PrtGoto(p_this, 5U, 0);
    
p_return_24: ;
    PrtFreeValue(PTMP_tmp0_19); PTMP_tmp0_19 = NULL;
    PrtFreeValue(PTMP_tmp1_18); PTMP_tmp1_18 = NULL;
    PrtFreeValue(PTMP_tmp2_16); PTMP_tmp2_16 = NULL;
    PrtFreeValue(PTMP_tmp3_15); PTMP_tmp3_15 = NULL;
    PrtFreeValue(PTMP_tmp4_15); PTMP_tmp4_15 = NULL;
    PrtFreeValue(PTMP_tmp5_15); PTMP_tmp5_15 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_22 =
{
    NULL,
    &P_Anon_IMPL_22,
    &P_GEND_TYPE_T2MKiVii
};


PRT_VALUE* P_Anon_IMPL_23(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_20 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("Operation successfully performed, closing client safely");
    
    PRT_VALUE** P_LVALUE_227 = &(PTMP_tmp0_20);
    PrtFreeValue(*P_LVALUE_227);
    *P_LVALUE_227 = PrtCloneValue((&_P_EVENT_HALT_STRUCT.value));
    
    PrtRaise(p_this, PTMP_tmp0_20, 0);
    *(&(PTMP_tmp0_20)) = NULL;
    goto p_return_25;
    
p_return_25: ;
    PrtFreeValue(PTMP_tmp0_20); PTMP_tmp0_20 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_23 =
{
    NULL,
    &P_Anon_IMPL_23,
    NULL
};


PRT_FUNDECL* P_SecureVotingClientMachine_METHODS[] = { &P_FUNCTION_Anon_17, &P_FUNCTION_Anon_18, &P_FUNCTION_Anon_19, &P_FUNCTION_Anon_20, &P_FUNCTION_Anon_21, &P_FUNCTION_Anon_22, &P_FUNCTION_Anon_23 };

PRT_EVENTDECL* P_SecureVotingClientMachine_RECV_INNER_1[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureVotingClientMachine_RECV_1 =
{
    17U,
    P_SecureVotingClientMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureVotingClientMachine_SEND_INNER[] = { &P_EVENT_StrEvent, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeGetElectionResults, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_eCloseElection, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureVotingClientMachine_SEND =
{
    17U,
    P_SecureVotingClientMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_SecureVotingClientMachine = 
{
    7U,
    "SecureVotingClientMachine",
    &P_EVENTSET_SecureVotingClientMachine_RECV_1,
    &P_EVENTSET_SecureVotingClientMachine_SEND,
    NULL,
    5U,
    6U,
    7U,
    4294967295U,
    0U,
    P_SecureVotingClientMachine_VARS,
    P_SecureVotingClientMachine_STATES,
    P_SecureVotingClientMachine_METHODS,
    PRT_TRUE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_TYPE* P_TYPEDEF_machine_handle = &P_GEND_TYPE_machine_handle;
PRT_TYPE* P_TYPEDEF_capability = &P_GEND_TYPE_capability;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_TRUSTEDeRespAddItem, &P_EVENT_TRUSTEDeRespGetLog, &P_EVENT_UNTRUSTEDGetVotingSSM, &P_EVENT_StrEvent, &P_EVENT_UNTRUSTEDReceiveVotingSSM, &P_EVENT_UNTRUSTEDVoteRequest, &P_EVENT_TRUSTEDeStartElection, &P_EVENT_TRUSTEDeVote, &P_EVENT_TRUSTEDeAddItem, &P_EVENT_TRUSTEDeRespConfirmVote, &P_EVENT_eCloseElection, &P_EVENT_TRUSTEDeGetLog, &P_EVENT_TRUSTEDeAllVotes, &P_EVENT_TRUSTEDeElectionResults, &P_EVENT_TRUSTEDeRespElectionResults, &P_EVENT_TRUSTEDeGetElectionResults };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_InitializerMachine, &P_MACHINE_SecureSupervisorMachine, &P_MACHINE_VotingUSM, &P_MACHINE_SecureBulletinBoardMachine, &P_MACHINE_SecureBallotBoxMachine, &P_MACHINE_SecureTamperEvidentLogMachine, &P_MACHINE_SecureTabulationTellerMachine, &P_MACHINE_SecureVotingClientMachine };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_InitializerMachine, &P_I_SecureSupervisorMachine, &P_I_VotingUSM, &P_I_SecureBulletinBoardMachine, &P_I_SecureBallotBoxMachine, &P_I_SecureTamperEvidentLogMachine, &P_I_SecureTabulationTellerMachine, &P_I_SecureVotingClientMachine };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_machine_handle, &P_StringType, &P_capability };
int P_DefaultImpl_LME_0[] = { -1,1,2,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,-1,3,4,-1,-1,7 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_3[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_4[] = { -1,-1,-1,-1,-1,5,6,-1 };
int P_DefaultImpl_LME_5[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_6[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_7[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3, P_DefaultImpl_LME_4, P_DefaultImpl_LME_5, P_DefaultImpl_LME_6, P_DefaultImpl_LME_7 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3,4,5,6,7 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    18U,
    8U,
    8U,
    0U,
    3U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};

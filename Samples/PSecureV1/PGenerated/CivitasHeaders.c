#include "CivitasHeaders.h"

// Type universe for program:
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
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_MKiVi = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_StringType, &P_GEND_TYPE_StringType };
static PRT_TUPTYPE P_TUP = { 2U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T2StringTypeStringType = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE* P_TUP_T_1[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_i };
static PRT_TUPTYPE P_TUP_1 = { 2U, P_TUP_T_1 };
static PRT_TYPE P_GEND_TYPE_T2machine_handlei = { PRT_KIND_TUPLE, { .tuple = &P_TUP_1 } };
static PRT_TYPE* P_TUP_T_2[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TUPTYPE P_TUP_2 = { 4U, P_TUP_T_2 };
static PRT_TYPE P_GEND_TYPE_T4machine_handlemachine_handleii = { PRT_KIND_TUPLE, { .tuple = &P_TUP_2 } };
static PRT_TYPE* P_TUP_T_3[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TUPTYPE P_TUP_3 = { 2U, P_TUP_T_3 };
static PRT_TYPE P_GEND_TYPE_T2ii = { PRT_KIND_TUPLE, { .tuple = &P_TUP_3 } };
static PRT_SEQTYPE P_SEQTYPE = { &P_GEND_TYPE_T2ii };
static PRT_TYPE P_GEND_TYPE_ST2ii = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE } };
static PRT_SEQTYPE P_SEQTYPE_1 = { &P_GEND_TYPE_machine_handle };
static PRT_TYPE P_GEND_TYPE_Smachine_handle = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_1 } };
static PRT_TYPE P_GEND_TYPE_i_1 = { PRT_KIND_INT, { NULL } };

// Function implementation prototypes:
PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Concat_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Hash_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GenerateRandomMasterSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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


PRT_EVENTDECL P_EVENT_BankPublicIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "BankPublicIDEvent",
    4294967295U,
    &P_GEND_TYPE_machine_handle
};

PRT_EVENTDECL P_EVENT_PublicIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "PublicIDEvent",
    4294967295U,
    &P_GEND_TYPE_machine_handle
};

PRT_EVENTDECL P_EVENT_MasterSecretEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MasterSecretEvent",
    4294967295U,
    &P_GEND_TYPE_StringType
};

PRT_EVENTDECL P_EVENT_GenerateOTPCodeEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "GenerateOTPCodeEvent",
    4294967295U,
    &P_GEND_TYPE_StringType
};

PRT_EVENTDECL P_EVENT_OTPCodeEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "OTPCodeEvent",
    4294967295U,
    &P_GEND_TYPE_StringType
};

PRT_EVENTDECL P_EVENT_MapEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MapEvent",
    4294967295U,
    &P_GEND_TYPE_MKiVi
};

PRT_EVENTDECL P_EVENT_AuthenticateRequest = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "AuthenticateRequest",
    4294967295U,
    &P_GEND_TYPE_T2StringTypeStringType
};

PRT_EVENTDECL P_EVENT_AuthSuccess = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "AuthSuccess",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_AuthFailure = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "AuthFailure",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_UNTRUSTEDGetVotingSSM = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDGetVotingSSM",
    4294967295U,
    &P_GEND_TYPE_T2machine_handlei
};

PRT_FUNDECL P_FUNCTION_CreateMachineSecureChild =
{
    "CreateMachineSecureChild",
    &P_CreateMachineSecureChild_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_PrintString =
{
    "PrintString",
    &P_PrintString_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_SecureSend =
{
    "SecureSend",
    &P_SecureSend_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetThis =
{
    "GetThis",
    &P_GetThis_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_Concat =
{
    "Concat",
    &P_Concat_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_Hash =
{
    "Hash",
    &P_Hash_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_UntrustedCreateCoordinator =
{
    "UntrustedCreateCoordinator",
    &P_UntrustedCreateCoordinator_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_UntrustedSend =
{
    "UntrustedSend",
    &P_UntrustedSend_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_InitializeUntrustedMachine =
{
    "InitializeUntrustedMachine",
    &P_InitializeUntrustedMachine_IMPL,
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


PRT_FUNDECL P_FUNCTION_PrintKey =
{
    "PrintKey",
    &P_PrintKey_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GenerateRandomMasterSecret =
{
    "GenerateRandomMasterSecret",
    &P_GenerateRandomMasterSecret_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetUserInput =
{
    "GetUserInput",
    &P_GetUserInput_IMPL,
    NULL
};


PRT_EVENTDECL* P_InitializerMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_InitializerMachine_RECV =
{
    11U,
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

PRT_EVENTDECL* P_SecureSupervisorMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSupervisorMachine_RECV =
{
    11U,
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

PRT_EVENTDECL* P_VotingUSM_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VotingUSM_RECV =
{
    11U,
    P_VotingUSM_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_VotingUSM =
{
    2U,
    "VotingUSM",
    &P_GEND_TYPE_machine_handle,
    &P_EVENTSET_VotingUSM_RECV
};

PRT_EVENTDECL* P_SecureBulletinBoardMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBulletinBoardMachine_RECV =
{
    11U,
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

PRT_EVENTDECL* P_SecureBallotBoxMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBallotBoxMachine_RECV =
{
    11U,
    P_SecureBallotBoxMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureBallotBoxMachine =
{
    4U,
    "SecureBallotBoxMachine",
    &P_GEND_TYPE_machine_handle,
    &P_EVENTSET_SecureBallotBoxMachine_RECV
};

PRT_EVENTDECL* P_SecureTamperEvidentLogMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTamperEvidentLogMachine_RECV =
{
    11U,
    P_SecureTamperEvidentLogMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureTamperEvidentLogMachine =
{
    5U,
    "SecureTamperEvidentLogMachine",
    &P_GEND_TYPE_machine_handle,
    &P_EVENTSET_SecureTamperEvidentLogMachine_RECV
};

PRT_EVENTDECL* P_SecureTabulationTellerMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTabulationTellerMachine_RECV =
{
    11U,
    P_SecureTabulationTellerMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureTabulationTellerMachine =
{
    6U,
    "SecureTabulationTellerMachine",
    &P_GEND_TYPE_machine_handle,
    &P_EVENTSET_SecureTabulationTellerMachine_RECV
};

PRT_EVENTDECL* P_SecureVotingClientMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureVotingClientMachine_RECV =
{
    11U,
    P_SecureVotingClientMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureVotingClientMachine =
{
    7U,
    "SecureVotingClientMachine",
    &P_GEND_TYPE_T4machine_handlemachine_handleii,
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
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
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
    
    _P_GEN_funargs[0] = "VotingUSM";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp1);
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_4 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_4);
        *P_LVALUE_4 = PTMP_tmp2;
        PTMP_tmp2 = NULL;
    }
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL
};


PRT_FUNDECL* P_InitializerMachine_METHODS[] = { &P_FUNCTION_Anon };

PRT_EVENTDECL* P_InitializerMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_InitializerMachine_RECV_1 =
{
    11U,
    P_InitializerMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_InitializerMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_InitializerMachine_SEND =
{
    11U,
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
    { "username_passwords", &P_GEND_TYPE_ST2ii },
    { "votingClients", &P_GEND_TYPE_Smachine_handle },
    { "numRequestsFulfilled", &P_GEND_TYPE_i },
    { "temp", &P_GEND_TYPE_i },
    { "i", &P_GEND_TYPE_i },
    { "tempMachineHandle", &P_GEND_TYPE_machine_handle },
    { "requestingMachineHandle", &P_GEND_TYPE_machine_handle },
    { "username", &P_GEND_TYPE_i }
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
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
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
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    _P_GEN_funargs[0] = "SecureBulletinBoardMachine";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_6 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_6);
        *P_LVALUE_6 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtCloneValue(p_this->varValues[0]);
    
    _P_GEN_funargs[0] = "SecureBallotBoxMachine";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp1_1);
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_9 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_9);
        *P_LVALUE_9 = PTMP_tmp2_1;
        PTMP_tmp2_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue((&P_LIT_INT32));
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue((&P_LIT_INT32));
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = (PrtMkTuple(&P_GEND_TYPE_T2ii, &(PTMP_tmp3), &(PTMP_tmp4)));
    
    PrtSeqInsertEx(p_this->varValues[3], (&P_LIT_INT32_1), PTMP_tmp5, PRT_FALSE);
    *(&(PTMP_tmp5)) = NULL;
    
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue((&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtCloneValue((&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = (PrtMkTuple(&P_GEND_TYPE_T2ii, &(PTMP_tmp6), &(PTMP_tmp7)));
    
    PrtSeqInsertEx(p_this->varValues[3], (&P_LIT_INT32_1), PTMP_tmp8, PRT_FALSE);
    *(&(PTMP_tmp8)) = NULL;
    
    PRT_VALUE** P_LVALUE_16 = &(p_this->varValues[7]);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtCloneValue((&P_LIT_INT32_1));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp9);
        PrtFreeValue(*P_LVALUE_17);
        *P_LVALUE_17 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[3]));
        
        PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp10);
        PrtFreeValue(*P_LVALUE_18);
        *P_LVALUE_18 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[7]) < PrtPrimGetInt(PTMP_tmp9));
        
        PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp11);
        PrtFreeValue(*P_LVALUE_19);
        *P_LVALUE_19 = PrtCloneValue(PTMP_tmp10);
        
        if (PrtPrimGetBool(PTMP_tmp11))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp12);
        PrtFreeValue(*P_LVALUE_20);
        *P_LVALUE_20 = PrtSeqGet(p_this->varValues[3], p_this->varValues[7]);
        
        PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp13);
        PrtFreeValue(*P_LVALUE_21);
        *P_LVALUE_21 = PrtTupleGet(PTMP_tmp12, 0);
        
        {
            PRT_VALUE** P_LVALUE_22 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_22);
            *P_LVALUE_22 = PTMP_tmp13;
            PTMP_tmp13 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp14);
        PrtFreeValue(*P_LVALUE_23);
        *P_LVALUE_23 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp15);
        PrtFreeValue(*P_LVALUE_24);
        *P_LVALUE_24 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp16);
        PrtFreeValue(*P_LVALUE_25);
        *P_LVALUE_25 = PrtSeqGet(p_this->varValues[3], p_this->varValues[7]);
        
        PRT_VALUE** P_LVALUE_26 = &(PTMP_tmp17);
        PrtFreeValue(*P_LVALUE_26);
        *P_LVALUE_26 = PrtTupleGet(PTMP_tmp16, 0);
        
        PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp18);
        PrtFreeValue(*P_LVALUE_27);
        *P_LVALUE_27 = PrtSeqGet(p_this->varValues[3], p_this->varValues[7]);
        
        PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp19);
        PrtFreeValue(*P_LVALUE_28);
        *P_LVALUE_28 = PrtTupleGet(PTMP_tmp18, 1);
        
        PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp20);
        PrtFreeValue(*P_LVALUE_29);
        *P_LVALUE_29 = (PrtMkTuple(&P_GEND_TYPE_T4machine_handlemachine_handleii, &(PTMP_tmp14), &(PTMP_tmp15), &(PTMP_tmp17), &(PTMP_tmp19)));
        
        _P_GEN_funargs[0] = "SecureVotingClientMachine";
        _P_GEN_funargs[1] = "1";
        _P_GEN_funargs[2] = &(PTMP_tmp20);
        PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp21);
        PrtFreeValue(*P_LVALUE_30);
        *P_LVALUE_30 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_1;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_1;
        }
        
        {
            PRT_VALUE** P_LVALUE_31 = &(p_this->varValues[8]);
            PrtFreeValue(*P_LVALUE_31);
            *P_LVALUE_31 = PTMP_tmp21;
            PTMP_tmp21 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp22);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PrtCloneValue(p_this->varValues[8]);
        
        PrtSeqInsertEx(p_this->varValues[4], (&P_LIT_INT32_1), PTMP_tmp22, PRT_FALSE);
        *(&(PTMP_tmp22)) = NULL;
        
        PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp23);
        PrtFreeValue(*P_LVALUE_33);
        *P_LVALUE_33 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[7]) + PrtPrimGetInt((&P_LIT_INT32)));
        
        {
            PRT_VALUE** P_LVALUE_34 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_34);
            *P_LVALUE_34 = PTMP_tmp23;
            PTMP_tmp23 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_35 = &(p_this->varValues[5]);
    PrtFreeValue(*P_LVALUE_35);
    *P_LVALUE_35 = PrtCloneValue((&P_LIT_INT32_1));
    
    PrtGoto(p_this, 1U, 0);
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
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
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_36);
    *P_LVALUE_36 = PrtTupleGet(*P_VAR_payload, 0);
    
    {
        PRT_VALUE** P_LVALUE_37 = &(p_this->varValues[9]);
        PrtFreeValue(*P_LVALUE_37);
        *P_LVALUE_37 = PTMP_tmp0_2;
        PTMP_tmp0_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_38);
    *P_LVALUE_38 = PrtTupleGet(*P_VAR_payload, 1);
    
    {
        PRT_VALUE** P_LVALUE_39 = &(p_this->varValues[10]);
        PrtFreeValue(*P_LVALUE_39);
        *P_LVALUE_39 = PTMP_tmp1_2;
        PTMP_tmp1_2 = NULL;
    }
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_T2machine_handlei
};


PRT_FUNDECL* P_SecureSupervisorMachine_METHODS[] = { &P_FUNCTION_Anon_1, &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_SecureSupervisorMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSupervisorMachine_RECV_1 =
{
    11U,
    P_SecureSupervisorMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureSupervisorMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSupervisorMachine_SEND =
{
    11U,
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
    11U,
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
    { "password", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_2 =
{
    0U,
    P_Init_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_2 =
{
    0U,
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

#define P_STATE_VotingUSM_Init \
{ \
    "VotingUSM.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_2, \
    &P_EVENTSET_Init_TRANS_2, \
    &P_EVENTSET_Init_DOS_2, \
    NULL, \
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
    &_P_NO_OP, \
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
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_40 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = PrtCloneValue(*P_VAR_payload_1);
    
    PRT_VALUE** P_LVALUE_41 = &(p_this->varValues[2]);
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = PrtCloneValue((&P_LIT_INT32_3));
    
    PRT_VALUE** P_LVALUE_42 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_42);
    *P_LVALUE_42 = PrtCloneValue((&P_LIT_INT32_3));
    
    PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_43);
    *P_LVALUE_43 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_44 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_44);
    *P_LVALUE_44 = PrtCloneValue((&P_EVENT_UNTRUSTEDGetVotingSSM.value));
    
    PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_45);
    *P_LVALUE_45 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_46);
    *P_LVALUE_46 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_47);
    *P_LVALUE_47 = (PrtMkTuple(&P_GEND_TYPE_T2machine_handlei, &(PTMP_tmp2_2), &(PTMP_tmp3_1)));
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32_4));
    _P_GEN_funargs[0] = &(PTMP_tmp0_3);
    _P_GEN_funargs[1] = &(PTMP_tmp1_3);
    _P_GEN_funargs[2] = &(P_PTMP_tmp);
    _P_GEN_funargs[3] = &(PTMP_tmp4_1);
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
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_machine_handle
};


PRT_FUNDECL* P_VotingUSM_METHODS[] = { &P_FUNCTION_Anon_3 };

PRT_EVENTDECL* P_VotingUSM_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VotingUSM_RECV_1 =
{
    11U,
    P_VotingUSM_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_VotingUSM_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_VotingUSM_SEND =
{
    11U,
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
    4U,
    3U,
    1U,
    4294967295U,
    0U,
    P_VotingUSM_VARS,
    P_VotingUSM_STATES,
    P_VotingUSM_METHODS,
    PRT_FALSE
};

PRT_VARDECL P_SecureBulletinBoardMachine_VARS[] = {
    { "electionResults", &P_GEND_TYPE_MKiVi }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_3 =
{
    0U,
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

PRT_EVENTDECL* P_Init_DOS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_3 =
{
    0U,
    P_Init_DOS_INNER_3,
    NULL
};

#define P_STATE_SecureBulletinBoardMachine_Init \
{ \
    "SecureBulletinBoardMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_3, \
    &P_EVENTSET_Init_TRANS_3, \
    &P_EVENTSET_Init_DOS_3, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureBulletinBoardMachine_STATES[] = { P_STATE_SecureBulletinBoardMachine_Init };

PRT_EVENTDECL* P_SecureBulletinBoardMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBulletinBoardMachine_RECV_1 =
{
    11U,
    P_SecureBulletinBoardMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureBulletinBoardMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBulletinBoardMachine_SEND =
{
    11U,
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
    1U,
    1U,
    0U,
    4294967295U,
    0U,
    P_SecureBulletinBoardMachine_VARS,
    P_SecureBulletinBoardMachine_STATES,
    NULL,
    PRT_TRUE
};

PRT_VARDECL P_SecureBallotBoxMachine_VARS[] = {
    { "bulletinBoard", &P_GEND_TYPE_machine_handle },
    { "tabulationTeller", &P_GEND_TYPE_machine_handle },
    { "appendOnlyLog", &P_GEND_TYPE_machine_handle }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_4 =
{
    0U,
    P_Init_DEFERS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_4 =
{
    0U,
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

#define P_STATE_SecureBallotBoxMachine_Init \
{ \
    "SecureBallotBoxMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_4, \
    &P_EVENTSET_Init_TRANS_4, \
    &P_EVENTSET_Init_DOS_4, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureBallotBoxMachine_STATES[] = { P_STATE_SecureBallotBoxMachine_Init };

PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_bBoard = argRefs[0];
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_48 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_48);
    *P_LVALUE_48 = PrtCloneValue(*P_VAR_bBoard);
    
    PRT_VALUE** P_LVALUE_49 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_49);
    *P_LVALUE_49 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    _P_GEN_funargs[0] = "SecureTamperEvidentLogMachine";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp0_4);
    PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_50);
    *P_LVALUE_50 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_51 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_51);
        *P_LVALUE_51 = PTMP_tmp1_4;
        PTMP_tmp1_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = PrtCloneValue(p_this->varValues[0]);
    
    _P_GEN_funargs[0] = "SecureTabulationTellerMachine";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp2_3);
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_54 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_54);
        *P_LVALUE_54 = PTMP_tmp3_2;
        PTMP_tmp3_2 = NULL;
    }
    
p_return_4: ;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    &P_GEND_TYPE_machine_handle
};


PRT_FUNDECL* P_SecureBallotBoxMachine_METHODS[] = { &P_FUNCTION_Anon_4 };

PRT_EVENTDECL* P_SecureBallotBoxMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBallotBoxMachine_RECV_1 =
{
    11U,
    P_SecureBallotBoxMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureBallotBoxMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureBallotBoxMachine_SEND =
{
    11U,
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
    3U,
    1U,
    1U,
    4294967295U,
    0U,
    P_SecureBallotBoxMachine_VARS,
    P_SecureBallotBoxMachine_STATES,
    P_SecureBallotBoxMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_SecureTamperEvidentLogMachine_VARS[] = {
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
    &P_FUNCTION_Anon_5, \
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

PRT_EVENTDECL* P_WaitForRequests_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForRequests_DOS =
{
    0U,
    P_WaitForRequests_DOS_INNER,
    NULL
};

#define P_STATE_SecureTamperEvidentLogMachine_WaitForRequests \
{ \
    "SecureTamperEvidentLogMachine.WaitForRequests", \
    0U, \
    0U, \
    &P_EVENTSET_WaitForRequests_DEFERS, \
    &P_EVENTSET_WaitForRequests_TRANS, \
    &P_EVENTSET_WaitForRequests_DOS, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureTamperEvidentLogMachine_STATES[] = { P_STATE_SecureTamperEvidentLogMachine_Init, P_STATE_SecureTamperEvidentLogMachine_WaitForRequests };

PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_55 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtCloneValue(*P_VAR_payload_2);
    
    PrtGoto(p_this, 1U, 0);
    
p_return_5: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_machine_handle
};


PRT_FUNDECL* P_SecureTamperEvidentLogMachine_METHODS[] = { &P_FUNCTION_Anon_5 };

PRT_EVENTDECL* P_SecureTamperEvidentLogMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTamperEvidentLogMachine_RECV_1 =
{
    11U,
    P_SecureTamperEvidentLogMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureTamperEvidentLogMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTamperEvidentLogMachine_SEND =
{
    11U,
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
    1U,
    2U,
    1U,
    4294967295U,
    0U,
    P_SecureTamperEvidentLogMachine_VARS,
    P_SecureTamperEvidentLogMachine_STATES,
    P_SecureTamperEvidentLogMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_SecureTabulationTellerMachine_VARS[] = {
    { "bulletinBoard", &P_GEND_TYPE_machine_handle }
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

PRT_EVENTDECL* P_Init_DOS_INNER_6[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_6 =
{
    0U,
    P_Init_DOS_INNER_6,
    NULL
};

#define P_STATE_SecureTabulationTellerMachine_Init \
{ \
    "SecureTabulationTellerMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_6, \
    &P_EVENTSET_Init_TRANS_6, \
    &P_EVENTSET_Init_DOS_6, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_6, \
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
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureTabulationTellerMachine_STATES[] = { P_STATE_SecureTabulationTellerMachine_Init, P_STATE_SecureTabulationTellerMachine_DoTally };

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_bBoard_1 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_56 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = PrtCloneValue(*P_VAR_bBoard_1);
    
p_return_6: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    &P_GEND_TYPE_machine_handle
};


PRT_FUNDECL* P_SecureTabulationTellerMachine_METHODS[] = { &P_FUNCTION_Anon_6 };

PRT_EVENTDECL* P_SecureTabulationTellerMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTabulationTellerMachine_RECV_1 =
{
    11U,
    P_SecureTabulationTellerMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureTabulationTellerMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureTabulationTellerMachine_SEND =
{
    11U,
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
    1U,
    2U,
    1U,
    4294967295U,
    0U,
    P_SecureTabulationTellerMachine_VARS,
    P_SecureTabulationTellerMachine_STATES,
    P_SecureTabulationTellerMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_SecureVotingClientMachine_VARS[] = {
    { "credentials", &P_GEND_TYPE_i_1 },
    { "ballotBox", &P_GEND_TYPE_machine_handle },
    { "bulletinBoard", &P_GEND_TYPE_machine_handle },
    { "username", &P_GEND_TYPE_i_1 },
    { "password", &P_GEND_TYPE_i_1 }
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
    &P_FUNCTION_Anon_7, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureVotingClientMachine_STATES[] = { P_STATE_SecureVotingClientMachine_Init };

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_7: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_T4machine_handlemachine_handleii
};


PRT_FUNDECL* P_SecureVotingClientMachine_METHODS[] = { &P_FUNCTION_Anon_7 };

PRT_EVENTDECL* P_SecureVotingClientMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureVotingClientMachine_RECV_1 =
{
    11U,
    P_SecureVotingClientMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureVotingClientMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDGetVotingSSM, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureVotingClientMachine_SEND =
{
    11U,
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
    1U,
    1U,
    4294967295U,
    0U,
    P_SecureVotingClientMachine_VARS,
    P_SecureVotingClientMachine_STATES,
    P_SecureVotingClientMachine_METHODS,
    PRT_TRUE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_TYPE* P_TYPEDEF_machine_handle = &P_GEND_TYPE_machine_handle;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_BankPublicIDEvent, &P_EVENT_PublicIDEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_AuthenticateRequest, &P_EVENT_AuthSuccess, &P_EVENT_AuthFailure, &P_EVENT_UNTRUSTEDGetVotingSSM };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_InitializerMachine, &P_MACHINE_SecureSupervisorMachine, &P_MACHINE_VotingUSM, &P_MACHINE_SecureBulletinBoardMachine, &P_MACHINE_SecureBallotBoxMachine, &P_MACHINE_SecureTamperEvidentLogMachine, &P_MACHINE_SecureTabulationTellerMachine, &P_MACHINE_SecureVotingClientMachine };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_InitializerMachine, &P_I_SecureSupervisorMachine, &P_I_VotingUSM, &P_I_SecureBulletinBoardMachine, &P_I_SecureBallotBoxMachine, &P_I_SecureTamperEvidentLogMachine, &P_I_SecureTabulationTellerMachine, &P_I_SecureVotingClientMachine };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_machine_handle, &P_StringType };
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
    12U,
    8U,
    8U,
    0U,
    2U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};

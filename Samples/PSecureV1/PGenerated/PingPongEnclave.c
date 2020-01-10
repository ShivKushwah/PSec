#include "PingPongEnclave.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
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
static PRT_SEQTYPE P_SEQTYPE = { &P_GEND_TYPE_StringType };
static PRT_TYPE P_GEND_TYPE_SStringType = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE } };
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_SStringType };
static PRT_TUPTYPE P_TUP = { 2U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T2iSStringType = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_MKiVi = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };

// Function implementation prototypes:
PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Concat_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_2;


PRT_EVENTDECL P_EVENT_Ping = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Ping",
    2U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_Pong = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Pong",
    2U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_UntrustedEventFromPing = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UntrustedEventFromPing",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_Success = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Success",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_PublicIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "PublicIDEvent",
    4294967295U,
    &P_GEND_TYPE_StringType
};

PRT_EVENTDECL P_EVENT_MasterSecretEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MasterSecretEvent",
    4294967295U,
    &P_GEND_TYPE_T2iSStringType
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

PRT_EVENTDECL P_EVENT_TestEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TestEvent",
    4294967295U,
    &P_GEND_TYPE_i
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


PRT_EVENTDECL* P_GodUntrusted_RECV_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodUntrusted_RECV =
{
    11U,
    P_GodUntrusted_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_GodUntrusted =
{
    0U,
    "GodUntrusted",
    &P_GEND_TYPE_n,
    &P_EVENTSET_GodUntrusted_RECV
};

PRT_EVENTDECL* P_GodMachine_RECV_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodMachine_RECV =
{
    11U,
    P_GodMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_GodMachine =
{
    1U,
    "GodMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_GodMachine_RECV
};

PRT_EVENTDECL* P_BankEnclave_RECV_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_RECV =
{
    11U,
    P_BankEnclave_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_BankEnclave =
{
    2U,
    "BankEnclave",
    &P_GEND_TYPE_n,
    &P_EVENTSET_BankEnclave_RECV
};

PRT_VARDECL P_GodUntrusted_VARS[] = {
    { "handler", &P_GEND_TYPE_StringType }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS =
{
    0U,
    P_Initial_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS =
{
    0U,
    P_Initial_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS =
{
    0U,
    P_Initial_DOS_INNER,
    NULL
};

#define P_STATE_GodUntrusted_Initial \
{ \
    "GodUntrusted.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS, \
    &P_EVENTSET_Initial_TRANS, \
    &P_EVENTSET_Initial_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_GodUntrusted_STATES[] = { P_STATE_GodUntrusted_Initial };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    _P_GEN_funargs[0] = "GodMachine";
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
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL
};


PRT_FUNDECL* P_GodUntrusted_METHODS[] = { &P_FUNCTION_Anon };

PRT_EVENTDECL* P_GodUntrusted_RECV_INNER_1[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodUntrusted_RECV_1 =
{
    11U,
    P_GodUntrusted_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_GodUntrusted_SEND_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodUntrusted_SEND =
{
    11U,
    P_GodUntrusted_SEND_INNER,
    NULL
};

PRT_UINT32 P_GodUntrusted_CREATES_ARR[] = { 1 };
PRT_INTERFACESETDECL P_GodUntrusted_CREATES = { 1, P_GodUntrusted_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_GodUntrusted = 
{
    0U,
    "GodUntrusted",
    &P_EVENTSET_GodUntrusted_RECV_1,
    &P_EVENTSET_GodUntrusted_SEND,
    &P_GodUntrusted_CREATES,
    1U,
    1U,
    1U,
    4294967295U,
    0U,
    P_GodUntrusted_VARS,
    P_GodUntrusted_STATES,
    P_GodUntrusted_METHODS,
    PRT_FALSE
};

PRT_VARDECL P_GodMachine_VARS[] = {
    { "bankSSM", &P_GEND_TYPE_StringType }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_1 =
{
    0U,
    P_Initial_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_1 =
{
    0U,
    P_Initial_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_1 =
{
    0U,
    P_Initial_DOS_INNER_1,
    NULL
};

#define P_STATE_GodMachine_Initial \
{ \
    "GodMachine.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_1, \
    &P_EVENTSET_Initial_TRANS_1, \
    &P_EVENTSET_Initial_DOS_1, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_1, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_GodMachine_STATES[] = { P_STATE_GodMachine_Initial };

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    _P_GEN_funargs[0] = "BankEnclave";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_3 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_3);
        *P_LVALUE_3 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtCloneValue(p_this->varValues[0]);
    
    _P_GEN_funargs[0] = &(PTMP_tmp1);
    PrtFreeValue(P_PrintKey_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp1);
    PTMP_tmp1 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = PrtCloneValue((&P_EVENT_TestEvent.value));
    
    PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtCloneValue((&P_LIT_INT32));
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp2);
    _P_GEN_funargs[1] = &(PTMP_tmp3);
    _P_GEN_funargs[2] = &(P_PTMP_tmp);
    _P_GEN_funargs[3] = &(PTMP_tmp4);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_FUNDECL* P_GodMachine_METHODS[] = { &P_FUNCTION_Anon_1 };

PRT_EVENTDECL* P_GodMachine_RECV_INNER_1[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodMachine_RECV_1 =
{
    11U,
    P_GodMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_GodMachine_SEND_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodMachine_SEND =
{
    11U,
    P_GodMachine_SEND_INNER,
    NULL
};

PRT_UINT32 P_GodMachine_CREATES_ARR[] = { 2 };
PRT_INTERFACESETDECL P_GodMachine_CREATES = { 1, P_GodMachine_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_GodMachine = 
{
    1U,
    "GodMachine",
    &P_EVENTSET_GodMachine_RECV_1,
    &P_EVENTSET_GodMachine_SEND,
    &P_GodMachine_CREATES,
    1U,
    1U,
    1U,
    4294967295U,
    0U,
    P_GodMachine_VARS,
    P_GodMachine_STATES,
    P_GodMachine_METHODS,
    PRT_TRUE
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_2 =
{
    0U,
    P_Initial_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_2[] = { &P_EVENT_TestEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_2 =
{
    1U,
    P_Initial_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_2 =
{
    0U,
    P_Initial_DOS_INNER_2,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 0, &P_EVENT_TestEvent, 1, &_P_NO_OP }
};

#define P_STATE_BankEnclave_Initial \
{ \
    "BankEnclave.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_2, \
    &P_EVENTSET_Initial_TRANS_2, \
    &P_EVENTSET_Initial_DOS_2, \
    P_TRANS, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_NextState_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_NextState_DEFERS =
{
    0U,
    P_NextState_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_NextState_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_NextState_TRANS =
{
    0U,
    P_NextState_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_NextState_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_NextState_DOS =
{
    0U,
    P_NextState_DOS_INNER,
    NULL
};

#define P_STATE_BankEnclave_NextState \
{ \
    "BankEnclave.NextState", \
    0U, \
    0U, \
    &P_EVENTSET_NextState_DEFERS, \
    &P_EVENTSET_NextState_TRANS, \
    &P_EVENTSET_NextState_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_BankEnclave_STATES[] = { P_STATE_BankEnclave_Initial, P_STATE_BankEnclave_NextState };

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtMkBoolValue(PrtIsEqualValue(*P_VAR_payload, (&P_LIT_INT32_2)));
    
    if (PrtPrimGetBool(PTMP_tmp0_2))
    {
        PrtPrintf("Test1 Success!");
        
    }
    
    else
    {
        PrtPrintf("Test1 Failure");
        
    }
    
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_i
};


PRT_FUNDECL* P_BankEnclave_METHODS[] = { &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_BankEnclave_RECV_INNER_1[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_RECV_1 =
{
    11U,
    P_BankEnclave_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_BankEnclave_SEND_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_TestEvent, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_SEND =
{
    11U,
    P_BankEnclave_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_BankEnclave = 
{
    2U,
    "BankEnclave",
    &P_EVENTSET_BankEnclave_RECV_1,
    &P_EVENTSET_BankEnclave_SEND,
    NULL,
    0U,
    2U,
    1U,
    4294967295U,
    0U,
    NULL,
    P_BankEnclave_STATES,
    P_BankEnclave_METHODS,
    PRT_TRUE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_UntrustedEventFromPing, &P_EVENT_Success, &P_EVENT_PublicIDEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_TestEvent };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_GodUntrusted, &P_MACHINE_GodMachine, &P_MACHINE_BankEnclave };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_GodUntrusted, &P_I_GodMachine, &P_I_BankEnclave };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType };
int P_DefaultImpl_LME_0[] = { -1,1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,2 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    12U,
    3U,
    3U,
    0U,
    1U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};

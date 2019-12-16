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
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };

// Function implementation prototypes:
PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_Success = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Success",
    4294967295U,
    &P_GEND_TYPE_n
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


PRT_EVENTDECL* P_Coordinator_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Coordinator_RECV =
{
    5U,
    P_Coordinator_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Coordinator =
{
    0U,
    "Coordinator",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Coordinator_RECV
};

PRT_EVENTDECL* P_Pong_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Pong_RECV =
{
    5U,
    P_Pong_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Pong =
{
    1U,
    "Pong",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Pong_RECV
};

PRT_EVENTDECL* P_SecureChild_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureChild_RECV =
{
    5U,
    P_SecureChild_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureChild =
{
    2U,
    "SecureChild",
    &P_GEND_TYPE_StringType,
    &P_EVENTSET_SecureChild_RECV
};

PRT_EVENTDECL* P_Ping_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Ping_RECV =
{
    5U,
    P_Ping_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Ping =
{
    3U,
    "Ping",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Ping_RECV
};

PRT_EVENTDECL* P_Temp_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Temp_RECV =
{
    5U,
    P_Temp_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Temp =
{
    4U,
    "Temp",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Temp_RECV
};

PRT_VARDECL P_Coordinator_VARS[] = {
    { "PongSecureChild", &P_GEND_TYPE_StringType }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS =
{
    0U,
    P_Initial_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER[] = { &P_EVENT_UntrustedEventFromPing };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS =
{
    1U,
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

PRT_TRANSDECL P_TRANS[] =
{
    { 0, &P_EVENT_UntrustedEventFromPing, 1, &_P_NO_OP }
};

#define P_STATE_Coordinator_Initial \
{ \
    "Coordinator.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS, \
    &P_EVENTSET_Initial_TRANS, \
    &P_EVENTSET_Initial_DOS, \
    P_TRANS, \
    NULL, \
    &P_FUNCTION_Anon, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Whoa_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Whoa_DEFERS =
{
    0U,
    P_Whoa_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Whoa_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Whoa_TRANS =
{
    0U,
    P_Whoa_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Whoa_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Whoa_DOS =
{
    0U,
    P_Whoa_DOS_INNER,
    NULL
};

#define P_STATE_Coordinator_Whoa \
{ \
    "Coordinator.Whoa", \
    0U, \
    0U, \
    &P_EVENTSET_Whoa_DEFERS, \
    &P_EVENTSET_Whoa_TRANS, \
    &P_EVENTSET_Whoa_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_1, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Coordinator_STATES[] = { P_STATE_Coordinator_Initial, P_STATE_Coordinator_Whoa };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    _P_GEN_funargs[0] = "Pong";
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


PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("WHOA");
    
p_return_1: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_FUNDECL* P_Coordinator_METHODS[] = { &P_FUNCTION_Anon, &P_FUNCTION_Anon_1 };

PRT_EVENTDECL* P_Coordinator_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Coordinator_RECV_1 =
{
    5U,
    P_Coordinator_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Coordinator_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Coordinator_SEND =
{
    5U,
    P_Coordinator_SEND_INNER,
    NULL
};

PRT_UINT32 P_Coordinator_CREATES_ARR[] = { 1 };
PRT_INTERFACESETDECL P_Coordinator_CREATES = { 1, P_Coordinator_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_Coordinator = 
{
    0U,
    "Coordinator",
    &P_EVENTSET_Coordinator_RECV_1,
    &P_EVENTSET_Coordinator_SEND,
    &P_Coordinator_CREATES,
    1U,
    2U,
    2U,
    4294967295U,
    0U,
    P_Coordinator_VARS,
    P_Coordinator_STATES,
    P_Coordinator_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_Pong_VARS[] = {
    { "secureChildRegular", &P_GEND_TYPE_StringType },
    { "thisVar", &P_GEND_TYPE_StringType }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_1 =
{
    0U,
    P_Initial_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_1[] = { &P_EVENT_Ping };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_1 =
{
    1U,
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

PRT_TRANSDECL P_TRANS_1[] =
{
    { 0, &P_EVENT_Ping, 1, &_P_NO_OP }
};

#define P_STATE_Pong_Initial \
{ \
    "Pong.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_1, \
    &P_EVENTSET_Initial_TRANS_1, \
    &P_EVENTSET_Initial_DOS_1, \
    P_TRANS_1, \
    NULL, \
    &P_FUNCTION_Anon_2, \
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

#define P_STATE_Pong_Done \
{ \
    "Pong.Done", \
    0U, \
    0U, \
    &P_EVENTSET_Done_DEFERS, \
    &P_EVENTSET_Done_TRANS, \
    &P_EVENTSET_Done_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Pong_STATES[] = { P_STATE_Pong_Initial, P_STATE_Pong_Done };

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
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
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = ((_P_GEN_funval = P_GetThis_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_3 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_3);
        *P_LVALUE_3 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtCloneValue(p_this->varValues[1]);
    
    _P_GEN_funargs[0] = "SecureChild";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp1);
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_6 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_6);
        *P_LVALUE_6 = PTMP_tmp2;
        PTMP_tmp2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtCloneValue(p_this->varValues[0]);
    
    _P_GEN_funargs[0] = &(PTMP_tmp3);
    PrtFreeValue(P_PrintString_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp3);
    PTMP_tmp3 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue((&P_EVENT_Pong.value));
    
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue((&P_LIT_INT32));
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp4);
    _P_GEN_funargs[1] = &(PTMP_tmp5);
    _P_GEN_funargs[2] = &(P_PTMP_tmp);
    _P_GEN_funargs[3] = &(PTMP_tmp6);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    NULL
};


PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("YOOOOO");
    
p_return_3: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    NULL
};


PRT_FUNDECL* P_Pong_METHODS[] = { &P_FUNCTION_Anon_2, &P_FUNCTION_Anon_3 };

PRT_EVENTDECL* P_Pong_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Pong_RECV_1 =
{
    5U,
    P_Pong_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Pong_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Pong_SEND =
{
    5U,
    P_Pong_SEND_INNER,
    NULL
};

PRT_UINT32 P_Pong_CREATES_ARR[] = { 2 };
PRT_INTERFACESETDECL P_Pong_CREATES = { 1, P_Pong_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_Pong = 
{
    1U,
    "Pong",
    &P_EVENTSET_Pong_RECV_1,
    &P_EVENTSET_Pong_SEND,
    &P_Pong_CREATES,
    2U,
    2U,
    2U,
    4294967295U,
    0U,
    P_Pong_VARS,
    P_Pong_STATES,
    P_Pong_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_SecureChild_VARS[] = {
    { "parent", &P_GEND_TYPE_StringType }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_2 =
{
    0U,
    P_Initial_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_2[] = { &P_EVENT_Pong };
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

PRT_TRANSDECL P_TRANS_2[] =
{
    { 0, &P_EVENT_Pong, 1, &_P_NO_OP }
};

#define P_STATE_SecureChild_Initial \
{ \
    "SecureChild.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_2, \
    &P_EVENTSET_Initial_TRANS_2, \
    &P_EVENTSET_Initial_DOS_2, \
    P_TRANS_2, \
    NULL, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Next_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Next_DEFERS =
{
    0U,
    P_Next_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Next_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Next_TRANS =
{
    0U,
    P_Next_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Next_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Next_DOS =
{
    0U,
    P_Next_DOS_INNER,
    NULL
};

#define P_STATE_SecureChild_Next \
{ \
    "SecureChild.Next", \
    0U, \
    0U, \
    &P_EVENTSET_Next_DEFERS, \
    &P_EVENTSET_Next_TRANS, \
    &P_EVENTSET_Next_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_5, \
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

#define P_STATE_SecureChild_Done \
{ \
    "SecureChild.Done", \
    0U, \
    0U, \
    &P_EVENTSET_Done_DEFERS_1, \
    &P_EVENTSET_Done_TRANS_1, \
    &P_EVENTSET_Done_DOS_1, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureChild_STATES[] = { P_STATE_SecureChild_Initial, P_STATE_SecureChild_Next, P_STATE_SecureChild_Done };

PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_11 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue(*P_VAR_payload);
    
p_return_4: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    &P_GEND_TYPE_StringType
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue((&P_EVENT_Ping.value));
    
    PRT_VALUE* P_PTMP_tmp_1 = PrtCloneValue(&(P_LIT_INT32_2));
    _P_GEN_funargs[0] = &(PTMP_tmp0_2);
    _P_GEN_funargs[1] = &(PTMP_tmp1_1);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_1);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
    PrtGoto(p_this, 2U, 0);
    
p_return_5: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    NULL
};


PRT_FUNDECL* P_SecureChild_METHODS[] = { &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5 };

PRT_EVENTDECL* P_SecureChild_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureChild_RECV_1 =
{
    5U,
    P_SecureChild_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureChild_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureChild_SEND =
{
    5U,
    P_SecureChild_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_SecureChild = 
{
    2U,
    "SecureChild",
    &P_EVENTSET_SecureChild_RECV_1,
    &P_EVENTSET_SecureChild_SEND,
    NULL,
    1U,
    3U,
    2U,
    4294967295U,
    0U,
    P_SecureChild_VARS,
    P_SecureChild_STATES,
    P_SecureChild_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_Ping_VARS[] = {
    { "pongId", &P_GEND_TYPE_m },
    { "coordinatorID", &P_GEND_TYPE_StringType },
    { "numArgs", &P_GEND_TYPE_i },
    { "payld", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Ping_Init_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Ping_Init_DEFERS =
{
    0U,
    P_Ping_Init_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Ping_Init_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Ping_Init_TRANS =
{
    1U,
    P_Ping_Init_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Ping_Init_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Ping_Init_DOS =
{
    0U,
    P_Ping_Init_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_3[] =
{
    { 0, &P_EVENT_Success, 1, &_P_NO_OP }
};

#define P_STATE_Ping_Ping_Init \
{ \
    "Ping.Ping_Init", \
    1U, \
    0U, \
    &P_EVENTSET_Ping_Init_DEFERS, \
    &P_EVENTSET_Ping_Init_TRANS, \
    &P_EVENTSET_Ping_Init_DOS, \
    P_TRANS_3, \
    NULL, \
    &P_FUNCTION_Anon_6, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Done_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DEFERS_2 =
{
    0U,
    P_Done_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Done_TRANS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_TRANS_2 =
{
    0U,
    P_Done_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Done_DOS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DOS_2 =
{
    0U,
    P_Done_DOS_INNER_2,
    NULL
};

#define P_STATE_Ping_Done \
{ \
    "Ping.Done", \
    0U, \
    0U, \
    &P_EVENTSET_Done_DEFERS_2, \
    &P_EVENTSET_Done_TRANS_2, \
    &P_EVENTSET_Done_DOS_2, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Ping_STATES[] = { P_STATE_Ping_Ping_Init, P_STATE_Ping_Done };

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 4 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 9 } };
    PrtFreeValue(P_InitializeUntrustedMachine_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PrtFreeValue(P_GetThis_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    _P_GEN_funargs[0] = "Temp";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtCloneValue(PrtMkInterface(context, 4, 0)->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    {
        PRT_VALUE** P_LVALUE_15 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_15);
        *P_LVALUE_15 = PTMP_tmp0_3;
        PTMP_tmp0_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = PrtCloneValue((&P_EVENT_Pong.value));
    
    PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_18);
    *P_LVALUE_18 = PrtCloneValue((&P_LIT_INT32_3));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_2), PTMP_tmp2_1, 1, &(PTMP_tmp3_1));
    *(&(PTMP_tmp2_1)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    _P_GEN_funargs[0] = "Coordinator";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    {
        PRT_VALUE** P_LVALUE_20 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_20);
        *P_LVALUE_20 = PTMP_tmp4_1;
        PTMP_tmp4_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_21 = &(p_this->varValues[2]);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtCloneValue((&P_LIT_INT32_4));
    
    PRT_VALUE** P_LVALUE_22 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = PrtCloneValue((&P_LIT_INT32_5));
    
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = PrtCloneValue(p_this->varValues[1]);
    
    _P_GEN_funargs[0] = &(PTMP_tmp5_1);
    PrtFreeValue(P_PrintString_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp5_1);
    PTMP_tmp5_1 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = PrtCloneValue((&P_EVENT_UntrustedEventFromPing.value));
    
    PRT_VALUE** P_LVALUE_26 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue(p_this->varValues[3]);
    
    _P_GEN_funargs[0] = &(PTMP_tmp6_1);
    _P_GEN_funargs[1] = &(PTMP_tmp7);
    _P_GEN_funargs[2] = &(PTMP_tmp8);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp6_1);
    PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7);
    PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8);
    PTMP_tmp8 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp9, 0);
    *(&(PTMP_tmp9)) = NULL;
    goto p_return_6;
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    NULL
};


PRT_FUNDECL* P_Ping_METHODS[] = { &P_FUNCTION_Anon_6 };

PRT_EVENTDECL* P_Ping_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Ping_RECV_1 =
{
    5U,
    P_Ping_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Ping_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Ping_SEND =
{
    5U,
    P_Ping_SEND_INNER,
    NULL
};

PRT_UINT32 P_Ping_CREATES_ARR[] = { 0, 4 };
PRT_INTERFACESETDECL P_Ping_CREATES = { 2, P_Ping_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_Ping = 
{
    3U,
    "Ping",
    &P_EVENTSET_Ping_RECV_1,
    &P_EVENTSET_Ping_SEND,
    &P_Ping_CREATES,
    4U,
    2U,
    1U,
    4294967295U,
    0U,
    P_Ping_VARS,
    P_Ping_STATES,
    P_Ping_METHODS,
    PRT_FALSE
};

PRT_EVENTDECL* P_Init_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS =
{
    0U,
    P_Init_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER[] = { &P_EVENT_Pong };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS =
{
    1U,
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

PRT_TRANSDECL P_TRANS_4[] =
{
    { 0, &P_EVENT_Pong, 1, &_P_NO_OP }
};

#define P_STATE_Temp_Init \
{ \
    "Temp.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS, \
    &P_EVENTSET_Init_TRANS, \
    &P_EVENTSET_Init_DOS, \
    P_TRANS_4, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Done_DEFERS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DEFERS_3 =
{
    0U,
    P_Done_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Done_TRANS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_TRANS_3 =
{
    0U,
    P_Done_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Done_DOS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Done_DOS_3 =
{
    0U,
    P_Done_DOS_INNER_3,
    NULL
};

#define P_STATE_Temp_Done \
{ \
    "Temp.Done", \
    0U, \
    0U, \
    &P_EVENTSET_Done_DEFERS_3, \
    &P_EVENTSET_Done_TRANS_3, \
    &P_EVENTSET_Done_DOS_3, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Temp_STATES[] = { P_STATE_Temp_Init, P_STATE_Temp_Done };

PRT_EVENTDECL* P_Temp_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Temp_RECV_1 =
{
    5U,
    P_Temp_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Temp_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Temp_SEND =
{
    5U,
    P_Temp_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_Temp = 
{
    4U,
    "Temp",
    &P_EVENTSET_Temp_RECV_1,
    &P_EVENTSET_Temp_SEND,
    NULL,
    0U,
    2U,
    0U,
    4294967295U,
    0U,
    NULL,
    P_Temp_STATES,
    NULL,
    PRT_FALSE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_UntrustedEventFromPing, &P_EVENT_Success };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Coordinator, &P_MACHINE_Pong, &P_MACHINE_SecureChild, &P_MACHINE_Ping, &P_MACHINE_Temp };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Coordinator, &P_I_Pong, &P_I_SecureChild, &P_I_Ping, &P_I_Temp };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType };
int P_DefaultImpl_LME_0[] = { -1,1,-1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,2,-1,-1 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_3[] = { 0,-1,-1,-1,4 };
int P_DefaultImpl_LME_4[] = { -1,-1,-1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3, P_DefaultImpl_LME_4 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3,4 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    6U,
    5U,
    5U,
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

#include "PingPong.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };
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

// Function implementation prototypes:
PRT_VALUE* P_InitializePongEnclave_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;


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

PRT_FUNDECL P_FUNCTION_InitializePongEnclave =
{
    "InitializePongEnclave",
    &P_InitializePongEnclave_IMPL,
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


PRT_EVENTDECL* P_Ping_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Ping_RECV =
{
    5U,
    P_Ping_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Ping =
{
    0U,
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
    1U,
    "Temp",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Temp_RECV
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

PRT_TRANSDECL P_TRANS[] =
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
    P_TRANS, \
    NULL, \
    &P_FUNCTION_Anon, \
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

#define P_STATE_Ping_Done \
{ \
    "Ping.Done", \
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

PRT_STATEDECL P_Ping_STATES[] = { P_STATE_Ping_Ping_Init, P_STATE_Ping_Done };

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
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 4 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 9 } };
    _P_GEN_funargs[0] = "Temp";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtCloneValue(PrtMkInterface(context, 1, 0)->id);
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
    *P_LVALUE_3 = PrtCloneValue((&P_EVENT_Pong.value));
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtCloneValue((&P_LIT_INT32));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1), PTMP_tmp2, 1, &(PTMP_tmp3));
    *(&(PTMP_tmp2)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = ((_P_GEN_funval = P_UntrustedCreateCoordinator_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_6 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_6);
        *P_LVALUE_6 = PTMP_tmp4;
        PTMP_tmp4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_7 = &(p_this->varValues[2]);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtCloneValue((&P_LIT_INT32_1));
    
    PRT_VALUE** P_LVALUE_8 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtCloneValue((&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue((&P_EVENT_UntrustedEventFromPing.value));
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue(p_this->varValues[3]);
    
    _P_GEN_funargs[0] = &(PTMP_tmp5);
    _P_GEN_funargs[1] = &(PTMP_tmp6);
    _P_GEN_funargs[2] = &(PTMP_tmp7);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp5);
    PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6);
    PTMP_tmp6 = NULL;
    PrtFreeValue(PTMP_tmp7);
    PTMP_tmp7 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp8, 0);
    *(&(PTMP_tmp8)) = NULL;
    goto p_return;
    
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
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL
};


PRT_FUNDECL* P_Ping_METHODS[] = { &P_FUNCTION_Anon };

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

PRT_UINT32 P_Ping_CREATES_ARR[] = { 1 };
PRT_INTERFACESETDECL P_Ping_CREATES = { 1, P_Ping_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_Ping = 
{
    0U,
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

PRT_TRANSDECL P_TRANS_1[] =
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
    P_TRANS_1, \
    NULL, \
    &_P_NO_OP, \
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

#define P_STATE_Temp_Done \
{ \
    "Temp.Done", \
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
    1U,
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
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Ping, &P_MACHINE_Temp };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Ping, &P_I_Temp };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType };
int P_DefaultImpl_LME_0[] = { -1,1 };
int P_DefaultImpl_LME_1[] = { -1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1 };
int P_DefaultImpl_DEFMAP[] = { 0,1 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    6U,
    2U,
    2U,
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

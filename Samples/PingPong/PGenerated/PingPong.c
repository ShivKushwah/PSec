#include "PingPong.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };

// Function implementation prototypes:
PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_2;

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_3;


PRT_EVENTDECL P_EVENT_Ping = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Ping",
    1U,
    &P_GEND_TYPE_m
};

PRT_EVENTDECL P_EVENT_Pong = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Pong",
    1U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_Success = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Success",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL* P_Main_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Main_RECV =
{
    3U,
    P_Main_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Main =
{
    0U,
    "Main",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Main_RECV
};

PRT_EVENTDECL* P_PONG_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_PONG_RECV =
{
    3U,
    P_PONG_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_PONG =
{
    1U,
    "PONG",
    &P_GEND_TYPE_n,
    &P_EVENTSET_PONG_RECV
};

PRT_VARDECL P_Main_VARS[] = {
    { "pongId", &P_GEND_TYPE_m }
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

#define P_STATE_Main_Ping_Init \
{ \
    "Main.Ping_Init", \
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

PRT_EVENTDECL* P_Ping_SendPing_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Ping_SendPing_DEFERS =
{
    0U,
    P_Ping_SendPing_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Ping_SendPing_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Ping_SendPing_TRANS =
{
    1U,
    P_Ping_SendPing_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Ping_SendPing_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Ping_SendPing_DOS =
{
    0U,
    P_Ping_SendPing_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 1, &P_EVENT_Success, 2, &_P_NO_OP }
};

#define P_STATE_Main_Ping_SendPing \
{ \
    "Main.Ping_SendPing", \
    1U, \
    0U, \
    &P_EVENTSET_Ping_SendPing_DEFERS, \
    &P_EVENTSET_Ping_SendPing_TRANS, \
    &P_EVENTSET_Ping_SendPing_DOS, \
    P_TRANS_1, \
    NULL, \
    &P_FUNCTION_Anon_1, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Ping_WaitPong_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Ping_WaitPong_DEFERS =
{
    0U,
    P_Ping_WaitPong_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Ping_WaitPong_TRANS_INNER[] = { &P_EVENT_Pong };
PRT_EVENTSETDECL P_EVENTSET_Ping_WaitPong_TRANS =
{
    1U,
    P_Ping_WaitPong_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Ping_WaitPong_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Ping_WaitPong_DOS =
{
    0U,
    P_Ping_WaitPong_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_2[] =
{
    { 2, &P_EVENT_Pong, 1, &_P_NO_OP }
};

#define P_STATE_Main_Ping_WaitPong \
{ \
    "Main.Ping_WaitPong", \
    1U, \
    0U, \
    &P_EVENTSET_Ping_WaitPong_DEFERS, \
    &P_EVENTSET_Ping_WaitPong_TRANS, \
    &P_EVENTSET_Ping_WaitPong_DOS, \
    P_TRANS_2, \
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

#define P_STATE_Main_Done \
{ \
    "Main.Done", \
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

PRT_STATEDECL P_Main_STATES[] = { P_STATE_Main_Ping_Init, P_STATE_Main_Ping_SendPing, P_STATE_Main_Ping_WaitPong, P_STATE_Main_Done };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtCloneValue(PrtMkInterface(context, 1, 0)->id);
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
    *P_LVALUE_2 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp1, 0);
    *(&(PTMP_tmp1)) = NULL;
    goto p_return;
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
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
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtCloneValue((&P_EVENT_Ping.value));
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = PrtCloneValue((p_this->id));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_1), PTMP_tmp1_1, 1, &(PTMP_tmp2));
    *(&(PTMP_tmp1_1)) = NULL;
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp3, 0);
    *(&(PTMP_tmp3)) = NULL;
    goto p_return_1;
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_FUNDECL* P_Main_METHODS[] = { &P_FUNCTION_Anon, &P_FUNCTION_Anon_1 };

PRT_EVENTDECL* P_Main_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Main_RECV_1 =
{
    3U,
    P_Main_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Main_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Main_SEND =
{
    3U,
    P_Main_SEND_INNER,
    NULL
};

PRT_UINT32 P_Main_CREATES_ARR[] = { 1 };
PRT_INTERFACESETDECL P_Main_CREATES = { 1, P_Main_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_Main = 
{
    0U,
    "Main",
    &P_EVENTSET_Main_RECV_1,
    &P_EVENTSET_Main_SEND,
    &P_Main_CREATES,
    1U,
    4U,
    2U,
    4294967295U,
    0U,
    P_Main_VARS,
    P_Main_STATES,
    P_Main_METHODS
};

PRT_EVENTDECL* P_Pong_WaitPing_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Pong_WaitPing_DEFERS =
{
    0U,
    P_Pong_WaitPing_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Pong_WaitPing_TRANS_INNER[] = { &P_EVENT_Ping };
PRT_EVENTSETDECL P_EVENTSET_Pong_WaitPing_TRANS =
{
    1U,
    P_Pong_WaitPing_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Pong_WaitPing_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Pong_WaitPing_DOS =
{
    0U,
    P_Pong_WaitPing_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_3[] =
{
    { 0, &P_EVENT_Ping, 1, &_P_NO_OP }
};

#define P_STATE_PONG_Pong_WaitPing \
{ \
    "PONG.Pong_WaitPing", \
    1U, \
    0U, \
    &P_EVENTSET_Pong_WaitPing_DEFERS, \
    &P_EVENTSET_Pong_WaitPing_TRANS, \
    &P_EVENTSET_Pong_WaitPing_DOS, \
    P_TRANS_3, \
    NULL, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Pong_SendPong_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Pong_SendPong_DEFERS =
{
    0U,
    P_Pong_SendPong_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Pong_SendPong_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Pong_SendPong_TRANS =
{
    1U,
    P_Pong_SendPong_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Pong_SendPong_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Pong_SendPong_DOS =
{
    0U,
    P_Pong_SendPong_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_4[] =
{
    { 1, &P_EVENT_Success, 0, &_P_NO_OP }
};

#define P_STATE_PONG_Pong_SendPong \
{ \
    "PONG.Pong_SendPong", \
    1U, \
    0U, \
    &P_EVENTSET_Pong_SendPong_DEFERS, \
    &P_EVENTSET_Pong_SendPong_TRANS, \
    &P_EVENTSET_Pong_SendPong_DOS, \
    P_TRANS_4, \
    NULL, \
    &P_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_PONG_STATES[] = { P_STATE_PONG_Pong_WaitPing, P_STATE_PONG_Pong_SendPong };

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_2: ;
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
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtCloneValue(*P_VAR_payload);
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtCloneValue((&P_EVENT_Pong.value));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_2), PTMP_tmp1_2, 0);
    *(&(PTMP_tmp1_2)) = NULL;
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp2_1, 0);
    *(&(PTMP_tmp2_1)) = NULL;
    goto p_return_3;
    
p_return_3: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_m
};


PRT_FUNDECL* P_PONG_METHODS[] = { &P_FUNCTION_Anon_2, &P_FUNCTION_Anon_3 };

PRT_EVENTDECL* P_PONG_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_PONG_RECV_1 =
{
    3U,
    P_PONG_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_PONG_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_PONG_SEND =
{
    3U,
    P_PONG_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_PONG = 
{
    1U,
    "PONG",
    &P_EVENTSET_PONG_RECV_1,
    &P_EVENTSET_PONG_SEND,
    NULL,
    0U,
    2U,
    2U,
    4294967295U,
    0U,
    NULL,
    P_PONG_STATES,
    P_PONG_METHODS
};

PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Main, &P_MACHINE_PONG };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Main, &P_I_PONG };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { NULL };
int P_DefaultImpl_LME_0[] = { -1,1 };
int P_DefaultImpl_LME_1[] = { -1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1 };
int P_DefaultImpl_DEFMAP[] = { 0,1 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    5U,
    2U,
    2U,
    0U,
    0U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};

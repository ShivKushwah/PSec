#include "PingPong.h"

// Type universe for program:
static PRT_TYPE P_PINGPONG_GEND_TYPE_e = { PRT_KIND_EVENT, { NULL } };
static PRT_TYPE P_PINGPONG_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
// TODO: implement full permission types in runtime
static PRT_TYPE P_PINGPONG_GEND_TYPE_R = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE P_PINGPONG_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };
// TODO: implement full permission types in runtime
static PRT_TYPE P_PINGPONG_GEND_TYPE_R_1 = { PRT_KIND_MACHINE, { NULL } };

// Function implementation prototypes:
PRT_VALUE* P_PINGPONG_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_PINGPONG_FUNCTION_Anon;

PRT_VALUE* P_PINGPONG_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_PINGPONG_FUNCTION_Anon_1;

PRT_VALUE* P_PINGPONG_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_PINGPONG_FUNCTION_Anon_2;

PRT_VALUE* P_PINGPONG_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_PINGPONG_FUNCTION_Anon_3;


#line 1 "PingPong.p"
PRT_EVENTDECL P_PINGPONG_EVENT_Ping = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Ping",
    1U,
    &P_PINGPONG_GEND_TYPE_m
};

#line 2 "PingPong.p"
PRT_EVENTDECL P_PINGPONG_EVENT_Pong = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Pong",
    1U,
    &P_PINGPONG_GEND_TYPE_n
};

#line 3 "PingPong.p"
PRT_EVENTDECL P_PINGPONG_EVENT_Success = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Success",
    4294967295U,
    &P_PINGPONG_GEND_TYPE_n
};

#line 5 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Main_RECV_INNER[] = { &P_PINGPONG_EVENT_Ping, &P_PINGPONG_EVENT_Pong, &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Main_RECV =
{
    3U,
    P_PINGPONG_Main_RECV_INNER,
    NULL
};

#line 5 "PingPong.p"
PRT_INTERFACEDECL P_PINGPONG_I_Main =
{
    0U,
    "Main",
    &P_PINGPONG_GEND_TYPE_n,
    &P_PINGPONG_EVENTSET_Main_RECV
};

#line 31 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_PONG_RECV_INNER[] = { &P_PINGPONG_EVENT_Ping, &P_PINGPONG_EVENT_Pong, &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_PONG_RECV =
{
    3U,
    P_PINGPONG_PONG_RECV_INNER,
    NULL
};

#line 31 "PingPong.p"
PRT_INTERFACEDECL P_PINGPONG_I_PONG =
{
    1U,
    "PONG",
    &P_PINGPONG_GEND_TYPE_n,
    &P_PINGPONG_EVENTSET_PONG_RECV
};

PRT_VARDECL P_PINGPONG_Main_VARS[] = {
    { "pongId", &P_PINGPONG_GEND_TYPE_m }
};

#line 8 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_Init_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_Init_DEFERS =
{
    0U,
    P_PINGPONG_Ping_Init_DEFERS_INNER,
    NULL
};

#line 8 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_Init_TRANS_INNER[] = { &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_Init_TRANS =
{
    1U,
    P_PINGPONG_Ping_Init_TRANS_INNER,
    NULL
};

#line 8 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_Init_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_Init_DOS =
{
    0U,
    P_PINGPONG_Ping_Init_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_PINGPONG_TRANS[] =
{
    { 0, &P_PINGPONG_EVENT_Success, 1, &_P_NO_OP }
};

#line 8 "PingPong.p"
#define P_PINGPONG_STATE_Main_Ping_Init \
{ \
    "Main.Ping_Init", \
    1U, \
    0U, \
    &P_PINGPONG_EVENTSET_Ping_Init_DEFERS, \
    &P_PINGPONG_EVENTSET_Ping_Init_TRANS, \
    &P_PINGPONG_EVENTSET_Ping_Init_DOS, \
    P_PINGPONG_TRANS, \
    NULL, \
    &P_PINGPONG_FUNCTION_Anon, \
    &_P_NO_OP, \
}

#line 16 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_SendPing_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_SendPing_DEFERS =
{
    0U,
    P_PINGPONG_Ping_SendPing_DEFERS_INNER,
    NULL
};

#line 16 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_SendPing_TRANS_INNER[] = { &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_SendPing_TRANS =
{
    1U,
    P_PINGPONG_Ping_SendPing_TRANS_INNER,
    NULL
};

#line 16 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_SendPing_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_SendPing_DOS =
{
    0U,
    P_PINGPONG_Ping_SendPing_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_PINGPONG_TRANS_1[] =
{
    { 1, &P_PINGPONG_EVENT_Success, 2, &_P_NO_OP }
};

#line 16 "PingPong.p"
#define P_PINGPONG_STATE_Main_Ping_SendPing \
{ \
    "Main.Ping_SendPing", \
    1U, \
    0U, \
    &P_PINGPONG_EVENTSET_Ping_SendPing_DEFERS, \
    &P_PINGPONG_EVENTSET_Ping_SendPing_TRANS, \
    &P_PINGPONG_EVENTSET_Ping_SendPing_DOS, \
    P_PINGPONG_TRANS_1, \
    NULL, \
    &P_PINGPONG_FUNCTION_Anon_1, \
    &_P_NO_OP, \
}

#line 24 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_WaitPong_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_WaitPong_DEFERS =
{
    0U,
    P_PINGPONG_Ping_WaitPong_DEFERS_INNER,
    NULL
};

#line 24 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_WaitPong_TRANS_INNER[] = { &P_PINGPONG_EVENT_Pong };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_WaitPong_TRANS =
{
    1U,
    P_PINGPONG_Ping_WaitPong_TRANS_INNER,
    NULL
};

#line 24 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Ping_WaitPong_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Ping_WaitPong_DOS =
{
    0U,
    P_PINGPONG_Ping_WaitPong_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_PINGPONG_TRANS_2[] =
{
    { 2, &P_PINGPONG_EVENT_Pong, 1, &_P_NO_OP }
};

#line 24 "PingPong.p"
#define P_PINGPONG_STATE_Main_Ping_WaitPong \
{ \
    "Main.Ping_WaitPong", \
    1U, \
    0U, \
    &P_PINGPONG_EVENTSET_Ping_WaitPong_DEFERS, \
    &P_PINGPONG_EVENTSET_Ping_WaitPong_TRANS, \
    &P_PINGPONG_EVENTSET_Ping_WaitPong_DOS, \
    P_PINGPONG_TRANS_2, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

#line 28 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Done_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Done_DEFERS =
{
    0U,
    P_PINGPONG_Done_DEFERS_INNER,
    NULL
};

#line 28 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Done_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Done_TRANS =
{
    0U,
    P_PINGPONG_Done_TRANS_INNER,
    NULL
};

#line 28 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Done_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Done_DOS =
{
    0U,
    P_PINGPONG_Done_DOS_INNER,
    NULL
};

#line 28 "PingPong.p"
#define P_PINGPONG_STATE_Main_Done \
{ \
    "Main.Done", \
    0U, \
    0U, \
    &P_PINGPONG_EVENTSET_Done_DEFERS, \
    &P_PINGPONG_EVENTSET_Done_TRANS, \
    &P_PINGPONG_EVENTSET_Done_DOS, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_PINGPONG_Main_STATES[] = { P_PINGPONG_STATE_Main_Ping_Init, P_PINGPONG_STATE_Main_Ping_SendPing, P_PINGPONG_STATE_Main_Ping_WaitPong, P_PINGPONG_STATE_Main_Done };

#line 9 "PingPong.p"
PRT_VALUE* P_PINGPONG_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
#line 9 "PingPong.p"
    PRT_VALUE* PTMP_tmp0 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_R);
    PRT_VALUE* PTMP_tmp1 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_e);
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
#line 9 "PingPong.p"
#line 10 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_PINGPONG_LVALUE);
    *P_PINGPONG_LVALUE = PrtCloneValue(PrtMkInterface(context, 1, 0)->id);
    
#line 10 "PingPong.p"
    {
        PRT_VALUE** P_PINGPONG_LVALUE_1 = &(p_this->varValues[0]);
        PrtFreeValue(*P_PINGPONG_LVALUE_1);
        *P_PINGPONG_LVALUE_1 = PTMP_tmp0;
        PTMP_tmp0 = NULL;
    }
    
#line 11 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE_2 = &(PTMP_tmp1);
    PrtFreeValue(*P_PINGPONG_LVALUE_2);
    *P_PINGPONG_LVALUE_2 = PrtCloneValue((&P_PINGPONG_EVENT_Success.value));
    
#line 11 "PingPong.p"
    PrtFreeTriggerPayload(p_this);
    PrtRaise(p_this, PTMP_tmp1, 0);
    *(&(PTMP_tmp1)) = NULL;
    goto p_return;
    
p_return:
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_PINGPONG_FUNCTION_Anon =
{
    NULL,
    &P_PINGPONG_Anon_IMPL,
    NULL
};


#line 17 "PingPong.p"
PRT_VALUE* P_PINGPONG_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
#line 17 "PingPong.p"
    PRT_VALUE* PTMP_tmp0_1 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_m);
    PRT_VALUE* PTMP_tmp1_1 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_e);
    PRT_VALUE* PTMP_tmp2 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_R_1);
    PRT_VALUE* PTMP_tmp3 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_e);
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
#line 17 "PingPong.p"
#line 18 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE_3 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_PINGPONG_LVALUE_3);
    *P_PINGPONG_LVALUE_3 = PrtCloneValue(p_this->varValues[0]);
    
#line 18 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE_4 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_PINGPONG_LVALUE_4);
    *P_PINGPONG_LVALUE_4 = PrtCloneValue((&P_PINGPONG_EVENT_Ping.value));
    
#line 18 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE_5 = &(PTMP_tmp2);
    PrtFreeValue(*P_PINGPONG_LVALUE_5);
    *P_PINGPONG_LVALUE_5 = PrtCloneValue((p_this->id));
    
#line 18 "PingPong.p"
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_1), PTMP_tmp1_1, 1, &(PTMP_tmp2));
    *(&(PTMP_tmp1_1)) = NULL;
    
#line 19 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE_6 = &(PTMP_tmp3);
    PrtFreeValue(*P_PINGPONG_LVALUE_6);
    *P_PINGPONG_LVALUE_6 = PrtCloneValue((&P_PINGPONG_EVENT_Success.value));
    
#line 19 "PingPong.p"
    PrtFreeTriggerPayload(p_this);
    PrtRaise(p_this, PTMP_tmp3, 0);
    *(&(PTMP_tmp3)) = NULL;
    goto p_return;
    
p_return:
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_PINGPONG_FUNCTION_Anon_1 =
{
    NULL,
    &P_PINGPONG_Anon_IMPL_1,
    NULL
};


PRT_FUNDECL* P_PINGPONG_Main_METHODS[] = { &P_PINGPONG_FUNCTION_Anon, &P_PINGPONG_FUNCTION_Anon_1 };

#line 5 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Main_RECV_INNER_1[] = { &P_PINGPONG_EVENT_Ping, &P_PINGPONG_EVENT_Pong, &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Main_RECV_1 =
{
    3U,
    P_PINGPONG_Main_RECV_INNER_1,
    NULL
};

#line 5 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Main_SEND_INNER[] = { &P_PINGPONG_EVENT_Ping, &P_PINGPONG_EVENT_Pong, &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Main_SEND =
{
    3U,
    P_PINGPONG_Main_SEND_INNER,
    NULL
};

PRT_UINT32 P_PINGPONG_Main_CREATES_ARR[] = { 1 };
PRT_INTERFACESETDECL P_PINGPONG_Main_CREATES = { 1, P_PINGPONG_Main_CREATES_ARR };
#line 5 "PingPong.p"
PRT_MACHINEDECL P_PINGPONG_MACHINE_Main = 
{
    0U,
    "Main",
    &P_PINGPONG_EVENTSET_Main_RECV_1,
    &P_PINGPONG_EVENTSET_Main_SEND,
    &P_PINGPONG_Main_CREATES,
    1U,
    4U,
    2U,
    4294967295U,
    0U,
    P_PINGPONG_Main_VARS,
    P_PINGPONG_Main_STATES,
    P_PINGPONG_Main_METHODS
};

#line 32 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Pong_WaitPing_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Pong_WaitPing_DEFERS =
{
    0U,
    P_PINGPONG_Pong_WaitPing_DEFERS_INNER,
    NULL
};

#line 32 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Pong_WaitPing_TRANS_INNER[] = { &P_PINGPONG_EVENT_Ping };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Pong_WaitPing_TRANS =
{
    1U,
    P_PINGPONG_Pong_WaitPing_TRANS_INNER,
    NULL
};

#line 32 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Pong_WaitPing_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Pong_WaitPing_DOS =
{
    0U,
    P_PINGPONG_Pong_WaitPing_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_PINGPONG_TRANS_3[] =
{
    { 0, &P_PINGPONG_EVENT_Ping, 1, &_P_NO_OP }
};

#line 32 "PingPong.p"
#define P_PINGPONG_STATE_PONG_Pong_WaitPing \
{ \
    "PONG.Pong_WaitPing", \
    1U, \
    0U, \
    &P_PINGPONG_EVENTSET_Pong_WaitPing_DEFERS, \
    &P_PINGPONG_EVENTSET_Pong_WaitPing_TRANS, \
    &P_PINGPONG_EVENTSET_Pong_WaitPing_DOS, \
    P_PINGPONG_TRANS_3, \
    NULL, \
    &P_PINGPONG_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

#line 37 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Pong_SendPong_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Pong_SendPong_DEFERS =
{
    0U,
    P_PINGPONG_Pong_SendPong_DEFERS_INNER,
    NULL
};

#line 37 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Pong_SendPong_TRANS_INNER[] = { &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Pong_SendPong_TRANS =
{
    1U,
    P_PINGPONG_Pong_SendPong_TRANS_INNER,
    NULL
};

#line 37 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_Pong_SendPong_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_Pong_SendPong_DOS =
{
    0U,
    P_PINGPONG_Pong_SendPong_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_PINGPONG_TRANS_4[] =
{
    { 1, &P_PINGPONG_EVENT_Success, 0, &_P_NO_OP }
};

#line 37 "PingPong.p"
#define P_PINGPONG_STATE_PONG_Pong_SendPong \
{ \
    "PONG.Pong_SendPong", \
    1U, \
    0U, \
    &P_PINGPONG_EVENTSET_Pong_SendPong_DEFERS, \
    &P_PINGPONG_EVENTSET_Pong_SendPong_TRANS, \
    &P_PINGPONG_EVENTSET_Pong_SendPong_DOS, \
    P_PINGPONG_TRANS_4, \
    NULL, \
    &P_PINGPONG_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_PINGPONG_PONG_STATES[] = { P_PINGPONG_STATE_PONG_Pong_WaitPing, P_PINGPONG_STATE_PONG_Pong_SendPong };

#line 33 "PingPong.p"
PRT_VALUE* P_PINGPONG_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
#line 33 "PingPong.p"
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
#line 33 "PingPong.p"
p_return:
    return _P_GEN_retval;
}

PRT_FUNDECL P_PINGPONG_FUNCTION_Anon_2 =
{
    NULL,
    &P_PINGPONG_Anon_IMPL_2,
    NULL
};


#line 38 "PingPong.p"
PRT_VALUE* P_PINGPONG_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
#line 38 "PingPong.p"
    PRT_VALUE** P_PINGPONG_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_m);
    PRT_VALUE* PTMP_tmp1_2 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_e);
    PRT_VALUE* PTMP_tmp2_1 = PrtMkDefaultValue(&P_PINGPONG_GEND_TYPE_e);
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
#line 38 "PingPong.p"
#line 39 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE_7 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_PINGPONG_LVALUE_7);
    *P_PINGPONG_LVALUE_7 = PrtCloneValue(*P_PINGPONG_VAR_payload);
    
#line 39 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE_8 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_PINGPONG_LVALUE_8);
    *P_PINGPONG_LVALUE_8 = PrtCloneValue((&P_PINGPONG_EVENT_Pong.value));
    
#line 39 "PingPong.p"
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_2), PTMP_tmp1_2, 0);
    *(&(PTMP_tmp1_2)) = NULL;
    
#line 40 "PingPong.p"
    PRT_VALUE** P_PINGPONG_LVALUE_9 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_PINGPONG_LVALUE_9);
    *P_PINGPONG_LVALUE_9 = PrtCloneValue((&P_PINGPONG_EVENT_Success.value));
    
#line 40 "PingPong.p"
    PrtFreeTriggerPayload(p_this);
    PrtRaise(p_this, PTMP_tmp2_1, 0);
    *(&(PTMP_tmp2_1)) = NULL;
    goto p_return;
    
p_return:
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_PINGPONG_FUNCTION_Anon_3 =
{
    NULL,
    &P_PINGPONG_Anon_IMPL_3,
    &P_PINGPONG_GEND_TYPE_m
};


PRT_FUNDECL* P_PINGPONG_PONG_METHODS[] = { &P_PINGPONG_FUNCTION_Anon_2, &P_PINGPONG_FUNCTION_Anon_3 };

#line 31 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_PONG_RECV_INNER_1[] = { &P_PINGPONG_EVENT_Ping, &P_PINGPONG_EVENT_Pong, &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_PONG_RECV_1 =
{
    3U,
    P_PINGPONG_PONG_RECV_INNER_1,
    NULL
};

#line 31 "PingPong.p"
PRT_EVENTDECL* P_PINGPONG_PONG_SEND_INNER[] = { &P_PINGPONG_EVENT_Ping, &P_PINGPONG_EVENT_Pong, &P_PINGPONG_EVENT_Success };
PRT_EVENTSETDECL P_PINGPONG_EVENTSET_PONG_SEND =
{
    3U,
    P_PINGPONG_PONG_SEND_INNER,
    NULL
};

#line 31 "PingPong.p"
PRT_MACHINEDECL P_PINGPONG_MACHINE_PONG = 
{
    1U,
    "PONG",
    &P_PINGPONG_EVENTSET_PONG_RECV_1,
    &P_PINGPONG_EVENTSET_PONG_SEND,
    NULL,
    0U,
    2U,
    2U,
    4294967295U,
    0U,
    NULL,
    P_PINGPONG_PONG_STATES,
    P_PINGPONG_PONG_METHODS
};

PRT_EVENTDECL* P_PINGPONG_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_PINGPONG_EVENT_Ping, &P_PINGPONG_EVENT_Pong, &P_PINGPONG_EVENT_Success };
PRT_MACHINEDECL* P_PINGPONG_ALL_MACHINES[] = { &P_PINGPONG_MACHINE_Main, &P_PINGPONG_MACHINE_PONG };
PRT_INTERFACEDECL* P_PINGPONG_ALL_INTERFACES[] = { &P_PINGPONG_I_Main, &P_PINGPONG_I_PONG };
PRT_FUNDECL* P_PINGPONG_ALL_FUNCTIONS[] = { NULL };
int P_PINGPONG_DefaultImpl_LME_0[] = { -1,1 };
int P_PINGPONG_DefaultImpl_LME_1[] = { -1,-1 };
int* P_PINGPONG_DefaultImpl_LINKMAP[] = { P_PINGPONG_DefaultImpl_LME_0, P_PINGPONG_DefaultImpl_LME_1 };
int P_PINGPONG_DefaultImpl_DEFMAP[] = { 0,1 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    5U,
    2U,
    2U,
    0U,
    0U,
    P_PINGPONG_ALL_EVENTS,
    P_PINGPONG_ALL_MACHINES,
    P_PINGPONG_ALL_INTERFACES,
    P_PINGPONG_ALL_FUNCTIONS,
    NULL,
    P_PINGPONG_DefaultImpl_LINKMAP,
    P_PINGPONG_DefaultImpl_DEFMAP
};

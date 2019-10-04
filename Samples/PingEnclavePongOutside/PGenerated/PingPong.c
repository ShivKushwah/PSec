#include "PingPong.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };

// Function implementation prototypes:
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
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_Success = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Success",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL* P_Ping_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Ping_RECV =
{
    4U,
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

PRT_EVENTDECL* P_Pong_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Pong_RECV =
{
    4U,
    P_Pong_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Pong =
{
    1U,
    "Pong",
    &P_GEND_TYPE_i,
    &P_EVENTSET_Pong_RECV
};

PRT_VARDECL P_Ping_VARS[] = {
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

PRT_EVENTDECL* P_Ping_SendingPing_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Ping_SendingPing_DEFERS =
{
    0U,
    P_Ping_SendingPing_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Ping_SendingPing_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Ping_SendingPing_TRANS =
{
    1U,
    P_Ping_SendingPing_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Ping_SendingPing_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Ping_SendingPing_DOS =
{
    0U,
    P_Ping_SendingPing_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 1, &P_EVENT_Success, 2, &_P_NO_OP }
};

#define P_STATE_Ping_Ping_SendingPing \
{ \
    "Ping.Ping_SendingPing", \
    1U, \
    0U, \
    &P_EVENTSET_Ping_SendingPing_DEFERS, \
    &P_EVENTSET_Ping_SendingPing_TRANS, \
    &P_EVENTSET_Ping_SendingPing_DOS, \
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
    { 2, &P_EVENT_Pong, 3, &_P_NO_OP }
};

#define P_STATE_Ping_Ping_WaitPong \
{ \
    "Ping.Ping_WaitPong", \
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

PRT_EVENTDECL* P_Done_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Done_TRANS =
{
    1U,
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

PRT_TRANSDECL P_TRANS_3[] =
{
    { 3, &P_EVENT_Success, 4, &_P_NO_OP }
};

#define P_STATE_Ping_Done \
{ \
    "Ping.Done", \
    1U, \
    0U, \
    &P_EVENTSET_Done_DEFERS, \
    &P_EVENTSET_Done_TRANS, \
    &P_EVENTSET_Done_DOS, \
    P_TRANS_3, \
    NULL, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_ReallyDone_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReallyDone_DEFERS =
{
    0U,
    P_ReallyDone_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReallyDone_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReallyDone_TRANS =
{
    0U,
    P_ReallyDone_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReallyDone_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReallyDone_DOS =
{
    0U,
    P_ReallyDone_DOS_INNER,
    NULL
};

#define P_STATE_Ping_ReallyDone \
{ \
    "Ping.ReallyDone", \
    0U, \
    0U, \
    &P_EVENTSET_ReallyDone_DEFERS, \
    &P_EVENTSET_ReallyDone_TRANS, \
    &P_EVENTSET_ReallyDone_DOS, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Ping_STATES[] = { P_STATE_Ping_Ping_Init, P_STATE_Ping_Ping_SendingPing, P_STATE_Ping_Ping_WaitPong, P_STATE_Ping_Done, P_STATE_Ping_ReallyDone };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp0, 0);
    *(&(PTMP_tmp0)) = NULL;
    goto p_return;
    
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
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_1 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_1);
    *P_LVALUE_1 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp0_1, 0);
    *(&(PTMP_tmp0_1)) = NULL;
    goto p_return_1;
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
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
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("Kirat");
    
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp0_2, 0);
    *(&(PTMP_tmp0_2)) = NULL;
    goto p_return_2;
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    NULL
};


PRT_FUNDECL* P_Ping_METHODS[] = { &P_FUNCTION_Anon, &P_FUNCTION_Anon_1, &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_Ping_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Ping_RECV_1 =
{
    4U,
    P_Ping_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Ping_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Ping_SEND =
{
    4U,
    P_Ping_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_Ping = 
{
    0U,
    "Ping",
    &P_EVENTSET_Ping_RECV_1,
    &P_EVENTSET_Ping_SEND,
    NULL,
    1U,
    5U,
    3U,
    4294967295U,
    0U,
    P_Ping_VARS,
    P_Ping_STATES,
    P_Ping_METHODS
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

PRT_TRANSDECL P_TRANS_4[] =
{
    { 0, &P_EVENT_Ping, 1, &_P_NO_OP }
};

#define P_STATE_Pong_Pong_WaitPing \
{ \
    "Pong.Pong_WaitPing", \
    1U, \
    0U, \
    &P_EVENTSET_Pong_WaitPing_DEFERS, \
    &P_EVENTSET_Pong_WaitPing_TRANS, \
    &P_EVENTSET_Pong_WaitPing_DOS, \
    P_TRANS_4, \
    NULL, \
    &P_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Pong_SendingPong_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Pong_SendingPong_DEFERS =
{
    0U,
    P_Pong_SendingPong_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Pong_SendingPong_TRANS_INNER[] = { &P_EVENT_Success };
PRT_EVENTSETDECL P_EVENTSET_Pong_SendingPong_TRANS =
{
    1U,
    P_Pong_SendingPong_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Pong_SendingPong_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Pong_SendingPong_DOS =
{
    0U,
    P_Pong_SendingPong_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_5[] =
{
    { 1, &P_EVENT_Success, 2, &_P_NO_OP }
};

#define P_STATE_Pong_Pong_SendingPong \
{ \
    "Pong.Pong_SendingPong", \
    1U, \
    0U, \
    &P_EVENTSET_Pong_SendingPong_DEFERS, \
    &P_EVENTSET_Pong_SendingPong_TRANS, \
    &P_EVENTSET_Pong_SendingPong_DOS, \
    P_TRANS_5, \
    NULL, \
    &P_FUNCTION_Anon_4, \
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

#define P_STATE_Pong_Done \
{ \
    "Pong.Done", \
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

PRT_STATEDECL P_Pong_STATES[] = { P_STATE_Pong_Pong_WaitPing, P_STATE_Pong_Pong_SendingPong, P_STATE_Pong_Done };

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_3: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_i
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtCloneValue((&P_EVENT_Success.value));
    
    PrtRaise(p_this, PTMP_tmp0_3, 0);
    *(&(PTMP_tmp0_3)) = NULL;
    goto p_return_4;
    
p_return_4: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    NULL
};


PRT_FUNDECL* P_Pong_METHODS[] = { &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4 };

PRT_EVENTDECL* P_Pong_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Pong_RECV_1 =
{
    4U,
    P_Pong_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Pong_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Pong_SEND =
{
    4U,
    P_Pong_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_Pong = 
{
    1U,
    "Pong",
    &P_EVENTSET_Pong_RECV_1,
    &P_EVENTSET_Pong_SEND,
    NULL,
    0U,
    3U,
    2U,
    4294967295U,
    0U,
    NULL,
    P_Pong_STATES,
    P_Pong_METHODS
};

PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Ping, &P_MACHINE_Pong };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Ping, &P_I_Pong };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { NULL };
int P_DefaultImpl_LME_0[] = { -1,-1 };
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

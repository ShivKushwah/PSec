#include "PingPongEnclave.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_TYPE P_GEND_TYPE_i_1 = { PRT_KIND_INT, { NULL } };
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
PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;


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
    &P_GEND_TYPE_n,
    &P_EVENTSET_SecureChild_RECV
};

PRT_VARDECL P_Coordinator_VARS[] = {
    { "s_int", &P_GEND_TYPE_i_1 },
    { "reg_int", &P_GEND_TYPE_i },
    { "s_bool", &P_GEND_TYPE_i_1 }
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
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 9 } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 8 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtCloneValue((&P_LIT_INT32));
    
    PRT_VALUE** P_LVALUE_1 = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE_1);
    *P_LVALUE_1 = PrtMkIntValue(-PrtPrimGetInt((&P_LIT_INT32)));
    
    {
        PRT_VALUE** P_LVALUE_2 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_2);
        *P_LVALUE_2 = PTMP_tmp0;
        PTMP_tmp0 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtMkIntValue(-PrtPrimGetInt((&P_LIT_INT32)));
    
    {
        PRT_VALUE** P_LVALUE_4 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_4);
        *P_LVALUE_4 = PTMP_tmp1;
        PTMP_tmp1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[1]) + PrtPrimGetInt((&P_LIT_INT32_1)));
    
    {
        PRT_VALUE** P_LVALUE_6 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_6);
        *P_LVALUE_6 = PTMP_tmp2;
        PTMP_tmp2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtMkIntValue(-PrtPrimGetInt(p_this->varValues[1]));
    
    {
        PRT_VALUE** P_LVALUE_8 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_8);
        *P_LVALUE_8 = PTMP_tmp3;
        PTMP_tmp3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtMkIntValue(-PrtPrimGetInt(p_this->varValues[0]));
    
    {
        PRT_VALUE** P_LVALUE_10 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_10);
        *P_LVALUE_10 = PTMP_tmp4;
        PTMP_tmp4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_11 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[0], (&P_LIT_INT32)));
    
    if (PrtPrimGetBool(PTMP_tmp5))
    {
        PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp6);
        PrtFreeValue(*P_LVALUE_13);
        *P_LVALUE_13 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[0]) + PrtPrimGetInt((&P_LIT_INT32_1)));
        
        {
            PRT_VALUE** P_LVALUE_14 = &(p_this->varValues[0]);
            PrtFreeValue(*P_LVALUE_14);
            *P_LVALUE_14 = PTMP_tmp6;
            PTMP_tmp6 = NULL;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_15 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_15);
        *P_LVALUE_15 = PrtCloneValue((&P_LIT_INT32_2));
        
    }
    
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[0], (&P_LIT_INT32)));
    
    if (PrtPrimGetBool(PTMP_tmp7))
    {
        PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp8);
        PrtFreeValue(*P_LVALUE_17);
        *P_LVALUE_17 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[0]) + PrtPrimGetInt((&P_LIT_INT32_1)));
        
        {
            PRT_VALUE** P_LVALUE_18 = &(p_this->varValues[0]);
            PrtFreeValue(*P_LVALUE_18);
            *P_LVALUE_18 = PTMP_tmp8;
            PTMP_tmp8 = NULL;
        }
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], (&P_LIT_INT32)));
    
    if (PrtPrimGetBool(PTMP_tmp9))
    {
        PRT_VALUE** P_LVALUE_20 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_20);
        *P_LVALUE_20 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[0], (&P_LIT_INT32)));
    
    if (PrtPrimGetBool(PTMP_tmp10))
    {
        PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp11);
        PrtFreeValue(*P_LVALUE_22);
        *P_LVALUE_22 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[0]) + PrtPrimGetInt((&P_LIT_INT32_1)));
        
        {
            PRT_VALUE** P_LVALUE_23 = &(p_this->varValues[0]);
            PrtFreeValue(*P_LVALUE_23);
            *P_LVALUE_23 = PTMP_tmp11;
            PTMP_tmp11 = NULL;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp12);
        PrtFreeValue(*P_LVALUE_24);
        *P_LVALUE_24 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[0], (&P_LIT_INT32_4)));
        
        if (PrtPrimGetBool(PTMP_tmp12))
        {
            PRT_VALUE** P_LVALUE_25 = &(p_this->varValues[0]);
            PrtFreeValue(*P_LVALUE_25);
            *P_LVALUE_25 = PrtCloneValue((&P_LIT_INT32_3));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_26 = &(p_this->varValues[0]);
            PrtFreeValue(*P_LVALUE_26);
            *P_LVALUE_26 = PrtCloneValue((&P_LIT_INT32_2));
            
        }
        
        
    }
    
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp13);
        PrtFreeValue(*P_LVALUE_27);
        *P_LVALUE_27 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[0], (&P_LIT_INT32)));
        
        PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp14);
        PrtFreeValue(*P_LVALUE_28);
        *P_LVALUE_28 = PrtCloneValue(PTMP_tmp13);
        
        if (PrtPrimGetBool(PTMP_tmp14))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp15);
        PrtFreeValue(*P_LVALUE_29);
        *P_LVALUE_29 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[0]) + PrtPrimGetInt((&P_LIT_INT32_1)));
        
        {
            PRT_VALUE** P_LVALUE_30 = &(p_this->varValues[0]);
            PrtFreeValue(*P_LVALUE_30);
            *P_LVALUE_30 = PTMP_tmp15;
            PTMP_tmp15 = NULL;
        }
        
    }
    
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp16);
        PrtFreeValue(*P_LVALUE_31);
        *P_LVALUE_31 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[0], (&P_LIT_INT32)));
        
        PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp17);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PrtCloneValue(PTMP_tmp16);
        
        if (PrtPrimGetBool(PTMP_tmp17))
        {
        }
        
        else
        {
            break;
            
        }
        
        
    }
    
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp18);
        PrtFreeValue(*P_LVALUE_33);
        *P_LVALUE_33 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], (&P_LIT_INT32)));
        
        PRT_VALUE** P_LVALUE_34 = &(PTMP_tmp19);
        PrtFreeValue(*P_LVALUE_34);
        *P_LVALUE_34 = PrtCloneValue(PTMP_tmp18);
        
        if (PrtPrimGetBool(PTMP_tmp19))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp20);
        PrtFreeValue(*P_LVALUE_35);
        *P_LVALUE_35 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[0]) + PrtPrimGetInt((&P_LIT_INT32_1)));
        
        {
            PRT_VALUE** P_LVALUE_36 = &(p_this->varValues[0]);
            PrtFreeValue(*P_LVALUE_36);
            *P_LVALUE_36 = PTMP_tmp20;
            PTMP_tmp20 = NULL;
        }
        
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

PRT_MACHINEDECL P_MACHINE_Coordinator = 
{
    0U,
    "Coordinator",
    &P_EVENTSET_Coordinator_RECV_1,
    &P_EVENTSET_Coordinator_SEND,
    NULL,
    3U,
    2U,
    2U,
    4294967295U,
    0U,
    P_Coordinator_VARS,
    P_Coordinator_STATES,
    P_Coordinator_METHODS,
    PRT_TRUE
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

#define P_STATE_Pong_Initial \
{ \
    "Pong.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_1, \
    &P_EVENTSET_Initial_TRANS_1, \
    &P_EVENTSET_Initial_DOS_1, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Pong_STATES[] = { P_STATE_Pong_Initial };

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

PRT_MACHINEDECL P_MACHINE_Pong = 
{
    1U,
    "Pong",
    &P_EVENTSET_Pong_RECV_1,
    &P_EVENTSET_Pong_SEND,
    NULL,
    0U,
    1U,
    0U,
    4294967295U,
    0U,
    NULL,
    P_Pong_STATES,
    NULL,
    PRT_TRUE
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_2 =
{
    0U,
    P_Initial_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_2 =
{
    0U,
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

#define P_STATE_SecureChild_Initial \
{ \
    "SecureChild.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_2, \
    &P_EVENTSET_Initial_TRANS_2, \
    &P_EVENTSET_Initial_DOS_2, \
    NULL, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureChild_STATES[] = { P_STATE_SecureChild_Initial };

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
    0U,
    1U,
    0U,
    4294967295U,
    0U,
    NULL,
    P_SecureChild_STATES,
    NULL,
    PRT_TRUE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_UntrustedEventFromPing, &P_EVENT_Success };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Coordinator, &P_MACHINE_Pong, &P_MACHINE_SecureChild };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Coordinator, &P_I_Pong, &P_I_SecureChild };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType };
int P_DefaultImpl_LME_0[] = { -1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,-1 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    6U,
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

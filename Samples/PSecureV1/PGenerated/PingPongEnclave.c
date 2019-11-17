#include "PingPongEnclave.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_TYPE P_GEND_TYPE_i_1 = { PRT_KIND_INT, { NULL } };
static PRT_TYPE P_GEND_TYPE_b = { PRT_KIND_BOOL, { NULL } };
static PRT_TYPE P_GEND_TYPE_b_1 = { PRT_KIND_BOOL, { NULL } };
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


PRT_EVENTDECL* P_Coordinator_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Coordinator_RECV =
{
    4U,
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

PRT_VARDECL P_Coordinator_VARS[] = {
    { "sidhu", &P_GEND_TYPE_i },
    { "har", &P_GEND_TYPE_i_1 },
    { "b", &P_GEND_TYPE_b },
    { "bb", &P_GEND_TYPE_b_1 }
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

#define P_STATE_Coordinator_Initial \
{ \
    "Coordinator.Initial", \
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

PRT_STATEDECL P_Coordinator_STATES[] = { P_STATE_Coordinator_Initial };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_kirat = PrtMkDefaultValue(&P_GEND_TYPE_i_1);
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
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 5 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 8 } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 9 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 17 } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 6 } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE P_LIT_BOOLEAN_1 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtMkIntValue(PrtPrimGetInt((&P_LIT_INT32)) + PrtPrimGetInt((&P_LIT_INT32_1)));
    
    PRT_VALUE** P_LVALUE_1 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_1);
    *P_LVALUE_1 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp0) + PrtPrimGetInt((&P_LIT_INT32_2)));
    
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp1) + PrtPrimGetInt((&P_LIT_INT32_3)));
    
    {
        PRT_VALUE** P_LVALUE_3 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_3);
        *P_LVALUE_3 = PTMP_tmp2;
        PTMP_tmp2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_4 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtCloneValue((&P_LIT_INT32_4));
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = PrtMkIntValue(PrtPrimGetInt(P_VAR_kirat) + PrtPrimGetInt(p_this->varValues[1]));
    
    {
        PRT_VALUE** P_LVALUE_6 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_6);
        *P_LVALUE_6 = PTMP_tmp3;
        PTMP_tmp3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_7 = &(P_VAR_kirat);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_8 = &(p_this->varValues[2]);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtCloneValue((&P_LIT_BOOLEAN));
    
    PRT_VALUE** P_LVALUE_9 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue((&P_LIT_BOOLEAN_1));
    
    PRT_VALUE** P_LVALUE_10 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue((&P_LIT_BOOLEAN));
    
    if (PrtPrimGetBool(PTMP_tmp4))
    {
        PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp4);
        PrtFreeValue(*P_LVALUE_12);
        *P_LVALUE_12 = PrtCloneValue((&P_LIT_BOOLEAN_1));
        
    }
    
    
    {
        PRT_VALUE** P_LVALUE_13 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_13);
        *P_LVALUE_13 = PTMP_tmp4;
        PTMP_tmp4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtCloneValue(p_this->varValues[3]);
    
    if (PrtPrimGetBool(PTMP_tmp5))
    {
        PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp5);
        PrtFreeValue(*P_LVALUE_15);
        *P_LVALUE_15 = PrtCloneValue((&P_LIT_BOOLEAN_1));
        
    }
    
    
    {
        PRT_VALUE** P_LVALUE_16 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_16);
        *P_LVALUE_16 = PTMP_tmp5;
        PTMP_tmp5 = NULL;
    }
    
    if (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PrtPrintf("Kirat");
        
    }
    
    else
    {
    }
    
    
    if (PrtPrimGetBool(p_this->varValues[2]))
    {
        PRT_VALUE** P_LVALUE_17 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_17);
        *P_LVALUE_17 = PrtCloneValue((&P_LIT_INT32));
        
        PRT_VALUE** P_LVALUE_18 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_18);
        *P_LVALUE_18 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_19 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_19);
        *P_LVALUE_19 = PrtCloneValue((&P_LIT_INT32_5));
        
    }
    
    
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_kirat, (&P_LIT_INT32)));
    
    if (PrtPrimGetBool(PTMP_tmp6))
    {
        PRT_VALUE** P_LVALUE_21 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_21);
        *P_LVALUE_21 = PrtCloneValue((&P_LIT_INT32_2));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_22 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_22);
        *P_LVALUE_22 = PrtCloneValue((&P_LIT_INT32_5));
        
    }
    
    
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_kirat, (&P_LIT_INT32)));
    
    if (PrtPrimGetBool(PTMP_tmp7))
    {
        PRT_VALUE** P_LVALUE_24 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_24);
        *P_LVALUE_24 = PrtCloneValue((&P_LIT_INT32_2));
        
        PRT_VALUE** P_LVALUE_25 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_25);
        *P_LVALUE_25 = PrtCloneValue((&P_LIT_INT32));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_26 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_26);
        *P_LVALUE_26 = PrtCloneValue((&P_LIT_INT32_5));
        
        PRT_VALUE** P_LVALUE_27 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_27);
        *P_LVALUE_27 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_kirat, p_this->varValues[0]));
    
    if (PrtPrimGetBool(PTMP_tmp8))
    {
        PRT_VALUE** P_LVALUE_29 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_29);
        *P_LVALUE_29 = PrtCloneValue((&P_LIT_INT32_2));
        
        PRT_VALUE** P_LVALUE_30 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_30);
        *P_LVALUE_30 = PrtCloneValue((&P_LIT_INT32));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_31 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_31);
        *P_LVALUE_31 = PrtCloneValue((&P_LIT_INT32_5));
        
        PRT_VALUE** P_LVALUE_32 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    
    PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_33);
    *P_LVALUE_33 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[2], p_this->varValues[3]));
    
    if (PrtPrimGetBool(PTMP_tmp9))
    {
        PRT_VALUE** P_LVALUE_34 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_34);
        *P_LVALUE_34 = PrtCloneValue((&P_LIT_INT32_2));
        
        PRT_VALUE** P_LVALUE_35 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_35);
        *P_LVALUE_35 = PrtCloneValue((&P_LIT_INT32));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_36 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_36);
        *P_LVALUE_36 = PrtCloneValue((&P_LIT_INT32_5));
        
        PRT_VALUE** P_LVALUE_37 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_37);
        *P_LVALUE_37 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    
p_return: ;
    PrtFreeValue(P_VAR_kirat); P_VAR_kirat = NULL;
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
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL
};


PRT_FUNDECL* P_Coordinator_METHODS[] = { &P_FUNCTION_Anon };

PRT_EVENTDECL* P_Coordinator_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Coordinator_RECV_1 =
{
    4U,
    P_Coordinator_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Coordinator_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Coordinator_SEND =
{
    4U,
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
    4U,
    1U,
    1U,
    4294967295U,
    0U,
    P_Coordinator_VARS,
    P_Coordinator_STATES,
    P_Coordinator_METHODS,
    PRT_TRUE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Coordinator };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Coordinator };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType };
int P_DefaultImpl_LME_0[] = { -1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0 };
int P_DefaultImpl_DEFMAP[] = { 0 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    5U,
    1U,
    1U,
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

#include "PingPongEnclave.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
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
static PRT_TYPE P_GEND_TYPE_i_1 = { PRT_KIND_INT, { NULL } };
static PRT_TYPE P_GEND_TYPE_b = { PRT_KIND_BOOL, { NULL } };
static PRT_TYPE P_GEND_TYPE_b_1 = { PRT_KIND_BOOL, { NULL } };

// Function implementation prototypes:
PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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
    &P_GEND_TYPE_n,
    &P_EVENTSET_Pong_RECV
};

PRT_EVENTDECL* P_SecureChild_RECV_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureChild_RECV =
{
    4U,
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
    { "PongSecureChild", &P_GEND_TYPE_StringType },
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
    PRT_VALUE* PTMP_tmp10 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    PRT_VALUE* PTMP_tmp17 = NULL;
    PRT_VALUE* PTMP_tmp18 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 5 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 8 } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 9 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 17 } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 6 } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE P_LIT_BOOLEAN_1 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    _P_GEN_funargs[0] = "Pong";
    *P_LVALUE = ((_P_GEN_funval = P_CreateMachineSecureChild_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
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
    *P_LVALUE_2 = PrtMkIntValue(PrtPrimGetInt((&P_LIT_INT32)) + PrtPrimGetInt((&P_LIT_INT32_1)));
    
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp1) + PrtPrimGetInt((&P_LIT_INT32_2)));
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp2) + PrtPrimGetInt((&P_LIT_INT32_3)));
    
    {
        PRT_VALUE** P_LVALUE_5 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_5);
        *P_LVALUE_5 = PTMP_tmp3;
        PTMP_tmp3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_6 = &(p_this->varValues[2]);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = PrtCloneValue((&P_LIT_INT32_4));
    
    PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtMkIntValue(PrtPrimGetInt(P_VAR_kirat) + PrtPrimGetInt(p_this->varValues[2]));
    
    {
        PRT_VALUE** P_LVALUE_8 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_8);
        *P_LVALUE_8 = PTMP_tmp4;
        PTMP_tmp4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_9 = &(P_VAR_kirat);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_10 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue((&P_LIT_BOOLEAN));
    
    PRT_VALUE** P_LVALUE_11 = &(p_this->varValues[4]);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue((&P_LIT_BOOLEAN_1));
    
    PRT_VALUE** P_LVALUE_12 = &(p_this->varValues[4]);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue((&P_LIT_BOOLEAN));
    
    if (PrtPrimGetBool(PTMP_tmp5))
    {
        PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp5);
        PrtFreeValue(*P_LVALUE_14);
        *P_LVALUE_14 = PrtCloneValue((&P_LIT_BOOLEAN_1));
        
    }
    
    
    {
        PRT_VALUE** P_LVALUE_15 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_15);
        *P_LVALUE_15 = PTMP_tmp5;
        PTMP_tmp5 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtCloneValue(p_this->varValues[4]);
    
    if (PrtPrimGetBool(PTMP_tmp6))
    {
        PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp6);
        PrtFreeValue(*P_LVALUE_17);
        *P_LVALUE_17 = PrtCloneValue((&P_LIT_BOOLEAN_1));
        
    }
    
    
    {
        PRT_VALUE** P_LVALUE_18 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_18);
        *P_LVALUE_18 = PTMP_tmp6;
        PTMP_tmp6 = NULL;
    }
    
    if (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PrtPrintf("Kirat");
        
    }
    
    else
    {
    }
    
    
    if (PrtPrimGetBool(p_this->varValues[3]))
    {
        PRT_VALUE** P_LVALUE_19 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_19);
        *P_LVALUE_19 = PrtCloneValue((&P_LIT_INT32));
        
        PRT_VALUE** P_LVALUE_20 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_20);
        *P_LVALUE_20 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_21 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_21);
        *P_LVALUE_21 = PrtCloneValue((&P_LIT_INT32_5));
        
    }
    
    
    PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_kirat, (&P_LIT_INT32)));
    
    if (PrtPrimGetBool(PTMP_tmp7))
    {
        PRT_VALUE** P_LVALUE_23 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_23);
        *P_LVALUE_23 = PrtCloneValue((&P_LIT_INT32_2));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_24 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_24);
        *P_LVALUE_24 = PrtCloneValue((&P_LIT_INT32_5));
        
    }
    
    
    PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_kirat, (&P_LIT_INT32)));
    
    if (PrtPrimGetBool(PTMP_tmp8))
    {
        PRT_VALUE** P_LVALUE_26 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_26);
        *P_LVALUE_26 = PrtCloneValue((&P_LIT_INT32_2));
        
        PRT_VALUE** P_LVALUE_27 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_27);
        *P_LVALUE_27 = PrtCloneValue((&P_LIT_INT32));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_28 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_28);
        *P_LVALUE_28 = PrtCloneValue((&P_LIT_INT32_5));
        
        PRT_VALUE** P_LVALUE_29 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_29);
        *P_LVALUE_29 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_kirat, p_this->varValues[1]));
    
    if (PrtPrimGetBool(PTMP_tmp9))
    {
        PRT_VALUE** P_LVALUE_31 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_31);
        *P_LVALUE_31 = PrtCloneValue((&P_LIT_INT32_2));
        
        PRT_VALUE** P_LVALUE_32 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PrtCloneValue((&P_LIT_INT32));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_33 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_33);
        *P_LVALUE_33 = PrtCloneValue((&P_LIT_INT32_5));
        
        PRT_VALUE** P_LVALUE_34 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_34);
        *P_LVALUE_34 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    
    PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_35);
    *P_LVALUE_35 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[3], p_this->varValues[4]));
    
    if (PrtPrimGetBool(PTMP_tmp10))
    {
        PRT_VALUE** P_LVALUE_36 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_36);
        *P_LVALUE_36 = PrtCloneValue((&P_LIT_INT32_2));
        
        PRT_VALUE** P_LVALUE_37 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_37);
        *P_LVALUE_37 = PrtCloneValue((&P_LIT_INT32));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_38 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_38);
        *P_LVALUE_38 = PrtCloneValue((&P_LIT_INT32_5));
        
        PRT_VALUE** P_LVALUE_39 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_39);
        *P_LVALUE_39 = PrtCloneValue((&P_LIT_INT32_3));
        
    }
    
    
    PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp11);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[3], p_this->varValues[4]));
    
    if (PrtPrimGetBool(PTMP_tmp11))
    {
        PRT_VALUE** P_LVALUE_41 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_41);
        *P_LVALUE_41 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp12);
        PrtFreeValue(*P_LVALUE_42);
        *P_LVALUE_42 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_kirat, p_this->varValues[1]));
        
        if (PrtPrimGetBool(PTMP_tmp12))
        {
            PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp13);
            PrtFreeValue(*P_LVALUE_43);
            *P_LVALUE_43 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[1]) - PrtPrimGetInt((&P_LIT_INT32_6)));
            
            {
                PRT_VALUE** P_LVALUE_44 = &(P_VAR_kirat);
                PrtFreeValue(*P_LVALUE_44);
                *P_LVALUE_44 = PTMP_tmp13;
                PTMP_tmp13 = NULL;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_45 = &(P_VAR_kirat);
            PrtFreeValue(*P_LVALUE_45);
            *P_LVALUE_45 = PrtCloneValue((&P_LIT_INT32_4));
            
        }
        
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp14);
        PrtFreeValue(*P_LVALUE_46);
        *P_LVALUE_46 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[1]) + PrtPrimGetInt((&P_LIT_INT32_6)));
        
        {
            PRT_VALUE** P_LVALUE_47 = &(P_VAR_kirat);
            PrtFreeValue(*P_LVALUE_47);
            *P_LVALUE_47 = PTMP_tmp14;
            PTMP_tmp14 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_48 = &(PTMP_tmp15);
    PrtFreeValue(*P_LVALUE_48);
    *P_LVALUE_48 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[3], p_this->varValues[3]));
    
    if (PrtPrimGetBool(PTMP_tmp15))
    {
        PRT_VALUE** P_LVALUE_49 = &(P_VAR_kirat);
        PrtFreeValue(*P_LVALUE_49);
        *P_LVALUE_49 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp16);
        PrtFreeValue(*P_LVALUE_50);
        *P_LVALUE_50 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], p_this->varValues[1]));
        
        if (PrtPrimGetBool(PTMP_tmp16))
        {
            PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp17);
            PrtFreeValue(*P_LVALUE_51);
            *P_LVALUE_51 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[1]) - PrtPrimGetInt((&P_LIT_INT32_6)));
            
            {
                PRT_VALUE** P_LVALUE_52 = &(p_this->varValues[1]);
                PrtFreeValue(*P_LVALUE_52);
                *P_LVALUE_52 = PTMP_tmp17;
                PTMP_tmp17 = NULL;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_53 = &(p_this->varValues[1]);
            PrtFreeValue(*P_LVALUE_53);
            *P_LVALUE_53 = PrtCloneValue((&P_LIT_INT32_4));
            
        }
        
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp18);
        PrtFreeValue(*P_LVALUE_54);
        *P_LVALUE_54 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[1]) + PrtPrimGetInt((&P_LIT_INT32_6)));
        
        {
            PRT_VALUE** P_LVALUE_55 = &(P_VAR_kirat);
            PrtFreeValue(*P_LVALUE_55);
            *P_LVALUE_55 = PTMP_tmp18;
            PTMP_tmp18 = NULL;
        }
        
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
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    PrtFreeValue(PTMP_tmp17); PTMP_tmp17 = NULL;
    PrtFreeValue(PTMP_tmp18); PTMP_tmp18 = NULL;
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

PRT_UINT32 P_Coordinator_CREATES_ARR[] = { 1 };
PRT_INTERFACESETDECL P_Coordinator_CREATES = { 1, P_Coordinator_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_Coordinator = 
{
    0U,
    "Coordinator",
    &P_EVENTSET_Coordinator_RECV_1,
    &P_EVENTSET_Coordinator_SEND,
    &P_Coordinator_CREATES,
    5U,
    1U,
    1U,
    4294967295U,
    0U,
    P_Coordinator_VARS,
    P_Coordinator_STATES,
    P_Coordinator_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_Pong_VARS[] = {
    { "secureChildRegular", &P_GEND_TYPE_StringType },
    { "sBool", &P_GEND_TYPE_b_1 }
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

PRT_TRANSDECL P_TRANS[] =
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
    P_TRANS, \
    NULL, \
    &P_FUNCTION_Anon_1, \
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

PRT_TRANSDECL P_TRANS_1[] =
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
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Pong_STATES[] = { P_STATE_Pong_Initial, P_STATE_Pong_Pong_SendingPong, P_STATE_Pong_Done };

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_kirat_1 = PrtMkDefaultValue(&P_GEND_TYPE_i_1);
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_7 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_8 = { PRT_VALUE_KIND_INT, { .nt = 5 } };
    PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = PrtMkIntValue(PrtPrimGetInt((&P_LIT_INT32_7)) + PrtPrimGetInt((&P_LIT_INT32_8)));
    
    {
        PRT_VALUE** P_LVALUE_57 = &(P_VAR_kirat_1);
        PrtFreeValue(*P_LVALUE_57);
        *P_LVALUE_57 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_58);
    _P_GEN_funargs[0] = "SecureChild";
    *P_LVALUE_58 = ((_P_GEN_funval = P_CreateMachineSecureChild_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_59 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_59);
        *P_LVALUE_59 = PTMP_tmp1_1;
        PTMP_tmp1_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_60 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_60);
    *P_LVALUE_60 = PrtCloneValue(p_this->varValues[0]);
    
    _P_GEN_funargs[0] = &(PTMP_tmp2_1);
    PrtFreeValue(P_PrintString_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp2_1);
    PTMP_tmp2_1 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PRT_VALUE** P_LVALUE_61 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_61);
    *P_LVALUE_61 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_62 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_62);
    *P_LVALUE_62 = PrtCloneValue((&P_EVENT_Pong.value));
    
    _P_GEN_funargs[0] = &(PTMP_tmp3_1);
    _P_GEN_funargs[1] = &(PTMP_tmp4_1);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PRT_VALUE** P_LVALUE_63 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_63);
    *P_LVALUE_63 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_64 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_64);
    *P_LVALUE_64 = PrtCloneValue((&P_EVENT_Pong.value));
    
    _P_GEN_funargs[0] = &(PTMP_tmp5_1);
    _P_GEN_funargs[1] = &(PTMP_tmp6_1);
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
    PrtFreeValue(P_VAR_kirat_1); P_VAR_kirat_1 = NULL;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
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
    PRT_VALUE** P_LVALUE_65 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_65);
    *P_LVALUE_65 = PrtCloneValue((&P_EVENT_Success.value));
    
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


PRT_FUNDECL* P_Pong_METHODS[] = { &P_FUNCTION_Anon_1, &P_FUNCTION_Anon_2 };

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
    3U,
    2U,
    4294967295U,
    0U,
    P_Pong_VARS,
    P_Pong_STATES,
    P_Pong_METHODS,
    PRT_TRUE
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
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Next_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Next_DEFERS =
{
    0U,
    P_Next_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Next_TRANS_INNER[] = { &P_EVENT_Pong };
PRT_EVENTSETDECL P_EVENTSET_Next_TRANS =
{
    1U,
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

PRT_TRANSDECL P_TRANS_3[] =
{
    { 1, &P_EVENT_Pong, 2, &_P_NO_OP }
};

#define P_STATE_SecureChild_Next \
{ \
    "SecureChild.Next", \
    1U, \
    0U, \
    &P_EVENTSET_Next_DEFERS, \
    &P_EVENTSET_Next_TRANS, \
    &P_EVENTSET_Next_DOS, \
    P_TRANS_3, \
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

PRT_EVENTDECL* P_SecureChild_RECV_INNER_1[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureChild_RECV_1 =
{
    4U,
    P_SecureChild_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureChild_SEND_INNER[] = { &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureChild_SEND =
{
    4U,
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
    3U,
    0U,
    4294967295U,
    0U,
    NULL,
    P_SecureChild_STATES,
    NULL,
    PRT_TRUE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_Success };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Coordinator, &P_MACHINE_Pong, &P_MACHINE_SecureChild };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Coordinator, &P_I_Pong, &P_I_SecureChild };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType };
int P_DefaultImpl_LME_0[] = { -1,1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,2 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    5U,
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

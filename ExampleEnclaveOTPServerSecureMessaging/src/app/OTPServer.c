#include "OTPServer.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_m, &P_GEND_TYPE_i };
static PRT_TUPTYPE P_TUP = { 2U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T2mi = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE P_GEND_TYPE_a = { PRT_KIND_ANY, { NULL } };
static PRT_TYPE P_GEND_TYPE_R = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE* P_TUP_T_1[] = { &P_GEND_TYPE_R, &P_GEND_TYPE_i };
static PRT_TUPTYPE P_TUP_1 = { 2U, P_TUP_T_1 };
static PRT_TYPE P_GEND_TYPE_T2Ri = { PRT_KIND_TUPLE, { .tuple = &P_TUP_1 } };

// Function implementation prototypes:
PRT_VALUE* P_SaveOTPSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetOTPSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_EnclaveCallTwo_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_EnclaveOneSendSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_EnclaveTwoGenerateOTPCode_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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


PRT_EVENTDECL P_EVENT_OTPSecretMsg = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "OTPSecretMsg",
    4294967295U,
    &P_GEND_TYPE_T2mi
};

PRT_EVENTDECL P_EVENT_OTPSecretReceived = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "OTPSecretReceived",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_OTPCodeMsg = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "OTPCodeMsg",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_OTPCodeValidated = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "OTPCodeValidated",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_OTPCodeFailed = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "OTPCodeFailed",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_FUNDECL P_FUNCTION_SaveOTPSecret =
{
    "SaveOTPSecret",
    &P_SaveOTPSecret_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetOTPSecret =
{
    "GetOTPSecret",
    &P_GetOTPSecret_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_EnclaveCallTwo =
{
    "EnclaveCallTwo",
    &P_EnclaveCallTwo_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_EnclaveOneSendSecret =
{
    "EnclaveOneSendSecret",
    &P_EnclaveOneSendSecret_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_EnclaveTwoGenerateOTPCode =
{
    "EnclaveTwoGenerateOTPCode",
    &P_EnclaveTwoGenerateOTPCode_IMPL,
    NULL
};


PRT_EVENTDECL* P_BANK_SERVER_RECV_INNER[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BANK_SERVER_RECV =
{
    6U,
    P_BANK_SERVER_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_BANK_SERVER =
{
    0U,
    "BANK_SERVER",
    &P_GEND_TYPE_a,
    &P_EVENTSET_BANK_SERVER_RECV
};

PRT_EVENTDECL* P_CLIENT_OTP_GENERATOR_RECV_INNER[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_CLIENT_OTP_GENERATOR_RECV =
{
    6U,
    P_CLIENT_OTP_GENERATOR_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_CLIENT_OTP_GENERATOR =
{
    1U,
    "CLIENT_OTP_GENERATOR",
    &P_GEND_TYPE_n,
    &P_EVENTSET_CLIENT_OTP_GENERATOR_RECV
};

PRT_EVENTDECL* P_IntializerMachine_RECV_INNER[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_IntializerMachine_RECV =
{
    6U,
    P_IntializerMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_IntializerMachine =
{
    2U,
    "IntializerMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_IntializerMachine_RECV
};

PRT_VARDECL P_BANK_SERVER_VARS[] = {
    { "clientOtpGenerator", &P_GEND_TYPE_m },
    { "secret", &P_GEND_TYPE_i }
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

#define P_STATE_BANK_SERVER_Init \
{ \
    "BANK_SERVER.Init", \
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

PRT_EVENTDECL* P_GenerateOTPSecret_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_GenerateOTPSecret_DEFERS =
{
    0U,
    P_GenerateOTPSecret_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_GenerateOTPSecret_TRANS_INNER[] = { &P_EVENT_OTPSecretReceived };
PRT_EVENTSETDECL P_EVENTSET_GenerateOTPSecret_TRANS =
{
    1U,
    P_GenerateOTPSecret_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_GenerateOTPSecret_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_GenerateOTPSecret_DOS =
{
    0U,
    P_GenerateOTPSecret_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 1, &P_EVENT_OTPSecretReceived, 2, &_P_NO_OP }
};

#define P_STATE_BANK_SERVER_GenerateOTPSecret \
{ \
    "BANK_SERVER.GenerateOTPSecret", \
    1U, \
    0U, \
    &P_EVENTSET_GenerateOTPSecret_DEFERS, \
    &P_EVENTSET_GenerateOTPSecret_TRANS, \
    &P_EVENTSET_GenerateOTPSecret_DOS, \
    P_TRANS, \
    NULL, \
    &P_FUNCTION_Anon_1, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitOTPCode_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitOTPCode_DEFERS =
{
    0U,
    P_WaitOTPCode_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitOTPCode_TRANS_INNER[] = { &P_EVENT_OTPCodeMsg };
PRT_EVENTSETDECL P_EVENTSET_WaitOTPCode_TRANS =
{
    1U,
    P_WaitOTPCode_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitOTPCode_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitOTPCode_DOS =
{
    0U,
    P_WaitOTPCode_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 2, &P_EVENT_OTPCodeMsg, 3, &_P_NO_OP }
};

#define P_STATE_BANK_SERVER_WaitOTPCode \
{ \
    "BANK_SERVER.WaitOTPCode", \
    1U, \
    0U, \
    &P_EVENTSET_WaitOTPCode_DEFERS, \
    &P_EVENTSET_WaitOTPCode_TRANS, \
    &P_EVENTSET_WaitOTPCode_DOS, \
    P_TRANS_1, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_ValidateOTPCode_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ValidateOTPCode_DEFERS =
{
    0U,
    P_ValidateOTPCode_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_ValidateOTPCode_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ValidateOTPCode_TRANS =
{
    0U,
    P_ValidateOTPCode_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_ValidateOTPCode_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ValidateOTPCode_DOS =
{
    0U,
    P_ValidateOTPCode_DOS_INNER,
    NULL
};

#define P_STATE_BANK_SERVER_ValidateOTPCode \
{ \
    "BANK_SERVER.ValidateOTPCode", \
    0U, \
    0U, \
    &P_EVENTSET_ValidateOTPCode_DEFERS, \
    &P_EVENTSET_ValidateOTPCode_TRANS, \
    &P_EVENTSET_ValidateOTPCode_DOS, \
    NULL, \
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

#define P_STATE_BANK_SERVER_Done \
{ \
    "BANK_SERVER.Done", \
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

PRT_STATEDECL P_BANK_SERVER_STATES[] = { P_STATE_BANK_SERVER_Init, P_STATE_BANK_SERVER_GenerateOTPSecret, P_STATE_BANK_SERVER_WaitOTPCode, P_STATE_BANK_SERVER_ValidateOTPCode, P_STATE_BANK_SERVER_Done };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtCloneValue(PrtCastValue(*P_VAR_payload, &P_GEND_TYPE_m));
    
    {
        PRT_VALUE** P_LVALUE_1 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_1);
        *P_LVALUE_1 = PTMP_tmp0;
        PTMP_tmp0 = NULL;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    &P_GEND_TYPE_a
};


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
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 12344 } };
    PRT_VALUE** P_LVALUE_2 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = PrtCloneValue((&P_LIT_INT32));
    
    PrtFreeValue(P_EnclaveCallTwo_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PrtFreeValue(P_EnclaveOneSendSecret_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtCloneValue((&P_EVENT_OTPSecretMsg.value));
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = (PrtMkTuple(&P_GEND_TYPE_T2Ri, &(PTMP_tmp2), &(PTMP_tmp3)));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_1), PTMP_tmp1, 1, &(PTMP_tmp4));
    *(&(PTMP_tmp1)) = NULL;
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


PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 12345 } };
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtMkBoolValue(PrtIsEqualValue(*P_VAR_payload_1, (&P_LIT_INT32_1)));
    
    if (PrtPrimGetBool(PTMP_tmp0_2))
    {
        PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp1_1);
        PrtFreeValue(*P_LVALUE_9);
        *P_LVALUE_9 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp2_1);
        PrtFreeValue(*P_LVALUE_10);
        *P_LVALUE_10 = PrtCloneValue((&P_EVENT_OTPCodeValidated.value));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_1), PTMP_tmp2_1, 0);
        *(&(PTMP_tmp2_1)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_2;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_2;
        }
        
        PrtGoto(p_this, 4U, 0);
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp3_1);
        PrtFreeValue(*P_LVALUE_11);
        *P_LVALUE_11 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp4_1);
        PrtFreeValue(*P_LVALUE_12);
        *P_LVALUE_12 = PrtCloneValue((&P_EVENT_OTPCodeFailed.value));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp3_1), PTMP_tmp4_1, 0);
        *(&(PTMP_tmp4_1)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_2;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_2;
        }
        
        PrtGoto(p_this, 2U, 0);
        
    }
    
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_i
};


PRT_FUNDECL* P_BANK_SERVER_METHODS[] = { &P_FUNCTION_Anon, &P_FUNCTION_Anon_1, &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_BANK_SERVER_RECV_INNER_1[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BANK_SERVER_RECV_1 =
{
    6U,
    P_BANK_SERVER_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_BANK_SERVER_SEND_INNER[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BANK_SERVER_SEND =
{
    6U,
    P_BANK_SERVER_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_BANK_SERVER = 
{
    0U,
    "BANK_SERVER",
    &P_EVENTSET_BANK_SERVER_RECV_1,
    &P_EVENTSET_BANK_SERVER_SEND,
    NULL,
    2U,
    5U,
    3U,
    4294967295U,
    0U,
    P_BANK_SERVER_VARS,
    P_BANK_SERVER_STATES,
    P_BANK_SERVER_METHODS
};

PRT_VARDECL P_CLIENT_OTP_GENERATOR_VARS[] = {
    { "bankServer", &P_GEND_TYPE_m },
    { "OTPSecret", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_1 =
{
    0U,
    P_Init_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_1[] = { &P_EVENT_OTPSecretMsg };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_1 =
{
    1U,
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

PRT_TRANSDECL P_TRANS_2[] =
{
    { 0, &P_EVENT_OTPSecretMsg, 1, &_P_NO_OP }
};

#define P_STATE_CLIENT_OTP_GENERATOR_Init \
{ \
    "CLIENT_OTP_GENERATOR.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_1, \
    &P_EVENTSET_Init_TRANS_1, \
    &P_EVENTSET_Init_DOS_1, \
    P_TRANS_2, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_HandleOTPSecret_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_HandleOTPSecret_DEFERS =
{
    0U,
    P_HandleOTPSecret_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_HandleOTPSecret_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_HandleOTPSecret_TRANS =
{
    0U,
    P_HandleOTPSecret_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_HandleOTPSecret_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_HandleOTPSecret_DOS =
{
    0U,
    P_HandleOTPSecret_DOS_INNER,
    NULL
};

#define P_STATE_CLIENT_OTP_GENERATOR_HandleOTPSecret \
{ \
    "CLIENT_OTP_GENERATOR.HandleOTPSecret", \
    0U, \
    0U, \
    &P_EVENTSET_HandleOTPSecret_DEFERS, \
    &P_EVENTSET_HandleOTPSecret_TRANS, \
    &P_EVENTSET_HandleOTPSecret_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_GenerateOTPCode_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_GenerateOTPCode_DEFERS =
{
    0U,
    P_GenerateOTPCode_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_GenerateOTPCode_TRANS_INNER[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeValidated };
PRT_EVENTSETDECL P_EVENTSET_GenerateOTPCode_TRANS =
{
    2U,
    P_GenerateOTPCode_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_GenerateOTPCode_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_GenerateOTPCode_DOS =
{
    0U,
    P_GenerateOTPCode_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_3[] =
{
    { 2, &P_EVENT_OTPCodeValidated, 3, &_P_NO_OP },
    { 2, &P_EVENT_OTPCodeFailed, 2, &_P_NO_OP }
};

#define P_STATE_CLIENT_OTP_GENERATOR_GenerateOTPCode \
{ \
    "CLIENT_OTP_GENERATOR.GenerateOTPCode", \
    2U, \
    0U, \
    &P_EVENTSET_GenerateOTPCode_DEFERS, \
    &P_EVENTSET_GenerateOTPCode_TRANS, \
    &P_EVENTSET_GenerateOTPCode_DOS, \
    P_TRANS_3, \
    NULL, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_End_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_End_DEFERS =
{
    0U,
    P_End_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_End_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_End_TRANS =
{
    0U,
    P_End_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_End_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_End_DOS =
{
    0U,
    P_End_DOS_INNER,
    NULL
};

#define P_STATE_CLIENT_OTP_GENERATOR_End \
{ \
    "CLIENT_OTP_GENERATOR.End", \
    0U, \
    0U, \
    &P_EVENTSET_End_DEFERS, \
    &P_EVENTSET_End_TRANS, \
    &P_EVENTSET_End_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_5, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_CLIENT_OTP_GENERATOR_STATES[] = { P_STATE_CLIENT_OTP_GENERATOR_Init, P_STATE_CLIENT_OTP_GENERATOR_HandleOTPSecret, P_STATE_CLIENT_OTP_GENERATOR_GenerateOTPCode, P_STATE_CLIENT_OTP_GENERATOR_End };

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtTupleGet(*P_VAR_payload_2, 0);
    
    {
        PRT_VALUE** P_LVALUE_14 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_14);
        *P_LVALUE_14 = PTMP_tmp0_3;
        PTMP_tmp0_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtTupleGet(*P_VAR_payload_2, 1);
    
    {
        PRT_VALUE** P_LVALUE_16 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_16);
        *P_LVALUE_16 = PTMP_tmp1_2;
        PTMP_tmp1_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = PrtCloneValue(p_this->varValues[1]);
    
    _P_GEN_funargs[0] = &(PTMP_tmp2_2);
    PrtFreeValue(P_SaveOTPSecret_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp2_2);
    PTMP_tmp2_2 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_18);
    *P_LVALUE_18 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp4_2);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = PrtCloneValue((&P_EVENT_OTPSecretReceived.value));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp3_2), PTMP_tmp4_2, 0);
    *(&(PTMP_tmp4_2)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    PrtGoto(p_this, 2U, 0);
    
p_return_3: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_T2mi
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_code = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = ((_P_GEN_funval = P_GetOTPSecret_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_21 = &(P_VAR_code);
        PrtFreeValue(*P_LVALUE_21);
        *P_LVALUE_21 = PTMP_tmp0_4;
        PTMP_tmp0_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = ((_P_GEN_funval = P_EnclaveTwoGenerateOTPCode_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_23 = &(P_VAR_code);
        PrtFreeValue(*P_LVALUE_23);
        *P_LVALUE_23 = PTMP_tmp1_3;
        PTMP_tmp1_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp3_3);
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = PrtCloneValue((&P_EVENT_OTPCodeMsg.value));
    
    PRT_VALUE** P_LVALUE_26 = &(PTMP_tmp4_3);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue(P_VAR_code);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp2_3), PTMP_tmp3_3, 1, &(PTMP_tmp4_3));
    *(&(PTMP_tmp3_3)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
p_return_4: ;
    PrtFreeValue(P_VAR_code); P_VAR_code = NULL;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_3); PTMP_tmp4_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    NULL
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = PrtCloneValue((&_P_EVENT_HALT_STRUCT.value));
    
    PrtRaise(p_this, PTMP_tmp0_5, 0);
    *(&(PTMP_tmp0_5)) = NULL;
    goto p_return_5;
    
p_return_5: ;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    NULL
};


PRT_FUNDECL* P_CLIENT_OTP_GENERATOR_METHODS[] = { &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5 };

PRT_EVENTDECL* P_CLIENT_OTP_GENERATOR_RECV_INNER_1[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_CLIENT_OTP_GENERATOR_RECV_1 =
{
    6U,
    P_CLIENT_OTP_GENERATOR_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_CLIENT_OTP_GENERATOR_SEND_INNER[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_CLIENT_OTP_GENERATOR_SEND =
{
    6U,
    P_CLIENT_OTP_GENERATOR_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_CLIENT_OTP_GENERATOR = 
{
    1U,
    "CLIENT_OTP_GENERATOR",
    &P_EVENTSET_CLIENT_OTP_GENERATOR_RECV_1,
    &P_EVENTSET_CLIENT_OTP_GENERATOR_SEND,
    NULL,
    2U,
    4U,
    3U,
    4294967295U,
    0U,
    P_CLIENT_OTP_GENERATOR_VARS,
    P_CLIENT_OTP_GENERATOR_STATES,
    P_CLIENT_OTP_GENERATOR_METHODS
};

PRT_VARDECL P_IntializerMachine_VARS[] = {
    { "clientMachine", &P_GEND_TYPE_m },
    { "bankMachine", &P_GEND_TYPE_m }
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

#define P_STATE_IntializerMachine_Init \
{ \
    "IntializerMachine.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_2, \
    &P_EVENTSET_Init_TRANS_2, \
    &P_EVENTSET_Init_DOS_2, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_6, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_IntializerMachine_STATES[] = { P_STATE_IntializerMachine_Init };

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = PrtCloneValue(PrtMkInterface(context, 1, 0)->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    {
        PRT_VALUE** P_LVALUE_29 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_29);
        *P_LVALUE_29 = PTMP_tmp0_6;
        PTMP_tmp0_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp2_4);
    PrtFreeValue(*P_LVALUE_31);
    *P_LVALUE_31 = PrtCloneValue(PrtMkInterface(context, 0, 1, &(PTMP_tmp1_4))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    {
        PRT_VALUE** P_LVALUE_32 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PTMP_tmp2_4;
        PTMP_tmp2_4 = NULL;
    }
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    NULL
};


PRT_FUNDECL* P_IntializerMachine_METHODS[] = { &P_FUNCTION_Anon_6 };

PRT_EVENTDECL* P_IntializerMachine_RECV_INNER_1[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_IntializerMachine_RECV_1 =
{
    6U,
    P_IntializerMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_IntializerMachine_SEND_INNER[] = { &P_EVENT_OTPCodeFailed, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_IntializerMachine_SEND =
{
    6U,
    P_IntializerMachine_SEND_INNER,
    NULL
};

PRT_UINT32 P_IntializerMachine_CREATES_ARR[] = { 0, 1 };
PRT_INTERFACESETDECL P_IntializerMachine_CREATES = { 2, P_IntializerMachine_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_IntializerMachine = 
{
    2U,
    "IntializerMachine",
    &P_EVENTSET_IntializerMachine_RECV_1,
    &P_EVENTSET_IntializerMachine_SEND,
    &P_IntializerMachine_CREATES,
    2U,
    1U,
    1U,
    4294967295U,
    0U,
    P_IntializerMachine_VARS,
    P_IntializerMachine_STATES,
    P_IntializerMachine_METHODS
};

PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_OTPSecretMsg, &P_EVENT_OTPSecretReceived, &P_EVENT_OTPCodeMsg, &P_EVENT_OTPCodeValidated, &P_EVENT_OTPCodeFailed };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_BANK_SERVER, &P_MACHINE_CLIENT_OTP_GENERATOR, &P_MACHINE_IntializerMachine };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_BANK_SERVER, &P_I_CLIENT_OTP_GENERATOR, &P_I_IntializerMachine };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { NULL };
int P_DefaultImpl_LME_0[] = { -1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,-1 };
int P_DefaultImpl_LME_2[] = { 0,1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    7U,
    3U,
    3U,
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

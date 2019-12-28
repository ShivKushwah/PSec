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
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_MKiVi = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };

// Function implementation prototypes:
PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_SecureSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_UntrustedSend_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_InitializeUntrustedMachine_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_7;


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
    &P_GEND_TYPE_MKiVi
};

PRT_EVENTDECL P_EVENT_GenerateOTPCodeEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "GenerateOTPCodeEvent",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_OTPCodeEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "OTPCodeEvent",
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


PRT_EVENTDECL* P_GodUntrusted_RECV_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodUntrusted_RECV =
{
    9U,
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

PRT_EVENTDECL* P_GodMachine_RECV_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodMachine_RECV =
{
    9U,
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

PRT_EVENTDECL* P_BankEnclave_RECV_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_RECV =
{
    9U,
    P_BankEnclave_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_BankEnclave =
{
    2U,
    "BankEnclave",
    &P_GEND_TYPE_StringType,
    &P_EVENTSET_BankEnclave_RECV
};

PRT_EVENTDECL* P_ClientEnclave_RECV_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_RECV =
{
    9U,
    P_ClientEnclave_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ClientEnclave =
{
    3U,
    "ClientEnclave",
    &P_GEND_TYPE_StringType,
    &P_EVENTSET_ClientEnclave_RECV
};

PRT_EVENTDECL* P_ClientWebBrowser_RECV_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_RECV =
{
    9U,
    P_ClientWebBrowser_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ClientWebBrowser =
{
    4U,
    "ClientWebBrowser",
    &P_GEND_TYPE_n,
    &P_EVENTSET_ClientWebBrowser_RECV
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

PRT_EVENTDECL* P_GodUntrusted_RECV_INNER_1[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodUntrusted_RECV_1 =
{
    9U,
    P_GodUntrusted_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_GodUntrusted_SEND_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodUntrusted_SEND =
{
    9U,
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
    { "clientUSM", &P_GEND_TYPE_StringType },
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
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    _P_GEN_funargs[0] = "ClientWebBrowser";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
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
    
    _P_GEN_funargs[0] = "BankEnclave";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp1);
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_6 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_6);
        *P_LVALUE_6 = PTMP_tmp2;
        PTMP_tmp2 = NULL;
    }
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_FUNDECL* P_GodMachine_METHODS[] = { &P_FUNCTION_Anon_1 };

PRT_EVENTDECL* P_GodMachine_RECV_INNER_1[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodMachine_RECV_1 =
{
    9U,
    P_GodMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_GodMachine_SEND_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_GodMachine_SEND =
{
    9U,
    P_GodMachine_SEND_INNER,
    NULL
};

PRT_UINT32 P_GodMachine_CREATES_ARR[] = { 2, 4 };
PRT_INTERFACESETDECL P_GodMachine_CREATES = { 2, P_GodMachine_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_GodMachine = 
{
    1U,
    "GodMachine",
    &P_EVENTSET_GodMachine_RECV_1,
    &P_EVENTSET_GodMachine_SEND,
    &P_GodMachine_CREATES,
    2U,
    1U,
    1U,
    4294967295U,
    0U,
    P_GodMachine_VARS,
    P_GodMachine_STATES,
    P_GodMachine_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_BankEnclave_VARS[] = {
    { "clientSSM", &P_GEND_TYPE_StringType },
    { "clientUSM", &P_GEND_TYPE_StringType },
    { "result", &P_GEND_TYPE_MKiVi }
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

#define P_STATE_BankEnclave_Initial \
{ \
    "BankEnclave.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_2, \
    &P_EVENTSET_Initial_TRANS_2, \
    &P_EVENTSET_Initial_DOS_2, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_BankEnclave_STATES[] = { P_STATE_BankEnclave_Initial };

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_7 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_7);
    *P_LVALUE_7 = PrtCloneValue(*P_VAR_payload);
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtCloneValue(p_this->varValues[1]);
    
    _P_GEN_funargs[0] = "ClientEnclave";
    _P_GEN_funargs[1] = "1";
    _P_GEN_funargs[2] = &(PTMP_tmp0_2);
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_10 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_10);
        *P_LVALUE_10 = PTMP_tmp1_1;
        PTMP_tmp1_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_11 = &(*(PrtMapGetLValue(p_this->varValues[2], (&P_LIT_INT32), PRT_TRUE, &P_GEND_TYPE_MKiVi)));
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue((&P_LIT_INT32_1));
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue((&P_EVENT_MasterSecretEvent.value));
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32_2));
    _P_GEN_funargs[0] = &(PTMP_tmp2_1);
    _P_GEN_funargs[1] = &(PTMP_tmp3);
    _P_GEN_funargs[2] = &(P_PTMP_tmp);
    _P_GEN_funargs[3] = &(PTMP_tmp4);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtCloneValue(p_this->varValues[0]);
    
    _P_GEN_funargs[0] = &(PTMP_tmp5);
    PrtFreeValue(P_PrintString_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp5);
    PTMP_tmp5 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = PrtCloneValue((&P_EVENT_PublicIDEvent.value));
    
    PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_18);
    *P_LVALUE_18 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE* P_PTMP_tmp_1 = PrtCloneValue(&(P_LIT_INT32_2));
    _P_GEN_funargs[0] = &(PTMP_tmp6);
    _P_GEN_funargs[1] = &(PTMP_tmp7);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_1);
    _P_GEN_funargs[3] = &(PTMP_tmp8);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_StringType
};


PRT_FUNDECL* P_BankEnclave_METHODS[] = { &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_BankEnclave_RECV_INNER_1[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_RECV_1 =
{
    9U,
    P_BankEnclave_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_BankEnclave_SEND_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_SEND =
{
    9U,
    P_BankEnclave_SEND_INNER,
    NULL
};

PRT_UINT32 P_BankEnclave_CREATES_ARR[] = { 3 };
PRT_INTERFACESETDECL P_BankEnclave_CREATES = { 1, P_BankEnclave_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_BankEnclave = 
{
    2U,
    "BankEnclave",
    &P_EVENTSET_BankEnclave_RECV_1,
    &P_EVENTSET_BankEnclave_SEND,
    &P_BankEnclave_CREATES,
    3U,
    1U,
    1U,
    4294967295U,
    0U,
    P_BankEnclave_VARS,
    P_BankEnclave_STATES,
    P_BankEnclave_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_ClientEnclave_VARS[] = {
    { "masterSecret", &P_GEND_TYPE_i },
    { "clientUSM", &P_GEND_TYPE_StringType },
    { "result", &P_GEND_TYPE_MKiVi }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_3[] = { &P_EVENT_GenerateOTPCodeEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_3 =
{
    1U,
    P_Initial_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_3[] = { &P_EVENT_MasterSecretEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_3 =
{
    1U,
    P_Initial_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_3 =
{
    0U,
    P_Initial_DOS_INNER_3,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 0, &P_EVENT_MasterSecretEvent, 1, &_P_NO_OP }
};

#define P_STATE_ClientEnclave_Initial \
{ \
    "ClientEnclave.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_3, \
    &P_EVENTSET_Initial_TRANS_3, \
    &P_EVENTSET_Initial_DOS_3, \
    P_TRANS, \
    NULL, \
    &P_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_ProvisionEnclaveWithSecret_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ProvisionEnclaveWithSecret_DEFERS =
{
    0U,
    P_ProvisionEnclaveWithSecret_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_ProvisionEnclaveWithSecret_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ProvisionEnclaveWithSecret_TRANS =
{
    0U,
    P_ProvisionEnclaveWithSecret_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_ProvisionEnclaveWithSecret_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ProvisionEnclaveWithSecret_DOS =
{
    0U,
    P_ProvisionEnclaveWithSecret_DOS_INNER,
    NULL
};

#define P_STATE_ClientEnclave_ProvisionEnclaveWithSecret \
{ \
    "ClientEnclave.ProvisionEnclaveWithSecret", \
    0U, \
    0U, \
    &P_EVENTSET_ProvisionEnclaveWithSecret_DEFERS, \
    &P_EVENTSET_ProvisionEnclaveWithSecret_TRANS, \
    &P_EVENTSET_ProvisionEnclaveWithSecret_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_WaitForGenerateOTP_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForGenerateOTP_DEFERS =
{
    0U,
    P_WaitForGenerateOTP_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForGenerateOTP_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitForGenerateOTP_TRANS =
{
    0U,
    P_WaitForGenerateOTP_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitForGenerateOTP_DOS_INNER[] = { &P_EVENT_GenerateOTPCodeEvent };
PRT_EVENTSETDECL P_EVENTSET_WaitForGenerateOTP_DOS =
{
    1U,
    P_WaitForGenerateOTP_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS[] =
{
    { 2, &P_EVENT_GenerateOTPCodeEvent, &P_FUNCTION_Anon_5 }
};

#define P_STATE_ClientEnclave_WaitForGenerateOTP \
{ \
    "ClientEnclave.WaitForGenerateOTP", \
    0U, \
    1U, \
    &P_EVENTSET_WaitForGenerateOTP_DEFERS, \
    &P_EVENTSET_WaitForGenerateOTP_TRANS, \
    &P_EVENTSET_WaitForGenerateOTP_DOS, \
    NULL, \
    P_DOS, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClientEnclave_STATES[] = { P_STATE_ClientEnclave_Initial, P_STATE_ClientEnclave_ProvisionEnclaveWithSecret, P_STATE_ClientEnclave_WaitForGenerateOTP };

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_19 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = PrtCloneValue(*P_VAR_payload_1);
    
p_return_3: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_StringType
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = PrtMapGet(*P_VAR_payload_2, (&P_LIT_INT32_3));
    
    {
        PRT_VALUE** P_LVALUE_21 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_21);
        *P_LVALUE_21 = PTMP_tmp0_3;
        PTMP_tmp0_3 = NULL;
    }
    
    PrtGoto(p_this, 2U, 0);
    
p_return_4: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    &P_GEND_TYPE_MKiVi
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_usernamePassword = argRefs[0];
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = PrtCloneValue((&P_EVENT_OTPCodeEvent.value));
    
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = PrtMkIntValue(PrtPrimGetInt(*P_VAR_usernamePassword) + PrtPrimGetInt(p_this->varValues[0]));
    
    PRT_VALUE* P_PTMP_tmp_2 = PrtCloneValue(&(P_LIT_INT32_4));
    _P_GEN_funargs[0] = &(PTMP_tmp0_4);
    _P_GEN_funargs[1] = &(PTMP_tmp1_2);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_2);
    _P_GEN_funargs[3] = &(PTMP_tmp2_2);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
    PRT_VALUE** P_LVALUE_25 = &(*(PrtMapGetLValue(p_this->varValues[2], (&P_LIT_INT32_5), PRT_TRUE, &P_GEND_TYPE_MKiVi)));
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = PrtCloneValue(p_this->varValues[0]);
    
p_return_5: ;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_i
};


PRT_FUNDECL* P_ClientEnclave_METHODS[] = { &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5 };

PRT_EVENTDECL* P_ClientEnclave_RECV_INNER_1[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_RECV_1 =
{
    9U,
    P_ClientEnclave_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ClientEnclave_SEND_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_SEND =
{
    9U,
    P_ClientEnclave_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_ClientEnclave = 
{
    3U,
    "ClientEnclave",
    &P_EVENTSET_ClientEnclave_RECV_1,
    &P_EVENTSET_ClientEnclave_SEND,
    NULL,
    3U,
    3U,
    3U,
    4294967295U,
    0U,
    P_ClientEnclave_VARS,
    P_ClientEnclave_STATES,
    P_ClientEnclave_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_ClientWebBrowser_VARS[] = {
    { "clientSSM", &P_GEND_TYPE_StringType },
    { "usernamePassword", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_4 =
{
    0U,
    P_Initial_DEFERS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_4[] = { &P_EVENT_PublicIDEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_4 =
{
    1U,
    P_Initial_TRANS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_4 =
{
    0U,
    P_Initial_DOS_INNER_4,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 0, &P_EVENT_PublicIDEvent, 1, &_P_NO_OP }
};

#define P_STATE_ClientWebBrowser_Initial \
{ \
    "ClientWebBrowser.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_4, \
    &P_EVENTSET_Initial_TRANS_4, \
    &P_EVENTSET_Initial_DOS_4, \
    P_TRANS_1, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Authenticate_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Authenticate_DEFERS =
{
    0U,
    P_Authenticate_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Authenticate_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Authenticate_TRANS =
{
    0U,
    P_Authenticate_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Authenticate_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Authenticate_DOS =
{
    0U,
    P_Authenticate_DOS_INNER,
    NULL
};

#define P_STATE_ClientWebBrowser_Authenticate \
{ \
    "ClientWebBrowser.Authenticate", \
    0U, \
    0U, \
    &P_EVENTSET_Authenticate_DEFERS, \
    &P_EVENTSET_Authenticate_TRANS, \
    &P_EVENTSET_Authenticate_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_6, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_SaveOTPCode_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveOTPCode_DEFERS =
{
    0U,
    P_SaveOTPCode_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_SaveOTPCode_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveOTPCode_TRANS =
{
    0U,
    P_SaveOTPCode_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_SaveOTPCode_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveOTPCode_DOS =
{
    0U,
    P_SaveOTPCode_DOS_INNER,
    NULL
};

#define P_STATE_ClientWebBrowser_SaveOTPCode \
{ \
    "ClientWebBrowser.SaveOTPCode", \
    0U, \
    0U, \
    &P_EVENTSET_SaveOTPCode_DEFERS, \
    &P_EVENTSET_SaveOTPCode_TRANS, \
    &P_EVENTSET_SaveOTPCode_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_7, \
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

#define P_STATE_ClientWebBrowser_Done \
{ \
    "ClientWebBrowser.Done", \
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

PRT_STATEDECL P_ClientWebBrowser_STATES[] = { P_STATE_ClientWebBrowser_Initial, P_STATE_ClientWebBrowser_Authenticate, P_STATE_ClientWebBrowser_SaveOTPCode, P_STATE_ClientWebBrowser_Done };

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* P_VAR_P_payload = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_7 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_26 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue(*P_VAR_payload_3);
    
    PRT_VALUE** P_LVALUE_27 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = PrtCloneValue((&P_LIT_INT32_6));
    
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_29);
    *P_LVALUE_29 = PrtCloneValue((&P_EVENT_GenerateOTPCodeEvent.value));
    
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE* P_PTMP_tmp_3 = PrtCloneValue(&(P_LIT_INT32_7));
    _P_GEN_funargs[0] = &(PTMP_tmp0_5);
    _P_GEN_funargs[1] = &(PTMP_tmp1_3);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_3);
    _P_GEN_funargs[3] = &(PTMP_tmp2_3);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PRT_UINT32 P_allowedEventIds[] = { 2 };
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    PRT_UINT32 P_eventId = PrtReceiveAsync(1U, P_allowedEventIds, &P_VAR_P_payload);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    switch (P_eventId) {
        case 2: {
            PRT_VALUE** P_VAR_payload_4 = &P_VAR_P_payload;
                        PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp3_1);
            PrtFreeValue(*P_LVALUE_31);
            *P_LVALUE_31 = PrtCloneValue(*P_VAR_payload_4);
            
            PrtGoto(p_this, 2U, 1, &(PTMP_tmp3_1));
            
            p_return_7: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    &P_GEND_TYPE_StringType
};


PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_5 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtFormatPrintf("OTP Code Received: ", 1, *P_VAR_payload_5, 1, 0, "\n");
    
    PrtGoto(p_this, 3U, 0);
    
p_return_8: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_i
};


PRT_FUNDECL* P_ClientWebBrowser_METHODS[] = { &P_FUNCTION_Anon_6, &P_FUNCTION_Anon_7 };

PRT_EVENTDECL* P_ClientWebBrowser_RECV_INNER_1[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_RECV_1 =
{
    9U,
    P_ClientWebBrowser_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ClientWebBrowser_SEND_INNER[] = { &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_PublicIDEvent, &P_EVENT_Success, &P_EVENT_UntrustedEventFromPing, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_SEND =
{
    9U,
    P_ClientWebBrowser_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_ClientWebBrowser = 
{
    4U,
    "ClientWebBrowser",
    &P_EVENTSET_ClientWebBrowser_RECV_1,
    &P_EVENTSET_ClientWebBrowser_SEND,
    NULL,
    2U,
    4U,
    2U,
    4294967295U,
    0U,
    P_ClientWebBrowser_VARS,
    P_ClientWebBrowser_STATES,
    P_ClientWebBrowser_METHODS,
    PRT_FALSE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_OTPCodeEvent, &P_EVENT_Ping, &P_EVENT_Pong, &P_EVENT_UntrustedEventFromPing, &P_EVENT_Success, &P_EVENT_PublicIDEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_GenerateOTPCodeEvent };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_GodUntrusted, &P_MACHINE_GodMachine, &P_MACHINE_BankEnclave, &P_MACHINE_ClientEnclave, &P_MACHINE_ClientWebBrowser };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_GodUntrusted, &P_I_GodMachine, &P_I_BankEnclave, &P_I_ClientEnclave, &P_I_ClientWebBrowser };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType };
int P_DefaultImpl_LME_0[] = { -1,1,-1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,2,-1,4 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1,3,-1 };
int P_DefaultImpl_LME_3[] = { -1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_4[] = { -1,-1,-1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3, P_DefaultImpl_LME_4 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3,4 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    10U,
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

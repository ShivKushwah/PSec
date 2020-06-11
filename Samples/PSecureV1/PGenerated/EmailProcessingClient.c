#include "EmailProcessingClient.h"

// Type universe for program:
extern PRT_UINT64 P_MKDEF_machine_handle_IMPL(void);
extern PRT_UINT64 P_CLONE_machine_handle_IMPL(PRT_UINT64);
extern void P_FREE_machine_handle_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_machine_handle_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_machine_handle_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_machine_handle_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_machine_handle = {
    0U,
    "machine_handle",
    P_MKDEF_machine_handle_IMPL,
    P_CLONE_machine_handle_IMPL,
    P_FREE_machine_handle_IMPL,
    P_GETHASHCODE_machine_handle_IMPL,
    P_ISEQUAL_machine_handle_IMPL,
    P_TOSTRING_machine_handle_IMPL,
};
PRT_TYPE P_GEND_TYPE_machine_handle = { PRT_KIND_FOREIGN, { .foreignType = &P_machine_handle } };
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
static PRT_TYPE P_GEND_TYPE_b = { PRT_KIND_BOOL, { NULL } };
extern PRT_UINT64 P_MKDEF_secure_machine_handle_IMPL(void);
extern PRT_UINT64 P_CLONE_secure_machine_handle_IMPL(PRT_UINT64);
extern void P_FREE_secure_machine_handle_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_secure_machine_handle_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_secure_machine_handle_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_secure_machine_handle_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_secure_machine_handle = {
    0U,
    "secure_machine_handle",
    P_MKDEF_secure_machine_handle_IMPL,
    P_CLONE_secure_machine_handle_IMPL,
    P_FREE_secure_machine_handle_IMPL,
    P_GETHASHCODE_secure_machine_handle_IMPL,
    P_ISEQUAL_secure_machine_handle_IMPL,
    P_TOSTRING_secure_machine_handle_IMPL,
};
PRT_TYPE P_GEND_TYPE_secure_machine_handle = { PRT_KIND_FOREIGN, { .foreignType = &P_secure_machine_handle } };
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_secure_machine_handle, &P_GEND_TYPE_machine_handle };
static PRT_TUPTYPE P_TUP = { 2U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T2secure_machine_handlemachine_handle = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
extern PRT_UINT64 P_MKDEF_secure_StringType_IMPL(void);
extern PRT_UINT64 P_CLONE_secure_StringType_IMPL(PRT_UINT64);
extern void P_FREE_secure_StringType_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_secure_StringType_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_secure_StringType_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_secure_StringType_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_secure_StringType = {
    0U,
    "secure_StringType",
    P_MKDEF_secure_StringType_IMPL,
    P_CLONE_secure_StringType_IMPL,
    P_FREE_secure_StringType_IMPL,
    P_GETHASHCODE_secure_StringType_IMPL,
    P_ISEQUAL_secure_StringType_IMPL,
    P_TOSTRING_secure_StringType_IMPL,
};
PRT_TYPE P_GEND_TYPE_secure_StringType = { PRT_KIND_FOREIGN, { .foreignType = &P_secure_StringType } };
static PRT_TYPE* P_TUP_T_1[] = { &P_GEND_TYPE_secure_machine_handle, &P_GEND_TYPE_secure_StringType };
static PRT_TUPTYPE P_TUP_1 = { 2U, P_TUP_T_1 };
static PRT_TYPE P_GEND_TYPE_T2secure_machine_handlesecure_StringType = { PRT_KIND_TUPLE, { .tuple = &P_TUP_1 } };
static PRT_TYPE P_GEND_TYPE_sb = { PRT_KIND_SECURE_BOOL, { NULL } };
extern PRT_UINT64 P_MKDEF_sealed_data_key_IMPL(void);
extern PRT_UINT64 P_CLONE_sealed_data_key_IMPL(PRT_UINT64);
extern void P_FREE_sealed_data_key_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_sealed_data_key_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_sealed_data_key_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_sealed_data_key_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_sealed_data_key = {
    0U,
    "sealed_data_key",
    P_MKDEF_sealed_data_key_IMPL,
    P_CLONE_sealed_data_key_IMPL,
    P_FREE_sealed_data_key_IMPL,
    P_GETHASHCODE_sealed_data_key_IMPL,
    P_ISEQUAL_sealed_data_key_IMPL,
    P_TOSTRING_sealed_data_key_IMPL,
};
PRT_TYPE P_GEND_TYPE_sealed_data_key = { PRT_KIND_FOREIGN, { .foreignType = &P_sealed_data_key } };
extern PRT_UINT64 P_MKDEF_sealed_data_IMPL(void);
extern PRT_UINT64 P_CLONE_sealed_data_IMPL(PRT_UINT64);
extern void P_FREE_sealed_data_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_sealed_data_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_sealed_data_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_sealed_data_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_sealed_data = {
    0U,
    "sealed_data",
    P_MKDEF_sealed_data_IMPL,
    P_CLONE_sealed_data_IMPL,
    P_FREE_sealed_data_IMPL,
    P_GETHASHCODE_sealed_data_IMPL,
    P_ISEQUAL_sealed_data_IMPL,
    P_TOSTRING_sealed_data_IMPL,
};
PRT_TYPE P_GEND_TYPE_sealed_data = { PRT_KIND_FOREIGN, { .foreignType = &P_sealed_data } };
static PRT_TYPE* P_TUP_T_2[] = { &P_GEND_TYPE_sealed_data_key, &P_GEND_TYPE_sealed_data };
static PRT_TUPTYPE P_TUP_2 = { 2U, P_TUP_T_2 };
static PRT_TYPE P_GEND_TYPE_T2sealed_data_keysealed_data = { PRT_KIND_TUPLE, { .tuple = &P_TUP_2 } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
extern PRT_UINT64 P_MKDEF_capability_IMPL(void);
extern PRT_UINT64 P_CLONE_capability_IMPL(PRT_UINT64);
extern void P_FREE_capability_IMPL(PRT_UINT64);
extern PRT_UINT32 P_GETHASHCODE_capability_IMPL(PRT_UINT64);
extern PRT_BOOLEAN P_ISEQUAL_capability_IMPL(PRT_UINT64, PRT_UINT64);
extern PRT_STRING P_TOSTRING_capability_IMPL(PRT_UINT64);
static PRT_FOREIGNTYPEDECL P_capability = {
    0U,
    "capability",
    P_MKDEF_capability_IMPL,
    P_CLONE_capability_IMPL,
    P_FREE_capability_IMPL,
    P_GETHASHCODE_capability_IMPL,
    P_ISEQUAL_capability_IMPL,
    P_TOSTRING_capability_IMPL,
};
PRT_TYPE P_GEND_TYPE_capability = { PRT_KIND_FOREIGN, { .foreignType = &P_capability } };

// Function implementation prototypes:
PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintRawStringType_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintRawSecureStringType_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Declassify_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Endorse_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GenerateSealedDataKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GenerateSealedData_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_seal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_seal;

PRT_VALUE* P_unseal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_8;

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_9;

PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_10;

PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_11;


PRT_EVENTDECL P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDSecureSpamFilterIDEvent",
    4294967295U,
    &P_GEND_TYPE_machine_handle,
    0
};

PRT_EVENTDECL P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDReceiveEmailEnclaveIDEvent",
    4294967295U,
    &P_GEND_TYPE_machine_handle,
    0
};

PRT_EVENTDECL P_EVENT_UNTRUSTEDEmailEnclaveIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDEmailEnclaveIDEvent",
    4294967295U,
    &P_GEND_TYPE_machine_handle,
    0
};

PRT_EVENTDECL P_EVENT_UNTRUSTEDEmailBodyEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDEmailBodyEvent",
    4294967295U,
    &P_GEND_TYPE_StringType,
    0
};

PRT_EVENTDECL P_EVENT_UNTRUSTEDSpamResultEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDSpamResultEvent",
    4294967295U,
    &P_GEND_TYPE_b,
    0
};

PRT_EVENTDECL P_EVENT_TRUSTEDSecureSpamFilterIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDSecureSpamFilterIDEvent",
    4294967295U,
    &P_GEND_TYPE_secure_machine_handle,
    1
};

PRT_EVENTDECL P_EVENT_TRUSTEDProvisionEmailUserEnclave = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDProvisionEmailUserEnclave",
    4294967295U,
    &P_GEND_TYPE_T2secure_machine_handlemachine_handle,
    1
};

PRT_EVENTDECL P_EVENT_TRUSTEDEmailBodyEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDEmailBodyEvent",
    4294967295U,
    &P_GEND_TYPE_T2secure_machine_handlesecure_StringType,
    1
};

PRT_EVENTDECL P_EVENT_TRUSTEDSpamResultEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDSpamResultEvent",
    4294967295U,
    &P_GEND_TYPE_sb,
    1
};

PRT_FUNDECL P_FUNCTION_PrintString =
{
    "PrintString",
    &P_PrintString_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_PrintRawStringType =
{
    "PrintRawStringType",
    &P_PrintRawStringType_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_PrintRawSecureStringType =
{
    "PrintRawSecureStringType",
    &P_PrintRawSecureStringType_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_PrintKey =
{
    "PrintKey",
    &P_PrintKey_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_Declassify =
{
    "Declassify",
    &P_Declassify_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_Endorse =
{
    "Endorse",
    &P_Endorse_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetThis =
{
    "GetThis",
    &P_GetThis_IMPL,
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


PRT_FUNDECL P_FUNCTION_GenerateSealedDataKey =
{
    "GenerateSealedDataKey",
    &P_GenerateSealedDataKey_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GenerateSealedData =
{
    "GenerateSealedData",
    &P_GenerateSealedData_IMPL,
    NULL
};


PRT_VALUE* P_seal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_T2sealed_data_keysealed_data);
    PRT_VALUE** P_VAR_input = argRefs[0];
    PRT_VALUE* P_VAR_output = PrtMkDefaultValue(&P_GEND_TYPE_T2sealed_data_keysealed_data);
    PRT_VALUE* PTMP_tmp0 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = ((_P_GEN_funval = P_GenerateSealedDataKey_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_1 = &(*(PrtTupleGetLValue(P_VAR_output, 0)));
        PrtFreeValue(*P_LVALUE_1);
        *P_LVALUE_1 = PTMP_tmp0;
        PTMP_tmp0 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = PrtTupleGet(P_VAR_output, 0);
    
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtCloneValue(*P_VAR_input);
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = ((_P_GEN_funargs[0] = &(PTMP_tmp1)), (_P_GEN_funargs[1] = &(PTMP_tmp2)), (_P_GEN_funval = P_GenerateSealedData_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp1), PTMP_tmp1 = NULL), (PrtFreeValue(PTMP_tmp2), PTMP_tmp2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_5 = &(*(PrtTupleGetLValue(P_VAR_output, 1)));
        PrtFreeValue(*P_LVALUE_5);
        *P_LVALUE_5 = PTMP_tmp3;
        PTMP_tmp3 = NULL;
    }
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(P_VAR_output);
    goto p_return;
    
p_return: ;
    PrtFreeValue(P_VAR_output); P_VAR_output = NULL;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_seal =
{
    "seal",
    &P_seal_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_unseal =
{
    "unseal",
    &P_unseal_IMPL,
    NULL
};


PRT_EVENTDECL* P_EmailUserEnclave_RECV_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EmailUserEnclave_RECV =
{
    10U,
    P_EmailUserEnclave_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_EmailUserEnclave =
{
    0U,
    "EmailUserEnclave",
    &P_GEND_TYPE_n,
    &P_EVENTSET_EmailUserEnclave_RECV
};

PRT_EVENTDECL* P_EmailUser_RECV_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EmailUser_RECV =
{
    10U,
    P_EmailUser_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_EmailUser =
{
    1U,
    "EmailUser",
    &P_GEND_TYPE_n,
    &P_EVENTSET_EmailUser_RECV
};

PRT_EVENTDECL* P_UntrustedInitializer_RECV_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_RECV =
{
    10U,
    P_UntrustedInitializer_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_UntrustedInitializer =
{
    2U,
    "UntrustedInitializer",
    &P_GEND_TYPE_n,
    &P_EVENTSET_UntrustedInitializer_RECV
};

PRT_EVENTDECL* P_TrustedInitializer_RECV_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_RECV =
{
    10U,
    P_TrustedInitializer_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_TrustedInitializer =
{
    3U,
    "TrustedInitializer",
    &P_GEND_TYPE_n,
    &P_EVENTSET_TrustedInitializer_RECV
};

PRT_EVENTDECL* P_SecureSpamFilter_RECV_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSpamFilter_RECV =
{
    10U,
    P_SecureSpamFilter_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_SecureSpamFilter =
{
    4U,
    "SecureSpamFilter",
    &P_GEND_TYPE_n,
    &P_EVENTSET_SecureSpamFilter_RECV
};

PRT_VARDECL P_EmailUserEnclave_VARS[] = {
    { "secureSpamSSM", &P_GEND_TYPE_secure_machine_handle },
    { "emailUserUSM", &P_GEND_TYPE_machine_handle }
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

PRT_EVENTDECL* P_Initial_DOS_INNER[] = { &P_EVENT_TRUSTEDProvisionEmailUserEnclave };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS =
{
    1U,
    P_Initial_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS[] =
{
    { 0, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_FUNCTION_Anon }
};

#define P_STATE_EmailUserEnclave_Initial \
{ \
    "EmailUserEnclave.Initial", \
    0U, \
    1U, \
    &P_EVENTSET_Initial_DEFERS, \
    &P_EVENTSET_Initial_TRANS, \
    &P_EVENTSET_Initial_DOS, \
    NULL, \
    P_DOS, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_ReceiveEmailBodyAndSendSpamRequest_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReceiveEmailBodyAndSendSpamRequest_DEFERS =
{
    0U,
    P_ReceiveEmailBodyAndSendSpamRequest_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReceiveEmailBodyAndSendSpamRequest_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReceiveEmailBodyAndSendSpamRequest_TRANS =
{
    0U,
    P_ReceiveEmailBodyAndSendSpamRequest_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReceiveEmailBodyAndSendSpamRequest_DOS_INNER[] = { &P_EVENT_UNTRUSTEDEmailBodyEvent };
PRT_EVENTSETDECL P_EVENTSET_ReceiveEmailBodyAndSendSpamRequest_DOS =
{
    1U,
    P_ReceiveEmailBodyAndSendSpamRequest_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_1[] =
{
    { 1, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_FUNCTION_Anon_1 }
};

#define P_STATE_EmailUserEnclave_ReceiveEmailBodyAndSendSpamRequest \
{ \
    "EmailUserEnclave.ReceiveEmailBodyAndSendSpamRequest", \
    0U, \
    1U, \
    &P_EVENTSET_ReceiveEmailBodyAndSendSpamRequest_DEFERS, \
    &P_EVENTSET_ReceiveEmailBodyAndSendSpamRequest_TRANS, \
    &P_EVENTSET_ReceiveEmailBodyAndSendSpamRequest_DOS, \
    NULL, \
    P_DOS_1, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_ReceiveSpamResult_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReceiveSpamResult_DEFERS =
{
    0U,
    P_ReceiveSpamResult_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReceiveSpamResult_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReceiveSpamResult_TRANS =
{
    0U,
    P_ReceiveSpamResult_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReceiveSpamResult_DOS_INNER[] = { &P_EVENT_TRUSTEDSpamResultEvent };
PRT_EVENTSETDECL P_EVENTSET_ReceiveSpamResult_DOS =
{
    1U,
    P_ReceiveSpamResult_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_2[] =
{
    { 2, &P_EVENT_TRUSTEDSpamResultEvent, &P_FUNCTION_Anon_2 }
};

#define P_STATE_EmailUserEnclave_ReceiveSpamResult \
{ \
    "EmailUserEnclave.ReceiveSpamResult", \
    0U, \
    1U, \
    &P_EVENTSET_ReceiveSpamResult_DEFERS, \
    &P_EVENTSET_ReceiveSpamResult_TRANS, \
    &P_EVENTSET_ReceiveSpamResult_DOS, \
    NULL, \
    P_DOS_2, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_EmailUserEnclave_STATES[] = { P_STATE_EmailUserEnclave_Initial, P_STATE_EmailUserEnclave_ReceiveEmailBodyAndSendSpamRequest, P_STATE_EmailUserEnclave_ReceiveSpamResult };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = PrtTupleGet(*P_VAR_payload, 0);
    
    {
        PRT_VALUE** P_LVALUE_7 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_7);
        *P_LVALUE_7 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtTupleGet(*P_VAR_payload, 1);
    
    {
        PRT_VALUE** P_LVALUE_9 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_9);
        *P_LVALUE_9 = PTMP_tmp1_1;
        PTMP_tmp1_1 = NULL;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    &P_GEND_TYPE_T2secure_machine_handlemachine_handle
};


PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue((&P_EVENT_TRUSTEDEmailBodyEvent.value));
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue((P_GetThis_IMPL(context, _P_GEN_funargs)));
    
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue(*P_VAR_payload_1);
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = ((_P_GEN_funargs[0] = &(PTMP_tmp3_1)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp3_1), PTMP_tmp3_1 = NULL), (_P_GEN_funval));
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
    *P_LVALUE_15 = PrtCloneValue(PrtCastValue(PTMP_tmp4, &P_GEND_TYPE_secure_StringType));
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = (PrtMkTuple(&P_GEND_TYPE_T2secure_machine_handlesecure_StringType, &(PTMP_tmp2_1), &(PTMP_tmp5)));
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32));
    _P_GEN_funargs[0] = &(PTMP_tmp0_2);
    _P_GEN_funargs[1] = &(PTMP_tmp1_2);
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
    
    PrtGoto(p_this, 2U, 0);
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    &P_GEND_TYPE_StringType
};


PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_18);
    *P_LVALUE_18 = PrtCloneValue((&P_EVENT_UNTRUSTEDSpamResultEvent.value));
    
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = PrtCloneValue(*P_VAR_payload_2);
    
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = ((_P_GEN_funargs[0] = &(PTMP_tmp2_2)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp2_2), PTMP_tmp2_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtCloneValue(PrtCastValue(PTMP_tmp3_2, &P_GEND_TYPE_b));
    
    PRT_VALUE* P_PTMP_tmp_1 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp0_3);
    _P_GEN_funargs[1] = &(PTMP_tmp1_3);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_1);
    _P_GEN_funargs[3] = &(PTMP_tmp4_1);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_3: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_sb
};


PRT_FUNDECL* P_EmailUserEnclave_METHODS[] = { &P_FUNCTION_Anon, &P_FUNCTION_Anon_1, &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_EmailUserEnclave_RECV_INNER_1[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EmailUserEnclave_RECV_1 =
{
    10U,
    P_EmailUserEnclave_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_EmailUserEnclave_SEND_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EmailUserEnclave_SEND =
{
    10U,
    P_EmailUserEnclave_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_EmailUserEnclave = 
{
    0U,
    "EmailUserEnclave",
    &P_EVENTSET_EmailUserEnclave_RECV_1,
    &P_EVENTSET_EmailUserEnclave_SEND,
    NULL,
    2U,
    3U,
    3U,
    4294967295U,
    0U,
    P_EmailUserEnclave_VARS,
    P_EmailUserEnclave_STATES,
    P_EmailUserEnclave_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_EmailUser_VARS[] = {
    { "secureSpamSSM", &P_GEND_TYPE_machine_handle },
    { "emailEnclaveSSM", &P_GEND_TYPE_machine_handle }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_1 =
{
    0U,
    P_Initial_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_1[] = { &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent };
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
    { 0, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, 1, &_P_NO_OP }
};

#define P_STATE_EmailUser_Initial \
{ \
    "EmailUser.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_1, \
    &P_EVENTSET_Initial_TRANS_1, \
    &P_EVENTSET_Initial_DOS_1, \
    P_TRANS, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_SaveSecureSpamFilter_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveSecureSpamFilter_DEFERS =
{
    0U,
    P_SaveSecureSpamFilter_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_SaveSecureSpamFilter_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveSecureSpamFilter_TRANS =
{
    0U,
    P_SaveSecureSpamFilter_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_SaveSecureSpamFilter_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveSecureSpamFilter_DOS =
{
    0U,
    P_SaveSecureSpamFilter_DOS_INNER,
    NULL
};

#define P_STATE_EmailUser_SaveSecureSpamFilter \
{ \
    "EmailUser.SaveSecureSpamFilter", \
    0U, \
    0U, \
    &P_EVENTSET_SaveSecureSpamFilter_DEFERS, \
    &P_EVENTSET_SaveSecureSpamFilter_TRANS, \
    &P_EVENTSET_SaveSecureSpamFilter_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_3, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_SaveEmailUserEnclave_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveEmailUserEnclave_DEFERS =
{
    0U,
    P_SaveEmailUserEnclave_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_SaveEmailUserEnclave_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveEmailUserEnclave_TRANS =
{
    0U,
    P_SaveEmailUserEnclave_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_SaveEmailUserEnclave_DOS_INNER[] = { &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent };
PRT_EVENTSETDECL P_EVENTSET_SaveEmailUserEnclave_DOS =
{
    1U,
    P_SaveEmailUserEnclave_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_3[] =
{
    { 2, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_FUNCTION_Anon_5 }
};

#define P_STATE_EmailUser_SaveEmailUserEnclave \
{ \
    "EmailUser.SaveEmailUserEnclave", \
    0U, \
    1U, \
    &P_EVENTSET_SaveEmailUserEnclave_DEFERS, \
    &P_EVENTSET_SaveEmailUserEnclave_TRANS, \
    &P_EVENTSET_SaveEmailUserEnclave_DOS, \
    NULL, \
    P_DOS_3, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_RequestSpamCheck_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RequestSpamCheck_DEFERS =
{
    0U,
    P_RequestSpamCheck_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_RequestSpamCheck_TRANS_INNER[] = { &P_EVENT_UNTRUSTEDSpamResultEvent };
PRT_EVENTSETDECL P_EVENTSET_RequestSpamCheck_TRANS =
{
    1U,
    P_RequestSpamCheck_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_RequestSpamCheck_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RequestSpamCheck_DOS =
{
    0U,
    P_RequestSpamCheck_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 3, &P_EVENT_UNTRUSTEDSpamResultEvent, 4, &_P_NO_OP }
};

#define P_STATE_EmailUser_RequestSpamCheck \
{ \
    "EmailUser.RequestSpamCheck", \
    1U, \
    0U, \
    &P_EVENTSET_RequestSpamCheck_DEFERS, \
    &P_EVENTSET_RequestSpamCheck_TRANS, \
    &P_EVENTSET_RequestSpamCheck_DOS, \
    P_TRANS_1, \
    NULL, \
    &P_FUNCTION_Anon_6, \
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

#define P_STATE_EmailUser_Done \
{ \
    "EmailUser.Done", \
    0U, \
    0U, \
    &P_EVENTSET_Done_DEFERS, \
    &P_EVENTSET_Done_TRANS, \
    &P_EVENTSET_Done_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_7, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_EmailUser_STATES[] = { P_STATE_EmailUser_Initial, P_STATE_EmailUser_SaveSecureSpamFilter, P_STATE_EmailUser_SaveEmailUserEnclave, P_STATE_EmailUser_RequestSpamCheck, P_STATE_EmailUser_Done };

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_22 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = PrtCloneValue(*P_VAR_payload_3);
    
    PrtGoto(p_this, 2U, 0);
    
p_return_4: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_machine_handle
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = PrtCloneValue((&P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent.value));
    
    PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = PrtCloneValue((P_GetThis_IMPL(context, _P_GEN_funargs)));
    
    PRT_VALUE* P_PTMP_tmp_2 = PrtCloneValue(&(P_LIT_INT32_2));
    _P_GEN_funargs[0] = &(PTMP_tmp0_4);
    _P_GEN_funargs[1] = &(PTMP_tmp1_4);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_2);
    _P_GEN_funargs[3] = &(PTMP_tmp2_3);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
p_return_5: ;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
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
    PRT_VALUE** P_VAR_payload_4 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_26 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue(*P_VAR_payload_4);
    
    PrtGoto(p_this, 3U, 0);
    
p_return_6: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_machine_handle
};


PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_emailBody = PrtMkDefaultValue(&P_GEND_TYPE_StringType);
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_5 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp1_5);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = PrtCloneValue((&P_EVENT_UNTRUSTEDEmailBodyEvent.value));
    
    PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp2_4);
    PrtFreeValue(*P_LVALUE_29);
    *P_LVALUE_29 = PrtCloneValue(P_VAR_emailBody);
    
    PRT_VALUE* P_PTMP_tmp_3 = PrtCloneValue(&(P_LIT_INT32_3));
    _P_GEN_funargs[0] = &(PTMP_tmp0_5);
    _P_GEN_funargs[1] = &(PTMP_tmp1_5);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_3);
    _P_GEN_funargs[3] = &(PTMP_tmp2_4);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
p_return_7: ;
    PrtFreeValue(P_VAR_emailBody); P_VAR_emailBody = NULL;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_5); PTMP_tmp1_5 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    NULL
};


PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_5 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtMkBoolValue(PrtIsEqualValue(*P_VAR_payload_5, (&P_LIT_BOOLEAN)));
    
    if (PrtPrimGetBool(PTMP_tmp0_6))
    {
        PrtPrintf("Spam detected and deleted!");
        
    }
    
    else
    {
        PrtPrintf("Email is good!");
        
    }
    
    
p_return_8: ;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_b
};


PRT_FUNDECL* P_EmailUser_METHODS[] = { &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5, &P_FUNCTION_Anon_6, &P_FUNCTION_Anon_7 };

PRT_EVENTDECL* P_EmailUser_RECV_INNER_1[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EmailUser_RECV_1 =
{
    10U,
    P_EmailUser_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_EmailUser_SEND_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EmailUser_SEND =
{
    10U,
    P_EmailUser_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_EmailUser = 
{
    1U,
    "EmailUser",
    &P_EVENTSET_EmailUser_RECV_1,
    &P_EVENTSET_EmailUser_SEND,
    NULL,
    2U,
    5U,
    5U,
    4294967295U,
    0U,
    P_EmailUser_VARS,
    P_EmailUser_STATES,
    P_EmailUser_METHODS,
    PRT_FALSE
};

PRT_VARDECL P_UntrustedInitializer_VARS[] = {
    { "handler", &P_GEND_TYPE_machine_handle }
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

#define P_STATE_UntrustedInitializer_Initial \
{ \
    "UntrustedInitializer.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_2, \
    &P_EVENTSET_Initial_TRANS_2, \
    &P_EVENTSET_Initial_DOS_2, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_8, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_UntrustedInitializer_STATES[] = { P_STATE_UntrustedInitializer_Initial };

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_7 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    _P_GEN_funargs[0] = "TrustedInitializer";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE* P_this_ref = (P_GetThis_IMPL(context, _P_GEN_funargs));
    _P_GEN_funargs[2] = &P_this_ref;
    PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp0_7);
    PrtFreeValue(*P_LVALUE_31);
    *P_LVALUE_31 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_9;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_9;
    }
    
    {
        PRT_VALUE** P_LVALUE_32 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PTMP_tmp0_7;
        PTMP_tmp0_7 = NULL;
    }
    
p_return_9: ;
    PrtFreeValue(PTMP_tmp0_7); PTMP_tmp0_7 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_8,
    NULL
};


PRT_FUNDECL* P_UntrustedInitializer_METHODS[] = { &P_FUNCTION_Anon_8 };

PRT_EVENTDECL* P_UntrustedInitializer_RECV_INNER_1[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_RECV_1 =
{
    10U,
    P_UntrustedInitializer_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_UntrustedInitializer_SEND_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_SEND =
{
    10U,
    P_UntrustedInitializer_SEND_INNER,
    NULL
};

PRT_UINT32 P_UntrustedInitializer_CREATES_ARR[] = { 3 };
PRT_INTERFACESETDECL P_UntrustedInitializer_CREATES = { 1, P_UntrustedInitializer_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_UntrustedInitializer = 
{
    2U,
    "UntrustedInitializer",
    &P_EVENTSET_UntrustedInitializer_RECV_1,
    &P_EVENTSET_UntrustedInitializer_SEND,
    &P_UntrustedInitializer_CREATES,
    1U,
    1U,
    1U,
    4294967295U,
    0U,
    P_UntrustedInitializer_VARS,
    P_UntrustedInitializer_STATES,
    P_UntrustedInitializer_METHODS,
    PRT_FALSE
};

PRT_VARDECL P_TrustedInitializer_VARS[] = {
    { "emailUserUSM", &P_GEND_TYPE_machine_handle },
    { "spamFilterSSM", &P_GEND_TYPE_secure_machine_handle }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_3 =
{
    0U,
    P_Initial_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_3 =
{
    0U,
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

#define P_STATE_TrustedInitializer_Initial \
{ \
    "TrustedInitializer.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_3, \
    &P_EVENTSET_Initial_TRANS_3, \
    &P_EVENTSET_Initial_DOS_3, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_9, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_TrustedInitializer_STATES[] = { P_STATE_TrustedInitializer_Initial };

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_8 = NULL;
    PRT_VALUE* PTMP_tmp1_6 = NULL;
    PRT_VALUE* PTMP_tmp2_5 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    _P_GEN_funargs[0] = "EmailUser";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = NULL;
    PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp0_8);
    PrtFreeValue(*P_LVALUE_33);
    *P_LVALUE_33 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
    {
        PRT_VALUE** P_LVALUE_34 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_34);
        *P_LVALUE_34 = PTMP_tmp0_8;
        PTMP_tmp0_8 = NULL;
    }
    
    _P_GEN_funargs[0] = "SecureSpamFilter";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE* P_this_ref_1 = (P_GetThis_IMPL(context, _P_GEN_funargs));
    _P_GEN_funargs[2] = &P_this_ref_1;
    PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp1_6);
    PrtFreeValue(*P_LVALUE_35);
    *P_LVALUE_35 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
    {
        PRT_VALUE** P_LVALUE_36 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_36);
        *P_LVALUE_36 = PTMP_tmp1_6;
        PTMP_tmp1_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_37 = &(PTMP_tmp2_5);
    PrtFreeValue(*P_LVALUE_37);
    *P_LVALUE_37 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp3_3);
    PrtFreeValue(*P_LVALUE_38);
    *P_LVALUE_38 = PrtCloneValue((&P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent.value));
    
    PRT_VALUE** P_LVALUE_39 = &(PTMP_tmp4_2);
    PrtFreeValue(*P_LVALUE_39);
    *P_LVALUE_39 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = ((_P_GEN_funargs[0] = &(PTMP_tmp4_2)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp4_2), PTMP_tmp4_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
    PRT_VALUE** P_LVALUE_41 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = PrtCloneValue(PrtCastValue(PTMP_tmp5_1, &P_GEND_TYPE_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp_4 = PrtCloneValue(&(P_LIT_INT32_4));
    _P_GEN_funargs[0] = &(PTMP_tmp2_5);
    _P_GEN_funargs[1] = &(PTMP_tmp3_3);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_4);
    _P_GEN_funargs[3] = &(PTMP_tmp6_1);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
p_return_10: ;
    PrtFreeValue(PTMP_tmp0_8); PTMP_tmp0_8 = NULL;
    PrtFreeValue(PTMP_tmp1_6); PTMP_tmp1_6 = NULL;
    PrtFreeValue(PTMP_tmp2_5); PTMP_tmp2_5 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_9 =
{
    NULL,
    &P_Anon_IMPL_9,
    NULL
};


PRT_FUNDECL* P_TrustedInitializer_METHODS[] = { &P_FUNCTION_Anon_9 };

PRT_EVENTDECL* P_TrustedInitializer_RECV_INNER_1[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_RECV_1 =
{
    10U,
    P_TrustedInitializer_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_TrustedInitializer_SEND_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_SEND =
{
    10U,
    P_TrustedInitializer_SEND_INNER,
    NULL
};

PRT_UINT32 P_TrustedInitializer_CREATES_ARR[] = { 1, 4 };
PRT_INTERFACESETDECL P_TrustedInitializer_CREATES = { 2, P_TrustedInitializer_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_TrustedInitializer = 
{
    3U,
    "TrustedInitializer",
    &P_EVENTSET_TrustedInitializer_RECV_1,
    &P_EVENTSET_TrustedInitializer_SEND,
    &P_TrustedInitializer_CREATES,
    2U,
    1U,
    1U,
    4294967295U,
    0U,
    P_TrustedInitializer_VARS,
    P_TrustedInitializer_STATES,
    P_TrustedInitializer_METHODS,
    PRT_TRUE
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_4 =
{
    0U,
    P_Initial_DEFERS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_4 =
{
    0U,
    P_Initial_TRANS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER_4[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_4 =
{
    2U,
    P_Initial_DOS_INNER_4,
    NULL
};

PRT_DODECL P_DOS_4[] =
{
    { 0, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_FUNCTION_Anon_10 },
    { 0, &P_EVENT_TRUSTEDEmailBodyEvent, &P_FUNCTION_Anon_11 }
};

#define P_STATE_SecureSpamFilter_Initial \
{ \
    "SecureSpamFilter.Initial", \
    0U, \
    2U, \
    &P_EVENTSET_Initial_DEFERS_4, \
    &P_EVENTSET_Initial_TRANS_4, \
    &P_EVENTSET_Initial_DOS_4, \
    NULL, \
    P_DOS_4, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SecureSpamFilter_STATES[] = { P_STATE_SecureSpamFilter_Initial };

PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_6 = argRefs[0];
    PRT_VALUE* P_VAR_emailEnclaveSSM = PrtMkDefaultValue(&P_GEND_TYPE_secure_machine_handle);
    PRT_VALUE* PTMP_tmp0_9 = NULL;
    PRT_VALUE* PTMP_tmp1_7 = NULL;
    PRT_VALUE* PTMP_tmp2_6 = NULL;
    PRT_VALUE* PTMP_tmp3_4 = NULL;
    PRT_VALUE* PTMP_tmp4_3 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_2 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    _P_GEN_funargs[0] = "EmailUserEnclave";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = &(*P_VAR_payload_6);
    PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp0_9);
    PrtFreeValue(*P_LVALUE_42);
    *P_LVALUE_42 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_11;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_11;
    }
    
    {
        PRT_VALUE** P_LVALUE_43 = &(P_VAR_emailEnclaveSSM);
        PrtFreeValue(*P_LVALUE_43);
        *P_LVALUE_43 = PTMP_tmp0_9;
        PTMP_tmp0_9 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_44 = &(PTMP_tmp1_7);
    PrtFreeValue(*P_LVALUE_44);
    *P_LVALUE_44 = PrtCloneValue(P_VAR_emailEnclaveSSM);
    
    PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp2_6);
    PrtFreeValue(*P_LVALUE_45);
    *P_LVALUE_45 = PrtCloneValue((&P_EVENT_TRUSTEDProvisionEmailUserEnclave.value));
    
    PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp3_4);
    PrtFreeValue(*P_LVALUE_46);
    *P_LVALUE_46 = PrtCloneValue((P_GetThis_IMPL(context, _P_GEN_funargs)));
    
    PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp4_3);
    PrtFreeValue(*P_LVALUE_47);
    *P_LVALUE_47 = PrtCloneValue(*P_VAR_payload_6);
    
    PRT_VALUE** P_LVALUE_48 = &(PTMP_tmp5_2);
    PrtFreeValue(*P_LVALUE_48);
    *P_LVALUE_48 = (PrtMkTuple(&P_GEND_TYPE_T2secure_machine_handlemachine_handle, &(PTMP_tmp3_4), &(PTMP_tmp4_3)));
    
    PRT_VALUE* P_PTMP_tmp_5 = PrtCloneValue(&(P_LIT_INT32_5));
    _P_GEN_funargs[0] = &(PTMP_tmp1_7);
    _P_GEN_funargs[1] = &(PTMP_tmp2_6);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_5);
    _P_GEN_funargs[3] = &(PTMP_tmp5_2);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_11;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_11;
    }
    
    PRT_VALUE** P_LVALUE_49 = &(PTMP_tmp6_2);
    PrtFreeValue(*P_LVALUE_49);
    *P_LVALUE_49 = PrtCloneValue(*P_VAR_payload_6);
    
    PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_50);
    *P_LVALUE_50 = PrtCloneValue((&P_EVENT_UNTRUSTEDEmailEnclaveIDEvent.value));
    
    PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_51);
    *P_LVALUE_51 = PrtCloneValue(P_VAR_emailEnclaveSSM);
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = ((_P_GEN_funargs[0] = &(PTMP_tmp8)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp8), PTMP_tmp8 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_11;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_11;
    }
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = PrtCloneValue(PrtCastValue(PTMP_tmp9, &P_GEND_TYPE_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp_6 = PrtCloneValue(&(P_LIT_INT32_5));
    _P_GEN_funargs[0] = &(PTMP_tmp6_2);
    _P_GEN_funargs[1] = &(PTMP_tmp7);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_6);
    _P_GEN_funargs[3] = &(PTMP_tmp10);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_11;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_11;
    }
    
p_return_11: ;
    PrtFreeValue(P_VAR_emailEnclaveSSM); P_VAR_emailEnclaveSSM = NULL;
    PrtFreeValue(PTMP_tmp0_9); PTMP_tmp0_9 = NULL;
    PrtFreeValue(PTMP_tmp1_7); PTMP_tmp1_7 = NULL;
    PrtFreeValue(PTMP_tmp2_6); PTMP_tmp2_6 = NULL;
    PrtFreeValue(PTMP_tmp3_4); PTMP_tmp3_4 = NULL;
    PrtFreeValue(PTMP_tmp4_3); PTMP_tmp4_3 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_2); PTMP_tmp6_2 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_10 =
{
    NULL,
    &P_Anon_IMPL_10,
    &P_GEND_TYPE_machine_handle
};


PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_7 = argRefs[0];
    PRT_VALUE* P_VAR_emailEnclaveSSM_1 = PrtMkDefaultValue(&P_GEND_TYPE_secure_machine_handle);
    PRT_VALUE* PTMP_tmp0_10 = NULL;
    PRT_VALUE* PTMP_tmp1_8 = NULL;
    PRT_VALUE* PTMP_tmp2_7 = NULL;
    PRT_VALUE* PTMP_tmp3_5 = NULL;
    PRT_VALUE* PTMP_tmp4_4 = NULL;
    PRT_VALUE* PTMP_tmp5_3 = NULL;
    PRT_VALUE* PTMP_tmp6_3 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8_1 = NULL;
    PRT_VALUE* PTMP_tmp9_1 = NULL;
    PRT_VALUE* PTMP_tmp10_1 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_1 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE P_LIT_BOOLEAN_2 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp0_10);
    PrtFreeValue(*P_LVALUE_54);
    *P_LVALUE_54 = PrtTupleGet(*P_VAR_payload_7, 0);
    
    {
        PRT_VALUE** P_LVALUE_55 = &(P_VAR_emailEnclaveSSM_1);
        PrtFreeValue(*P_LVALUE_55);
        *P_LVALUE_55 = PTMP_tmp0_10;
        PTMP_tmp0_10 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp1_8);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = (PrtMkNondetBoolValue());
    
    if (PrtPrimGetBool(PTMP_tmp1_8))
    {
        PRT_VALUE** P_LVALUE_57 = &(PTMP_tmp2_7);
        PrtFreeValue(*P_LVALUE_57);
        *P_LVALUE_57 = PrtCloneValue(P_VAR_emailEnclaveSSM_1);
        
        PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp3_5);
        PrtFreeValue(*P_LVALUE_58);
        *P_LVALUE_58 = PrtCloneValue((&P_EVENT_TRUSTEDSpamResultEvent.value));
        
        PRT_VALUE** P_LVALUE_59 = &(PTMP_tmp4_4);
        PrtFreeValue(*P_LVALUE_59);
        *P_LVALUE_59 = PrtCloneValue((&P_LIT_BOOLEAN_1));
        
        PRT_VALUE** P_LVALUE_60 = &(PTMP_tmp5_3);
        PrtFreeValue(*P_LVALUE_60);
        *P_LVALUE_60 = ((_P_GEN_funargs[0] = &(PTMP_tmp4_4)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp4_4), PTMP_tmp4_4 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_12;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_12;
        }
        
        PRT_VALUE** P_LVALUE_61 = &(PTMP_tmp6_3);
        PrtFreeValue(*P_LVALUE_61);
        *P_LVALUE_61 = PrtCloneValue(PrtCastValue(PTMP_tmp5_3, &P_GEND_TYPE_sb));
        
        PRT_VALUE* P_PTMP_tmp_7 = PrtCloneValue(&(P_LIT_INT32_6));
        _P_GEN_funargs[0] = &(PTMP_tmp2_7);
        _P_GEN_funargs[1] = &(PTMP_tmp3_5);
        _P_GEN_funargs[2] = &(P_PTMP_tmp_7);
        _P_GEN_funargs[3] = &(PTMP_tmp6_3);
        PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_12;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_12;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_62 = &(PTMP_tmp7_1);
        PrtFreeValue(*P_LVALUE_62);
        *P_LVALUE_62 = PrtCloneValue(P_VAR_emailEnclaveSSM_1);
        
        PRT_VALUE** P_LVALUE_63 = &(PTMP_tmp8_1);
        PrtFreeValue(*P_LVALUE_63);
        *P_LVALUE_63 = PrtCloneValue((&P_EVENT_TRUSTEDSpamResultEvent.value));
        
        PRT_VALUE** P_LVALUE_64 = &(PTMP_tmp9_1);
        PrtFreeValue(*P_LVALUE_64);
        *P_LVALUE_64 = PrtCloneValue((&P_LIT_BOOLEAN_2));
        
        PRT_VALUE** P_LVALUE_65 = &(PTMP_tmp10_1);
        PrtFreeValue(*P_LVALUE_65);
        *P_LVALUE_65 = ((_P_GEN_funargs[0] = &(PTMP_tmp9_1)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp9_1), PTMP_tmp9_1 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_12;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_12;
        }
        
        PRT_VALUE** P_LVALUE_66 = &(PTMP_tmp11);
        PrtFreeValue(*P_LVALUE_66);
        *P_LVALUE_66 = PrtCloneValue(PrtCastValue(PTMP_tmp10_1, &P_GEND_TYPE_sb));
        
        PRT_VALUE* P_PTMP_tmp_8 = PrtCloneValue(&(P_LIT_INT32_6));
        _P_GEN_funargs[0] = &(PTMP_tmp7_1);
        _P_GEN_funargs[1] = &(PTMP_tmp8_1);
        _P_GEN_funargs[2] = &(P_PTMP_tmp_8);
        _P_GEN_funargs[3] = &(PTMP_tmp11);
        PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_12;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_12;
        }
        
    }
    
    
p_return_12: ;
    PrtFreeValue(P_VAR_emailEnclaveSSM_1); P_VAR_emailEnclaveSSM_1 = NULL;
    PrtFreeValue(PTMP_tmp0_10); PTMP_tmp0_10 = NULL;
    PrtFreeValue(PTMP_tmp1_8); PTMP_tmp1_8 = NULL;
    PrtFreeValue(PTMP_tmp2_7); PTMP_tmp2_7 = NULL;
    PrtFreeValue(PTMP_tmp3_5); PTMP_tmp3_5 = NULL;
    PrtFreeValue(PTMP_tmp4_4); PTMP_tmp4_4 = NULL;
    PrtFreeValue(PTMP_tmp5_3); PTMP_tmp5_3 = NULL;
    PrtFreeValue(PTMP_tmp6_3); PTMP_tmp6_3 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8_1); PTMP_tmp8_1 = NULL;
    PrtFreeValue(PTMP_tmp9_1); PTMP_tmp9_1 = NULL;
    PrtFreeValue(PTMP_tmp10_1); PTMP_tmp10_1 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_11 =
{
    NULL,
    &P_Anon_IMPL_11,
    &P_GEND_TYPE_T2secure_machine_handlesecure_StringType
};


PRT_FUNDECL* P_SecureSpamFilter_METHODS[] = { &P_FUNCTION_Anon_10, &P_FUNCTION_Anon_11 };

PRT_EVENTDECL* P_SecureSpamFilter_RECV_INNER_1[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSpamFilter_RECV_1 =
{
    10U,
    P_SecureSpamFilter_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_SecureSpamFilter_SEND_INNER[] = { &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDSpamResultEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_SecureSpamFilter_SEND =
{
    10U,
    P_SecureSpamFilter_SEND_INNER,
    NULL
};

PRT_UINT32 P_SecureSpamFilter_CREATES_ARR[] = { 0 };
PRT_INTERFACESETDECL P_SecureSpamFilter_CREATES = { 1, P_SecureSpamFilter_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_SecureSpamFilter = 
{
    4U,
    "SecureSpamFilter",
    &P_EVENTSET_SecureSpamFilter_RECV_1,
    &P_EVENTSET_SecureSpamFilter_SEND,
    &P_SecureSpamFilter_CREATES,
    0U,
    1U,
    2U,
    4294967295U,
    0U,
    NULL,
    P_SecureSpamFilter_STATES,
    P_SecureSpamFilter_METHODS,
    PRT_TRUE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_TYPE* P_TYPEDEF_machine_handle = &P_GEND_TYPE_machine_handle;
PRT_TYPE* P_TYPEDEF_capability = &P_GEND_TYPE_capability;
PRT_TYPE* P_TYPEDEF_secure_machine_handle = &P_GEND_TYPE_secure_machine_handle;
PRT_TYPE* P_TYPEDEF_secure_StringType = &P_GEND_TYPE_secure_StringType;
PRT_TYPE* P_TYPEDEF_sealed_data = &P_GEND_TYPE_sealed_data;
PRT_TYPE* P_TYPEDEF_sealed_data_key = &P_GEND_TYPE_sealed_data_key;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_UNTRUSTEDSecureSpamFilterIDEvent, &P_EVENT_UNTRUSTEDReceiveEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDEmailEnclaveIDEvent, &P_EVENT_UNTRUSTEDEmailBodyEvent, &P_EVENT_UNTRUSTEDSpamResultEvent, &P_EVENT_TRUSTEDSecureSpamFilterIDEvent, &P_EVENT_TRUSTEDProvisionEmailUserEnclave, &P_EVENT_TRUSTEDEmailBodyEvent, &P_EVENT_TRUSTEDSpamResultEvent };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_EmailUserEnclave, &P_MACHINE_EmailUser, &P_MACHINE_UntrustedInitializer, &P_MACHINE_TrustedInitializer, &P_MACHINE_SecureSpamFilter };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_EmailUserEnclave, &P_I_EmailUser, &P_I_UntrustedInitializer, &P_I_TrustedInitializer, &P_I_SecureSpamFilter };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { &P_FUNCTION_seal };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_machine_handle, &P_StringType, &P_secure_machine_handle, &P_secure_StringType, &P_sealed_data_key, &P_sealed_data, &P_capability };
int P_DefaultImpl_LME_0[] = { -1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1,3,-1 };
int P_DefaultImpl_LME_3[] = { -1,1,-1,-1,4 };
int P_DefaultImpl_LME_4[] = { 0,-1,-1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3, P_DefaultImpl_LME_4 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3,4 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    11U,
    5U,
    5U,
    1U,
    7U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};

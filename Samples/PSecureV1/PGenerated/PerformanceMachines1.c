#include "PerformanceMachines1.h"

// Type universe for program:
static PRT_STRING P_NMDTUP_N[] = { "fst", "snd" };
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
static PRT_TYPE* P_NMDTUP_T[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_StringType };
static PRT_NMDTUPTYPE P_NMDTUP = { 2U, P_NMDTUP_N, P_NMDTUP_T };
static PRT_TYPE P_GEND_TYPE_T2iStringType = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP } };
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
static PRT_STRING P_NMDTUP_N_1[] = { "usernamePW", "OTPCode" };
static PRT_TYPE* P_NMDTUP_T_1[] = { &P_GEND_TYPE_StringType, &P_GEND_TYPE_StringType };
static PRT_NMDTUPTYPE P_NMDTUP_1 = { 2U, P_NMDTUP_N_1, P_NMDTUP_T_1 };
static PRT_TYPE P_GEND_TYPE_T2StringTypeStringType = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_1 } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
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
static PRT_STRING P_NMDTUP_N_2[] = { "fst", "snd" };
static PRT_TYPE P_GEND_TYPE_s = { PRT_KIND_SECURE_INT, { NULL } };
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
static PRT_TYPE* P_NMDTUP_T_2[] = { &P_GEND_TYPE_s, &P_GEND_TYPE_secure_StringType };
static PRT_NMDTUPTYPE P_NMDTUP_2 = { 2U, P_NMDTUP_N_2, P_NMDTUP_T_2 };
static PRT_TYPE P_GEND_TYPE_T2ssecure_StringType = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_2 } };
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_s, &P_GEND_TYPE_s };
static PRT_TYPE P_GEND_TYPE_MKsVs = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };
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

// Function implementation prototypes:
PRT_VALUE* P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintRawStringType_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintRawSecureStringType_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Concat_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Hash_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GenerateRandomMasterSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetHelloWorld_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_MeasureTime_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_EXIT_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Declassify_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Endorse_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GenerateSealedData_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_seal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_seal;

PRT_VALUE* P_unseal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_localAuthenticate_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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

PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_12;

PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_13;


PRT_EVENTDECL P_EVENT_MeasureEvent1 = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MeasureEvent1",
    4294967295U,
    &P_GEND_TYPE_T2iStringType,
    0
};

PRT_EVENTDECL P_EVENT_MeasureEvent2 = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MeasureEvent2",
    4294967295U,
    &P_GEND_TYPE_T2iStringType,
    0
};

PRT_EVENTDECL P_EVENT_BankPublicIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "BankPublicIDEvent",
    4294967295U,
    &P_GEND_TYPE_machine_handle,
    0
};

PRT_EVENTDECL P_EVENT_PublicIDEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "PublicIDEvent",
    4294967295U,
    &P_GEND_TYPE_machine_handle,
    0
};

PRT_EVENTDECL P_EVENT_UNTRUSTEDReceiveRegistrationCredentials = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDReceiveRegistrationCredentials",
    4294967295U,
    &P_GEND_TYPE_StringType,
    0
};

PRT_EVENTDECL P_EVENT_GenerateOTPCodeEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "GenerateOTPCodeEvent",
    4294967295U,
    &P_GEND_TYPE_StringType,
    0
};

PRT_EVENTDECL P_EVENT_OTPCodeEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "OTPCodeEvent",
    4294967295U,
    &P_GEND_TYPE_StringType,
    0
};

PRT_EVENTDECL P_EVENT_AuthenticateRequest = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "AuthenticateRequest",
    4294967295U,
    &P_GEND_TYPE_T2StringTypeStringType,
    0
};

PRT_EVENTDECL P_EVENT_AuthSuccess = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "AuthSuccess",
    4294967295U,
    &P_GEND_TYPE_n,
    0
};

PRT_EVENTDECL P_EVENT_AuthFailure = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "AuthFailure",
    4294967295U,
    &P_GEND_TYPE_n,
    0
};

PRT_EVENTDECL P_EVENT_TRUSTEDProvisionBankSSM = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDProvisionBankSSM",
    4294967295U,
    &P_GEND_TYPE_secure_machine_handle,
    1
};

PRT_EVENTDECL P_EVENT_TRUSTEDProvisionClientSSM = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDProvisionClientSSM",
    4294967295U,
    &P_GEND_TYPE_secure_machine_handle,
    1
};

PRT_EVENTDECL P_EVENT_TRUSTEDMeasureEvent1 = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDMeasureEvent1",
    4294967295U,
    &P_GEND_TYPE_T2ssecure_StringType,
    1
};

PRT_EVENTDECL P_EVENT_TRUSTEDMeasureEvent2 = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDMeasureEvent2",
    4294967295U,
    &P_GEND_TYPE_T2ssecure_StringType,
    1
};

PRT_EVENTDECL P_EVENT_MasterSecretEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MasterSecretEvent",
    4294967295U,
    &P_GEND_TYPE_secure_StringType,
    1
};

PRT_EVENTDECL P_EVENT_MapEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MapEvent",
    4294967295U,
    &P_GEND_TYPE_MKsVs,
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


PRT_FUNDECL P_FUNCTION_Concat =
{
    "Concat",
    &P_Concat_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_Hash =
{
    "Hash",
    &P_Hash_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_PrintKey =
{
    "PrintKey",
    &P_PrintKey_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GenerateRandomMasterSecret =
{
    "GenerateRandomMasterSecret",
    &P_GenerateRandomMasterSecret_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetHelloWorld =
{
    "GetHelloWorld",
    &P_GetHelloWorld_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_MeasureTime =
{
    "MeasureTime",
    &P_MeasureTime_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_EXIT =
{
    "EXIT",
    &P_EXIT_IMPL,
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
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_sealed_data);
    PRT_VALUE** P_VAR_input = argRefs[0];
    PRT_VALUE* PTMP_tmp0 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtCloneValue(*P_VAR_input);
    
    PRT_VALUE** P_LVALUE_1 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_1);
    *P_LVALUE_1 = ((_P_GEN_funargs[0] = &(PTMP_tmp0)), (_P_GEN_funval = P_GenerateSealedData_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0), PTMP_tmp0 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(PTMP_tmp1);
    goto p_return;
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
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


PRT_FUNDECL P_FUNCTION_localAuthenticate =
{
    "localAuthenticate",
    &P_localAuthenticate_IMPL,
    NULL
};


PRT_EVENTDECL* P_UntrustedInitializer_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_RECV =
{
    17U,
    P_UntrustedInitializer_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_UntrustedInitializer =
{
    0U,
    "UntrustedInitializer",
    &P_GEND_TYPE_n,
    &P_EVENTSET_UntrustedInitializer_RECV
};

PRT_EVENTDECL* P_TrustedInitializer_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_RECV =
{
    17U,
    P_TrustedInitializer_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_TrustedInitializer =
{
    1U,
    "TrustedInitializer",
    &P_GEND_TYPE_n,
    &P_EVENTSET_TrustedInitializer_RECV
};

PRT_EVENTDECL* P_BankEnclave_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_RECV =
{
    17U,
    P_BankEnclave_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_BankEnclave =
{
    2U,
    "BankEnclave",
    &P_GEND_TYPE_n,
    &P_EVENTSET_BankEnclave_RECV
};

PRT_EVENTDECL* P_TempMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TempMachine_RECV =
{
    17U,
    P_TempMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_TempMachine =
{
    3U,
    "TempMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_TempMachine_RECV
};

PRT_EVENTDECL* P_MeasureMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MeasureMachine_RECV =
{
    17U,
    P_MeasureMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_MeasureMachine =
{
    4U,
    "MeasureMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_MeasureMachine_RECV
};

PRT_EVENTDECL* P_MeasureMachine2_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MeasureMachine2_RECV =
{
    17U,
    P_MeasureMachine2_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_MeasureMachine2 =
{
    5U,
    "MeasureMachine2",
    &P_GEND_TYPE_n,
    &P_EVENTSET_MeasureMachine2_RECV
};

PRT_EVENTDECL* P_ClientEnclave_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_RECV =
{
    17U,
    P_ClientEnclave_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ClientEnclave =
{
    6U,
    "ClientEnclave",
    &P_GEND_TYPE_n,
    &P_EVENTSET_ClientEnclave_RECV
};

PRT_EVENTDECL* P_ClientWebBrowser_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_RECV =
{
    17U,
    P_ClientWebBrowser_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ClientWebBrowser =
{
    7U,
    "ClientWebBrowser",
    &P_GEND_TYPE_n,
    &P_EVENTSET_ClientWebBrowser_RECV
};

PRT_VARDECL P_UntrustedInitializer_VARS[] = {
    { "handler", &P_GEND_TYPE_machine_handle }
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

#define P_STATE_UntrustedInitializer_Initial \
{ \
    "UntrustedInitializer.Initial", \
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

PRT_STATEDECL P_UntrustedInitializer_STATES[] = { P_STATE_UntrustedInitializer_Initial };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
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
    _P_GEN_funargs[0] = "TempMachine";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = NULL;
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
    
    PrtPrintf("MEASURE UNTRUSTED CREATE START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    _P_GEN_funargs[0] = "MeasureMachine";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = NULL;
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_5 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_5);
        *P_LVALUE_5 = PTMP_tmp1_1;
        PTMP_tmp1_1 = NULL;
    }
    
    PrtPrintf("MEASURE UNTRUSTED CREATE SSM START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    _P_GEN_funargs[0] = "MeasureMachine2";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = NULL;
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_7 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_7);
        *P_LVALUE_7 = PTMP_tmp2;
        PTMP_tmp2 = NULL;
    }
    
    _P_GEN_funargs[0] = "TrustedInitializer";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE* P_this_ref = (P_GetThis_IMPL(context, _P_GEN_funargs));
    _P_GEN_funargs[2] = &P_this_ref;
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
    {
        PRT_VALUE** P_LVALUE_9 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_9);
        *P_LVALUE_9 = PTMP_tmp3;
        PTMP_tmp3 = NULL;
    }
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL
};


PRT_FUNDECL* P_UntrustedInitializer_METHODS[] = { &P_FUNCTION_Anon };

PRT_EVENTDECL* P_UntrustedInitializer_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_RECV_1 =
{
    17U,
    P_UntrustedInitializer_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_UntrustedInitializer_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_SEND =
{
    17U,
    P_UntrustedInitializer_SEND_INNER,
    NULL
};

PRT_UINT32 P_UntrustedInitializer_CREATES_ARR[] = { 4, 5, 3, 1 };
PRT_INTERFACESETDECL P_UntrustedInitializer_CREATES = { 4, P_UntrustedInitializer_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_UntrustedInitializer = 
{
    0U,
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
    { "clientUSM", &P_GEND_TYPE_machine_handle },
    { "bankSSM", &P_GEND_TYPE_secure_machine_handle }
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

#define P_STATE_TrustedInitializer_Initial \
{ \
    "TrustedInitializer.Initial", \
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

PRT_STATEDECL P_TrustedInitializer_STATES[] = { P_STATE_TrustedInitializer_Initial };

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    _P_GEN_funargs[0] = "ClientWebBrowser";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = NULL;
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_11 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_11);
        *P_LVALUE_11 = PTMP_tmp0_2;
        PTMP_tmp0_2 = NULL;
    }
    
    _P_GEN_funargs[0] = "BankEnclave";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE* P_this_ref_1 = (P_GetThis_IMPL(context, _P_GEN_funargs));
    _P_GEN_funargs[2] = &P_this_ref_1;
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_13 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_13);
        *P_LVALUE_13 = PTMP_tmp1_2;
        PTMP_tmp1_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtCloneValue((&P_EVENT_TRUSTEDProvisionBankSSM.value));
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = ((_P_GEN_funargs[0] = &(PTMP_tmp4)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp4), PTMP_tmp4 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_18);
    *P_LVALUE_18 = PrtCloneValue(PrtCastValue(PTMP_tmp5, &P_GEND_TYPE_secure_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32));
    _P_GEN_funargs[0] = &(PTMP_tmp2_1);
    _P_GEN_funargs[1] = &(PTMP_tmp3_1);
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
    
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = PrtCloneValue((&P_EVENT_BankPublicIDEvent.value));
    
    PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = ((_P_GEN_funargs[0] = &(PTMP_tmp9)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp9), PTMP_tmp9 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp11);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = PrtCloneValue(PrtCastValue(PTMP_tmp10, &P_GEND_TYPE_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp_1 = PrtCloneValue(&(P_LIT_INT32));
    _P_GEN_funargs[0] = &(PTMP_tmp7);
    _P_GEN_funargs[1] = &(PTMP_tmp8);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_1);
    _P_GEN_funargs[3] = &(PTMP_tmp11);
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
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_FUNDECL* P_TrustedInitializer_METHODS[] = { &P_FUNCTION_Anon_1 };

PRT_EVENTDECL* P_TrustedInitializer_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_RECV_1 =
{
    17U,
    P_TrustedInitializer_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_TrustedInitializer_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_SEND =
{
    17U,
    P_TrustedInitializer_SEND_INNER,
    NULL
};

PRT_UINT32 P_TrustedInitializer_CREATES_ARR[] = { 2, 7 };
PRT_INTERFACESETDECL P_TrustedInitializer_CREATES = { 2, P_TrustedInitializer_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_TrustedInitializer = 
{
    1U,
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

PRT_VARDECL P_BankEnclave_VARS[] = {
    { "clientSSM", &P_GEND_TYPE_secure_machine_handle },
    { "clientUSM", &P_GEND_TYPE_machine_handle },
    { "masterSecret", &P_GEND_TYPE_secure_StringType },
    { "userCredential", &P_GEND_TYPE_secure_StringType }
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

PRT_EVENTDECL* P_ReceiveClientUSM_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReceiveClientUSM_DEFERS =
{
    0U,
    P_ReceiveClientUSM_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReceiveClientUSM_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReceiveClientUSM_TRANS =
{
    0U,
    P_ReceiveClientUSM_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReceiveClientUSM_DOS_INNER[] = { &P_EVENT_TRUSTEDProvisionBankSSM };
PRT_EVENTSETDECL P_EVENTSET_ReceiveClientUSM_DOS =
{
    1U,
    P_ReceiveClientUSM_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS[] =
{
    { 1, &P_EVENT_TRUSTEDProvisionBankSSM, &P_FUNCTION_Anon_3 }
};

#define P_STATE_BankEnclave_ReceiveClientUSM \
{ \
    "BankEnclave.ReceiveClientUSM", \
    0U, \
    1U, \
    &P_EVENTSET_ReceiveClientUSM_DEFERS, \
    &P_EVENTSET_ReceiveClientUSM_TRANS, \
    &P_EVENTSET_ReceiveClientUSM_DOS, \
    NULL, \
    P_DOS, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_RegisterNewBankAccount_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RegisterNewBankAccount_DEFERS =
{
    0U,
    P_RegisterNewBankAccount_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_RegisterNewBankAccount_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RegisterNewBankAccount_TRANS =
{
    0U,
    P_RegisterNewBankAccount_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_RegisterNewBankAccount_DOS_INNER[] = { &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2 };
PRT_EVENTSETDECL P_EVENTSET_RegisterNewBankAccount_DOS =
{
    2U,
    P_RegisterNewBankAccount_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_1[] =
{
    { 2, &P_EVENT_MeasureEvent1, &P_FUNCTION_Anon_4 },
    { 2, &P_EVENT_MeasureEvent2, &P_FUNCTION_Anon_5 }
};

#define P_STATE_BankEnclave_RegisterNewBankAccount \
{ \
    "BankEnclave.RegisterNewBankAccount", \
    0U, \
    2U, \
    &P_EVENTSET_RegisterNewBankAccount_DEFERS, \
    &P_EVENTSET_RegisterNewBankAccount_TRANS, \
    &P_EVENTSET_RegisterNewBankAccount_DOS, \
    NULL, \
    P_DOS_1, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_BankEnclave_STATES[] = { P_STATE_BankEnclave_Initial, P_STATE_BankEnclave_ReceiveClientUSM, P_STATE_BankEnclave_RegisterNewBankAccount };

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtGoto(p_this, 1U, 0);
    
p_return_3: ;
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
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8_1 = NULL;
    PRT_VALUE* PTMP_tmp9_1 = NULL;
    PRT_VALUE* PTMP_tmp10_1 = NULL;
    PRT_VALUE* PTMP_tmp11_1 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    PRT_VALUE* PTMP_tmp17 = NULL;
    PRT_VALUE* PTMP_tmp18 = NULL;
    PRT_VALUE* PTMP_tmp19 = NULL;
    PRT_VALUE* PTMP_tmp20 = NULL;
    PRT_VALUE* PTMP_tmp21 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = PrtCloneValue(*P_VAR_payload);
    
    PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_3)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_3), PTMP_tmp0_3 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_26 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue(PrtCastValue(PTMP_tmp1_3, &P_GEND_TYPE_machine_handle));
    
    {
        PRT_VALUE** P_LVALUE_27 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_27);
        *P_LVALUE_27 = PTMP_tmp2_2;
        PTMP_tmp2_2 = NULL;
    }
    
    PrtPrintf("MEASURE TRUSTED CREATE START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    _P_GEN_funargs[0] = "ClientEnclave";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = &(p_this->varValues[1]);
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_29 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_29);
        *P_LVALUE_29 = PTMP_tmp3_2;
        PTMP_tmp3_2 = NULL;
    }
    
    PrtPrintf("MEASURE TRUSTED SEND START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_31);
    *P_LVALUE_31 = PrtCloneValue((&P_EVENT_TRUSTEDMeasureEvent1.value));
    
    PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_32);
    *P_LVALUE_32 = PrtCloneValue((&P_LIT_INT32_1));
    
    PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp7_1);
    PrtFreeValue(*P_LVALUE_33);
    *P_LVALUE_33 = ((_P_GEN_funargs[0] = &(PTMP_tmp6_1)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp6_1), PTMP_tmp6_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_34 = &(PTMP_tmp8_1);
    PrtFreeValue(*P_LVALUE_34);
    *P_LVALUE_34 = PrtCloneValue(PrtCastValue(PTMP_tmp7_1, &P_GEND_TYPE_s));
    
    PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp9_1);
    PrtFreeValue(*P_LVALUE_35);
    *P_LVALUE_35 = ((_P_GEN_funval = P_GetHelloWorld_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp10_1);
    PrtFreeValue(*P_LVALUE_36);
    *P_LVALUE_36 = ((_P_GEN_funargs[0] = &(PTMP_tmp9_1)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp9_1), PTMP_tmp9_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_37 = &(PTMP_tmp11_1);
    PrtFreeValue(*P_LVALUE_37);
    *P_LVALUE_37 = PrtCloneValue(PrtCastValue(PTMP_tmp10_1, &P_GEND_TYPE_secure_StringType));
    
    PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp12);
    PrtFreeValue(*P_LVALUE_38);
    *P_LVALUE_38 = (PrtMkTuple(&P_GEND_TYPE_T2ssecure_StringType, &(PTMP_tmp8_1), &(PTMP_tmp11_1)));
    
    PRT_VALUE* P_PTMP_tmp_2 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp4_1);
    _P_GEN_funargs[1] = &(PTMP_tmp5_1);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_2);
    _P_GEN_funargs[3] = &(PTMP_tmp12);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PrtPrintf("MEASURE TRUSTED SEND 2 START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_39 = &(PTMP_tmp13);
    PrtFreeValue(*P_LVALUE_39);
    *P_LVALUE_39 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp14);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = PrtCloneValue((&P_EVENT_TRUSTEDMeasureEvent2.value));
    
    PRT_VALUE** P_LVALUE_41 = &(PTMP_tmp15);
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = PrtCloneValue((&P_LIT_INT32_1));
    
    PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp16);
    PrtFreeValue(*P_LVALUE_42);
    *P_LVALUE_42 = ((_P_GEN_funargs[0] = &(PTMP_tmp15)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp15), PTMP_tmp15 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp17);
    PrtFreeValue(*P_LVALUE_43);
    *P_LVALUE_43 = PrtCloneValue(PrtCastValue(PTMP_tmp16, &P_GEND_TYPE_s));
    
    PRT_VALUE** P_LVALUE_44 = &(PTMP_tmp18);
    PrtFreeValue(*P_LVALUE_44);
    *P_LVALUE_44 = ((_P_GEN_funval = P_GetHelloWorld_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp19);
    PrtFreeValue(*P_LVALUE_45);
    *P_LVALUE_45 = ((_P_GEN_funargs[0] = &(PTMP_tmp18)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp18), PTMP_tmp18 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp20);
    PrtFreeValue(*P_LVALUE_46);
    *P_LVALUE_46 = PrtCloneValue(PrtCastValue(PTMP_tmp19, &P_GEND_TYPE_secure_StringType));
    
    PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp21);
    PrtFreeValue(*P_LVALUE_47);
    *P_LVALUE_47 = (PrtMkTuple(&P_GEND_TYPE_T2ssecure_StringType, &(PTMP_tmp17), &(PTMP_tmp20)));
    
    PRT_VALUE* P_PTMP_tmp_3 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp13);
    _P_GEN_funargs[1] = &(PTMP_tmp14);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_3);
    _P_GEN_funargs[3] = &(PTMP_tmp21);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PrtGoto(p_this, 2U, 0);
    
p_return_4: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8_1); PTMP_tmp8_1 = NULL;
    PrtFreeValue(PTMP_tmp9_1); PTMP_tmp9_1 = NULL;
    PrtFreeValue(PTMP_tmp10_1); PTMP_tmp10_1 = NULL;
    PrtFreeValue(PTMP_tmp11_1); PTMP_tmp11_1 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    PrtFreeValue(PTMP_tmp17); PTMP_tmp17 = NULL;
    PrtFreeValue(PTMP_tmp18); PTMP_tmp18 = NULL;
    PrtFreeValue(PTMP_tmp19); PTMP_tmp19 = NULL;
    PrtFreeValue(PTMP_tmp20); PTMP_tmp20 = NULL;
    PrtFreeValue(PTMP_tmp21); PTMP_tmp21 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_secure_machine_handle
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE UNTRUSTED SEND END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
p_return_5: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    &P_GEND_TYPE_T2iStringType
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE UNTRUSTED SEND 2 END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PrtFreeValue(P_EXIT_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
p_return_6: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_T2iStringType
};


PRT_FUNDECL* P_BankEnclave_METHODS[] = { &P_FUNCTION_Anon_2, &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5 };

PRT_EVENTDECL* P_BankEnclave_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_RECV_1 =
{
    17U,
    P_BankEnclave_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_BankEnclave_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_SEND =
{
    17U,
    P_BankEnclave_SEND_INNER,
    NULL
};

PRT_UINT32 P_BankEnclave_CREATES_ARR[] = { 6 };
PRT_INTERFACESETDECL P_BankEnclave_CREATES = { 1, P_BankEnclave_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_BankEnclave = 
{
    2U,
    "BankEnclave",
    &P_EVENTSET_BankEnclave_RECV_1,
    &P_EVENTSET_BankEnclave_SEND,
    &P_BankEnclave_CREATES,
    4U,
    3U,
    4U,
    4294967295U,
    0U,
    P_BankEnclave_VARS,
    P_BankEnclave_STATES,
    P_BankEnclave_METHODS,
    PRT_TRUE
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

#define P_STATE_TempMachine_Initial \
{ \
    "TempMachine.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_3, \
    &P_EVENTSET_Initial_TRANS_3, \
    &P_EVENTSET_Initial_DOS_3, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_6, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_TempMachine_STATES[] = { P_STATE_TempMachine_Initial };

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("Temp machine created to prevent first call from influencing results");
    
p_return_7: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    NULL
};


PRT_FUNDECL* P_TempMachine_METHODS[] = { &P_FUNCTION_Anon_6 };

PRT_EVENTDECL* P_TempMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TempMachine_RECV_1 =
{
    17U,
    P_TempMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_TempMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TempMachine_SEND =
{
    17U,
    P_TempMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_TempMachine = 
{
    3U,
    "TempMachine",
    &P_EVENTSET_TempMachine_RECV_1,
    &P_EVENTSET_TempMachine_SEND,
    NULL,
    0U,
    1U,
    1U,
    4294967295U,
    0U,
    NULL,
    P_TempMachine_STATES,
    P_TempMachine_METHODS,
    PRT_FALSE
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

PRT_EVENTDECL* P_Initial_DOS_INNER_4[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_4 =
{
    0U,
    P_Initial_DOS_INNER_4,
    NULL
};

#define P_STATE_MeasureMachine_Initial \
{ \
    "MeasureMachine.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_4, \
    &P_EVENTSET_Initial_TRANS_4, \
    &P_EVENTSET_Initial_DOS_4, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_7, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_MeasureMachine_STATES[] = { P_STATE_MeasureMachine_Initial };

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE UNTRUSTED CREATE END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
p_return_8: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    NULL
};


PRT_FUNDECL* P_MeasureMachine_METHODS[] = { &P_FUNCTION_Anon_7 };

PRT_EVENTDECL* P_MeasureMachine_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MeasureMachine_RECV_1 =
{
    17U,
    P_MeasureMachine_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_MeasureMachine_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MeasureMachine_SEND =
{
    17U,
    P_MeasureMachine_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_MeasureMachine = 
{
    4U,
    "MeasureMachine",
    &P_EVENTSET_MeasureMachine_RECV_1,
    &P_EVENTSET_MeasureMachine_SEND,
    NULL,
    0U,
    1U,
    1U,
    4294967295U,
    0U,
    NULL,
    P_MeasureMachine_STATES,
    P_MeasureMachine_METHODS,
    PRT_FALSE
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_5[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_5 =
{
    0U,
    P_Initial_DEFERS_INNER_5,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_5[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_5 =
{
    0U,
    P_Initial_TRANS_INNER_5,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER_5[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_5 =
{
    0U,
    P_Initial_DOS_INNER_5,
    NULL
};

#define P_STATE_MeasureMachine2_Initial \
{ \
    "MeasureMachine2.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_5, \
    &P_EVENTSET_Initial_TRANS_5, \
    &P_EVENTSET_Initial_DOS_5, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_8, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_MeasureMachine2_STATES[] = { P_STATE_MeasureMachine2_Initial };

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE UNTRUSTED CREATE SSM END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_9;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_9;
    }
    
p_return_9: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_8,
    NULL
};


PRT_FUNDECL* P_MeasureMachine2_METHODS[] = { &P_FUNCTION_Anon_8 };

PRT_EVENTDECL* P_MeasureMachine2_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MeasureMachine2_RECV_1 =
{
    17U,
    P_MeasureMachine2_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_MeasureMachine2_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MeasureMachine2_SEND =
{
    17U,
    P_MeasureMachine2_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_MeasureMachine2 = 
{
    5U,
    "MeasureMachine2",
    &P_EVENTSET_MeasureMachine2_RECV_1,
    &P_EVENTSET_MeasureMachine2_SEND,
    NULL,
    0U,
    1U,
    1U,
    4294967295U,
    0U,
    NULL,
    P_MeasureMachine2_STATES,
    P_MeasureMachine2_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_ClientEnclave_VARS[] = {
    { "masterSecret", &P_GEND_TYPE_secure_StringType },
    { "clientUSM", &P_GEND_TYPE_machine_handle }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_6[] = { &P_EVENT_GenerateOTPCodeEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_6 =
{
    1U,
    P_Initial_DEFERS_INNER_6,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_6[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_6 =
{
    0U,
    P_Initial_TRANS_INNER_6,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER_6[] = { &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2 };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_6 =
{
    2U,
    P_Initial_DOS_INNER_6,
    NULL
};

PRT_DODECL P_DOS_2[] =
{
    { 0, &P_EVENT_TRUSTEDMeasureEvent1, &P_FUNCTION_Anon_10 },
    { 0, &P_EVENT_TRUSTEDMeasureEvent2, &P_FUNCTION_Anon_11 }
};

#define P_STATE_ClientEnclave_Initial \
{ \
    "ClientEnclave.Initial", \
    0U, \
    2U, \
    &P_EVENTSET_Initial_DEFERS_6, \
    &P_EVENTSET_Initial_TRANS_6, \
    &P_EVENTSET_Initial_DOS_6, \
    NULL, \
    P_DOS_2, \
    &P_FUNCTION_Anon_9, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClientEnclave_STATES[] = { P_STATE_ClientEnclave_Initial };

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE TRUSTED CREATE END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
p_return_10: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_9 =
{
    NULL,
    &P_Anon_IMPL_9,
    NULL
};


PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE TRUSTED SEND END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_11;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_11;
    }
    
p_return_11: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_10 =
{
    NULL,
    &P_Anon_IMPL_10,
    &P_GEND_TYPE_T2ssecure_StringType
};


PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_4 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE TRUSTED SEND 2 END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
p_return_12: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_11 =
{
    NULL,
    &P_Anon_IMPL_11,
    &P_GEND_TYPE_T2ssecure_StringType
};


PRT_FUNDECL* P_ClientEnclave_METHODS[] = { &P_FUNCTION_Anon_9, &P_FUNCTION_Anon_10, &P_FUNCTION_Anon_11 };

PRT_EVENTDECL* P_ClientEnclave_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_RECV_1 =
{
    17U,
    P_ClientEnclave_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ClientEnclave_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_SEND =
{
    17U,
    P_ClientEnclave_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_ClientEnclave = 
{
    6U,
    "ClientEnclave",
    &P_EVENTSET_ClientEnclave_RECV_1,
    &P_EVENTSET_ClientEnclave_SEND,
    NULL,
    2U,
    1U,
    3U,
    4294967295U,
    0U,
    P_ClientEnclave_VARS,
    P_ClientEnclave_STATES,
    P_ClientEnclave_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_ClientWebBrowser_VARS[] = {
    { "clientSSM", &P_GEND_TYPE_machine_handle },
    { "bankSSM", &P_GEND_TYPE_machine_handle },
    { "usernamePassword", &P_GEND_TYPE_StringType },
    { "OTPCode", &P_GEND_TYPE_StringType }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_7[] = { &P_EVENT_PublicIDEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_7 =
{
    1U,
    P_Initial_DEFERS_INNER_7,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_7[] = { &P_EVENT_BankPublicIDEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_7 =
{
    1U,
    P_Initial_TRANS_INNER_7,
    NULL
};

PRT_EVENTDECL* P_Initial_DOS_INNER_7[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_7 =
{
    0U,
    P_Initial_DOS_INNER_7,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 0, &P_EVENT_BankPublicIDEvent, 1, &_P_NO_OP }
};

#define P_STATE_ClientWebBrowser_Initial \
{ \
    "ClientWebBrowser.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_7, \
    &P_EVENTSET_Initial_TRANS_7, \
    &P_EVENTSET_Initial_DOS_7, \
    P_TRANS, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_SaveBankSSM_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveBankSSM_DEFERS =
{
    0U,
    P_SaveBankSSM_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_SaveBankSSM_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveBankSSM_TRANS =
{
    0U,
    P_SaveBankSSM_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_SaveBankSSM_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SaveBankSSM_DOS =
{
    0U,
    P_SaveBankSSM_DOS_INNER,
    NULL
};

#define P_STATE_ClientWebBrowser_SaveBankSSM \
{ \
    "ClientWebBrowser.SaveBankSSM", \
    0U, \
    0U, \
    &P_EVENTSET_SaveBankSSM_DEFERS, \
    &P_EVENTSET_SaveBankSSM_TRANS, \
    &P_EVENTSET_SaveBankSSM_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_12, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_RegisterAccountInBank_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RegisterAccountInBank_DEFERS =
{
    0U,
    P_RegisterAccountInBank_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_RegisterAccountInBank_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RegisterAccountInBank_TRANS =
{
    0U,
    P_RegisterAccountInBank_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_RegisterAccountInBank_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RegisterAccountInBank_DOS =
{
    0U,
    P_RegisterAccountInBank_DOS_INNER,
    NULL
};

#define P_STATE_ClientWebBrowser_RegisterAccountInBank \
{ \
    "ClientWebBrowser.RegisterAccountInBank", \
    0U, \
    0U, \
    &P_EVENTSET_RegisterAccountInBank_DEFERS, \
    &P_EVENTSET_RegisterAccountInBank_TRANS, \
    &P_EVENTSET_RegisterAccountInBank_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_13, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClientWebBrowser_STATES[] = { P_STATE_ClientWebBrowser_Initial, P_STATE_ClientWebBrowser_SaveBankSSM, P_STATE_ClientWebBrowser_RegisterAccountInBank };

PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_5 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_48 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_48);
    *P_LVALUE_48 = PrtCloneValue(*P_VAR_payload_5);
    
    PrtGoto(p_this, 2U, 0);
    
p_return_13: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_12 =
{
    NULL,
    &P_Anon_IMPL_12,
    &P_GEND_TYPE_machine_handle
};


PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_2 = NULL;
    PRT_VALUE* PTMP_tmp7_2 = NULL;
    PRT_VALUE* PTMP_tmp8_2 = NULL;
    PRT_VALUE* PTMP_tmp9_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PrtPrintf("MEASURE UNTRUSTED SEND START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
    PRT_VALUE** P_LVALUE_49 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_49);
    *P_LVALUE_49 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_50);
    *P_LVALUE_50 = PrtCloneValue((&P_EVENT_MeasureEvent1.value));
    
    PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_51);
    *P_LVALUE_51 = PrtCloneValue((&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp3_3);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = ((_P_GEN_funval = P_GetHelloWorld_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp4_2);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = (PrtMkTuple(&P_GEND_TYPE_T2iStringType, &(PTMP_tmp2_3), &(PTMP_tmp3_3)));
    
    PRT_VALUE* P_PTMP_tmp_4 = PrtCloneValue(&(P_LIT_INT32_2));
    _P_GEN_funargs[0] = &(PTMP_tmp0_4);
    _P_GEN_funargs[1] = &(PTMP_tmp1_4);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_4);
    _P_GEN_funargs[3] = &(PTMP_tmp4_2);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
    PrtPrintf("MEASURE UNTRUSTED SEND 2 START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
    PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp5_2);
    PrtFreeValue(*P_LVALUE_54);
    *P_LVALUE_54 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp6_2);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtCloneValue((&P_EVENT_MeasureEvent2.value));
    
    PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp7_2);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = PrtCloneValue((&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_57 = &(PTMP_tmp8_2);
    PrtFreeValue(*P_LVALUE_57);
    *P_LVALUE_57 = ((_P_GEN_funval = P_GetHelloWorld_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
    PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp9_2);
    PrtFreeValue(*P_LVALUE_58);
    *P_LVALUE_58 = (PrtMkTuple(&P_GEND_TYPE_T2iStringType, &(PTMP_tmp7_2), &(PTMP_tmp8_2)));
    
    PRT_VALUE* P_PTMP_tmp_5 = PrtCloneValue(&(P_LIT_INT32_2));
    _P_GEN_funargs[0] = &(PTMP_tmp5_2);
    _P_GEN_funargs[1] = &(PTMP_tmp6_2);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_5);
    _P_GEN_funargs[3] = &(PTMP_tmp9_2);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
    PrtPrintf("Done!");
    
    PrtFreeValue(P_EXIT_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
p_return_14: ;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_2); PTMP_tmp6_2 = NULL;
    PrtFreeValue(PTMP_tmp7_2); PTMP_tmp7_2 = NULL;
    PrtFreeValue(PTMP_tmp8_2); PTMP_tmp8_2 = NULL;
    PrtFreeValue(PTMP_tmp9_2); PTMP_tmp9_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_13 =
{
    NULL,
    &P_Anon_IMPL_13,
    NULL
};


PRT_FUNDECL* P_ClientWebBrowser_METHODS[] = { &P_FUNCTION_Anon_12, &P_FUNCTION_Anon_13 };

PRT_EVENTDECL* P_ClientWebBrowser_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_RECV_1 =
{
    17U,
    P_ClientWebBrowser_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ClientWebBrowser_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_SEND =
{
    17U,
    P_ClientWebBrowser_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_ClientWebBrowser = 
{
    7U,
    "ClientWebBrowser",
    &P_EVENTSET_ClientWebBrowser_RECV_1,
    &P_EVENTSET_ClientWebBrowser_SEND,
    NULL,
    4U,
    3U,
    2U,
    4294967295U,
    0U,
    P_ClientWebBrowser_VARS,
    P_ClientWebBrowser_STATES,
    P_ClientWebBrowser_METHODS,
    PRT_FALSE
};

PRT_TYPE* P_TYPEDEF_StringType = &P_GEND_TYPE_StringType;
PRT_TYPE* P_TYPEDEF_machine_handle = &P_GEND_TYPE_machine_handle;
PRT_TYPE* P_TYPEDEF_capability = &P_GEND_TYPE_capability;
PRT_TYPE* P_TYPEDEF_secure_machine_handle = &P_GEND_TYPE_secure_machine_handle;
PRT_TYPE* P_TYPEDEF_secure_StringType = &P_GEND_TYPE_secure_StringType;
PRT_TYPE* P_TYPEDEF_sealed_data = &P_GEND_TYPE_sealed_data;
PRT_TYPE* P_TYPEDEF_sealed_data_key = &P_GEND_TYPE_sealed_data_key;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_BankPublicIDEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_AuthenticateRequest, &P_EVENT_AuthSuccess, &P_EVENT_AuthFailure, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_MasterSecretEvent, &P_EVENT_MapEvent };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_UntrustedInitializer, &P_MACHINE_TrustedInitializer, &P_MACHINE_BankEnclave, &P_MACHINE_TempMachine, &P_MACHINE_MeasureMachine, &P_MACHINE_MeasureMachine2, &P_MACHINE_ClientEnclave, &P_MACHINE_ClientWebBrowser };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_UntrustedInitializer, &P_I_TrustedInitializer, &P_I_BankEnclave, &P_I_TempMachine, &P_I_MeasureMachine, &P_I_MeasureMachine2, &P_I_ClientEnclave, &P_I_ClientWebBrowser };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { &P_FUNCTION_seal };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType, &P_machine_handle, &P_secure_machine_handle, &P_secure_StringType, &P_sealed_data, &P_capability, &P_sealed_data_key };
int P_DefaultImpl_LME_0[] = { -1,1,-1,3,4,5,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,2,-1,-1,-1,-1,7 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1,-1,-1,-1,6,-1 };
int P_DefaultImpl_LME_3[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_4[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_5[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_6[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_7[] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3, P_DefaultImpl_LME_4, P_DefaultImpl_LME_5, P_DefaultImpl_LME_6, P_DefaultImpl_LME_7 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3,4,5,6,7 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    18U,
    8U,
    8U,
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

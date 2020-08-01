#include "OTPBankServerCode.h"

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
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_machine_handle, &P_GEND_TYPE_StringType, &P_GEND_TYPE_StringType };
static PRT_TUPTYPE P_TUP = { 3U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T3machine_handleStringTypeStringType = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
static PRT_STRING P_NMDTUP_N[] = { "Username", "Password", "OTPCode" };
static PRT_TYPE* P_NMDTUP_T[] = { &P_GEND_TYPE_StringType, &P_GEND_TYPE_StringType, &P_GEND_TYPE_StringType };
static PRT_NMDTUPTYPE P_NMDTUP = { 3U, P_NMDTUP_N, P_NMDTUP_T };
static PRT_TYPE P_GEND_TYPE_T3StringTypeStringTypeStringType = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
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
static PRT_TYPE P_GEND_TYPE_s = { PRT_KIND_SECURE_INT, { NULL } };
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_s, &P_GEND_TYPE_s };
static PRT_TYPE P_GEND_TYPE_MKsVs = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };
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
static PRT_MAPTYPE P_MAPTYPE_1 = { &P_GEND_TYPE_secure_StringType, &P_GEND_TYPE_secure_StringType };
static PRT_TYPE P_GEND_TYPE_MKsecure_StringTypeVsecure_StringType = { PRT_KIND_MAP, { .map = &P_MAPTYPE_1 } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_MAPTYPE P_MAPTYPE_2 = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_MKiVi = { PRT_KIND_MAP, { .map = &P_MAPTYPE_2 } };
static PRT_TYPE* P_TUP_T_1[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TUPTYPE P_TUP_1 = { 2U, P_TUP_T_1 };
static PRT_TYPE P_GEND_TYPE_T2ii = { PRT_KIND_TUPLE, { .tuple = &P_TUP_1 } };
static PRT_TYPE P_GEND_TYPE_r = { PRT_KIND_STRING, { NULL } };
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

PRT_VALUE* P_PrintKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GenerateRandomMasterSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetUsernameInput_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetPasswordInput_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Concat_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Hash_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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

PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_14;


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
    &P_GEND_TYPE_T3machine_handleStringTypeStringType,
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

PRT_EVENTDECL P_EVENT_UNTRUSTEDAuthenticateRequest = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "UNTRUSTEDAuthenticateRequest",
    4294967295U,
    &P_GEND_TYPE_T3StringTypeStringTypeStringType,
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

PRT_EVENTDECL P_EVENT_TRUSTEDProvisionClientSSM = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDProvisionClientSSM",
    4294967295U,
    &P_GEND_TYPE_secure_machine_handle,
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


PRT_FUNDECL P_FUNCTION_GenerateRandomMasterSecret =
{
    "GenerateRandomMasterSecret",
    &P_GenerateRandomMasterSecret_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetUsernameInput =
{
    "GetUsernameInput",
    &P_GetUsernameInput_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetPasswordInput =
{
    "GetPasswordInput",
    &P_GetPasswordInput_IMPL,
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


PRT_EVENTDECL* P_UntrustedInitializer_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_RECV =
{
    12U,
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

PRT_EVENTDECL* P_TrustedInitializer_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_RECV =
{
    12U,
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

PRT_EVENTDECL* P_BankEnclave_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_RECV =
{
    12U,
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

PRT_EVENTDECL* P_ClientEnclave_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_RECV =
{
    12U,
    P_ClientEnclave_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ClientEnclave =
{
    3U,
    "ClientEnclave",
    &P_GEND_TYPE_n,
    &P_EVENTSET_ClientEnclave_RECV
};

PRT_EVENTDECL* P_ClientWebBrowser_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_RECV =
{
    12U,
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
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    _P_GEN_funargs[0] = "TrustedInitializer";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE* P_this_ref = (P_GetThis_IMPL(context, _P_GEN_funargs));
    _P_GEN_funargs[2] = &P_this_ref;
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
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL
};


PRT_FUNDECL* P_UntrustedInitializer_METHODS[] = { &P_FUNCTION_Anon };

PRT_EVENTDECL* P_UntrustedInitializer_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_RECV_1 =
{
    12U,
    P_UntrustedInitializer_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_UntrustedInitializer_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_UntrustedInitializer_SEND =
{
    12U,
    P_UntrustedInitializer_SEND_INNER,
    NULL
};

PRT_UINT32 P_UntrustedInitializer_CREATES_ARR[] = { 1 };
PRT_INTERFACESETDECL P_UntrustedInitializer_CREATES = { 1, P_UntrustedInitializer_CREATES_ARR };
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
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    _P_GEN_funargs[0] = "ClientWebBrowser";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = NULL;
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_5 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_5);
        *P_LVALUE_5 = PTMP_tmp0_2;
        PTMP_tmp0_2 = NULL;
    }
    
    _P_GEN_funargs[0] = "BankEnclave";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE* P_this_ref_1 = (P_GetThis_IMPL(context, _P_GEN_funargs));
    _P_GEN_funargs[2] = &P_this_ref_1;
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_7 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_7);
        *P_LVALUE_7 = PTMP_tmp1_1;
        PTMP_tmp1_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue((&P_EVENT_BankPublicIDEvent.value));
    
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = ((_P_GEN_funargs[0] = &(PTMP_tmp4)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp4), PTMP_tmp4 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue(PrtCastValue(PTMP_tmp5, &P_GEND_TYPE_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32));
    _P_GEN_funargs[0] = &(PTMP_tmp2);
    _P_GEN_funargs[1] = &(PTMP_tmp3);
    _P_GEN_funargs[2] = &(P_PTMP_tmp);
    _P_GEN_funargs[3] = &(PTMP_tmp6);
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
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_FUNDECL* P_TrustedInitializer_METHODS[] = { &P_FUNCTION_Anon_1 };

PRT_EVENTDECL* P_TrustedInitializer_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_RECV_1 =
{
    12U,
    P_TrustedInitializer_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_TrustedInitializer_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_TrustedInitializer_SEND =
{
    12U,
    P_TrustedInitializer_SEND_INNER,
    NULL
};

PRT_UINT32 P_TrustedInitializer_CREATES_ARR[] = { 2, 4 };
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
    { "registeredCredentials", &P_GEND_TYPE_MKsecure_StringTypeVsecure_StringType },
    { "credentialToMasterSecretMap", &P_GEND_TYPE_MKsecure_StringTypeVsecure_StringType }
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

PRT_EVENTDECL* P_RegisterNewBankAccount_DOS_INNER[] = { &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials };
PRT_EVENTSETDECL P_EVENTSET_RegisterNewBankAccount_DOS =
{
    2U,
    P_RegisterNewBankAccount_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS[] =
{
    { 1, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &P_FUNCTION_Anon_3 },
    { 1, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_FUNCTION_Anon_4 }
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
    P_DOS, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_BankEnclave_STATES[] = { P_STATE_BankEnclave_Initial, P_STATE_BankEnclave_RegisterNewBankAccount };

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
    PRT_VALUE* P_VAR_masterSecret = PrtMkDefaultValue(&P_GEND_TYPE_secure_StringType);
    PRT_VALUE* P_VAR_username = PrtMkDefaultValue(&P_GEND_TYPE_secure_StringType);
    PRT_VALUE* P_VAR_password = PrtMkDefaultValue(&P_GEND_TYPE_secure_StringType);
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
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
    PRT_VALUE* PTMP_tmp21 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtTupleGet(*P_VAR_payload, 0);
    
    {
        PRT_VALUE** P_LVALUE_14 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_14);
        *P_LVALUE_14 = PTMP_tmp0_3;
        PTMP_tmp0_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtTupleGet(*P_VAR_payload, 1);
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = ((_P_GEN_funargs[0] = &(PTMP_tmp1_2)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp1_2), PTMP_tmp1_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = PrtCloneValue(PrtCastValue(PTMP_tmp2_1, &P_GEND_TYPE_secure_StringType));
    
    {
        PRT_VALUE** P_LVALUE_18 = &(P_VAR_username);
        PrtFreeValue(*P_LVALUE_18);
        *P_LVALUE_18 = PTMP_tmp3_1;
        PTMP_tmp3_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = PrtTupleGet(*P_VAR_payload, 2);
    
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = ((_P_GEN_funargs[0] = &(PTMP_tmp4_1)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp4_1), PTMP_tmp4_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtCloneValue(PrtCastValue(PTMP_tmp5_1, &P_GEND_TYPE_secure_StringType));
    
    {
        PRT_VALUE** P_LVALUE_22 = &(P_VAR_password);
        PrtFreeValue(*P_LVALUE_22);
        *P_LVALUE_22 = PTMP_tmp6_1;
        PTMP_tmp6_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = ((_P_GEN_funval = P_GenerateRandomMasterSecret_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_24 = &(P_VAR_masterSecret);
        PrtFreeValue(*P_LVALUE_24);
        *P_LVALUE_24 = PTMP_tmp7;
        PTMP_tmp7 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_25 = &(*(PrtMapGetLValue(p_this->varValues[2], P_VAR_username, PRT_TRUE, &P_GEND_TYPE_MKsecure_StringTypeVsecure_StringType)));
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = PrtCloneValue(P_VAR_password);
    
    PRT_VALUE** P_LVALUE_26 = &(*(PrtMapGetLValue(p_this->varValues[3], P_VAR_username, PRT_TRUE, &P_GEND_TYPE_MKsecure_StringTypeVsecure_StringType)));
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue(P_VAR_masterSecret);
    
    PrtPrintf("Bank: Creating new bank account!");
    
    _P_GEN_funargs[0] = "ClientEnclave";
    _P_GEN_funargs[1] = "0";
    _P_GEN_funargs[2] = &(p_this->varValues[1]);
    PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_28 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_28);
        *P_LVALUE_28 = PTMP_tmp8;
        PTMP_tmp8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_29);
    *P_LVALUE_29 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtCloneValue((&P_EVENT_TRUSTEDProvisionClientSSM.value));
    
    PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp11);
    PrtFreeValue(*P_LVALUE_31);
    *P_LVALUE_31 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp12);
    PrtFreeValue(*P_LVALUE_32);
    *P_LVALUE_32 = ((_P_GEN_funargs[0] = &(PTMP_tmp11)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp11), PTMP_tmp11 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp13);
    PrtFreeValue(*P_LVALUE_33);
    *P_LVALUE_33 = PrtCloneValue(PrtCastValue(PTMP_tmp12, &P_GEND_TYPE_secure_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp_1 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp9);
    _P_GEN_funargs[1] = &(PTMP_tmp10);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_1);
    _P_GEN_funargs[3] = &(PTMP_tmp13);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_34 = &(PTMP_tmp14);
    PrtFreeValue(*P_LVALUE_34);
    *P_LVALUE_34 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp15);
    PrtFreeValue(*P_LVALUE_35);
    *P_LVALUE_35 = PrtCloneValue((&P_EVENT_MasterSecretEvent.value));
    
    PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp16);
    PrtFreeValue(*P_LVALUE_36);
    *P_LVALUE_36 = PrtCloneValue(P_VAR_masterSecret);
    
    PRT_VALUE* P_PTMP_tmp_2 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp14);
    _P_GEN_funargs[1] = &(PTMP_tmp15);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_2);
    _P_GEN_funargs[3] = &(PTMP_tmp16);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_37 = &(PTMP_tmp17);
    PrtFreeValue(*P_LVALUE_37);
    *P_LVALUE_37 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp18);
    PrtFreeValue(*P_LVALUE_38);
    *P_LVALUE_38 = PrtCloneValue((&P_EVENT_PublicIDEvent.value));
    
    PRT_VALUE** P_LVALUE_39 = &(PTMP_tmp19);
    PrtFreeValue(*P_LVALUE_39);
    *P_LVALUE_39 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp20);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = ((_P_GEN_funargs[0] = &(PTMP_tmp19)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp19), PTMP_tmp19 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_41 = &(PTMP_tmp21);
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = PrtCloneValue(PrtCastValue(PTMP_tmp20, &P_GEND_TYPE_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp_3 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp17);
    _P_GEN_funargs[1] = &(PTMP_tmp18);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_3);
    _P_GEN_funargs[3] = &(PTMP_tmp21);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
p_return_4: ;
    PrtFreeValue(P_VAR_masterSecret); P_VAR_masterSecret = NULL;
    PrtFreeValue(P_VAR_username); P_VAR_username = NULL;
    PrtFreeValue(P_VAR_password); P_VAR_password = NULL;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
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
    PrtFreeValue(PTMP_tmp21); PTMP_tmp21 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    &P_GEND_TYPE_T3machine_handleStringTypeStringType
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE* P_VAR_masterSecret_1 = PrtMkDefaultValue(&P_GEND_TYPE_secure_StringType);
    PRT_VALUE* P_VAR_inputUsername = PrtMkDefaultValue(&P_GEND_TYPE_secure_StringType);
    PRT_VALUE* P_VAR_inputPassword = PrtMkDefaultValue(&P_GEND_TYPE_secure_StringType);
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_2 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8_1 = NULL;
    PRT_VALUE* PTMP_tmp9_1 = NULL;
    PRT_VALUE* PTMP_tmp10_1 = NULL;
    PRT_VALUE* PTMP_tmp11_1 = NULL;
    PRT_VALUE* PTMP_tmp12_1 = NULL;
    PRT_VALUE* PTMP_tmp13_1 = NULL;
    PRT_VALUE* PTMP_tmp14_1 = NULL;
    PRT_VALUE* PTMP_tmp15_1 = NULL;
    PRT_VALUE* PTMP_tmp16_1 = NULL;
    PRT_VALUE* PTMP_tmp17_1 = NULL;
    PRT_VALUE* PTMP_tmp18_1 = NULL;
    PRT_VALUE* PTMP_tmp19_1 = NULL;
    PRT_VALUE* PTMP_tmp20_1 = NULL;
    PRT_VALUE* PTMP_tmp21_1 = NULL;
    PRT_VALUE* PTMP_tmp22 = NULL;
    PRT_VALUE* PTMP_tmp23 = NULL;
    PRT_VALUE* PTMP_tmp24 = NULL;
    PRT_VALUE* PTMP_tmp25 = NULL;
    PRT_VALUE* PTMP_tmp26 = NULL;
    PRT_VALUE* PTMP_tmp27 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_42);
    *P_LVALUE_42 = PrtTupleGet(*P_VAR_payload_1, 0);
    
    PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_43);
    *P_LVALUE_43 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_4)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_4), PTMP_tmp0_4 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
    PRT_VALUE** P_LVALUE_44 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_44);
    *P_LVALUE_44 = PrtCloneValue(PrtCastValue(PTMP_tmp1_3, &P_GEND_TYPE_secure_StringType));
    
    {
        PRT_VALUE** P_LVALUE_45 = &(P_VAR_inputUsername);
        PrtFreeValue(*P_LVALUE_45);
        *P_LVALUE_45 = PTMP_tmp2_2;
        PTMP_tmp2_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_46);
    *P_LVALUE_46 = PrtTupleGet(*P_VAR_payload_1, 1);
    
    PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp4_2);
    PrtFreeValue(*P_LVALUE_47);
    *P_LVALUE_47 = ((_P_GEN_funargs[0] = &(PTMP_tmp3_2)), (_P_GEN_funval = P_Endorse_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp3_2), PTMP_tmp3_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
    PRT_VALUE** P_LVALUE_48 = &(PTMP_tmp5_2);
    PrtFreeValue(*P_LVALUE_48);
    *P_LVALUE_48 = PrtCloneValue(PrtCastValue(PTMP_tmp4_2, &P_GEND_TYPE_secure_StringType));
    
    {
        PRT_VALUE** P_LVALUE_49 = &(P_VAR_inputPassword);
        PrtFreeValue(*P_LVALUE_49);
        *P_LVALUE_49 = PTMP_tmp5_2;
        PTMP_tmp5_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp6_2);
    PrtFreeValue(*P_LVALUE_50);
    *P_LVALUE_50 = PrtMapGet(p_this->varValues[3], P_VAR_inputUsername);
    
    {
        PRT_VALUE** P_LVALUE_51 = &(P_VAR_masterSecret_1);
        PrtFreeValue(*P_LVALUE_51);
        *P_LVALUE_51 = PTMP_tmp6_2;
        PTMP_tmp6_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp7_1);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = PrtMapGet(p_this->varValues[2], P_VAR_inputUsername);
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp8_1);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = ((_P_GEN_funargs[0] = &(PTMP_tmp7_1)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp7_1), PTMP_tmp7_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
    PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp9_1);
    PrtFreeValue(*P_LVALUE_54);
    *P_LVALUE_54 = PrtCloneValue(PrtCastValue(PTMP_tmp8_1, &P_GEND_TYPE_StringType));
    
    PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp10_1);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtCloneValue(P_VAR_inputPassword);
    
    PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp11_1);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = ((_P_GEN_funargs[0] = &(PTMP_tmp10_1)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp10_1), PTMP_tmp10_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
    PRT_VALUE** P_LVALUE_57 = &(PTMP_tmp12_1);
    PrtFreeValue(*P_LVALUE_57);
    *P_LVALUE_57 = PrtCloneValue(PrtCastValue(PTMP_tmp11_1, &P_GEND_TYPE_StringType));
    
    PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp13_1);
    PrtFreeValue(*P_LVALUE_58);
    *P_LVALUE_58 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp9_1, PTMP_tmp12_1));
    
    PRT_VALUE** P_LVALUE_59 = &(PTMP_tmp23);
    PrtFreeValue(*P_LVALUE_59);
    *P_LVALUE_59 = PrtCloneValue(PTMP_tmp13_1);
    
    if (PrtPrimGetBool(PTMP_tmp23))
    {
        PRT_VALUE** P_LVALUE_60 = &(PTMP_tmp14_1);
        PrtFreeValue(*P_LVALUE_60);
        *P_LVALUE_60 = PrtCloneValue(P_VAR_masterSecret_1);
        
        PRT_VALUE** P_LVALUE_61 = &(PTMP_tmp15_1);
        PrtFreeValue(*P_LVALUE_61);
        *P_LVALUE_61 = ((_P_GEN_funargs[0] = &(PTMP_tmp14_1)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp14_1), PTMP_tmp14_1 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_5;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_5;
        }
        
        PRT_VALUE** P_LVALUE_62 = &(PTMP_tmp16_1);
        PrtFreeValue(*P_LVALUE_62);
        *P_LVALUE_62 = PrtCloneValue(PrtCastValue(PTMP_tmp15_1, &P_GEND_TYPE_StringType));
        
        PRT_VALUE** P_LVALUE_63 = &(PTMP_tmp17_1);
        PrtFreeValue(*P_LVALUE_63);
        *P_LVALUE_63 = PrtCloneValue(P_VAR_inputPassword);
        
        PRT_VALUE** P_LVALUE_64 = &(PTMP_tmp18_1);
        PrtFreeValue(*P_LVALUE_64);
        *P_LVALUE_64 = ((_P_GEN_funargs[0] = &(PTMP_tmp17_1)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp17_1), PTMP_tmp17_1 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_5;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_5;
        }
        
        PRT_VALUE** P_LVALUE_65 = &(PTMP_tmp19_1);
        PrtFreeValue(*P_LVALUE_65);
        *P_LVALUE_65 = PrtCloneValue(PrtCastValue(PTMP_tmp18_1, &P_GEND_TYPE_StringType));
        
        PRT_VALUE** P_LVALUE_66 = &(PTMP_tmp20_1);
        PrtFreeValue(*P_LVALUE_66);
        *P_LVALUE_66 = ((_P_GEN_funargs[0] = &(PTMP_tmp16_1)), (_P_GEN_funargs[1] = &(PTMP_tmp19_1)), (_P_GEN_funval = P_Hash_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp16_1), PTMP_tmp16_1 = NULL), (PrtFreeValue(PTMP_tmp19_1), PTMP_tmp19_1 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_5;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_5;
        }
        
        PRT_VALUE** P_LVALUE_67 = &(PTMP_tmp21_1);
        PrtFreeValue(*P_LVALUE_67);
        *P_LVALUE_67 = PrtTupleGet(*P_VAR_payload_1, 2);
        
        PRT_VALUE** P_LVALUE_68 = &(PTMP_tmp22);
        PrtFreeValue(*P_LVALUE_68);
        *P_LVALUE_68 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp20_1, PTMP_tmp21_1));
        
        PRT_VALUE** P_LVALUE_69 = &(PTMP_tmp23);
        PrtFreeValue(*P_LVALUE_69);
        *P_LVALUE_69 = PrtCloneValue(PTMP_tmp22);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp23))
    {
        PrtPrintf("Auth Success");
        
        PRT_VALUE** P_LVALUE_70 = &(PTMP_tmp24);
        PrtFreeValue(*P_LVALUE_70);
        *P_LVALUE_70 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_71 = &(PTMP_tmp25);
        PrtFreeValue(*P_LVALUE_71);
        *P_LVALUE_71 = PrtCloneValue((&P_EVENT_AuthSuccess.value));
        
        PRT_VALUE* P_PTMP_tmp_4 = PrtCloneValue(&(P_LIT_INT32_2));
        _P_GEN_funargs[0] = &(PTMP_tmp24);
        _P_GEN_funargs[1] = &(PTMP_tmp25);
        _P_GEN_funargs[2] = &(P_PTMP_tmp_4);
        PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_5;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_5;
        }
        
    }
    
    else
    {
        PrtPrintf("Auth Failure");
        
        PRT_VALUE** P_LVALUE_72 = &(PTMP_tmp26);
        PrtFreeValue(*P_LVALUE_72);
        *P_LVALUE_72 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_73 = &(PTMP_tmp27);
        PrtFreeValue(*P_LVALUE_73);
        *P_LVALUE_73 = PrtCloneValue((&P_EVENT_AuthFailure.value));
        
        PRT_VALUE* P_PTMP_tmp_5 = PrtCloneValue(&(P_LIT_INT32_2));
        _P_GEN_funargs[0] = &(PTMP_tmp26);
        _P_GEN_funargs[1] = &(PTMP_tmp27);
        _P_GEN_funargs[2] = &(P_PTMP_tmp_5);
        PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_5;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_5;
        }
        
    }
    
    
p_return_5: ;
    PrtFreeValue(P_VAR_masterSecret_1); P_VAR_masterSecret_1 = NULL;
    PrtFreeValue(P_VAR_inputUsername); P_VAR_inputUsername = NULL;
    PrtFreeValue(P_VAR_inputPassword); P_VAR_inputPassword = NULL;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_2); PTMP_tmp6_2 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8_1); PTMP_tmp8_1 = NULL;
    PrtFreeValue(PTMP_tmp9_1); PTMP_tmp9_1 = NULL;
    PrtFreeValue(PTMP_tmp10_1); PTMP_tmp10_1 = NULL;
    PrtFreeValue(PTMP_tmp11_1); PTMP_tmp11_1 = NULL;
    PrtFreeValue(PTMP_tmp12_1); PTMP_tmp12_1 = NULL;
    PrtFreeValue(PTMP_tmp13_1); PTMP_tmp13_1 = NULL;
    PrtFreeValue(PTMP_tmp14_1); PTMP_tmp14_1 = NULL;
    PrtFreeValue(PTMP_tmp15_1); PTMP_tmp15_1 = NULL;
    PrtFreeValue(PTMP_tmp16_1); PTMP_tmp16_1 = NULL;
    PrtFreeValue(PTMP_tmp17_1); PTMP_tmp17_1 = NULL;
    PrtFreeValue(PTMP_tmp18_1); PTMP_tmp18_1 = NULL;
    PrtFreeValue(PTMP_tmp19_1); PTMP_tmp19_1 = NULL;
    PrtFreeValue(PTMP_tmp20_1); PTMP_tmp20_1 = NULL;
    PrtFreeValue(PTMP_tmp21_1); PTMP_tmp21_1 = NULL;
    PrtFreeValue(PTMP_tmp22); PTMP_tmp22 = NULL;
    PrtFreeValue(PTMP_tmp23); PTMP_tmp23 = NULL;
    PrtFreeValue(PTMP_tmp24); PTMP_tmp24 = NULL;
    PrtFreeValue(PTMP_tmp25); PTMP_tmp25 = NULL;
    PrtFreeValue(PTMP_tmp26); PTMP_tmp26 = NULL;
    PrtFreeValue(PTMP_tmp27); PTMP_tmp27 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    &P_GEND_TYPE_T3StringTypeStringTypeStringType
};


PRT_FUNDECL* P_BankEnclave_METHODS[] = { &P_FUNCTION_Anon_2, &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4 };

PRT_EVENTDECL* P_BankEnclave_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_RECV_1 =
{
    12U,
    P_BankEnclave_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_BankEnclave_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_BankEnclave_SEND =
{
    12U,
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
    4U,
    2U,
    3U,
    4294967295U,
    0U,
    P_BankEnclave_VARS,
    P_BankEnclave_STATES,
    P_BankEnclave_METHODS,
    PRT_TRUE
};

PRT_VARDECL P_ClientEnclave_VARS[] = {
    { "masterSecret", &P_GEND_TYPE_secure_StringType },
    { "clientUSM", &P_GEND_TYPE_machine_handle }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_3[] = { &P_EVENT_GenerateOTPCodeEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_3 =
{
    1U,
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

PRT_EVENTDECL* P_Initial_DOS_INNER_3[] = { &P_EVENT_TRUSTEDProvisionClientSSM };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_3 =
{
    1U,
    P_Initial_DOS_INNER_3,
    NULL
};

PRT_DODECL P_DOS_1[] =
{
    { 0, &P_EVENT_TRUSTEDProvisionClientSSM, &P_FUNCTION_Anon_5 }
};

#define P_STATE_ClientEnclave_Initial \
{ \
    "ClientEnclave.Initial", \
    0U, \
    1U, \
    &P_EVENTSET_Initial_DEFERS_3, \
    &P_EVENTSET_Initial_TRANS_3, \
    &P_EVENTSET_Initial_DOS_3, \
    NULL, \
    P_DOS_1, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_ReceiveMasterSecretEvent_DEFERS_INNER[] = { &P_EVENT_GenerateOTPCodeEvent };
PRT_EVENTSETDECL P_EVENTSET_ReceiveMasterSecretEvent_DEFERS =
{
    1U,
    P_ReceiveMasterSecretEvent_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReceiveMasterSecretEvent_TRANS_INNER[] = { &P_EVENT_MasterSecretEvent };
PRT_EVENTSETDECL P_EVENTSET_ReceiveMasterSecretEvent_TRANS =
{
    1U,
    P_ReceiveMasterSecretEvent_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_ReceiveMasterSecretEvent_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_ReceiveMasterSecretEvent_DOS =
{
    0U,
    P_ReceiveMasterSecretEvent_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 1, &P_EVENT_MasterSecretEvent, 2, &_P_NO_OP }
};

#define P_STATE_ClientEnclave_ReceiveMasterSecretEvent \
{ \
    "ClientEnclave.ReceiveMasterSecretEvent", \
    1U, \
    0U, \
    &P_EVENTSET_ReceiveMasterSecretEvent_DEFERS, \
    &P_EVENTSET_ReceiveMasterSecretEvent_TRANS, \
    &P_EVENTSET_ReceiveMasterSecretEvent_DOS, \
    P_TRANS, \
    NULL, \
    &_P_NO_OP, \
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
    &P_FUNCTION_Anon_6, \
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

PRT_DODECL P_DOS_2[] =
{
    { 3, &P_EVENT_GenerateOTPCodeEvent, &P_FUNCTION_Anon_7 }
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
    P_DOS_2, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClientEnclave_STATES[] = { P_STATE_ClientEnclave_Initial, P_STATE_ClientEnclave_ReceiveMasterSecretEvent, P_STATE_ClientEnclave_ProvisionEnclaveWithSecret, P_STATE_ClientEnclave_WaitForGenerateOTP };

PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_74 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_74);
    *P_LVALUE_74 = PrtCloneValue(*P_VAR_payload_2);
    
    PRT_VALUE** P_LVALUE_75 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_75);
    *P_LVALUE_75 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_5)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_5), PTMP_tmp0_5 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PRT_VALUE** P_LVALUE_76 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_76);
    *P_LVALUE_76 = PrtCloneValue(PrtCastValue(PTMP_tmp1_4, &P_GEND_TYPE_machine_handle));
    
    {
        PRT_VALUE** P_LVALUE_77 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_77);
        *P_LVALUE_77 = PTMP_tmp2_3;
        PTMP_tmp2_3 = NULL;
    }
    
    PrtGoto(p_this, 1U, 0);
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_secure_machine_handle
};


PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_78 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_78);
    *P_LVALUE_78 = PrtCloneValue(*P_VAR_payload_3);
    
    PrtGoto(p_this, 3U, 0);
    
p_return_7: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    &P_GEND_TYPE_secure_StringType
};


PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_password_1 = argRefs[0];
    PRT_VALUE* P_VAR_hashedString = PrtMkDefaultValue(&P_GEND_TYPE_StringType);
    PRT_VALUE* P_VAR_test1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_test2 = PrtMkDefaultValue(&P_GEND_TYPE_MKiVi);
    PRT_VALUE* P_VAR_test3 = PrtMkDefaultValue(&P_GEND_TYPE_T2ii);
    PRT_VALUE* P_VAR_sealedDataDump = PrtMkDefaultValue(&P_GEND_TYPE_sealed_data);
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    PRT_VALUE* PTMP_tmp1_5 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_3 = NULL;
    PRT_VALUE* PTMP_tmp5_3 = NULL;
    PRT_VALUE* PTMP_tmp6_3 = NULL;
    PRT_VALUE* PTMP_tmp7_2 = NULL;
    PRT_VALUE* PTMP_tmp8_2 = NULL;
    PRT_VALUE* PTMP_tmp9_2 = NULL;
    PRT_VALUE* PTMP_tmp10_2 = NULL;
    PRT_VALUE* PTMP_tmp11_2 = NULL;
    PRT_VALUE* PTMP_tmp12_2 = NULL;
    PRT_VALUE* PTMP_tmp13_2 = NULL;
    PRT_VALUE* PTMP_tmp14_2 = NULL;
    PRT_VALUE* PTMP_tmp15_2 = NULL;
    PRT_VALUE* PTMP_tmp16_2 = NULL;
    PRT_VALUE* PTMP_tmp17_2 = NULL;
    PRT_VALUE* PTMP_tmp18_2 = NULL;
    PRT_VALUE* PTMP_tmp19_2 = NULL;
    PRT_VALUE* PTMP_tmp20_2 = NULL;
    PRT_VALUE* PTMP_tmp21_2 = NULL;
    PRT_VALUE* PTMP_tmp22_1 = NULL;
    PRT_VALUE* PTMP_tmp23_1 = NULL;
    PRT_VALUE* PTMP_tmp24_1 = NULL;
    PRT_VALUE* PTMP_tmp25_1 = NULL;
    PRT_VALUE* PTMP_tmp26_1 = NULL;
    PRT_VALUE* PTMP_tmp27_1 = NULL;
    PRT_VALUE* PTMP_tmp28 = NULL;
    PRT_VALUE* PTMP_tmp29 = NULL;
    PRT_VALUE* PTMP_tmp30 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 7 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 8 } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 9 } };
    PRT_VALUE P_LIT_INT32_7 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_79 = &(P_VAR_test1);
    PrtFreeValue(*P_LVALUE_79);
    *P_LVALUE_79 = PrtCloneValue((&P_LIT_INT32_3));
    
    PRT_VALUE** P_LVALUE_80 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_80);
    *P_LVALUE_80 = PrtCloneValue(P_VAR_test1);
    
    PRT_VALUE** P_LVALUE_81 = &(PTMP_tmp1_5);
    PrtFreeValue(*P_LVALUE_81);
    *P_LVALUE_81 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_6)), (_P_GEN_funval = P_seal_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_6), PTMP_tmp0_6 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    {
        PRT_VALUE** P_LVALUE_82 = &(P_VAR_sealedDataDump);
        PrtFreeValue(*P_LVALUE_82);
        *P_LVALUE_82 = PTMP_tmp1_5;
        PTMP_tmp1_5 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_83 = &(PTMP_tmp2_4);
    PrtFreeValue(*P_LVALUE_83);
    *P_LVALUE_83 = PrtCloneValue(P_VAR_sealedDataDump);
    
    PRT_VALUE** P_LVALUE_84 = &(PTMP_tmp3_3);
    PrtFreeValue(*P_LVALUE_84);
    *P_LVALUE_84 = ((_P_GEN_funargs[0] = &(PTMP_tmp2_4)), (_P_GEN_funval = P_unseal_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp2_4), PTMP_tmp2_4 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_85 = &(PTMP_tmp4_3);
    PrtFreeValue(*P_LVALUE_85);
    *P_LVALUE_85 = PrtCloneValue(PrtCastValue(PTMP_tmp3_3, &P_GEND_TYPE_i));
    
    PRT_VALUE** P_LVALUE_86 = &(PTMP_tmp5_3);
    PrtFreeValue(*P_LVALUE_86);
    *P_LVALUE_86 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp4_3, (&P_LIT_INT32_3)));
    
    if (PrtPrimGetBool(PTMP_tmp5_3))
    {
        PrtPrintf("First Seal Test Success!");
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_87 = &(*(PrtMapGetLValue(P_VAR_test2, (&P_LIT_INT32_4), PRT_TRUE, &P_GEND_TYPE_MKiVi)));
    PrtFreeValue(*P_LVALUE_87);
    *P_LVALUE_87 = PrtCloneValue((&P_LIT_INT32_5));
    
    PRT_VALUE** P_LVALUE_88 = &(PTMP_tmp6_3);
    PrtFreeValue(*P_LVALUE_88);
    *P_LVALUE_88 = PrtCloneValue(P_VAR_test2);
    
    PRT_VALUE** P_LVALUE_89 = &(PTMP_tmp7_2);
    PrtFreeValue(*P_LVALUE_89);
    *P_LVALUE_89 = ((_P_GEN_funargs[0] = &(PTMP_tmp6_3)), (_P_GEN_funval = P_seal_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp6_3), PTMP_tmp6_3 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    {
        PRT_VALUE** P_LVALUE_90 = &(P_VAR_sealedDataDump);
        PrtFreeValue(*P_LVALUE_90);
        *P_LVALUE_90 = PTMP_tmp7_2;
        PTMP_tmp7_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_91 = &(PTMP_tmp8_2);
    PrtFreeValue(*P_LVALUE_91);
    *P_LVALUE_91 = PrtCloneValue(P_VAR_sealedDataDump);
    
    PRT_VALUE** P_LVALUE_92 = &(PTMP_tmp9_2);
    PrtFreeValue(*P_LVALUE_92);
    *P_LVALUE_92 = ((_P_GEN_funargs[0] = &(PTMP_tmp8_2)), (_P_GEN_funval = P_unseal_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp8_2), PTMP_tmp8_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_93 = &(PTMP_tmp10_2);
    PrtFreeValue(*P_LVALUE_93);
    *P_LVALUE_93 = PrtCloneValue(PrtCastValue(PTMP_tmp9_2, &P_GEND_TYPE_MKiVi));
    
    PRT_VALUE** P_LVALUE_94 = &(PTMP_tmp11_2);
    PrtFreeValue(*P_LVALUE_94);
    *P_LVALUE_94 = PrtMapGet(PTMP_tmp10_2, (&P_LIT_INT32_4));
    
    PRT_VALUE** P_LVALUE_95 = &(PTMP_tmp12_2);
    PrtFreeValue(*P_LVALUE_95);
    *P_LVALUE_95 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp11_2, (&P_LIT_INT32_5)));
    
    if (PrtPrimGetBool(PTMP_tmp12_2))
    {
        PrtPrintf("Second Seal Test Success!");
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_96 = &(PTMP_tmp13_2);
    PrtFreeValue(*P_LVALUE_96);
    *P_LVALUE_96 = PrtCloneValue((&P_LIT_INT32_6));
    
    PRT_VALUE** P_LVALUE_97 = &(PTMP_tmp14_2);
    PrtFreeValue(*P_LVALUE_97);
    *P_LVALUE_97 = PrtCloneValue((&P_LIT_INT32_6));
    
    PRT_VALUE** P_LVALUE_98 = &(PTMP_tmp15_2);
    PrtFreeValue(*P_LVALUE_98);
    *P_LVALUE_98 = (PrtMkTuple(&P_GEND_TYPE_T2ii, &(PTMP_tmp13_2), &(PTMP_tmp14_2)));
    
    {
        PRT_VALUE** P_LVALUE_99 = &(P_VAR_test3);
        PrtFreeValue(*P_LVALUE_99);
        *P_LVALUE_99 = PTMP_tmp15_2;
        PTMP_tmp15_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_100 = &(PTMP_tmp16_2);
    PrtFreeValue(*P_LVALUE_100);
    *P_LVALUE_100 = PrtCloneValue(P_VAR_test3);
    
    PRT_VALUE** P_LVALUE_101 = &(PTMP_tmp17_2);
    PrtFreeValue(*P_LVALUE_101);
    *P_LVALUE_101 = ((_P_GEN_funargs[0] = &(PTMP_tmp16_2)), (_P_GEN_funval = P_seal_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp16_2), PTMP_tmp16_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    {
        PRT_VALUE** P_LVALUE_102 = &(P_VAR_sealedDataDump);
        PrtFreeValue(*P_LVALUE_102);
        *P_LVALUE_102 = PTMP_tmp17_2;
        PTMP_tmp17_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_103 = &(PTMP_tmp18_2);
    PrtFreeValue(*P_LVALUE_103);
    *P_LVALUE_103 = PrtCloneValue(P_VAR_sealedDataDump);
    
    PRT_VALUE** P_LVALUE_104 = &(PTMP_tmp19_2);
    PrtFreeValue(*P_LVALUE_104);
    *P_LVALUE_104 = ((_P_GEN_funargs[0] = &(PTMP_tmp18_2)), (_P_GEN_funval = P_unseal_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp18_2), PTMP_tmp18_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_105 = &(PTMP_tmp20_2);
    PrtFreeValue(*P_LVALUE_105);
    *P_LVALUE_105 = PrtCloneValue(PrtCastValue(PTMP_tmp19_2, &P_GEND_TYPE_T2ii));
    
    PRT_VALUE** P_LVALUE_106 = &(PTMP_tmp21_2);
    PrtFreeValue(*P_LVALUE_106);
    *P_LVALUE_106 = PrtTupleGet(PTMP_tmp20_2, 1);
    
    PRT_VALUE** P_LVALUE_107 = &(PTMP_tmp22_1);
    PrtFreeValue(*P_LVALUE_107);
    *P_LVALUE_107 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp21_2, (&P_LIT_INT32_6)));
    
    if (PrtPrimGetBool(PTMP_tmp22_1))
    {
        PrtPrintf("Third Seal Test Success!");
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_108 = &(PTMP_tmp23_1);
    PrtFreeValue(*P_LVALUE_108);
    *P_LVALUE_108 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_109 = &(PTMP_tmp24_1);
    PrtFreeValue(*P_LVALUE_109);
    *P_LVALUE_109 = ((_P_GEN_funargs[0] = &(PTMP_tmp23_1)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp23_1), PTMP_tmp23_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_110 = &(PTMP_tmp25_1);
    PrtFreeValue(*P_LVALUE_110);
    *P_LVALUE_110 = PrtCloneValue(PrtCastValue(PTMP_tmp24_1, &P_GEND_TYPE_StringType));
    
    PRT_VALUE** P_LVALUE_111 = &(PTMP_tmp26_1);
    PrtFreeValue(*P_LVALUE_111);
    *P_LVALUE_111 = PrtCloneValue(*P_VAR_password_1);
    
    PRT_VALUE** P_LVALUE_112 = &(PTMP_tmp27_1);
    PrtFreeValue(*P_LVALUE_112);
    *P_LVALUE_112 = ((_P_GEN_funargs[0] = &(PTMP_tmp25_1)), (_P_GEN_funargs[1] = &(PTMP_tmp26_1)), (_P_GEN_funval = P_Hash_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp25_1), PTMP_tmp25_1 = NULL), (PrtFreeValue(PTMP_tmp26_1), PTMP_tmp26_1 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    {
        PRT_VALUE** P_LVALUE_113 = &(P_VAR_hashedString);
        PrtFreeValue(*P_LVALUE_113);
        *P_LVALUE_113 = PTMP_tmp27_1;
        PTMP_tmp27_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_114 = &(PTMP_tmp28);
    PrtFreeValue(*P_LVALUE_114);
    *P_LVALUE_114 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_115 = &(PTMP_tmp29);
    PrtFreeValue(*P_LVALUE_115);
    *P_LVALUE_115 = PrtCloneValue((&P_EVENT_OTPCodeEvent.value));
    
    PRT_VALUE** P_LVALUE_116 = &(PTMP_tmp30);
    PrtFreeValue(*P_LVALUE_116);
    *P_LVALUE_116 = PrtCloneValue(P_VAR_hashedString);
    
    PRT_VALUE* P_PTMP_tmp_6 = PrtCloneValue(&(P_LIT_INT32_7));
    _P_GEN_funargs[0] = &(PTMP_tmp28);
    _P_GEN_funargs[1] = &(PTMP_tmp29);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_6);
    _P_GEN_funargs[3] = &(PTMP_tmp30);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
p_return_8: ;
    PrtFreeValue(P_VAR_hashedString); P_VAR_hashedString = NULL;
    PrtFreeValue(P_VAR_test1); P_VAR_test1 = NULL;
    PrtFreeValue(P_VAR_test2); P_VAR_test2 = NULL;
    PrtFreeValue(P_VAR_test3); P_VAR_test3 = NULL;
    PrtFreeValue(P_VAR_sealedDataDump); P_VAR_sealedDataDump = NULL;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    PrtFreeValue(PTMP_tmp1_5); PTMP_tmp1_5 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_3); PTMP_tmp4_3 = NULL;
    PrtFreeValue(PTMP_tmp5_3); PTMP_tmp5_3 = NULL;
    PrtFreeValue(PTMP_tmp6_3); PTMP_tmp6_3 = NULL;
    PrtFreeValue(PTMP_tmp7_2); PTMP_tmp7_2 = NULL;
    PrtFreeValue(PTMP_tmp8_2); PTMP_tmp8_2 = NULL;
    PrtFreeValue(PTMP_tmp9_2); PTMP_tmp9_2 = NULL;
    PrtFreeValue(PTMP_tmp10_2); PTMP_tmp10_2 = NULL;
    PrtFreeValue(PTMP_tmp11_2); PTMP_tmp11_2 = NULL;
    PrtFreeValue(PTMP_tmp12_2); PTMP_tmp12_2 = NULL;
    PrtFreeValue(PTMP_tmp13_2); PTMP_tmp13_2 = NULL;
    PrtFreeValue(PTMP_tmp14_2); PTMP_tmp14_2 = NULL;
    PrtFreeValue(PTMP_tmp15_2); PTMP_tmp15_2 = NULL;
    PrtFreeValue(PTMP_tmp16_2); PTMP_tmp16_2 = NULL;
    PrtFreeValue(PTMP_tmp17_2); PTMP_tmp17_2 = NULL;
    PrtFreeValue(PTMP_tmp18_2); PTMP_tmp18_2 = NULL;
    PrtFreeValue(PTMP_tmp19_2); PTMP_tmp19_2 = NULL;
    PrtFreeValue(PTMP_tmp20_2); PTMP_tmp20_2 = NULL;
    PrtFreeValue(PTMP_tmp21_2); PTMP_tmp21_2 = NULL;
    PrtFreeValue(PTMP_tmp22_1); PTMP_tmp22_1 = NULL;
    PrtFreeValue(PTMP_tmp23_1); PTMP_tmp23_1 = NULL;
    PrtFreeValue(PTMP_tmp24_1); PTMP_tmp24_1 = NULL;
    PrtFreeValue(PTMP_tmp25_1); PTMP_tmp25_1 = NULL;
    PrtFreeValue(PTMP_tmp26_1); PTMP_tmp26_1 = NULL;
    PrtFreeValue(PTMP_tmp27_1); PTMP_tmp27_1 = NULL;
    PrtFreeValue(PTMP_tmp28); PTMP_tmp28 = NULL;
    PrtFreeValue(PTMP_tmp29); PTMP_tmp29 = NULL;
    PrtFreeValue(PTMP_tmp30); PTMP_tmp30 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_StringType
};


PRT_FUNDECL* P_ClientEnclave_METHODS[] = { &P_FUNCTION_Anon_5, &P_FUNCTION_Anon_6, &P_FUNCTION_Anon_7 };

PRT_EVENTDECL* P_ClientEnclave_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_RECV_1 =
{
    12U,
    P_ClientEnclave_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ClientEnclave_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientEnclave_SEND =
{
    12U,
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
    2U,
    4U,
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
    { "username", &P_GEND_TYPE_StringType },
    { "password", &P_GEND_TYPE_StringType },
    { "OTPCode", &P_GEND_TYPE_StringType }
};

PRT_EVENTDECL* P_Initial_DEFERS_INNER_4[] = { &P_EVENT_PublicIDEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_4 =
{
    1U,
    P_Initial_DEFERS_INNER_4,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_4[] = { &P_EVENT_BankPublicIDEvent };
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
    { 0, &P_EVENT_BankPublicIDEvent, 1, &_P_NO_OP }
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
    &P_FUNCTION_Anon_8, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_RegisterAccountInBank_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RegisterAccountInBank_DEFERS =
{
    0U,
    P_RegisterAccountInBank_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_RegisterAccountInBank_TRANS_INNER[] = { &P_EVENT_PublicIDEvent };
PRT_EVENTSETDECL P_EVENTSET_RegisterAccountInBank_TRANS =
{
    1U,
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

PRT_TRANSDECL P_TRANS_2[] =
{
    { 2, &P_EVENT_PublicIDEvent, 3, &_P_NO_OP }
};

#define P_STATE_ClientWebBrowser_RegisterAccountInBank \
{ \
    "ClientWebBrowser.RegisterAccountInBank", \
    1U, \
    0U, \
    &P_EVENTSET_RegisterAccountInBank_DEFERS, \
    &P_EVENTSET_RegisterAccountInBank_TRANS, \
    &P_EVENTSET_RegisterAccountInBank_DOS, \
    P_TRANS_2, \
    NULL, \
    &P_FUNCTION_Anon_9, \
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
    &P_FUNCTION_Anon_10, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_RequestOTPCodeGeneration_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RequestOTPCodeGeneration_DEFERS =
{
    0U,
    P_RequestOTPCodeGeneration_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_RequestOTPCodeGeneration_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RequestOTPCodeGeneration_TRANS =
{
    0U,
    P_RequestOTPCodeGeneration_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_RequestOTPCodeGeneration_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_RequestOTPCodeGeneration_DOS =
{
    0U,
    P_RequestOTPCodeGeneration_DOS_INNER,
    NULL
};

#define P_STATE_ClientWebBrowser_RequestOTPCodeGeneration \
{ \
    "ClientWebBrowser.RequestOTPCodeGeneration", \
    0U, \
    0U, \
    &P_EVENTSET_RequestOTPCodeGeneration_DEFERS, \
    &P_EVENTSET_RequestOTPCodeGeneration_TRANS, \
    &P_EVENTSET_RequestOTPCodeGeneration_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_11, \
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
    &P_FUNCTION_Anon_12, \
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

#define P_STATE_ClientWebBrowser_ValidateOTPCode \
{ \
    "ClientWebBrowser.ValidateOTPCode", \
    0U, \
    0U, \
    &P_EVENTSET_ValidateOTPCode_DEFERS, \
    &P_EVENTSET_ValidateOTPCode_TRANS, \
    &P_EVENTSET_ValidateOTPCode_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_13, \
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
    &P_FUNCTION_Anon_14, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClientWebBrowser_STATES[] = { P_STATE_ClientWebBrowser_Initial, P_STATE_ClientWebBrowser_SaveBankSSM, P_STATE_ClientWebBrowser_RegisterAccountInBank, P_STATE_ClientWebBrowser_Authenticate, P_STATE_ClientWebBrowser_RequestOTPCodeGeneration, P_STATE_ClientWebBrowser_SaveOTPCode, P_STATE_ClientWebBrowser_ValidateOTPCode, P_STATE_ClientWebBrowser_Done };

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_4 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_117 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_117);
    *P_LVALUE_117 = PrtCloneValue(*P_VAR_payload_4);
    
    PrtGoto(p_this, 2U, 0);
    
p_return_9: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_8,
    &P_GEND_TYPE_machine_handle
};


PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_7 = NULL;
    PRT_VALUE* PTMP_tmp1_6 = NULL;
    PRT_VALUE* PTMP_tmp2_5 = NULL;
    PRT_VALUE* PTMP_tmp3_4 = NULL;
    PRT_VALUE* PTMP_tmp4_4 = NULL;
    PRT_VALUE* PTMP_tmp5_4 = NULL;
    PRT_VALUE* PTMP_tmp6_4 = NULL;
    PRT_VALUE* PTMP_tmp7_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_8 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_118 = &(PTMP_tmp0_7);
    PrtFreeValue(*P_LVALUE_118);
    *P_LVALUE_118 = ((_P_GEN_funval = P_GetUsernameInput_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
    {
        PRT_VALUE** P_LVALUE_119 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_119);
        *P_LVALUE_119 = PTMP_tmp0_7;
        PTMP_tmp0_7 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_120 = &(PTMP_tmp1_6);
    PrtFreeValue(*P_LVALUE_120);
    *P_LVALUE_120 = ((_P_GEN_funval = P_GetPasswordInput_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_10;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_10;
    }
    
    {
        PRT_VALUE** P_LVALUE_121 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_121);
        *P_LVALUE_121 = PTMP_tmp1_6;
        PTMP_tmp1_6 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_122 = &(PTMP_tmp2_5);
    PrtFreeValue(*P_LVALUE_122);
    *P_LVALUE_122 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_123 = &(PTMP_tmp3_4);
    PrtFreeValue(*P_LVALUE_123);
    *P_LVALUE_123 = PrtCloneValue((&P_EVENT_UNTRUSTEDReceiveRegistrationCredentials.value));
    
    PRT_VALUE** P_LVALUE_124 = &(PTMP_tmp4_4);
    PrtFreeValue(*P_LVALUE_124);
    *P_LVALUE_124 = PrtCloneValue((P_GetThis_IMPL(context, _P_GEN_funargs)));
    
    PRT_VALUE** P_LVALUE_125 = &(PTMP_tmp5_4);
    PrtFreeValue(*P_LVALUE_125);
    *P_LVALUE_125 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_126 = &(PTMP_tmp6_4);
    PrtFreeValue(*P_LVALUE_126);
    *P_LVALUE_126 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_127 = &(PTMP_tmp7_3);
    PrtFreeValue(*P_LVALUE_127);
    *P_LVALUE_127 = (PrtMkTuple(&P_GEND_TYPE_T3machine_handleStringTypeStringType, &(PTMP_tmp4_4), &(PTMP_tmp5_4), &(PTMP_tmp6_4)));
    
    PRT_VALUE* P_PTMP_tmp_7 = PrtCloneValue(&(P_LIT_INT32_8));
    _P_GEN_funargs[0] = &(PTMP_tmp2_5);
    _P_GEN_funargs[1] = &(PTMP_tmp3_4);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_7);
    _P_GEN_funargs[3] = &(PTMP_tmp7_3);
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
    PrtFreeValue(PTMP_tmp0_7); PTMP_tmp0_7 = NULL;
    PrtFreeValue(PTMP_tmp1_6); PTMP_tmp1_6 = NULL;
    PrtFreeValue(PTMP_tmp2_5); PTMP_tmp2_5 = NULL;
    PrtFreeValue(PTMP_tmp3_4); PTMP_tmp3_4 = NULL;
    PrtFreeValue(PTMP_tmp4_4); PTMP_tmp4_4 = NULL;
    PrtFreeValue(PTMP_tmp5_4); PTMP_tmp5_4 = NULL;
    PrtFreeValue(PTMP_tmp6_4); PTMP_tmp6_4 = NULL;
    PrtFreeValue(PTMP_tmp7_3); PTMP_tmp7_3 = NULL;
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
    PRT_VALUE** P_VAR_payload_5 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE BASELINE START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_11;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_11;
    }
    
    PRT_VALUE** P_LVALUE_128 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_128);
    *P_LVALUE_128 = PrtCloneValue(*P_VAR_payload_5);
    
    PrtPrintf("Client Web Browser: Enter Credentials to login to bank!\n");
    
    PrtGoto(p_this, 4U, 0);
    
p_return_11: ;
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
    PRT_VALUE* P_VAR_machineTypeToValidate = PrtMkDefaultValue(&P_GEND_TYPE_r);
    PRT_VALUE* PTMP_tmp0_8 = NULL;
    PRT_VALUE* PTMP_tmp1_7 = NULL;
    PRT_VALUE* PTMP_tmp2_6 = NULL;
    PRT_VALUE* PTMP_tmp3_5 = NULL;
    PRT_VALUE* PTMP_tmp4_5 = NULL;
    PRT_VALUE* PTMP_tmp5_5 = NULL;
    PRT_VALUE* PTMP_tmp6_5 = NULL;
    PRT_VALUE* PTMP_tmp7_4 = NULL;
    PRT_VALUE* P_VAR_P_payload = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_9 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_129 = &(PTMP_tmp0_8);
    PrtFreeValue(*P_LVALUE_129);
    *P_LVALUE_129 = PrtMkStringValue(PrtFormatString("ClientEnclave", 0, 0));
    ;
    
    {
        PRT_VALUE** P_LVALUE_130 = &(P_VAR_machineTypeToValidate);
        PrtFreeValue(*P_LVALUE_130);
        *P_LVALUE_130 = PTMP_tmp0_8;
        PTMP_tmp0_8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_131 = &(PTMP_tmp1_7);
    PrtFreeValue(*P_LVALUE_131);
    *P_LVALUE_131 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_132 = &(PTMP_tmp2_6);
    PrtFreeValue(*P_LVALUE_132);
    *P_LVALUE_132 = PrtCloneValue(P_VAR_machineTypeToValidate);
    
    PRT_VALUE** P_LVALUE_133 = &(PTMP_tmp3_5);
    PrtFreeValue(*P_LVALUE_133);
    *P_LVALUE_133 = ((_P_GEN_funargs[0] = &(PTMP_tmp1_7)), (_P_GEN_funargs[1] = &(PTMP_tmp2_6)), (_P_GEN_funval = P_localAuthenticate_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp1_7), PTMP_tmp1_7 = NULL), (PrtFreeValue(PTMP_tmp2_6), PTMP_tmp2_6 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    if (PrtPrimGetBool(PTMP_tmp3_5))
    {
        PrtPrintf("Authenticated installed enclave!");
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_134 = &(PTMP_tmp4_5);
    PrtFreeValue(*P_LVALUE_134);
    *P_LVALUE_134 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_135 = &(PTMP_tmp5_5);
    PrtFreeValue(*P_LVALUE_135);
    *P_LVALUE_135 = PrtCloneValue((&P_EVENT_GenerateOTPCodeEvent.value));
    
    PRT_VALUE** P_LVALUE_136 = &(PTMP_tmp6_5);
    PrtFreeValue(*P_LVALUE_136);
    *P_LVALUE_136 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE* P_PTMP_tmp_8 = PrtCloneValue(&(P_LIT_INT32_9));
    _P_GEN_funargs[0] = &(PTMP_tmp4_5);
    _P_GEN_funargs[1] = &(PTMP_tmp5_5);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_8);
    _P_GEN_funargs[3] = &(PTMP_tmp6_5);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
    PRT_UINT32 P_allowedEventIds[] = { 2 };
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    PRT_UINT32 P_eventId = PrtReceiveAsync(1U, P_allowedEventIds, &P_VAR_P_payload);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    switch (P_eventId) {
        case 2: {
            PRT_VALUE** P_VAR_payload_6 = &P_VAR_P_payload;
                        PRT_VALUE** P_LVALUE_137 = &(PTMP_tmp7_4);
            PrtFreeValue(*P_LVALUE_137);
            *P_LVALUE_137 = PrtCloneValue(*P_VAR_payload_6);
            
            PrtGoto(p_this, 5U, 1, &(PTMP_tmp7_4));
            
            p_return_13: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    
p_return_12: ;
    PrtFreeValue(P_VAR_machineTypeToValidate); P_VAR_machineTypeToValidate = NULL;
    PrtFreeValue(PTMP_tmp0_8); PTMP_tmp0_8 = NULL;
    PrtFreeValue(PTMP_tmp1_7); PTMP_tmp1_7 = NULL;
    PrtFreeValue(PTMP_tmp2_6); PTMP_tmp2_6 = NULL;
    PrtFreeValue(PTMP_tmp3_5); PTMP_tmp3_5 = NULL;
    PrtFreeValue(PTMP_tmp4_5); PTMP_tmp4_5 = NULL;
    PrtFreeValue(PTMP_tmp5_5); PTMP_tmp5_5 = NULL;
    PrtFreeValue(PTMP_tmp6_5); PTMP_tmp6_5 = NULL;
    PrtFreeValue(PTMP_tmp7_4); PTMP_tmp7_4 = NULL;
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_11 =
{
    NULL,
    &P_Anon_IMPL_11,
    NULL
};


PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_7 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("OTP Code Received:\n");
    
    PRT_VALUE** P_LVALUE_138 = &(PTMP_tmp0_9);
    PrtFreeValue(*P_LVALUE_138);
    *P_LVALUE_138 = PrtCloneValue(*P_VAR_payload_7);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_9);
    PrtFreeValue(P_PrintString_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_9);
    PTMP_tmp0_9 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
    PRT_VALUE** P_LVALUE_139 = &(p_this->varValues[4]);
    PrtFreeValue(*P_LVALUE_139);
    *P_LVALUE_139 = PrtCloneValue(*P_VAR_payload_7);
    
    PrtGoto(p_this, 6U, 0);
    
p_return_14: ;
    PrtFreeValue(PTMP_tmp0_9); PTMP_tmp0_9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_12 =
{
    NULL,
    &P_Anon_IMPL_12,
    &P_GEND_TYPE_StringType
};


PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_10 = NULL;
    PRT_VALUE* PTMP_tmp1_8 = NULL;
    PRT_VALUE* PTMP_tmp2_7 = NULL;
    PRT_VALUE* PTMP_tmp3_6 = NULL;
    PRT_VALUE* PTMP_tmp4_6 = NULL;
    PRT_VALUE* PTMP_tmp5_6 = NULL;
    PRT_VALUE* PTMP_tmp6_6 = NULL;
    PRT_VALUE* PTMP_tmp7_5 = NULL;
    PRT_VALUE* P_VAR_P_payload_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_10 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_140 = &(PTMP_tmp0_10);
    PrtFreeValue(*P_LVALUE_140);
    *P_LVALUE_140 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_141 = &(PTMP_tmp1_8);
    PrtFreeValue(*P_LVALUE_141);
    *P_LVALUE_141 = PrtCloneValue((&P_EVENT_UNTRUSTEDAuthenticateRequest.value));
    
    PRT_VALUE** P_LVALUE_142 = &(PTMP_tmp2_7);
    PrtFreeValue(*P_LVALUE_142);
    *P_LVALUE_142 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_143 = &(PTMP_tmp3_6);
    PrtFreeValue(*P_LVALUE_143);
    *P_LVALUE_143 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_144 = &(PTMP_tmp4_6);
    PrtFreeValue(*P_LVALUE_144);
    *P_LVALUE_144 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_145 = &(PTMP_tmp5_6);
    PrtFreeValue(*P_LVALUE_145);
    *P_LVALUE_145 = (PrtMkTuple(&P_GEND_TYPE_T3StringTypeStringTypeStringType, &(PTMP_tmp2_7), &(PTMP_tmp3_6), &(PTMP_tmp4_6)));
    
    PRT_VALUE* P_PTMP_tmp_9 = PrtCloneValue(&(P_LIT_INT32_10));
    _P_GEN_funargs[0] = &(PTMP_tmp0_10);
    _P_GEN_funargs[1] = &(PTMP_tmp1_8);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_9);
    _P_GEN_funargs[3] = &(PTMP_tmp5_6);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    
    PRT_UINT32 P_allowedEventIds_1[] = { 3, 4 };
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    PRT_UINT32 P_eventId_1 = PrtReceiveAsync(2U, P_allowedEventIds_1, &P_VAR_P_payload_1);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    switch (P_eventId_1) {
        case 3: {
                        PrtGoto(p_this, 7U, 0);
            
            p_return_16: ;
} break;
        case 4: {
                        PrtPrintf("Authentication Failed!");
            
            PrtPrintf("Client Web Browser: Reenter Credentials to login!");
            
            PRT_VALUE** P_LVALUE_146 = &(PTMP_tmp6_6);
            PrtFreeValue(*P_LVALUE_146);
            *P_LVALUE_146 = ((_P_GEN_funval = P_GetUsernameInput_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_15;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_15;
            }
            
            {
                PRT_VALUE** P_LVALUE_147 = &(p_this->varValues[2]);
                PrtFreeValue(*P_LVALUE_147);
                *P_LVALUE_147 = PTMP_tmp6_6;
                PTMP_tmp6_6 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_148 = &(PTMP_tmp7_5);
            PrtFreeValue(*P_LVALUE_148);
            *P_LVALUE_148 = ((_P_GEN_funval = P_GetPasswordInput_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_15;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_15;
            }
            
            {
                PRT_VALUE** P_LVALUE_149 = &(p_this->varValues[3]);
                PrtFreeValue(*P_LVALUE_149);
                *P_LVALUE_149 = PTMP_tmp7_5;
                PTMP_tmp7_5 = NULL;
            }
            
            PrtGoto(p_this, 4U, 0);
            
            p_return_17: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    
p_return_15: ;
    PrtFreeValue(PTMP_tmp0_10); PTMP_tmp0_10 = NULL;
    PrtFreeValue(PTMP_tmp1_8); PTMP_tmp1_8 = NULL;
    PrtFreeValue(PTMP_tmp2_7); PTMP_tmp2_7 = NULL;
    PrtFreeValue(PTMP_tmp3_6); PTMP_tmp3_6 = NULL;
    PrtFreeValue(PTMP_tmp4_6); PTMP_tmp4_6 = NULL;
    PrtFreeValue(PTMP_tmp5_6); PTMP_tmp5_6 = NULL;
    PrtFreeValue(PTMP_tmp6_6); PTMP_tmp6_6 = NULL;
    PrtFreeValue(PTMP_tmp7_5); PTMP_tmp7_5 = NULL;
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_13 =
{
    NULL,
    &P_Anon_IMPL_13,
    NULL
};


PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("Client Web Browser Authenticated Successfully!\n");
    
    PrtPrintf("MEASURE BASELINE END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_18;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_18;
    }
    
    PrtFreeValue(P_EXIT_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_18;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_18;
    }
    
p_return_18: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_14 =
{
    NULL,
    &P_Anon_IMPL_14,
    NULL
};


PRT_FUNDECL* P_ClientWebBrowser_METHODS[] = { &P_FUNCTION_Anon_8, &P_FUNCTION_Anon_9, &P_FUNCTION_Anon_10, &P_FUNCTION_Anon_11, &P_FUNCTION_Anon_12, &P_FUNCTION_Anon_13, &P_FUNCTION_Anon_14 };

PRT_EVENTDECL* P_ClientWebBrowser_RECV_INNER_1[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_RECV_1 =
{
    12U,
    P_ClientWebBrowser_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ClientWebBrowser_SEND_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClientWebBrowser_SEND =
{
    12U,
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
    5U,
    8U,
    7U,
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
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_OTPCodeEvent, &P_EVENT_AuthSuccess, &P_EVENT_AuthFailure, &P_EVENT_BankPublicIDEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_UNTRUSTEDAuthenticateRequest, &P_EVENT_MasterSecretEvent, &P_EVENT_MapEvent, &P_EVENT_TRUSTEDProvisionClientSSM };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_UntrustedInitializer, &P_MACHINE_TrustedInitializer, &P_MACHINE_BankEnclave, &P_MACHINE_ClientEnclave, &P_MACHINE_ClientWebBrowser };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_UntrustedInitializer, &P_I_TrustedInitializer, &P_I_BankEnclave, &P_I_ClientEnclave, &P_I_ClientWebBrowser };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { &P_FUNCTION_seal };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_machine_handle, &P_StringType, &P_secure_StringType, &P_secure_machine_handle, &P_sealed_data, &P_capability, &P_sealed_data_key };
int P_DefaultImpl_LME_0[] = { -1,1,-1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,2,-1,4 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1,3,-1 };
int P_DefaultImpl_LME_3[] = { -1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_4[] = { -1,-1,-1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3, P_DefaultImpl_LME_4 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3,4 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    13U,
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

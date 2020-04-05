#include "OTPBankServerCode.h"

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
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_MKiVi = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };
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

PRT_VALUE* P_Declassify_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Classify_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Concat_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Hash_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CreateUSMMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_PrintKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GenerateRandomMasterSecret_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetUserInput_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetHelloWorld_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_MeasureTime_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

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

PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_15;

PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_16;

PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_17;

PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_18;

PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_19;

PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_20;

PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_21;


PRT_EVENTDECL P_EVENT_TRUSTEDMeasureEvent1 = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDMeasureEvent1",
    4294967295U,
    &P_GEND_TYPE_T2iStringType,
    1
};

PRT_EVENTDECL P_EVENT_TRUSTEDMeasureEvent2 = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDMeasureEvent2",
    4294967295U,
    &P_GEND_TYPE_T2iStringType,
    1
};

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

PRT_EVENTDECL P_EVENT_MasterSecretEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MasterSecretEvent",
    4294967295U,
    &P_GEND_TYPE_secure_StringType,
    1
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

PRT_EVENTDECL P_EVENT_MapEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "MapEvent",
    4294967295U,
    &P_GEND_TYPE_MKiVi,
    1
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
    &P_GEND_TYPE_machine_handle,
    1
};

PRT_EVENTDECL P_EVENT_TRUSTEDProvisionClientSSM = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "TRUSTEDProvisionClientSSM",
    4294967295U,
    &P_GEND_TYPE_machine_handle,
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


PRT_FUNDECL P_FUNCTION_Declassify =
{
    "Declassify",
    &P_Declassify_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_Classify =
{
    "Classify",
    &P_Classify_IMPL,
    NULL
};


PRT_FUNDECL P_FUNCTION_GetThis =
{
    "GetThis",
    &P_GetThis_IMPL,
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


PRT_FUNDECL P_FUNCTION_GetUserInput =
{
    "GetUserInput",
    &P_GetUserInput_IMPL,
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

PRT_EVENTDECL* P_MeasureMachine_RECV_INNER[] = { &P_EVENT_AuthFailure, &P_EVENT_AuthSuccess, &P_EVENT_AuthenticateRequest, &P_EVENT_BankPublicIDEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_MasterSecretEvent, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_OTPCodeEvent, &P_EVENT_PublicIDEvent, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MeasureMachine_RECV =
{
    17U,
    P_MeasureMachine_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_MeasureMachine =
{
    1U,
    "MeasureMachine",
    &P_GEND_TYPE_n,
    &P_EVENTSET_MeasureMachine_RECV
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
    2U,
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
    3U,
    "BankEnclave",
    &P_GEND_TYPE_n,
    &P_EVENTSET_BankEnclave_RECV
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
    4U,
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
    5U,
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
    PRT_VALUE* PTMP_tmp0 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE UNTRUSTED CREATE START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    _P_GEN_funargs[0] = "MeasureMachine";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = ((_P_GEN_funval = P_CreateUSMMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
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
    
    _P_GEN_funargs[0] = "TrustedInitializer";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_3 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_3);
        *P_LVALUE_3 = PTMP_tmp1;
        PTMP_tmp1 = NULL;
    }
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
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

PRT_UINT32 P_UntrustedInitializer_CREATES_ARR[] = { 1, 2 };
PRT_INTERFACESETDECL P_UntrustedInitializer_CREATES = { 2, P_UntrustedInitializer_CREATES_ARR };
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

#define P_STATE_MeasureMachine_Initial \
{ \
    "MeasureMachine.Initial", \
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

PRT_STATEDECL P_MeasureMachine_STATES[] = { P_STATE_MeasureMachine_Initial };

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE UNTRUSTED CREATE END:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
p_return_1: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL
};


PRT_FUNDECL* P_MeasureMachine_METHODS[] = { &P_FUNCTION_Anon_1 };

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
    1U,
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

PRT_VARDECL P_TrustedInitializer_VARS[] = {
    { "clientUSM", &P_GEND_TYPE_machine_handle },
    { "bankSSM", &P_GEND_TYPE_secure_machine_handle }
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

#define P_STATE_TrustedInitializer_Initial \
{ \
    "TrustedInitializer.Initial", \
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

PRT_STATEDECL P_TrustedInitializer_STATES[] = { P_STATE_TrustedInitializer_Initial };

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    _P_GEN_funargs[0] = "ClientWebBrowser";
    _P_GEN_funargs[1] = "0";
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp0_1);
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
        *P_LVALUE_5 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    _P_GEN_funargs[0] = "BankEnclave";
    _P_GEN_funargs[1] = "0";
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
    *P_LVALUE_8 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtCloneValue((&P_EVENT_TRUSTEDProvisionBankSSM.value));
    
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE* P_PTMP_tmp = PrtCloneValue(&(P_LIT_INT32));
    _P_GEN_funargs[0] = &(PTMP_tmp2);
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
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue((&P_EVENT_BankPublicIDEvent.value));
    
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = ((_P_GEN_funargs[0] = &(PTMP_tmp7)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp7), PTMP_tmp7 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtCloneValue(PrtCastValue(PTMP_tmp8, &P_GEND_TYPE_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp_1 = PrtCloneValue(&(P_LIT_INT32));
    _P_GEN_funargs[0] = &(PTMP_tmp5);
    _P_GEN_funargs[1] = &(PTMP_tmp6);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_1);
    _P_GEN_funargs[3] = &(PTMP_tmp9);
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
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
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

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    NULL
};


PRT_FUNDECL* P_TrustedInitializer_METHODS[] = { &P_FUNCTION_Anon_2 };

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

PRT_UINT32 P_TrustedInitializer_CREATES_ARR[] = { 3, 5 };
PRT_INTERFACESETDECL P_TrustedInitializer_CREATES = { 2, P_TrustedInitializer_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_TrustedInitializer = 
{
    2U,
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

#define P_STATE_BankEnclave_Initial \
{ \
    "BankEnclave.Initial", \
    0U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_3, \
    &P_EVENTSET_Initial_TRANS_3, \
    &P_EVENTSET_Initial_DOS_3, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_3, \
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
    { 1, &P_EVENT_TRUSTEDProvisionBankSSM, &P_FUNCTION_Anon_4 }
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

PRT_EVENTDECL* P_RegisterNewBankAccount_DOS_INNER[] = { &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials };
PRT_EVENTSETDECL P_EVENTSET_RegisterNewBankAccount_DOS =
{
    3U,
    P_RegisterNewBankAccount_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_1[] =
{
    { 2, &P_EVENT_MeasureEvent1, &P_FUNCTION_Anon_5 },
    { 2, &P_EVENT_MeasureEvent2, &P_FUNCTION_Anon_6 },
    { 2, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &P_FUNCTION_Anon_7 }
};

#define P_STATE_BankEnclave_RegisterNewBankAccount \
{ \
    "BankEnclave.RegisterNewBankAccount", \
    0U, \
    3U, \
    &P_EVENTSET_RegisterNewBankAccount_DEFERS, \
    &P_EVENTSET_RegisterNewBankAccount_TRANS, \
    &P_EVENTSET_RegisterNewBankAccount_DOS, \
    NULL, \
    P_DOS_1, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_AuthCheck_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_AuthCheck_DEFERS =
{
    0U,
    P_AuthCheck_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_AuthCheck_TRANS_INNER[] = { &P_EVENT_AuthenticateRequest };
PRT_EVENTSETDECL P_EVENTSET_AuthCheck_TRANS =
{
    1U,
    P_AuthCheck_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_AuthCheck_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_AuthCheck_DOS =
{
    0U,
    P_AuthCheck_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 3, &P_EVENT_AuthenticateRequest, 4, &_P_NO_OP }
};

#define P_STATE_BankEnclave_AuthCheck \
{ \
    "BankEnclave.AuthCheck", \
    1U, \
    0U, \
    &P_EVENTSET_AuthCheck_DEFERS, \
    &P_EVENTSET_AuthCheck_TRANS, \
    &P_EVENTSET_AuthCheck_DOS, \
    P_TRANS, \
    NULL, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Verify_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Verify_DEFERS =
{
    0U,
    P_Verify_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Verify_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Verify_TRANS =
{
    0U,
    P_Verify_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Verify_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Verify_DOS =
{
    0U,
    P_Verify_DOS_INNER,
    NULL
};

#define P_STATE_BankEnclave_Verify \
{ \
    "BankEnclave.Verify", \
    0U, \
    0U, \
    &P_EVENTSET_Verify_DEFERS, \
    &P_EVENTSET_Verify_TRANS, \
    &P_EVENTSET_Verify_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_8, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_BankEnclave_STATES[] = { P_STATE_BankEnclave_Initial, P_STATE_BankEnclave_ReceiveClientUSM, P_STATE_BankEnclave_RegisterNewBankAccount, P_STATE_BankEnclave_AuthCheck, P_STATE_BankEnclave_Verify };

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
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

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    NULL
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8_1 = NULL;
    PRT_VALUE* PTMP_tmp9_1 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_16 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = PrtCloneValue(*P_VAR_payload);
    
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
    PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = ((_P_GEN_funval = P_CreateSecureMachineRequest_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_18 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_18);
        *P_LVALUE_18 = PTMP_tmp0_2;
        PTMP_tmp0_2 = NULL;
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
    
    PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_19);
    *P_LVALUE_19 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = PrtCloneValue((&P_EVENT_TRUSTEDMeasureEvent1.value));
    
    PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtCloneValue((&P_LIT_INT32_1));
    
    PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = ((_P_GEN_funval = P_GetHelloWorld_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_23);
    *P_LVALUE_23 = (PrtMkTuple(&P_GEND_TYPE_T2iStringType, &(PTMP_tmp3_1), &(PTMP_tmp4_1)));
    
    PRT_VALUE* P_PTMP_tmp_2 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp1_2);
    _P_GEN_funargs[1] = &(PTMP_tmp2_1);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_2);
    _P_GEN_funargs[3] = &(PTMP_tmp5_1);
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
    
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp7_1);
    PrtFreeValue(*P_LVALUE_25);
    *P_LVALUE_25 = PrtCloneValue((&P_EVENT_TRUSTEDMeasureEvent2.value));
    
    PRT_VALUE** P_LVALUE_26 = &(PTMP_tmp8_1);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue((&P_LIT_INT32_1));
    
    PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp9_1);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = ((_P_GEN_funval = P_GetHelloWorld_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = (PrtMkTuple(&P_GEND_TYPE_T2iStringType, &(PTMP_tmp8_1), &(PTMP_tmp9_1)));
    
    PRT_VALUE* P_PTMP_tmp_3 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp6_1);
    _P_GEN_funargs[1] = &(PTMP_tmp7_1);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_3);
    _P_GEN_funargs[3] = &(PTMP_tmp10);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp11);
    PrtFreeValue(*P_LVALUE_29);
    *P_LVALUE_29 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp12);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtCloneValue((&P_EVENT_TRUSTEDProvisionClientSSM.value));
    
    PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp13);
    PrtFreeValue(*P_LVALUE_31);
    *P_LVALUE_31 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE* P_PTMP_tmp_4 = PrtCloneValue(&(P_LIT_INT32_1));
    _P_GEN_funargs[0] = &(PTMP_tmp11);
    _P_GEN_funargs[1] = &(PTMP_tmp12);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_4);
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
    
    PrtGoto(p_this, 2U, 0);
    
p_return_4: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8_1); PTMP_tmp8_1 = NULL;
    PrtFreeValue(PTMP_tmp9_1); PTMP_tmp9_1 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    &P_GEND_TYPE_machine_handle
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
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

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_T2iStringType
};


PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
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
    
p_return_6: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    &P_GEND_TYPE_T2iStringType
};


PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_2 = NULL;
    PRT_VALUE* PTMP_tmp7_2 = NULL;
    PRT_VALUE* PTMP_tmp8_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PrtPrintf("Bank: Creating new bank account!");
    
    PRT_VALUE** P_LVALUE_32 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_32);
    *P_LVALUE_32 = PrtCloneValue(*P_VAR_payload_3);
    
    PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_33);
    *P_LVALUE_33 = ((_P_GEN_funval = P_GenerateRandomMasterSecret_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    {
        PRT_VALUE** P_LVALUE_34 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_34);
        *P_LVALUE_34 = PTMP_tmp0_3;
        PTMP_tmp0_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp1_3);
    PrtFreeValue(*P_LVALUE_35);
    *P_LVALUE_35 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_36);
    *P_LVALUE_36 = PrtCloneValue((&P_EVENT_MasterSecretEvent.value));
    
    PRT_VALUE** P_LVALUE_37 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_37);
    *P_LVALUE_37 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE* P_PTMP_tmp_5 = PrtCloneValue(&(P_LIT_INT32_2));
    _P_GEN_funargs[0] = &(PTMP_tmp1_3);
    _P_GEN_funargs[1] = &(PTMP_tmp2_2);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_5);
    _P_GEN_funargs[3] = &(PTMP_tmp3_2);
    PrtFreeValue(P_SecureSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp4_2);
    PrtFreeValue(*P_LVALUE_38);
    *P_LVALUE_38 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_39 = &(PTMP_tmp5_2);
    PrtFreeValue(*P_LVALUE_39);
    *P_LVALUE_39 = PrtCloneValue((&P_EVENT_PublicIDEvent.value));
    
    PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp6_2);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_41 = &(PTMP_tmp7_2);
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = ((_P_GEN_funargs[0] = &(PTMP_tmp6_2)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp6_2), PTMP_tmp6_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp8_2);
    PrtFreeValue(*P_LVALUE_42);
    *P_LVALUE_42 = PrtCloneValue(PrtCastValue(PTMP_tmp7_2, &P_GEND_TYPE_machine_handle));
    
    PRT_VALUE* P_PTMP_tmp_6 = PrtCloneValue(&(P_LIT_INT32_2));
    _P_GEN_funargs[0] = &(PTMP_tmp4_2);
    _P_GEN_funargs[1] = &(PTMP_tmp5_2);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_6);
    _P_GEN_funargs[3] = &(PTMP_tmp8_2);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_7;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_7;
    }
    
    PrtGoto(p_this, 3U, 0);
    
p_return_7: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_2); PTMP_tmp6_2 = NULL;
    PrtFreeValue(PTMP_tmp7_2); PTMP_tmp7_2 = NULL;
    PrtFreeValue(PTMP_tmp8_2); PTMP_tmp8_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_StringType
};


PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_4 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_3 = NULL;
    PRT_VALUE* PTMP_tmp5_3 = NULL;
    PRT_VALUE* PTMP_tmp6_3 = NULL;
    PRT_VALUE* PTMP_tmp7_3 = NULL;
    PRT_VALUE* PTMP_tmp8_3 = NULL;
    PRT_VALUE* PTMP_tmp9_2 = NULL;
    PRT_VALUE* PTMP_tmp10_1 = NULL;
    PRT_VALUE* PTMP_tmp11_1 = NULL;
    PRT_VALUE* PTMP_tmp12_1 = NULL;
    PRT_VALUE* PTMP_tmp13_1 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    PRT_VALUE* PTMP_tmp17 = NULL;
    PRT_VALUE* PTMP_tmp18 = NULL;
    PRT_VALUE* PTMP_tmp19 = NULL;
    PRT_VALUE* PTMP_tmp20 = NULL;
    PRT_VALUE* PTMP_tmp21 = NULL;
    PRT_VALUE* PTMP_tmp22 = NULL;
    PRT_VALUE* PTMP_tmp23 = NULL;
    PRT_VALUE* PTMP_tmp24 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_43);
    *P_LVALUE_43 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_44 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_44);
    *P_LVALUE_44 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_4)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_4), PTMP_tmp0_4 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp2_3);
    PrtFreeValue(*P_LVALUE_45);
    *P_LVALUE_45 = PrtCloneValue(PrtCastValue(PTMP_tmp1_4, &P_GEND_TYPE_StringType));
    
    _P_GEN_funargs[0] = &(PTMP_tmp2_3);
    PrtFreeValue(P_PrintRawStringType_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp2_3);
    PTMP_tmp2_3 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp3_3);
    PrtFreeValue(*P_LVALUE_46);
    *P_LVALUE_46 = PrtTupleGet(*P_VAR_payload_4, 0);
    
    PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp4_3);
    PrtFreeValue(*P_LVALUE_47);
    *P_LVALUE_47 = PrtCloneValue(PrtCastValue(PTMP_tmp3_3, &P_GEND_TYPE_StringType));
    
    _P_GEN_funargs[0] = &(PTMP_tmp4_3);
    PrtFreeValue(P_PrintRawStringType_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp4_3);
    PTMP_tmp4_3 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_48 = &(PTMP_tmp5_3);
    PrtFreeValue(*P_LVALUE_48);
    *P_LVALUE_48 = PrtCloneValue(PrtCastValue(p_this->varValues[2], &P_GEND_TYPE_StringType));
    
    PRT_VALUE** P_LVALUE_49 = &(PTMP_tmp6_3);
    PrtFreeValue(*P_LVALUE_49);
    *P_LVALUE_49 = PrtCloneValue(PrtCastValue(p_this->varValues[3], &P_GEND_TYPE_StringType));
    
    PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp7_3);
    PrtFreeValue(*P_LVALUE_50);
    *P_LVALUE_50 = ((_P_GEN_funargs[0] = &(PTMP_tmp5_3)), (_P_GEN_funargs[1] = &(PTMP_tmp6_3)), (_P_GEN_funval = P_Hash_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp5_3), PTMP_tmp5_3 = NULL), (PrtFreeValue(PTMP_tmp6_3), PTMP_tmp6_3 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    _P_GEN_funargs[0] = &(PTMP_tmp7_3);
    PrtFreeValue(P_PrintRawStringType_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp7_3);
    PTMP_tmp7_3 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp8_3);
    PrtFreeValue(*P_LVALUE_51);
    *P_LVALUE_51 = PrtTupleGet(*P_VAR_payload_4, 1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp8_3);
    PrtFreeValue(P_PrintRawStringType_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp8_3);
    PTMP_tmp8_3 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp9_2);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp10_1);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = ((_P_GEN_funargs[0] = &(PTMP_tmp9_2)), (_P_GEN_funval = P_Declassify_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp9_2), PTMP_tmp9_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp11_1);
    PrtFreeValue(*P_LVALUE_54);
    *P_LVALUE_54 = PrtCloneValue(PrtCastValue(PTMP_tmp10_1, &P_GEND_TYPE_StringType));
    
    PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp12_1);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtTupleGet(*P_VAR_payload_4, 0);
    
    PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp13_1);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = PrtCloneValue(PrtCastValue(PTMP_tmp12_1, &P_GEND_TYPE_StringType));
    
    PRT_VALUE** P_LVALUE_57 = &(PTMP_tmp14);
    PrtFreeValue(*P_LVALUE_57);
    *P_LVALUE_57 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp11_1, PTMP_tmp13_1));
    
    PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp20);
    PrtFreeValue(*P_LVALUE_58);
    *P_LVALUE_58 = PrtCloneValue(PTMP_tmp14);
    
    if (PrtPrimGetBool(PTMP_tmp20))
    {
        PRT_VALUE** P_LVALUE_59 = &(PTMP_tmp15);
        PrtFreeValue(*P_LVALUE_59);
        *P_LVALUE_59 = PrtCloneValue(PrtCastValue(p_this->varValues[2], &P_GEND_TYPE_StringType));
        
        PRT_VALUE** P_LVALUE_60 = &(PTMP_tmp16);
        PrtFreeValue(*P_LVALUE_60);
        *P_LVALUE_60 = PrtCloneValue(PrtCastValue(p_this->varValues[3], &P_GEND_TYPE_StringType));
        
        PRT_VALUE** P_LVALUE_61 = &(PTMP_tmp17);
        PrtFreeValue(*P_LVALUE_61);
        *P_LVALUE_61 = ((_P_GEN_funargs[0] = &(PTMP_tmp15)), (_P_GEN_funargs[1] = &(PTMP_tmp16)), (_P_GEN_funval = P_Hash_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp15), PTMP_tmp15 = NULL), (PrtFreeValue(PTMP_tmp16), PTMP_tmp16 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
        PRT_VALUE** P_LVALUE_62 = &(PTMP_tmp18);
        PrtFreeValue(*P_LVALUE_62);
        *P_LVALUE_62 = PrtTupleGet(*P_VAR_payload_4, 1);
        
        PRT_VALUE** P_LVALUE_63 = &(PTMP_tmp19);
        PrtFreeValue(*P_LVALUE_63);
        *P_LVALUE_63 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp17, PTMP_tmp18));
        
        PRT_VALUE** P_LVALUE_64 = &(PTMP_tmp20);
        PrtFreeValue(*P_LVALUE_64);
        *P_LVALUE_64 = PrtCloneValue(PTMP_tmp19);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp20))
    {
        PRT_VALUE** P_LVALUE_65 = &(PTMP_tmp21);
        PrtFreeValue(*P_LVALUE_65);
        *P_LVALUE_65 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_66 = &(PTMP_tmp22);
        PrtFreeValue(*P_LVALUE_66);
        *P_LVALUE_66 = PrtCloneValue((&P_EVENT_AuthSuccess.value));
        
        PRT_VALUE* P_PTMP_tmp_7 = PrtCloneValue(&(P_LIT_INT32_3));
        _P_GEN_funargs[0] = &(PTMP_tmp21);
        _P_GEN_funargs[1] = &(PTMP_tmp22);
        _P_GEN_funargs[2] = &(P_PTMP_tmp_7);
        PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_67 = &(PTMP_tmp23);
        PrtFreeValue(*P_LVALUE_67);
        *P_LVALUE_67 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_68 = &(PTMP_tmp24);
        PrtFreeValue(*P_LVALUE_68);
        *P_LVALUE_68 = PrtCloneValue((&P_EVENT_AuthFailure.value));
        
        PRT_VALUE* P_PTMP_tmp_8 = PrtCloneValue(&(P_LIT_INT32_3));
        _P_GEN_funargs[0] = &(PTMP_tmp23);
        _P_GEN_funargs[1] = &(PTMP_tmp24);
        _P_GEN_funargs[2] = &(P_PTMP_tmp_8);
        PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
    }
    
    
    PrtGoto(p_this, 3U, 0);
    
p_return_8: ;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_3); PTMP_tmp4_3 = NULL;
    PrtFreeValue(PTMP_tmp5_3); PTMP_tmp5_3 = NULL;
    PrtFreeValue(PTMP_tmp6_3); PTMP_tmp6_3 = NULL;
    PrtFreeValue(PTMP_tmp7_3); PTMP_tmp7_3 = NULL;
    PrtFreeValue(PTMP_tmp8_3); PTMP_tmp8_3 = NULL;
    PrtFreeValue(PTMP_tmp9_2); PTMP_tmp9_2 = NULL;
    PrtFreeValue(PTMP_tmp10_1); PTMP_tmp10_1 = NULL;
    PrtFreeValue(PTMP_tmp11_1); PTMP_tmp11_1 = NULL;
    PrtFreeValue(PTMP_tmp12_1); PTMP_tmp12_1 = NULL;
    PrtFreeValue(PTMP_tmp13_1); PTMP_tmp13_1 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    PrtFreeValue(PTMP_tmp17); PTMP_tmp17 = NULL;
    PrtFreeValue(PTMP_tmp18); PTMP_tmp18 = NULL;
    PrtFreeValue(PTMP_tmp19); PTMP_tmp19 = NULL;
    PrtFreeValue(PTMP_tmp20); PTMP_tmp20 = NULL;
    PrtFreeValue(PTMP_tmp21); PTMP_tmp21 = NULL;
    PrtFreeValue(PTMP_tmp22); PTMP_tmp22 = NULL;
    PrtFreeValue(PTMP_tmp23); PTMP_tmp23 = NULL;
    PrtFreeValue(PTMP_tmp24); PTMP_tmp24 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_8,
    &P_GEND_TYPE_T2StringTypeStringType
};


PRT_FUNDECL* P_BankEnclave_METHODS[] = { &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5, &P_FUNCTION_Anon_6, &P_FUNCTION_Anon_7, &P_FUNCTION_Anon_8 };

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

PRT_UINT32 P_BankEnclave_CREATES_ARR[] = { 4 };
PRT_INTERFACESETDECL P_BankEnclave_CREATES = { 1, P_BankEnclave_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_BankEnclave = 
{
    3U,
    "BankEnclave",
    &P_EVENTSET_BankEnclave_RECV_1,
    &P_EVENTSET_BankEnclave_SEND,
    &P_BankEnclave_CREATES,
    4U,
    5U,
    6U,
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

PRT_EVENTDECL* P_Initial_DEFERS_INNER_4[] = { &P_EVENT_GenerateOTPCodeEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_4 =
{
    1U,
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

PRT_EVENTDECL* P_Initial_DOS_INNER_4[] = { &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_TRUSTEDProvisionClientSSM };
PRT_EVENTSETDECL P_EVENTSET_Initial_DOS_4 =
{
    3U,
    P_Initial_DOS_INNER_4,
    NULL
};

PRT_DODECL P_DOS_2[] =
{
    { 0, &P_EVENT_TRUSTEDMeasureEvent1, &P_FUNCTION_Anon_10 },
    { 0, &P_EVENT_TRUSTEDMeasureEvent2, &P_FUNCTION_Anon_11 },
    { 0, &P_EVENT_TRUSTEDProvisionClientSSM, &P_FUNCTION_Anon_12 }
};

#define P_STATE_ClientEnclave_Initial \
{ \
    "ClientEnclave.Initial", \
    0U, \
    3U, \
    &P_EVENTSET_Initial_DEFERS_4, \
    &P_EVENTSET_Initial_TRANS_4, \
    &P_EVENTSET_Initial_DOS_4, \
    NULL, \
    P_DOS_2, \
    &P_FUNCTION_Anon_9, \
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

PRT_TRANSDECL P_TRANS_1[] =
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
    P_TRANS_1, \
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
    &P_FUNCTION_Anon_13, \
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

PRT_DODECL P_DOS_3[] =
{
    { 3, &P_EVENT_GenerateOTPCodeEvent, &P_FUNCTION_Anon_14 }
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
    P_DOS_3, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClientEnclave_STATES[] = { P_STATE_ClientEnclave_Initial, P_STATE_ClientEnclave_ReceiveMasterSecretEvent, P_STATE_ClientEnclave_ProvisionEnclaveWithSecret, P_STATE_ClientEnclave_WaitForGenerateOTP };

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
    PrtPrintf("MEASURE TRUSTED SEND END:");
    
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

PRT_FUNDECL P_FUNCTION_Anon_10 =
{
    NULL,
    &P_Anon_IMPL_10,
    &P_GEND_TYPE_T2iStringType
};


PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_6 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("MEASURE TRUSTED SEND 2 END:");
    
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

PRT_FUNDECL P_FUNCTION_Anon_11 =
{
    NULL,
    &P_Anon_IMPL_11,
    &P_GEND_TYPE_T2iStringType
};


PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_7 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_69 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_69);
    *P_LVALUE_69 = PrtCloneValue(*P_VAR_payload_7);
    
    PrtGoto(p_this, 1U, 0);
    
p_return_12: ;
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
    PRT_VALUE** P_VAR_payload_8 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_70 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_70);
    *P_LVALUE_70 = PrtCloneValue(*P_VAR_payload_8);
    
    PrtGoto(p_this, 3U, 0);
    
p_return_13: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_13 =
{
    NULL,
    &P_Anon_IMPL_13,
    &P_GEND_TYPE_secure_StringType
};


PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_usernamePassword = argRefs[0];
    PRT_VALUE* P_VAR_hashedString = PrtMkDefaultValue(&P_GEND_TYPE_StringType);
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_5 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    PRT_VALUE* PTMP_tmp3_4 = NULL;
    PRT_VALUE* PTMP_tmp4_4 = NULL;
    PRT_VALUE* PTMP_tmp5_4 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_71 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_71);
    *P_LVALUE_71 = PrtCloneValue(PrtCastValue(p_this->varValues[0], &P_GEND_TYPE_StringType));
    
    PRT_VALUE** P_LVALUE_72 = &(PTMP_tmp1_5);
    PrtFreeValue(*P_LVALUE_72);
    *P_LVALUE_72 = PrtCloneValue(*P_VAR_usernamePassword);
    
    PRT_VALUE** P_LVALUE_73 = &(PTMP_tmp2_4);
    PrtFreeValue(*P_LVALUE_73);
    *P_LVALUE_73 = ((_P_GEN_funargs[0] = &(PTMP_tmp0_5)), (_P_GEN_funargs[1] = &(PTMP_tmp1_5)), (_P_GEN_funval = P_Hash_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp0_5), PTMP_tmp0_5 = NULL), (PrtFreeValue(PTMP_tmp1_5), PTMP_tmp1_5 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
    {
        PRT_VALUE** P_LVALUE_74 = &(P_VAR_hashedString);
        PrtFreeValue(*P_LVALUE_74);
        *P_LVALUE_74 = PTMP_tmp2_4;
        PTMP_tmp2_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_75 = &(PTMP_tmp3_4);
    PrtFreeValue(*P_LVALUE_75);
    *P_LVALUE_75 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_76 = &(PTMP_tmp4_4);
    PrtFreeValue(*P_LVALUE_76);
    *P_LVALUE_76 = PrtCloneValue((&P_EVENT_OTPCodeEvent.value));
    
    PRT_VALUE** P_LVALUE_77 = &(PTMP_tmp5_4);
    PrtFreeValue(*P_LVALUE_77);
    *P_LVALUE_77 = PrtCloneValue(P_VAR_hashedString);
    
    PRT_VALUE* P_PTMP_tmp_9 = PrtCloneValue(&(P_LIT_INT32_4));
    _P_GEN_funargs[0] = &(PTMP_tmp3_4);
    _P_GEN_funargs[1] = &(PTMP_tmp4_4);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_9);
    _P_GEN_funargs[3] = &(PTMP_tmp5_4);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
p_return_14: ;
    PrtFreeValue(P_VAR_hashedString); P_VAR_hashedString = NULL;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_5); PTMP_tmp1_5 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    PrtFreeValue(PTMP_tmp3_4); PTMP_tmp3_4 = NULL;
    PrtFreeValue(PTMP_tmp4_4); PTMP_tmp4_4 = NULL;
    PrtFreeValue(PTMP_tmp5_4); PTMP_tmp5_4 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_14 =
{
    NULL,
    &P_Anon_IMPL_14,
    &P_GEND_TYPE_StringType
};


PRT_FUNDECL* P_ClientEnclave_METHODS[] = { &P_FUNCTION_Anon_9, &P_FUNCTION_Anon_10, &P_FUNCTION_Anon_11, &P_FUNCTION_Anon_12, &P_FUNCTION_Anon_13, &P_FUNCTION_Anon_14 };

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
    4U,
    "ClientEnclave",
    &P_EVENTSET_ClientEnclave_RECV_1,
    &P_EVENTSET_ClientEnclave_SEND,
    NULL,
    2U,
    4U,
    6U,
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

PRT_EVENTDECL* P_Initial_DEFERS_INNER_5[] = { &P_EVENT_PublicIDEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_DEFERS_5 =
{
    1U,
    P_Initial_DEFERS_INNER_5,
    NULL
};

PRT_EVENTDECL* P_Initial_TRANS_INNER_5[] = { &P_EVENT_BankPublicIDEvent };
PRT_EVENTSETDECL P_EVENTSET_Initial_TRANS_5 =
{
    1U,
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

PRT_TRANSDECL P_TRANS_2[] =
{
    { 0, &P_EVENT_BankPublicIDEvent, 1, &_P_NO_OP }
};

#define P_STATE_ClientWebBrowser_Initial \
{ \
    "ClientWebBrowser.Initial", \
    1U, \
    0U, \
    &P_EVENTSET_Initial_DEFERS_5, \
    &P_EVENTSET_Initial_TRANS_5, \
    &P_EVENTSET_Initial_DOS_5, \
    P_TRANS_2, \
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
    &P_FUNCTION_Anon_15, \
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

PRT_TRANSDECL P_TRANS_3[] =
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
    P_TRANS_3, \
    NULL, \
    &P_FUNCTION_Anon_16, \
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
    &P_FUNCTION_Anon_17, \
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
    &P_FUNCTION_Anon_18, \
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
    &P_FUNCTION_Anon_19, \
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
    &P_FUNCTION_Anon_20, \
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
    &P_FUNCTION_Anon_21, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClientWebBrowser_STATES[] = { P_STATE_ClientWebBrowser_Initial, P_STATE_ClientWebBrowser_SaveBankSSM, P_STATE_ClientWebBrowser_RegisterAccountInBank, P_STATE_ClientWebBrowser_Authenticate, P_STATE_ClientWebBrowser_RequestOTPCodeGeneration, P_STATE_ClientWebBrowser_SaveOTPCode, P_STATE_ClientWebBrowser_ValidateOTPCode, P_STATE_ClientWebBrowser_Done };

PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_9 = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_78 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_78);
    *P_LVALUE_78 = PrtCloneValue(*P_VAR_payload_9);
    
    PrtGoto(p_this, 2U, 0);
    
p_return_15: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_15 =
{
    NULL,
    &P_Anon_IMPL_15,
    &P_GEND_TYPE_machine_handle
};


PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_credentials = PrtMkDefaultValue(&P_GEND_TYPE_StringType);
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    PRT_VALUE* PTMP_tmp1_6 = NULL;
    PRT_VALUE* PTMP_tmp2_5 = NULL;
    PRT_VALUE* PTMP_tmp3_5 = NULL;
    PRT_VALUE* PTMP_tmp4_5 = NULL;
    PRT_VALUE* PTMP_tmp5_5 = NULL;
    PRT_VALUE* PTMP_tmp6_4 = NULL;
    PRT_VALUE* PTMP_tmp7_4 = NULL;
    PRT_VALUE* PTMP_tmp8_4 = NULL;
    PRT_VALUE* PTMP_tmp9_3 = NULL;
    PRT_VALUE* PTMP_tmp10_2 = NULL;
    PRT_VALUE* PTMP_tmp11_2 = NULL;
    PRT_VALUE* PTMP_tmp12_2 = NULL;
    PRT_VALUE* PTMP_tmp13_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_79 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_79);
    *P_LVALUE_79 = ((_P_GEN_funval = P_GetUserInput_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    {
        PRT_VALUE** P_LVALUE_80 = &(P_VAR_credentials);
        PrtFreeValue(*P_LVALUE_80);
        *P_LVALUE_80 = PTMP_tmp0_6;
        PTMP_tmp0_6 = NULL;
    }
    
    PrtPrintf("MEASURE UNTRUSTED SEND START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    PRT_VALUE** P_LVALUE_81 = &(PTMP_tmp1_6);
    PrtFreeValue(*P_LVALUE_81);
    *P_LVALUE_81 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_82 = &(PTMP_tmp2_5);
    PrtFreeValue(*P_LVALUE_82);
    *P_LVALUE_82 = PrtCloneValue((&P_EVENT_MeasureEvent1.value));
    
    PRT_VALUE** P_LVALUE_83 = &(PTMP_tmp3_5);
    PrtFreeValue(*P_LVALUE_83);
    *P_LVALUE_83 = PrtCloneValue((&P_LIT_INT32_5));
    
    PRT_VALUE** P_LVALUE_84 = &(PTMP_tmp4_5);
    PrtFreeValue(*P_LVALUE_84);
    *P_LVALUE_84 = ((_P_GEN_funval = P_GetHelloWorld_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    PRT_VALUE** P_LVALUE_85 = &(PTMP_tmp5_5);
    PrtFreeValue(*P_LVALUE_85);
    *P_LVALUE_85 = (PrtMkTuple(&P_GEND_TYPE_T2iStringType, &(PTMP_tmp3_5), &(PTMP_tmp4_5)));
    
    PRT_VALUE* P_PTMP_tmp_10 = PrtCloneValue(&(P_LIT_INT32_5));
    _P_GEN_funargs[0] = &(PTMP_tmp1_6);
    _P_GEN_funargs[1] = &(PTMP_tmp2_5);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_10);
    _P_GEN_funargs[3] = &(PTMP_tmp5_5);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    PrtPrintf("MEASURE UNTRUSTED SEND 2 START:");
    
    PrtFreeValue(P_MeasureTime_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    PRT_VALUE** P_LVALUE_86 = &(PTMP_tmp6_4);
    PrtFreeValue(*P_LVALUE_86);
    *P_LVALUE_86 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_87 = &(PTMP_tmp7_4);
    PrtFreeValue(*P_LVALUE_87);
    *P_LVALUE_87 = PrtCloneValue((&P_EVENT_MeasureEvent2.value));
    
    PRT_VALUE** P_LVALUE_88 = &(PTMP_tmp8_4);
    PrtFreeValue(*P_LVALUE_88);
    *P_LVALUE_88 = PrtCloneValue((&P_LIT_INT32_5));
    
    PRT_VALUE** P_LVALUE_89 = &(PTMP_tmp9_3);
    PrtFreeValue(*P_LVALUE_89);
    *P_LVALUE_89 = ((_P_GEN_funval = P_GetHelloWorld_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    PRT_VALUE** P_LVALUE_90 = &(PTMP_tmp10_2);
    PrtFreeValue(*P_LVALUE_90);
    *P_LVALUE_90 = (PrtMkTuple(&P_GEND_TYPE_T2iStringType, &(PTMP_tmp8_4), &(PTMP_tmp9_3)));
    
    PRT_VALUE* P_PTMP_tmp_11 = PrtCloneValue(&(P_LIT_INT32_5));
    _P_GEN_funargs[0] = &(PTMP_tmp6_4);
    _P_GEN_funargs[1] = &(PTMP_tmp7_4);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_11);
    _P_GEN_funargs[3] = &(PTMP_tmp10_2);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    PRT_VALUE** P_LVALUE_91 = &(PTMP_tmp11_2);
    PrtFreeValue(*P_LVALUE_91);
    *P_LVALUE_91 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_92 = &(PTMP_tmp12_2);
    PrtFreeValue(*P_LVALUE_92);
    *P_LVALUE_92 = PrtCloneValue((&P_EVENT_UNTRUSTEDReceiveRegistrationCredentials.value));
    
    PRT_VALUE** P_LVALUE_93 = &(PTMP_tmp13_2);
    PrtFreeValue(*P_LVALUE_93);
    *P_LVALUE_93 = PrtCloneValue(P_VAR_credentials);
    
    PRT_VALUE* P_PTMP_tmp_12 = PrtCloneValue(&(P_LIT_INT32_5));
    _P_GEN_funargs[0] = &(PTMP_tmp11_2);
    _P_GEN_funargs[1] = &(PTMP_tmp12_2);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_12);
    _P_GEN_funargs[3] = &(PTMP_tmp13_2);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
p_return_16: ;
    PrtFreeValue(P_VAR_credentials); P_VAR_credentials = NULL;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    PrtFreeValue(PTMP_tmp1_6); PTMP_tmp1_6 = NULL;
    PrtFreeValue(PTMP_tmp2_5); PTMP_tmp2_5 = NULL;
    PrtFreeValue(PTMP_tmp3_5); PTMP_tmp3_5 = NULL;
    PrtFreeValue(PTMP_tmp4_5); PTMP_tmp4_5 = NULL;
    PrtFreeValue(PTMP_tmp5_5); PTMP_tmp5_5 = NULL;
    PrtFreeValue(PTMP_tmp6_4); PTMP_tmp6_4 = NULL;
    PrtFreeValue(PTMP_tmp7_4); PTMP_tmp7_4 = NULL;
    PrtFreeValue(PTMP_tmp8_4); PTMP_tmp8_4 = NULL;
    PrtFreeValue(PTMP_tmp9_3); PTMP_tmp9_3 = NULL;
    PrtFreeValue(PTMP_tmp10_2); PTMP_tmp10_2 = NULL;
    PrtFreeValue(PTMP_tmp11_2); PTMP_tmp11_2 = NULL;
    PrtFreeValue(PTMP_tmp12_2); PTMP_tmp12_2 = NULL;
    PrtFreeValue(PTMP_tmp13_2); PTMP_tmp13_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_16 =
{
    NULL,
    &P_Anon_IMPL_16,
    NULL
};


PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_10 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_7 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_94 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_94);
    *P_LVALUE_94 = PrtCloneValue(*P_VAR_payload_10);
    
    PrtPrintf("Client Web Browser: Enter Credentials to login to bank!\n");
    
    PRT_VALUE** P_LVALUE_95 = &(PTMP_tmp0_7);
    PrtFreeValue(*P_LVALUE_95);
    *P_LVALUE_95 = ((_P_GEN_funval = P_GetUserInput_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_17;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_17;
    }
    
    {
        PRT_VALUE** P_LVALUE_96 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_96);
        *P_LVALUE_96 = PTMP_tmp0_7;
        PTMP_tmp0_7 = NULL;
    }
    
    PrtGoto(p_this, 4U, 0);
    
p_return_17: ;
    PrtFreeValue(PTMP_tmp0_7); PTMP_tmp0_7 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_17 =
{
    NULL,
    &P_Anon_IMPL_17,
    &P_GEND_TYPE_machine_handle
};


PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_8 = NULL;
    PRT_VALUE* PTMP_tmp1_7 = NULL;
    PRT_VALUE* PTMP_tmp2_6 = NULL;
    PRT_VALUE* PTMP_tmp3_6 = NULL;
    PRT_VALUE* P_VAR_P_payload = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_97 = &(PTMP_tmp0_8);
    PrtFreeValue(*P_LVALUE_97);
    *P_LVALUE_97 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_98 = &(PTMP_tmp1_7);
    PrtFreeValue(*P_LVALUE_98);
    *P_LVALUE_98 = PrtCloneValue((&P_EVENT_GenerateOTPCodeEvent.value));
    
    PRT_VALUE** P_LVALUE_99 = &(PTMP_tmp2_6);
    PrtFreeValue(*P_LVALUE_99);
    *P_LVALUE_99 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE* P_PTMP_tmp_13 = PrtCloneValue(&(P_LIT_INT32_6));
    _P_GEN_funargs[0] = &(PTMP_tmp0_8);
    _P_GEN_funargs[1] = &(PTMP_tmp1_7);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_13);
    _P_GEN_funargs[3] = &(PTMP_tmp2_6);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_18;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_18;
    }
    
    PRT_UINT32 P_allowedEventIds[] = { 2 };
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    PRT_UINT32 P_eventId = PrtReceiveAsync(1U, P_allowedEventIds, &P_VAR_P_payload);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_18;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_18;
    }
    switch (P_eventId) {
        case 2: {
            PRT_VALUE** P_VAR_payload_11 = &P_VAR_P_payload;
                        PRT_VALUE** P_LVALUE_100 = &(PTMP_tmp3_6);
            PrtFreeValue(*P_LVALUE_100);
            *P_LVALUE_100 = PrtCloneValue(*P_VAR_payload_11);
            
            PrtGoto(p_this, 5U, 1, &(PTMP_tmp3_6));
            
            p_return_19: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    
p_return_18: ;
    PrtFreeValue(PTMP_tmp0_8); PTMP_tmp0_8 = NULL;
    PrtFreeValue(PTMP_tmp1_7); PTMP_tmp1_7 = NULL;
    PrtFreeValue(PTMP_tmp2_6); PTMP_tmp2_6 = NULL;
    PrtFreeValue(PTMP_tmp3_6); PTMP_tmp3_6 = NULL;
    PrtFreeValue(P_VAR_P_payload); P_VAR_P_payload = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_18 =
{
    NULL,
    &P_Anon_IMPL_18,
    NULL
};


PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_12 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("OTP Code Received:\n");
    
    PRT_VALUE** P_LVALUE_101 = &(PTMP_tmp0_9);
    PrtFreeValue(*P_LVALUE_101);
    *P_LVALUE_101 = PrtCloneValue(*P_VAR_payload_12);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_9);
    PrtFreeValue(P_PrintString_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_9);
    PTMP_tmp0_9 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_20;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_20;
    }
    
    PRT_VALUE** P_LVALUE_102 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_102);
    *P_LVALUE_102 = PrtCloneValue(*P_VAR_payload_12);
    
    PrtGoto(p_this, 6U, 0);
    
p_return_20: ;
    PrtFreeValue(PTMP_tmp0_9); PTMP_tmp0_9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_19 =
{
    NULL,
    &P_Anon_IMPL_19,
    &P_GEND_TYPE_StringType
};


PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_10 = NULL;
    PRT_VALUE* PTMP_tmp1_8 = NULL;
    PRT_VALUE* PTMP_tmp2_7 = NULL;
    PRT_VALUE* PTMP_tmp3_7 = NULL;
    PRT_VALUE* PTMP_tmp4_6 = NULL;
    PRT_VALUE* PTMP_tmp5_6 = NULL;
    PRT_VALUE* P_VAR_P_payload_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_7 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_103 = &(PTMP_tmp0_10);
    PrtFreeValue(*P_LVALUE_103);
    *P_LVALUE_103 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_104 = &(PTMP_tmp1_8);
    PrtFreeValue(*P_LVALUE_104);
    *P_LVALUE_104 = PrtCloneValue((&P_EVENT_AuthenticateRequest.value));
    
    PRT_VALUE** P_LVALUE_105 = &(PTMP_tmp2_7);
    PrtFreeValue(*P_LVALUE_105);
    *P_LVALUE_105 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_106 = &(PTMP_tmp3_7);
    PrtFreeValue(*P_LVALUE_106);
    *P_LVALUE_106 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_107 = &(PTMP_tmp4_6);
    PrtFreeValue(*P_LVALUE_107);
    *P_LVALUE_107 = (PrtMkTuple(&P_GEND_TYPE_T2StringTypeStringType, &(PTMP_tmp2_7), &(PTMP_tmp3_7)));
    
    PRT_VALUE* P_PTMP_tmp_14 = PrtCloneValue(&(P_LIT_INT32_7));
    _P_GEN_funargs[0] = &(PTMP_tmp0_10);
    _P_GEN_funargs[1] = &(PTMP_tmp1_8);
    _P_GEN_funargs[2] = &(P_PTMP_tmp_14);
    _P_GEN_funargs[3] = &(PTMP_tmp4_6);
    PrtFreeValue(P_UntrustedSend_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_21;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_21;
    }
    
    PRT_UINT32 P_allowedEventIds_1[] = { 3, 4 };
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    PRT_UINT32 P_eventId_1 = PrtReceiveAsync(2U, P_allowedEventIds_1, &P_VAR_P_payload_1);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_21;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_21;
    }
    switch (P_eventId_1) {
        case 3: {
                        PrtGoto(p_this, 7U, 0);
            
            p_return_22: ;
} break;
        case 4: {
                        PrtPrintf("Authentication Failed!");
            
            PrtPrintf("Client Web Browser: Reenter Credentials to login!");
            
            PRT_VALUE** P_LVALUE_108 = &(PTMP_tmp5_6);
            PrtFreeValue(*P_LVALUE_108);
            *P_LVALUE_108 = ((_P_GEN_funval = P_GetUserInput_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_21;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_21;
            }
            
            {
                PRT_VALUE** P_LVALUE_109 = &(p_this->varValues[2]);
                PrtFreeValue(*P_LVALUE_109);
                *P_LVALUE_109 = PTMP_tmp5_6;
                PTMP_tmp5_6 = NULL;
            }
            
            PrtGoto(p_this, 4U, 0);
            
            p_return_23: ;
} break;
        default: {
            PrtAssert(PRT_FALSE, "receive returned unhandled event");
        } break;
    }
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    
p_return_21: ;
    PrtFreeValue(PTMP_tmp0_10); PTMP_tmp0_10 = NULL;
    PrtFreeValue(PTMP_tmp1_8); PTMP_tmp1_8 = NULL;
    PrtFreeValue(PTMP_tmp2_7); PTMP_tmp2_7 = NULL;
    PrtFreeValue(PTMP_tmp3_7); PTMP_tmp3_7 = NULL;
    PrtFreeValue(PTMP_tmp4_6); PTMP_tmp4_6 = NULL;
    PrtFreeValue(PTMP_tmp5_6); PTMP_tmp5_6 = NULL;
    PrtFreeValue(P_VAR_P_payload_1); P_VAR_P_payload_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_20 =
{
    NULL,
    &P_Anon_IMPL_20,
    NULL
};


PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtPrintf("Client Web Browser Authenticated Successfully!");
    
p_return_24: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_21 =
{
    NULL,
    &P_Anon_IMPL_21,
    NULL
};


PRT_FUNDECL* P_ClientWebBrowser_METHODS[] = { &P_FUNCTION_Anon_15, &P_FUNCTION_Anon_16, &P_FUNCTION_Anon_17, &P_FUNCTION_Anon_18, &P_FUNCTION_Anon_19, &P_FUNCTION_Anon_20, &P_FUNCTION_Anon_21 };

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
    5U,
    "ClientWebBrowser",
    &P_EVENTSET_ClientWebBrowser_RECV_1,
    &P_EVENTSET_ClientWebBrowser_SEND,
    NULL,
    4U,
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
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_OTPCodeEvent, &P_EVENT_AuthSuccess, &P_EVENT_AuthFailure, &P_EVENT_TRUSTEDMeasureEvent1, &P_EVENT_TRUSTEDMeasureEvent2, &P_EVENT_MeasureEvent1, &P_EVENT_MeasureEvent2, &P_EVENT_BankPublicIDEvent, &P_EVENT_PublicIDEvent, &P_EVENT_UNTRUSTEDReceiveRegistrationCredentials, &P_EVENT_MasterSecretEvent, &P_EVENT_GenerateOTPCodeEvent, &P_EVENT_MapEvent, &P_EVENT_AuthenticateRequest, &P_EVENT_TRUSTEDProvisionBankSSM, &P_EVENT_TRUSTEDProvisionClientSSM };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_UntrustedInitializer, &P_MACHINE_MeasureMachine, &P_MACHINE_TrustedInitializer, &P_MACHINE_BankEnclave, &P_MACHINE_ClientEnclave, &P_MACHINE_ClientWebBrowser };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_UntrustedInitializer, &P_I_MeasureMachine, &P_I_TrustedInitializer, &P_I_BankEnclave, &P_I_ClientEnclave, &P_I_ClientWebBrowser };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { &P_StringType, &P_machine_handle, &P_secure_StringType, &P_secure_machine_handle, &P_capability };
int P_DefaultImpl_LME_0[] = { -1,1,2,-1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1,3,-1,5 };
int P_DefaultImpl_LME_3[] = { -1,-1,-1,-1,4,-1 };
int P_DefaultImpl_LME_4[] = { -1,-1,-1,-1,-1,-1 };
int P_DefaultImpl_LME_5[] = { -1,-1,-1,-1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3, P_DefaultImpl_LME_4, P_DefaultImpl_LME_5 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3,4,5 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    18U,
    6U,
    6U,
    0U,
    5U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};

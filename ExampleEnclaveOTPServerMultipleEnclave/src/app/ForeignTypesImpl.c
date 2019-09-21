#include "OTPServer.h"
#include "enclave_u.h"
#include "sgx_urts.h"
#include "sgx_utils/sgx_utils.h"


// PRT_VALUE* P_Print_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
// {
// 	printf("KKKKKK\n");
//     //ocall_print("kirat2");
//     //You can make enclave call here
// 	PRT_INT64 temp = (PRT_INT64) PrtMalloc(sizeof(PRT_UINT32));
// 	temp = 64;
// 	return (PRT_VALUE*) &temp;
// 	//return PrtMkDefaultValue(P_TYPEDEF_StringType);
// }
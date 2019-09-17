#include "PingPong.h"

PRT_VALUE* P_Print_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
	//printf("KKKKKK\n");
    ocall_print("kirat");
	PRT_INT64 temp = PrtMalloc(sizeof(PRT_UINT32));
	temp = 64;
	return &temp;
	//return PrtMkDefaultValue(P_TYPEDEF_StringType);
}
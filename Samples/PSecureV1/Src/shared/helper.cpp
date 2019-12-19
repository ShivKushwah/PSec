#include "PingPongEnclave.h"
#include "string.h"
#include <string>
#include "constants.h"
#include <tuple>
#include <unordered_map> 



#ifdef ENCLAVE_STD_ALT
#include "enclave_t.h"
#endif

#ifndef ENCLAVE_STD_ALT
#include "enclave_u.h"
#endif

using namespace std;

extern PRT_PROCESS *process;
extern PRT_PROGRAMDECL* program;

//NOTE all typedefs are also defined in enclave.cpp and app.cpp
typedef tuple <string,string> identityKeyPair; //public, private
extern unordered_map<int, identityKeyPair> MachinePIDToIdentityDictionary;


int atoi(char *p) {
    int k = 0;
    while (*p) {
        k = (k << 3) + (k << 1) + (*p) - '0';
        p++;
     }
     return k;
}

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        char temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        //swap(*(str+start), *(str+end)); 
        start++; 
        end--; 
    } 
} 

// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 

char* serializePrtValueToString(PRT_VALUE* value) {
    //TODO code the rest of the types
    //TODO if modifying this, also modify in app.cpp
    if (value->discriminator == PRT_VALUE_KIND_INT) {
        char* integer = (char*) malloc(10);
        itoa(value->valueUnion.nt, integer, 10);
        return integer;
    } else if (value->discriminator == PRT_VALUE_KIND_FOREIGN) {
        if (value->valueUnion.frgn->typeTag == 0) { //if StringType
            return (char*) value->valueUnion.frgn->value;
        } else {
            return "UNSUPPORTED_TYPE";
        }
    } else {
        return "UNSUPPORTED_TYPE";
    }

}

PRT_VALUE** deserializeStringToPrtValue(int numArgs, char* str, int payloadType) {
        //TODO if there are changes in here make changes in enclave.cpp

    //TODO code the rest of the types (only int is coded for now)
    PRT_VALUE** values = (PRT_VALUE**) PrtCalloc(numArgs, sizeof(PRT_VALUE*));
    for (int i = 0; i < numArgs; i++) {
        char* split = strtok(str, ":");
        values[i] = (PRT_VALUE*)PrtMalloc(sizeof(PRT_VALUE));
        values[i]->discriminator = (PRT_VALUE_KIND) payloadType;
        if (payloadType == PRT_VALUE_KIND_INT) {
            values[i]->valueUnion.nt = atoi(split);
        } else if (payloadType == PRT_VALUE_KIND_FOREIGN) {
            values[i]->valueUnion.frgn = (PRT_FOREIGNVALUE*) PrtMalloc(sizeof(PRT_FOREIGNVALUE));
            values[i]->valueUnion.frgn->typeTag = 0; //TODO hardcoded for StringType
            PRT_STRING prtStr = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	        sprintf_s(prtStr, 100, str);
            values[i]->valueUnion.frgn->value = (PRT_UINT64) prtStr; //TODO do we need to memcpy?
        }
    }
    return values;
}

char* generateCStringFromFormat(char* format_string, char* strings_to_print[], int num_strings) {
        //NOTE make changes in app.cpp as well

    if (num_strings > 5) {
        ocall_print("Too many strings passed to generateCStringFromFormat!");
        return "ERROR!";
    }
    char* returnString = (char*) malloc(100);

    char* str1 = strings_to_print[0];
    char* str2 = strings_to_print[1];
    char* str3 = strings_to_print[2];
    char* str4 = strings_to_print[3];
    char* str5 = strings_to_print[4];

    snprintf(returnString, 100, format_string, str1, str2, str3, str4, str5);
    //ocall_print("Return string is");
    //ocall_print(returnString);
    return returnString;

}

int getNextPID() {
    return ((PRT_PROCESS_PRIV*)process)->numMachines + 1;
}

int handle_incoming_event(PRT_UINT32 eventIdentifier, PRT_MACHINEID receivingMachinePID, int numArgs, int payloadType, char* payload) {
    PRT_VALUE* event = PrtMkEventValue(eventIdentifier);
    PRT_MACHINEINST* machine = PrtGetMachine(process, PrtMkMachineValue(receivingMachinePID));
    if (numArgs == 0) {
        PrtSend(NULL, machine, event, 0);
    } else {
        PRT_VALUE** prtPayload =  deserializeStringToPrtValue(numArgs, payload, payloadType);
        PrtSend(NULL, machine, event, numArgs, prtPayload);
    }
    return 0;
}

int createMachine(char* machineType, int numArgs, int payloadType, char* payload) {
    PRT_VALUE* prtPayload;
    if (numArgs > 0) {
        ocall_print("Serialized the following payload");
        ocall_print(payload);
        prtPayload = *(deserializeStringToPrtValue(numArgs, payload, payloadType));
    } else {
        prtPayload = PrtMkNullValue();
    }
    PRT_UINT32 newMachinePID;
	PRT_BOOLEAN foundMachine = PrtLookupMachineByName(machineType, &newMachinePID);
    // ocall_print_int(newMachinePID);
	PrtAssert(foundMachine, "No machine found!");
	PRT_MACHINEINST* pongMachine = PrtMkMachine(process, newMachinePID, 1, &prtPayload);
    return pongMachine->id->valueUnion.mid->machineId;
}

int machineTypeIsSecure(char* machineType) {
    //TODO there is a bug with this function because it thought that BankEnclave is USM
    PRT_UINT32 interfaceName;  
	PrtLookupMachineByName(machineType, &interfaceName);
    PRT_UINT32 instanceOf = program->interfaceDefMap[interfaceName];
    PRT_MACHINEDECL* curMachineDecl = program->machines[instanceOf];
    return curMachineDecl->isSecure;
}


string createString(char* str) {
    char* strCopy = (char*) malloc(strlen(str) + 1);
    memcpy(strCopy, str, strlen(str) + 1);
    return string(strCopy);
}

extern "C" PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    char* currentMachineIDPublicKey;
 
    currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str()); 
    //Return the currentMachineIDPublicKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, currentMachineIDPublicKey);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}

//String Class

extern "C" void P_FREE_StringType_IMPL(PRT_UINT64 frgnVal)
{
	PrtFree((PRT_STRING)frgnVal);
}

extern "C" PRT_BOOLEAN P_ISEQUAL_StringType_IMPL(PRT_UINT64 frgnVal1, PRT_UINT64 frgnVal2)
{
	return strcmp((PRT_STRING)frgnVal1, (PRT_STRING)frgnVal2) == 0 ? PRT_TRUE : PRT_FALSE;
}

extern "C" PRT_STRING P_TOSTRING_StringType_IMPL(PRT_UINT64 frgnVal)
{
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, "String : %lld", frgnVal);
	return str;
}

extern "C" PRT_UINT32 P_GETHASHCODE_StringType_IMPL(PRT_UINT64 frgnVal)
{
	return (PRT_UINT32)frgnVal;
}

extern "C" PRT_UINT64 P_MKDEF_StringType_IMPL(void)
{
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, "xyx$12");
	return (PRT_UINT64)str;
}

extern "C" PRT_UINT64 P_CLONE_StringType_IMPL(PRT_UINT64 frgnVal)
{
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
	sprintf_s(str, 100, (PRT_STRING)frgnVal);
	return (PRT_UINT64)str;
}

extern "C" void P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_UINT64 val = (*P_VAR_payload)->valueUnion.frgn->value;
    ocall_print("String P value is:");
    ocall_print((char*) val);
    
}
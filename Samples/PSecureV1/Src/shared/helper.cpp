#include "PingPongEnclave.h"

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


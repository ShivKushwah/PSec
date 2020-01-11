#include "PingPongEnclave.h"
#include "string.h"
#include <string>
#include "constants.h"
#include <tuple>
#include <unordered_map> 
#include <unordered_set> 
#include <map> 

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
typedef tuple <uint32_t,string> PMachineChildPair; //parentMachineID, childPublicKey
extern map<PMachineChildPair, string> PMachineToChildCapabilityKey;
extern unordered_map<string, sgx_enclave_id_t> PublicIdentityKeyToEidDictionary;
extern unordered_map<string, int> USMPublicIdentityKeyToMachinePIDDictionary;

extern unordered_set<string> USMAuthorizedTypes;

extern int CURRENT_ENCLAVE_EID_NUM;

extern int initialize_enclave(sgx_enclave_id_t* eid, const std::string& launch_token_path, const std::string& enclave_name);

extern char* createUSMMachineAPI(char* machineType, int numArgs, int payloadType, char* payload, int payloadSize);
extern char* USMsendMessageAPI(char* receivingMachineIDKey, char* eventNum, int numArgs, int payloadType, char* payload, int payloadSize);
extern char* USMinitializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey);


extern char* untrusted_enclave1_receiveNetworkRequest(char* request, size_t requestSize);


extern char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey);
extern char* send_network_request_API(char* request);

void safe_free(void* ptr) {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
    }
}

//Responsiblity of caller to free return
char* createStringLiteralMalloced(char* stringLiteral) {
    //TODO if modifying here, modify in network_ra.cpp
    char* malloced = (char*) malloc(strlen(stringLiteral));
    strncpy(malloced, stringLiteral, strlen(stringLiteral) + 1);
    return malloced;

}

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

//Responsibility of caller to free result
char* concat(char* str1, char* str2) {
    char* retString = (char*) malloc(strlen(str1) + strlen(str2) + 2);
    strncpy(retString, str1, strlen(str1) + 1);
    strncat(retString, str2, strlen(str2) + 1);
    retString[strlen(str1) + strlen(str2)] = '\0';
    return retString;
}

PRT_TYPE_KIND convertKindToType(int kind) {
    if (kind == PRT_VALUE_KIND_INT) {
        return PRT_KIND_INT;
    } else if (kind == PRT_VALUE_KIND_FOREIGN) {
        return PRT_KIND_FOREIGN;
    } else if (kind == PRT_VALUE_KIND_BOOL) {
        return PRT_KIND_BOOL;
    } else {
        return PRT_TYPE_KIND_CANARY; //unsupported type
    }
}

//Responsibility of Caller to free return
char* serializePrtValueToString(PRT_VALUE* value, int& final_size) {
    //TODO code the rest of the types
    if (value->discriminator == PRT_VALUE_KIND_INT) {
        char* integer = (char*) malloc(10);
        itoa(value->valueUnion.nt, integer, 10);
        final_size += strlen(integer);
        return integer;
    } else if (value->discriminator == PRT_VALUE_KIND_FOREIGN) {
        if (value->valueUnion.frgn->typeTag == 0) { //if StringType
            char* string = (char*) malloc(SIZE_OF_PRT_STRING_SERIALIZED);
            memcpy(string, (char*) value->valueUnion.frgn->value, SIZE_OF_PRT_STRING_SERIALIZED);
            ocall_print("the actual PRT value is");
            ocall_print((char*)value->valueUnion.frgn->value);
            //string[SIZE_OF_PRT_STRING_SERIALIZED] = '\0';
            final_size += SIZE_OF_PRT_STRING_SERIALIZED;
            return string;
        } else {
            return createStringLiteralMalloced("UNSUPPORTED_TYPE");
        }
    } else if (value->discriminator == PRT_VALUE_KIND_BOOL) {
        if (value->valueUnion.bl == PRT_TRUE) {
            final_size += 4;
            return createStringLiteralMalloced("true");
        } else if (value->valueUnion.bl == PRT_FALSE) {
            final_size += 5;
            return createStringLiteralMalloced("false");
        } else {
            final_size += 24;
            return createStringLiteralMalloced("ERROR: Boolean not found");
        }
    } else if (value->discriminator == PRT_VALUE_KIND_TUPLE) {
        char* tupleString = (char*) malloc(SIZE_OF_MAX_SERIALIZED_TUPLE);
        int currIndex = 0;
        PRT_TUPVALUE* tupPtr = value->valueUnion.tuple;
        for (int i = 0; i < tupPtr->size; i++) {
            PRT_VALUE* currValue = tupPtr->values[i];
            int currValueType = tupPtr->values[i]->discriminator;
            char* typeString = (char*) malloc(10);
            itoa(currValueType, typeString, 10);
            memcpy(tupleString + currIndex, typeString, strlen(typeString) + 1);
            currIndex += strlen(typeString);
            safe_free(typeString);
            tupleString[currIndex] = ':';
            currIndex++;
            int szSerializedStr = 0;
            char* serializedStr = serializePrtValueToString(currValue, szSerializedStr);
            memcpy(tupleString + currIndex, serializedStr, szSerializedStr + 1);
            currIndex += szSerializedStr;
            safe_free(serializedStr);
            if (i < tupPtr->size - 1) {
                tupleString[currIndex] = ':';
                currIndex++;
            }
        }
        // strncat(tupleString, ":END_TUP", 10);
        memcpy(tupleString + currIndex, ":END_TUP", 8);
        currIndex += 8;
        tupleString[currIndex] = '\0';
        final_size = currIndex;
        return tupleString;
    } else if (value->discriminator == PRT_VALUE_KIND_MAP) {
        char* mapString = (char*) malloc(SIZE_OF_MAX_SERIALIZED_MAP);
        int currIndex = 0;

        PRT_VALUE* mapValues = PrtMapGetValues(value);
        PRT_VALUE* mapKeys = PrtMapGetKeys(value);
        int size = mapValues->valueUnion.seq->size;

        for (int i = 0; i < size; i++) {
            PRT_VALUE* mapKey = mapKeys->valueUnion.seq->values[i];
            int currValueType = mapKey->discriminator;
            char* typeString = (char*) malloc(10);
            itoa(currValueType, typeString, 10);
            memcpy(mapString + currIndex, typeString, strlen(typeString) + 1);
            currIndex += strlen(typeString);
            safe_free(typeString);
            mapString[currIndex] = ':';
            currIndex++;
            int serializedKeySz = 0;
            char* serializedKey = serializePrtValueToString(mapKey, serializedKeySz);
            memcpy(mapString + currIndex, serializedKey, serializedKeySz + 1);
            currIndex += serializedKeySz;
            safe_free(serializedKey);
            mapString[currIndex] = ':';
            currIndex++;
            PRT_VALUE* mapValue = mapValues->valueUnion.seq->values[i];
            currValueType = mapValue->discriminator;
            typeString = (char*) malloc(10);
            itoa(currValueType, typeString, 10);
            memcpy(mapString + currIndex, typeString, strlen(typeString) + 1);
            currIndex += strlen(typeString);
            safe_free(typeString);
            mapString[currIndex] = ':';
            currIndex++;
            int serializedValueSz = 0;
            char* serializedValue = serializePrtValueToString(mapValue, serializedValueSz);
            memcpy(mapString + currIndex, serializedValue, serializedValueSz + 1);
            currIndex += serializedValueSz;
            safe_free(serializedValue);
            if (i < size - 1) {
                mapString[currIndex] = ':';
                currIndex++;
            }
        }
        // strncat(mapString, ":END_MAP", 10);
        memcpy(mapString + currIndex, ":END_MAP", 8);
        currIndex += 8;
        mapString[currIndex] = '\0';
        final_size = currIndex;
        return mapString;
    } else if (value->discriminator == PRT_VALUE_KIND_SEQ) {
        char* seqString = (char*) malloc(SIZE_OF_MAX_SERIALIZED_SEQ);
        int currIndex = 0;

        int size = PrtSeqSizeOf(value);

        for (int i = 0; i < size; i++) {

            PRT_VALUE* seqValue = PrtSeqGet(value, PrtMkIntValue(currIndex));
            int currValueType = seqValue->discriminator;
            char* typeString = (char*) malloc(10);
            itoa(currValueType, typeString, 10);
            memcpy(seqString + currIndex, typeString, strlen(typeString) + 1);
            currIndex += strlen(typeString);
            safe_free(typeString);
            seqString[currIndex] = ':';
            currIndex++;
            int serializedValueSz = 0;
            char* serializedValue = serializePrtValueToString(seqValue, serializedValueSz);
            memcpy(seqString + currIndex, serializedValue, serializedValueSz + 1);
            currIndex += serializedValueSz;
            safe_free(serializedValue);
            if (i < size - 1) {
                seqString[currIndex] = ':';
                currIndex++;
            }
        }
        // strncat(seqString, ":END_SEQ", 10);
        ocall_print("sequence so far");
        ocall_print(seqString);
        ocall_print("checking location of currIndex");
        ocall_print_int(currIndex);
        memcpy(seqString + currIndex, ":END_SEQ", 9);
        ocall_print("new seq");
        ocall_print(seqString);
        currIndex += 8;
        seqString[currIndex] = '\0';
        final_size = currIndex;
        return seqString;
    }
    
    
     else {
        return createStringLiteralMalloced("UNSUPPORTED_TYPE");
    }

}

PRT_VALUE* deserializeHelper(char* payloadOriginal, int* numCharactersProcessed) { //assumes only 1 non-recursive element
    char* payload = (char*) malloc(strlen(payloadOriginal) + 1);
    strncpy(payload, payloadOriginal, strlen(payloadOriginal) + 1);
    char* reentrant = NULL; 
    char* payloadTypeString = strtok_r(payload, ":", &reentrant);
    int payloadType = atoi(payloadTypeString);
    char* str = strtok_r(NULL, ":", &reentrant);
    *numCharactersProcessed = strlen(payloadTypeString) + 1 + strlen(str);
    PRT_VALUE* newPrtValue = (PRT_VALUE*)PrtMalloc(sizeof(PRT_VALUE));
    newPrtValue->discriminator = (PRT_VALUE_KIND) payloadType;
    if (payloadType == PRT_VALUE_KIND_INT) {
        ocall_print("Make Prt Int with Value:");
        ocall_print(str);
        newPrtValue->valueUnion.nt = atoi(str);
    } else if (payloadType == PRT_VALUE_KIND_FOREIGN) {
        ocall_print("Make Prt String with Value:");
        ocall_print(str);
        newPrtValue->valueUnion.frgn = (PRT_FOREIGNVALUE*) PrtMalloc(sizeof(PRT_FOREIGNVALUE));
        newPrtValue->valueUnion.frgn->typeTag = 0; //TODO hardcoded for StringType
        PRT_STRING prtStr = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * (SIZE_OF_PRT_STRING_SERIALIZED));
        // sprintf_s(prtStr, SIZE_OF_PRT_STRING_SERIALIZED, str);
        memcpy(prtStr, str, SIZE_OF_PRT_STRING_SERIALIZED);
        newPrtValue->valueUnion.frgn->value = (PRT_UINT64) prtStr; //TODO do we need to memcpy?
    } else if (payloadType == PRT_VALUE_KIND_BOOL) {
        if (strcmp(str, "true") == 0) {
            newPrtValue->valueUnion.bl = PRT_TRUE;
        } else if (strcmp(str, "false") == 0){
            newPrtValue->valueUnion.bl = PRT_FALSE;
        } 
    } 
    safe_free(payload);
    return newPrtValue;

}

PRT_VALUE** deserializeStringToPrtValue(int numArgs, char* strOriginal, int* numCharactersProcessed) {
    //TODO code the rest of the types (only int is coded for now)
    // ocall_print("Deserialized called!");
    // ocall_print(strOriginal);
    *numCharactersProcessed = 0;
    char* str = (char*) malloc(strlen(strOriginal) + 1);
    strncpy(str, strOriginal, strlen(strOriginal) + 1);
    char* strCopy = (char*) malloc(strlen(strOriginal) + 1);
    strncpy(strCopy, strOriginal, strlen(strOriginal) + 1);

    PRT_VALUE** values = (PRT_VALUE**) PrtCalloc(numArgs, sizeof(PRT_VALUE*));
    char* reentrant = NULL;
    char* temp = str;
    char* split = strtok_r(str, ":", &reentrant);
    *numCharactersProcessed = *numCharactersProcessed + strlen(split) + 1; //+ 1 for ":"
    int payloadType = atoi(split);
    for (int i = 0; i < numArgs; i++) {
        
        if (payloadType == PRT_VALUE_KIND_INT || payloadType == PRT_VALUE_KIND_FOREIGN || payloadType == PRT_VALUE_KIND_BOOL) {
            ocall_print("Processing Native Type String:");
            ocall_print(strOriginal);
            int numProcessedInHelper;
            values[i] = deserializeHelper(strOriginal, &numProcessedInHelper);
            *numCharactersProcessed = numProcessedInHelper;
        }
        else if (payloadType == PRT_VALUE_KIND_TUPLE) {
            ocall_print("Deserializing Tuple:");
            values[i] = (PRT_VALUE*) PrtMalloc(sizeof(PRT_VALUE));
            PRT_TUPVALUE* tupPtr = (PRT_TUPVALUE*) PrtMalloc(sizeof(PRT_TUPVALUE));
            values[i]->discriminator = PRT_VALUE_KIND_TUPLE;
            values[i]->valueUnion.tuple = tupPtr;            
            tupPtr->size = 0;
            char* nextTupleElementToProcess = strCopy + strlen(split) + 1; // + 1 for ":"
            char* nextTupleElementToProcessOriginal = nextTupleElementToProcess;
            tupPtr->values = (PRT_VALUE **)PrtCalloc(MAX_TUPLE_ELEMENT_LENGTH, sizeof(PRT_VALUE*));
            while (strncmp(nextTupleElementToProcess, "END_TUP", 7) != 0) {
                //char* payload = strtok_r(NULL, ":", &reentrant); //TODO make this safe?
                ocall_print("Processing Element String:");
                ocall_print(nextTupleElementToProcess);
                int i = tupPtr->size;
                tupPtr->size++;
                int numProcessedInHelper;
                tupPtr->values[i] = *deserializeStringToPrtValue(1, nextTupleElementToProcess, &numProcessedInHelper);// deserializeStringToPrtValue(1, );
                ocall_print("Element Processed.");
                ocall_print("Number of characters in helper is ");
                ocall_print_int(numProcessedInHelper);
                // *numCharactersProcessed =  *numCharactersProcessed + numProcessedInHelper + 1; //+1 for ":"
                nextTupleElementToProcess = nextTupleElementToProcess + numProcessedInHelper + 1;
            }
            *numCharactersProcessed =  *numCharactersProcessed + (nextTupleElementToProcess - nextTupleElementToProcessOriginal) + 7; //+7 for "END_TUP"

        } else if (payloadType == PRT_VALUE_KIND_MAP) {

            char* nextMapKeyValuePairToProcess = strCopy + strlen(split) + 1; // + 1 for ":"
            char* nextMapKeyValuePairToProcessOriginal = nextMapKeyValuePairToProcess;

           
            // PrtMkDefaultValue()
            // values[i]->discriminator = PRT_VALUE_KIND_MAP;
            // values[i]->valueUnion.map = map;

            // map->size = 0;
            // map->capNum = 0;
            // map->buckets = (PRT_MAPNODE **)PrtCalloc(PrtHashtableCapacities[0], sizeof(PRT_MAPNODE *));
            // map->first = NULL;
            // map->last = NULL;

            while (strncmp(nextMapKeyValuePairToProcess, "END_MAP", 7) != 0) {
                int numProcessedInHelper;
                PRT_VALUE* key = *deserializeStringToPrtValue(1, nextMapKeyValuePairToProcess, &numProcessedInHelper);
                char* dataType = (char*) malloc(strlen(nextMapKeyValuePairToProcess) + 1);
                strncpy(dataType, nextMapKeyValuePairToProcess, strlen(nextMapKeyValuePairToProcess) + 1);
                char* reentrant = NULL;
                strtok_r(dataType, ":", &reentrant);
                int dType = atoi(dataType);
                safe_free(dataType);
                nextMapKeyValuePairToProcess = nextMapKeyValuePairToProcess + numProcessedInHelper + 1;

                PRT_VALUE* value = *deserializeStringToPrtValue(1, nextMapKeyValuePairToProcess, &numProcessedInHelper);
                char* dataType2 = (char*) malloc(strlen(nextMapKeyValuePairToProcess) + 1);
                strncpy(dataType2, nextMapKeyValuePairToProcess, strlen(nextMapKeyValuePairToProcess) + 1);
                char* reentrant2 = NULL;
                strtok_r(dataType2, ":", &reentrant2);
                int dType2 = atoi(dataType2);
                safe_free(dataType2);
                nextMapKeyValuePairToProcess = nextMapKeyValuePairToProcess + numProcessedInHelper + 1;

                if (values[i] == NULL) {

                    PRT_TYPE* mapType = PrtMkMapType(PrtMkPrimitiveType(convertKindToType(dType)), PrtMkPrimitiveType(convertKindToType(dType2)));
                    // PRT_TYPE* mapType = (PRT_TYPE*) PrtMalloc(sizeof(PRT_TYPE));
                    // mapType->typeKind = PRT_KIND_MAP;
                    // mapType->typeUnion.map = 
                    values[i] = PrtMkDefaultValue(mapType);

                }

                PrtMapUpdate(values[i], key, value);
            }

            ocall_print("Map created");
            *numCharactersProcessed =  *numCharactersProcessed + (nextMapKeyValuePairToProcess - nextMapKeyValuePairToProcessOriginal) + 7; //+7 for "END_MAP"


        } else if (payloadType == PRT_VALUE_KIND_SEQ) {

            char* nextSeqElementToProcess = strCopy + strlen(split) + 1; // + 1 for ":"
            char* nextSeqElementToProcessOriginal = nextSeqElementToProcess;

            int index = 0;
            while (strncmp(nextSeqElementToProcess, "END_SEQ", 7) != 0) {
                // char* payload = strtok_r(NULL, ":", &reentrant); //TODO make this safe?
                // int dType = atoi(dataType);
                int numProcessedInHelper;
                PRT_VALUE* value = *deserializeStringToPrtValue(1, nextSeqElementToProcess, &numProcessedInHelper);
                //*numCharactersProcessed =  *numCharactersProcessed + numProcessedInHelper + 1; //+1 for ":"

                char* dataType = (char*) malloc(strlen(nextSeqElementToProcess) + 1);
                strncpy(dataType, nextSeqElementToProcess, strlen(nextSeqElementToProcess) + 1);
                char* reentrant = NULL;
                strtok_r(dataType, ":", &reentrant);
                int dType = atoi(dataType);
                safe_free(dataType);

                if (values[i] == NULL) {

                    PRT_TYPE* seqType = PrtMkSeqType(PrtMkPrimitiveType(convertKindToType(dType)));
                    values[i] = PrtMkDefaultValue(seqType);

                }

                PrtSeqInsert(values[i], PrtMkIntValue(index), value);
                nextSeqElementToProcess = nextSeqElementToProcess + numProcessedInHelper + 1;
                
            }
            ocall_print("Seq created");
            *numCharactersProcessed =  *numCharactersProcessed + (nextSeqElementToProcess - nextSeqElementToProcessOriginal) + 7; //+7 for "END_SEQ"

        }
    }
    safe_free(str);
    safe_free(strCopy);
    return values;
}
//Responsbility of caller to free return
char* generateCStringFromFormat(char* format_string, char* strings_to_print[], int num_strings) {
        //NOTE make changes in app.cpp as well

    if (num_strings > 5) {
        ocall_print("Too many strings passed to generateCStringFromFormat!");
        return "ERROR!";
    }
    char* returnString = (char*) malloc(1600);

    char* str1 = strings_to_print[0];
    char* str2 = strings_to_print[1];
    char* str3 = strings_to_print[2];
    char* str4 = strings_to_print[3];
    char* str5 = strings_to_print[4];

    snprintf(returnString, 1600, format_string, str1, str2, str3, str4, str5);
    //ocall_print("Return string is");
    //ocall_print(returnString);
    return returnString;

}

int returnTotalSizeofLengthArray(int lengths[], int length){
    int total_size = 0;
    for (int i = 0; i < length; i++) {
        total_size += lengths[i];
    }
    return total_size;
}

void printRSAKey(char* key) {
    //NOTE if modifying this method, modify it in kps.cpp also
    char* keyCopy = (char*) malloc(SGX_RSA3072_KEY_SIZE);
    memcpy(keyCopy, key, SGX_RSA3072_KEY_SIZE);
    ocall_print("key:");
    char* temp = keyCopy;
    for (int i = 0; i < SGX_RSA3072_KEY_SIZE; i++) {
        if (temp[i] == '\0') {
            temp[i] = 'D';
        }
    }
    keyCopy[SGX_RSA3072_KEY_SIZE - 1] = '\0';
    
    ocall_print(keyCopy);
    safe_free(keyCopy);
}

//Responsbility of caller to free return
char* concatMutipleStringsWithLength(char* strings_to_concat[], int lengths[], int size_array) {
        //NOTE make changes in app.cpp as well
    int total_size = returnTotalSizeofLengthArray(lengths, size_array);
    ocall_print("Total size of concat is ");
    ocall_print_int(total_size);
    

    char* returnString = (char*) malloc(total_size + 1);
    char* ptr = returnString;
    for (int i = 0; i < size_array; i++) {
        memcpy(ptr, strings_to_concat[i], lengths[i]);
        ptr = ptr + lengths[i];
    }
    returnString[total_size] = '\0';

    ocall_print("Concat return string is");
    ocall_print(returnString);
    return returnString;

}
//Responbility of caller to free return
char* receiveNetworkRequestHelper(char* request, size_t requestSize, bool isEnclaveUntrustedHost) {
    // ocall_print("helllo");
    // ocall_print_int(strlen(request));
    //char requestCopy[250];
    char* requestCopy = (char*) malloc(requestSize);
    // ocall_print("malloc init");
    memcpy(requestCopy, request, requestSize);
    // requestCopy[strlen(request)] = '\0';
    // ocall_print("malloc yeeee");


    #ifdef ENCLAVE_STD_ALT   
    return createStringLiteralMalloced("empty");
    #else
    char* split = strtok(requestCopy, ":");
    if (strcmp(split, "Create") == 0) {
        char* newMachineID;
        char* parentTrustedMachinePublicIDKey;
        char* machineType;
        int numArgs;
        int payloadType;
        char* payload;


        // if (NETWORK_DEBUG) {
        //     newMachineID = (char* ) malloc(SIZE_OF_IDENTITY_STRING);
        //     split = strtok(NULL, ":");
        //     parentTrustedMachinePublicIDKey = split;
        //     split = strtok(NULL, ":");
        //     machineType = split;
        //     split = strtok(NULL, ":");
        //     numArgs = atoi(split);
        //     payloadType = -1;
        //     payload = (char*) malloc(10);
        //     payload[0] = '\0';
        //     if (numArgs > 0) {
        //         split = strtok(NULL, ":");
        //         payloadType = atoi(split);
        //         split = strtok(NULL, "\0");
        //         safe_free(payload);
        //         payload = split;

        //     } else {
        //         safe_free(payload);
        //     }
        // } else {
            // char* requestCopyCopy = (char*) malloc(requestSize);
            // memcpy(requestCopyCopy, request, requestSize);

            newMachineID = (char* ) malloc(SGX_RSA3072_KEY_SIZE);

            parentTrustedMachinePublicIDKey = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(parentTrustedMachinePublicIDKey, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            char* nextIndex = requestCopy + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1; //TODO using requestcopy here might be an issue

            char* newTokenizerString = (char*) malloc(strlen(nextIndex) + 1);
            strncpy(newTokenizerString, nextIndex, strlen(nextIndex) + 1);
            ocall_print("New tokenizer is ");
            ocall_print(newTokenizerString);

            split = strtok(newTokenizerString, ":");
            machineType = split;
            split = strtok(NULL, ":");
            numArgs = atoi(split);
            payloadType = -1;
            payload = (char*) malloc(10);
            payload[0] = '\0';
            int payloadSize;
            if (numArgs > 0) {
                split = strtok(NULL, ":");
                payloadType = atoi(split);
                split = strtok(NULL, ":");
                payloadSize = atoi(split);
                safe_free(payload);
                payload = split + strlen(split) + 1;

            } else {
                safe_free(payload);
            }
        // }
        

        if (isEnclaveUntrustedHost) {
        
            sgx_enclave_id_t new_enclave_eid = 0;
            string token = "enclave" + to_string((int)CURRENT_ENCLAVE_EID_NUM) + ".token";
            CURRENT_ENCLAVE_EID_NUM += 1;


            if (initialize_enclave(&new_enclave_eid, token, "enclave.signed.so") < 0) { //TODO figure out how to initialize all enclaves. Maybe network_ra should do that as a setup step?
                ocall_print("Fail to initialize enclave.");
            }    

            int ptr;

            // printf("Enclave eid is : %d\n", new_enclave_eid);
            // printf("machineType is : %s\n", machineType);
            // printf("parentTrustedIdKey is : %s\n", parentTrustedMachinePublicIDKey);
            // printf("payload is : %s\n", payload);
            // printf("numArgs is : %d\n", numArgs);
            // printf("PayloadType is : %d\n", payloadType);
            // enclave_eprint(new_enclave_eid, "hello-ddd");

            //TODO make it so that you know which enclave to call createMachineAPI on since there may be multiple enclaves
            //TODO actually make this call a method in untrusted host (enclave_untrusted_host.cpp)
            // application of this enclave and have that make an ecall to createMachineAPi
            // if (NETWORK_DEBUG) {
            //     sgx_status_t status = enclave_createMachineAPI(new_enclave_eid, &ptr, new_enclave_eid, machineType, parentTrustedMachinePublicIDKey, newMachineID, numArgs, payloadType, payload, SIZE_OF_IDENTITY_STRING, SIZE_OF_MAX_EVENT_PAYLOAD, new_enclave_eid);
            // } else {
                ocall_print("at helper.cpp level");
                printRSAKey(parentTrustedMachinePublicIDKey);
                sgx_status_t status = enclave_createMachineAPI(new_enclave_eid, &ptr, new_enclave_eid, machineType, parentTrustedMachinePublicIDKey, newMachineID, numArgs, payloadType, payload, payloadSize, SGX_RSA3072_KEY_SIZE, SIZE_OF_MAX_EVENT_PAYLOAD, new_enclave_eid);
            // }
            safe_free(requestCopy);
            return newMachineID;

        } else {
            //free(requestCopy);
            if (USMAuthorizedTypes.count(machineType) > 0) {
                char* ret = createUSMMachineAPI(machineType, numArgs, payloadType, payload, payloadSize);
                safe_free(requestCopy);
                return ret;
            } else {
                safe_free(requestCopy);
                return untrusted_enclave1_receiveNetworkRequest(request, requestSize);
            }
        }

    // }  else if (strcmp(split, "GetKey") == 0) {
    //     //TODO move this segmant of code into other ra method because attestation needs to occur first and then call retrieveCapabilityKey
    //     //TODO move this and use the messageFromMachine int
    //     //TODO might need to verify the currentMachineIDs signagure before we call attestation, so we need to do that first?
    //     split = strtok(NULL, ":");
    //     char currentMachineID[SIZE_OF_IDENTITY_STRING];
    //     //TODO add check that split is not too big
    //     memcpy(currentMachineID, split, strlen(split) + 1);
    //     split = strtok(NULL, ":");
    //     char childMachineID[SIZE_OF_IDENTITY_STRING];
    //     memcpy(childMachineID, split, strlen(split) + 1);
    //     return retrieveCapabilityKey(currentMachineID, childMachineID);

    
    }  else if (strcmp(split, "UntrustedCreate") == 0) {

        char* newMachineID = (char* ) malloc(SIZE_OF_IDENTITY_STRING);
        split = strtok(NULL, ":");
        char* machineType = split;
        split = strtok(NULL, ":");
        int numArgs = atoi(split);
        int payloadType = -1;
        char* payload = (char*) malloc(10);
        payload[0] = '\0';
        int payloadSize;
        if (numArgs > 0) {
            split = strtok(NULL, ":");
            payloadType = atoi(split);
            split = strtok(NULL, ":");
            payloadSize = atoi(split);
            safe_free(payload);
            payload = split + strlen(split) + 1;

        } else {
            safe_free(payload);
        }

        if (isEnclaveUntrustedHost) {

            sgx_enclave_id_t new_enclave_eid = 0;
            string token = "enclave" + to_string((int)CURRENT_ENCLAVE_EID_NUM) + ".token";
            CURRENT_ENCLAVE_EID_NUM += 1;

            if (initialize_enclave(&new_enclave_eid, token, "enclave.signed.so") < 0) { //TODO figure out how to initialize all enclaves. Maybe network_ra should do that as a setup step?
                ocall_print("Fail to initialize enclave.");
            }   

            //TODO actually make this call a method in untrusted host (enclave_untrusted_host.cpp)
            // if (NETWORK_DEBUG) {
            //     sgx_status_t status = enclave_UntrustedCreateMachineAPI(new_enclave_eid, new_enclave_eid, machineType, 30, newMachineID, numArgs, payloadType, payload, SIZE_OF_IDENTITY_STRING, SIZE_OF_MAX_MESSAGE, new_enclave_eid);
            // } else {
                sgx_status_t status = enclave_UntrustedCreateMachineAPI(new_enclave_eid, new_enclave_eid, machineType, 30, newMachineID, numArgs, payloadType, payload, payloadSize, SGX_RSA3072_KEY_SIZE, SIZE_OF_MAX_MESSAGE, new_enclave_eid);
            // }
            safe_free(requestCopy);
            return newMachineID;


        } else {
            if (USMAuthorizedTypes.count(machineType) > 0) {
                char* ret = createUSMMachineAPI(machineType, numArgs, payloadType, payload, payloadSize);
                safe_free(requestCopy);
                return ret;
            } else {
                safe_free(requestCopy);
                return untrusted_enclave1_receiveNetworkRequest(request, requestSize);
            }
        }

    
    } else if (strcmp(split, "InitComm") == 0) {

        char* newSessionKey = (char* ) malloc(SIZE_OF_SESSION_KEY);
        newSessionKey[0] = '\0';

        char* machineInitializingComm;
        char* machineReceivingComm;

        // if (NETWORK_DEBUG) {
        //     split = strtok(NULL, ":");
        //     machineInitializingComm = split;
        //     split = strtok(NULL, ":");
        //     machineReceivingComm = split;
        // } else {
            machineInitializingComm = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineInitializingComm, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            machineReceivingComm = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingComm, request + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1, SGX_RSA3072_KEY_SIZE);
        // }
        
        if (isEnclaveUntrustedHost) {

            // if (NETWORK_DEBUG) {
            //     if (PublicIdentityKeyToEidDictionary.count(string(machineReceivingComm)) == 0) {
            //         ocall_print("\n No Enclave Eid Found!\n");
            //     }
                
            //     sgx_enclave_id_t enclave_eid = PublicIdentityKeyToEidDictionary[string(machineReceivingComm)]; //TODO add check here in case its not in dictionary

            //     int ptr;
            //     //TODO actually make this call a method in untrusted host (enclave_untrusted_host.cpp)
            //     sgx_status_t status = enclave_initializeCommunicationAPI(enclave_eid, &ptr, machineInitializingComm,machineReceivingComm, newSessionKey, SIZE_OF_IDENTITY_STRING, SIZE_OF_SESSION_KEY);
            //     if (status != SGX_SUCCESS) {
            //         printf("Sgx Error Code: %x\n", status);
            //     }
            // } else {
                if (PublicIdentityKeyToEidDictionary.count(string(machineReceivingComm, SGX_RSA3072_KEY_SIZE)) == 0) {
                    ocall_print("\n No Enclave Eid Found!\n");
                }
                
                sgx_enclave_id_t enclave_eid = PublicIdentityKeyToEidDictionary[string(machineReceivingComm, SGX_RSA3072_KEY_SIZE)]; //TODO add check here in case its not in dictionary

                int ptr;
                //TODO actually make this call a method in untrusted host (enclave_untrusted_host.cpp)
                sgx_status_t status = enclave_initializeCommunicationAPI(enclave_eid, &ptr, machineInitializingComm,machineReceivingComm, newSessionKey, SGX_RSA3072_KEY_SIZE, SIZE_OF_SESSION_KEY);
                if (status != SGX_SUCCESS) {
                    printf("Sgx Error Code: %x\n", status);
                }
            // }
        
            
            safe_free(requestCopy);
            return newSessionKey;

        } else {
            //TODO shivIdentity
            if (USMPublicIdentityKeyToMachinePIDDictionary.count(string(machineReceivingComm)) > 0) {
                
                char* ret = USMinitializeCommunicationAPI(machineInitializingComm, machineReceivingComm);
                safe_free(requestCopy);
                return ret;
            
            } else {
                safe_free(requestCopy);
                return untrusted_enclave1_receiveNetworkRequest(request, requestSize);
            }
        }

    
    }  else if (strcmp(split, "UntrustedSend") == 0) {

        char* machineReceivingMessage;
        char* eventNum;
        char* temp;
        int numArgs;
        int payloadType;
        char* payload;

        // if (NETWORK_DEBUG) {
        //     split = strtok(NULL, ":");
        //     machineReceivingMessage = split;
        //     split = strtok(NULL, ":");
        //     eventNum = split;
        //     split = strtok(NULL, ":");
        //     numArgs = atoi(split);
        //     payloadType = -1;
        //     payload = (char*) malloc(10);
        //     payload[0] = '\0';
        //     if (numArgs > 0) {
        //         split = strtok(NULL, ":");
        //         payloadType = atoi(split);
        //         split = strtok(NULL, "\0");
        //         safe_free(payload);
        //         payload = split;

        //     } else {
        //         safe_free(payload);
        //     }
        // } else {
            machineReceivingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingMessage, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);

            char* nextIndex = requestCopy + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1; //TODO using requestcopy here might be an issue

            char* newTokenizerString = (char*) malloc(strlen(nextIndex) + 1);
            strncpy(newTokenizerString, nextIndex, strlen(nextIndex) + 1);
            ocall_print("New tokenizer is ");
            ocall_print(newTokenizerString);

            split = strtok(newTokenizerString, ":");
            eventNum = split;
            split = strtok(NULL, ":");
            numArgs = atoi(split);
            payloadType = -1;
            payload = (char*) malloc(10);
            payload[0] = '\0';
            int payloadSize;
            if (numArgs > 0) {
                split = strtok(NULL, ":");
                payloadType = atoi(split);
                split = strtok(NULL, ":");
                payloadSize = atoi(split);
                safe_free(payload);
                payload = split + strlen(split) + 1;

            } else {
                safe_free(payload);
            }

            
        // }

        

        if (isEnclaveUntrustedHost) {

            // if (NETWORK_DEBUG) {
            //     sgx_enclave_id_t enclave_eid = PublicIdentityKeyToEidDictionary[string(machineReceivingMessage)]; //TODO add check here in case its not in dictionary
            //     int ptr;
            //     //TODO actually make this call a method in untrusted host (enclave_untrusted_host.cpp)
            //     sgx_status_t status = enclave_sendUntrustedMessageAPI(enclave_eid, &ptr, machineReceivingMessage, eventNum, numArgs, payloadType, payload, SIZE_OF_IDENTITY_STRING, SIZE_OF_MAX_EVENT_NAME, SIZE_OF_MAX_EVENT_PAYLOAD);
            // } else {
                sgx_enclave_id_t enclave_eid = PublicIdentityKeyToEidDictionary[string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE)]; //TODO add check here in case its not in dictionary
                int ptr;
                //TODO actually make this call a method in untrusted host (enclave_untrusted_host.cpp)
                sgx_status_t status = enclave_sendUntrustedMessageAPI(enclave_eid, &ptr, machineReceivingMessage, eventNum, numArgs, payloadType, payload, payloadSize, SGX_RSA3072_KEY_SIZE, SIZE_OF_MAX_EVENT_NAME, SIZE_OF_MAX_EVENT_PAYLOAD);
            // }

            
            safe_free(requestCopy);
            return createStringLiteralMalloced("Untrusted Message Succesfully sent!");

        } else {
            string machineReceiveMsgString;
            int count;
            // if (NETWORK_DEBUG) {
            //     machineReceiveMsgString = string(machineReceivingMessage);
            //     count = USMPublicIdentityKeyToMachinePIDDictionary.count(string(machineReceivingMessage));
            // } else {
                machineReceiveMsgString = string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE);
                count = USMPublicIdentityKeyToMachinePIDDictionary.count(string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE));
            // }
            
            // printf("Untrusted Send -> machine checking in dictionary is %s\n", machineReceiveMsgString.c_str());
            if (count > 0) {
                // printf("Sending Message to USM in app.cpp\n");
                char* ret = USMsendMessageAPI(machineReceivingMessage, eventNum, numArgs, payloadType, payload, payloadSize);
                safe_free(requestCopy);
                return ret;
                
            } else {
                safe_free(requestCopy);
                return untrusted_enclave1_receiveNetworkRequest(request, requestSize);
            }
        }

    } else if (strcmp(split, "Send") == 0) {

        char* machineSendingMessage;
        char* machineReceivingMessage;
        char* encryptedMessage;
        char* temp;

        // if (NETWORK_DEBUG) {
        //     split = strtok(NULL, ":");
        //     machineSendingMessage = split;
        //     split = strtok(NULL, ":");
        //     machineReceivingMessage = split;
        //     encryptedMessage = requestCopy + strlen("Send") + 1 + strlen(machineSendingMessage) + 1 + strlen(machineReceivingMessage) + 1;
        // } else {
            machineSendingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineSendingMessage, request + strlen(split) + 1, SGX_RSA3072_KEY_SIZE);
            machineReceivingMessage = (char*) malloc(SGX_RSA3072_KEY_SIZE);
            memcpy(machineReceivingMessage, request + strlen(split) + 1 + SGX_RSA3072_KEY_SIZE + 1, SGX_RSA3072_KEY_SIZE);

            encryptedMessage = requestCopy + strlen("Send") + 1 + SGX_RSA3072_KEY_SIZE + 1 + SGX_RSA3072_KEY_SIZE + 1;
        // }

        
        ocall_print("encrypted message is");
        ocall_print(encryptedMessage);

        if (isEnclaveUntrustedHost) {

            int count;
            int ptr;
            sgx_enclave_id_t enclave_eid;
            // if (NETWORK_DEBUG) {
            //     count = PublicIdentityKeyToEidDictionary.count(string(machineReceivingMessage));
            //     enclave_eid = PublicIdentityKeyToEidDictionary[string(machineReceivingMessage)]; //TODO add check here in case its not in dictionary
            //     // ocall_print("about to call decrypt");
            //     // ocall_print(machineSendingMessage);
            //     // ocall_print_int(strlen(machineSendingMessage) + 1);
            //     // ocall_print(machineReceivingMessage);
            //     // ocall_print_int(strlen(machineReceivingMessage) + 1);
            //     // ocall_print(encryptedMessage);
            //     // ocall_print_int(strlen(encryptedMessage) + 1);
            //     // char mSM[strlen(machineSendingMessage) + 1];
            //     // memcpy(mSM, machineSendingMessage, strlen(machineSendingMessage) + 1);
            //     // char mRM[strlen(machineReceivingMessage) + 1];
            //     // memcpy(mRM, machineReceivingMessage, strlen(machineReceivingMessage) + 1);
            //     // char eM[strlen(encryptedMessage) + 1];
            //     // memcpy(eM, encryptedMessage, strlen(encryptedMessage) + 1);
            //     //TODO actually make this call a method in untrusted host (enclave_untrusted_host.cpp)
            //     sgx_status_t status = enclave_decryptAndSendMessageAPI(enclave_eid, &ptr, machineSendingMessage,machineReceivingMessage, encryptedMessage, SIZE_OF_IDENTITY_STRING, SIZE_OF_MAX_EVENT_PAYLOAD);
            // } else {
                count = PublicIdentityKeyToEidDictionary.count(string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE));
                enclave_eid = PublicIdentityKeyToEidDictionary[string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE)];
                sgx_status_t status = enclave_decryptAndSendMessageAPI(enclave_eid, &ptr, machineSendingMessage,machineReceivingMessage, encryptedMessage, SGX_RSA3072_KEY_SIZE, SIZE_OF_MAX_EVENT_PAYLOAD);
            // }
            

            if (count == 0) {
                printf("\n No Enclave Eid Found!\n");
            }
            
            safe_free(requestCopy);
            return temp;

        } else {
            int count;
            // if (NETWORK_DEBUG) {
            //     count = USMPublicIdentityKeyToMachinePIDDictionary.count(string(machineReceivingMessage));
            // } else {
                count = USMPublicIdentityKeyToMachinePIDDictionary.count(string(machineReceivingMessage, SGX_RSA3072_KEY_SIZE));
            // }
            if (count > 0) {
                safe_free(requestCopy);
                //TODO need to implement
                return createStringLiteralMalloced("TODO");
                
            } else {
                safe_free(requestCopy);
                return untrusted_enclave1_receiveNetworkRequest(request, requestSize);
            }
        }


    } else {
        safe_free(requestCopy);
        return createStringLiteralMalloced("Command Not Found");
    }
    #endif
}

PRT_VALUE* sendCreateMachineNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* createTypeCommand, bool isSecureCreate) {
    //If making changes here, make relevant changes in app.cpp
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    char* requestedNewMachineTypeToCreate = (char*) argRefs[0];

    char* currentMachineIDPublicKey;

    // if (NETWORK_DEBUG) {
    //     currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    //     snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)(get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str())); 
    // } else {
        currentMachineIDPublicKey = (char*) malloc(SGX_RSA3072_KEY_SIZE);
        memcpy(currentMachineIDPublicKey, (char*)(get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str()), SGX_RSA3072_KEY_SIZE);
    // }
  

    // if (!machineTypeIsSecure(requestedNewMachineTypeToCreate)) {
    //     //TODO Add case here if we are creating untrusted machine (Do we need this because inside the enclave we dont
    //     //have untrusted machines)
    //     PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * 100);
    //     sprintf_s(str, 100, "Error: Tried to Create USM inside enclave!");
    //     return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);

    // }

    // ocall_print("KIRAT TEST");
    // char* constructString2[] = {"kirat", ":", "sidhu"};
    //             int constructStringLengths2[] = {strlen("kirat"), 1, strlen("sidhu")};
    //             ocall_print(concatMutipleStringsWithLength(constructString2, constructStringLengths2, 3));

    int numArgs = atoi((char*) argRefs[1]);

    PRT_VALUE* payloadPrtValue;
    char* payloadString = NULL;  
    int payloadType;
    int payloadStringSize;

    if (numArgs == 1) {
        payloadPrtValue = *(argRefs[2]);
        payloadType = payloadPrtValue->discriminator;
        payloadStringSize = 0; //TODO shividentity
        payloadString = (char*) malloc(SIZE_OF_MAX_EVENT_PAYLOAD);
        char* temp = serializePrtValueToString(payloadPrtValue, payloadStringSize);
        memcpy(payloadString, temp, payloadStringSize + 1);
        payloadString[payloadStringSize] = '\0';
        ocall_print("EVENT MESSAGE PAYLOAD IS");
        ocall_print(payloadString);
        ocall_print("Length is");
        ocall_print_int(payloadStringSize);
        safe_free(temp);

    }

    char* payloadStringSizeString = (char*) malloc(10);
    itoa(payloadStringSize, payloadStringSizeString, 10);

    char* newMachinePublicIDKey = (char*) malloc(SIZE_OF_IDENTITY_STRING + 1);
    int requestSize = 5 + 1 + SIZE_OF_IDENTITY_STRING + 1 + SIZE_OF_NEWMACHINETYPE + 1 + 10 + 1 + SIZE_OF_MAX_MESSAGE + 1 + SIZE_OF_MAX_EVENT_PAYLOAD + 1;
    char* createMachineRequest = (char*) malloc(requestSize);//(char*)("Create:" + string(currentMachineIDPublicKey) + ":" + string(requestedNewMachineTypeToCreate)).c_str();
    int requestLength;
    char* numArgsString = (char*) argRefs[1];
    char* payloadTypeString = (char*) malloc(10);
    itoa(payloadType, payloadTypeString, 10);
         if (isSecureCreate) {
            if (numArgs == 0) {

                // if (NETWORK_DEBUG) {
                //     // char* constructString[] = {createTypeCommand, ":", currentMachineIDPublicKey, ":", requestedNewMachineTypeToCreate, ":0"};
                //     // int constructStringLengths[] = {strlen(createTypeCommand), 1, strlen(currentMachineIDPublicKey), 1, strlen(requestedNewMachineTypeToCreate), 2};
                //     // safe_free(createMachineRequest);
                //     // createMachineRequest = concatMutipleStringsWithLength(constructString, constructStringLengths, 6);
                //     snprintf(createMachineRequest, requestSize, "%s:%s:%s:0", createTypeCommand, currentMachineIDPublicKey, requestedNewMachineTypeToCreate);
                //     requestLength = strlen(createMachineRequest) + 1;
                // } else {
                    char* constructString[] = {createTypeCommand, ":", currentMachineIDPublicKey, ":", requestedNewMachineTypeToCreate, ":0"};
                    int constructStringLengths[] = {strlen(createTypeCommand), 1, SGX_RSA3072_KEY_SIZE, 1, strlen(requestedNewMachineTypeToCreate), 2};
                    safe_free(createMachineRequest);
                    createMachineRequest = concatMutipleStringsWithLength(constructString, constructStringLengths, 6);
                    requestLength = returnTotalSizeofLengthArray(constructStringLengths, 6) + 1;

                // }
            } else {
                
                // ocall_print("GURGY");
                // if (NETWORK_DEBUG) {
                //     // char* numArgsString = (char*) argRefs[1];
                //     // char* payloadTypeString = (char*) malloc(10);
                //     // itoa(payloadType, payloadTypeString, 10);
                //     // char* constructString[] = {createTypeCommand, ":", currentMachineIDPublicKey, ":", requestedNewMachineTypeToCreate, ":", numArgsString, ":", payloadTypeString, ":", payloadString};
                //     // int constructStringLengths[] = {strlen(createTypeCommand), 1, strlen(currentMachineIDPublicKey), 1, strlen(requestedNewMachineTypeToCreate), 1, strlen(numArgsString), 1, strlen(payloadTypeString), 1, strlen(payloadString)};
                //     // safe_free(createMachineRequest);
                //     // createMachineRequest = concatMutipleStringsWithLength(constructString, constructStringLengths, 11);
                //     snprintf(createMachineRequest, requestSize, "%s:%s:%s:%d:%d:", createTypeCommand, currentMachineIDPublicKey, requestedNewMachineTypeToCreate, numArgs, payloadType);
                //     memcpy(createMachineRequest + strlen(createMachineRequest), payloadString, payloadStringSize);

                //     requestLength = strlen(createMachineRequest) + 1;
                // } else {
                    ocall_print("requested new type of machine to create is");
                    ocall_print(requestedNewMachineTypeToCreate);
                    ocall_print("current RSA key is");
                    printRSAKey(currentMachineIDPublicKey);
                    
                    char* constructString[] = {createTypeCommand, ":", currentMachineIDPublicKey, ":", requestedNewMachineTypeToCreate, ":", numArgsString, ":", payloadTypeString, ":", payloadStringSizeString, ":", payloadString};
                    int constructStringLengths[] = {strlen(createTypeCommand), 1, SGX_RSA3072_KEY_SIZE, 1, strlen(requestedNewMachineTypeToCreate), 1, strlen(numArgsString), 1, strlen(payloadTypeString), 1, strlen(payloadStringSizeString), 1, payloadStringSize};
                    safe_free(createMachineRequest);
                    createMachineRequest = concatMutipleStringsWithLength(constructString, constructStringLengths, 13);
                    requestLength = returnTotalSizeofLengthArray(constructStringLengths, 13) + 1;
                    safe_free(payloadTypeString);

                    ocall_print("KURUT");
                    ocall_print(createMachineRequest);
                // }
                // ocall_print(createMachineRequest);
            }
        

        // concatMutipleStringsWithLength

        } else {
            if (numArgs == 0) {
                char* constructString[] = {createTypeCommand, ":", requestedNewMachineTypeToCreate, ":0"};
                int constructStringLengths[] = {strlen(createTypeCommand), 1, strlen(requestedNewMachineTypeToCreate), 2};
                safe_free(createMachineRequest);
                createMachineRequest = concatMutipleStringsWithLength(constructString, constructStringLengths, 4);
                requestLength = returnTotalSizeofLengthArray(constructStringLengths, 4) + 1;

                // snprintf(createMachineRequest, requestSize, "%s:%s:0", createTypeCommand, requestedNewMachineTypeToCreate);
            } else {
                char* constructString[] = {createTypeCommand, ":", requestedNewMachineTypeToCreate, ":", numArgsString, ":", payloadTypeString, ":", payloadStringSizeString, ":", payloadString};
                int constructStringLengths[] = {strlen(createTypeCommand), 1, strlen(requestedNewMachineTypeToCreate), 1, strlen(numArgsString), 1, strlen(payloadTypeString), 1, strlen(payloadStringSizeString), 1, payloadStringSize};
                safe_free(createMachineRequest);
                createMachineRequest = concatMutipleStringsWithLength(constructString, constructStringLengths, 11);
                requestLength = returnTotalSizeofLengthArray(constructStringLengths, 11) + 1;

                // snprintf(createMachineRequest, requestSize, "%s:%s:%d:%d:", createTypeCommand, requestedNewMachineTypeToCreate, numArgs, payloadType);
                // memcpy(createMachineRequest + strlen(createMachineRequest), payloadString, payloadStringSize);

            }
            // requestLength = strlen(createMachineRequest) + 1;
        }
    
   
    safe_free(payloadString);
    
    
    char* machineNameWrapper[] = {currentMachineIDPublicKey};
    char* printStr = generateCStringFromFormat("%s machine is sending out the following network request:", machineNameWrapper, 1);
    ocall_print(printStr); //TODO use this method for all future ocall_prints
    safe_free(printStr);
    ocall_print(createMachineRequest);
    int ret_value; 

    #ifdef ENCLAVE_STD_ALT   
    ocall_network_request(&ret_value, createMachineRequest, newMachinePublicIDKey, requestLength, SIZE_OF_IDENTITY_STRING + 1);
    #else
    ocall_network_request(createMachineRequest, newMachinePublicIDKey, requestLength, SIZE_OF_IDENTITY_STRING + 1);
    // newMachinePublicIDKey = send_network_request_API(createMachineRequest);
    #endif
    safe_free(createMachineRequest);
    
    char* machineNameWrapper2[] = {currentMachineIDPublicKey};
    printStr = generateCStringFromFormat("%s machine has created a new machine with Identity Public Key as:", machineNameWrapper2, 1);
    ocall_print(printStr); //TODO use this method for all future ocall_prints
    safe_free(printStr);

    // if (NETWORK_DEBUG) {
    //     ocall_print(newMachinePublicIDKey);
    // } else {
        printRSAKey(newMachinePublicIDKey);
    // }
    

    #ifdef ENCLAVE_STD_ALT

    if (isSecureCreate) {

        //Now, need to retrieve capabilityKey for this newMachinePublicIDKey and store (thisMachineID, newMachinePublicIDKey) -> capabilityKey
        string request;
        // if (NETWORK_DEBUG) {
        //     request = "GetKey:" + string(currentMachineIDPublicKey) + ":" + string(newMachinePublicIDKey);//TODO unhardcode current Machine name
        // } else {
            request = "GetKey:" + string(currentMachineIDPublicKey, SGX_RSA3072_KEY_SIZE) + ":" + string(newMachinePublicIDKey, SGX_RSA3072_KEY_SIZE);//TODO unhardcode current Machine name
        // }
        //TODO replace above line with snprintf as did with createMachineRequest, and do this everywhere in code
        char* getChildMachineIDRequest = (char*) request.c_str(); 
        char* capabilityKey = retrieveCapabilityKeyForChildFromKPS(currentMachineIDPublicKey, newMachinePublicIDKey);//(char*) malloc(SIZE_OF_CAPABILITYKEY); 
        //ocall_network_request(&ret_value, getChildMachineIDRequest, capabilityKey, SIZE_OF_CAPABILITYKEY);
        
        char* machineNameWrapper3[] = {currentMachineIDPublicKey};
        printStr = generateCStringFromFormat("%s machine has received capability key for secure child:", machineNameWrapper3, 1);
        ocall_print(printStr); //TODO use this method for all future ocall_prints
        safe_free(printStr);
        ocall_print(capabilityKey);

        // if (NETWORK_DEBUG) {
        //     PMachineToChildCapabilityKey[make_tuple(currentMachinePID, string(newMachinePublicIDKey))] = string(capabilityKey); //TODO shiv identity
        // } else {
            PMachineToChildCapabilityKey[make_tuple(currentMachinePID, string(newMachinePublicIDKey, SGX_RSA3072_KEY_SIZE))] = string(capabilityKey); //TODO shiv identity
        // }

        safe_free(capabilityKey);
    }

    #endif
    safe_free(currentMachineIDPublicKey);

    //Return the newMachinePublicIDKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * (SIZE_OF_PRT_STRING_SERIALIZED));
    // if (NETWORK_DEBUG) {
    //     sprintf_s(str, SIZE_OF_PRT_STRING_SERIALIZED, newMachinePublicIDKey);
    // } else {
        memcpy(str, newMachinePublicIDKey, SIZE_OF_PRT_STRING_SERIALIZED);
    // }
	
    safe_free(newMachinePublicIDKey);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}

int getNextPID() {
    return ((PRT_PROCESS_PRIV*)process)->numMachines + 1;
}

void PrintTuple(PRT_VALUE* tuple){
    ocall_print("Printing Tuple:");
    PRT_TUPVALUE* tupPtr = tuple->valueUnion.tuple;
    ocall_print("Tuple size:");
    ocall_print_int(tupPtr->size);
    for (int i = 0; i < tupPtr->size; i++) {
        PRT_VALUE* currValue = tupPtr->values[i];
        int currValueType = tupPtr->values[i]->discriminator;
        if (currValueType == PRT_VALUE_KIND_INT) {
            ocall_print("Int Value:");
            ocall_print_int(currValue->valueUnion.nt);
        } else if (currValueType == PRT_VALUE_KIND_FOREIGN) {
            ocall_print("String Value:");
            ocall_print( (char*)currValue->valueUnion.frgn->value);
        }
    }

}

int handle_incoming_event(PRT_UINT32 eventIdentifier, PRT_MACHINEID receivingMachinePID, int numArgs, int payloadType, char* payload, int payloadSize) {
    PRT_VALUE* event = PrtMkEventValue(eventIdentifier);
    PRT_MACHINEINST* machine = PrtGetMachine(process, PrtMkMachineValue(receivingMachinePID));
    if (numArgs == 0) {
        PrtSend(NULL, machine, event, 0);
    } else {
        char* payloadConcat = (char*) malloc(SIZE_OF_MAX_MESSAGE);
        itoa(payloadType, payloadConcat, 10);
        strncat(payloadConcat, ":", SIZE_OF_MAX_MESSAGE + 1);
        int sizeSoFar = strlen(payloadConcat);
        memcpy(payloadConcat + sizeSoFar, payload, payloadSize);
        payloadConcat[sizeSoFar + payloadSize] = '\0';
        // strncat(payloadConcat, payload, SIZE_OF_MAX_MESSAGE + 1);
        int numCharactersProcessed;
        //print out what is being passed to the below method
        ocall_print("Passing In String To Deserialize:");
        ocall_print(payloadConcat);
        PRT_VALUE** prtPayload =  deserializeStringToPrtValue(numArgs, payloadConcat, &numCharactersProcessed);
        safe_free(payloadConcat);
        if (payloadType == PRT_VALUE_KIND_TUPLE) {
            PrintTuple(*prtPayload);
        } else if (payloadType == PRT_VALUE_KIND_MAP) {
            PrtPrintValue(event);
            PrtPrintValue(*prtPayload);
        }
        PrtSend(NULL, machine, event, numArgs, prtPayload);
    }
    return 0;
}

int createMachine(char* machineType, int numArgs, int payloadType, char* payload, int payloadSize) {
    PRT_VALUE* prtPayload;
    if (numArgs > 0) {
        ocall_print("Serialized the following payload");
        char* payloadConcat = (char*) malloc(SIZE_OF_MAX_MESSAGE);
        itoa(payloadType, payloadConcat, 10);
        strncat(payloadConcat, ":", SIZE_OF_MAX_MESSAGE + 1);
        int sizeSoFar = strlen(payloadConcat);
        memcpy(payloadConcat + sizeSoFar, payload, payloadSize);
        payloadConcat[sizeSoFar + payloadSize] = '\0';
        ocall_print(payloadConcat);
        int numCharactersProcessed;
        prtPayload = *(deserializeStringToPrtValue(numArgs, payloadConcat, &numCharactersProcessed));
        safe_free(payloadConcat);
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
    PRT_UINT32 interfaceName;  
	PrtLookupMachineByName(machineType, &interfaceName);
    PRT_UINT32 instanceOf = program->interfaceDefMap[interfaceName];
    PRT_MACHINEDECL* curMachineDecl = program->machines[instanceOf];
    return curMachineDecl->isSecure;
}

//responsibility of caller to free string
string createString(char* str) {
    char* strCopy = (char*) malloc(strlen(str) + 1); //TODO shivfree
    memcpy(strCopy, str, strlen(str) + 1);
    return string(strCopy);
}

extern "C" PRT_VALUE* P_Concat_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_UINT64 val = (*P_VAR_payload)->valueUnion.frgn->value;

    PRT_VALUE** P_VAR_payload2 = argRefs[1];
    PRT_UINT64 val2 = (*P_VAR_payload2)->valueUnion.frgn->value;

    // strncat((char*) val, (char*) val2, SGX_RSA3072_KEY_SIZE + 1); //TODO shividentity

    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * (SIZE_OF_PRT_STRING_SERIALIZED));
    memcpy(str, (char*)val, SIZE_OF_PRT_STRING_SERIALIZED);
	// sprintf_s(str, SIZE_OF_PRT_STRING_SERIALIZED, (char*)val);
    return PrtMkForeignValue((PRT_UINT64)str, P_TYPEDEF_StringType);
}

extern "C" PRT_VALUE* P_GetThis_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    uint32_t currentMachinePID = context->id->valueUnion.mid->machineId;
    char* currentMachineIDPublicKey;
 
    currentMachineIDPublicKey = (char*) malloc(SIZE_OF_IDENTITY_STRING);
    snprintf(currentMachineIDPublicKey, SIZE_OF_IDENTITY_STRING, "%s",(char*)get<0>(MachinePIDToIdentityDictionary[currentMachinePID]).c_str()); //TODO shivIdentity
    //Return the currentMachineIDPublicKey and it is the responsibility of the P Secure machine to save it and use it to send messages later
    PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * (SIZE_OF_PRT_STRING_SERIALIZED));
    memcpy(str, currentMachineIDPublicKey, SIZE_OF_PRT_STRING_SERIALIZED);
	// sprintf_s(str, SIZE_OF_PRT_STRING_SERIALIZED, currentMachineIDPublicKey); //TODO shividentity
    safe_free(currentMachineIDPublicKey);
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
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * (SIZE_OF_PRT_STRING_SERIALIZED));
	sprintf_s(str, SIZE_OF_PRT_STRING_SERIALIZED, "String : %lld", frgnVal);
	return str;
}

extern "C" PRT_UINT32 P_GETHASHCODE_StringType_IMPL(PRT_UINT64 frgnVal)
{
	return (PRT_UINT32)frgnVal;
}

extern "C" PRT_UINT64 P_MKDEF_StringType_IMPL(void)
{
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * (SIZE_OF_PRT_STRING_SERIALIZED));
	sprintf_s(str, SIZE_OF_PRT_STRING_SERIALIZED, "xyx$12");
	return (PRT_UINT64)str;
}

extern "C" PRT_UINT64 P_CLONE_StringType_IMPL(PRT_UINT64 frgnVal)
{
	PRT_STRING str = (PRT_STRING) PrtMalloc(sizeof(PRT_CHAR) * (SIZE_OF_PRT_STRING_SERIALIZED));
    // if (NETWORK_DEBUG) {
    //     sprintf_s(str, SIZE_OF_PRT_STRING_SERIALIZED, (PRT_STRING)frgnVal);
    // } else {
        memcpy(str, (void*)frgnVal, SIZE_OF_PRT_STRING_SERIALIZED);
    // }
	
	return (PRT_UINT64)str;
}

extern "C" void P_PrintString_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_UINT64 val = (*P_VAR_payload)->valueUnion.frgn->value;
    ocall_print("String P value is:");
    ocall_print((char*) val);
    
}

extern "C" void P_PrintKey_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_UINT64 val = (*P_VAR_payload)->valueUnion.frgn->value;
    ocall_print("FOREIGN PRINT KEY IS:");
    printRSAKey((char*) val);
    
}
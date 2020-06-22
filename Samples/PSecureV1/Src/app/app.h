#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <unordered_map> 
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

char* itoa(int num, char* str, int base);
int atoi(char *p);
void reverse(char str[], int length);

//NOTE all typedefs are also defined in enclave.cpp and constants.cpp
typedef tuple <string,string> PublicMachineChildPair; //parentMachineID, childPublicKey
typedef tuple <string,string> identityKeyPair; //public, private
typedef tuple <uint32_t,string> PMachineChildPair; //parentMachineID, childPublicKey

extern char* KPS_CERT_LOCATION;
extern char* KPS_CERT_KEYS_LOCATION;
extern bool isKpsProcess;

extern char* DST_HOST_CERT_LOCATION;
extern char* DST_HOST_CERT_KEYS_LOCATION;

void initApp();

void start_socket_network_handler();

void start_socket_attestation_network_handler();

void start_socket_kps_generic_network_handler();

int handle_incoming_event(PRT_UINT32 eventIdentifier, PRT_MACHINEID receivingMachinePID, int numArgs, int payloadType, char* payload, int payloadSize);
char* serializePrtValueToString(PRT_VALUE* value, int& final_size);

void generateIdentity(string& publicID, string& privateID, string prefix, string& publicIDSigningKey, string& privateIDSigningKey);

char* receiveNetworkRequest(char* request, size_t requestSize);

void startPrtProcessIfNotStarted();

int getNextPID();

string createString(char* str);

int createPMachine(char* machineType, int numArgs, int payloadType, char* payload, int payloadSize);

int machineTypeIsSecure(char* machineType);

char* createUSMMachineAPI(char* machineType, int numArgs, int payloadType, char* payload, int payloadSize);

char* generateCStringFromFormat(char* format_string, char* strings_to_print[], int num_strings);

char* USMinitializeCommunicationAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* newSessionKey);

void generateSessionKey(string& newSessionKey);

char* USMSendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response);

char* USMSendUnencryptedMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response);

PRT_VALUE* sendCreateMachineNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* createTypeCommand, bool isSecureCreate);

extern "C" PRT_VALUE* P_UntrustedCreateRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

extern "C" PRT_VALUE* P_CreateSecureMachineRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

char* receiveNetworkRequestHelper(char* request, size_t requestSize, bool isEnclaveUntrustedHost);

void parseIPAddressPortString(char* serializedString, string& ipAddress, int& port);

void safe_free(void* ptr);

char* concatMutipleStringsWithLength(char* strings_to_concat[], int lengths[], int size_array);
int returnTotalSizeofLengthArray(int lengths[], int size);
void printRSAKey(char* key);

extern void initKPS();
extern void addRegisteredMachineToKPS(char* machineName, char* machineAddress);
void printPayload(char* payload, int size);

char* createStringLiteralMalloced(char* stringLiteral);

void sendSendNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* sendTypeCommand, bool isSecureSend, bool isEnclave);
void decryptAndSendInternalMessageHelper(char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response, bool isSecureSend);
void sendInternalMessageHelper(char* requestingMachineIDKey, char* receivingMachineIDKey, char* iv, char* mac, char* encryptedMessage, char* response, bool isSecureSend);
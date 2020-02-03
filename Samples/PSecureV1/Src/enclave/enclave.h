#include "enclave_t.h"
#include "string.h"
#include <string>
#include <tuple>
#include <unordered_map> 
#include <map> 
#include <list> 
#include "constants.h"
#include "sgx_tcrypto.h"
#include "sgx_trts.h"
using namespace std;

extern sgx_enclave_id_t current_eid;


//For Enclave Internal Methods
typedef tuple <uint32_t,string> PMachineChildPair; //parentMachineID, childPublicKey
typedef tuple <string,string> PublicMachineChildPair; //parentMachineID, childPublicKey
extern map<PMachineChildPair, string> PMachineToChildCapabilityKey;
extern map<PublicMachineChildPair, string> PublicIdentityKeyToChildSessionKey;



//NOTE all typedefs are also defined in app.cpp and constants.cpp
//For Enclave API
typedef tuple <string,string> capabilityKey;
typedef tuple <string,string> identityKeyPair; //public, private
extern unordered_map<int, identityKeyPair> MachinePIDToIdentityDictionary;
extern unordered_map<string, int> PublicIdentityKeyToMachinePIDDictionary;
extern unordered_map<int, string> MachinePIDtoCapabilityKeyDictionary;
extern uint8_t g_secret[SIZE_OF_MESSAGE];



void startPrtProcessIfNotStarted();
char* createMachineHelper(char* machineType, char* parentTrustedMachinePublicIDKey, int numArgs, int payloadType, char* payload, int payloadSize, bool isSecureCreate,sgx_enclave_id_t enclaveEid);
int handle_incoming_events_pong_enclave(PRT_UINT32 eventIdentifier);
int handle_incoming_event(PRT_UINT32 eventIdentifier, PRT_MACHINEID receivingMachinePID, int numArgs, int payloadType, char* payload, int payloadSize);
void generateIdentityDebug(string& publicID, string& privateID, string prefix);
void generateIdentity(sgx_rsa3072_public_key_t *public_key, sgx_rsa3072_key_t *private_key, void** publicIdentity, void** privateIdentity);
string createString(char* str);
char* itoa(int num, char* str, int base);
PRT_VALUE* sendCreateMachineNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* createTypeCommand, bool isSecureCreate);
int createMachine(char* machineType, int numArgs, int payloadType, char* payload, int payloadSize);
char* receiveNewCapabilityKeyFromKPS(char* parentTrustedMachineID, char* newMachinePublicIDKey);
char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey);
void sendSendNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* sendTypeCommand, bool isSecureSend);
void generateSessionKey(string& newSessionKey);

int machineTypeIsSecure(char* machineType);

int getNextPID();

void safe_free(void* ptr);

int sendMessageAPI(char* requestingMachineIDKey, char* receivingMachineIDKey, char* event, int numArgs, int payloadType, char* payload, int payloadSize);

char* registerMachineWithNetwork(char* newMachineID);
int sendMessageHelper(char* requestingMachineIDKey, char* receivingMachineIDKey, char* event, int numArgs, int payloadType, char* payload, int payloadSize);

char* generateCStringFromFormat(char* format_string, char** strings_to_print, int num_strings);

char* serializePrtValueToString(PRT_VALUE* value, int& final_size);
extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

char* concatVoid(void* str1, size_t str1_size, void* str2, size_t str2_size);
char* concatMutipleStringsWithLength(char* strings_to_concat[], int lengths[], int size_array);
int returnTotalSizeofLengthArray(int lengths[], int size);
void printRSAKey(char* key);
void printPublicCapabilityKey(char* key);
void printPrivateCapabilityKey(char* key);
void createRsaKeyPair(sgx_rsa3072_public_key_t *public_key ,sgx_rsa3072_key_t *private_key, void** public_key_raw, void** private_key_raw);
char* retrievePublicCapabilityKey(char* capabilityPayload);
char* retrievePrivateCapabilityKey(char* capabilityPayload);
void printPayload(char* payload, int size);
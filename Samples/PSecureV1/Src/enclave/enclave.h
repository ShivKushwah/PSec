#include "PingPongEnclave.h"
#include "enclave_t.h"
#include "string.h"
#include <string>
#include <tuple>
#include <unordered_map> 
#include <map> 
#include <list> 
#include "constants.h"
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
char* createMachineHelper(char* machineType, char* parentTrustedMachinePublicIDKey, int numArgs, int payloadType, char* payload, bool isSecureCreate,sgx_enclave_id_t enclaveEid);
int handle_incoming_events_pong_enclave(PRT_UINT32 eventIdentifier);
int handle_incoming_event(PRT_UINT32 eventIdentifier, PRT_MACHINEID receivingMachinePID, int numArgs, int payloadType, char* payload);
void generateIdentity(string& publicID, string& privateID, string prefix);
string createString(char* str);
char* itoa(int num, char* str, int base);
PRT_VALUE* sendCreateMachineNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* createTypeCommand, bool isSecureCreate);
int createMachine(char* machineType, int numArgs, int payloadType, char* payload);
char* receiveNewCapabilityKeyFromKPS(char* parentTrustedMachineID, char* newMachinePublicIDKey);
char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey);
void sendSendNetworkRequest(PRT_MACHINEINST* context, PRT_VALUE*** argRefs, char* sendTypeCommand, bool isSecureSend);
void generateSessionKey(string& newSessionKey);

int machineTypeIsSecure(char* machineType);

int getNextPID();

char* registerMachineWithNetwork(char* newMachineID);
int sendMessageHelper(char* requestingMachineIDKey, char* receivingMachineIDKey, char* event, int numArgs, int payloadType, char* payload);

char* generateCStringFromFormat(char* format_string, char** strings_to_print, int num_strings);

char* serializePrtValueToString(PRT_VALUE* value);
PRT_VALUE** deserializeStringToPrtValue(int numArgs, char* str, int payloadType);
extern "C" PRT_VALUE* P_UntrustedCreateCoordinator_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern "C" PRT_VALUE* P_CreateMachineSecureChild_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
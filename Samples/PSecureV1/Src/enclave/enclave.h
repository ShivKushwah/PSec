#include "PingPongEnclave.h"
#include "enclave_t.h"
#include "string.h"
#include <string>
#include <tuple>
#include <unordered_map> 
#include <map> 
#include <list> 
using namespace std;

//NOTE: If modifying these constants, search for these in other header files too
const int SIZE_OF_MESSAGE = 20;
const int SIZE_OF_IDENTITY_STRING = 20;
const int SIZE_OF_CAPABILITYKEY = 20;
const int SIZE_OF_NEWMACHINETYPE = 20;
const int SIZE_OF_SESSION_KEY = 20;
const int SIZE_OF_MAX_MESSAGE = 20;

const int SIZE_OF_MAX_EVENT_NAME = 20;
const int SIZE_OF_MAX_EVENT_PAYLOAD = 100;




const int CREATE_CAPABILITY_KEY_CONSTANT = 1;
const int RETRIEVE_CAPABLITY_KEY_CONSTANT = 2;

//For Enclave Internal Methods
typedef tuple <uint32_t,string> PMachineChildPair; //parentMachineID, childPublicKey
typedef tuple <string,string> PublicMachineChildPair; //parentMachineID, childPublicKey
extern map<PMachineChildPair, string> PMachineToChildCapabilityKey;
extern map<PublicMachineChildPair, string> PublicIdentityKeyToChildSessionKey;



//For Enclave API
typedef tuple <string,string> identityKeyPair; //public, private
typedef tuple <string,string> capabilityKey;
extern unordered_map<int, identityKeyPair> MachinePIDToIdentityDictionary;
extern unordered_map<string, int> PublicIdentityKeyToMachinePIDDictionary;
extern unordered_map<int, string> MachinePIDtoCapabilityKeyDictionary;
extern uint8_t g_secret[SIZE_OF_MESSAGE];





int handle_incoming_events_pong_enclave(PRT_UINT32 eventIdentifier);
void generateIdentity(string& publicID, string& privateID);
char* itoa(int num, char* str, int base);
int createMachine(char* machineType, char* parentTrustedMachineID, int numArgs, int payloadType, char* payload);
char* receiveNewCapabilityKeyFromKPS(char* parentTrustedMachineID, char* newMachinePublicIDKey);
char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey);

void generateSessionKey(string& newSessionKey);

int machineTypeIsSecure(char* machineType);

int getNextPID();

char* registerMachineWithNetwork(char* newMachineID);

char* generateCStringFromFormat(char* format_string, char** strings_to_print, int num_strings);

char* serializePrtValueToString(PRT_VALUE* value);
PRT_VALUE** deserializeStringToPrtValue(int numArgs, char* str, int payloadType);
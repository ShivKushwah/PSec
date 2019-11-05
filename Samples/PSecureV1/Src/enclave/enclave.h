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

const int CREATE_CAPABILITY_KEY_CONSTANT = 1;
const int RETRIEVE_CAPABLITY_KEY_CONSTANT = 2;

//For Enclave Internal Methods
typedef tuple <uint32_t,string> PMachineChildPair; //parentMachineID, childPublicKey
extern map<PMachineChildPair, string> PMachineToChildCapabilityKey;


//For Enclave API
typedef tuple <string,string> identityKeyPair;
typedef tuple <string,string> capabilityKey;
extern unordered_map<int, identityKeyPair> MachinePIDToIdentityDictionary;
extern unordered_map<string, int> PublicIdentityKeyToMachinePIDDictionary;
extern unordered_map<int, string> MachinePIDtoCapabilityKeyDictionary;
extern uint8_t g_secret[SIZE_OF_MESSAGE];



int handle_incoming_events_pong_enclave(PRT_UINT32 eventIdentifier);
void generateIdentity(string& publicID, string& privateID);
char* itoa(int num, char* str, int base);
int createMachine(char* machineType, char* parentTrustedMachineID);
char* receiveNewCapabilityKeyFromKPS();
char* retrieveCapabilityKeyForChildFromKPS(char* currentMachinePublicIDKey, char* childPublicIDKey);
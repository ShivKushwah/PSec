#include "PingPongEnclave.h"
#include "enclave_t.h"
#include "string.h"
#include <string>
#include <tuple>
#include <unordered_map> 
#include <list> 
using namespace std;

//NOTE: If modifying these constants, search for these in other header files too
const int SIZE_OF_MESSAGE = 20;
const int SIZE_OF_IDENTITY_STRING = 20;
const int SIZE_OF_CAPABILITYKEY = 20;

typedef tuple <string,string> identityKeyPair;
typedef tuple <string,string> capabilityKey;

extern unordered_map<int, identityKeyPair> PMachineIDToIdentityDictionary;
extern unordered_map<string, int> PublicIdentityKeyToPMachineIDDictionary;
extern unordered_map<int, string> PMachineIDtoCapabilityKeyDictionary;
extern uint8_t g_secret[SIZE_OF_MESSAGE];



int handle_incoming_events_pong_enclave(PRT_UINT32 eventIdentifier);
void generateIdentity(string& publicID, string& privateID);
char* itoa(int num, char* str, int base);
int createMachine(char* machineType, char* untrustedHostID, char* parentTrustedMachineID);
char* receiveCapabilityKey();
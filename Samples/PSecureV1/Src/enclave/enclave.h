#include "PingPongEnclave.h"
#include "enclave_t.h"
#include "string.h"
#include <string>
#include <tuple>
#include <unordered_map> 
using namespace std;

const int SIZE_OF_MESSAGE = 20;
const int SIZE_OF_IDENTITY_STRING = 20;

typedef tuple <string,string> identityKeyPair;

extern unordered_map<int, identityKeyPair> identityDictionary;

int handle_incoming_events_pong_enclave(PRT_UINT32 eventIdentifier);
void generateIdentity(string& publicID, string& privateID);
char* itoa(int num, char* str, int base);
int createMachine(char* machineType, char* untrustedHostID, char* parentTrustedMachineID);
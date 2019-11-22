#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "PingPong.h"
#include <unordered_map> 
#include <map>

using namespace std;

char* itoa(int num, char* str, int base);
int atoi(char *p);
void reverse(char str[], int length);

int handle_incoming_events_ping_machine(PRT_UINT32 eventIdentifier);
char* serializePrtValueToString(PRT_VALUE* value);

void generateIdentity(string& publicID);
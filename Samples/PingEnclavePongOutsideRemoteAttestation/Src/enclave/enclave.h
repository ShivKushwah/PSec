#include "PingPongEnclave.h"

const int SIZE_OF_MESSAGE = 20;

int handle_incoming_events_pong_enclave(PRT_UINT32 eventIdentifier);
char* itoa(int num, char* str, int base);
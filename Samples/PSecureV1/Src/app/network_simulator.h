#include "constants.h"
#include "network_ra.h"

#define PORT 8080


void* handle_socket_network_request(void* arg);
char* network_socket_sender(char* request, int request_size, int port=PORT);
void printPayload(char* payload, int size);

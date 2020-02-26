#include "constants.h"
#include "network_ra.h"

#define PORT 8080
#define PORT_ATTESTATION 8090


void* handle_socket_network_request(void* arg);
void* handle_socket_network_request_attestation(void* arg);
char* network_socket_sender(char* request, int request_size, int port=PORT);
void printPayload(char* payload, int size);

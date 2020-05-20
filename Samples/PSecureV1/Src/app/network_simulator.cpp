#include "network_simulator.h"
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#define MAX 72400 
#define SA struct sockaddr 

extern int host_machine_port;
extern int KPS_PORT_ATTESTATION;
extern int KPS_PORT_GENERIC;

const int DISTRIBUTED_HOST_READ_REQUEST = 1;
const int KPS_ATTESTATION_READ_REQUEST = 2;
const int KPS_GENERIC_READ_REQUEST = 3;

// Reading Incoming Network Request Handlers *******************

// Function that reads incoming data from the network and forwards it to send_network_request_API and returns the results back over the network
void func(int sockfd, int handle_incoming_request_type) 
{ 
	char buff[MAX]; 
	int n; 
	// infinite loop for chat 
	for (;;) { 
		bzero(buff, MAX); 

		// read the message from client and copy it in buffer 
		int actual_response_size = read(sockfd, buff, sizeof(buff)); 

		if (actual_response_size >= sizeof(buff)) {
			ocall_print("NOTE: Server Network buffer full\n");
		}

		int responseSize;
		char* retString;
		if (handle_incoming_request_type == DISTRIBUTED_HOST_READ_REQUEST) {
			responseSize = 1000; //TODO unhardcode 1000 and have make network request return values that have size associated with them 
			retString = send_network_request_API(buff, actual_response_size);
		} else if (handle_incoming_request_type == KPS_ATTESTATION_READ_REQUEST) {
			retString = handle_socket_attestation_request(buff, responseSize);
			if (responseSize >= MAX) {
				ocall_print("ERROR: Server network buffer overflow\n");
			}
		} else {
			retString = handle_socket_kps_generic_request(buff, responseSize);
			if (responseSize >= MAX) {
				ocall_print("ERROR: Server network buffer overflow\n");
			}
		}


		// print buffer which contains the client contents 
		// ocall_print("From client: %s\t To client : ", buff); 
		bzero(buff, MAX); 
		n = 0; 
		// copy server message in the buffer 
		ocall_print("Server: copying into return buffer\n");
		printPayload(retString, 20);
		ocall_print("Server: about to memcpy\n");
		memcpy(buff, retString, responseSize);  
		

		// and send that buffer to client 
		write(sockfd, buff, responseSize); 

		// if msg contains "Exit" then server exit and chat ended. 
		// if (strncmp("exit", buff, 4) == 0) { 
		// 	ocall_print("Server Exit...\n"); 
		// 	break; 
		// } 
		ocall_print("Server sent message to client!\n");
        break;
	} 
} 

void* server_handle_connection_thread(void* arg) {
	int sockfd = *((int *)arg);
	func(sockfd, DISTRIBUTED_HOST_READ_REQUEST);
	close(sockfd);

}

void* server_handle_attestation_connection_thread(void* arg) {
	int sockfd = *((int *)arg);
	func(sockfd, KPS_ATTESTATION_READ_REQUEST);
	close(sockfd);

}

void* server_handle_kps_generic_connection_thread(void* arg) {
	int sockfd = *((int *)arg);
	func(sockfd, KPS_GENERIC_READ_REQUEST);
	close(sockfd);

}

void handle_socket_helper(void* arg, int handle_incoming_request_type) {
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		ocall_print("Server Socket creation failed...\n"); 
		exit(0); 
	} 
	else
		ocall_print("Server Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	int enable = 1;

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
		ocall_print("server setsockopt(SO_REUSEADDR) failed\n");
	}
    

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 

	if (handle_incoming_request_type == DISTRIBUTED_HOST_READ_REQUEST) {
		servaddr.sin_port = htons(host_machine_port);
	} else if (handle_incoming_request_type == KPS_ATTESTATION_READ_REQUEST) {
		servaddr.sin_port = htons(KPS_PORT_ATTESTATION); 
	} else {
		servaddr.sin_port = htons(KPS_PORT_GENERIC);
	}

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		if (errno == EADDRINUSE) {
			ocall_print("Error: Address already in use!\n");
		}
		ocall_print("Server Socket bind failed...\n"); 
		exit(0); 
	} 
	else
		ocall_print("Server Socket successfully binded..\n"); 

	// -------------------------------------------------------
	
	// int sockfd2, connfd2, len2; 
	// struct sockaddr_in servaddr2, cli2; 

	// // socket create and verification 
	// sockfd2 = socket(AF_INET, SOCK_STREAM, 0); 
	// if (sockfd2 == -1) { 
	// 	ocall_print("socket2 creation failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	ocall_print("Socket2 successfully created..\n"); 
	// bzero(&servaddr2, sizeof(servaddr2)); 

	// // assign IP, PORT 
	// servaddr2.sin_family = AF_INET; 
	// servaddr2.sin_addr.s_addr = htonl(INADDR_ANY); 
	// servaddr2.sin_port = htons(PORT2); 

	// // Binding newly created socket to given IP and verification 
	// if ((bind(sockfd2, (SA*)&servaddr2, sizeof(servaddr2))) != 0) { 
	// 	ocall_print("socket2 bind failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	ocall_print("Socket2 successfully binded..\n");
	
	// -----------------------------

	// Now server is ready to listen and verification 
	if ((listen(sockfd, 5)) != 0) { 
		if (errno == EADDRINUSE) {
			ocall_print("ERROR: Server Address already in use!\n");
		} else if (errno == EBADF) {
			ocall_print("ERROR: Server sockfd is not valid for listen command!\n");

		}
		ocall_print("Server listen failed...\n"); 
		exit(0); 
	} 
	else
		ocall_print("Server listening..\n"); 
	len = sizeof(cli);

    while (1) {
        // Accept the data packet from client and verification 
        connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len); 
        if (connfd < 0) { 
            ocall_print("server acccept failed...\n"); 
            exit(0); 
        } 
        else
            ocall_print("server acccept the client...\n"); 

		pthread_t pid;
		if (handle_incoming_request_type == DISTRIBUTED_HOST_READ_REQUEST) {
			pthread_create(&pid, NULL, server_handle_connection_thread, &connfd);
		} else if (handle_incoming_request_type == KPS_ATTESTATION_READ_REQUEST) {
			pthread_create(&pid, NULL, server_handle_attestation_connection_thread, &connfd); 
		} else {
			pthread_create(&pid, NULL, server_handle_kps_generic_connection_thread, &connfd);
		}

        // After chatting close the socket 
        // close(connfd); 
    }
}

void* handle_socket_network_request(void* arg) 
{ 
	handle_socket_helper(arg, DISTRIBUTED_HOST_READ_REQUEST);
} 
void* handle_socket_network_request_attestation(void* arg) 
{ 
	handle_socket_helper(arg, KPS_ATTESTATION_READ_REQUEST);
} 

void* handle_socket_network_kps_generic_requests(void* arg) 
{ 
	handle_socket_helper(arg, KPS_GENERIC_READ_REQUEST);
} 

//*******************


// Sending Outgoing Network Request Methods *******************

// Function that sends outgoing data across the network to appropiate machine and returns response
void func_sender(int sockfd, char* request, int request_size, char* network_response) 
{ 
	char buff[MAX]; 
	for (;;) { 
		bzero(buff, sizeof(buff)); 
		memcpy(buff, request, request_size);
		write(sockfd, buff, request_size); 
		bzero(buff, sizeof(buff)); 
		read(sockfd, buff, sizeof(buff)); 
		ocall_print("From Server :");
		ocall_print(buff); 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			ocall_print("Client Exit...\n"); 
			break; 
		} 
		break;
	}
	memcpy(network_response, buff, MAX); 
} 

char* network_socket_sender(char* request, int request_size, char* ipAddress, int ipAddressSize, int port) 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli;
	char* network_response = (char*) malloc(MAX); 

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		ocall_print("client socket creation failed...\n"); 
		exit(0); 
	} 
	else
		ocall_print("Client Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	char* ipAddressCopy = (char*) malloc(ipAddressSize + 1);
	memcpy(ipAddressCopy, ipAddress, ipAddressSize);
	ipAddressCopy[ipAddressSize] = '\0';

	ocall_print("Sending Message to IP Address:");
	ocall_print(ipAddressCopy);
	ocall_print("Port:");
	ocall_print_int(port);

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr(ipAddressCopy); 
	servaddr.sin_port = htons(port); 

	//---------------------------
	// int sockfd2, connfd2; 
	// struct sockaddr_in servaddr2, cli2; 

	// // socket create and varification 
	// sockfd2 = socket(AF_INET, SOCK_STREAM, 0); 
	// if (sockfd2 == -1) { 
	// 	ocall_print("socket2 creation failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	ocall_print("Socket2 successfully created..\n"); 
	// bzero(&servaddr2, sizeof(servaddr2)); 

	// // assign IP, PORT 
	// servaddr2.sin_family = AF_INET; 
	// servaddr2.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	// servaddr2.sin_port = htons(PORT2); 
	//--------------------

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		ocall_print("client connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		ocall_print("client connected to the server..\n"); 

	// function for chat 
	func_sender(sockfd, request, request_size, network_response); 

	// close the socket 
	close(sockfd); 

	return network_response;
} 
//*******************
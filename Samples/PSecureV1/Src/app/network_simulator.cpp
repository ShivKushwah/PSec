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

// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
	char buff[MAX]; 
	int n; 
	// infinite loop for chat 
	for (;;) { 
		bzero(buff, MAX); 

		// read the message from client and copy it in buffer 
		int actual_response_size = read(sockfd, buff, sizeof(buff)); 

		if (actual_response_size >= sizeof(buff)) {
			printf("NOTE: Server Network buffer full\n");
		}

		char* retString = send_network_request_API(buff, actual_response_size);
		// char* retString = "netreceive";


		// print buffer which contains the client contents 
		// printf("From client: %s\t To client : ", buff); 
		bzero(buff, MAX); 
		n = 0; 
		// copy server message in the buffer 
		printf("Server: copying into return buffer\n");
		printPayload(retString, 20);
		printf("Server: about to memcpy\n");
		memcpy(buff, retString, 1000);  //TODO unhardcode 1000 and have make network request
										//return values have size assoicated with them 
		

		// and send that buffer to client 
		write(sockfd, buff, sizeof(buff)); 

		// if msg contains "Exit" then server exit and chat ended. 
		// if (strncmp("exit", buff, 4) == 0) { 
		// 	printf("Server Exit...\n"); 
		// 	break; 
		// } 
		printf("Server sent message to client!\n");
        break;
	} 
} 

// Function designed for chat between client and server. 
void func_attestation(int sockfd) 
{ 
	char buff[MAX]; 
	int n; 
	// infinite loop for chat 
	for (;;) { 
		bzero(buff, MAX); 

		// read the message from client and copy it in buffer 
		int actual_response_size = read(sockfd, buff, sizeof(buff)); 

		if (actual_response_size >= sizeof(buff)) {
			printf("NOTE: Server Network buffer full\n");
		}
		
		int responseSize;
		char* retString = handle_socket_attestation_request(buff, responseSize);
		// char* retString = "netreceive";

		if (responseSize >= MAX) {
			printf("ERROR: Server network buffer overflow\n");
		}


		// print buffer which contains the client contents 
		// printf("From client: %s\t To client : ", buff); 
		bzero(buff, MAX); 
		n = 0; 
		// copy server message in the buffer 
		printf("Server: copying into return buffer\n");
		printPayload(retString, 20);
		printf("Server: about to memcpy\n");
		memcpy(buff, retString, responseSize);  //TODO unhardcode 1000 and have make network request
										//return values have size assoicated with them 
		

		// and send that buffer to client 
		write(sockfd, buff, responseSize); 

		// if msg contains "Exit" then server exit and chat ended. 
		// if (strncmp("exit", buff, 4) == 0) { 
		// 	printf("Server Exit...\n"); 
		// 	break; 
		// } 
		printf("Server sent message to client!\n");
        break;
	} 
} 

// Function designed for chat between client and server. 
void func_kps_generic(int sockfd) 
{ 
	char buff[MAX]; 
	int n; 
	// infinite loop for chat 
	for (;;) { 
		bzero(buff, MAX); 

		// read the message from client and copy it in buffer 
		int actual_response_size = read(sockfd, buff, sizeof(buff)); 

		if (actual_response_size >= sizeof(buff)) {
			printf("NOTE: Server Network buffer full\n");
		}
		
		int responseSize;
		char* retString = handle_socket_kps_generic_request(buff, responseSize);
		// char* retString = "netreceive";

		if (responseSize >= MAX) {
			printf("ERROR: Server network buffer overflow\n");
		}


		// print buffer which contains the client contents 
		// printf("From client: %s\t To client : ", buff); 
		bzero(buff, MAX); 
		n = 0; 
		// copy server message in the buffer 
		printf("Server: copying into return buffer\n");
		printPayload(retString, 20);
		printf("Server: about to memcpy\n");
		memcpy(buff, retString, responseSize);  //TODO unhardcode 1000 and have make network request
										//return values have size assoicated with them 
		

		// and send that buffer to client 
		write(sockfd, buff, responseSize); 

		// if msg contains "Exit" then server exit and chat ended. 
		// if (strncmp("exit", buff, 4) == 0) { 
		// 	printf("Server Exit...\n"); 
		// 	break; 
		// } 
		printf("Server sent message to client!\n");
        break;
	} 
} 

void* server_handle_connection_thread(void* arg) {
	int sockfd = *((int *)arg);
	func(sockfd);
	close(sockfd);

}

void* server_handle_attestation_connection_thread(void* arg) {
	int sockfd = *((int *)arg);
	func_attestation(sockfd);
	close(sockfd);

}

void* server_handle_kps_generic_connection_thread(void* arg) {
	int sockfd = *((int *)arg);
	func_kps_generic(sockfd);
	close(sockfd);

}

// Driver function 
void* handle_socket_network_request(void* arg) 
{ 
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("Server Socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	int enable = 1;

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
		printf("server setsockopt(SO_REUSEADDR) failed\n");
	}
    

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	int port = host_machine_port;

	servaddr.sin_port = htons(port); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		if (errno == EADDRINUSE) {
			printf("Error: Address already in use!\n");
		}
		printf("Server Socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server Socket successfully binded..\n"); 

	// -------------------------------------------------------
	
	// int sockfd2, connfd2, len2; 
	// struct sockaddr_in servaddr2, cli2; 

	// // socket create and verification 
	// sockfd2 = socket(AF_INET, SOCK_STREAM, 0); 
	// if (sockfd2 == -1) { 
	// 	printf("socket2 creation failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	printf("Socket2 successfully created..\n"); 
	// bzero(&servaddr2, sizeof(servaddr2)); 

	// // assign IP, PORT 
	// servaddr2.sin_family = AF_INET; 
	// servaddr2.sin_addr.s_addr = htonl(INADDR_ANY); 
	// servaddr2.sin_port = htons(PORT2); 

	// // Binding newly created socket to given IP and verification 
	// if ((bind(sockfd2, (SA*)&servaddr2, sizeof(servaddr2))) != 0) { 
	// 	printf("socket2 bind failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	printf("Socket2 successfully binded..\n");
	
	// -----------------------------

	// Now server is ready to listen and verification 
	if ((listen(sockfd, 5)) != 0) { 
		if (errno == EADDRINUSE) {
			printf("ERROR: Server Address already in use!\n");
		} else if (errno == EBADF) {
			printf("ERROR: Server sockfd is not valid for listen command!\n");

		}
		printf("Server listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli);

    while (1) {
        // Accept the data packet from client and verification 
        connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len); 
        if (connfd < 0) { 
            printf("server acccept failed...\n"); 
            exit(0); 
        } 
        else
            printf("server acccept the client...\n"); 

		pthread_t pid;
		pthread_create(&pid, NULL, server_handle_connection_thread, &connfd);

        // Function for chatting between client and server 
        // func(connfd); 

        // After chatting close the socket 
        // close(connfd); 
    }
	
} 
// Driver function 
void* handle_socket_network_request_attestation(void* arg) 
{ 
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("Server Socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	int enable = 1;

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
		printf("server setsockopt(SO_REUSEADDR) failed\n");
	}
    

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(KPS_PORT_ATTESTATION); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		if (errno == EADDRINUSE) {
			printf("Error: Address already in use!\n");
		}
		printf("Server Socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server Socket successfully binded..\n"); 

	// -------------------------------------------------------
	
	// int sockfd2, connfd2, len2; 
	// struct sockaddr_in servaddr2, cli2; 

	// // socket create and verification 
	// sockfd2 = socket(AF_INET, SOCK_STREAM, 0); 
	// if (sockfd2 == -1) { 
	// 	printf("socket2 creation failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	printf("Socket2 successfully created..\n"); 
	// bzero(&servaddr2, sizeof(servaddr2)); 

	// // assign IP, PORT 
	// servaddr2.sin_family = AF_INET; 
	// servaddr2.sin_addr.s_addr = htonl(INADDR_ANY); 
	// servaddr2.sin_port = htons(PORT2); 

	// // Binding newly created socket to given IP and verification 
	// if ((bind(sockfd2, (SA*)&servaddr2, sizeof(servaddr2))) != 0) { 
	// 	printf("socket2 bind failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	printf("Socket2 successfully binded..\n");
	
	// -----------------------------

	// Now server is ready to listen and verification 
	if ((listen(sockfd, 5)) != 0) { 
		if (errno == EADDRINUSE) {
			printf("ERROR: Server Address already in use!\n");
		} else if (errno == EBADF) {
			printf("ERROR: Server sockfd is not valid for listen command!\n");

		}
		printf("Server listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli);

    while (1) {
        // Accept the data packet from client and verification 
        connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len); 
        if (connfd < 0) { 
            printf("server acccept failed...\n"); 
            exit(0); 
        } 
        else
            printf("server acccept the client...\n"); 

		pthread_t pid;
		pthread_create(&pid, NULL, server_handle_attestation_connection_thread, &connfd);

        // Function for chatting between client and server 
        // func(connfd); 

        // After chatting close the socket 
        // close(connfd); 
    }
	
} 

// Driver function 
void* handle_socket_network_kps_generic_requests(void* arg) 
{ 
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("Server Socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	int enable = 1;

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
		printf("server setsockopt(SO_REUSEADDR) failed\n");
	}
    

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(KPS_PORT_GENERIC); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		if (errno == EADDRINUSE) {
			printf("Error: Address already in use!\n");
		}
		printf("Server Socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server Socket successfully binded..\n"); 

	// Now server is ready to listen and verification 
	if ((listen(sockfd, 5)) != 0) { 
		if (errno == EADDRINUSE) {
			printf("ERROR: Server Address already in use!\n");
		} else if (errno == EBADF) {
			printf("ERROR: Server sockfd is not valid for listen command!\n");

		}
		printf("Server listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli);

    while (1) {
        // Accept the data packet from client and verification 
        connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len); 
        if (connfd < 0) { 
            printf("server acccept failed...\n"); 
            exit(0); 
        } 
        else
            printf("server acccept the client...\n"); 

		pthread_t pid;
		pthread_create(&pid, NULL, server_handle_kps_generic_connection_thread, &connfd);

        // Function for chatting between client and server 
        // func(connfd); 

        // After chatting close the socket 
        // close(connfd); 
    }
	
} 


void func_sender(int sockfd, char* request, int request_size, char* network_response) 
{ 
	char buff[MAX]; 
	int n; 
	for (;;) { 
		bzero(buff, sizeof(buff)); 
		memcpy(buff, request, request_size);
		// printf("Enter the string : "); 
		n = 0; 
		// while ((buff[n++] = getchar()) != '\n') 
		// 	; 
		write(sockfd, buff, request_size); 
		bzero(buff, sizeof(buff)); 
		read(sockfd, buff, sizeof(buff)); 
		printf("From Server : %s\n", buff); 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("Client Exit...\n"); 
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
		printf("client socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Client Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	char* ipAddressCopy = (char*) malloc(ipAddressSize + 1);
	memcpy(ipAddressCopy, ipAddress, ipAddressSize);
	ipAddressCopy[ipAddressSize] = '\0';

	printf("Sending Message to IP Address:\n");
	printf("%s\n", ipAddressCopy);
	printf("Port:\n");
	printf("%d\n", port);

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
	// 	printf("socket2 creation failed...\n"); 
	// 	exit(0); 
	// } 
	// else
	// 	printf("Socket2 successfully created..\n"); 
	// bzero(&servaddr2, sizeof(servaddr2)); 

	// // assign IP, PORT 
	// servaddr2.sin_family = AF_INET; 
	// servaddr2.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	// servaddr2.sin_port = htons(PORT2); 
	//--------------------

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("client connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("client connected to the server..\n"); 

	// function for chat 
	func_sender(sockfd, request, request_size, network_response); 

	// close the socket 
	close(sockfd); 

	return network_response;
} 

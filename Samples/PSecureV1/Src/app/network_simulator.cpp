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
#include <resolv.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <libgen.h>
#include <fcntl.h>  
#define FAIL -1
#define MAX 72400 
#define SA struct sockaddr 

extern int host_machine_port;
extern int KPS_PORT_ATTESTATION;
extern int KPS_PORT_GENERIC;

const int DISTRIBUTED_HOST_READ_REQUEST = 1;
const int KPS_ATTESTATION_READ_REQUEST = 2;
const int KPS_GENERIC_READ_REQUEST = 3;

//TLS 1.2 Helper functions with OpenSSL
SSL_CTX* InitCTX(void)
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;
    OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
    SSL_load_error_strings();   /* Bring in and register error messages */
    method = TLSv1_2_client_method();  /* Create new client-method instance */
    ctx = SSL_CTX_new(method);   /* Create new context */
    if ( ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}
SSL_CTX* InitServerCTX(void)
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;
    OpenSSL_add_all_algorithms();  /* load & register all cryptos, etc. */
    SSL_load_error_strings();   /* load all error messages */
    method = TLSv1_2_server_method();  /* create new server-method instance */
    ctx = SSL_CTX_new(method);   /* create new context from method */
    if ( ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}
bool validateServerCertIsSignedByKPS(SSL* ssl) {
	X509 *cert;
    char *line;
    cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */
	if (cert != NULL) {
		ocall_print("Checking Server cert is signed by KPS\n");
		char* curr_directory = (char*) malloc(200);
		getcwd(curr_directory, 200);
		// ocall_enclave_print("cur dir is");
		// ocall_enclave_print(curr_directory);
		// ocall_enclave_print("parent dir is");
		// ocall_enclave_print(dirname(curr_directory));
		// ocall_enclave_print("cur dir is");
		// ocall_enclave_print(dirname(dirname(curr_directory)));
		char* root_dir = dirname(dirname(dirname(curr_directory)));
		char* localTLSCertLocation = "/keys/TLSCertReceived.pem";
		char* TLSCertLocation = (char*) malloc(200);
		strcpy(TLSCertLocation, root_dir);
		strcat(TLSCertLocation, localTLSCertLocation);
		// ocall_enclave_print(TLSCertLocation);
		FILE * pFile;
  		pFile = fopen (TLSCertLocation,"w");
		PEM_write_X509(pFile, cert);
		fclose(pFile); 
		free(curr_directory);

		// system("openssl verify -CAfile /home/shiv/Research/PSec/KPS.pem /home/shiv/Research/PSec/TLSCertReceived.pem > temp.txt");
		char* cmdFormat = "openssl verify -CAfile %s %s";
		char cmd[200];
		sprintf(cmd, cmdFormat, KPS_CERT_LOCATION, TLSCertLocation);
		free(TLSCertLocation);
		char buf[200];
		FILE *fp;

		if ((fp = popen(cmd, "r")) == NULL) {
			ocall_print("Error: Error opening pipe for openssl system command!\n");
			return false;
		}
		bool success;

		while (fgets(buf, 200, fp) != NULL) {
			// if (strcmp(buf + strlen(buf) - 3, "OK") == 0) {
			if (buf[strlen(buf) - 3] == 'O' && buf[strlen(buf) - 2] == 'K') {
				ocall_print("Server certificate validated!\n");
				success = true;
			} else {
				ocall_print("Error: server certificate invalid!");
				success = false;
			}
		}

		if(pclose(fp))  {
			ocall_print("Error: Openssl Command not found or exited with error status\n");
			return false;
		}

		return success;


		// system("openssl verify -CAfile KPS.pem TLSCertReceived.pem");
		// X509_STORE *s = X509_STORE_new();
		// int num = sk_X509_num(sk);
		// X509 *top = sk_X509_value(st, num-1);
		// X509_STORE_add_cert(s, top);
		// X509_STORE_CTX *ctx = X509_STORE_CTX_new();
		// X509_STORE_CTX_init(ctx, s, cert, st);
		// int rc = X509_verify_cert(ctx);
		// if (rc == 1) {
		// 	// validated OK. either trusted or self signed.
		// } else {
		// 	// validation failed
		// 	int err = X509_STORE_CTX_get_error(ctx);
		// }
	} else {
		return false;
	}
}
void ShowCerts(SSL* ssl)
{
    X509 *cert;
    char *line;
    cert = SSL_get_peer_certificate(ssl); /* get the server's certificate */
    if ( cert != NULL )
    {
        ocall_print("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        ocall_print("Subject:");
		ocall_print(line);
        free(line);       /* free the malloc'ed string */
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        ocall_print("Issuer:");
		ocall_print(line);
        free(line);       /* free the malloc'ed string */
        X509_free(cert);     /* free the malloc'ed certificate copy */
    }
    else
        ocall_print("Info: No client certificates configured.\n");
}

void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile)
{
    /* set the local certificate from CertFile */
    if ( SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* set the private key from KeyFile (may be the same as CertFile) */
    if ( SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0 )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    /* verify private key */
    if ( !SSL_CTX_check_private_key(ctx) )
    {
		ocall_print("ERROR: Private key issues in TLS connection");
        fprintf(stderr, "Private key does not match the public certificate\n");
        abort();
    }
}

// Reading Incoming Network Request Handlers *******************

// Function that reads incoming data from the network and forwards it to send_network_request_API and returns the results back over the network
void func(SSL* ssl, int handle_incoming_request_type) 
{ 
	if ( SSL_accept(ssl) == FAIL )     /* do SSL-protocol accept */
        ERR_print_errors_fp(stderr);
    else
    {
		ShowCerts(ssl);        /* get any certificates */
		char buff[MAX]; 
		int n; 
		// infinite loop for chat 
		for (;;) { 
			bzero(buff, MAX); 

			// read the message from client and copy it in buffer 
			// int actual_response_size = read(sockfd, buff, sizeof(buff)); 
			int actual_response_size = SSL_read(ssl, buff, sizeof(buff)); /* get request */

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
			// write(sockfd, buff, responseSize); 
			SSL_write(ssl, buff, responseSize);			

			// if msg contains "Exit" then server exit and chat ended. 
			// if (strncmp("exit", buff, 4) == 0) { 
			// 	ocall_print("Server Exit...\n"); 
			// 	break; 
			// } 
			ocall_print("Server sent message to client!\n");
			break;
		} 
	}
} 

void* server_handle_connection_thread(void* arg) {
	SSL* ssl = (SSL*) arg;
	func(ssl, DISTRIBUTED_HOST_READ_REQUEST);
	int sd = SSL_get_fd(ssl);       /* get socket connection */
    SSL_free(ssl);         /* release SSL state */
    close(sd);          /* close connection */

}

void* server_handle_attestation_connection_thread(void* arg) {
	SSL* ssl = (SSL*) arg;
	func(ssl, KPS_ATTESTATION_READ_REQUEST);
	int sd = SSL_get_fd(ssl);       /* get socket connection */
    SSL_free(ssl);         /* release SSL state */
    close(sd);          /* close connection */

}

void* server_handle_kps_generic_connection_thread(void* arg) {
	SSL* ssl = (SSL*) arg;
	func(ssl, KPS_GENERIC_READ_REQUEST);
	int sd = SSL_get_fd(ssl);       /* get socket connection */
    SSL_free(ssl);         /* release SSL state */
    close(sd);          /* close connection */

}

void handle_socket_helper(void* arg, int handle_incoming_request_type) {
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli;
	SSL_CTX *ctx;
 
	SSL_library_init();
    ctx = InitServerCTX();        /* initialize SSL */
	if (isKpsProcess) {
		LoadCertificates(ctx, KPS_CERT_LOCATION, KPS_CERT_KEYS_LOCATION); /* load certs */
	} else {
		LoadCertificates(ctx, DST_HOST_CERT_LOCATION, DST_HOST_CERT_KEYS_LOCATION); /* load certs */
	}

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		ocall_print("Error: Server Socket creation failed...\n"); 
		exit(0); 
	} 
	else
		ocall_print("Server Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	int enable = 1;

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
		ocall_print("Error: server setsockopt(SO_REUSEADDR) failed\n");
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
		
		SSL *ssl;
		ssl = SSL_new(ctx);              /* get new SSL state with context */
        SSL_set_fd(ssl, connfd);      /* set connection socket to SSL state */ 

		pthread_t pid;
		if (handle_incoming_request_type == DISTRIBUTED_HOST_READ_REQUEST) {
			pthread_create(&pid, NULL, server_handle_connection_thread, ssl);
		} else if (handle_incoming_request_type == KPS_ATTESTATION_READ_REQUEST) {
			pthread_create(&pid, NULL, server_handle_attestation_connection_thread, ssl); 
		} else {
			pthread_create(&pid, NULL, server_handle_kps_generic_connection_thread, ssl);
		}

        // After chatting close the socket 
        // close(connfd); 
    }
	SSL_CTX_free(ctx);         /* release context */
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
void func_sender(int sockfd, char* request, int request_size, char* network_response, SSL* ssl) 
{ 
	char buff[MAX]; 
	for (;;) { 
		bzero(buff, sizeof(buff)); 
		memcpy(buff, request, request_size);
		ocall_print("\n\nConnected with encryption:");
		ocall_print(SSL_get_cipher(ssl));
        ShowCerts(ssl);        /* get any certs */
		if (!validateServerCertIsSignedByKPS(ssl)) {
			return;
		}
        SSL_write(ssl, buff, request_size);   /* encrypt & send message */
		bzero(buff, sizeof(buff)); 
        SSL_read(ssl, buff, sizeof(buff)); /* get reply & decrypt */

		// write(sockfd, buff, request_size); 
		// bzero(buff, sizeof(buff)); 
		// read(sockfd, buff, sizeof(buff)); 
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
	SSL_CTX *ctx;
    SSL *ssl;

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

	int attempts = 0;

	//Retry creating connection 30 times
	while(attempts < 30) {
    	/* Create the client socket */
		sockfd = socket(AF_INET, SOCK_STREAM, 0); 
		if (sockfd == -1) { 
			ocall_print("client socket creation failed...\n"); 
			exit(0); 
		} 
		else
			ocall_print("Client Socket successfully created..\n"); 

		//Connect client to server
		if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) == 0 ) {
			break;
		}

		fprintf(stderr, "Cannot connect to the server. Retrying...");
		fprintf(stderr, " IP Address: ");
		fprintf(stderr, ipAddressCopy);
		fprintf(stderr, " Port: ");
		if (port == 8070) {
		   fprintf(stderr, "8070");
		}
		fprintf(stderr, "\n");
		ocall_print("Cannot connect to the server. Retrying...");
		close(sockfd);
		sleep(1);
		attempts++;
	}
	
	ctx = InitCTX();
	ssl = SSL_new(ctx);      /* create new SSL connection state */
    SSL_set_fd(ssl, sockfd);    /* attach the socket descriptor */
    if ( SSL_connect(ssl) == FAIL )   /* perform the connection */
        ERR_print_errors_fp(stderr);
    else
    {
		// function for chat 
		func_sender(sockfd, request, request_size, network_response, ssl); 
		SSL_free(ssl);        /* release connection state */
		SSL_CTX_free(ctx);        /* release context */
	}

	// close the socket 
	close(sockfd); 

	return network_response;
} 
//*******************
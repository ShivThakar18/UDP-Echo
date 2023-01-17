/*
 * COMP 3271 - Computer Networks
 * Project Part 1 - UDP Time Server - Server Implementation
 * Name: Shiv Thakar
 */

#include <stdio.h>		/* I/O functions */
#include <string.h>		/* string functions */
#include <stdlib.h>		/* C standard functions */
#include <sys/socket.h>	/* socket functions */
#include <sys/types.h>	/* library of basic types */
#include <netinet/in.h>	/* library of Internet address functions */
#include <arpa/inet.h>	/* Internet operations */
#include <time.h>		/* time functions */

#define PORT 9988		/* server port # */

 //port changed according to project requirements 

#define BUFFSIZE 200	/* buffer size */

int main()
{
	int sockfd;
	int addrlen;
	char buffer[BUFFSIZE];
	struct sockaddr_in server;
	struct sockaddr_in client;
	time_t current_time;

	char name[21];
	char message[200] = "";

	/* Populate socket data structures with IP address and port number */
	printf("Populate IP Address and Port Number to Socket\n");
	memset((char*)&server, 0, sizeof(struct sockaddr_in));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);

	/* Create a UDP socket; returns -1 on failure */
	printf("Creating UDP Socket\n");
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) {
		printf("Socket error\n");
		exit(1); /* Exit on error */
	}

	/* Bind the socket address */
	printf("Binding the socket address\n");
	if ((bind(sockfd, (struct sockaddr*)&server, sizeof(struct sockaddr_in))) == -1) {
		printf("Server bind error\n");
		exit(1); /* Exit on error */
	}

	/* Helpful status message */
	printf("Server is listening on port: %d\n", PORT);
	printf("Waiting for client request...\n");
	printf("Press CTRL + C to exit\n");

	while (1) {
		addrlen = sizeof(struct sockaddr_in);
		recvfrom(sockfd, buffer, BUFFSIZE, 0, (struct sockaddr*)&client, (socklen_t*)&addrlen);
		printf("%s\n", buffer);

		strncpy(name, &buffer[9], 21);
		name[21] = '\0';

		strncpy(buffer, &buffer[0], 8);
		buffer[8] = '\0';

		current_time = time(NULL);
		sendto(sockfd, (char*)&current_time, (int)sizeof(current_time), 0, (struct sockaddr*)&client, addrlen);

		printf("Request Processing...\n");

		sendto(sockfd, name, (int)strlen(name), 0, (struct sockaddr*)&client, addrlen);

		recvfrom(sockfd, message, (int)sizeof(message), 0, (struct sockaddr*)&client, (socklen_t*)&addrlen);
		printf("%s\n", message);
	}

	exit(0);

} /* End of time server program */
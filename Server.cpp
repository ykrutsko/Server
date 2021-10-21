#include "Server.h"
#include <fstream>


Server::Server() {
	socketAdress = createSocket();
	bindSocket();
}

const char* Server::hostAdress = "127.0.0.1";
const int Server::portNumber = 1111;

struct sockaddr_in Server::createSocket() {
	// Initializing Winsock
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
	}

	struct sockaddr_in sock;
	sock.sin_family = AF_INET;
	sock.sin_port = htons(portNumber);
	sock.sin_addr.s_addr = INADDR_ANY;
	thisSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (thisSocket < 0) {
		printf("Socket Creation FAILED!\n");
	}
	return sock;
}

void Server::bindSocket() {
	if (bind(thisSocket, (struct sockaddr*)&socketAdress, sizeof(socketAdress)) < 0) {
		printf("\nBinding Socket FAILED!\n");
		if (thisSocket)
			closesocket(thisSocket);
	}
}

void Server::waitConnection() {
	printf("Listening on 1111...\n");
	if (listen(thisSocket, 5) < 0) {
		printf("Listening on Socket FAILED!\n");
		if (thisSocket)
			closesocket(thisSocket);
	}

	struct sockaddr_in clientAddress;
	int clientSize = sizeof(clientAddress);
	thisSocket = accept(thisSocket, (struct sockaddr*)&clientAddress, (int*)&clientSize);
	if (thisSocket < 0) {
		printf("Socket Connection FAILED!\n");
		if (thisSocket)
			closesocket(thisSocket);
	}
	else {
		printf("Client was connected!\n");
	}
}


Server::~Server() {
	closesocket(thisSocket);
	WSACleanup();
}


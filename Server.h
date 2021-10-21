#ifndef SERVER_H
#define SERVER_H

#include <Windows.h>
#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")

class Server {
private:
	static const int portNumber;
	static const char* hostAdress;
	int thisSocket;
	struct sockaddr_in socketAdress;
public:
	Server();
	struct sockaddr_in createSocket();
	void bindSocket();
	void waitConnection();
	~Server();
};

#endif 


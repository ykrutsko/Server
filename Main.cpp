#include "Server.h"

int main(int argc, char* argv[]) {
    Server server;
    server.waitConnection();
    return 0;
}
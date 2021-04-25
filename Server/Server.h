//
// Created by fernando on 8/4/21.
//

#ifndef ADS2_PJ1_SERVER_H
#define ADS2_PJ1_SERVER_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "../Json/json.hpp"

using json = nlohmann::json;


class Server {

public:

    Server();
    void start();

private:
    int socketS;
    int client_Socket;
    int port = 56000;
    int bytes_Received;
    char buffer[4096];
    json info;


};


#endif //ADS2_PJ1_SERVER_H
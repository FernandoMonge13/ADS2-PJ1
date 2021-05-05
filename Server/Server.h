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
#include <fstream>
#include "spdlog/spdlog.h"
#include "../Json/json.hpp"
#include "../Mserver/Mserver.h"

using json = nlohmann::json;

/**
     * @brief It provide us the chance of chance the communication
     */
class Server {

public:

    /*!
     * @brief Constructor
     */
    Server();

    /*!
     * @brief Starts the server related to sockets
     */
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
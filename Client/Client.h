//
// Created by fernando on 8/4/21.
//

#ifndef ADS2_PJ1_CLIENT_H
#define ADS2_PJ1_CLIENT_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fstream>
#include <string.h>
#include <string>

#include "../Json/json.hpp"

using namespace std;
using json = nlohmann::json;

class Client {
public:

    Client();
    void start();
    string communication();
    string construction(string type, string name, string value, string instruction, string access, string size);

private:
    int socketC;
    int port = 56000;
    int connect_Res;
    int send_Res;
    int bytes_Received;
    int counter = 1;
    char buffer[4096];
    json line ;
    bool flag = true;

};


#endif //ADS2_PJ1_CLIENT_H
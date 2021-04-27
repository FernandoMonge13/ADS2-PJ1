//
// Created by fernando on 8/4/21.
//

#include "Client.h"

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;



Client ::Client() {

}

void Client::start() {
    socketC = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    string ip = "127.0.0.1";
    inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);

    // Connect to the server
    connect_Res = connect(socketC, (sockaddr*) &hint, sizeof(hint));

    string userInput = line.dump();

    do {

        send_Res =  send(socketC, userInput.c_str(), userInput.size() + 1, 0);

        if (send_Res == -1){
            cout <<  "Could not send to server! Whoops!\r\n";
            continue;
        }

        memset(buffer, 0, 4096);

        bytes_Received = recv(socketC, buffer, 4096, 0);

        if (bytes_Received == -1){
            cout << "There was an error getting response from server\r\n";
            break;
        }
        else{
            cout << typeid(buffer).name() << endl;
            cout << "SERVER> " << string(buffer, bytes_Received) << "\r\n";
            break;
        }


    } while (true);

    close(socketC);

}

void Client::construction(string type, string name, string value, string instruction, string access, string size) {
    line= {{"Type",  type},
           {"Name",  name},
           {"Value", value},
           {"Instruccion", instruction},
           {"Access", access},
           {"Size", size}};
}
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

ifstream openPort;
string userInput;

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

//    userInput = line.dump();
//
//    do {
//
//        send_Res =  send(socketC, userInput.c_str(), userInput.size() + 1, 0);
//
//        if (send_Res == -1){
//            cout <<  "Could not send to server! Whoops!\r\n";
//            continue;
//        }
//
//        memset(buffer, 0, 4096);
//
//        bytes_Received = recv(socketC, buffer, 4096, 0);
//
//        if (bytes_Received == -1){
//            cout << "There was an error getting response from server\r\n";
//            break;
//        }
//        else{
//            cout << "SERVER> " << string(buffer, bytes_Received) << "\r\n";
//            break;
//        }
//
//
//
//    } while (true);
//
//    close(socketC);

}

void Client::construction(string type, string name, string value, string instruction, string access, string size) {
    line= {{"Type",  type},
           {"Name",  name},
           {"Value", value},
           {"Instruccion", instruction},
           {"Access", access},
           {"Size", size}};

    if (flag){
        start();
        cout << "PASSS0";
        communication();
        flag = false;
    }else{
        communication();

    }


}

void Client::communication(){
    userInput = line.dump();
    send(socketC, userInput.c_str(), userInput.size() + 1, 0);
    recv(socketC, buffer, 4096, 0);
    cout << "SERVER> " << string(buffer, bytes_Received) << "\r\n";

}
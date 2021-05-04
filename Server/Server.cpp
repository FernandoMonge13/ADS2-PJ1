//
// Created by fernando on 8/4/21.
//


#include "Server.h"
#include "../Json/json.hpp"

using namespace std;

Mserver memory = Mserver();
ofstream text;

Server ::Server() {

}

void Server::start() {

    socketS = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);

    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    cout << hint.sin_port << endl;

    text.open("ports.txt");
    text << hint.sin_port;
    text.close();




    bind(socketS, (sockaddr*)&hint, sizeof(hint));

    listen(socketS, SOMAXCONN);

    sockaddr_in client;

    socklen_t clientSize = sizeof(client);

    client_Socket = accept(socketS, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
        cout << host << " connected on port " << service << endl;

    }
    else{
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

//    close(socketS);

    std::string test = "Radio check";
    std::string message;
  //    while (true){
        //memset(buffer, 0, 4096);
    int cont = 0;
    memset(buffer, 0, 4096);
    while (true){
        cout << "Hello" << endl;
        recv(client_Socket, buffer, 4096, 0);
        cout << "Mensaje Recibido" << endl;
        cout << string(buffer);
        message = memory.receive(string(buffer, 0, bytes_Received));
        send(client_Socket, message.c_str(), message.size() + 1 , 0);
        cont++;
        cout << ""<< endl;
        //cout << cont << endl;
        cout << "Mensaje Procesado" << endl;


    }
//        bytes_Received = recv(client_Socket, buffer, 4096, 0);
//
//        if (bytes_Received == -1)
//        {
//            cerr << "Error in recv(). Quitting" << endl;
//            break;
//        }
//
//        if (bytes_Received == 0)
//        {
//            cout << "Client disconnected " << endl;
//            close(client_Socket); // restart server if client closes
//            start();
//            break;
//        }
//
//
//        memory.receive(string(buffer, 0, bytes_Received));
//
//
//    }
    close(client_Socket);

}
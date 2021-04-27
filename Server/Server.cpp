//
// Created by fernando on 8/4/21.
//


#include "Server.h"


using namespace std;

Mserver memory = Mserver();

Server ::Server() {

}

void Server::start() {

    socketS = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

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

    close(socketS);

    while (true){
        memset(buffer, 0, 4096);
        bytes_Received = recv(client_Socket, buffer, 4096, 0);

        if (bytes_Received == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytes_Received == 0)
        {
            cout << "Client disconnected " << endl;
            close(client_Socket); // restart server if client closes
            start();
            break;
        }


        memory.insertion(string(buffer, 0, bytes_Received));


        cout << "Serverrrrr";
        cout << string(buffer, 0, bytes_Received) << endl;

        std:: string s = "BUenos dias";
        // Echo message back to client
        send(client_Socket, s.c_str(), s.size() + 1 , 0);
    }
    close(client_Socket);
}
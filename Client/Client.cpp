//
// Created by fernando on 8/4/21.
//

#include "Client.h"

#include <iostream>
#include <sstream>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

using namespace std;

Client ::Client() {

}

void Client::start(int argc, char *argv[]) {
    if (argc > 1 && *(argv[1]) == '-'){
        exit(1);
    }

    // Socket creation
    socket0 = socket(AF_INET, SOCK_STREAM, 0);
    if (socket0 < 0){
        cerr << "Error: " << strerror(errno) << endl;
        exit(1);
    }

    //Get in to the server IP address.
    struct sockaddr_in server;
    bzero( &server, sizeof(server));

    char* peer_host = "localhost";
    if (argc > 1){
        peer_host = argv[1];
    }

    struct hostent *host = gethostbyname(peer_host);
    if (host == nullptr){
        cerr << "Error: " << strerror(errno) << endl;
        exit(1);
    }

    server.sin_family = AF_INET;
    if (argc >= 3){
        port = (short) atoi(argv[2]);
    }

    server.sin_port = htons(port);

    //Write the ip in to the address structure
    memmove(&(server.sin_addr.s_addr), host->h_addr_list[0], 4);

    // Connect to the server
    association = connect(socket0, (struct sockaddr*) &server, sizeof(server));
    if (association < 0){
        cerr << "Error: " << strerror(errno) << endl;
        exit(1);
    }

    char buffer[1024];
    write(socket0, "Hi from client \r\n", 20);

    for (int i = 0; i < 2; ++i) {
        association = read(socket0, buffer, 1024);
        std::cout << "From server:" << "\n" << buffer;
    }

    buffer[association] = 0;

    close(socket0);

}





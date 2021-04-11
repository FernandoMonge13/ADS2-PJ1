//
// Created by fernando on 8/4/21.
//


#include "Server.h"

#include <iostream>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

Server ::Server() {

}

void Server::start(int argc, char *argv[]) {

    if (argc > 1 && *(argv[1]) == '-'){
        exit(1);
    }

    if (argc > 1){
        port = atoi(argv[0]);
    }

    // Socket creation.
    socket0 = socket(AF_INET, SOCK_STREAM, 0);
    if (socket0 < 0){
        cerr << "Error: " << strerror(errno) << endl;
    }

    // Join to the address
    struct sockaddr_in address;
    memset(&address, 0, sizeof(struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Connect the socket with the address
    association = bind(socket0, (struct sockaddr*) &address, sizeof(address));
    if (association < 0){
        cerr << "Error: " << strerror(errno) << endl;
        exit(1);
    }

    // Socket listening time
    struct linger linger_opt = {1, 0};
    setsockopt(socket0, SOL_SOCKET, SO_LINGER, &linger_opt, sizeof(linger_opt));

    // Wait for connection
    association = listen(socket0, 1);
    if (association < 0){
        cerr << "Error: " << strerror(errno) << endl;
        exit(1);
    }

    // Accept connection
    struct sockaddr_in peer_address;
    socklen_t peer_len;
    socket1 = accept(socket0, (struct sockaddr*) &peer_address, &peer_len);
    if (socket1 < 0){
        cerr << "Error: " << strerror(errno) << endl;
        exit(1);
    }

    char buffer[1024];
    association = read(socket1, buffer, 1024);
    if (association < 0){
        cerr << "Error: " << strerror(errno) << endl;
        exit(1);
    }
    buffer[association] = 0;

    cout << "From client: " << buffer << endl;

    write(socket1,"Hello from server \r\n", 8);

    close(socket1);


}



 //
// Created by fernando on 8/4/21.
//

#ifndef ADS2_PJ1_SERVER_H
#define ADS2_PJ1_SERVER_H


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


};


#endif //ADS2_PJ1_SERVER_H

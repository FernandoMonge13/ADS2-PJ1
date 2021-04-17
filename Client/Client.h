//
// Created by fernando on 8/4/21.
//

#ifndef ADS2_PJ1_CLIENT_H
#define ADS2_PJ1_CLIENT_H


class Client {
public:

    Client();
    void start();

private:
    int socketC;
    int port = 56000;
    int connect_Res;
    int send_Res;
    int bytes_Received;
    char buffer[4096];
};


#endif //ADS2_PJ1_CLIENT_H

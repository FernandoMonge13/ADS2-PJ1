//
// Created by fernando on 8/4/21.
//

#ifndef ADS2_PJ1_CLIENT_H
#define ADS2_PJ1_CLIENT_H


class Client {
public:

    Client();
    void start(int, char *[] );

private:
    int socket0;
    int port = 1234;
    int association;


};


#endif //ADS2_PJ1_CLIENT_H

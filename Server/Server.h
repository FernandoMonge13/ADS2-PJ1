 //
// Created by fernando on 8/4/21.
//

#ifndef ADS2_PJ1_SERVER_H
#define ADS2_PJ1_SERVER_H


class Server {

public:

    Server();
    void start(int, char *[]);

private:
    int port = 1243;
    int socket0;
    int socket1;
    int association;

};


#endif //ADS2_PJ1_SERVER_H

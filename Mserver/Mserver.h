//
// Created by fernando on 25/4/21.
//

#ifndef ADS2_PJ1_MSERVER_H
#define ADS2_PJ1_MSERVER_H

#include "../List/List.h"
//#include "../Json/Json.hpp"


class Mserver {

public:
    void insertion();
    Mserver();

private:

    bool* memory = (bool*) malloc(10000000);

};


#endif //ADS2_PJ1_MSERVER_H

//
// Created by fernando on 25/4/21.
//

#ifndef ADS2_PJ1_MSERVER_H
#define ADS2_PJ1_MSERVER_H



#include "../List/List.h"
#include "../Json/json.hpp"
#include "spdlog/spdlog.h"
#include <string>

using json = nlohmann::json;

// HOLA;
// HOLA855;


class Mserver {

public:
    std::string receive(std::string);
    std::string print();
    Mserver();

private:

    bool* memory = (bool*) malloc(10485760);
    void add(std::string _value, std::string _type, int position);
};


#endif //ADS2_PJ1_MSERVER_H

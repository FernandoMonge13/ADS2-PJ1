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
    std::string definition(std::string message);
    std::string defintion_with_operation(std::string message);
    std::string calculateI(std::string _variable_1, std::string _variable_2, std::string _operation);
    std::string  calculateL(std::string _variable_1, std::string _variable_2, std::string _operation);
    std::string  calculateF(std::string _variable_1, std::string _variable_2, std::string _operation);
    std::string  calculateD(std::string _variable_1, std::string _variable_2, std::string _operation);
    std::string calculate(std::string _variable_1, std::string _variable_2, std::string _operation, std::string _type);
    // añade a memory
    void add(std::string _value, std::string _type, int position);
    std::string operation_handler (std::string _value, std::string type);
};


#endif //ADS2_PJ1_MSERVER_H

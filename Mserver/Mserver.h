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

/*!
 * @brief It whats basically do is manage the memory
 */
class Mserver {

public:
    /*!
     * @brief Constructor
     */
    Mserver();

    /*!
     * @brief it get a Json object from the client to add it to the memory
     * @return the information reorganized
     */
    std::string receive(std::string);

    /*!
     * @brief give us the status of the memory state
     * @return the info that is actually in memory
     */
    std::string print();


private:

    bool* memory = (bool*) malloc(10485760);
    std::string printV(std::string message);
    std::string definition(std::string message);
    std::string defintion_with_operation(std::string message);
    std::string re_definition(std::string message);
    std::string re_definition_with_operation(std::string message);
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
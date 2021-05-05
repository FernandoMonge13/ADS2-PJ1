//
// Created by fernando on 25/4/21.
//
#include <string>
#include <iostream>
#include "Mserver.h"

Mserver::Mserver() {

}

List list = List();


std::string Mserver::receive(std::string temporal){
    auto json_message = json::parse(temporal);

    std::string instruccion = json_message["Instruccion"].get<std::string>();
//    std::string tipo =  json_message["Type"].get<std::string>();

    if(instruccion == "ReRun"){
        list.setFlag();
        json nullmessage ={
                {"Addresses",  "skip"},
                {"Values",  "skip"},
                {"Labels", "skip"},
                {"Refs_Count", "skip"},
        };
        return nullmessage.dump();
    }
    else if (instruccion == "definition") {
        return definition(temporal);
    }
    else if (instruccion == "definition_with_operation"){
        return defintion_with_operation(temporal);
    }
    else if (instruccion == "re definition"){
        return re_definition(temporal);
    }
    else if (instruccion == "re definition_with_operation"){
        return re_definition_with_operation(temporal);
    }
    else if (instruccion == "print"){
        return printV(temporal);
    }
}

void Mserver::add(std::string _value, std::string _type, int position) {

    if (_type == "int"){
        *((int *)(memory + position)) = std::stoi(_value);
    }
    else if (_type == "long"){
        *((long *)(memory + position)) = std::stol(_value);
    }
    else if (_type == "char"){
        *((char *)(memory + position)) = *((char*)_value.c_str());
    }
    else if (_type == "float"){
        *((float *)(memory + position)) = std::stof(_value);
    }
    else if (_type == "double"){
        *((double *)(memory + position)) = std::stod(_value);
    }
    else if(_type == "reference"){
        // Protocol for reference definitions
    }
    else{
        spdlog::critical("No se pudo realizar el guardado en memoria");
    }

}

std::string Mserver::print() {
    return list.print(memory);
}

std::string Mserver::definition(std::string message) {
    auto json_message = json::parse(message);

    if (list.getFlag()) {
        //std::cout << json_message;
        spdlog::info("Mserver: First");
        list.insert(json_message["Name"].get<std::string>(), json_message["Type"].get<std::string>(),
                    std::stoi(json_message["Size"].get<std::string>()), json_message["Access"].get<std::string>());
        spdlog::info("Mserver: list insert finalized");
        this->add((json_message["Value"]).get<std::string>(), (json_message["Type"]).get<std::string>(),
                  (list.find(json_message["Name"].get<std::string>())->getN()));
        spdlog::info("Mserver: add finalized");
        return this->print();
    }
    else {
        list.insert(json_message["Name"], json_message["Type"], std::stoi(json_message["Size"].get<std::string>()),
                    json_message["Access"].get<std::string>());
        this->add((json_message["Value"]).get<std::string>(), (json_message["Type"]).get<std::string>(),
                  list.find((json_message["Name"]).get<std::string>())->getN());
        spdlog::info("Second Variable added, to print in Mserver");
        return this->print();
    }
}

std::string Mserver::defintion_with_operation(std::string message) {
    auto json_message = json::parse(message);

    std::string value = operation_handler(json_message["Value"].get<std::string>(),
                                  json_message["Type"].get<std::string>());
    if (list.getFlag()) {
        //std::cout << json_message;
        spdlog::info("Mserver: First");
        list.insert(json_message["Name"].get<std::string>(), json_message["Type"].get<std::string>(),
                    std::stoi(json_message["Size"].get<std::string>()), json_message["Access"].get<std::string>());
        spdlog::info("Mserver: list insert finalized");
        this->add(value, (json_message["Type"]).get<std::string>(),
                  (list.find(json_message["Name"].get<std::string>())->getN()));
        spdlog::info("Mserver: add finalized");
        return this->print();
    }
    else {
        list.insert(json_message["Name"], json_message["Type"], std::stoi(json_message["Size"].get<std::string>()),
                    json_message["Access"].get<std::string>());
        this->add(value, (json_message["Type"]).get<std::string>(),
                  list.find((json_message["Name"]).get<std::string>())->getN());
        spdlog::info("Second Variable added, to print in Mserver");
        return this->print();
    }
}

std::string Mserver::operation_handler (std::string _value, std::string type) {
    try{
        std::string variable_1;
        std::string variable_2;
        std::string operation;
        std::string result;
        std::string character = _value;
        character = character[0];

        while (!_value.empty()){

            if (character == "+" || character == "-" || character == "*" || character == "/"){
                if (variable_1.empty()){
                    spdlog::error("Error getting operation");
                    // mega error, hay una operación antes que cualquier variable
                    break;
                }
                    // se encuentra el signo de operacion y eso tambien indica que se tiene la variable 1
                else if (variable_2.empty()) {
                    Node* node1 = list.find(variable_1);
                    variable_1 = list.getValue(node1->getType(),node1->getN(), memory); // Cambio arriesgado
                    operation = character;
                    _value.erase(_value.begin());
                    character = _value;
                    character = character[0];
                }
                    // la variable dos no está vacia por lo que se debe utilizar para operación
                else if (!variable_2.empty()){
                    result = calculate(variable_1, variable_2, operation, type);
//                    std::cout << result << std::endl;
                    variable_1 = result;
                    operation = character;
                    _value.erase(_value.begin());
                    character = _value;
                    character = character[0];
                    variable_2 = "";
                }
            }
                // Si aun no ha encontrado una operación, significa que está obteniendo la variable 1
            else if (operation.empty()){
                variable_1.append(character);
                _value.erase(_value.begin());
                character = _value;
                character = character[0];
            }
                // Si se ha encontrado una operación, significa que está obteniendo la variable 2
            else if (!operation.empty()) {
                variable_2.append(character);
                _value.erase(_value.begin());
                character = _value;
                character = character[0];
            }

        }
        if (!variable_2.empty()){
            result = calculate(variable_1, variable_2, operation, type);
        }
        return result;
//        return true;
//        std::cout << result << std::endl;

    }
    catch (std::exception exception){
        std::cout << "Operation error" << std::endl;
        return "0";
//        return false;
    }
    return _value;
}

std::string  Mserver::calculateI(std::string _variable_1, std::string _variable_2, std::string _operation) {
    int result;
    try {
//        Node* node1 = list.find(_variable_1); // cambio arriesgado
        Node* node2 = list.find(_variable_2);
//        int variable1 = std::stoi(list.getValue(node1->getType(),node1->getN(), memory)); // cambio arriesgado
        int variable1 = std::stoi(_variable_1); // cambio arriesgado
        int variable2 = std::stoi(list.getValue(node2->getType(),node2->getN(), memory));

        if (_operation == "+"){
            result = variable1 + variable2;
        }
        else if (_operation == "-"){
            result = variable1 - variable2;
        }
        else if (_operation == "*"){
            result = variable1 * variable2;
        }
        else if (_operation == "/"){
            result = variable1 / variable2;
        }
    }
    catch (int exc){
        std::cout << "failed in conversion" << std::endl;
    }
    return std::to_string(result);
}

std::string
Mserver::calculate(std::string _variable_1, std::string _variable_2, std::string _operation, std::string _type) {

    if (_type == "int"){
        return calculateI(_variable_1, _variable_2, _operation);
    }
    else if (_type == "long"){
        return calculateL(_variable_1, _variable_2, _operation);
    }
    else if (_type == "float"){
        return calculateF(_variable_1, _variable_2, _operation);
    }
    else if (_type == "double"){
        return calculateD(_variable_1, _variable_2, _operation);
    }
    else{
        spdlog::error("Calculate: no se encontró type para realizar la operación");
        return "0";
    }
}

std::string Mserver::calculateF(std::string _variable_1, std::string _variable_2, std::string _operation) {

    float result;
    try {
//        Node* node1 = list.find(_variable_1); // cambio arriesgado
        Node* node2 = list.find(_variable_2);
//        float variable1 = std::stoi(list.getValue(node1->getType(),node1->getN(), memory)); // cambio arriesgado
        float variable1 = std::stof(_variable_1); // cambio arriesgado
        float variable2 = std::stof(list.getValue(node2->getType(),node2->getN(), memory));

        if (_operation == "+"){
            result = variable1 + variable2;
        }
        else if (_operation == "-"){
            result = variable1 - variable2;
        }
        else if (_operation == "*"){
            result = variable1 * variable2;
        }
        else if (_operation == "/"){
            result = variable1 / variable2;
        }
    }
    catch (float exc){
        std::cout << "failed in conversion" << std::endl;
    }
    return std::to_string(result);
}

std::string Mserver::calculateL(std::string _variable_1, std::string _variable_2, std::string _operation) {
    long result;
    try {
//        Node* node1 = list.find(_variable_1); // cambio arriesgado
        Node* node2 = list.find(_variable_2);
//        long variable1 = std::stoi(list.getValue(node1->getType(),node1->getN(), memory)); // cambio arriesgado
        long variable1 = std::stoi(_variable_1); // cambio arriesgado
        long variable2 = std::stoi(list.getValue(node2->getType(),node2->getN(), memory));

        if (_operation == "+"){
            result = variable1 + variable2;
        }
        else if (_operation == "-"){
            result = variable1 - variable2;
        }
        else if (_operation == "*"){
            result = variable1 * variable2;
        }
        else if (_operation == "/"){
            result = variable1 / variable2;
        }
    }
    catch (long exc){
        std::cout << "failed in conversion" << std::endl;
    }
    return std::to_string(result);
}

std::string Mserver::calculateD(std::string _variable_1, std::string _variable_2, std::string _operation) {
    double result;
    try {
//        Node* node1 = list.find(_variable_1); // cambio arriesgado
        Node* node2 = list.find(_variable_2);
//        double variable1 = std::stoi(list.getValue(node1->getType(),node1->getN(), memory)); // cambio arriesgado
        double variable1 = std::stoi(_variable_1); // cambio arriesgado
        double variable2 = std::stoi(list.getValue(node2->getType(),node2->getN(), memory));

        if (_operation == "+"){
            result = variable1 + variable2;
        }
        else if (_operation == "-"){
            result = variable1 - variable2;
        }
        else if (_operation == "*"){
            result = variable1 * variable2;
        }
        else if (_operation == "/"){
            result = variable1 / variable2;
        }
    }
    catch (double exc){
        std::cout << "failed in conversion" << std::endl;
    }
    return std::to_string(result);
}

std::string Mserver::re_definition(std::string message) {
    auto json_message = json::parse(message);

    Node* node = list.find(json_message["Name"].get<std::string>());
    std::string value = json_message["Value"].get<std::string>();
    std::string type = node->getType();
    int position = node->getN();
    add(value, type, position);
    return print();
}

std::string Mserver::re_definition_with_operation(std::string message) {
    auto json_message = json::parse(message);

    Node* node = list.find(json_message["Name"].get<std::string>());
    std::string no_calculated_value = json_message["Value"].get<std::string>();
    std::string type = node->getType();
    int position = node->getN();

    std::string calculated_value = operation_handler(no_calculated_value,type);
    add(calculated_value, type, position);

    return print();
}

std::string Mserver::printV(std::string message) {
    auto json_message = json::parse(message);
    Node* node = list.find(json_message["Name"].get<std::string>());
    std::string value = list.getValue(node->getType(), node->getN(), memory);
    json j_message = {
            {"Addresses",  "addresses"},
            {"Values",  value},
            {"Labels", "labels"},
            {"Refs_Count", "refs_count"},
    };
    return j_message.dump();
}


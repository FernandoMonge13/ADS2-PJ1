//
// Created by fernando on 25/4/21.
//
#include <string>
#include <iostream>

#include "Mserver.h"

Mserver::Mserver() {

}

List list = List();


void Mserver::receive(std::string temporal){
    auto json = json::parse(temporal);

//    std::string tipo =  json["Type"].get<std::string>();

    if(json["Instruccion"].get<std::string>() == "ReRun"){
        list.setFlag();
        free(memory);
        memory = (bool*) malloc(10000000);
    }

    else if(list.getFlag()){
        //std::cout << json;
        spdlog::info("Mserver: First");
        list.insert(json["Name"].get<std::string>(), json["Type"].get<std::string>(), std::stoi(json["Size"].get<std::string>()));
        spdlog::info("Mserver: list insert finalized");
        this->add((json["Value"]).get<std::string>(), (json["Type"]).get<std::string>(), (list.find(json["Name"].get<std::string>())->getN()));
        spdlog::info("Mserver: add finalized");
        this->print();
        spdlog::info("Mserver: print did");
    }
    else{
        list.insert(json["Name"], json["Type"], std::stoi(json["Size"].get<std::string>()));
        this->add((json["Value"]).get<std::string>(), (json["Type"]).get<std::string>(), list.find((json["Name"]).get<std::string>())->getN());
        spdlog::info("Second Variable added, to print in Mserver");
        this->print();
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
        // How the fuck it suppose that i save a char
    }
    else if (_type == "float"){
        *((float *)(memory + position)) = std::stof(_value);
    }
    else if (_type == "double"){
        *((double *)(memory + position)) = std::stod(_value);
    }
    else if(_type == "reference"){
        // Protocol for reference declarations
    }
    else{
        spdlog::critical("Valió verga el guardado en memoria");
    }

}

void Mserver::print() {
    list.print(memory);
}

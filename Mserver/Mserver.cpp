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

//    std::string tipo =  json_message["Type"].get<std::string>();

    if(json_message["Instruccion"].get<std::string>() == "ReRun"){
        list.setFlag();
        json nullmessage ={
                {"Addresses",  "skip"},
                {"Values",  "skip"},
                {"Labels", "skip"},
                {"Refs_Count", "skip"},
        };
        return nullmessage.dump();
    }

    else if(list.getFlag()){
        //std::cout << json_message;
        spdlog::info("Mserver: First");
        list.insert(json_message["Name"].get<std::string>(), json_message["Type"].get<std::string>(), std::stoi(json_message["Size"].get<std::string>()));
        spdlog::info("Mserver: list insert finalized");
        this->add((json_message["Value"]).get<std::string>(), (json_message["Type"]).get<std::string>(), (list.find(json_message["Name"].get<std::string>())->getN()));
        spdlog::info("Mserver: add finalized");
        return this->print();
    }
    else{
        list.insert(json_message["Name"], json_message["Type"], std::stoi(json_message["Size"].get<std::string>()));
        this->add((json_message["Value"]).get<std::string>(), (json_message["Type"]).get<std::string>(), list.find((json_message["Name"]).get<std::string>())->getN());
        spdlog::info("Second Variable added, to print in Mserver");
        return this->print();
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

std::string Mserver::print() {
    return list.print(memory);
}

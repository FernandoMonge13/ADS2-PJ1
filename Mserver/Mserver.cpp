//
// Created by fernando on 25/4/21.
//
#include <string>
#include <iostream>

#include "Mserver.h"

Mserver::Mserver() {

}

List list = List();


void Mserver::insertion(std::string temporal){
    auto json = json::parse(temporal);


    if(list.getFlag()){
        int available_position = list.insert("0", (json["Name"]).dump(), (json["Type"]).dump(), json["Size"].dump());
        std::cout << json;
        this->add((json["Value"]).dump(), (json["Type"]).dump(), available_position);
        this->print();

//        if(json["type"]== "int"){
//            *((int *)(memory)) = std::stoi(json["value"]);
//
//        }
//////////////////////////// AQui va lo de memoria

    }
    else{
        int available_position = list.insert(std::to_string((list.getTail()->getN() + list.getTail()->getSize())), json["Name"], json["Type"],json["Size"].dump());
        this->add((json["Value"]).dump(), (json["Type"]).dump(), available_position);
        spdlog::info("Variable added, to print in Mserver");
        this->print();
//////////////////////////// AQui va lo de memoria
    }
}

void Mserver::add(std::string _value, std::string _type, int position) {
    std::cout << "dE QUE LLEGO LEGO";
    std::cout << _type;
    if (_type == "int"){
        *((int *)(memory + position)) = std::stoi(_value);
        std::cout << "HPPPPPPPP";
        std::cout << memory+position;
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
}

void Mserver::print() {
    list.print(memory);
}

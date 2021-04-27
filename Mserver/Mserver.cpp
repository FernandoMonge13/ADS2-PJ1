//
// Created by fernando on 25/4/21.
//
#include <string>

#include "Mserver.h"

Mserver::Mserver() {

}

List list = List();


void Mserver::insertion(std::string temporal){
    auto json = json::parse(temporal);


    if(list.getFlag()){
        list.insert("0", (json["Name"]).dump(), (json["Type"]).dump(), json["Size"].dump());


//        if(json["type"]== "int"){
//            *((int *)(memory)) = std::stoi(json["value"]);
//
//        }
//////////////////////////// AQui va lo de memoria

    }else{
        list.insert(std::to_string((list.getTail()->getSize())+1), json["Name"], json["Type"],json["Size"].dump());

//////////////////////////// AQui va lo de memoria


    }




}

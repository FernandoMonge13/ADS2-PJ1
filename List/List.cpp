//
// Created by fernando on 24/4/21.
//

#include <iostream>
#include <sstream>
#include "List.h"
#include <string>
#include <Client.h>
#include "../Json/json.hpp"


List::List() {

}

void List::insert(std::string name, std::string type, int _size) {


    temporal =  new Node;
    temporal->setName(name);
    temporal->setType(type);
    temporal->setSize(_size);
//    std::cout << "El valor del nodo es " << std::endl;

//    std::cout << "a" << std::endl;


    if (flag){
        temporal->setN(0);
        head = temporal;
        tail = temporal;
        temporal->setNext(nullptr);
        flag = false;
//        return tail->getN();
    }else{
        temporal->setN(tail->getN() + tail->getSize());
        tail->setNext(temporal);
        tail = temporal;
//        return tail->getN();
    }
}

void List::remove(std::string name) {

    temporal = head;
    Node* prev;

    while (temporal->getNext() != nullptr && temporal->getName() != name){

        prev = temporal;
        temporal = temporal->getNext();
    }
    if (temporal->getName() == name){
        prev->setNext(temporal->getNext());
        delete temporal;
    }else if (temporal->getNext() == nullptr){

        //
    }

}

Node* List::find(std::string _name) {

    temporal = head;

    while (true){

        if (temporal->getName() == _name){
            return temporal;
        }
        else if (temporal->getNext() == nullptr){
            return nullptr;
        }
        else {
            temporal = temporal->getNext();
        }
    }

}

bool List::getFlag() {
    return flag;
}

Node *List::getTail() {
    return tail;
}

std::string List::print(bool *_memory) {
    std::cout << " "    << std::endl;
    std::cout << "☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭ Print Socialista ☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭" << std::endl;
    Node* index = head;

    std::string addresses;
    std::string values;
    std::string labels;
    std::string refs_count = " ";
    json j_message;

    while (index != nullptr){
        std::cout << "N = ";
        std::cout << index->getN() << std::endl;
        std::cout << "Label = ";
        std::cout << index->getName() << std::endl;
        labels.append(index->getName() + " ");
        std::cout << "ref = ";
        std::cout << (_memory + index->getN()) << std::endl;
        std::ostringstream get_the_address;
        get_the_address << _memory + index->getN();
        addresses.append(get_the_address.str() + " ");
        std::cout << "value = ";
        std::cout << getValue(index->getType(), index->getN(), _memory) << std::endl;
        values.append(getValue(index->getType(), index->getN(), _memory) + " ");
        std::cout << "|" << std::endl;
        std::cout << "V" << std::endl;
        index = index->getNext();
    }
    std::cout << "nullptr" << std::endl;
    std::cout << addresses << std::endl;
    std::cout << values << std::endl;
    std::cout << labels << std::endl;
    j_message = {
            {"Addresses",  addresses},
            {"Values",  values},
            {"Labels", labels},
            {"Refs_Count", refs_count},
    };
    return j_message.dump();

}

int List::available_memory(int _size) {

    //Pendiente de obtener espacios que han sido liberados
    }

std::string List::getValue(std::string _type, int position, bool* _memory) {

    if (_type == "int"){
        return std::to_string(*((int *)(_memory + position)));
    }
    else if (_type == "long"){
        return std::to_string(*((long *)(_memory + position)));
    }
    else if (_type == "char"){
        // How the fuck it suppose that i save a char
    }
    else if (_type == "float"){
        return std::to_string(*((float *)(_memory + position)));
    }
    else if (_type == "double"){
        return std::to_string(*((double *)(_memory + position)));
    }
    else if(_type == "reference"){
        // Protocol for reference declarations
    }
    else{
        spdlog::critical("Lis.getValue:  Error desconocido");
    }
}

void List::setFlag() {
    flag = true;
}




//
// Created by fernando on 24/4/21.
//

#include <iostream>
#include "List.h"

List::List() {

}

int List::insert(std::string N, std::string name, std::string type, std::string _size) {


    temporal =  new Node;
    temporal->setName(name);
    temporal->setN(stoi(N));
    temporal->setType(type);
//    temporal->setSize(std::stoi(_size));

    if (flag){
        head = temporal;
        tail = temporal;
        temporal->setNext(nullptr);
        flag = false;
        return tail->getN();
    }else{
        tail->setNext(temporal);
        tail = temporal;
        return tail->getN();
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

bool List::find(std::string name) {

    temporal = head;

    while (temporal->getNext() != nullptr ){

        if (temporal->getName() == name){
            return true;

        }

        temporal = temporal->getNext();
    }
    return false;

}

bool List::getFlag() {
    return flag;
}

Node *List::getTail() {
    return tail;
}

void List::print(bool *_memory) {
    Node* index = tail;
    spdlog::info("In List print");
    while (index->getNext() != nullptr){

        std::cout << "N = ";
        std::cout << index->getN();
        spdlog::info("In List print2");
        std::cout << ((int *)(_memory + index->getN()));
        std::cout << " -";
        std::cout << *((int *)(_memory+index->getN()));
        std::cout << "- ";
        std::cout << " -> ";
        index = index->getNext();
        spdlog::info("In while");
    }
    std::cout << "N = ";
    std::cout << index->getN();
    spdlog::info("llego");
    std::cout << ((int *)(_memory + index->getN()));
    std::cout << " -";
    std::cout << *((int *)(_memory + index->getN()));
    std::cout << "- ";
    std::cout << " -> nullptr";
    spdlog::info("Out of while");
}



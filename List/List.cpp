//
// Created by fernando on 24/4/21.
//

#include "List.h"

List::List() {

}

void List::insert(std::string N, std::string name, std::string type, std::string) {

    spdlog::warn("AIUDA");

    temporal =  new Node;
    temporal->setName(name);
    temporal->setN(stoi(N));
    temporal->setType(type);

    if (flag){
        head = temporal;
        tail = temporal;
        flag = false;
    }else{
        tail->setNext(temporal);
        tail = temporal;
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



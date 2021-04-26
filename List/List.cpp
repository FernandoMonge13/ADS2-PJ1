//
// Created by fernando on 24/4/21.
//

#include "List.h"

List::List() {

}

void List::insert(int size, std::string name) {

    temporal =  new Node;
    temporal->setName(name);
    temporal->setSize(size);

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



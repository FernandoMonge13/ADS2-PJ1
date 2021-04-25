//
// Created by fernando on 24/4/21.
//

#include "List.h"

List::List() {

}

void List::insert(int size, std::string name){
    if (flag){
        Node* new_node = new Node();

        new_node->setSize(size);
        new_node->setName(name);

        new_node->setNext(nullptr);
        setTemporal(new_node);

        flag = false;

    }else{
        Node* new_node = new Node();

        new_node->setSize(size);
        new_node->setName(name);

        new_node->setNext(temporal);

        setTemporal(new_node);

    }
}

void List::setTemporal(Node *) {
    List::temporal = temporal;
}

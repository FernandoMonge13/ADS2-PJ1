//
// Created by fernando on 24/4/21.
//

#include "Node.h"

Node::Node() {

}

Node *Node::getNext(){
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

int Node::getSize() {
    return size;
}

void Node::setSize(int size) {
    Node::size = size;
}

std::string Node::getName() {
    return name;
}

void Node::setName(std::string name) {
    Node::name = name;

}

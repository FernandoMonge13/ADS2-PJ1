//
// Created by fernando on 24/4/21.
//

#include "Node.h"
#include "iostream"
#include "string"

Node::Node() {

}

Node *Node::getNext(){
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

int Node::getN() {
    return N;
}

void Node::setN(int size) {
    Node::N = size;
}

std::string Node::getName() {
    return name;
}

void Node::setName(std::string name) {
    Node::name = name;
}

std::string Node::getType() {
    return type;
}

void Node::setType(std::string type) {
    Node::type = type;
}
int Node::getSize() {
    return size;
}

void Node::setSize(int _size) {
    Node::size = _size;
}


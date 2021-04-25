//
// Created by fernando on 24/4/21.
//

#ifndef ADS2_PJ1_NODE_H
#define ADS2_PJ1_NODE_H

#include <string>


class Node {
public:

    Node();

public:
    Node *getNext();
    void setNext(Node *);

    int getSize();
    void setSize(int);

    std::string getName();
    void setName(std::string);

private:
    Node* next;
    int size;
    std::string name;

};


#endif //ADS2_PJ1_NODE_H

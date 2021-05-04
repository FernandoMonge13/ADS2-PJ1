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

    int getN();
    void setN(int);

    std::string getName();
    void setName(std::string);

    std::string getType();
    void setType(std::string);

    int getSize();
    void setSize(int _size);

    std::string getAccess();
    void setAccess(std::string _access);

private:

    Node* next = nullptr;
    int N;
    std::string name;
    std::string type;
    std::string access;
    int size;


};


#endif //ADS2_PJ1_NODE_H

//
// Created by fernando on 24/4/21.
//

#ifndef ADS2_PJ1_NODE_H
#define ADS2_PJ1_NODE_H

#include <string>


class Node {
public:

    Node* next;
    Node();

private:
    int size;
    std::string name;

};


#endif //ADS2_PJ1_NODE_H

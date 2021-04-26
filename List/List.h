//
// Created by fernando on 24/4/21.
//

#ifndef ADS2_PJ1_LIST_H
#define ADS2_PJ1_LIST_H

#include "../Node/Node.h"
#include <string>


class List {
public:

    void insert(int, std::string);
    void remove(std::string);
    bool find(std::string);

    List();


private:
    bool flag = true;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *temporal = nullptr;


};


#endif //ADS2_PJ1_LIST_H

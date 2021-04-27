//nt
// Created by fernando on 24/4/21.
//

#ifndef ADS2_PJ1_LIST_H
#define ADS2_PJ1_LIST_H

#include "../Node/Node.h"
#include <string>
#include "spdlog/spdlog.h"


class List {
public:
    //agrega al final - retorna la posicion donde se debe almacenar la variable
    int insert(std::string, std::string, std::string, std::string);
    void remove(std::string);
    bool find(std::string);
    bool getFlag();
    // Ultimo nodo
    Node* getTail();
    void print(bool * _memory);

    List();


private:
    bool flag = true;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *temporal = nullptr;


};


#endif //ADS2_PJ1_LIST_H

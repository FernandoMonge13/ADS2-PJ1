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
    void insert(std::string name, std::string type, int _size, std::string access);
    void remove(std::string);
    bool getFlag();
    void setFlag();
    // Ultimo nodo
    Node* getTail();
    Node* find(std::string);
    std::string print(bool * _memory);

    std::string getValue(std::string _type, int position, bool * _memory);


    List();

private:
    int available_memory(int _size);
    bool flag = true;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *temporal = nullptr;


};


#endif //ADS2_PJ1_LIST_H

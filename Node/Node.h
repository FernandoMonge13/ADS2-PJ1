//
// Created by fernando on 24/4/21.
//

#ifndef ADS2_PJ1_NODE_H
#define ADS2_PJ1_NODE_H

#include <string>


/**
     * @brief This is the base of the linked list creation
     */

class Node {
public:

    /*!
     * @brief Constructor
     */
    Node();

    /*!
     * @brief give us the the next node of the linked list
     * @return the next node
     */
    Node *getNext();

    /**
     * @brief set the nest node of a node
     */
    void setNext(Node *);

    /*!
     * @brief give us the among of movements offsets from the head of the memory
     * @return the N value of an specific node
     */
    int getN();

    /**
     * @brief set the N value
     */
    void setN(int);

    /*!
     * @brief give us the name of the node
     * @return node name
     */
    std::string getName();

    /**
     * @brief set the name of a node
     */
    void setName(std::string);

    /*!
     * @brief give us the variable type inside of a node
     * @return variable type
     */
    std::string getType();

    /**
     * @brief set the type of a node
     */
    void setType(std::string);

    /*!
     * @brief give us the size of an specific node
     * @return node size
     */
    int getSize();

    /**
     * @brief set the size of a node
     */
    void setSize(int _size);

    /*!
     * @brief give us the level of access of some node
     * @return access level
     */
    std::string getAccess();

    /**
     * @brief set the level of access
     */
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

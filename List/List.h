//nt
// Created by fernando on 24/4/21.
//

#ifndef ADS2_PJ1_LIST_H
#define ADS2_PJ1_LIST_H

#include "../Node/Node.h"
#include <string>
#include "spdlog/spdlog.h"

/*!
 * @brief It is used to help with the memory management
 */
class List {
public:

    /*!
     * @brief
     * @param name of the new node
     * @param type of the node
     * @param _size size according to the type
     * @param access level of access of the variable
     */
    void insert(std::string name, std::string type, int _size, std::string access);

    /*!
     * @brief delete a node from the linked list
     * @param the name of the node is gonna be deleted
     */
    void remove(std::string);

    /*!
     * @brief provide us an indicator for future analysis
     * @return status of the flag
     */
    bool getFlag();

    /*!
     * @brief set the value of the indicator
     */
    void setFlag();

    /*!
     * @brief give us the last node of the linked list
     * @return last node of the list
     */
    Node* getTail();
    /*!
     * @brief find if a node is on the linked list
     * @param name of the node to be searched
     * @return the node the one was been searched
     */
    Node* find(std::string);
    /*!
     * @brief give us how is conformed the list
     * @param _memory
     * @return the state of the list
     */
    std::string print(bool * _memory);

    /**
     * @brief give us the among of space that need to be reserved
     * @param _type of the variable
     * @param position where the node is located
     * @param _memory the head of the memory
     * @return
     */
    std::string getValue(std::string _type, int position, bool * _memory);


    /*!
     * @brief Constructor
     */
    List();

private:
    int available_memory(int _size);
    bool flag = true;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *temporal = nullptr;


};


#endif //ADS2_PJ1_LIST_H

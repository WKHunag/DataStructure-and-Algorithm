//
// Created by 黃威凱 on 2023/7/30.
//

#ifndef HOMEWORK_NODE_H
#define HOMEWORK_NODE_H

template<typename T>
class Node{
public:
    T value = {};
    Node<T> *next = nullptr;
    Node<T> *pre = nullptr;

    Node();
    Node(T item);
    ~Node();
};
#include "Node.tpp"
#endif //HOMEWORK_NODE_H

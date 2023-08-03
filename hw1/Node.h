//
// Created by 黃威凱 on 2023/7/30.
//

#ifndef HOMEWORK_NODE_H
#define HOMEWORK_NODE_H

template <typename T>
class Node{
    T value;
public:
    bool notNull;
    Node<T> *next = nullptr;
    Node<T> *pre = nullptr;
    Node();//:value(0),next(nullptr),pre(nullptr){};
    Node(T input);//:value(value),next(nullptr),pre(nullptr){};
    T getValue();
};

#endif //HOMEWORK_NODE_H

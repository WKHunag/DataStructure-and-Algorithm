//
// Created by 黃威凱 on 2023/7/30.
//

#ifndef HOMEWORK_NODE_H
#define HOMEWORK_NODE_H

template <class T>
class Node{
public:
    Node();//:value(0),next(nullptr),pre(nullptr){};
    Node(T value);//:value(value),next(nullptr),pre(nullptr){};
    T value;
    Node *next = nullptr;
    Node *pre = nullptr;
};

template<> Node<int> :: Node(int value){

}

template<> Node<double> :: Node(double value){

}

template<> Node<char> :: Node(char value){

}

#endif //HOMEWORK_NODE_H

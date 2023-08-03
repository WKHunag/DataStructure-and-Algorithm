//
// Created by 黃威凱 on 2023/7/30.
//

#include "Node.h"

template <typename T>
Node<T> :: Node() {
    notNull = false;
    value = 0;
}

template <typename T>
Node<T> :: Node(T input) {
    notNull = true;
    value = input;
}

template <typename T>
T Node<T>::getValue() {
    return value;
}

template struct Node<int>;
template struct Node<char>;
template struct Node<double>;
//
// Created by 黃威凱 on 2023/7/30.
//

#include "Node.h"

template <typename T>
Node<T> :: Node() {
    value = 0;
}

template <typename T>
Node<T> :: Node(T value) {
    value = value;
}


Node<int> nodeInt;
Node<double> nodeDouble;
Node<char> nodeChar;
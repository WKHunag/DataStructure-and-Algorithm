//
// Created by 黃威凱 on 2023/8/15.
//
#include "Node.h"

template<typename T>
Node<T> :: Node() = default;

template<typename T>
Node<T> :: Node(T item) {
    value = item;
}

template<typename T>
Node<T> :: ~Node() = default;
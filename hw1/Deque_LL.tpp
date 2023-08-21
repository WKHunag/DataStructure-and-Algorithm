//
// Created by 黃威凱 on 2023/8/15.
//

#include "Deque_LL.h"

template<typename T>
Deque_LL<T>::Deque_LL() {
    first = nullptr;
    last = nullptr;
    length = 0;
}

template<typename T>
int Deque_LL<T>::size() const {
    return length;
}

template<typename T>
bool Deque_LL<T>::isEmpty() const {
    return length == 0;
}

template<typename T>
void Deque_LL<T>::addFirst(T item) {
    Node<T> *newNode = new Node<T>(item);
    if (isEmpty()) {
        first = last = newNode;
    } else {
        newNode -> next = first;
        first -> pre = newNode;
        first = newNode;
    }
    length++;
}

template<typename T>
void Deque_LL<T>::addLast(T item) {
    Node<T> *newNode = new Node<T>(item);
    if (isEmpty()) {
        first = last = newNode;
    } else {
        newNode -> pre = last;
        last -> next = newNode;
        last = newNode;
    }
    length++;
}

template<typename T>
T Deque_LL<T>::removeFirst() {
    if (isEmpty()) {
        throw std::underflow_error("Error: Attempt to access data from an empty queue.");
    } else {
        T poppedValue = first -> value;
        first = first -> next;
        delete first -> pre;
        length--;
        return poppedValue;
    }
}

template<typename T>
T Deque_LL<T>::removeLast() {
    if (isEmpty()) {
        throw std::underflow_error("Error: Attempt to access data from an empty queue.");
    } else {
        T poppedValue = last -> value;
        last = last -> pre;
        delete last -> next;
        length--;
        return poppedValue;
    }
}

template<typename T>
T Deque_LL<T>::get(int index) const {
    if (index < 0 || index >= length) {
        throw std::runtime_error("Index out of the range.");
    }

    Node<T> *temp = first;
    for (int i = 0; i <= index-1; i++) {
        temp = temp -> next;
    }
    T result = temp -> value;
    return result;
}

template<typename T>
void Deque_LL<T>::printDeque() const {
    Node<T> *temp = first;
    std::cout << "[ ";
    while (temp != nullptr) {
        std::cout << temp -> value << " ";
        temp = temp -> next;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
Deque_LL<T>::~Deque_LL() {
    while (first != nullptr){
        Node<T> *cur = first;
        first = first -> next;
        delete cur;
    }
}
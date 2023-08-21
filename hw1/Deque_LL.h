#pragma once
#include <iostream>
#include "Deque.h"
#include "Node.h"


template<typename T>
class Deque_LL : public Deque<T> {
private:
    int length;
    Node<T> *first;
    Node<T> *last;
public:
    Deque_LL();
    int size() const override;
    bool isEmpty() const override;
    void addFirst(T item) override;
    void addLast(T item) override;
    void printDeque() const override;
    T removeFirst() override;
    T removeLast() override;
    T get(int index) const override;
    ~Deque_LL();
};

#include "Deque_LL.tpp"
//#pragma clang diagnostic pop
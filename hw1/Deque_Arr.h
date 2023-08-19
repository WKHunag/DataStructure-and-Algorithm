//
// Created by 黃威凱 on 2023/7/29.
//
#include <iostream>
#include "Deque.h"
#pragma once

template <typename T>
class Deque_Arr : public Deque<T> {
private:
    T* arr;
    int headIndex = -1;
    int tailIndex = -1;
    int capacity;
    int length = 0;

    void resize(int newCapacity);

public:
    Deque_Arr(int initialCapacity = 10);
    int size() const override;
    bool isEmpty() const override;
    bool isFull();
    void addFirst(T newFirst) override;
    void addLast(T newLast) override;
    T removeFirst() override;
    T removeLast() override;
    void printDeque() const override;
    T get(int index) const override;
    ~Deque_Arr();
};

#include "Deque_Arr.tpp"
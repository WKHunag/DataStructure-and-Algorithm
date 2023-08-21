//
// Created by 黃威凱 on 2023/7/29.
//
#pragma once
#include <iostream>
#include "Deque.h"


template <typename T>
class Deque_Arr : public Deque<T> {
private:
    T* arr;
    int capacity;
    int headIndex = capacity - 1;
    int tailIndex = 0;
    int length = 0;

    void resize();

public:
    Deque_Arr(int initialCapacity = 10);
    int size() const override;
    bool isEmpty() const override;
    bool isFull() const;
    void addFirst(T newFirst) override;
    void addLast(T newLast) override;
    T removeFirst() override;
    T removeLast() override;
    void printDeque() const override;
    T get(int index) const override;
    ~Deque_Arr();
};

#include "Deque_Arr.tpp"
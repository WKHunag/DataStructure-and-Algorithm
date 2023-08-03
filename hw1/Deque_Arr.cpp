//
// Created by 黃威凱 on 2023/7/29.
//
#include <iostream>
#include "Deque.h"

Deque_Arr :: Deque_Arr() {
    capacity = 10;
    pos1st = -1;
    poslast = -1;
    queue = new int[capacity];
}

int Deque_Arr :: size(){
    return poslast - pos1st;
}

void Deque_Arr :: addFirst(int newFirst) {
    if(isFull()){
        DoubleCapacityQueue();
    }
    poslast++;
    for (int i = poslast; i >= 1; i--){
        queue[i] = queue[i-1];
    }
    queue[0] = newFirst;
}

void Deque_Arr :: addLast(int newLast) {
    if(isFull()){
        DoubleCapacityQueue();
    }
    poslast++;
    queue[poslast] = newLast;
}

bool Deque_Arr :: isEmpty() {
    return not isFull();
}

void Deque_Arr :: printDeque() {
    for (int i = pos1st+1; i <= poslast; i++){
        std::cout << queue[i] << std::endl;
    }
}

int Deque_Arr :: removeFirst() {
    int first = queue[pos1st+1];
    pos1st ++;
    queue = &queue[pos1st];
    return first;
}

int Deque_Arr :: removeLast() {
    int last = queue[poslast];
    queue[poslast] = 0;
    poslast--;
    return last;
}

int Deque_Arr :: get(int index){
    return queue[index-pos1st+1];
}
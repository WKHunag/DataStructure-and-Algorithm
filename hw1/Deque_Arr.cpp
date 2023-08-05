//
// Created by 黃威凱 on 2023/7/29.
//
#include <iostream>
#include "Deque.h"

template<typename T>
Deque_Arr<T> :: Deque_Arr() {
    capacity = 10;
    pos1st = -1;
    poslast = -1;
    queue = new int[capacity];
}

template<typename T>
int Deque_Arr<T> :: size(){
    return poslast - pos1st;
}

template<typename T>
void Deque_Arr<T> :: addFirst(T newFirst) {
    if(isFull()){
        DoubleCapacityQueue();
    }
    poslast++;
    for (int i = poslast; i >= 1; i--){
        queue[i] = queue[i-1];
    }
    queue[0] = newFirst;
}

template<typename T>
void Deque_Arr<T> :: addLast(T newLast) {
    if(isFull()){
        DoubleCapacityQueue();
    }
    poslast++;
    queue[poslast] = newLast;
}

/*
    not full doesn't mean is empty.
*/
template<typename T>
bool Deque_Arr<T> :: isEmpty() {
    return not isFull();
}

template<typename T>
void Deque_Arr<T> :: printDeque() {
    for (int i = pos1st+1; i <= poslast; i++){
        std::cout << queue[i] << std::endl;
    }
}

template<typename T>
T Deque_Arr<T> :: removeFirst() {
    T first = queue[pos1st+1];
    pos1st ++;
    /*
        should be pos1st+1
        eventually will decrease the length of the array length
    */
    queue = &queue[pos1st];
    return first;
}

template<typename T>
T Deque_Arr<T> :: removeLast() {
    T last = queue[poslast];
    queue[poslast] = 0;
    poslast--;
    return last;
}

template<typename T>
T Deque_Arr<T> :: get(int index){
    return queue[index-pos1st+1];
}

template struct Deque_Arr<int>;
template struct Deque_Arr<double>;
template struct Deque_Arr<char>;
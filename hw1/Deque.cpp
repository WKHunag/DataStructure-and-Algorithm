#include <iostream>
#include "Deque.h"
#pragma ignore unreachible
template<typename T>
Deque_LL<T> :: Deque_LL(){
    length = 0;
}

template<typename T>
Deque_LL<T> :: Deque_LL(Node<T> head) {
    length = 1;
    first = &head;
    last = &head;
}

template<typename T>
int Deque_LL<T> :: size() {return length;};

template<typename T>
void Deque_LL<T> :: addFirst(Node<T> item) {
    if( length == 0 ){
        first = &item;
        last = &item;
    } else if (length == 1){
        first = &item;
        first -> next = last;
        last -> pre = first;
    }else{
        Node<T> *cur = &item;
        cur -> next = first;
        first -> pre = cur;
        first = cur;
    }
    length++;
}

template<typename T>
void Deque_LL<T> :: addLast(Node<T> item) {
    if(length == 0){
        first = &item;
        last = &item;
    }else if (length == 1){
        last = &item;
        last -> pre = first;
        first -> next = last;
    }else{
        last -> next = &item;
        item.pre = last;
        last = &item;
    }
    length++;
}

template<typename T>
void Deque_LL<T> :: printDeque() {
    if (length == 0) {
        std::cout << "The queue is empty" << std::endl;
    }
    for (Node<T> *p = first; p->notNull; p = p->next) {
        std::cout << p -> getValue() << std::endl;
    }
}

template<typename T>
Node<T> Deque_LL<T> :: removeFirst() {
    length--;
    Node<T> result = *first;
    first = first -> next;
    first -> pre = new Node<T>();
    return result;
}

template<typename T>
Node<T> Deque_LL<T> :: removeLast() {
    length--;
    Node<T> result = *last;
    last = last -> pre;
    last -> next = nullptr;
    return result;
}

template<typename T>
Node<T> Deque_LL<T> :: get(int index) {
    if (length == 0) {
        return Node<T>();
    }
    Node<T> *result = first->next;
    for (int i = 0; i < index; i++) {
        result = result -> next;
    }
    return *result;
}

template struct Deque_LL<int>;
template struct Deque_LL<double>;
template struct Deque_LL<char>;
//#pragma clang diagnostic pop
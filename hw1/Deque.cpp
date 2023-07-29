#include <iostream>
#include "Deque.h"

//template <class T>
Deque_LL :: Deque_LL(){
    length = 0;
    first = nullptr;
    last = nullptr;
}
Deque_LL ::Deque_LL(Node *head) {
    length = 1;
    first = head;
    last = head;
}


int Deque_LL :: size() {return length;};

void Deque_LL :: addFirst(Node item) {
    if(length == 0){
        first = &item;
        last = &item;
    }else if( length == 1 ) {
        item.next = first;
        first = &item;
        first -> next = last;
        last -> pre = first;
    }else{
        item.next = first;
        first -> pre = &item;
        first = &item;
    }
    length++;
}

void Deque_LL :: addLast(Node item) {
    if(length == 0){
        last = &item;
        first = &item;
    }else if(length == 1){
        last -> next = &item;
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

void Deque_LL :: printDeque() {
    for (Node *p = first; p != 0; p = p->next) {
        std::cout << p->value << std::endl;
    }
}

bool Deque_LL::isEmpty() {
    return length == 0;
}

Node Deque_LL :: removeFirst() {
    length--;
    Node result = *first;
    first = first -> next;
    first -> pre = nullptr;
    return result;
}

Node Deque_LL :: removeLast() {
    length--;
    Node result = *last;
    last = last -> pre;
    last -> next = nullptr;
    return result;
}

Node Deque_LL :: get(int index) {
    Node *result = first;
    for (int i = 0; i < index; i++) {
        result = result -> next;
    }
    return *result;
}
#include <iostream>
#include "Deque.h"

template<typename T, template<typename U> class Node>
Deque_LL<T, Node> :: Deque_LL(){
    length = 0;
    first = nullptr;
    last = nullptr;
}

template<typename T, template<typename U> class Node>
Deque_LL<T, Node> :: Deque_LL( Node<T> *head) {
    length = 1;
    first = head;
    last = head;
}

template<typename T, template<typename U> class Node>
int Deque_LL<T, Node> :: size() {return length;};

template<typename T, template<typename U> class Node>
void Deque_LL<T, Node> :: addFirst(Node<T> item) {
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

template<typename T, template<typename U> class Node>
void Deque_LL<T, Node> :: addLast(Node<T> item) {
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

template<typename T, template<typename U> class Node>
void Deque_LL<T, Node> :: printDeque() {
    for (Node<T> *p = first; p != 0; p = p->next) {
        std::cout << p->value << std::endl;
    }
}

template<typename T, template<typename U> class Node>
bool Deque_LL<T, Node> :: isEmpty() {
    return length == 0;
}

template<typename T, template<typename U> class Node>
Node<T> Deque_LL<T, Node> :: removeFirst() {
    length--;
    Node<T> result = *first;
    first = first -> next;
    first -> pre = nullptr;
    return result;
}

template<typename T, template<typename U> class Node>
Node<T> Deque_LL<T, Node> :: removeLast() {
    length--;
    Node<T> result = *last;
    last = last -> pre;
    last -> next = nullptr;
    return result;
}

template<typename T, template<typename U> class Node>
Node<T> Deque_LL<T, Node> :: get(int index) {
    Node<T> *result = first;
    for (int i = 0; i < index; i++) {
        result = result -> next;
    }
    return *result;
}

Deque_LL<int, Node> intDeque;
Deque_LL<double, Node> doubleDeque;
Deque_LL<char, Node> charDeque;

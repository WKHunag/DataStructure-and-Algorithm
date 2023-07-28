//
// Created by 黃威凱 on 2023/7/27.
//
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() :first(0), last(0), size(0){};
LinkedList::LinkedList(Node *head) :first(head), last(head), size(1) {};

void LinkedList::PrintList() {
    for (Node *p = first; p != 0; p = p->next) {
        std::cout << p->value << std::endl;
    }
}

void LinkedList::Push_front(Node *front) {
    size++;
    front->next = first;
}

void LinkedList::Push_back(Node *back) {
    size++;
    last -> next = back;
    last = back;
}

void LinkedList::Clear() {
    size = 0;
    // clear all elements
}

void LinkedList::Delete(Node *node) {
    size--;
    
}

void LinkedList::Reverse() {

}
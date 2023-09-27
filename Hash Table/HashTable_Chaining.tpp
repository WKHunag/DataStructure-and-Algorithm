//
// Created by 黃威凱 on 2023/9/22.
//

#include <iostream>
#include <functional>
#include "HashTable_Chaining.h"

template<typename K, typename V>
int HashTable_Chaining<K, V>::HashFunction(const K& key) const {
    std::hash<K> hashing;
    return hashing(key) % capacity;
}

template<typename K, typename V>
void HashTable_Chaining<K, V>::resize() {
    double loadfactor = occupied / (double)capacity;
    if ((loadfactor <= 0.25 && capacity <= 8) || (loadfactor > 0.25 && loadfactor < 1)) return;

    int origin_capacity = capacity;
    capacity = (loadfactor >= 1) ? capacity * 2 : capacity / 2;
    Node** newDict = new Node*[capacity];
    for (int i=0; i < capacity; i++) {
        newDict[i] = nullptr;
    }

    for (int i=0; i < origin_capacity; i++) {
        Node* temp = dict[i];
        while (temp != nullptr) {
            int index = HashFunction(temp -> key);
            newDict[index] = temp;
            temp = temp -> next;
        }
    }
    delete[] dict;
    dict = newDict;
}

template<typename K, typename V>
HashTable_Chaining<K, V>::HashTable_Chaining(int initial_capacity) : capacity(initial_capacity) {
    dict = new Node*[capacity];
    for (int i = 0; i < capacity; ++i) {
        dict[i] = nullptr;
    }
}

template <typename K, typename V>
HashTable_Chaining<K, V>::~HashTable_Chaining() {
    for (int i = 0; i < capacity; ++i) {
        while (dict[i]) {
            Node* temp = dict[i];
            dict[i] = dict[i]->next;
            delete temp;
        }
    }
}

template<typename K, typename V>
int HashTable_Chaining<K, V>::size() const {
    return occupied;
}

template<typename K, typename V>
void HashTable_Chaining<K, V>::insertion(const K& key, const V& value) {
    resize();
    long index = this -> HashFunction(key);
    Node* temp = new Node(key, value);
    Node* cur = dict[index];
    while (cur != nullptr) {
        if (cur -> key == key) {
            throw std::invalid_argument("Error: The key already existed.");
        }
        cur = cur -> next;
    }
    temp -> next = dict[index];
    dict[index] = temp;
    occupied++;
}

template<typename K, typename V>
void HashTable_Chaining<K, V>::deletion(const K &key) {
    resize();
    long index = this -> HashFunction(key);
    if (dict[index] == nullptr){
        throw std::invalid_argument("Error: Attempt delete the element not in the tree.");
    }
    Node* cur = dict[index];
    Node* pre = nullptr;
    while (cur) {
        if (cur -> key == key) {
            if (pre) {
                pre -> next = cur -> next;
            } else {
                dict[index] = cur -> next;
            }
            occupied--;
        }
        pre = cur;
        cur = cur -> next;
    }
}

template<typename K, typename V>
V HashTable_Chaining<K, V>::get(const K &key) const {
    long index = this -> HashFunction(key);
    if (dict[index] == nullptr){
        throw std::invalid_argument("Error: Attempt get the element not in the tree.");
    }
    Node* temp = dict[index];
    while (temp -> key != key){
        temp = temp -> next;
    }
    return temp -> value;
}
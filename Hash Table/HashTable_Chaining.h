//
// Created by 黃威凱 on 2023/9/22.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_HASHTABLE_CHAINING_H
#define DATA_STRUCTURE_AND_ALGORITHM_HASHTABLE_CHAINING_H
#include <iostream>
#include "HashTable.h"

template<typename K, typename V>
class HashTable_Chaining : public HashTable<K, V> {
private:
    struct Node {
        K key;
        V value;
        Node* next;

        Node(const K& newKey, const V& newValue) : key(newKey), value(newValue), next(nullptr) {};
    };
    int occupied = 0;
    Node** dict;
    int capacity;

    int HashFunction(const K& key) const;
    void resize();
public:
    HashTable_Chaining(int initial_capacity = 8);
    ~HashTable_Chaining();

    int size() const override;
    void insertion(const K& key, const V& value) override;
    void deletion(const K& key) override;
    V get(const K& key) const override;
};

#include "HashTable_Chaining.tpp"
#endif //DATA_STRUCTURE_AND_ALGORITHM_HASHTABLE_CHAINING_H

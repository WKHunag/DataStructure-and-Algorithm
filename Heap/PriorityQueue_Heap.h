//
// Created by 黃威凱 on 2023/10/17.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_PRIORITYQUEUE_HEAP_H
#define DATA_STRUCTURE_AND_ALGORITHM_PRIORITYQUEUE_HEAP_H
#include "PriorityQueue.h"

template<typename K, typename V>
class PriorityQueue_Heap : PriorityQueue<K, V>{
private:
    struct Pair{
        K key;
        V value;

        Pair(const K& newKey, const V& newValue) : key(newKey), value(newValue) {};
    };
    int capacity;
    int occupied = 0;
    Pair* heap;

    void resize();
    void HeapifyUp(int index);
    void HeapifyDown(int index);
public:
    PriorityQueue_Heap(int initial_capacity = 8);
    ~PriorityQueue_Heap();

    int size() const override;
    bool isEmpty();
    void put(const K& key, const V& value) override;
    V removeSmallest() override;
    V getSmallest() const override;
};

#include "PriorityQueue_Heap.tpp"
#endif //DATA_STRUCTURE_AND_ALGORITHM_PRIORITYQUEUE_HEAP_H

//
// Created by 黃威凱 on 2023/10/17.
//
#include <iostream>
#include "PriorityQueue_Heap.h"

template<typename K, typename V>
void PriorityQueue_Heap<K, V>::resize() {
    double usage = occupied / (double)capacity;
    if ((capacity <= 8 && usage <= 0.25) || (usage > 0.25 && usage < 1)) return;

    int newCapacity = (usage <= 0.25) ? capacity / 2 : capacity * 2;
    Pair* newHeap = new Pair[newCapacity];
    for (int i = 0; i < occupied; i++) {
        newHeap[i] = heap[i];
    }
    capacity = newCapacity;
    delete[] heap;
    heap = newHeap;
}

template<typename K, typename V>
void PriorityQueue_Heap<K, V>::HeapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index].key > heap[parentIndex].key) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

template<typename K, typename V>
void PriorityQueue_Heap<K, V>::HeapifyDown(int index) {
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    int smallest = index;

    if (leftChild < occupied && heap[leftChild].key < heap[smallest].key){
        smallest = leftChild;
    }

    if (rightChild < occupied && heap[rightChild].key < heap[smallest].key) {
        smallest = rightChild;
    }

    if (smallest != index) {
        std::swap(heap[smallest], heap[index]);
        HeapifyDown(smallest);
    }
}

template<typename K, typename V>
PriorityQueue_Heap<K, V>::PriorityQueue_Heap(int initial_capacity):capacity(initial_capacity) {
    heap = new Pair[capacity];
};

template<typename K, typename V>
PriorityQueue_Heap<K, V>::~PriorityQueue_Heap(){
    delete[] heap;
}

template<typename K, typename V>
int PriorityQueue_Heap<K, V>::size() const {
    return occupied;
}

template<typename K, typename V>
void PriorityQueue_Heap<K, V>::put(const K &key, const V &value) {
    Pair item(key, value);
    heap[occupied] = item;
    HeapifyUp(occupied);
    occupied++;
    resize();
}

template<typename K, typename V>
V PriorityQueue_Heap<K, V>::removeSmallest() {
    if (occupied == 0) {
        throw std::underflow_error("Error: Attempt to access data from an empty queue.");
    }
    V smallest = heap[0].value;
    heap[0] = heap[occupied - 1];
    HeapifyDown(0);
    occupied--;

    return smallest;
}

template<typename K, typename V>
V PriorityQueue_Heap<K, V>::getSmallest() const {
    if (occupied == 0) {
        throw std::underflow_error("Error: Attempt to access data from an empty queue.");
    }
    return heap[0].value;
}
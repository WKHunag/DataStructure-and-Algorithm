//
// Created by 黃威凱 on 2023/8/19.
//
#include "Deque_Arr.h"
#include <stdexcept>

template<typename T>
Deque_Arr<T>::Deque_Arr(int initialCapacity) : capacity(initialCapacity) {
    arr = new T[capacity];
}

template<typename T>
void Deque_Arr<T>::resize(int newCapacity) {
    T* newArr = new T[newCapacity];
    int newIndex = 0;

    for (int i = headIndex; i != tailIndex; i = (i + 1) % capacity) {
        newArr[newIndex] = arr[i];
        newIndex++;
    }
    newArr[newIndex] = arr[tailIndex];

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
    headIndex = 0;
    tailIndex = length - 1;
}

template<typename T>
Deque_Arr<T>::~Deque_Arr() {
    delete[] arr;
}

template<typename T>
int Deque_Arr<T>::size() const {
    return length;
}

template<typename T>
bool Deque_Arr<T>::isEmpty() const {
    return size() == 0;
}

template<typename T>
bool Deque_Arr<T>::isFull() {
    return length = capacity;
}

template<typename T>
void Deque_Arr<T>::addFirst(T newFirst) {
    if (capacity - tailIndex <= 3) {
        int newCapacity = capacity * 2;
        resize(newCapacity);
    }

    for (int i = tailIndex; i >= 0; i--){
        arr[i+1] = arr[i];
    }
    tailIndex++;
    arr[0] = newFirst;
    length++;
}

template<typename T>
void Deque_Arr<T>::addLast(T newLast) {
    if (capacity - tailIndex <= 3) {
        // Double the capacity and copy elements to the new array
        int newCapacity = capacity * 2;
        resize(newCapacity);
    }

    tailIndex++;
    arr[tailIndex] = newLast;
    length++;
}

template<typename T>
T Deque_Arr<T>::removeFirst() {
    if (isEmpty()) {
        throw std::underflow_error("Error: Attempt to access data from an empty deque.");
    }

    T poppedValue = arr[0];

    for (int i = 1; i <= tailIndex; i++) {
        arr[i-1] = arr[i];
    }
    length--;
    tailIndex--;
    return poppedValue;
}

template<typename T>
T Deque_Arr<T>::removeLast() {
    if (isEmpty()) {
        throw std::underflow_error("Error: Attempt to access data from an empty deque.");
    }

    T poppedValue = arr[tailIndex];
    arr[tailIndex] = 0;
    tailIndex--;
    length--;
    return poppedValue;
}

template<typename T>
T Deque_Arr<T>::get(int index) const {
    if (isEmpty()) {
        throw std::underflow_error("Error: Attempt to access data from an empty deque.");
    }

    if (index < 0 || index >= length) {
        throw std::out_of_range("Error: Index is out of range");
    }

    return arr[index];
}

template<typename T>
void Deque_Arr<T>::printDeque() const {
    if (isEmpty()) {
        std::cout << "The deque is empty." << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int currentIndex=0; currentIndex <= tailIndex; currentIndex++) {
        std::cout << arr[currentIndex] << " ";
    }
    std::cout << "]" << std::endl;
}
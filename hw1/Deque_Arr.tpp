//
// Created by 黃威凱 on 2023/8/19.
//
#include "Deque_Arr.h"
#include <stdexcept>

template<typename T>
Deque_Arr<T>::Deque_Arr(int initialCapacity) : capacity(initialCapacity) {
    arr = new T[capacity];
};

template<typename T>
void Deque_Arr<T>::resize() {
    double usage = length / (double)capacity;
    if ((usage <= 0.25 && capacity <= 10) || (!isFull() && usage > 0.25)) return;

    int newCapacity = usage <= 0.25 ? capacity / 2 : capacity * 2;
    T* newArr = new T[newCapacity];
    int iter_times =  fmax((capacity-headIndex-1), (tailIndex-1));
    for (int i = 0; i < iter_times; i++) {
        newArr[newCapacity - 1 - i] = arr[capacity - 1 - i];
        newArr[i] = arr[i];
    }
    headIndex = newCapacity - (capacity - headIndex);
    capacity = newCapacity;
    delete[] arr;
    arr = newArr;
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
bool Deque_Arr<T>::isFull() const {
    return (headIndex < tailIndex);
}

template<typename T>
void Deque_Arr<T>::addFirst(T newFirst) {
    resize();
    arr[headIndex] = newFirst;
    headIndex--;
    length++;
}

template<typename T>
void Deque_Arr<T>::addLast(T newLast) {
    resize();
    arr[tailIndex] = newLast;
    tailIndex++;
    length++;
}

template<typename T>
T Deque_Arr<T>::removeFirst() {
    if (isEmpty()) {
        throw std::underflow_error("Error: Attempt to access data from an empty deque.");
    }

    T poppedValue = arr[headIndex];
    headIndex++;
    length--;
    resize();
    return poppedValue;
}

template<typename T>
T Deque_Arr<T>::removeLast() {
    if (isEmpty()) {
        throw std::underflow_error("Error: Attempt to access data from an empty deque.");
    }

    T poppedValue = arr[tailIndex];
    tailIndex--;
    length--;
    resize();
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

    return arr[(index + headIndex + 1) % capacity];
}

template<typename T>
void Deque_Arr<T>::printDeque() const {
    if (isEmpty()) {
        std::cout << "The deque is empty." << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int i = (headIndex + 1); i < (headIndex + 1 + length); i++) {
        std::cout << arr[i % capacity] << " ";
    }
    std::cout << "]" << std::endl;
}
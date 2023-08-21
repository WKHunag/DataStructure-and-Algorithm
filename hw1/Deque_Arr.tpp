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
    if (usage <= 0.25 && capacity <= 10 || (!isFull() && usage > 0.25)) return;

    int newCapacity = usage <= 0.25 ? capacity / 2 : capacity * 2;
    T* newArr = new T[newCapacity];
    int iter_times =  (capacity-headIndex-1) >= tailIndex ? capacity - headIndex - 1 : tailIndex;
    for (int i = 0; i <= iter_times; i++) {
        newArr[newCapacity - i] = arr[capacity - i];
        newArr[i] = i <= tailIndex ? arr[i] : arr[capacity - i];
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

    return index + headIndex + 1 <= capacity - 1 ? arr[index + headIndex + 1] : arr[index + headIndex - capacity + 1];
}

template<typename T>
void Deque_Arr<T>::printDeque() const {
    if (isEmpty()) {
        std::cout << "The deque is empty." << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int i = 0; i < length; i++) {
        int cur =  i + headIndex + 1 <= capacity - 1 ? arr[i + headIndex + 1] : arr[i + headIndex - capacity + 1];
        std::cout << cur << " ";
    }
    std::cout << "]" << std::endl;
}
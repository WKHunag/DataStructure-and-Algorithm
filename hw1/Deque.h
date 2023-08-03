//
// Created by 黃威凱 on 2023/7/28.
//

#ifndef HOMEWORK_DEQUE_H
#define HOMEWORK_DEQUE_H

/*
	Homework1

	1. Create a class inherit the below class Deque
	   by using array data structure.
	2. Create a class inherit the below class Deque
	   by using linked list data structure.

	Requirement:
	You are not allowed to use any C's/C++'s built in data structure class,
	including dynamic array, vector.
	All you can use are basic array and the classes built by yourselves.
	The only function you can to use from C++'s libraries is "cout" to print content on the console.
*/

/// <summary>
/// double end queue
/// </summary>
/// <typeparam name="T"> the type of the item that the deque hold</typeparam>
#include "Node.h"

template<typename T>
class Deque
{
public:
    /// <summary>
    /// return quantity of items in the Deque
    /// </summary>
    /// <returns> quantity of items in the Deque </returns>
    virtual int size() {}

    /// <summary>
    /// add the item at the beginning of the Deque
    /// </summary>
    /// <param name="item"></param>
    virtual void addFirst(T item) {}

    /// <summary>
    /// add the item at the end of the Deque
    /// </summary>
    /// <param name="item"></param>
    virtual void addLast(T item) {}

    /// <summary>
    /// return true if Deque is empty
    /// </summary>
    /// <returns> true if the Deque is empty </returns>
    virtual bool isEmpty()
    {
        return size() == 0;
    }

    /// <summary>
    /// print out all items in the deque, seperate by the space, " "
    /// </summary>
    virtual void printDeque() {}

    /// <summary>
    /// remove the first item of the Deque
    /// </summary>
    /// <returns> the removed item </returns>
    virtual T removeFirst() {}

    /// <summary>
    /// remove the last item of the Deque
    /// </summary>
    /// <returns> the removed item </returns>
    virtual T removeLast() {}

    /// <summary>
    /// given the index and return the item at the position given index
    /// </summary>
    /// <param name="index"></param>
    /// <returns> the item at the index </returns>
    virtual T get(int index) {}
};

template struct Deque<int>;
template struct Deque<double>;
template struct Deque<char>;

template<typename T>
class Deque_LL : public Deque<Node<T>> {
private:
    int length;
    Node<T> *first = new Node<T>();
    Node<T> *last = new Node<T>();
public:
    Deque_LL();
    Deque_LL(Node<T> head);

    int size() override;
    void addFirst(Node<T> item) override;
    void addLast(Node<T> item) override;
    void printDeque() override;
    Node<T> removeFirst() override;
    Node<T> removeLast() override;
    Node<T> get(int index) override;
};


class Deque_Arr : public Deque<int> {
private:
    int capacity;
    int pos1st;
    int poslast;
    int *queue;

    bool isFull(){
        return poslast + 1 == capacity;
    };

    void DoubleCapacityQueue(){
        int newCapacity = capacity * 2;
        int *newStart = new int[newCapacity];
        int cur = -1;
        for (int i = pos1st; i <= poslast; i++){
            cur++;
            newStart[cur] = queue[i];
        }
        pos1st = -1;
        poslast = cur;
        queue = newStart;
    }

public:
    Deque_Arr();
    int size() override;
    void addFirst(int newFirst) override;
    void addLast(int newLast) override;
    bool isEmpty() override;
    void printDeque() override;
    int removeFirst() override;
    int removeLast() override;
    int get(int index) override;
};


#endif //HOMEWORK_DEQUE_H

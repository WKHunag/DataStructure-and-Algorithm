#include <iostream>
#include "Deque.h"
#include "Deque_Arr.h"
#include "Deque_LL.h"
using namespace std;

int main() {
//    Arrar
    Deque_Arr<int> queueArray;
    queueArray.addFirst(5);
    queueArray.addFirst(10);
    queueArray.addLast(0);
    queueArray.addLast(15);
    cout << "Double ended queue(implemented with array):" << endl;
    queueArray.printDeque();
    queueArray.removeLast();
    queueArray.removeFirst();
    cout << "Double ended queue after remove elements(implemented with array):" << endl;
    queueArray.printDeque();
    cout << "The first element in the queue: \n" << queueArray.get(1) << endl;

    cout << endl;

//    Linked List
    Deque_LL<int> queueLinkedList;
    queueLinkedList.addFirst(5);
    queueLinkedList.addFirst(10);
    queueLinkedList.addLast(0);
    queueLinkedList.addLast(15);
    cout << "Double ended queue(implemented with linked list):" << endl;
    queueLinkedList.printDeque();
    queueLinkedList.removeLast();
    queueLinkedList.removeFirst();
    cout << "Double ended queue after remove elements(implemented with linked list):" << endl;
    queueLinkedList.printDeque();
    cout << "The first element in the queue: \n" << queueLinkedList.get(1) << endl;
    return 0;
}
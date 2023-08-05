#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
//    Arrar
    Deque_Arr<int> queueArray;
    queueArray.addFirst(5);
    queueArray.addLast(10);
    queueArray.addFirst(0);
    /*
        unnecessary double brackets
    */
    queueArray.addLast((15));
    /*
        no need to keep the unnecessary comment
    */
//    queueArray.removeLast();
//    queueArray.removeFirst();
    cout << "Double ended queue(implemented with array):" << endl;
//    cout << queueArray.get(1) << endl;
    queueArray.printDeque();
//    Linked List
    Deque_LL<int> queueLinkedList;
    queueLinkedList.addFirst(Node<int>(5));
    queueLinkedList.addLast(Node<int>(10));
    queueLinkedList.addFirst(Node<int>(0));
    queueLinkedList.addLast(Node<int>(15));
//    queueLinkedList.removeLast();
//    queueLinkedList.removeFirst();
    cout << "Double ended queue(implemented with linked list)" << endl;
    queueLinkedList.printDeque();
    return 0;
}
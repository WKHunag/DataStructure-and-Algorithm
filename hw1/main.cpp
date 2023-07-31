#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
//    Arrar
    Deque_Arr queueArray;
    queueArray.addFirst(5);
    queueArray.addLast(10);
    queueArray.addFirst(0);
    queueArray.addLast((15));
    queueArray.removeLast();
    queueArray.removeFirst();
    cout << "Double ended queue(implemented with array):" << endl;
    cout << queueArray.get(1) << endl;
    queueArray.printDeque();
//    Linked List
    Deque_LL<int, Node> queueLinkedList;
    queueLinkedList.addFirst(5);
    queueLinkedList.addLast(10);
    queueLinkedList.addFirst(0);
    queueLinkedList.addLast(15);
    queueLinkedList.removeLast();
    queueLinkedList.removeFirst();
    cout << "Double ended queue(implemented with linked list)" << endl;
    cout << queueLinkedList.get(1).value << endl;
    queueLinkedList.printDeque();
    return 0;
}
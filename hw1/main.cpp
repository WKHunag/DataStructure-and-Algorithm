#include <iostream>
#include "Deque.h"
#include "Deque_Arr.h"
#include "Deque_LL.h"
using namespace std;

int main() {
//    Arrar
    Deque<int> *queue = new Deque_Arr<int>();
//    Linked List
//    Deque<int> *queue = new Deque_LL<int>();

    queue -> addLast(5);
    queue -> addLast(10);
    queue -> addLast(0);
    queue -> addLast(15);
    queue -> addLast(5);
    queue -> addLast(10);
    queue -> addLast(0);
    queue -> addLast(15);
    queue -> addLast(5);
    queue -> addLast(10);
    queue -> addLast(0);
    queue -> addLast(15);
    cout << "Double ended queue(implemented with array):" << endl;
    queue -> printDeque();
    queue -> removeFirst();
    queue -> printDeque();
    queue -> removeFirst();
    queue -> printDeque();
    queue -> removeFirst();
    queue -> printDeque();
    queue -> removeFirst();
    queue -> printDeque();
    queue -> removeFirst();
    queue -> printDeque();
    queue -> removeFirst();
    queue -> printDeque();
    queue -> removeFirst();
    cout << "Double ended queue after remove elements(implemented with array):" << endl;
    queue -> printDeque();
    cout << "The first element in the queue: \n" << queue -> get(0) << endl;

    return 0;
}
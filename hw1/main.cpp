#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
    int a = 5;
    Deque_Arr queue;
    queue.addLast(a);
    queue.addLast(10);
    queue.addFirst(0);
    queue.removeLast();
    queue.printDeque();
    return 0;
}
#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
    Node a = 5;
    Node b = 10;
    Node *head;
    head = &a;
    Deque_LL test;
    test.addFirst(head);
    test.addFirst(&b);
    cout << test.get(1).value << endl;
    return 0;
}

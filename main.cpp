#include <iostream>
#include <random>
#include "Hash Table/HashTable_Chaining.h"
#include "Binary Search Tree/BST.h"

int main() {
    BinarySearchTree<int>* bst = new BST<int>();
    HashTable<int, int>* table = new HashTable_Chaining<int, int>();
    for (int i=0; i<100; i++) {
        table -> insertion(i, i+1);
    }

    std::cout << table -> get(99) << std::endl;
    return 0;
}
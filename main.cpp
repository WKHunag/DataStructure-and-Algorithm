#include <iostream>
#include <random>
#include "Binary Search Tree/BST.h"

int main() {
    BinarySearchTree<int>* bst = new BST<int>();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);

    for (int i = 0; i < 3; ++i) {  // Adjust the loop count as needed
        int randomNum = distribution(gen);
        bst -> insertion(randomNum);
    }

    bst -> printTree();
    return 0;
}

#include <iostream>
#include "TreeNode.h"
#include "BST.h"

int main() {
    BST<int> *Tree;
    Tree -> insertion(5);
    Tree -> insertion(2);
    Tree -> printTree();
    return 0;
}

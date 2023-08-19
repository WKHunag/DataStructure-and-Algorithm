#include <iostream>
#include "TreeNode.h"
#include "BST.h"

int main() {
    BST<int> *Tree;
    int a = 5;
    int b = 2;
    Tree -> insertion(a);
    Tree -> insertion(b);
    Tree -> printTree();
    return 0;
}

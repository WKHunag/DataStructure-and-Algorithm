//
// Created by 黃威凱 on 2023/8/16.
//
#include <iostream>
#include "BST.h"

template<typename T>
BST<T>::BST() = default;

template<typename T>
void BST<T>::CuttingDown(TreeNode<T> *node) {
    if (node != 0) {
        CuttingDown(node -> left);
        CuttingDown(node -> right);
    }
}

template<typename T>
BST<T>::~BST() {
    CuttingDown(root);
}

template<typename T>
int BST<T>::size() {
    return quantity;
}

template<typename T>
TreeNode<T> *BST<T>::inserting(TreeNode<T> *node, TreeNode<T> *newParent, const T& item) {
    if (node == 0) {
        return new TreeNode<T>(item, newParent);
    }

    if (node->value > item) {
        inserting(node -> left, node, item);
    } else {
        inserting(node -> right, node, item);
    }

    return node;
}

template<typename T>
void BST<T>::insertion(const T &item) {
    root = inserting(root, nullptr, item);
    quantity ++;
}

template<typename T>
void BST<T>::deletion(const T &item) {
    if (not search(item) || root == 0) {
        throw std::invalid_argument("Error: Attempt delete the element not in the tree.");
    }

}

template<typename T>
bool BST<T>::search(const T &item) const {
    TreeNode<T> *cur = root;
    while (cur != 0) {
        if (item == cur -> value) {
            return true;
        } else if (item > cur -> value){
            cur = cur -> right;
        } else {
            cur = cur -> left;
        }
    }
    cur = nullptr;
    delete cur;
    return false;
}

template<typename T>
const T& BST<T>::top() const {
    return root -> value;
}

template <typename T>
void BST<T>::InOrder(TreeNode<T> *node) const {
    if (node != 0) {
        InOrder(node -> left);
        std::cout << node -> value << ' ';
        InOrder(node -> right);
    }
}

template<typename T>
void BST<T>::printTree() const {
    InOrder(root);
    std::cout << std::endl;
}

template<typename T>
int BST<T>::height(TreeNode<T> *node) {
    if (node == 0) {
        return -1;
    }
    return 1 + std::max(height(node -> left), height(node -> right));
}

template<typename T>
void BST<T>::balance(){
    /// Implement.
}
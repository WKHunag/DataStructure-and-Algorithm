//
// Created by 黃威凱 on 2023/8/16.
//
#include <iostream>
#include <iomanip>
#include "BST.h"

template<typename T>
BST<T>::BST() = default;

template<typename T>
void BST<T>::CuttingDown(TreeNode<T> *node) {
    if (node != nullptr) {
        CuttingDown(node -> left);
        CuttingDown(node -> right);
        delete node;
    }
}

template<typename T>
BST<T>::~BST() {
    CuttingDown(root);
}

template<typename T>
TreeNode<T> *BST<T>::findMax(TreeNode<T>* node) {
    while (node -> right != nullptr) {
        node = node -> right;
    }
    return node;
}

template<typename T>
TreeNode<T>* BST<T>::findMin(TreeNode<T> *node) {
    while (node -> left != nullptr) {
        node = node -> left;
    }
    return node;
}

template<typename T>
int BST<T>::size() {
    return quantity;
}

template<typename T>
TreeNode<T>* BST<T>::inserting(TreeNode<T>* node, TreeNode<T>* newParent, const T& item) {
    if (node == nullptr) {
        quantity++;
        return new TreeNode<T>(item, newParent);
    }

    if (node -> value > item) {
        node -> left = inserting(node -> left, node, item);
    } else if (node -> value < item) {
        node -> right = inserting(node -> right, node, item);
    }
    return node;
}

template<typename T>
void BST<T>::insertion(const T& item) {
    root = inserting(root, nullptr, item);
}

template<typename T>
TreeNode<T>* BST<T>::deleting(TreeNode<T>* node, const T& item) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node -> value < item) {
        node -> right = deleting(node -> right, item);
    } else if (node -> value > item) {
        node -> left = deleting(node -> left, item);
    } else {
        TreeNode<T>* temp;
        if (node -> right == nullptr && node -> left == nullptr){
            quantity--;
            delete node;
            return nullptr;
        } else if (node -> left == nullptr) {
            temp = findMin(node -> right);
            node -> value = temp -> value;
            node -> right = deleting(node -> right, node -> value);
        } else {
            temp = findMax(node -> left);
            node -> value = temp -> value;
            node -> left = deleting(node -> left, node -> value);
        }
    }
    return node;
}

template<typename T>
void BST<T>::deletion(const T& item) {
    if (root == 0) {
        throw std::invalid_argument("Error: Attempt delete the element not in the tree.");
    }
    root = deleting(root, item);
    quantity--;
}

template<typename T>
bool BST<T>::search(const T& item) const {
    TreeNode<T>* node = root;
    while (node != nullptr) {
        if (node -> value == item) {
            return true;
        } else if (node -> value < item) {
            node = node -> right;
        } else {
            node = node -> left;
        }
    }
    return false;
}

template<typename T>
const T& BST<T>::top() const {
    if (root == nullptr) {
        throw std::invalid_argument("Error: Tree is empty");
    }
    return root -> value ;
}

template <typename T>
void BST<T>::InOrder(TreeNode<T>* node, int space) const {
    if (node == nullptr){
        return;
    }

    // Increase distance between levels
    space += 5;
    // Process right child first
    InOrder(node -> right, space);
    // Print current node after space
    std::cout << std::endl;
    std::cout << std::setw(space - 5) << node -> value<< std::endl;
    // Process left child
    InOrder(node -> left, space);
}

template<typename T>
void BST<T>::printTree() const {
    if (root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }
    InOrder(root, 0);
}
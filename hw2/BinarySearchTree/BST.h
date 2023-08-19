//
// Created by 黃威凱 on 2023/8/16.
//

#ifndef PRIORITYQUEUE_BST_H
#define PRIORITYQUEUE_BST_H
#pragma once

#include "BinarySearchTree.h"
#include "TreeNode.h"

template<typename T>
class BST : public BinarySearchTree<T> {
private:
    TreeNode<T> *root;
    int quantity = 0;
    TreeNode<T> *inserting(TreeNode<T> *node, TreeNode<T> *newParent, const T& item);
    void InOrder(TreeNode<T> *node) const;
    void CuttingDown(TreeNode<T> *node);
    // For implement Balance Binary Search Tree
    int height(TreeNode<T> *node);
    void balance();

public:
    BST();
    int size() override;
    void insertion(const T& item) override;
    void deletion(const T& item) override;
    bool search(const T& item) const override;
    const T& top() const override;
    void printTree() const override;
    ~BST();
};

#include "BST.tpp"
#endif //PRIORITYQUEUE_BST_H
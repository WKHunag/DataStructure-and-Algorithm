//
// Created by 黃威凱 on 2023/8/16.
//

#ifndef PRIORITYQUEUE_TREENODE_H
#define PRIORITYQUEUE_TREENODE_H
#pragma once

template<typename T>
class TreeNode {
public:
    T value;
    TreeNode *parent = nullptr;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode();
    TreeNode(const T& data, TreeNode<T> *newParent = nullptr);
    ~TreeNode();
};

#include "TreeNode.tpp"
#endif //PRIORITYQUEUE_TREENODE_H
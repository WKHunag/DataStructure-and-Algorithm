//
// Created by 黃威凱 on 2023/8/16.
//

#include "TreeNode.h"
template<typename T>
TreeNode<T>::TreeNode() = default;

template<typename T>
TreeNode<T>::TreeNode(const T& data, TreeNode<T> *newParent) : value(data), parent(newParent), left(nullptr), right(nullptr) {};

template<typename T>
TreeNode<T>::~TreeNode() = default;
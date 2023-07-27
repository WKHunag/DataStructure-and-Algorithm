//
// Created by 黃威凱 on 2023/7/27.
//

#ifndef HOMEWORK_LINKEDLIST_H
#define HOMEWORK_LINKEDLIST_H

class LinkedList;

class Node{
private:
    int value;
    Node *next;
public:
    Node():value(0),next(nullptr){};
    Node(int a):value(a),next(nullptr){};

    friend class LinkedList;
};

class LinkedList{
private:
    Node *first;
public:
public:
    LinkedList();;
    void PrintList();           // 印出list的所有資料
    void Push_front(int x);     // 在list的開頭新增node
    void Push_back(int x);      // 在list的尾巴新增node
    void Delete(int x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
    void Reverse();             // 將list反轉: 7->3->14 => 14->3->7
};


#endif //HOMEWORK_LINKEDLIST_H

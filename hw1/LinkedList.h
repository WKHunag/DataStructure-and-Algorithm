//
// Created by 黃威凱 on 2023/7/27.
//

#ifndef HOMEWORK_LINKEDLIST_H
#define HOMEWORK_LINKEDLIST_H

class LinkedList;

class Node{

public:
    Node():value(0),next(nullptr){};
    Node(int a):value(a),next(nullptr){};

    int value;
    Node *next;

    friend class LinkedList;
};

class LinkedList{
private:
    int size;
    Node *first;
    Node *last;

public:
    LinkedList();
    LinkedList(Node *head);
    void PrintList();          
    void GetSize(); // Print all the elements in the list
    void Push_front(Node *front);     // Add a new element to the front of the list
    void Push_back(Node *back);      // Add a new element to the back of the list
    void Delete(Node *node);         // Delete a node from the list
    void Clear();               // Delete all the elements in the list
    void Reverse();             // Reverse the list
};


#endif //HOMEWORK_LINKEDLIST_H

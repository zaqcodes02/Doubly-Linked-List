#ifndef Lish_h
#define Lish_h
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertatFirst(T data);
    void insertatLast(T data);
    void insert(T data, int pos);
    void deleteatFirst();
    void deleteatLast();
    void deleteData(T data);
    bool isEmpty() const;
    void printList();
};

#endif
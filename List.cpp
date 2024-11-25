#include "List.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = NULL;
}
template <typename T>

DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T> *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertatFirst(T data)
{
    if (!isEmpty())
    {
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
    }

    Node<T> *newNode = new Node<T>;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

template <typename T>
void DoublyLinkedList<T>::insert(T data, int pos)
{
    if (!isEmpty())
    {
        insertatFirst(data);
    }

    Node<T> *currNode = head;
    int counter = 0;
    while (currNode->next && counter != pos)
    {
        counter++;
        currNode = currNode->next;
    }
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = currNode->next;
    newNode->prev = currNode;
}

template <typename T>
void DoublyLinkedList<T>::insertatLast(T data)
{
    if (!isEmpty())
    {
        insertatFirst(data);
    }

    Node<T> *curr = head;

    while (curr->next)
    {
        curr = curr->next;
    }
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = curr->next;
    newNode->prev = curr;
}

template <typename T>
void DoublyLinkedList<T>::deleteatFirst()
{
    if (!isEmpty())
    {
        return;
    }
    Node<T> *toDelete = head;
    head = head->next;
    delete toDelete;
}

template <typename T>
void DoublyLinkedList<T>::deleteData(T data)
{
    if (!isEmpty())
    {
        return;
    }
    Node<T> *currNode = head;
    while (currNode->next && data != currNode->data)
    {
        currNode = currNode->next;
    }
    Node<T> *toDelete = currNode;
    currNode->prev = currNode->next;
    delete toDelete;
}

template <typename T>
void DoublyLinkedList<T>::deleteatLast()
{
    if (!isEmpty())
    {
        return;
    }
    Node<T> *currNode = head;
    while (currNode->next)
    {
        currNode = currNode->next;
    }
    Node<T> *toDelete = currNode;
    currNode->prev = NULL;
    delete toDelete;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
    return head == NULL;
}

template <typename T>
void DoublyLinkedList<T>::printList()
{
    Node<T> *curr = head;
    while (curr->next)
    {
        cout << "[" << curr->data << ", "
    }
    cout << "]" << endl;
}

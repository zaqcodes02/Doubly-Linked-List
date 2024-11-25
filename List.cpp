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
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr)
    {
        head->prev = newNode;
    }

    head = newNode;
}

template <typename T>
void DoublyLinkedList<T>::insert(T data, int pos)
{
    if (pos == 0)
    {
        insertatFirst(data);
        return;
    }

    Node<T> *currNode = head;
    int counter = 0;

    while (currNode != nullptr && counter < pos - 1)
    {
        counter++;
        currNode = currNode->next;
    }

    if (currNode == nullptr)
    {
        insertatLast(data);
        return;
    }

    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = currNode->next;
    newNode->prev = currNode;

    if (currNode->next != nullptr)
    {
        currNode->next->prev = newNode;
    }
    currNode->next = newNode;
}

template <typename T>
void DoublyLinkedList<T>::insertatLast(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node<T> *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;
}

template <typename T>
void DoublyLinkedList<T>::deleteatFirst()
{
    if (isEmpty())
    {
        return;
    }

    Node<T> *toDelete = head;
    head = head->next;

    if (head != nullptr)
    {
        head->prev = nullptr;
    }

    delete toDelete;
}

template <typename T>
void DoublyLinkedList<T>::deleteData(T data)
{
    if (isEmpty())
    {
        return;
    }

    Node<T> *currNode = head;
    while (currNode != nullptr && currNode->data != data)
    {
        currNode = currNode->next;
    }

    if (currNode == nullptr)
    {
        return; // Data not found
    }

    if (currNode->prev != nullptr)
    {
        currNode->prev->next = currNode->next;
    }

    if (currNode->next != nullptr)
    {
        currNode->next->prev = currNode->prev;
    }

    if (currNode == head)
    {
        head = currNode->next;
    }

    delete currNode;
}

template <typename T>
void DoublyLinkedList<T>::deleteatLast()
{
    if (isEmpty())
    {
        return;
    }

    Node<T> *currNode = head;
    while (currNode->next != nullptr)
    {
        currNode = currNode->next;
    }

    if (currNode->prev != nullptr)
    {
        currNode->prev->next = nullptr;
    }

    if (currNode == head)
    {
        head = nullptr;
    }

    delete currNode;
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
    while (curr)
    {
        cout << "[" << curr->data << ", ";
    }
    cout << "]" << endl;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<char>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<double>;

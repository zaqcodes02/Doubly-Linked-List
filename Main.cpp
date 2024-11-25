#include "List.h"

int main()
{
    cout << "Doubly Linked List" << endl;
    cout << "Insterting at first: " << endl;
    DoublyLinkedList<int> List;
    List.insertatFirst(12);
    List.printList();
    List.insertatFirst(4);
    List.printList();

    List.insert(8, 1);
    List.printList();

    List.insert(6, 2);
    List.printList();

    List.insertatLast(18);
    List.printList();

    List.insertatLast(20);
    List.printList();

    List.deleteatFirst();
    List.printList();

    List.deleteatLast();
    List.printList();

    List.deleteData(6);
    List.printList();

    return 0;
}

// Print elements of a linked list in forward and reverse order using recursion
// Recursive traversal of linked list.

#include <iostream>
using namespace std;

class Node
{
public:
    int number;
    Node *next;
};

void Print(Node *p)
{
    if (p == NULL) // Exit Condition : very imp to remember during recursive call
    {
        cout << endl;
        return;
    }
    cout << " " << p->number; // First print the value in the node
    Print(p->next);           // Recursive call
}
/* Note that,for normal traversal of linked list(for normal print) an iterative approach will be a lot more
efficient than the recursive approach because in iterative approach we will just use one temporary variable
while in recursion we will use space in the stack section of the memory for so many function calls so there is
implicit use of memory there.For ReversePrint we will any way have to store elements in some structure so if we
use recursion it's still okay.      See,Print() in LinkedList3.cpp for iterative approach */

void ReversePrint(Node *p)
{
    if (p == NULL) // Exit Condition : very imp to remember during recursive call
    {
        return;
    }
    ReversePrint(p->next);    // Recursive call
    cout << " " << p->number; // First print the value in the node
}

// Inserts node at end of list.
Node *Insert(Node *head, int data)
{
    Node *temp = new Node;
    temp->number = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        Node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

int main()
{
    Node *head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8); // List : 2 4 6 8
    cout << "List is :";
    Print(head);
    cout << "Reversed list is : ";
    ReversePrint(head);
    cout << endl;
}

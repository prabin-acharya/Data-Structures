// Reverse a linked list using recursion

#include <iostream>
using namespace std;

class Node
{
public:
    int number;
    Node *next;
};
Node *head; // Global variable

void Reverse(Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    p->next->next = p;
    /*struct Node * q = p->next;
    q->next = p; */
    p->next = NULL;
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

void Print(Node *head)
{
    cout << "List is : ";
    while (head != NULL)
    {
        cout << "  " << head->number;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8); // List : 2 4 6 8
    Print(head);
    Reverse(head);
    Print(head);
}

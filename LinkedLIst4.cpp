//Reverse a linked List -Iterative method.

#include<iostream>
using namespace std;

class Node
{
    public:
    int number;
    Node *next;
};

Node * Reverse(Node *head)
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;     //so that when we changed the adrress,we won't lose the remaaining list
        current->next = prev;     //
        prev = current;
        current = next;           //
    }
    //Here,prev stores the address of the last node.
    head = prev;
    return head;
}

//Inserts node at end of list.
Node * Insert(Node *head, int data)
{
    Node *temp = new Node;
    temp->number = data;
    temp->next = NULL;
    if(head == NULL) 
         head = temp;
    else
    {
        Node *temp1 = head;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

void Print(Node *head)
{
    cout << "List is : ";
    while(head != NULL)
    {
        cout << " " << head->number;
        head = head->next;
    }
    cout << endl;
}


int main()
{
    Node *head = NULL;     //local variable
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8); 
    head = Insert(head,10); ////List : 2 4 6 8 
    Print(head);
    head = Reverse(head);
    Print(head);
}

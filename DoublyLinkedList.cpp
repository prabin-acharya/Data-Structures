/*Doubly Linked List Implementation */
#include<iostream>
using namespace std;

class Node 
{
    public:
    int number;
    Node *prev;
    Node *next;
};
Node *head;     //Global variable

Node * GetNewNode(int data)
{
   Node * newnode = new Node;
   newnode->number = data;
   newnode->prev = NULL;
   newnode->next = NULL;
   return newnode;
}

void Print()
{
    Node *temp = head;
    cout << "List is : ";
    while(temp != NULL)
    {
        cout << " " << temp->number;
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtHead(int data)
{
    Node *temp = GetNewNode(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void InsertAtTail(int data)
{
    Node *temp1 = GetNewNode(data);
    Node *temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp1->prev = temp2;
    temp2->next = temp1;
    
}

void Insert(int data, int n)
{
    Node *temp1 = GetNewNode(data);
    if(n==1)
    {
        temp1->next = head;
        head->prev = temp1;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < n-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->prev = temp2;
    temp1->next = temp2->next;
    if(temp1->next==NULL)
    {
        //Do Nothing
    }
    else
    {
    temp1->next->prev = temp1;
    }
    temp2->next = temp1;
}

void Delete(int n)
{
    Node *temp2 = head;
    if(n == 1)
    {
        head->next->prev = NULL;
        head = head->next;
        return;
    }
    for (int i = 0; i < n-1; i++)
    {
        temp2 = temp2->next;
    }
    if(temp2->next == NULL)
    {
        temp2->prev->next = NULL;
        return;
    }
    temp2->next->prev = temp2->prev;
    temp2->prev->next = temp2->next;
    //temp2->next->next->prev = temp2;
    //temp2->next = temp2->next->next;
}

void ReversePrint()
{
    Node *temp = head;
    //Traversing to last node
    while(temp->next != NULL) 
    {
        temp = temp->next;
    }
    //Traversing backward using prev pointer
    cout << "Reverse List is : ";
    while(temp != NULL)
    {
        cout << " " << temp->number;
        temp = temp->prev;
    }
    cout << endl;
}

int main()  
{
    head = NULL;
    InsertAtHead(6);
    InsertAtHead(4);
    InsertAtHead(2);  //List is : 2 4 6
    Print();
    InsertAtTail(5);
    InsertAtTail(10);
    InsertAtTail(15);      //List is : 2 4 6 5 10 15
    Print();
    Insert(1, 1);       //1 2 4 6 5 10 15
    Insert(100, 5);     //1 2 4 6 100 5 10 15
    Insert(200, 3);     //1 2 200 4 6 100 5 10 15
    Insert(300, 10);     //List is : 1 2 200 4 6 100 5 10 15 300
    Print();
    Delete(10);   
    Print(); 
    ReversePrint();
}
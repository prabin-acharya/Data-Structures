//Inserting a node at beginning of Linked List.
#include<iostream>
using namespace std;

class Node
{
    public:
    int number;
    Node *next;
};
Node *head;    //global variable,can be accessed anywhere.

//Inserts node at beginning of list.
void Insert(int x)
{ 
    Node *temp = new Node;
    temp->number = x;
    temp->next = head;   //temp->next=NULL;  if(head!=NULL){temp->next=head};
    //Notice,This works for both empty list or list with elemwnts.
    head = temp;
}

void Print()
{
    Node *temp = head;
    /* Also note this head variable stores the address of head node.It is only a pointer
    not a head node itself.Also we do not have any identity of linked list except the address of head note. */
    cout << "List is :";
    while(temp != NULL)
    {
        cout << " " << temp->number;
        temp = temp->next;
    }
    cout << endl;
}
   
int main()
{
    head = NULL;  //empty list
    cout << "How many numbers? ";
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter the number : ";
        cin >> x;
        Insert(x);
        Print();
    }
}
//Delete a node at nth position in Linked list.

//Recalling Dynamic memory allocation is a good idea to better understand.
/*Remember: Memory allocated to our program/application  is typically devided into four sections:
 one section is used to store all the instructions that needs to be executed(Code);
another section is allocated to store the Global variables; 
another section called Stack is used to store all the information about function calls execution,to store all the
local variables.These three section are fixed in size,their size is decided at compile time.
The last section that we call Heap(or Free store) is not fixed and we can request memory from heap during runtime,
tha's what we do when we use malloc() or new operator. */

#include<iostream>
using namespace std;

class Node 
{
    public :
    int number;
    Node *next;
};
Node *head;          //Global variable  
/* Also note this head variable stores the address of head node.It is only a pointer
not a head node itself.Also we do not have any identity of linked list except the address of the head node. */
           
//Inserts an integer at end of list.
void Insert(int data)    
{
    Node *temp1=new Node();
    temp1->number=data;
    temp1->next=NULL;
    if(head==NULL)
    {
        head=temp1;
        return;
    }

    Node *temp2=head;
    while(temp2->next!=NULL)   //Vey imp to understand the differnce between temp!=NULL and temp->next!=NULL.
    {
        temp2=temp2->next;
    }
    //temp2 now stores the address of last node.
    temp2->next=temp1;
    /*Notice,how we inserted the node without assigning the changes to "head".This is due to we changed the address
    stored in last node through temp2.*/
}

//Print all the elements in list
void Print()            
{
    Node *temp=head;
    cout<<"List is : "<<endl;
    while(temp!=NULL)
    {
        cout<<" "<<temp->number;
        temp=temp->next;
    }
    //temp now stores NULL.
    cout<<endl;
}

//Deletes an integer at nth position
void Delete(int n)
{
    Node *temp1=head;
    if(n==1)
    {
        head=temp1->next;     //head now points to second node.
        delete temp1;
        /*Remember that,this deletes the memory(heap) allocated through "new".
         "temp1" is cleared from the memory(stack) when the function ends.*/
        return;
    }
    for(int i=0;i<n-2;i++)
        temp1=temp1->next;
    //temp1 points to (n-1)th node.
    Node *temp2=temp1->next;    //nth node
    temp1->next=temp2->next;    //(n+1)th node
    delete temp2;
} 

int main()
{
    head=NULL;      //empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);      //List : 2 4 6 8 
    Print();
    int n;
    cout<<"Enter a position to delete : ";
    cin>>n;
    cout<<endl;
    Delete(n);
    Print();
}

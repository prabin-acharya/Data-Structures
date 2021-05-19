//Inserting a node at nth position of LInked List.
#include<iostream>
using namespace std;

class Node
{
    public:
    int number;
    Node *next;
};
Node *head;   //Global variable

void Insert(int data, int n)
{
    //Creating a temporary node for the number to be added.
    Node *temp1 = new Node;
    temp1->number = data;
    temp1->next = NULL;
    //When node is added at the first position.Also works with empty list.
    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    //Adding node at nth position.
    Node *temp2 = head;
    //Accessing (n-1)th node.
    for(int i = 0; i < n-2; i++)
    {
        temp2 = temp2->next;         
    }
    temp1->next = temp2->next;       //Assigns pointer of new node(temp1) to the (n-1)th position node.
    temp2->next = temp1;             //Assigns pointer of (n-1)th node to new node(temp1).

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

int main()
{
    head = NULL;      //empty list
    Insert(2,1);    //List: 2
    Insert(4,2);    //List: 2,4
    Insert(5,1);    //List: 5,2,4
    Insert(7,2);    //List: 5,7,2,4 
    Print();
}
// Implementation of list of numbers with Linked List.
#include <iostream>
using namespace std;

// Represents a node
class Node
{
public:
    int number;
    Node *next;
};

int main()
{
    // List of size 0
    Node *list = NULL;
    /*Unless a value is assigned, a pointer will point to some garbage address by default. Besides memory addresses,
    there is one additional value that a pointer can hold: a null value. A null value is a special value
    that means the pointer is not pointing at anything. A pointer holding a null value is called a null pointer. */
    /*A good idea is :pointer is also a data type(don't forget it,very IMP) so it stores address the same way
    as int x=5; stores its value.you think of pointer as different then other data types remember it is not.It is very similar.*/

    // Adding a number to a list.
    Node *n = new Node;
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    // Similar to (*temp).number .Remember that the bracket here is to specify the order.
    n->next = NULL;
    list = n;
    // Notice, how similar it is to int x,y; ... x=y;

    // Adding a number to a list.
    n = new Node;
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // Adding a number to a list.
    n = new Node;
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // Print list
    cout << "List is : ";
    for (Node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        cout << " " << tmp->number;
    }
    cout << endl;

    // Free list
    while (list != NULL)
    {
        Node *tmp = list->next;
        free(list);
        list = tmp;
    }
    return 0;
}

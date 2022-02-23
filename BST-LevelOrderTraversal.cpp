// Binary Search Tree - Level Order Traversal(Breadth First Traversal)
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Create a node
Node *GetNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node
Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

void LevelOrder(Node *root);

int main()
{
    Node *root = NULL; // Creating an empty tree;
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 35);
    root = Insert(root, 8);
    root = Insert(root, 12);

    LevelOrder(root);
}

void LevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

// Time-Complexity
// O(n)
// Space-Complexity
// O(1) - Best
// O(n) - Worst/Average
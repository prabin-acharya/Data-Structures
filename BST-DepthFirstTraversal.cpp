// Binary Search Tree - Depth First Traversal
// Preorder, Inorder, Postorder
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

void PreOrder(Node *root);
void InOrder(Node *root);
void PostOrder(Node *root);

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

    cout << "PreOrder:" << endl;
    PreOrder(root);
    cout << endl;
    cout << "InOrder: " << endl;
    InOrder(root);
    cout << endl;
    cout << "PostOrder: " << endl;
    PostOrder(root);
}

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
    // Time Complexity
    //  O(n)
    //  Space Complexity
    //  O(h) - h is height of tree
    // Heigth of tee: Worst - O(n), Best/average - O(logn)
}

// Inorder traversal of Binary Tree is Binary Search Tree and its traversal will give us elements of the tree in sorted order
void InOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);

    // Time Complexity
    //  O(n)
    //  Space Complexity
    //  O(h) - h is height of tree
    // Heigth of tee: Worst - O(n), Best/average - O(logn)
}

void PostOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";

    // Time Complexity
    //  O(n)
    //  Space Complexity
    //  O(h) - h is height of tree
    // Heigth of tee: Worst - O(n), Best/average - O(logn)
}
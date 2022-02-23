// Binary Search Tree - Implementation in C++
// - Binary tree is the tree in which each node can have at most two children
// - Binary Search Tree is the Binary Tree in which for each node, value of all the nodes in the left subtree
//      is lesser or equal  and value of all the nodes in right subtree is greater then root node
#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

// Create a node
BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node
BstNode *Insert(BstNode *root, int data)
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

// Search an element in Tree
bool Search(BstNode *, int);
// Find Min element in BST iteratively
int FindMin(BstNode *);
// Find Min element in BST recursively
int FindMinRecursive(BstNode *);
// Find Height of the Tree
int FindHeight(BstNode *);

int main()
{
    BstNode *root = NULL; // Creating an empty tree;
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 35);
    root = Insert(root, 8);
    root = Insert(root, 12);

    int min = FindMin(root);
    cout << FindHeight(root);

    cout << "Min element in BST is: " << min << endl;
    int number;
    cout << "Enter number to be searched: ";
    cin >> number;
    if (Search(root, number) == true)
        cout << "Found\n";
    else
        cout << "Not Found\n";
}

// Insert a node by passing root address
// BstNode *Insert(BstNode **root, int data)
// {
//     if (*root == NULL)
//     {
//         *root = GetNewNode(data);
//     }
//     else if (data <= (*root)->data)
//     {
//         (*root)->left = Insert((*root)->left, data);
//     }
//     else
//     {
//         (*root)->right = Insert((*root)->right, data);
//     }

// main(){
// BstNode *root = NULL; // Creating an empty tree;
// Insert(&root, 15);
// Insert(&root, 20);
// Insert(&root, 10);
// Insert(&root, 25);
// Insert(&root, 8);
// Insert(&root, 12);
// }
// }

// Search an element in Tree
bool Search(BstNode *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

// Find Min element in BST iteratively
int FindMin(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Error: Treee is empty!\n";
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

// Find Min element in BST recursively
int FindMinRecursive(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Error: Treee is empty!\n";
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    // Search in left subtree
    return FindMin(root->left);
}

int FindHeight(BstNode *root)
{

    if (root == NULL)
        return -1;

    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

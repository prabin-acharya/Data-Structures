// Binary Search Tree - Implementation in C++
#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

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
// }

int main()
{
    BstNode *root = NULL; // Creating an empty tree;
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    // Insert(&root, 15);
    // Insert(&root, 20);
    // Insert(&root, 10);
    // Insert(&root, 25);
    // Insert(&root, 8);
    // Insert(&root, 12);
}
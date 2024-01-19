#include <stdio.h>
// creating struture of node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// creating node in tree

struct Node *createNode(int key)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        createNode(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

// search function

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == NULL)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else if (key > root->right)
    {
        return search(root->right, key);
    }
}

struct Node *fsmallest(struct Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root->left = NULL;
    }
    return root;
}
struct Node *flarge(struct Node *root)
{
    while (root != NULL && root->right != NULL)
    {
        root->right = NULL;
    }
    return root;
}

int height(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftheight = root->left;
    int rightheight = root->right;

    return (leftheight > rightheight ? leftheight : rightheight) + 1;
}

int count(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left != NULL && root->right != NULL)
    {
        return 1;
    }

    return count(root->left) + count(root->right);
}

#include <stdio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = key;
    newnode->right = newnode->left = NULL;

    return newnode;
};

struct Node *insertNode(struct Node *root, int key)
{

    if (root == NULL)
    {
        createNode(key);
    }
    if (key < root->data)
    {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insertNode(root->right, key);
    }

    return root;
};

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        postorder(root->left);
        postorder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        preOrder(root->left);
        printf("%d", root->data);
        postorder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

struct Node *fsmallest(struct Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct Node *flargest(struct Node *root)
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
    int heightleft = root->left;
    int heightright = root->right;

    return (heightleft > heightright ? heightleft : heightright) + 1;
}

int countNode(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countNode(root->left) + countNode(root->right);
}

int main()
{
}
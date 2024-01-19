#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

struct Node* findLargest(struct Node* root) {
    while (root != NULL && root->right != NULL)
        root = root->right;
    return root;
}

struct Node* findSmallest(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findSmallest(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

int height(struct Node* root) {
    if (root == NULL)
        return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

struct Node* searchElement(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return searchElement(root->left, key);
    }

    return searchElement(root->right, key);
}

void displayMenu() {
    printf("\nMAIN MENU\n");
    printf("1. Insert\n");
    printf("2. Largest\n");
    printf("3. Smallest\n");
    printf("4. Height\n");
    printf("5. Count leaf nodes\n");
    printf("6. Delete\n");
    printf("7. Exit\n");
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int option, key;

    printf("Enter number of nodes: ");
    int n;
    scanf("%d", &n);

    printf("Enter elements of BST: ");
    for (int i = 0; i < n; ++i) {
        int element;
        scanf("%d", &element);
        root = insert(root, element);
    }

    while (1) {
        displayMenu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element to insert in BST: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Element %d inserted in BST.\n", key);
                break;
            case 2: {
                struct Node* largestNode = findLargest(root);
                if (largestNode != NULL)
                    printf("Largest element in BST: %d\n", largestNode->key);
                else
                    printf("BST is empty.\n");
                break;
            }
            case 3: {
                struct Node* smallestNode = findSmallest(root);
                if (smallestNode != NULL)
                    printf("Smallest element in BST: %d\n", smallestNode->key);
                else
                    printf("BST is empty.\n");
                break;
            }
            case 4:
                printf("Enter element to find its height: ");
                scanf("%d", &key);
                struct Node* node = searchElement(root, key);
                if (node != NULL)
                    printf("Height of node %d: %d\n", key, height(node));
                else
                    printf("Node %d not found in the BST.\n", key);
                break;
            case 5:
                printf("Number of leaf nodes in BST: %d\n", countLeafNodes(root));
                break;
            case 6:
                printf("Enter element to delete from BST: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Element %d deleted from BST.\n", key);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid option. Please enter a valid option.\n");
        }

        printf("BST Inorder: ");
        inorderTraversal(root);
        printf("\n");
    }

    return 0;
}

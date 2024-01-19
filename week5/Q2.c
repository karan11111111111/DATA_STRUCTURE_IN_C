#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a circular linked list
struct Node* createCircularLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        printf("Enter info of node%d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Make the linked list circular
    if (tail != NULL) {
        tail->next = head;
    }

    return head;
}

// Function to display a circular linked list
void displayCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("Clinkedlist is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Clinkedlist: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    int numNodes;

    printf("Enter no. of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    struct Node* circularLinkedList = createCircularLinkedList(numNodes);
    displayCircularLinkedList(circularLinkedList);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global pointer to the head of the doubly linked list
struct Node* head = NULL;

// Function to insert a node at the beginning
void insertAtBeginning(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted at the beginning.\n");
}

// Function to insert a node at the end
void insertAtEnd(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Node inserted at the end.\n");
}

// Function to insert a node at a specific position
void insertAtAnyPosition(int element, int position) {
    if (position <= 0) {
        printf("Invalid position for insertion.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(element);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = element;

    struct Node* current = head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position for insertion.\n");
        free(newNode);
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

// Function to delete a node from a specific position
void deleteAtPosition(int position) {
    if (position <= 0 || head == NULL) {
        printf("Invalid position or empty list. Node not deleted.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Node deleted from the beginning.\n");
        return;
    }

    struct Node* current = head;
    int currentPosition = 1;

    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position exceeds the list size. Node not deleted.\n");
        return;
    }

    if (current->next == NULL) {
        current->prev->next = NULL;
        free(current);
        printf("Node deleted from the end.\n");
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        printf("Node deleted from position %d.\n", position);
    }
}

// Function to traverse and print the doubly linked list
void traverse() {
    struct Node* current = head;
    printf("The list is: ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int numNodes, element, position, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the elements: ");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &element);
        insertAtEnd(element);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert a node at a specific position\n");
        printf("2. Delete a node from a specific position\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtAnyPosition(element, position);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

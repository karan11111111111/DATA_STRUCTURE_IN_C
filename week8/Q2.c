// 8.2 Write a menu driven program to implement priority queue operations such as Enqueue, 
// Dequeue, Traverse using linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

struct Node* front = NULL;

void enqueue(int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* current = front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Priority queue is empty. Dequeue not possible.\n");
    } else {
        struct Node* temp = front;
        front = front->next;
        printf("Dequeued: data=%d, priority=%d\n", temp->data, temp->priority);
        free(temp);
    }
}

void traverse() {
    struct Node* current = front;
    if (current == NULL) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority Queue:\n");
        while (current != NULL) {
            printf("Data: %d, Priority: %d\n", current->data, current->priority);
            current = current->next;
        }
    }
}

int main() {
    int choice, data, priority;

    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
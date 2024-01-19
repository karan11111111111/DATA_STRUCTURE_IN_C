// 7.1 Write a menu driven program to create a linear queue using array and perform Enqueue, 
// Dequeue, Traverse, IsEmpty, IsFull operations.

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int element) {
    if (rear == MAX_SIZE -1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Enqueued: %d\n", element);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;
    printf("Enter the size of Queue: ");
    int maxSize;
    scanf("%d", &maxSize);

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == maxSize - 1) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter element: ");
                    scanf("%d", &element);
                    enqueue(element);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                traverse();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}



// 7.3 Write a menu driven program to implement circular queue operations such as Enqueue, 
// Dequeue, Traverse, IsEmpty, IsFull using array.
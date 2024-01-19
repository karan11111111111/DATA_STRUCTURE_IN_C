
// 7.3 Write a menu driven program to implement circular queue operations such as Enqueue, 
// Dequeue, Traverse, IsEmpty, IsFull using array.

#include <stdio.h>

#define MAX_SIZE 100

int CQueue[MAX_SIZE];
int front = -1;
int rear = -1;
int size;

int IsEmpty() {
    return front == -1;
}

int IsFull() {
    return (front == 0 && rear == size - 1) || (front == rear + 1);
}

void Enqueue(int element) {
    if (IsFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    CQueue[rear] = element;
}

int Dequeue() {
    if (IsEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int element = CQueue[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;

    return element;
}

void Traverse() {
    if (IsEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("CQueue: ");
    int i = front;

    do {
        printf("%d ", CQueue[i]);
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);

    printf("\n");
}

int main() {
    int option, element;

    printf("Enter Queue size: ");
    scanf("%d", &size);

    while (1) {
        printf("Main Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                Enqueue(element);
                break;
            case 2:
                element = Dequeue();
                if (element != -1) {
                    printf("Element %d deleted from the queue.\n", element);
                }
                break;
            case 3:
                if (IsEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                if (IsFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                Traverse();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

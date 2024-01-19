// 8.1 Write a menu driven program to implement Deques (both Inputrestricted and outputestricted) and performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using 
// static array.


#include <stdio.h>

#define MAX_SIZE 5

int arr[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
}

void insertRear(int element) {
    if (isFull()) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    arr[rear] = element;
    printf("%d inserted at right.\n", element);
}

void insertfront(int element){
  if (isFull()) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }

    arr[front] = element;
    printf("%d inserted at left.\n", element);
}


void deletefront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from left.\n");
        return;
    }

    int deleted = arr[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("%d deleted from left.\n", deleted);
}


void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    int i = front;
    printf("Deque: ");

    if (front <= rear) {
        while (i <= rear) {
            printf("%d ", arr[i]);
            i++;
        }
    } else {
        while (i < MAX_SIZE) {
            printf("%d ", arr[i]);
            i++;
        }

        i = 0;
        while (i <= rear) {
            printf("%d ", arr[i]);
            i++;
        }
    }

    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("Input restricted Deque Menu\n");
        printf("1. Insert at rear\n");
        printf("2. insert from front\n");
        printf("3. Delete from front\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                insertRear(element);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &element);
                insertfront(element);
                break;
            case 3:
                deletefront();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


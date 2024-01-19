//7.2 Write a menu driven program to implement linear queue operations such as Enqueue, 
//Dequeue, IsEmpty, Traverse using single linked list.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};


struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int element){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if(rear==NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
}    

int Dequeue(){
    if(front == NULL){
        printf("Queue is empty");
        return -1;
    }

int element = front->data;
struct Node *temp = front;

if(front == rear){
    front = rear = NULL;
}else{
    front = front ->next;
}

free(temp);
return element;

}

int IsEmpty(){
    return front == NULL;
}

void Traverse(){
    struct Node *current = front;
    if(current == NULL){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int option, element;
    while (1) {
        printf("Main Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
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
                Traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
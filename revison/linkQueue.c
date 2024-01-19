#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int size=0;
int maxsize=5;

void enque(int element){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = element;
    newnode->next = NULL;

    if(rear == NULL){
        rear->next = newnode;
        rear = newnode;
    }

  size++;
}


void dequeu(){
    if(front == NULL){
        printf("Empty");
        return -1;
    }
    int element = front->data;
    struct Node *temp = front;
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }
    free(temp);
    return element;
}


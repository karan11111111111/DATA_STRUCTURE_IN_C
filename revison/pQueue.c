#include<stdio.h>
struct Node
{
    int data;
    int priority;
    struct Node *next;
};

//function to create node

void *createnode(int data, int priority){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->priority =  priority;
    newnode->next = NULL;
    return newnode;
}
struct Node* front = NULL;

void enqueue(int data, int priority){
    struct Node* newnode = createnode(data, priority);
if(front == NULL || priority < newnode->priority){
    newnode->next = front;
    front = newnode;
}
else{
     struct Node * current = front;

     while(current->next !=NULL && current->next->priority <=priority ){
    current = current->next;
     }
     newnode->next = current->next;
     current->next = newnode;
     }
}

void dequeue(){
    
}
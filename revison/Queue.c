#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = MAX_SIZE-1;

bool isEmty(){
   return front == -1;
}

bool isfull(){
    return rear == MAX_SIZE -1;
}

void enque(int element){
    if(rear == MAX_SIZE -1){
        printf("Queue is full");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Enqueued: %d ", element);
    }
}

void deque(){
    if(front == -1){
        printf("Queue is empty");
    }
    else{
        printf("Dequeued: %d \n", queue[front]);
        if(front==rear ){
            rear = front = -1;
        }else{
            front ++;
        }

    }
}

void traverse(){
    if(front ==-1){
        printf("Queue is empty");
    }else{
        printf("Queue is: ");
        for(int i =front; i<=rear; i++){
            printf(" %d",queue[i]);
            
        }
        printf("\n");
    }
}

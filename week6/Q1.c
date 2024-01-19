#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isFull()
{
    return top == MAX_SIZE - 1;
}

int isEmpty()
{
    return top == -1;
}

void push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full. Cannot push element %d. \n", data);
    }
    else
    {
        stack[++top] = data;
        printf("%d pushed into the stack \n", data);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        int data = stack[top--];
        return data;
    }
}

void display()
{
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice, element;

    while (1)
    {
        printf("\nMain Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");

        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed into the stack: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
           element = pop();
           if(element != -1){
            printf("%d deleted from stack \n", element);
           }
            break;
        case 3:
            if(isEmpty()){
                printf("Stack is empty \n");
            }else{
                printf("Stack is not empty\n");
            }
            break;
        case 4:
            if(isFull()){
                printf("Stack is Full\n");
            }else{
                printf("Stack is not full \n");
            }
            break;
        case 5:
           display();
            break;
        case 6:
          exit(0);
         

        default:
            printf("Invalid choice");
            break;
        }
    }
}
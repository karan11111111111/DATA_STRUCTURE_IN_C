#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Stack *createStack()
{
    struct Stack *stack;
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return (stack->top == NULL);
}

void push(struct Stack *stack, int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed into the stack\n", data);
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("stack is empty\n");
        return -1;
    }
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void display(struct Stack *stack)
{
    struct Node *current = stack->top;
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Stack *stack = createStack();
    int choice, element;

    while (1)
    {
        printf("\n Main Menu\n");
        printf("\n1. Push\n 2. pop \n 3. IsEmpty \n 4. Traverse \n 5. Exit\n ");

        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to be pushes into the stack: ");
            scanf("%d", &element);
            push(stack, element);
            break;
        case 2:
            element = pop(stack);
            if (element != -1)
            {
                printf("%d delete from the stack \n", element);
            }
            break;
        case 3:
            if (isEmpty(stack))
            {
                printf("Stack is empty \n");
            }
            else
            {
                printf("Stack is not empty \n");
            }
            break;
        case 4:
            printf("Stack: ");
            display(stack);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice. please try again. \n");
            break;
        }
    }
    return 0;
}

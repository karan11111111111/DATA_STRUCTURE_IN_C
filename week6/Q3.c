#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Define the maximum size for the stack
#define MAX_SIZE 100
// Define a stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};
// Function to initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}
// Function to check if the stack is empty
bool isEmpty(struct Stack *s) {
    return (s->top == -1);
}
// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
// Function to get the precedence of an operator
int precedence(char operator) {
    if (operator == '^') return 3;
    if (operator == '*' || operator == '/') return 2;
    if (operator == '+' || operator == '-') return 1;
    return -1; // Lower precedence
}
// Function to push an element onto the stack
void push(struct Stack *s, char item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        exit(1);
    }
    s->items[++(s->top)] = item;
}
// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    return s->items[(s->top)--];
}
// Function to convert infix to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    i = j = 0;
    while (infix[i] != '\0') {
        char token = infix[i];
        if (token == '(') {
            push(&stack, token);
            i++;
        } else if (token == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(') {
                pop(&stack);
            } else {
                printf("Invalid infix expression.\n");
                exit(1);
            }
            i++;
        } else if (isOperator(token)) {
            while (!isEmpty(&stack) && precedence(token) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
            i++;
        } else if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            postfix[j++] = token;
            i++;
        } else {
            printf("Invalid character in infix expression.\n");
            exit(1);
        }
    }
    while (!isEmpty(&stack)) {
        if (stack.items[stack.top] == '(' || stack.items[stack.top] == ')') {
            printf("Invalid infix expression.\n");
            exit(1);
        }
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}
int main() {
    char infix[100], postfix[100];   
    printf("Enter infix expression: ");
    scanf("%s", infix);   
    infixToPostfix(infix, postfix);   
    printf("Postfix: %s\n", postfix);   
    return 0;
}


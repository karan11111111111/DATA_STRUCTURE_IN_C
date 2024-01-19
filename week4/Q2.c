/*4.2 In addition to 4.1, perform following operations using function on the single linked list: 
 i. search an element in the list 
ii. sort the list in ascending order 
iii. reverse the list*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at a specific position
void insertNode(struct Node** head, int element, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted.\n");
    }
}

// Function to delete a node from a specific position
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Node deleted.\n");
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
    } else {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        printf("Node deleted.\n");
    }
}

// Function to count the number of nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to traverse and print the linked list
void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to search for an element in the linked list
int searchElement(struct Node* head, int element) {
    int position = 1;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == element) {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1; // Element not found
}

// Function to sort the linked list in ascending order (bubble sort)
void sortList(struct Node** head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    /* Checking for empty list */
    if (*head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data of two nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to the current node
        current = next;       // Move current to the next node
    }

    *head = prev; // Update the head to the new start of the reversed list
}

int main() {
    struct Node* head = NULL;
    int choice, element, position;

    printf("Enter number of nodes: ");
    int n;
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        insertNode(&head, element, i + 1);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert a node at a position\n");
        printf("2. Delete a node from a specific position\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(&head, element, position);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                printf("The list is: ");
                traverse(head);
                break;
            case 5:
                printf("Enter element to be searched: ");
                scanf("%d", &element);
                position = searchElement(head, element);
                if (position != -1) {
                    printf("Element found at node-%d\n", position);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 6:
                sortList(&head);
                printf("List sorted in ascending order.\n");
                break;
            case 7:
                reverseList(&head);
                printf("Reverse list: ");
                traverse(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
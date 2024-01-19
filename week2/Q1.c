// 2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using function. 
// a. insert a given element at specific position. 
// b. delete an element from a specific position of the array. 
// c. linear search to search an element 
// d. traversal of the array  

#include <stdio.h>

void insert_element(int arr[], int *size, int element, int position) {
    if (*size < position || position < 0) {
        printf("Invalid position\n");
        return;
    }

    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    (*size)++;
    printf("Element inserted\n");
}

void delete_element(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted\n");
}

int linear_search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void traverse_array(int arr[], int size) {
    printf("Array Elements:");
    for (int i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size n: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter Array elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int option, element, position;
    while (1) {
        printf("\n***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Element to insert: ");
                scanf("%d", &element);
                printf("Enter Position: ");
                scanf("%d", &position);
                insert_element(array, &n, element, position);
                break;
            case 2:
                printf("Enter Position to delete: ");
                scanf("%d", &position);
                delete_element(array, &n, position);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                int index = linear_search(array, n, element);
                if (index != -1) {
                    printf("Element found at position: %d\n", index);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 4:
                traverse_array(array, n);
                break;
            case 5:
                printf("Program exited\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}

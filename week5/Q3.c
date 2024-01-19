#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the sparse matrix list
struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to represent the sparse matrix using a header single-linked list
struct Node* createSparseMatrix(int matrix[][100], int rows, int cols) {
    struct Node* header = createNode(rows, cols, 0);
    struct Node* current = header;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                current->next = createNode(i, j, matrix[i][j]);
                current = current->next;
            }
        }
    }

    return header;
}

// Function to display the sparse matrix in 3-tuple format
void displaySparseMatrix(struct Node* header) {
    struct Node* current = header->next;

    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", header->row, header->col, header->value);

    while (current != NULL) {
        printf("%d %d %d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

int main() {
    int rows, cols;
    printf("Enter size of the sparse matrix (rows columns): ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100];
    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    struct Node* header = createSparseMatrix(matrix, rows, cols);
    displaySparseMatrix(header);

    return 0;
}

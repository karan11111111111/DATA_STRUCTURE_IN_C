// 3.2 WAP to perform addition of two given sparse matrix in 3–tuple format. 
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a sparse matrix element
struct SparseElement {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    int numElements;
    struct SparseElement* elements;
};

// Function to read a sparse matrix
void readSparseMatrix(struct SparseMatrix* matrix) {
    printf("(rows, column and non zeros: ");
    scanf("%d%d%d", &(matrix->rows), &(matrix->cols), &(matrix->numElements));

  

    // Allocate memory for the elements
    matrix->elements = (struct SparseElement*)malloc(matrix->numElements * sizeof(struct SparseElement));

    printf("");
    for (int i = 0; i < matrix->numElements; i++) {
        scanf("%d %d %d", &(matrix->elements[i].row), &(matrix->elements[i].col), &(matrix->elements[i].value));
    }
}

// Function to add two sparse matrices
void addSparseMatrices(const struct SparseMatrix* matrix1, const struct SparseMatrix* matrix2, struct SparseMatrix* result) {
    result->rows = matrix1->rows;
    result->cols = matrix1->cols;
    result->numElements = 0;  // Initialize the count of non-zero elements in the result matrix

    // Allocate memory for the maximum possible number of elements in the result matrix
    result->elements = (struct SparseElement*)malloc((matrix1->numElements + matrix2->numElements) * sizeof(struct SparseElement));

    int i = 0, j = 0, k = 0;

    // Merge the two matrices while adding elements with the same coordinates
    while (i < matrix1->numElements && j < matrix2->numElements) {
        if (matrix1->elements[i].row < matrix2->elements[j].row ||
            (matrix1->elements[i].row == matrix2->elements[j].row && matrix1->elements[i].col < matrix2->elements[j].col)) {
            result->elements[k++] = matrix1->elements[i++];
        } else if (matrix1->elements[i].row > matrix2->elements[j].row ||
                   (matrix1->elements[i].row == matrix2->elements[j].row && matrix1->elements[i].col > matrix2->elements[j].col)) {
            result->elements[k++] = matrix2->elements[j++];
        } else {
            // Elements with the same coordinates; add their values and store the result
            result->elements[k].row = matrix1->elements[i].row;
            result->elements[k].col = matrix1->elements[i].col;
            result->elements[k].value = matrix1->elements[i].value + matrix2->elements[j].value;
            i++;
            j++;
            k++;
        }
    }

    // Copy any remaining elements from matrix1
    while (i < matrix1->numElements) {
        result->elements[k++] = matrix1->elements[i++];
    }

    // Copy any remaining elements from matrix2
    while (j < matrix2->numElements) {
        result->elements[k++] = matrix2->elements[j++];
    }

    // Update the actual number of elements in the result matrix
    result->numElements = k;
}

// Function to display a sparse matrix
void displaySparseMatrix(const struct SparseMatrix* matrix) {
    printf("\n");
    printf("%d %d %d\n", matrix->rows, matrix->cols, matrix->numElements);
    for (int i = 0; i < matrix->numElements; i++) {
        printf("%d %d %d\n", matrix->elements[i].row, matrix->elements[i].col, matrix->elements[i].value);
    }
}

// Function to free memory used by a sparse matrix
void freeSparseMatrix(struct SparseMatrix* matrix) {
    free(matrix->elements);
    matrix->elements = NULL;
    matrix->numElements = 0;
}

int main() {
    struct SparseMatrix matrix1, matrix2, result;

    printf("Enter sparse matrix-1 in 3-tuple format:\n");
    readSparseMatrix(&matrix1);

    printf("Enter sparse matrix-2 in 3-tuple format:\n");
    readSparseMatrix(&matrix2);

    addSparseMatrices(&matrix1, &matrix2, &result);

    displaySparseMatrix(&result);

    // Free allocated memory
    freeSparseMatrix(&matrix1);
    freeSparseMatrix(&matrix2);
    freeSparseMatrix(&result);

    return 0;
}

// 2.2 Write a program to perform the following operations on a given square matrix using functions:  
// i.   Find the no.of nonzero elements 
// ii.  Display upper triangular matrix 
// iii. Display the elements of just above and below the main diagonal

#include <stdio.h>

void count_nonzero(int mat[][100], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                count++;
            }
        }
    }
    printf("Nonzero elements: %d\n", count);
}

void display_upper_triangular(int mat[][100], int n) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                printf("%d ", mat[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void display_diagonal_neighbors(int mat[][100], int n) {
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i + 1 || j == i - 1) {
                printf("%d ", mat[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter size of the square matrix: ");
    scanf("%d", &n);

    int matrix[100][100];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    count_nonzero(matrix, n);
    display_upper_triangular(matrix, n);
    display_diagonal_neighbors(matrix, n);

    return 0;
}

// 2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &rows, &cols);

    int sparseMatrix[rows][cols];

    printf("Enter elements of the sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    // non-zero elements
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                count++;
            }
        }
    }

    //3-tuple format matrix
    int triplet[count + 1][3];
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = count;

    int index = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                triplet[index][0] = i;
                triplet[index][1] = j;
                triplet[index][2] = sparseMatrix[i][j];
                index++;
            }
        }
    }

    printf("sparse matrix in 3-tuple format:\n");
    for (int i = 0; i <= count; i++) {
        printf("%d   %d   %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }

    return 0;
}

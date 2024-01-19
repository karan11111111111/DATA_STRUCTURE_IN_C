// 3.3 WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial equations. 

#include <stdio.h>

void readPolynomial(int poly[], int degree) {
    printf("from lowest to highest degree: ");
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly[i]);
    }
}

void addPolynomials(int poly1[], int poly2[], int result[], int degree) {
    for (int i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

void displayPolynomial(int poly[], int degree) {
    printf("Resultant Polynomial: ");
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i == 0) {
                printf("%d", poly[i]);
            } else if (i == 1) {
                printf("%dx", poly[i]);
            } else {
                printf("%dx^%d", poly[i], i);
            }

            if (i != 0 && poly[i - 1] != 0) {
                printf("+");
            }
        }
    }
    printf("\n");
}

int main() {
    int maxDegree;

    printf("Enter the maximum degree of x: ");
    scanf("%d", &maxDegree);

    int polynomial1[maxDegree + 1];
    int polynomial2[maxDegree + 1];
    int result[maxDegree + 1];

    printf("Enter Polynomial-1:\n");
    readPolynomial(polynomial1, maxDegree);

    printf("Enter Polynomial-2:\n");
    readPolynomial(polynomial2, maxDegree);

    addPolynomials(polynomial1, polynomial2, result, maxDegree);

    displayPolynomial(result, maxDegree);

    return 0;
}

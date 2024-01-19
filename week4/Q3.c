#include <stdio.h>
#include <stdlib.h>

// Define a structure for a single term of the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coeff, int exp) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coeff;
    term->exponent = exp;
    term->next = NULL;
    return term;
}

// Function to insert a term into a polynomial
void insertTerm(struct Term** poly, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);

    if (!(*poly)) {
        (*poly) = newTerm;
    } else {
        struct Term* current = (*poly);
        while (current->next) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* p1 = poly1;
    struct Term* p2 = poly2;

    while (p1 && p2) {
        if (p1->exponent > p2->exponent) {
            insertTerm(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            insertTerm(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coefficient + p2->coefficient;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, p1->exponent);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add any remaining terms from both polynomials
    while (p1) {
        insertTerm(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2) {
        insertTerm(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    if (!poly) {
        printf("0");
    } else {
        struct Term* current = poly;
        while (current) {
            if (current != poly && current->coefficient > 0) {
                printf(" + ");
            }
            if (current->exponent == 0) {
                printf("%d", current->coefficient);
            } else if (current->exponent == 1) {
                printf("%dx", current->coefficient);
            } else {
                printf("%dx^%d", current->coefficient, current->exponent);
            }
            current = current->next;
        }
    }
    printf("\n");
}

// Function to read a polynomial from the user
void readPolynomial(struct Term** poly) {
    int numTerms;
    int coeff, exp;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &numTerms);

    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(poly, coeff, exp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    printf("Enter Polynomial 1:\n");
    readPolynomial(&poly1);

    printf("Enter Polynomial 2:\n");
    readPolynomial(&poly2);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}

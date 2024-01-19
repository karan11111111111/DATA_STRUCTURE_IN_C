// 1.4 Write a menu driven program to create a structure to represent complex number and perform the following operation using function :
#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

void addComplex(struct Complex num1, struct Complex num2, struct Complex *result) {
    result->real = num1.real + num2.real;
    result->imag = num1.imag + num2.imag;
}

void multiplyComplex(struct Complex *num1, struct Complex *num2) {
    float tempReal = num1->real * num2->real - num1->imag * num2->imag;
    float tempImag = num1->real * num2->imag + num1->imag * num2->real;
    
    num1->real = tempReal;
    num1->imag = tempImag;
}

int main() {
    struct Complex num1, num2, result;
    int choice;

    printf("Eneter real and imaginary parts of complex number 1: ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Eneter real and imaginary parts of complex number 2: ");
    scanf("%f %f", &num2.real, &num2.imag);

    do {
        printf("\nMENU\n");
        printf("1.Addition of two Complex numbers (call by value)\n");
        printf("2.Multiplication of two Complex numbers (call by value)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addComplex(num1, num2, &result);
                printf("Sum=%.1f+%.1fi\n", result.real, result.imag);
                break;
            case 2:
                multiplyComplex(&num1, &num2);
                printf("Product=%.1f+%.1fi\n", num1.real, num1.imag);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 1 && choice != 2);

    return 0;
}

// 1.3 Write a program to create a structure to store the information of n number of Employees. Employee’s  information includes  data  members:  Emp-id, Name, Designation,  basic_salary, 
// hra%, da%. Display the information of employees with gross salary. Use array of structure.
#include <stdio.h>
#include <string.h>

struct Employees {
    char Name[50];  // Use an array of characters to store names
    char Designation[50];  // Use an array of characters to store designations
    float Basic_Salary;
    float HRA;
    float DA;
    float Gross_Salary;
};

int main() {
    int i, n;

    printf("Enter number of employees you want to enter: ");
    scanf("%d", &n);
    
    struct Employees E[n];

    for (i = 0; i < n; i++) {
        printf("Enter details of Employee %d:\n", i + 1);

        printf("Enter Name: ");
        scanf("%s", E[i].Name);
        
        printf("Enter Designation: ");
        scanf("%s", E[i].Designation);
        
        printf("Enter Basic Salary: ");
        scanf("%f", &E[i].Basic_Salary);
        
        printf("Enter HRA %%: ");
        scanf("%f", &E[i].HRA);
        
        printf("Enter DA %%: ");
        scanf("%f", &E[i].DA);

        E[i].Gross_Salary = E[i].Basic_Salary + (E[i].HRA / 100) * E[i].Basic_Salary + (E[i].DA / 100) * E[i].Basic_Salary;
    }

    printf("Employee Information:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s\n", E[i].Name);
        printf("Designation: %s\n", E[i].Designation);
        printf("Basic Salary: %f\n", E[i].Basic_Salary);
        printf("HRA %%: %f\n", E[i].HRA);
        printf("DA %%: %f\n", E[i].DA);
        printf("Gross Salary: %f\n", E[i].Gross_Salary);
    }
    
    return 0;
}

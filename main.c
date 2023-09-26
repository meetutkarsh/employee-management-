#include "functions.h"
#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h> // Include ctype.h for isalpha function

#define MAX_EMPLOYEES 100


int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;
    int choice, empNumber;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Update Employee\n");
        printf("4. Display Employee by Number\n");
        printf("5. Calculate Net Pay\n"); // New option
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &numEmployees);
                break;
            case 2:
                printf("Enter the employee number to delete: ");
                scanf("%d", &empNumber);
                deleteEmployee(employees, &numEmployees, empNumber);
                break;
            case 3:
                printf("Enter the employee number to update: ");
                scanf("%d", &empNumber);
                updateEmployee(employees, numEmployees, empNumber);
                break;
            case 4:
                printf("Enter the employee number to display: ");
                scanf("%d", &empNumber);
                displayEmployee(employees, numEmployees, empNumber);
                break;
            case 5:
                printf("Enter the employee number to calculate net pay: ");
                scanf("%d", &empNumber);
                calculateNetPay(employees, numEmployees, empNumber);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


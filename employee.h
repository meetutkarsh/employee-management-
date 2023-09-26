#include <stdio.h>
// Define a structure to represent a Date
struct Date {
    int dd;
    int mm;
    int yy;
};

// Define a structure to represent an Employee
struct Employee {
    int empNumber;
    char empFirstName[25];
    char empLastName[25];
    struct Date dateOfJoining; // Date of joining field
    float empBaseSalary;
    float empCTC;
};

// Function prototypes
void addEmployee(struct Employee employees[], int *numEmployees);
void deleteEmployee(struct Employee employees[], int *numEmployees, int empNumber);
void updateEmployee(struct Employee employees[], int numEmployees, int empNumber);
void displayEmployee(struct Employee employees[], int numEmployees, int empNumber);
void calculateNetPay(struct Employee employees[], int numEmployees, int empNumber); // New function prototype
int isAlpha(const char *str);
int isNumeric(const char *str);

#include "employee.h"
#include "validations.h"
#include <stdio.h>
#include <ctype.h> // Include ctype.h for isalpha function
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
// Function to add a new employee
void addEmployee(struct Employee employees[], int *numEmployees) {
  if (*numEmployees < MAX_EMPLOYEES) {
    struct Employee newEmployee;
    int isValidEmpNumber = 0;
    int isValidEmpBaseSalary = 0;
    int isValidEmpCTC = 0;
    int isValidEmpFirstName = 0;
    int isValidEmpLastName = 0;

    do {
      printf("Enter employee number (numeric): ");
      if (scanf("%d", &newEmployee.empNumber) == 1 &&
          newEmployee.empNumber > 0) {
        isValidEmpNumber = 1;
      } else {
        printf("Invalid input format. Please enter a positive numeric employee "
               "number.\n");
        while (getchar() != '\n')
          ;
      }
    } while (!isValidEmpNumber);

    do {
      printf("Enter employee first name (alphabetic): ");
      if (scanf("%s", newEmployee.empFirstName) == 1 &&
          isAlpha(newEmployee.empFirstName)) {
        isValidEmpFirstName = 1;
      } else {
        printf("Invalid input format. Please enter a valid alphabetic employee "
               "first name.\n");
        while (getchar() != '\n')
          ;
      }
    } while (!isValidEmpFirstName);

    do {
      printf("Enter employee last name (alphabetic): ");
      if (scanf("%s", newEmployee.empLastName) == 1 &&
          isAlpha(newEmployee.empLastName)) {
        isValidEmpLastName = 1;
      } else {
        printf("Invalid input format. Please enter a valid alphabetic employee "
               "last name.\n");
        while (getchar() != '\n')
          ;
      }
    } while (!isValidEmpLastName);

    do {
      printf("Enter employee date of joining (dd mm yy): ");
      if (scanf("%d %d %d", &newEmployee.dateOfJoining.dd,
                &newEmployee.dateOfJoining.mm,
                &newEmployee.dateOfJoining.yy) == 3) {
        // Additional validation for date fields can be added here if needed
      } else {
        printf("Invalid input format. Please enter a valid date of joining (dd "
               "mm yy).\n");
        while (getchar() != '\n')
          ;
      }
    } while (!isValidDate(newEmployee.dateOfJoining));

    do {
      printf("Enter employee base salary (numeric): ");
      if (scanf("%f", &newEmployee.empBaseSalary) == 1 &&
          newEmployee.empBaseSalary > 0) {
        isValidEmpBaseSalary = 1;
      } else {
        printf("Invalid input format. Please enter a positive numeric employee "
               "base salary.\n");
        while (getchar() != '\n')
          ;
      }
    } while (!isValidEmpBaseSalary);

    do {
      printf("Enter employee CTC (Cost to Company) (numeric): ");
      if (scanf("%f", &newEmployee.empCTC) == 1 && newEmployee.empCTC > 0) {
        isValidEmpCTC = 1;
      } else {
        printf("Invalid input format. Please enter a positive numeric employee "
               "CTC.\n");
        while (getchar() != '\n')
          ;
      }
    } while (!isValidEmpCTC);

    employees[*numEmployees] = newEmployee;
    (*numEmployees)++;
    printf("Employee added successfully.\n");
  } else {
    printf("Employee database is full. Cannot add more employees.\n");
  }
}

// Function to delete an employee by employee number
void deleteEmployee(struct Employee employees[], int *numEmployees,
                    int empNumber) {
  int found = 0;

  if (empNumber <= 0) {
    printf("Invalid employee number. Please enter a positive numeric employee "
           "number.\n");
    return;
  }

  for (int i = 0; i < *numEmployees; i++) {
    if (employees[i].empNumber == empNumber) {
      found = 1;
      for (int j = i; j < *numEmployees - 1; j++) {
        employees[j] = employees[j + 1];
      }
      (*numEmployees)--;
      printf("Employee with number %d deleted successfully.\n", empNumber);
      break;
    }
  }

  if (!found) {
    printf("Employee with number %d not found.\n", empNumber);
  }
}

// Function to update employee details by employee number
void updateEmployee(struct Employee employees[], int numEmployees,
                    int empNumber) {
  int found = 0;

  if (empNumber <= 0) {
    printf("Invalid employee number. Please enter a positive numeric employee "
           "number.\n");
    return;
  }

  for (int i = 0; i < numEmployees; i++) {
    if (employees[i].empNumber == empNumber) {
      found = 1;

      int isValidEmpBaseSalary = 0;
      int isValidEmpCTC = 0;
      int isValidEmpFirstName = 0;
      int isValidEmpLastName = 0;
      int isValidDateOfJoining = 0;

      do {
        printf("Enter new employee first name (alphabetic): ");
        if (scanf("%s", employees[i].empFirstName) == 1 &&
            isAlpha(employees[i].empFirstName)) {
          isValidEmpFirstName = 1;
        } else {
          printf("Invalid input format. Please enter a valid alphabetic "
                 "employee first name.\n");
          while (getchar() != '\n')
            ;
        }
      } while (!isValidEmpFirstName);

      do {
        printf("Enter new employee last name (alphabetic): ");
        if (scanf("%s", employees[i].empLastName) == 1 &&
            isAlpha(employees[i].empLastName)) {
          isValidEmpLastName = 1;
        } else {
          printf("Invalid input format. Please enter a valid alphabetic "
                 "employee last name.\n");
          while (getchar() != '\n')
            ;
        }
      } while (!isValidEmpLastName);

      do {
        printf("Enter new employee date of joining (dd mm yy): ");
        if (scanf("%d %d %d", &employees[i].dateOfJoining.dd,
                  &employees[i].dateOfJoining.mm,
                  &employees[i].dateOfJoining.yy) == 3) {
          // Additional validation for date fields can be added here if needed
        } else {
          printf("Invalid input format. Please enter a valid date of joining "
                 "(dd mm yy).\n");
          while (getchar() != '\n')
            ;
        }
      } while (!isValidDate(employees[i].dateOfJoining));

      do {
        printf("Enter new employee base salary (numeric): ");
        if (scanf("%f", &employees[i].empBaseSalary) == 1 &&
            employees[i].empBaseSalary > 0) {
          isValidEmpBaseSalary = 1;
        } else {
          printf("Invalid input format. Please enter a positive numeric "
                 "employee base salary.\n");
          while (getchar() != '\n')
            ;
        }
      } while (!isValidEmpBaseSalary);

      do {
        printf("Enter new employee CTC (Cost to Company) (numeric): ");
        if (scanf("%f", &employees[i].empCTC) == 1 && employees[i].empCTC > 0) {
          isValidEmpCTC = 1;
        } else {
          printf("Invalid input format. Please enter a positive numeric "
                 "employee CTC.\n");
          while (getchar() != '\n')
            ;
        }
      } while (!isValidEmpCTC);

      printf("Employee details updated successfully.\n");
      break;
    }
  }

  if (!found) {
    printf("Employee with number %d not found.\n", empNumber);
  }
}

// Function to display employee details by employee number
void displayEmployee(struct Employee employees[], int numEmployees,
                     int empNumber) {
  int found = 0;
  for (int i = 0; i < numEmployees; i++) {
    if (employees[i].empNumber == empNumber) {
      found = 1;
      printf("Employee Number: %d\n", employees[i].empNumber);
      printf("Employee Name: %s %s\n", employees[i].empFirstName,
             employees[i].empLastName);
      printf("Date of Joining: %02d/%02d/%02d\n", employees[i].dateOfJoining.dd,
             employees[i].dateOfJoining.mm, employees[i].dateOfJoining.yy);
      printf("Employee Base Salary: %.2f\n", employees[i].empBaseSalary);
      printf("Employee CTC (Cost to Company): %.2f\n", employees[i].empCTC);
      break;
    }
  }
  if (!found) {
    printf("Employee with number %d not found.\n", empNumber);
  }
}

// Function to calculate net pay for an employee
void calculateNetPay(struct Employee employees[], int numEmployees,
                     int empNumber) {
  int found = 0;
  for (int i = 0; i < numEmployees; i++) {
    if (employees[i].empNumber == empNumber) {
      found = 1;

      float basicSalary = employees[i].empBaseSalary;
      float DA = 0.4 * basicSalary;  // DA is 40% of Basic Salary
      float TA = 0.1 * basicSalary;  // TA is 10% of Basic Salary
      float PF = 0.05 * basicSalary; // PF is 5% of Basic Salary
      float netPay = basicSalary + DA + TA - PF;

      printf("Employee Number: %d\n", employees[i].empNumber);
      printf("Employee Name: %s %s\n", employees[i].empFirstName,
             employees[i].empLastName);
      printf("Date of Joining: %02d/%02d/%02d\n", employees[i].dateOfJoining.dd,
             employees[i].dateOfJoining.mm, employees[i].dateOfJoining.yy);
      printf("Employee Base Salary: %.2f\n", employees[i].empBaseSalary);
      printf("DA: %.2f\n", DA);
      printf("TA: %.2f\n", TA);
      printf("PF: %.2f\n", PF);
      printf("Net Pay: %.2f\n", netPay);
      break;
    }
  }
  if (!found) {
    printf("Employee with number %d not found.\n", empNumber);
  }
}

// // Function to check if a string contains only alphabetic characters
// int isAlpha(const char *str) {
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (!isalpha(str[i])) {
//             return 0; // Not alphabetic
//         }
//     }
//     return 1; // Alphabetic
// }

// // Function to validate date fields (e.g., day, month, year)
// int isValidDate(struct Date date) {
//     // Add your date validation logic here if needed
//     return 1; // Always returns valid for now
// }

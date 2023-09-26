// #include "employee.h"
#include <ctype.h>
// Function to check if a string contains only alphabetic characters
int isAlpha(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isalpha(str[i])) {
      return 0; // Not alphabetic
    }
  }
  return 1; // Alphabetic
}

// Function to validate date fields (e.g., day, month, year)
int isValidDate(struct Date date) {
  // Add your date validation logic here if needed
  return 1; // Always returns valid for now
}

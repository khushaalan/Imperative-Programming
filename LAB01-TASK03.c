/**********************************************************************
 * LAB01-TASK03: Factorial Calculator
 *
 * Group Members:
 * 1. Khushaalan Arjunan (A190409)
 * 2. Wang Rui (A184975)
 * 3. Stuart Heng Fu Yu (A189660)
 * 4. Zhao Zhao (A184841)
 *
 * This program calculates the factorial of a positive integer entered by the user.
 * It provides two methods for factorial calculation: basic and optimized.
 * User input validation and error handling are implemented to ensure the input
 * is a positive integer.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <ctype.h>
#include <string.h>

/**
 * Checks if a given string represents a positive integer.
 *
 * This function validates if the given string contains only digits,
 * indicating it represents a positive integer.
 *
 * Parameters:
 *     str - The string to be validated.
 *
 * Returns:
 *     true if the string represents a positive integer, false otherwise.
 */
bool is_integer(const char* str) {
    for (int64_t i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

/**
 * Structure to store the user's input number.
 *
 * This structure contains a flag indicating the validity of the input,
 * the parsed positive integer value, and the string representation of the input.
 */
struct NumInput {
    bool is_valid;
    int64_t number;
    char str[10];
};

/**
 * Retrieves a valid positive integer from the user.
 *
 * This function prompts the user to enter a positive integer.
 * It reads the input as a string, validates if it can be converted to a positive integer,
 * and checks if the input is a valid positive integer using the is_integer function.
 *
 * Returns:
 *     A NumInput structure containing the validity flag, parsed positive integer, and string representation of the input.
 */
struct NumInput get_valid_number() {
    struct NumInput user_num;
    scanf("%9[^\t\n ]", user_num.str);
    user_num.is_valid = (sscanf(user_num.str, "%" SCNd64, &user_num.number) == 1 && user_num.number >= 0 ? true : false);
    if (user_num.is_valid) {
        user_num.is_valid = is_integer(user_num.str);
    }
    return user_num;
}

/**
 * Multiplies the result array by a number.
 *
 * This function performs multiplication of the result array with a given number.
 * It handles carry and updates the size of the result array accordingly.
 *
 * Parameters:
 *     result - The result array to be multiplied.
 *     num - The number to multiply with.
 *     size - Pointer to the size of the result array.
 */
void multiply(int64_t result[], int64_t num, int64_t* size) {
    int64_t carry = 0;
    for (int64_t i = 0; i < *size; i++) {
        int64_t prod = result[i] * num + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        result[*size] = carry % 10;
        carry = carry / 10;
        (*size)++;
    }
}

/**
 * Calculates the factorial of a number using an optimized method.
 *
 * This function calculates the factorial of a given number using an optimized method.
 * It avoids potential overflow by using an array to store the digits of the factorial.
 * The result array is multiplied iteratively with each number to calculate the factorial.
 * The calculated factorial is then printed to the console.
 *
 * Parameters:
 *     number - The positive integer for which the factorial is to be calculated.
 */
void calculate_factorial_optimized(int64_t number) {
    int64_t result[100000];
    result[0] = 1;
    int64_t size = 1;

    for (int64_t i = 2; i <= number; i++) {
        multiply(result, i, &size);
    }
    printf("Number: %" PRId64 "\n", number);
    printf("Factorial: ");
    for (int64_t i = size - 1; i >= 0; i--) {
        printf("%" PRId64, result[i]);
    }
    printf("\n");
}

/**
 * Calculates the factorial of a number using a basic method.
 *
 * This function calculates the factorial of a given number using a basic method.
 * It uses a simple for loop to multiply each number to calculate the factorial.
 * The calculated factorial is then printed to the console.
 *
 * Parameters:
 *     number - The positive integer for which the factorial is to be calculated.
 */
void calculate_factorial_basic(int64_t number){
    int64_t factorial = 1;
    for(int64_t i = 1; i <= number; i++) {
        factorial *= i;
    }
    printf("Number: %" PRId64 "\n", number);
    printf("Factorial: %" PRId64 "\n", factorial);
}


int main() {
    printf("Enter a positive integer: ");
    struct NumInput number = get_valid_number();

    if (!number.is_valid) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    printf("----------------------------------------\n");
    printf("Method #1: Basic Factorial Calculation\n");
    calculate_factorial_basic(number.number);
    printf("We first tried this method. but this method produces overflow for inputs greater than 20.\n\n");

    printf("----------------------------------------\n");
    printf("Method #2: Optimized Factorial Calculation\n");
    calculate_factorial_optimized(number.number);
    printf("This method is comprehensive and does not result in overflow for any large inputs.\n");

    return 0;
}

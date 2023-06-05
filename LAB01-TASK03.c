/**********************************************************************
 * LAB01-TASK03: Factorial Calculator
 *
 * Group Members:
                    * 1. Khushaalan Arjunan (A190409)
                    * 2. Wang Rui (A184975)
                    * 3. Stuart Heng Fu Yu (A189660)
                    * 4. Zhao Zhao (A184841)
 *
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

struct NumInput {
    bool is_valid;
    int64_t number;  
    char str[10]; 
};

/**
 * get_valid_number() - Get valid positive integer input from the user.
 *
 * This function prompts the user to enter a positive integer and validates the input.
 * It reads the input as a string using scanf and then attempts to convert it to a
 * 64-bit integer value using sscanf. 
 * 
 * If the conversion is successful and the number is greater than or equal to 0, 
 * the input is considered valid and stored in the NumInput structure. 
 * 
 * If the conversion fails or the number is negative, the input is considered invalid 
 * and is_valid field is set to false.
 *
 * Returns:
 *     NumInput structure containing the validated positive integer input.
 */
struct NumInput get_valid_number() {
    struct NumInput user_num;
    user_num.is_valid = true;
    scanf("%9[^\t\n ]", user_num.str);

    user_num.is_valid = (sscanf(user_num.str, "%" SCNd64, &user_num.number) == 1 && user_num.number >= 0 ? true : false);
    return user_num;
}

/**
 * multiply() - Multiply an array of digits with a number.
 *
 * This function multiplies an array of digits with a given number. It performs
 * the multiplication operation digit by digit and maintains a carry value for
 * each calculation. The result is stored in the original array, and the size
 * of the array is updated accordingly.
 * 
 *
 * Parameters:
 *     result - The array of digits to be multiplied.
 *     num - The number to multiply with.
 *     size - A pointer to the size of the array.
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
 * calculate_factorial_optimized() - Calculate factorial using an optimized method.
 *
 * This function calculates the factorial of a given number using an optimized method.
 * It maintains an array of digits to store the factorial result and performs the
 * multiplication operation iteratively. The result is printed in reverse order to
 * display the factorial value.
 * 
 * This doesn'e need to use a big integer library. It can handle large inputs without
 * resulting in overflow.
 *
 * Parameters:
 *     number - The number for which the factorial is to be calculated.
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
 * calculate_factorial_basic() - Calculate factorial using a basic method.
 *
 * This function calculates the factorial of a given number using a basic method.
 * It iteratively multiplies the number with each integer from 1 to the given number.
 * The result is printed directly as the factorial value.
 *
 * Parameters:
 *     number - The number for which the factorial is to be calculated.
 */
void calculate_factorial_basic(int64_t number){
    int64_t factorial = 1;
    for(int64_t i = 1; i <= number; i++) {
        factorial *= i;
    }
    printf("Number: %" PRId64 "\n", number);
    printf("Factorial: %" PRId64 "\n", factorial);
}

/**
 * main() - The entry point of the program.
 *
 * This function prompts the user to enter a positive integer. It validates the input
 * using the get_valid_number() function. 
 * 
 * If the input is invalid, an error message is displayed, and the program exits. 
 * 
 * If the input is valid, two methods for calculating the factorial are shown. Basic method and Optimized method. 
 * The factorial is calculated using both methods and displayed on the console.
 *
 * Returns:
 *     0 on successful execution.
 */
int main() {
    printf("Enter a positive integer: ");
    struct NumInput number = get_valid_number();

    if (!number.is_valid) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    printf("Method #1: Basic Factorial Calculation\n");
    calculate_factorial_basic(number.number);
    printf("This method may produce overflow for inputs greater than 20.\n\n");

    printf("Method #2: Optimized Factorial Calculation\n");
    calculate_factorial_optimized(number.number);
    printf("This method is comprehensive and does not result in overflow for any large inputs.\n");

    return 0;
}

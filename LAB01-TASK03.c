/**********************************************************************
 * Group Members:   1. Khushaalan Arjunan (A190409)
 *                  2. Wang Rui (A184975)
 *                  3. Stuart Heng Fu Yu (A189660)
 *                  4. Zhao Zhao (A184841)
 *
 * Welcome to our Third Task of the LAB01. Factorial Calculator !!! This is a simple C program that
 * calculates the factorial of a given positive integer.
 * 
 * We need to repeat the same error handling procedures as in LAB01-TASK01.c. Once we validate the input,
 * we use a for loop to calculate the factorial of the given number.
 * 
 * But there is a problem. The factorial of a number can be very large. So we need to use a data type that can store large numbers.
 * We can use the int64_t data type. But even with this data type, the factorial of a number can still be very large.
 * So we need to use an array to store the digits of the factorial.
 * 
 * We first tried the basic method to calculate the factorial. But this method produces overflow for inputs greater than 20.
 * It started producing overflowed negative numbers. So, I have tried another method called "Multiplication of Large Integers using an Array".
 * I have learnt this method when i was practicing for competitive programming. This method is comprehensive and does not result in overflow 
 * for any large inputs.
 * So, basically what it does is that it uses an array to store the digits of the factorial.
 * The result array is multiplied iteratively with each number to calculate the factorial.
 * 
 * Let's just say we want to calculate the factorial of 5.
 * So, we first initialize the result array with 1. So, the result array will be [1].
 * Then we multiply the result array with 2. So, the result array will be [2].
 * Then we multiply the result array with 3. So, the result array will be [6].
 * Then we multiply the result array with 4. So, the result array will be [4, 2].
 * Then we multiply the result array with 5. So, the result array will be [0, 2, 1].
 * 
 * So, the factorial of 5 is 120. And the result array is [0, 2, 1]. Then, we print the result array in reverse order.
 * Note:: I have used SCNd64 && PRId64 instead of %d to print the int64_t data type. int64_t is a signed 64-bit integer type and it can handle large numbers.
 * 
 * 
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <ctype.h>
#include <string.h>

bool is_integer(const char* str) {
    for (int64_t i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

struct NumInput {
    bool is_valid;
    int64_t number;
    char str[10];
};


struct NumInput get_valid_number() {
    struct NumInput user_num;
    scanf("%9[^\t\n ]", user_num.str);
    user_num.is_valid = (sscanf(user_num.str, "%" SCNd64, &user_num.number) == 1 && user_num.number >= 0 ? true : false);
    if (user_num.is_valid) {
        user_num.is_valid = is_integer(user_num.str);
    }
    return user_num;
}


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

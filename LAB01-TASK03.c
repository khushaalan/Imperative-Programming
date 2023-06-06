/**********************************************************************
 * LAB01-TASK03: Factorial Calculator
 *
 * Group Members:
                    * 1. Khushaalan Arjunan (A190409)
                    * 2. Wang Rui (A184975)
                    * 3. Stuart Heng Fu Yu (A189660)
                    * 4. Zhao Zhao (A184841)
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

    printf("Method #1: Basic Factorial Calculation\n");
    calculate_factorial_basic(number.number);
    printf("This method may produce overflow for inputs greater than 20.\n\n");

    printf("Method #2: Optimized Factorial Calculation\n");
    calculate_factorial_optimized(number.number);
    printf("This method is comprehensive and does not result in overflow for any large inputs.\n");

    return 0;
}

/*
LAB01-TASK03: Factorial Calculator

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

This program prompts the user to enter a positive integer and calculates its factorial.
*/

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

struct input_num {
    bool is_valid;
    int64_t number;
    char str[10];
};

// This function validates the input and returns a valid positive integer.
struct input_num get_valid_number() {
    struct input_num user_num;
    user_num.is_valid = true;
    scanf("%9[^\t\n ]", user_num.str);

    user_num.is_valid = (sscanf(user_num.str, "%" SCNd64, &user_num.number) == 1 && user_num.number >= 0 ? true : false);
    return user_num;
}

int main() {
    printf("Enter a positive integer: ");

    struct input_num number = get_valid_number();

    if (!number.is_valid) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    int64_t factorial = 1;

    for (int64_t i = 1; i <= number.number; i++) {
        factorial *= i;
    }

    printf("Number: %" PRId64 "\n", number.number);
    printf("Factorial: %" PRId64 "\n", factorial);

    return 0;
}

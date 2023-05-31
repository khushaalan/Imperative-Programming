/*
LAB01-TASK03: Factorial Calculator

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include <stdbool.h>
#define SCNd64 "I64d"
#define PRId64 "I64d"
#define ll long long int

int main() {
    printf("Enter a positive integer: ");
    ll num, factorial = 1;
    bool isNegative = false;
    scanf("%" SCNd64, &num);

    
    for (ll i = 1; i <= num; i++) {
        factorial *= i;
    }

    isNegative = (num < 0 ? true : false);
    if (isNegative) {
        printf("Please enter a positive integer. Please try again.\n");
    } else {
        printf("Number: %"PRId64"\n", num);
        printf("Factorial: %"PRId64"\n", factorial);
    }

    return 0;
}

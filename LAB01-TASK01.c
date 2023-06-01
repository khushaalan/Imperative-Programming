/*
LAB01-TASK01: Grade Calculator

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include<stdbool.h>
struct variables{
    bool is_number;
    float score;
    char str[10];
};

struct variables isNumber() {
    struct variables a;
    a.is_number = true;
    scanf("%5[^\t\n ]", a.str);

    a.is_number = (sscanf(a.str, "%f", &a.score) == 1 ? true : false);
    return a;
}

int main() {
    
    printf("Enter your score: ");


    if (isNumber().is_number==false) {
        printf("This is not a Valid Score. Please try again.\n");
        return 0;
    }


    if (isNumber().score >= 0 && isNumber().score <= 100) {
        if (isNumber().score >= 90 && isNumber().score <= 100) {
            printf("Score: %.1f\nGrade: A+\n", isNumber().score);
        } else if (isNumber().score >= 80 && isNumber().score < 90) {
            printf("Score: %.1f\nGrade: A\n", isNumber().score);
        } else if (isNumber().score >= 70 && isNumber().score < 80) {
            printf("Score: %.1f\nGrade: B+\n", isNumber().score);
        } else if (isNumber().score >= 60 && isNumber().score < 70) {
            printf("Score: %.1f\nGrade: B\n", isNumber().score);
        } else if (isNumber().score >= 50 && isNumber().score < 60) {
            printf("Score: %.1f\nGrade: C+\n", isNumber().score);
        } else if (isNumber().score >= 40 && isNumber().score < 50) {
            printf("Score: %.1f\nGrade: C\n", isNumber().score);
        } else if (isNumber().score >= 30 && isNumber().score < 40) {
            printf("Score: %.1f\nGrade: D\n", isNumber().score);
        } else {
            printf("Score: %.1f\nGrade: F\n", isNumber().score);
        }
    } else {
        printf("Invalid Score. Please enter a score between 0 and 100.\n");
    }

    return 0;
}

/*
LAB01-TASK01: Grade Calculator

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include<stdbool.h>

int main() {
    
    printf("Enter your score: ");
    float score;    char str[10];   bool is_number=false;  
    
    scanf("%5[^\t\n ]", str);
    // %5[^\t\n ] -> scan until 5 characters, no tab, no new line, no space
    is_number= (sscanf(str, "%f", &score) == 1? true: false);

    if (is_number==false) {
        printf("This is not a Valid Score. Please try again.\n");
        return 0;
    }


    if (score >= 0 && score <= 100) {
        if (score >= 90 && score <= 100) {
            printf("Score: %.1f\nGrade: A+\n", score);
        } else if (score >= 80 && score < 90) {
            printf("Score: %.1f\nGrade: A\n", score);
        } else if (score >= 70 && score < 80) {
            printf("Score: %.1f\nGrade: B+\n", score);
        } else if (score >= 60 && score < 70) {
            printf("Score: %.1f\nGrade: B\n", score);
        } else if (score >= 50 && score < 60) {
            printf("Score: %.1f\nGrade: C+\n", score);
        } else if (score >= 40 && score < 50) {
            printf("Score: %.1f\nGrade: C\n", score);
        } else if (score >= 30 && score < 40) {
            printf("Score: %.1f\nGrade: D\n", score);
        } else {
            printf("Score: %.1f\nGrade: F\n", score);
        }
    } else {
        printf("Invalid Score. Please enter a score between 0 and 100.\n");
    }

    return 0;
}

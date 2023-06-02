/*
LAB01-TASK01: Grade Calculator

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include<stdbool.h>

struct input_score{
    bool is_valid;
    float score;
    char str[10];
};

struct input_score get_valid_score() {
    struct input_score user_score;
    user_score.is_valid = true;
    scanf("%5[^\t\n ]", user_score.str);

    user_score.is_valid = (sscanf(user_score.str, "%f", &user_score.score) == 1 ? true : false);
    return user_score;
}

int main() {
    printf("Enter your score: ");

    struct input_score score = get_valid_score();

    if (score.is_valid==false) {
        printf("This is not a Valid Score. Please try again.\n");
        return 0;
    }

    if (score.score >= 0 && score.score <= 100) {
        if (score.score >= 90 && score.score <= 100) {
            printf("Score: %.1f\nGrade: A+\n", score.score);
        } else if (score.score >= 80 && score.score < 90) {
            printf("Score: %.1f\nGrade: A\n", score.score);
        } else if (score.score >= 70 && score.score < 80) {
            printf("Score: %.1f\nGrade: B+\n", score.score);
        } else if (score.score >= 60 && score.score < 70) {
            printf("Score: %.1f\nGrade: B\n", score.score);
        } else if (score.score >= 50 && score.score < 60) {
            printf("Score: %.1f\nGrade: C+\n", score.score);
        } else if (score.score >= 40 && score.score < 50) {
            printf("Score: %.1f\nGrade: C\n", score.score);
        } else if (score.score >= 30 && score.score < 40) {
            printf("Score: %.1f\nGrade: D\n", score.score);
        } else {
            printf("Score: %.1f\nGrade: F\n", score.score);
        }
    } else {
        printf("Invalid Score. Please enter a score between 0 and 100.\n");
    }

    return 0;
}

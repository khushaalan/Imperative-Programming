/**********************************************************************
 * LAB01-TASK01: Grade Calculator
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


struct ScoreInput {
    bool is_valid; 
    float score;
    char str[10];
};

/**
 * get_valid_score() - Get valid score input from the user.
 *
 * This function prompts the user to enter a score and validates the input.
 * 
 * It reads the input as a string using scanf and then attempts to convert it
 * to a float value using sscanf. 
 * If the conversion is successful, the input is considered valid and stored in the ScoreInput structure. 
 * If the conversion fails, the input is considered invalid and is_valid field is set to false.
 *
 * Returns:
 *     ScoreInput structure containing the validated score input.
 */
struct ScoreInput get_valid_score() {
    struct ScoreInput user_score;
    user_score.is_valid = true;

    /**
     * %5[^\t\n ] - Matches up to 5 characters that are not a tab, newline, or space.
     * This is to prevent buffer overflow.
    */
    scanf("%5[^\t\n ]", user_score.str);
    user_score.is_valid = (sscanf(user_score.str, "%f", &user_score.score) == 1 ? true : false);

    return user_score;
}

/**
 * main() - The entry point of the program.
 *
 * This function calls the get_valid_score() function to get a valid score input from the user.
 * Based on the input, it determines if the score is valid and falls within the range of 0 to 100. 
 * If the score is valid, it determines the grade based on the score and prints the score and grade.
 * If the score is invalid or outside the valid range, it displays an error message.
 *
 * Returns:
 *     0 on successful execution.
 */
int main() {
    printf("Enter your score: ");
    struct ScoreInput score = get_valid_score();

    if (score.is_valid == false) {
        printf("Invalid score. Please enter a score between 0 and 100.\n");
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
        printf("Invalid score. Please enter a score between 0 and 100.\n");
    }

    return 0;
}

/**********************************************************************
 * LAB01-TASK01: Grade Calculator
 *
 * Group Members:
 * 1. Khushaalan Arjunan (A190409)
 * 2. Wang Rui (A184975)
 * 3. Stuart Heng Fu Yu (A189660)
 * 4. Zhao Zhao (A184841)
 *
 *
 **********************************************************************/

/* Necessary libraries are included. */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>

/* A structure, ScoreInput, is defined to store the user input as a string and as a float, and to record whether the input is valid. */
struct ScoreInput {
    bool is_valid;  /**< Flag to indicate if the input is valid. */
    float score;    /**< The user's score. */
    char str[10];   /**< The user's input as a string. */
};

/**
 * Checks if a given string can be converted to a float.
 *
 * This function validates if the given string can be successfully converted to a float.
 * It checks if the string contains only digits and at most one decimal point.
 *
 * Parameters:
 *     str - The string to be validated.
 *
 * Returns:
 *     true if the string is a valid float, false otherwise.
 */
bool is_float(const char* str) {
    bool point_seen = false;
    for (int64_t i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            if (point_seen) {
                return false;
            }
            point_seen = true;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

/**
 * Reads and validates the user's score input.
 *
 * This function prompts the user to enter their score and reads the input as a string.
 * It then attempts to convert the string to a float and validates if it is a valid float using the is_float function.
 * The function returns a ScoreInput structure containing the validated score and input string.
 *
 * Returns:
 *     A ScoreInput structure containing the validated score and input string.
 */
struct ScoreInput get_valid_score() {
    struct ScoreInput user_score;
    user_score.is_valid = true;

    /* First, the function attempts to read the user input as a string up to a newline character.
     * If this fails, the function sets is_valid to false and returns.
     */
    if (scanf("%[^\n]", user_score.str) != 1) {
        user_score.is_valid = false;
        return user_score;
    }

    /* Next, the function attempts to convert the string to a float.
     * If this fails, the function sets is_valid to false.
     */
    user_score.is_valid = (sscanf(user_score.str, "%f", &user_score.score) == 1 ? true : false);

    /* If the conversion to float was successful, the function checks whether the string is a valid float using the is_float function. */
    if (user_score.is_valid) {
        user_score.is_valid = is_float(user_score.str);
    }

    return user_score;
}


int main() {
    /* The user is prompted to enter their score. */
    printf("Enter your score: ");
    struct ScoreInput score = get_valid_score();

    /* If the input was not valid, an error message is printed, and the program terminates. */
    if (score.is_valid == false) {
        printf("Invalid score. Please enter a score between 0 and 100.\n");
        return 0;
    }

    /* If the input is valid, the program checks which range the score falls into and prints the score and the corresponding grade. */
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

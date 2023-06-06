/**********************************************************************
 * Group Members:   1. Khushaalan Arjunan (A190409)
 *                  2. Wang Rui (A184975)
 *                  3. Stuart Heng Fu Yu (A189660)
 *                  4. Zhao Zhao (A184841)
 *
 * Welcome to your First Task of the LAB01. Grade Calculator !!! This is a simple C program that
 * calculates the grade of a student based on the score entered by the user.
 * 
 * This Question is actually pretty straight forward, we just need to use if-else statement
 * to check the score and print the corresponding grade.
 * 
 * But the trickiest part is to validate the input, we need to check if the input is a valid float.
 * In the Question there, they didn't mention whether the input should be an integer or float.
 * But the Sample Output shows that the input should be float.
 * 
 * First, when we read the input using scanf(), we read it as a string.
 * Then we convert the string to a float using sscanf().
 * If the conversion is successful, then the input is a valid float.
 * If the conversion fails, then the input is not a valid float.
 * 
 * BUT there is a problem with this approach. If the input is "87abc" or "87.5abc", then the conversion
 * will be successful and the score will be 87.5. This is not correct. 
 * The reason is that sscanf() will read the string up to the first non-digit character and convert it to a float.
 * Once it sees the character 'a', it will stop reading the string and convert the string to a float.
 * 
 * To solve this problem, we need to validate the input before converting it to a float.
 * For this, I have written a function called "is_float()" which returns true if the given string
 * contains only digits and at most one decimal point.
 * If the '.' is seen once, then it is a valid float.
 * If the string contains any other character other than digits and '.', then it is not a valid float.
 * 
 * After validating the input, we can use if-else statement to check the score and print the corresponding grade.
 * We need to make sure that the score is within the range of 0 to 100.
 * If the score is not within the range, we raise an error message.
 * And that's pretty much it.
 * 
 * 
 * 
 * 
 ****************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>

struct ScoreValue {
    bool is_valid;
    float score; 
    char str[10];
};

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


struct ScoreValue get_valid_score() {
    struct ScoreValue user_score;
    user_score.is_valid = true;

    if (scanf("%[^\n]", user_score.str) != 1) {
        user_score.is_valid = false;
        return user_score;
    }
    user_score.is_valid = (sscanf(user_score.str, "%f", &user_score.score) == 1 ? true : false);

    if (user_score.is_valid) {
        user_score.is_valid = is_float(user_score.str);
    }

    return user_score;
}


int main() {
    printf("Enter your score: ");
    struct ScoreValue score_value = get_valid_score();

    if (score_value.is_valid == false) {
        printf("Invalid Score. Please enter a score between 0 and 100.\n");
        return 0;
    }

    if (score_value.score >= 0 && score_value.score <= 100) {
        if (score_value.score >= 90 && score_value.score <= 100) {
            printf("Score: %.1f\n", score_value.score);
            printf("Grade: A+\n");
        } else if (score_value.score >= 80 && score_value.score < 90) {
            printf("Score: %.1f\n", score_value.score);
            printf("Grade: A\n");
        } else if (score_value.score >= 70 && score_value.score < 80) {
            printf("Score: %.1f\n", score_value.score);
            printf("Grade: B+\n");
        } else if (score_value.score >= 60 && score_value.score < 70) {
            printf("Score: %.1f\n", score_value.score);
            printf("Grade: B\n");
        } else if (score_value.score >= 50 && score_value.score < 60) {
            printf("Score: %.1f\n", score_value.score);
            printf("Grade: C+\n");
        } else if (score_value.score >= 40 && score_value.score < 50) {
            printf("Score: %.1f\n", score_value.score);
            printf("Grade: C\n");
        } else if (score_value.score >= 30 && score_value.score < 40) {
            printf("Score: %.1f\n", score_value.score);
            printf("Grade: D\n");
        } else {
            printf("Score: %.1f\n", score_value.score);
            printf("Grade: F\n");
        }
    } else {
        printf("Invalid Score. Please enter a score between 0 and 100.\n");
    }

    return 0;
}

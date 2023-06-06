/**********************************************************************
 * LAB01-TASK04: Guessing Game
 *
 * Group Members:
 * 1. Khushaalan Arjunan (A190409)
 * 2. Wang Rui (A184975)
 * 3. Stuart Heng Fu Yu (A189660)
 * 4. Zhao Zhao (A184841)
 *
 * This program is a number guessing game where the user has to guess a random number
 * between 1 and 100. The program provides feedback to the user indicating whether
 * their guess is too high or too low. The game continues until the user correctly
 * guesses the number.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <inttypes.h>

#define MAX_LINE_LENGTH 1024

/**
 * Checks if a given string represents an integer.
 *
 * This function validates if the given string contains only digits,
 * indicating it represents an integer.
 *
 * Parameters:
 *     str - The string to be validated.
 *
 * Returns:
 *     true if the string represents an integer, false otherwise.
 */
bool is_integer(const char* str) {
    for (int64_t i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}



int main(){

    srand(time(NULL));
    printf("Welcome to the Guessing Game!\nGuess a number between 1 and 100: ");
    int answer = rand() % 100 + 1;
    bool correct = false;
    char input_str[MAX_LINE_LENGTH];
    int guess;

    while(!correct){
        scanf(" %[^\t\n ]", input_str); // add a space before the format specifier
        if (!is_integer(input_str)) {
            printf("Invalid input! Please enter a number between 1 and 100: ");
            continue;
        }
        sscanf(input_str, "%d", &guess);

        if(guess < 1 || guess > 100){
            printf("Invalid input! Please enter a number between 1 and 100: ");
        }
        else if(guess == answer){
            printf("Congratulations! You guessed the number %d correctly.\n", answer);
            correct = true;
        }
        else if(guess < answer){
            printf("Too low! Guess a higher number: ");
        }
        else{
            printf("Too high! Guess a lower number: ");
        }
    }
    return 0;
}

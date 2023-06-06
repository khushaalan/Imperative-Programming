/**********************************************************************
 * LAB01-TASK04: Guessing Game
 * Group Members:   1. Khushaalan Arjunan (A190409)
 *                  2. Wang Rui (A184975)
 *                  3. Stuart Heng Fu Yu (A189660)
 *                  4. Zhao Zhao (A184841)
 * 
 * Welcome to our Fourth Task of the LAB01. Guessing Game !!! This is a simple C program that
 * generates a random number between 1 and 100 and asks the user to guess the number.
 * 
 * We need to repeat the same error handling procedures as in LAB01-TASK03.c which uses the is_integer() function.
 * Once we validate the input, we can initialise 2 values. The answer value and the guess value.
 * The answer value is a random number between 1 and 100. The guess value is the number guessed by the user.
 * 
 * For the answer value, I have used the rand() function to generate a random number between 1 and 100. 
 * Actually the built-in rand() function, is not truly random. It is a pseudo-random number generator. It generates a random number based on a seed value. 
 * Lets say we didn't initialize the seed value in the main method, then the rand() function will generate the same random number every time we run the program.
 * 
 * I have used the srand() function to initialize the seed value. I have used the time() function as the seed value. 
 * Because the time is always changing, the seed value will always be different. So, the rand() function will generate 
 * a different random number every time we run the program.
 * 
 * The next part of this program is to create a while loop. We want to keep asking the user to guess the number 
 * until the user guesses the number correctly. 
 * If the user has guessed the number correctly, we print a congratulatory message and exit the program. 
 * If the user has not guessed the number correctly, we print a message indicating whether the guess is too high or too low.
 * 
 * That's it for this task.
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
        scanf(" %[^\t\n ]", input_str);
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

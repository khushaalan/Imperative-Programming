/**********************************************************************
 * LAB01-TASK03: Guessing Game
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
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

/**
 * main() - The entry point of the program.
 *
 * This function implements a guessing game where the user tries to guess a randomly
 * generated number between 1 and 100. 
 * 
 * The function generates a random number using the srand() and rand() functions. 
 * If we do not  set the seed using srand(), the rand() function will generate the same
 * random number every time the program is run.
 * 
 * What I did here is I set the seed to the current time, so that the random number
 * generated will be different every time the program is run.
 * 
 * The user's input is read using fgets() to allow for error checking and prevent buffer overflow.
 * The user's input is then validated, and the program provides feedback based on the input. 
 * 
 * If the user guesses the correct number, a success message is displayed, and the program exits. 
 * If the guess is too high or too low, the user is prompted to guess again. 
 * Invalid inputs or errors in reading input are handled gracefully.
 *
 * Returns:
 *     0 on successful execution.
 */
int main(){

    srand(time(NULL));
    printf("Welcome to the Guessing Game!\nGuess a number between 1 and 100: ");
    int guess, answer = rand() % 100 + 1;
    bool correct = false;
    char line[MAX_LINE_LENGTH];
    int scanResult;

    while(!correct){
        if(fgets(line, MAX_LINE_LENGTH, stdin) == NULL){
            printf("Error reading input! Please try again: ");
            continue;
        }
        scanResult = sscanf(line, "%d", &guess);
        if(scanResult < 1 || guess < 1 || guess > 100){
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

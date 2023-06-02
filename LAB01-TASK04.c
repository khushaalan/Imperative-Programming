/*
LAB01-TASK04: Guessing Game

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

int main(){
    // Seed the random number generator with the current time
    srand(time(NULL));
    printf("Welcome to the guessing game!\nGuess a number between 1 and 100: ");
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

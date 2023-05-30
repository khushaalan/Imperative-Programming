/*
LAB01-TASK04: Guessing Game

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include<stdbool.h>

int main(){
    printf("Welcome to the guessing game!\nGuess a number between 1 and 100: ");
    int guess, answer = 65;
    bool correct = false;
    
    while(!correct){
        scanf("%d", &guess);
        if(guess == answer){
            printf("Correct!\n");
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
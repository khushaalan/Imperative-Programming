/*
LAB01-TASK03: Factorial Calculator

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/


#include <stdio.h>
#include<stdbool.h>
#define ll long long int

int main(){
    printf("Enter a positive integer: ");
    ll num, factorial=1;
    bool isNegative = false;
    scanf("%lld", &num);

    isNegative = (num<0 ? true:false);
    for(ll i = 1; i <= num; i++){
        factorial *= i;
    }


    if(isNegative){
        printf("Please enter a positive integer.Please try again.\n");
    }else{
        printf("Number: %lld\nFactorial: %lld\n", num, factorial);
    }

    return 0;
}
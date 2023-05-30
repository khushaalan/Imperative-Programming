/*
LAB01-TASK02: Temperature Classification

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include<stdbool.h>
#include<limits.h>

int main() {
    printf("Enter the temperature in degrees Celsius: ");
    float temperature;  int temp;
    scanf("%f", &temperature);
    temp = (int) temperature;

    switch(temp) {
        case INT_MIN ... -1:
            printf("The entered temperature is Freezing\n");
            break;
        case 0 ... 10:
            printf("The entered temperature is Cold\n");
            break;
        case 11 ... 25:
            printf("The entered temperature is Moderate\n");
            break;
        case 26 ... 35:
            printf("The entered temperature is Hot\n");
            break;
        case 36 ... INT_MAX:
            printf("The entered temperature is Extreme\n");
            break;
        default:
            printf("Invalid temperature\n");
    }

    return 0;
}

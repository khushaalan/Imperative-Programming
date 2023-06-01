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
#include<math.h>

int roundFunc(float num) {
    int temp=0;
    if(num < 0) {
        temp = -1;
    } else if (num < 35) {
        temp = round(num);
    } else {
        temp = 36;
    }
    return temp;
}

int main() {
    printf("Enter the temperature in degrees Celsius: ");
    float temperature;  int temp; char str[10];  bool is_number=false;
    scanf("%5[^\t\n ]", str);
    // %5[^\t\n ] -> scan until 5 characters, no tab, no new line, no space
    is_number= (sscanf(str, "%f", &temperature) == 1? true: false);

    if (is_number==false) {
        printf("This is not a Valid Score. Please try again.\n");
        return 0;
    }
    temp =  roundFunc(temperature);

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

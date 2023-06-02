/*
LAB01-TASK02: Temperature Classification

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int classify_temperature(float temperature) {
    int rounded_temp = 0;
    if (temperature < 0) {
        rounded_temp = -1;
    } else if (temperature <= 35) {
        rounded_temp = round(temperature);
    } else {
        rounded_temp = 36;
    }
    return rounded_temp;
}

int main() {
    printf("Enter the temperature in degrees Celsius: ");

    float temperature;
    int temp_category;
    char input_str[10];
    bool is_valid = false;
    
    scanf("%5[^\t\n ]", input_str);

    is_valid = (sscanf(input_str, "%f", &temperature) == 1 ? true : false);

    if (is_valid == false) {
        printf("This is not a Valid Temperature. Please try again.\n");
        return 0;
    }

    temp_category =  classify_temperature(temperature);

    // Classify the temperature
    switch (temp_category) {
        case INT_MIN ... -1:
            printf("The entered temperature is freezing\n");
            break;
        case 0 ... 10:
            printf("The entered temperature is cold\n");
            break;
        case 11 ... 25:
            printf("The entered temperature is moderate\n");
            break;
        case 26 ... 35:
            printf("The entered temperature is hot\n");
            break;
        case 36 ... INT_MAX:
            printf("The entered temperature is extreme\n");
            break;
        default:
            printf("Invalid temperature\n");
    }

    return 0;
}

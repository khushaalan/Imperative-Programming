/********************************************************************** * 
 * Group Members:   1. Khushaalan Arjunan (A190409)
 *                  2. Wang Rui (A184975)
 *                  3. Stuart Heng Fu Yu (A189660)
 *                  4. Zhao Zhao (A184841)
 *
 * Welcome to our Second Task of the LAB01. Temperature Classification !!! This is a simple C program that
 * classifies the temperature into one of the five categories: freezing, cold, moderate, hot, or extreme.
 * 
 * We need to repeat the same error handling procedures as in LAB01-TASK01.c. Once we validate the input, 
 * we use a switch statement to check the temperature and print the corresponding category. 
 * It is stated in the Question that the we MUST use switch statement. Cannot use if-else statement.
 * Switch statement is only accepts INTEGER data type as the case. So we need to round the temperature to the nearest integer.
 * But this doesnt apply to the freezing category and extreme category.
 * 
 * If the temperature is negative, then we set the category to -1 instead of rounding it to the nearest integer.
 * If the temperature is greater than 35, then we set the category to 36. because again it doesnt apply to the extreme category.
 * Let me explain why.
 * Let's say the temperature is 35.3, we cannot round it to 35. We need to round it to 36. Because the rule is that
 * if the temperature is greater than 35, then it is extreme. So we need to round it to 36.
 * Same goes to the freezing category. If the temperature is -0.3, we cannot round it to 0. We need to round it to -1.
 * Because the rule is that if the temperature is negative, then it is freezing. So we need to round it to -1.
 * Only when the temperature is between 0 and 35, then we round it to the nearest integer.
 * 
 * For the is_float() function, I have amended it to check if the string contains a negative sign at the beginning.
 * If the string contains a negative sign at the beginning, then it is a valid float.
 * This will allow us to enter negative temperature. And that's pretty much it for this task.
 * 
 *
 **********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <inttypes.h>

bool is_float(const char* str) {
    bool point_seen = false;
    for (int64_t i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            if (point_seen) {
                return false;
            }
            point_seen = true;
        } else if (str[i] == '-' && i == 0) {
            continue;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}


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

    scanf("%[^\t\n ]", input_str);

    is_valid = (sscanf(input_str, "%f", &temperature) == 1 ? true : false);
    
    if (is_valid) {
        is_valid = is_float(input_str);
    }

    if (is_valid == false) {
        printf("This is not a Valid Temperature. Please try again.\n");
        return 0;
    }

    temp_category = classify_temperature(temperature);

    switch (temp_category) {
        case INT_MIN ... -1:
            printf("The entered temperature is freezing.\n");
            break;
        case 0 ... 10:
            printf("The entered temperature is cold.\n");
            break;
        case 11 ... 25:
            printf("The entered temperature is moderate.\n");
            break;
        case 26 ... 35:
            printf("The entered temperature is hot.\n");
            break;
        case 36 ... INT_MAX:
            printf("The entered temperature is extreme.\n");
            break;
        default:
            printf("This is not a Valid Temperature.n");
    }

    return 0;
}

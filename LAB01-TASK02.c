/**********************************************************************
 * LAB01-TASK02: Temperature Classification
 *
 * Group Members:
 * 1. Khushaalan Arjunan (A190409)
 * 2. Wang Rui (A184975)
 * 3. Stuart Heng Fu Yu (A189660)
 * 4. Zhao Zhao (A184841)
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

/**
 * Checks if a given string can be converted to a float.
 *
 * This function validates if the given string can be successfully converted to a float.
 * It checks if the string contains only digits and at most one decimal point.
 *
 * Parameters:
 *     str - The string to be validated.
 *
 * Returns:
 *     true if the string is a valid float, false otherwise.
 */
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


/**
 * Classifies the temperature into a category.
 *
 * This function takes a temperature as input and classifies it into one of the five categories:
 * freezing, cold, moderate, hot, or extreme. The temperature is rounded to the nearest integer
 * and returned as the category.
 *
 * Parameters:
 *     temperature - The input temperature.
 *
 * Returns:
 *     The rounded temperature as the category.
 */
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
    
    /* Checking if input string is a valid float */
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
            printf("Invalid temperature\n");
    }

    return 0;
}

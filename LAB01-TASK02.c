/**********************************************************************
 * LAB01-TASK02: Temperature Classification
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
#include <limits.h>
#include <math.h>

/**
 * classify_temperature() - Classify the temperature into categories.
 *
 * This function takes a temperature value as input and classifies it into
 * different categories based on the given temperature ranges. The temperature
 * is rounded to the nearest whole number. The categories are defined as follows:
 * 
 * - Freezing: Temperatures below 0 degrees Celsius
 * - Cold: Temperatures between 0 and 10 degrees Celsius (inclusive)
 * - Moderate: Temperatures between 11 and 25 degrees Celsius (inclusive)
 * - Hot: Temperatures between 26 and 35 degrees Celsius (inclusive)
 * - Extreme: Temperatures above 35 degrees Celsius
 *
 * Parameters:
 *     temperature - The temperature value to be classified.
 *
 * Returns:
 *     The rounded temperature value, which represents the category.
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

/**
 * main() - The entry point of the program.
 *
 * This function prompts the user to enter a temperature in degrees Celsius.
 * It validates the input and determines the category of the temperature using
 * the classify_temperature() function. The program then displays the category
 * based on the rounded temperature value.
 * 
 * The main reason why we need the classify_temperature() function is because
 * we need to round the temperature value to the nearest whole number before
 * we can classify it into the different categories.
 * 
 * The Switch statement only accepts integer values as cases. Therefore, we
 * need to round the temperature value to the nearest whole number before we
 * can use it in the Switch statement.
 * 
 * And also for cases like (temperature>10 AND temperature<11), we need to round the temperature value
 * If the temperature value is 10.5, we need to round it to 11 so that it can
 * be classified as Moderate.
 * If the temperature value is 10.4, we need to round it to 10 so that it can
 * be classified as Cold.
 * 
 *
 * Returns:
 *     0 on successful execution.
 */
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

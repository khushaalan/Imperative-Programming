#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <inttypes.h>

/* Function to check if a string can be converted to float. */
bool is_float(const char* str) {
    bool point_seen = false;
    for (int64_t i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            if (point_seen) {
                return false;
            }
            point_seen = true;
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

/**********************************************************************
 * LAB01-TASK05: Scenario Based Question
 * Group Members:   1. Khushaalan Arjunan (A190409)
 *                  2. Wang Rui (A184975)
 *                  3. Stuart Heng Fu Yu (A189660)
 *                  4. Zhao Zhao (A184841)
 * 
 * Welcome to our Fifth Task of the LAB01.Scenario Based Question !!! This is a simple C program that
 * generates a random employee ID, calculates the age of the employee, and prints the employee details.
 * 
 * We need to repeat the same error handling procedures as in LAB01-TASK03.c. But now we don't really 
 * need the is_integer() function or the is_float() function.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int year;
    int day;
} DetailedAge;


/**
 * getCurrentDate() - Get the current date.
 *
 * This function retrieves the current date from the system's clock and
 * returns it as a Date structure.
 *
 * Returns:
 *     Date structure representing the current date.
 */
Date getCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    Date date;
    date.day = tm.tm_mday;
    date.month = tm.tm_mon + 1;
    date.year = tm.tm_year + 1900;

    return date;
}


/**
 * isLeap() - Check if a year is a leap year.
 *
 * This function determines if a given year is a leap year or not.
 *
 * Parameters:
 *     year - The year to be checked.
 *
 * Returns:
 *     1 if the year is a leap year, 0 otherwise.
 */
int isLeap(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}


/**
 * countLeapYears() - Count the number of leap years.
 *
 * This function counts the number of leap years that have occurred
 * until the given date.
 *
 * Parameters:
 *     d - The date until which leap years are to be counted.
 *
 * Returns:
 *     The number of leap years.
 */
int countLeapYears(Date d) {
    int years = d.year;
    if (d.month <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}


/**
 * calculateDays() - Calculate the number of days between two dates.
 *
 * This function calculates the number of days between two given dates,
 * taking leap years into account.
 *
 * Parameters:
 *     dob - The date of birth.
 *     current - The current date.
 *
 * Returns:
 *     The number of days between the two dates.
 */
int calculateDays(Date dob, Date current) {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long int dobDays = dob.year * 365 + dob.day;
    for (int i = 0; i < dob.month - 1; i++)
        dobDays += monthDays[i];
    dobDays += countLeapYears(dob);

    long int currentDays = current.year * 365 + current.day;
    for (int i = 0; i < current.month - 1; i++)
        currentDays += monthDays[i];
    currentDays += countLeapYears(current);

    return (currentDays - dobDays);
}

/**
 * calculateAge() - Calculate the age based on the date of birth.
 *
 * This function calculates the age in years and days based on the given
 * date of birth.
 *
 * Parameters:
 *     dateofbirth - The date of birth in the format "day month year".
 *
 * Returns:
 *     DetailedAge structure containing the calculated age in years and days.
 */
DetailedAge calculateAge(char dateofbirth[]) {
    DetailedAge detailed_age;
    Date dob;

    if (sscanf(dateofbirth, "%d %d %d", &dob.day, &dob.month, &dob.year) != 3) {
        printf("Invalid date format\n");
    }

    Date current = getCurrentDate();
    int totalDays = calculateDays(dob, current);
    
    detailed_age.year = totalDays / 365;
    detailed_age.day  = totalDays;
    return detailed_age;
}



/**
 * generateEmployeeID() - Generate a random employee ID.
 *
 * This function generates a random employee ID in the format "Rxxxx",
 * where 'xxxx' is a random four-digit number.
 *
 * Returns:
 *     A dynamically allocated string containing the generated employee ID.
 *     The string must be freed after use to prevent memory leaks.
 */
char * generateEmployeeID() {
    char * employeeID = malloc(sizeof(char) * 6);
    sprintf(employeeID, "R%04d", rand() % 10000);
    return employeeID;
}



int main() {
    //Initialise seed for random number generator
    srand(time(NULL));


    /** Since C language does not have a built-in function for mapping month 
     * to number of days, we have to create our own array that maps the month
     * to the number of days. 
     * 
     * The first element of the array is 0 because we want to map the month 
     * to the index of the array. So, January is index 1, February is index 2, 
     * and so on. It acts like a dictionary.
     * 
     * For this, we can also use a structure, but ii prefer to use an array.
     * 
     * */
    int numofDays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int numofDaysLeap[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

    char name[1000],  department[1000], dateofbirth[50];
    int day, month, year, isAlphabet=0;



    /** Prompt user for name
     *  %*c is used to clear the input buffer
     *  %[^\n\t] is used to read the input until a newline or tab is encountered
     * 
     *  Then, we check the input to see if it is an alphabet, using ASCII values
     *  Small letters ==> 97 to 122 (a to z)
     *  Capital letters ==> 65 to 90 (A to Z)
     * 
     *  If it is an alphabet, we increment the isAlphabet variable, which is used
     *  to check if the input is an empty string.
     * 
     * */
    printf("Enter name: ");    
    scanf("%[^\n\t]%*c", name);
    for(size_t i=0;i<strlen(name);i++){
        if((name[i]> 'a' && name[i]<'z') || (name[i]> 'A' && name[i]<'Z') ){  
            isAlphabet++;  
        }
    }
    if(isAlphabet<=0){
        printf("This is an Empty String\n");
        return 0;
    }


    /** Prompt user for department
     *  %*c is used to clear the input buffer
     *  %[^\n\t] is used to read the input until a newline or tab is encountered
     * 
     *  Then, we check the input to see if it is an alphabet, using ASCII values
     *  Small letters ==> 97 to 122 (a to z)
     *  Capital letters ==> 65 to 90 (A to Z)
     * 
     *  If it is an alphabet, we increment the isAlphabet variable, which is used
     *  to check if the input is an empty string.
     * 
     * */
    printf("Enter department: ");   
    scanf("%[^\n\t]%*c", department);   
    isAlphabet = 0;
    for(size_t i=0;i<strlen(department);i++){
        if((department[i]> 'a' && department[i]<'z') || (department[i]> 'A' && department[i]<'Z') ){  
            isAlphabet++; 
        }
    }
    if(isAlphabet<=0){
        printf("This is Empty String\n");
        return 0;
    }


    bool flag = false;
    int isDigit = 0;

    // Validate date of birth
    while(flag==false){
        isDigit = 0;    strcpy(dateofbirth, "");

        /** Prompt user for department
         * %*c is used to clear the input buffer
         * %[^\n\t] is used to read the input until a newline or tab is encountered
         * 
         * Then, we check the input to see if it is a digit, using ASCII values
         * Digits ==> 48 to 57 (0 to 9)
         * 
         * If it is a digit, we increment the isDigit variable, which is used
         * to check if the input is an empty string.
         * 
         * */

        printf("Enter birthdate (day month year): ");
        scanf("%[^\n\t]%*c", dateofbirth);
        for(size_t i=0;i<strlen(dateofbirth);i++){
            if(dateofbirth[i]>='0' && dateofbirth[i]<='9'){  isDigit++;  }
        }

        /**
         * We use sscanf to read the input string and store it in the day, month and year variables.
         * If the input is not in the format "day month year", sscanf will return a value less than 3.
         * 
         * We also check if the input is a digit, using the isDigit variable.
         * If the input is not a digit, or if sscanf returns a value less than 3, we print an error message.
         * And we exit the program.
         * 
         * This is a very tricky part of the program. If we don't return 0, the program will continue to run forever.
         * Let's say the user just press enter without entering anything. The program will never exit the while loop.
         * Because the isDigit variable will be 0, and sscanf will return a value less than 3.
         * 
        */
        if(sscanf(dateofbirth, "%d %d %d", &day, &month, &year) != 3 || isDigit<=0){
                printf("Invalid date format. Program will now exit.\n");
                return 0;

        }
        // Validate the date is not in today's date
        else if(calculateAge(dateofbirth).day == 0){
            printf("Are you sure you were born today?\n");
        }
        // Validate the date is not in the future
        else if(calculateAge(dateofbirth).day < 0){
            printf("You've entered a future date\n");
        }
        // Validate the month value is not more than 12 or less than 1
        else if(month>12 || month<1){
            printf("Invalid month\n");
        }
        // Validate the day value is not more than 31 or less than 1
        else if(day>31 || day<1){
            printf("Invalid day\n");
        }
        // Validate the year is not less than 1800
        else if(year < 1800){
            printf("Invalid year\n");
        }
        else{
            for(int i=0;i < 13;i++){
                /** If the year is a leap year, we check find the value for the key "month" in the numofDaysLeap array. "numberofDaysLeap[month]"
                 *  Let's say the input is 29 02 2020. The month value is 2. So, we check the value of numofDaysLeap[2], which is 29.
                 *  If the day value from the input(day = 30) is more than the number of days in the month (numofDaysLeap[2] = 29), we print an error message.
                 * 
                 *  If the year is not a leap year, we check find the value for the key "month" in the numofDays array. "numberofDays[month]"
                 *  Let's say the input is 29 02 2021. The month value is 2. So, we check the value of numofDays[2], which is 28.
                 *  If the day value from the input(day = 29) is more than the number of days in the month (numofDays[2] = 28), we print an error message.
                 * 
                 * */
                if(isLeap(year)){
                    if(month==i){
                        if(day>numofDaysLeap[i]){
                            printf("Invalid day\n");
                            flag = false;
                            break;
                        }
                        else{
                            flag = true;
                            break;
                        }
                    }
                }
                else{
                    if(month==i){
                        if(day>numofDays[i]){
                            printf("Invalid day\n");
                            flag = false;
                            break;
                        }
                        else{
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("\n\nEmployee Details\n\n-----------------------\n\n");
    char * employeeID = generateEmployeeID();
    printf("Employee ID: %s\n", employeeID);
    printf("Name: %s\n", name);
    printf("Department: %s\n", department);
    printf("Age: %d\n", calculateAge(dateofbirth).year);

    // Free the dynamically allocated memory to prevent memory leaks
    free(employeeID);

    return 0;
}

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
 * We need to repeat the same error handling procedures as in previous tasks. But the error handling here is a bit more complicated.
 * What I did is that for the name and department, I checked if the input is an alphabet(Case Insensitive). 
 * If any of the characters in the input is an non-alphabet(except space), it is considered as an invalid input.
 * I excluded the space character because the name and department can have spaces in between.
 * For the date of birth, I checked if the input is a digit. If any of the characters in the input is an non-digit, it is considered as an invalid input.
 * 
 * Then, I used sscanf to read the input string and store it in the day, month and year variables. If all the three variables are not assigned a value,
 * sscanf will return a value less than 3. If sscanf returns a value less than 3, it means that the input is not in the format "day month year". 
 * It is an invalid input.
 * 
 * Once the format is validated, I checked if the date is in today's date. 
 * If the date is in today's date, raise an error message.
 * I also checked if the date is in the future. If the date is in the future, raise an error message.
 * Only when the date is in the past, we proceed to check the month and day values.
 * 
 * Then, I checked if the month value is not more than 12 or less than 1. If the month value is more than 12 or less than 1, raise an error message.
 * Because there are only 12 months in a year. So, the month value cannot be more than 12 or less than 1.
 * Similarly, I checked if the day value is not more than 31 or less than 1. If the day value is more than 31 or less than 1, raise an error message.
 * Because there are only 31 days in a month. So, the day value cannot be more than 31 or less than 1.
 * Then, I checked if the year is not less than 1800. If the year is less than 1800, raise an error message.
 * Because its impossible for a person who is born in 1800 to be alive today.
 * 
 * Now comes the tricky part. We have to check which year is a leap year. If the year is a leap year, we have to check the number of days in February.
 * For example, 29 02 2021 is an invalid date because 2021 is not a leap year.
 * Same goes to months with 30 days. For example, 31 04 2021 is an invalid date because April has only 30 days.
 * To handle this, we can create dictionary alike structure to map the month to the number of days. Since C language does not have a built-in function for this,
 * I have created an array that maps the month to the number of days. The first element of the array is 0 because we want to map the month to the index of the array.
 * So, January is index 1, February is index 2, and so on. It acts like a dictionary.
 * 
 * If the year is a leap year, we check and find the "value" for the "key=month" in the numofDaysLeap array. "numberofDaysLeap[month]"
 * Let's say the input is 29 02 2020. The month value is 2. So, we check the value of numofDaysLeap[2], which is 29.
 * If the day value from the input(day = 30) is more than the number of days in the month (numofDaysLeap[2] = 29), we print an error message.
 * 
 * If the year is not a leap year, we check find the "value" for the "key=month" in the numofDays array. "numberofDays[month]"
 * Let's say the input is 29 02 2021. The month value is 2. So, we check the value of numofDays[2], which is 28.
 * If the day value from the input(day = 29) is more than the number of days in the month (numofDays[2] = 28), we print an error message.
 * 
 * If the input is valid, we exit the while loop and proceed to print the employee details. But before that, we need to generate a random employee ID.
 * Based on the given format, the employee ID is in the format "RXXXX", where XXXX is a random four-digit number.
 * To generate a random four-digit number, I used the rand() function and formatted it accordingly. 
 * Now, the employeeID is generated.
 * 
 * Then, we calculate the age of the employee. To calculate the age, we need to get the current date. Because in the question, it is stated that the age is 
 * calculated based on the current date and it should be precisely calculated. 
 * One way to precisely calculate the age is to get the current date from the system's clock. and subtract the user's date of birth from the current date. 
 * But its not that simple. We need to take leap years into account.
 * So i have created a function to calculate the number of days between two dates, taking leap years into account.
 * Once we get the number of days between two dates, we can calculate the age in years and days. But in the Sample Output, they only print the age in years.
 * So, I only print the age in years.
 * 
 * Finally, we print the employee details. and free the dynamically allocated memory to prevent memory leaks. 
 * That's it for this task.
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



Date getCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    Date date;
    date.day = tm.tm_mday;
    date.month = tm.tm_mon + 1;
    date.year = tm.tm_year + 1900;

    return date;
}


int isLeap(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}


int countLeapYears(Date d) {
    int years = d.year;
    if (d.month <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}


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


char * generateEmployeeID() {
    char * employeeID = malloc(sizeof(char) * 6);
    sprintf(employeeID, "R%04d", rand() % 10000);
    return employeeID;
}



int main() {
    srand(time(NULL));

    int numofDays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int numofDaysLeap[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

    char name[1000],  department[1000], dateofbirth[50];
    int day, month, year, isAlphabet=0, isSpace=0;


    printf("Enter name: ");    
    scanf("%[^\n\t]%*c", name);
    for(size_t i=0;i<strlen(name);i++){
        if((name[i]> 'a' && name[i]<'z') || (name[i]> 'A' && name[i]<'Z') ){  
            isAlphabet++;  
        }
        if (name[i] == ' '){
            isSpace++;
        }
    }
    if(isAlphabet<=0 || (strlen(name)!=isAlphabet && isSpace<=0)){
        printf("This is an Empty String\n");
        return 0;
    }

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

    while(flag==false){
        isDigit = 0;    strcpy(dateofbirth, "");


        printf("Enter birthdate (day month year): ");
        scanf("%[^\n\t]%*c", dateofbirth);
        for(size_t i=0;i<strlen(dateofbirth);i++){
            if(dateofbirth[i]>='0' && dateofbirth[i]<='9'){  isDigit++;  }
        }

        if(sscanf(dateofbirth, "%d %d %d", &day, &month, &year) != 3 || isDigit<=0){
                printf("Invalid date format. Program will now exit.\n");
                return 0;

        }
        else if(calculateAge(dateofbirth).day == 0){
            printf("Are you sure you were born today?\n");
        }
        else if(calculateAge(dateofbirth).day < 0){
            printf("You've entered a future date\n");
        }
        else if(month>12 || month<1){
            printf("Invalid month\n");
        }
        else if(day>31 || day<1){
            printf("Invalid day\n");
        }
        else if(year < 1800){
            printf("Invalid year\n");
        }
        else{
            for(int i=0;i < 13;i++){
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

    free(employeeID);

    return 0;
}

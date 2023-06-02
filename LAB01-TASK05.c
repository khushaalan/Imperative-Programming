/*
LAB01-TASK05: Scenario Based Question

Group Members:  
1. Khushaalan Arjunan (A190409)
2. Wang Rui (A184975)
3. Stuart Heng Fu Yu (A189660)
4. Zhao Zhao (A184841)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int getCurrentYear() {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    return tm->tm_year + 1900;
}

int calculateAge(int day, int month, int year) {
    int currentYear = getCurrentYear();
    if (year > currentYear || year < 1900) {
        printf("Invalid birth year.\n");
        exit(1);
    }

    time_t now = time(NULL);
    struct tm* birthday = localtime(&now);
    birthday->tm_year = year - 1900;
    birthday->tm_mon = month - 1;
    birthday->tm_mday = day;

    time_t birthTime = mktime(birthday);
    double seconds = difftime(now, birthTime);
    int age = seconds / (60 * 60 * 24 * 365.25);
    return age;
}

char* generateEmployeeID() {
    char* employeeID = malloc(sizeof(char) * 5);
    if (employeeID == NULL) {
        printf("Memory allocation failed for employee ID.\n");
        exit(1);
    }
    sprintf(employeeID, "R%04d", rand() % 10000);
    return employeeID;
}

int main() {
    srand(time(NULL));

    char name[50], department[20];
    int day, month, year;

    printf("Enter name: ");
    scanf(" %[^\n]%*c", name);

    printf("Enter department: ");
    scanf(" %[^\n]%*c", department);

    printf("Enter birthdate (day month year): ");
    if (scanf("%d %d %d", &day, &month, &year) != 3) {
        printf("Invalid input for birthdate.\n");
        exit(1);
    }

    printf("\n\nEmployee Details\n\n-----------------------\n\n");
    char* employeeID = generateEmployeeID();
    printf("Employee ID: %s\n", employeeID);
    printf("Name: %s\n", name);
    printf("Department: %s\n", department);
    printf("Age: %d\n", calculateAge(day, month, year));

    free(employeeID);

    return 0;
}

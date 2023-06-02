/*
LAB01-TASK05: Scenario Based Question

Group Members:  1. Khushaalan Arjunan (A190409)
                2. Wang Rui(A184975)
                3. Stuart Heng Fu Yu (A189660)
                4. Zhao Zhao(A184841)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int getcurrentYear() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900;
}

int calculateAge(int year) {
    return getcurrentYear() - year;
}

char * generateEmployeeID() {
    char * employeeID = malloc(sizeof(char) * 5);
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
    scanf("%d %d %d", &day, &month, &year);

    printf("\n\nEmployee Details\n\n-----------------------\n\n");
    char * employeeID = generateEmployeeID();
    printf("Employee ID: %s\n", employeeID);
    printf("Name: %s\n", name);
    printf("Department: %s\n", department);
    printf("Age: %d\n", calculateAge(year));

    free(employeeID);

    return 0;
}

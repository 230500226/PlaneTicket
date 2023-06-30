#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
// #include "Passenger.h"

// Function to handle invalid user input
void handleInvalidInput(int options) {
    system("cls");
    printf("Invalid choice. Please enter a number from 1 to %d.\n", options);
    // Clear the input buffer to remove any remaining characters
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    // This effectively restarts the program while preserving previous data
}

// Function to check if a string contains only digits
int isNumber(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Not a number
        }
    }
    return 1; // All characters are digits
}

// Function to prompt for and validate a 10-digit phone number
void getPassengerPhone(char *phone) {
    do {
        printf("Enter passenger phone number: ");
        scanf("%s", phone);
        if (!isNumber(phone) || strlen(phone) != 10) {
            printf("Invalid input. Please enter a valid 10-digit phone number.\n");
        }
    } while (!isNumber(phone) || strlen(phone) != 10);
}

// Function to prompt for and validate a 13-digit ID number and calculate the passenger's age
char *getPassengerID(int *age) {
    char *id = malloc(14 * sizeof(char));
    int numRead = 0;
    do {
        printf("Enter passenger ID: ");
        numRead = scanf("%13s", id);
        if (numRead == 0 || strlen(id) != 13 || !isNumber(id)) {
            printf("Invalid input. Please enter a valid 13-digit ID number.\n");
            // Clear the input buffer
            while ((getchar()) != '\n');
        }
    } while (numRead == 0 || strlen(id) != 13 || !isNumber(id));

    // Calculate the passenger's age based on the ID number
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;
    int currentMonth = tm.tm_mon + 1;
    int currentDay = tm.tm_mday;

    // Extract the birth year from the ID number
    char year[3];
    strncpy(year, id, 2);
    year[2] = '\0';
    int birthYear = atoi(year);

    // Determine the correct century for the birth year
    if (birthYear > currentYear % 100) {
        birthYear += 1900;
    } else {
        birthYear += 2000;
    }

    // Extract the birth month from the ID number
    char month[3];
    strncpy(month, id + 2, 2);
    month[2] = '\0';
    int birthMonth = atoi(month);

    // Extract the birth day from the ID number
    char day[3];
    strncpy(day, id + 4, 2);
    day[2] = '\0';
    int birthDay = atoi(day);

    // Calculate the age based on the current date and the birth date
    *age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        (*age)--;
    }

    return id;
}

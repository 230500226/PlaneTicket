#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
// #include "Passenger.h"

void handleInvalidInput(int options) {
        system("cls");
                printf("Invalid choice please enter a number from 1 to %d. \n", options);
                //clear the input buffer so that all characters the user entered last are removed
                //this prevents the program from reading old input data
        int c;
        while ((c = getchar()) != '\n' && c != EOF); 
        //effectively restarts the program keeping all previous data recorded
}
int isNumber(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

//makes sure that the user enters a 10 digit phone number
void getPassengerPhone(char *phone) {
    do {
        printf("Enter passenger phone number: ");
        scanf("%s", phone);
        if (!isNumber(phone) || strlen(phone) != 10) {
            printf("Invalid input. Please enter a valid 10-digit phone number.\n");
        }
    } while (!isNumber(phone) || strlen(phone) != 10);
}

//makes sure that the user enters a 13 digit number and gets thier age from the id
char *getPassengerID(int *age) {
    char *id = malloc(14 * sizeof(char));
    int numRead = 0;
    do {
        printf("Enter passenger ID: ");
        numRead = scanf("%13s", id);
        if (numRead == 0 || strlen(id) != 13 || !isNumber(id)) {
            printf("Invalid input. Please enter a valid 13-digit ID number.\n");
            // clear the input buffer
            while ((getchar()) != '\n');
        }
    } while (numRead == 0 || strlen(id) != 13 || !isNumber(id));

    // calculate age
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;
    int currentMonth = tm.tm_mon + 1;
    int currentDay = tm.tm_mday;

    char year[3];
    strncpy(year, id, 2);
    year[2] = '\0';
    int birthYear = atoi(year);
    if (birthYear > currentYear % 100) {
        birthYear += 1900;
    } else {
        birthYear += 2000;
    }

    char month[3];
    strncpy(month, id + 2, 2);
    month[2] = '\0';
    int birthMonth = atoi(month);

    char day[3];
    strncpy(day, id + 4, 2);
    day[2] = '\0';
    int birthDay = atoi(day);

    *age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        (*age)--;
    }

    return id;
}

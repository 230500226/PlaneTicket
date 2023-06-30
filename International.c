/************* AUTHOR INFO **************/
// Name: Shahied Rustin
// Student No.: 230500226
// Course Title: Software Design 1 (SDN150S)
// Date: 30/06/2023
/************* HEADER FILES ***************/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FlightType.h"
#include "Authentication.h"
#include "Passenger.h"
/************* GLOBAL VARIABLES ************/
#define MAX_PASSENGERS 3 // Maximum passengers allowed on the flight to the destination
                        // Yes, it's low but it's for test purposes and can easily be adjusted as needed

/******** FUNCTIONS (DECLARE/DEFINE) *********/
// Flight information
flightData internationalCountries[] = {
    // Simulated extra passengers for testing purposes
    {"France: Paris (CDG)", 1},
    {"Brazil: Brasilia (BSB)", 2},
    {"Japan: Tokyo (HND)", 3},
    {"South Africa: Johannesburg (JNB)", 1},
    {"ECanada: Ottawa (YOW)", 0},
    {"Australia: Canberra (CBR)", 1},
    {"Italy: Rome (FCO)", 2},
    {"India: New Delhi (DEL)", 2}
};

// Passenger information
passengerData ipassengers[MAX_PASSENGERS];
int inumPassengers = 0;
/************* MAIN FUNCTION**************/
int international() {
    system("cls");
    int choice;
    char cDisplayPassengers;
    int lengthCountries = sizeof(internationalCountries) / sizeof(internationalCountries[0]);

    // Display all passenger information for international flights
    printf("----Do you want to view all passenger information?----\n");
    printf("Y for yes\n");
    printf("Or any key and enter to continue\n");
    scanf(" %c", &cDisplayPassengers); // For some reason, getchar gave me an error and scanf works just fine
    cDisplayPassengers = toupper(cDisplayPassengers);
    if (cDisplayPassengers == 'Y') {
        displayAllPassengers(ipassengers, inumPassengers);
    }

origin:
    while (1) {
        // Choose origin country
        // Assuming that the origin country departure flight is always available for passengers (no limit)
        system("cls");
    originNoCls:
        printf("----Origin \nWhere from?----\n");
        int j = 1;
        for (int i = 0; i < lengthCountries; i++) {
            printf("%d. %s\n", j++, internationalCountries[i].city);
        }
        printf("%d. Exit\n", j);

        // Makes sure that the input is valid so that it doesn't loop
        if (scanf("%d", &choice) != 1) {
            handleInvalidInput(lengthCountries);
            goto originNoCls;
        }

        // Checks that the choice is within the menu
        if (choice >= 1 && choice <= lengthCountries) {
            strcpy(ipassengers[inumPassengers].origin, internationalCountries[choice - 1].city);
            system("cls");
            printf("==== You chose origin: %s ====\n", ipassengers[inumPassengers].origin);
            break;
        } else if (choice == j) {
            goto exit;
        } else {
            system("cls");
            printf("Invalid choice number, please try again...\n");
            goto originNoCls;
        }
    }

destination:
    while (1) {
        // Choose destination country
        printf("----Destination \nWhere to?----\n");
        int j = 1;
        for (int i = 0; i < lengthCountries; i++) {
            printf("%d. %s\n", j++, internationalCountries[i].city);
        }
        printf("%d. Exit\n", j);

        if (scanf("%d", &choice) != 1) {
            handleInvalidInput(lengthCountries);
            goto destination;
        }

        // Checks that the number is within the menu and checks that the origin is not the same as the destination
        if (choice >= 1 && choice <= lengthCountries) {
            if (strcmp(ipassengers[inumPassengers].origin, internationalCountries[choice - 1].city) != 0) {
                strcpy(ipassengers[inumPassengers].destination, internationalCountries[choice - 1].city);
                system("cls");
                printf("==== You chose destination: %s ====\n", ipassengers[inumPassengers].destination);
                break;
            } else {
                system("cls");
                printf("Your origin and destination location can't be the same. Please try again.\n");
                goto origin;
            }
        } else if (choice == j) {
            goto exit;
        } else {
            system("cls");
            printf("Invalid choice number, please try again...\n");
            goto destination;
        }
    }

    // Checks if there are seats available for the destination only
    for (int i = 0; i < sizeof(internationalCountries) / sizeof(internationalCountries[0]); i++) {
        if (strcmp(ipassengers[inumPassengers].destination, internationalCountries[i].city) == 0 && internationalCountries[i].passengers >= MAX_PASSENGERS) {
            system("cls");
            printf("Sorry, the flight to %s is fully booked. Please choose another destination.\n", ipassengers[inumPassengers].destination);
            goto destination;
        }
    }

    system("cls");
    printf("There are seats available for the flight to %s.\n", ipassengers[inumPassengers].destination);
    printf("Please enter your details to continue.\n");

    // Collect passenger information
    // Passes the whole array to check for unique ID
    createPassenger(ipassengers, inumPassengers);

    // Print reservation ticket information
    displayPassenger(&ipassengers[inumPassengers], inumPassengers);

    // Increment arrays for the next passenger reservation so that data is not overwritten
    for (int i = 0; i < (sizeof(internationalCountries) / sizeof(internationalCountries[0])); i++) {
        if (strcmp(ipassengers[inumPassengers].destination, internationalCountries[i].city) == 0) {
            internationalCountries[i].passengers++;
        }
    }
    inumPassengers++;

    // Confirmation for the passenger to view the ticket
    printf("Please press enter to confirm...\n");
    printf("Ready for the next passenger...\n");
    getchar();
    getchar();

exit:
    return 0;
}

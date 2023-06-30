#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FlightType.h"
#include "Authentication.h"
#include "Passenger.h"

#define MAX_PASSENGERS 3 // Maximum passengers allowed on the flight to the destination
                        // Yes, it's low but it's for test purposes and can easily be adjusted as needed 

// Flight information
flightData domesticCities[] = {
    // Simulated extra passengers for testing purposes
    {"Cape Town (CPT)", 1},
    {"Durban (DUR)", 2},
    {"Johannesburg (JNB)", 3},
    {"George (GRJ)", 0},
    {"East London (ELS)", 1},
    {"Bloemfontein (BFN)", 2}
};

// Passenger information
passengerData passengers[MAX_PASSENGERS];
int numPassengers = 0;

int domestic() {
    system("cls");
    int choice;
    char cDisplayPassengers;
    int lengthCity = sizeof(domesticCities) / sizeof(domesticCities[0]);

    // Display all passenger information for domestic flights
    printf("----Do you want to view all passenger information?----\n");
    printf("Y for yes\n");
    printf("Or any key and enter to continue\n");
    scanf(" %c", &cDisplayPassengers); // For some reason, getchar gave me an error and scanf works just fine 
    cDisplayPassengers = toupper(cDisplayPassengers);
    if (cDisplayPassengers == 'Y') {
        displayAllPassengers(passengers, numPassengers);
    }

origin:
    while (1) {
        // Choose origin country
        // Assuming that the origin country departure flight is always available for passengers (no limit)
        system("cls");
    originNoCls:
        printf("----Origin \nWhere from?----\n");
        int j = 1;
        for (int i = 0; i < lengthCity; i++) {
            printf("%d. %s\n", j++, domesticCities[i].city);
        }
        printf("%d. Exit\n", j);

        // Makes sure that the input is valid so that it doesn't loop
        if (scanf("%d", &choice) != 1) {
            handleInvalidInput(lengthCity);
            goto originNoCls;
        }

        // Checks that the choice is within the menu
        if (choice >= 1 && choice <= lengthCity) {
            strcpy(passengers[numPassengers].origin, domesticCities[choice - 1].city);
            system("cls");
            printf("==== You chose origin: %s ====\n", passengers[numPassengers].origin);
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
        for (int i = 0; i < lengthCity; i++) {
            printf("%d. %s\n", j++, domesticCities[i].city);
        }
        printf("%d. Exit\n", j);

        if (scanf("%d", &choice) != 1) {
            handleInvalidInput(lengthCity);
            goto destination;
        }

        // Checks that the number is within the menu and checks that the origin is not the same as destination
        if (choice >= 1 && choice <= lengthCity) {
            if (strcmp(passengers[numPassengers].origin, domesticCities[choice - 1].city) != 0) {
                strcpy(passengers[numPassengers].destination, domesticCities[choice - 1].city);
                system("cls");
                printf("==== You chose destination: %s ====\n", passengers[numPassengers].destination);
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

    // Check if there are seats available for the destination only
    for (int i = 0; i < sizeof(domesticCities) / sizeof(domesticCities[0]); i++) {
        if (strcmp(passengers[numPassengers].destination, domesticCities[i].city) == 0 && domesticCities[i].passengers >= MAX_PASSENGERS) {
            system("cls");
            printf("Sorry, the flight to %s is fully booked. Please choose another destination.\n", passengers[numPassengers].destination);
            goto destination;
        }
    }

    system("cls");
    printf("There are seats available for the flight to %s.\n", passengers[numPassengers].destination);
    printf("Please enter your details to continue.\n");

    // Collect passenger information
    // Passes the whole array to check for unique ID
    createPassenger(passengers, numPassengers);

    // Print reservation ticket information
    displayPassenger(&passengers[numPassengers], numPassengers);

    // Increment arrays for the next passenger reservation so that data is not overwritten
    for (int i = 0; i < (sizeof(domesticCities) / sizeof(domesticCities[0])); i++) {
        if (strcmp(passengers[numPassengers].destination, domesticCities[i].city) == 0) {
            domesticCities[i].passengers++;
        }
    }
    numPassengers++;

    // Confirmation for the passenger to view the ticket
    printf("Please press enter to confirm...\n");
    printf("Ready for the next passenger...\n");
    getchar();
    getchar();

exit:
    return 0;
}

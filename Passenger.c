#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passenger.h"
#include "Authentication.h"

// Checks if there are multiple passengers with the same ID for a flight
int checkID(char *id, passengerData *passengers, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(passengers[i].id, id) == 0) {
            return 1; // Multiple passengers with the same ID found
        }
    }
    return 0; // No duplicate IDs found
}

// Function to create a new passenger record
void createPassenger(passengerData *passengers, int numPassengers) {
    printf("Enter passenger name: ");
    scanf("%s", passengers[numPassengers].name);

    char *id;
    int age;
    do {
        id = getPassengerID(&age); // Prompt for unique passenger ID
        if (checkID(id, passengers, numPassengers)) {
            printf("Sorry, you have already booked a ticket for today.\n");
            printf("Please check your ID number or book for another time.\n");
        }
    } while (checkID(id, passengers, numPassengers));

    passengers[numPassengers].id = (id); // Store the passenger's ID

    passengers[numPassengers].age = age; // Store the passenger's age
    getPassengerPhone(passengers[numPassengers].phone); // Prompt for the passenger's phone number
}

// Function to display the details of a single passenger
void displayPassenger(passengerData *passenger, int numPassengers) {
    system("cls");
    printf("----You have successfully booked your flight----\n");
    printf("Here is your flight ticket:\n");
    printf("--------------------------------------------------\n");
    printf("Name: %s\n", passenger->name);
    printf("ID: %s\n", passenger->id);
    printf("Age: %d\n", passenger->age);
    printf("Phone number: %s\n", passenger->phone);
    printf("Origin: %s\n", passenger->origin);
    printf("Destination: %s\n", passenger->destination);
    printf("Thank you for choosing SAA. Have a safe flight!\n");
    printf("--------------------------------------------------\n");
}

// Function to display details of all passengers
void displayAllPassengers(passengerData *passenger, int numPassengers) {
    if (numPassengers == 0) {
        printf("No passengers have been created yet.\n");
        getchar();
    }

    int j = 1;
    for (int i = 0; i <= numPassengers - 1; i++) {
        printf("---------------------------------------------------\n");
        printf("Record number: %d\n", j);
        printf("Name: %s\n", passenger[i].name);
        printf("ID: %s\n", passenger[i].id);
        printf("Age: %d\n", passenger[i].age);
        printf("Phone number: %s\n", passenger[i].phone);
        printf("Origin: %s\n", passenger[i].origin);
        printf("Destination: %s\n", passenger[i].destination);
        printf("---------------------------------------------------\n");
        j++;
    }

    printf("Please press enter to confirm...\n");
    getchar();
    getchar();
}

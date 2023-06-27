#include "passenger.h"
#include <stdio.h>
#include <stdlib.h>

void displayPassenger(passengerData *passenger, int numPassengers) {
    system("cls");
    printf("----You have successfully booked your filght----\n");
    printf("Here is your flight ticket:\n");
    printf("--------------------------------------------------\n");
    printf("Name: %s\n", passenger->name);
    printf("ID: %d\n", passenger->id);
    printf("Phone number: %s\n", passenger->phone);
    printf("Origin: %s\n", passenger->origin);
    printf("Destination: %s\n", passenger->destination);
    printf("Thank you for choosing SAA have a safe flight\n");
    printf("--------------------------------------------------\n");
}

void createPassenger(passengerData *passenger, int numPassengers) {

    printf("Enter passenger name: ");
    scanf("%s", passenger->name);

    printf("Enter passenger ID: ");
    scanf("%d", &passenger->id);

    printf("Enter passenger phone number: ");
    scanf("%s", passenger->phone);

}

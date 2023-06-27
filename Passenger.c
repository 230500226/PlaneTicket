#include "passenger.h"
#include <stdio.h>
#include <stdlib.h>

void displayPassenger(passengerData *passenger) {
    system("cls");
    printf("----You have successfully booked your filght----");
    printf("Here is your flight ticket:");
    printf("--------------------------------------------------");
    printf("Name: %s\n", passenger->name);
    printf("ID: %d\n", passenger->id);
    printf("Phone number: %s\n", passenger->phone);
    printf("Origin: %s\n", passenger->origin);
    printf("Destination: %s\n", passenger->destination);
    printf("Thank you for choosing SAA have a safe flight");
    printf("--------------------------------------------------");
}

passengerData createPassenger() {
    passengerData *passenger;

    printf("Enter passenger name: ");
    scanf("%s", passenger->name);

    printf("Enter passenger ID: ");
    scanf("%d", &passenger->id);

    printf("Enter passenger phone number: ");
    scanf("%s", passenger->phone);

    printf("Enter passenger origin: ");
    scanf("%s", passenger->origin);

    printf("Enter passenger destination: ");
    scanf("%s", passenger->destination);

    return *passenger;
}

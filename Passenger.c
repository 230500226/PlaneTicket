#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passenger.h"
#include "Authentication.h"

//checks that the are not multiple of the same passengers booked for a flight on the same time (since this program is set to a specific depature and arrival time to reduce complexity)
int checkID(char *id, passengerData *passengers, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(passengers[i].id, id) == 0) {
            return 1;
        }
    }
    return 0;
}


void createPassenger(passengerData *passengers, int numPassengers) {

    //populates name
    printf("Enter passenger name: ");
    scanf("%s", passengers[numPassengers].name);

    //prompts passenger to enter the correct ID so that IDs are unique
    char *id;
    int age;
        do {
            id = getPassengerID(&age);
            if (checkID(id, passengers, numPassengers)) {
                printf("Sorry, you have already booked a ticket for today.\n");
                printf("Please check your ID number or book for another time.\n");
            }
        } while (checkID(id, passengers, numPassengers));
    //populates ID
    passengers[numPassengers].id = (id);

    //populates age
    passengers[numPassengers].age = age;
    //populates phone number
    getPassengerPhone(passengers[numPassengers].phone);

}

void displayPassenger(passengerData *passenger, int numPassengers) {
    system("cls");
    printf("----You have successfully booked your filght----\n");
    printf("Here is your flight ticket:\n");
    printf("--------------------------------------------------\n");
    printf("Name: %s\n", passenger->name);
    printf("ID: %s\n", passenger->id);
    printf("Age: %d\n", passenger->age);
    printf("Phone number: %s\n", passenger->phone);
    printf("Origin: %s\n", passenger->origin);
    printf("Destination: %s\n", passenger->destination);
    printf("Thank you for choosing SAA have a safe flight\n");
    printf("--------------------------------------------------\n");
}

void displayAllPassengers(passengerData *passenger, int numPassengers){
    if (numPassengers == 0){
        printf("No passengers have been created yet.\n");
        getchar();
    }
    int j = 1;
    for (int i = 0; i <= numPassengers-1; i++){
        printf("---------------------------------------------------\n");
        printf("Record number : %d\n", j);
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

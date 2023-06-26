#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Authentication.h"

#define MAX_PASSENGERS 10

//Flight information
typedef struct {
    char city[50];
    int passengers;
}domesticFlight;

domesticFlight domesticCountries[] = {
    {"Cape Town", 9},
    {"Durban", 4},
    {"Johannesburg", 5},
    {"Port Elizabeth", 10},
    {"East London", 7},
    {"George", 3}
};

//Passenger information
typedef struct {
    char name[50];
    int id;
    char phone[20];
    char origin[50];
    char destination[50];
} passengerData;

passengerData passenger;

            int numPassengers = 0;
            void createPassenger() {
            printf("Enter your name: ");
            scanf("%s", passenger.name);
            printf("Enter your ID number: ");
            scanf("%d", &passenger.id);
            printf("Enter your phone number: ");
            scanf("%s", passenger.phone);
            numPassengers++;
            }

            void displayPassengers(passengerData passengers[], int numPassengers) {
            for (int i = 0; i < numPassengers; i++) {
                printf("Passenger %d:\n", i + 1);
                printf("Name: %s\n", passengers[i].name);
                printf("ID: %d\n", passengers[i].id);
                printf("Phone number: %s\n", passengers[i].phone);
                printf("Origin: %s\n", passengers[i].origin);
                printf("Destination: %s\n", passengers[i].destination);
                printf("\n");
            }
            }
int domestic(){
system("cls");
    int choice;
    int lengthCountries = sizeof(domesticCountries)/sizeof(domesticCountries[0]);
        while (1) {
            //choose origin country
            printf("----Origin \nWhere from?----\n");
                int j = 1;
                for (int i = 0; i < lengthCountries; i++){
                    printf("%d. %s\n", j++, domesticCountries[i].city);
                }
                
                if (scanf("%d", &choice) != 1) { 
                    handleInvalidInput(lengthCountries);
                    continue;
                };

                if (choice >= 1 && choice <= lengthCountries) {
                    strcpy(passenger.origin, domesticCountries[choice-1].city);
                    system("cls");
                    printf("==== You chose origin: %s ====\n", passenger.origin);
                    break;
                } else {
                    system("cls");
                    printf("Invalid choice. Please try again.\n");
            };
        }
        start:
        while (1) {
            //choose destination country
            printf("----Destination \nWhere to?----\n");
                int j = 1;
                for (int i = 0; i < lengthCountries; i++){
                    printf("%d. %s\n", j++, domesticCountries[i].city);
                }
                
                if (scanf("%d", &choice) != 1) { 
                    handleInvalidInput(lengthCountries);
                    continue;
                };

                if (choice >= 1 && choice <= lengthCountries) {
                    char destination[50];
                    strcpy(passenger.destination, domesticCountries[choice-1].city);
                    system("cls");
                    printf("==== You chose destination : %s ====\n", passenger.destination);
                    break;
                } else {
                    system("cls");
                    printf("Invalid choice. Please try again.\n");
            };
        }
            //checkcs if there are seats available
        for (int i = 0; i < sizeof(domesticCountries) / sizeof(domesticCountries[0]); i++) {
            if (strcmp(passenger.destination, domesticCountries[i].city) == 0 && domesticCountries[i].passengers >= MAX_PASSENGERS) {
                system("cls");
                printf("Sorry, the flight to %s is fully booked please choose another destination\n", passenger.destination);
                goto start;
            }
        }
            system("cls");
            printf("There are seats available for the flight to %s\n", passenger.destination);
            printf("please enter your details to contine\n");

            //Collects passenger information

                createPassenger();

            //Prints reservation ticket information

                displayPassengers(passenger, numPassengers);

            printf("Please press enter to confirm...\n");
            int c;
            scanf(" %c", &c);
        
return 0;}
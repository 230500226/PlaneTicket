#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Authentication.h"
#include "Passenger.h"

#define MAX_PASSENGERS 3 //maximum passengers allowed on the flight to the destination
                            //yes its low buts its for test purposes can easily be adjusted as needed 

//Flight information

flightData domesticCities[] = {
    //simulated extra passengers for testing purposes
    {"Cape Town", 1},
    {"Durban", 2},
    {"Johannesburg", 3},
    {"Port Elizabeth", 0},
    {"East London", 1},
    {"George", 2}
};

//Passenger information
passengerData passengers[MAX_PASSENGERS];
   int numPassengers = 0;

int domestic(){
system("cls");
    int choice;
    char cDisplayPassengers;
    int lengthCity = sizeof(domesticCities)/sizeof(domesticCities[0]);
            //display all passenger information for domestic flights
        printf("----Do you want to view all passenger information?----\n");
        printf("Y for yes\n");
        printf("Or any key and enter to continue\n");
            scanf(" %c", &cDisplayPassengers);  //for some reason getchar gave me an error and scanf works just fine 
            cDisplayPassengers = toupper(cDisplayPassengers);
            if (cDisplayPassengers == 'Y'){
                displayAllPassengers(passengers, numPassengers);
            }
    
        origin:
        while (1) {
            //choose origin country
            //asuming that the origin country departure flight is always available for passengers(no limit)
            system("cls");
            originNoCls:
            printf("----Origin \nWhere from?----\n");
                int j = 1;
                for (int i = 0; i < lengthCity; i++){
                    printf("%d. %s\n", j++, domesticCities[i].city);
                }
                    //makes sure that the input is valid so that it doesn't loop 
                if (scanf("%d", &choice) != 1) { 
                    handleInvalidInput(lengthCity);
                    goto originNoCls;
                };
                    //checks that the choice is within the menu
                if (choice >= 1 && choice <= lengthCity) {
                    strcpy(passengers[numPassengers].origin, domesticCities[choice-1].city);
                    system("cls");
                    printf("==== You chose origin: %s ====\n", passengers[numPassengers].origin);
                    break;
                } else {
                    system("cls");
                    printf("Invalid choice number, please try again...\n");
                    goto originNoCls;
            };
        }
        destination:
        while (1) {
            //choose destination country
            printf("----Destination \nWhere to?----\n");
                int j = 1;
                for (int i = 0; i < lengthCity; i++){
                    printf("%d. %s\n", j++, domesticCities[i].city);
                }
                
                if (scanf("%d", &choice) != 1) { 
                    handleInvalidInput(lengthCity);
                    goto destination;
                };
                    //checks that the number is within the menu and checks that the origin is not the same as destination
                if (choice >= 1 && choice <= lengthCity) {

                    if(strcmp(passengers[numPassengers].origin, domesticCities[choice-1].city) != 0){
                        strcpy(passengers[numPassengers].destination, domesticCities[choice-1].city);
                        system("cls");
                        printf("==== You chose destination : %s ====\n", passengers[numPassengers].destination);
                        break;
                    } else {
                        system("cls");
                        printf("Your origin and destination location can't be the same please try again.\n");
                        goto origin;
                    }                    
                } else {
                    system("cls");
                    printf("Invalid choice number, please try again...\n");
                    goto destination;
            };
        }
            //checkcs if there are seats available for destination only
        for (int i = 0; i < sizeof(domesticCities) / sizeof(domesticCities[0]); i++) {
            if (strcmp(passengers[numPassengers].destination, domesticCities[i].city) == 0 && domesticCities[i].passengers >= MAX_PASSENGERS) {
                system("cls");
                printf("Sorry, the flight to %s is fully booked please choose another destination\n", passengers[numPassengers].destination);
                goto destination;
            }
        }
            system("cls");
            printf("There are seats available for the flight to %s\n", passengers[numPassengers].destination);
            printf("please enter your details to contine\n");

            //Collects passenger information
                //passes whole array to check for unique ID

                createPassenger(passengers, numPassengers);

            //Prints reservation ticket information

                displayPassenger(&passengers[numPassengers], numPassengers);

            //increments arrays for the next passenger reservation so that data is not overwritten
                for (int i = 0; i < (sizeof(domesticCities)/sizeof(domesticCities[0])); i++){
                    if (strcmp(passengers[numPassengers].destination, domesticCities[i].city) == 0){
                        domesticCities[i].passengers++;
                    }
                }
                numPassengers++;

            //confirmation for the passenger to view the ticket
            printf("Please press enter to confirm...\n");
            printf("Ready for next passenger...\n");
            getchar();
            getchar();
        
return 0;}
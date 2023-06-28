#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FlightType.h"
#include "Authentication.h"
#include "Passenger.h"

#define MAX_PASSENGERS 3 //maximum passengers allowed on the flight to the destination
                            //yes its low buts its for test purposes can easily be adjusted as needed 

//Flight information

flightData internationalCountries[] = {
    //simulated extra passengers for testing purposes
    {"France: Paris (CDG)", 1},
    {"Brazil: Brasília (BSB)", 2},
    {"Japan: Tokyo (HND)", 3},
    {"South Africa: Johannesburg (JNB)", 1},
    {"ECanada: Ottawa (YOW)", 0},
    {"Australia: Canberra (CBR)", 1},
    {"Italy: Rome (FCO)", 2},
    {"India: New Delhi (DEL)", 2}
};

//Passenger information
passengerData ipassengers[MAX_PASSENGERS];
   int inumPassengers = 0;

int international(){
system("cls");
    int choice;
    char cDisplayPassengers;
    int lengthCountries = sizeof(internationalCountries)/sizeof(internationalCountries[0]);
            //display all passenger information for domestic flights
        printf("----Do you want to view all passenger information?----\n");
        printf("Y for yes\n");
        printf("Or any key and enter to continue\n");
            scanf(" %c", &cDisplayPassengers);  //for some reason getchar gave me an error and scanf works just fine 
            cDisplayPassengers = toupper(cDisplayPassengers);
            if (cDisplayPassengers == 'Y'){
                displayAllPassengers(ipassengers, inumPassengers);
            }
    
        origin:
        while (1) {
            //choose origin country
            //asuming that the origin country departure flight is always available for i(no limit)
            system("cls");
            originNoCls:
            printf("----Origin \nWhere from?----\n");
                int j = 1;
                for (int i = 0; i < lengthCountries; i++){
                    printf("%d. %s\n", j++, internationalCountries[i].city);
                }
                printf("%d. Exit\n", j);
                    //makes sure that the input is valid so that it doesn't loop 
                if (scanf("%d", &choice) != 1) { 
                    handleInvalidInput(lengthCountries);
                    goto originNoCls;
                };
                    //checks that the choice is within the menu
                if (choice >= 1 && choice <= lengthCountries) {
                    strcpy(ipassengers[inumPassengers].origin, internationalCountries[choice-1].city);
                    system("cls");
                    printf("==== You chose origin: %s ====\n", ipassengers[inumPassengers].origin);
                    break;
                } else if (choice == j) {

                    goto exit;

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
                for (int i = 0; i < lengthCountries; i++){
                    printf("%d. %s\n", j++, internationalCountries[i].city);
                }
                printf("%d. Exit\n", j);
                
                if (scanf("%d", &choice) != 1) { 
                    handleInvalidInput(lengthCountries);
                    goto destination;
                };
                    //checks that the number is within the menu and checks that the origin is not the same as destination
                if (choice >= 1 && choice <= lengthCountries) {

                    if(strcmp(ipassengers[inumPassengers].origin, internationalCountries[choice-1].city) != 0){
                        strcpy(ipassengers[inumPassengers].destination, internationalCountries[choice-1].city);
                        system("cls");
                        printf("==== You chose destination : %s ====\n", ipassengers[inumPassengers].destination);
                        break;
                    } else {
                        system("cls");
                        printf("Your origin and destination location can't be the same please try again.\n");
                        goto origin;
                    }                    
                } else if (choice == j) {

                    goto exit;

                } else {
                    system("cls");
                    printf("Invalid choice number, please try again...\n");
                    goto destination;
            };
        }
            //checkcs if there are seats available for destination only
        for (int i = 0; i < sizeof(internationalCountries) / sizeof(internationalCountries[0]); i++) {
            if (strcmp(ipassengers[inumPassengers].destination, internationalCountries[i].city) == 0 && internationalCountries[i].passengers >= MAX_PASSENGERS) {
                system("cls");
                printf("Sorry, the flight to %s is fully booked please choose another destination\n", ipassengers[inumPassengers].destination);
                goto destination;
            }
        }
            system("cls");
            printf("There are seats available for the flight to %s\n", ipassengers[inumPassengers].destination);
            printf("please enter your details to contine\n");

            //Collects passenger information
                //passes whole array to check for unique ID

                createPassenger(ipassengers, inumPassengers);

            //Prints reservation ticket information

                displayPassenger(&ipassengers[inumPassengers], inumPassengers);

            //increments arrays for the next passenger reservation so that data is not overwritten
                for (int i = 0; i < (sizeof(internationalCountries)/sizeof(internationalCountries[0])); i++){
                    if (strcmp(ipassengers[inumPassengers].destination, internationalCountries[i].city) == 0){
                        internationalCountries[i].passengers++;
                    }
                }
                inumPassengers++;

            //confirmation for the passenger to view the ticket
            printf("Please press enter to confirm...\n");
            printf("Ready for next passenger...\n");
            getchar();
            getchar();
            exit:
        
return 0;}
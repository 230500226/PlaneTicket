/************* AUTHOR INFO **************/
// Name: Shahied Rustin
// Student No.: 230500226
// Course Title: Software Design 1 (SDN150S)
// Date: 30/06/2023
/************* HEADER FILES ***************/

/************* GLOBAL VARIABLES ************/

/******** FUNCTIONS (DECLARE/DEFINE) *********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Authentication.h"
#include "FlightType.h"
/************* MAIN FUNCTION**************/
int main() {
    int choice;
    while (1) {
        system("cls");
        start:
        printf("Welcome to SAA\nLet's Book a flight!\n");
        printf("\nWill your flight be\n1. Domestic\n2. International\n3. Exit\n");

        // Check if the user enters a non-integer value to avoid infinite looping
        if (scanf("%d", &choice) != 1) { 
            handleInvalidInput(3);
            goto start;
        }

        switch (choice) {
            case 1:
                printf("Domestic()\n");
                domestic(); // Call the function to book a domestic flight
                break;
            case 2:
                printf("International\n");
                international(); // Call the function to book an international flight
                break;
            case 3:
                exit(0); // Exit the program
            default:
                system("cls");
                printf("Invalid choice number, please try again...\n");
                goto start; // Restart the loop if an invalid choice is entered
        }
    }
    return 0;
}

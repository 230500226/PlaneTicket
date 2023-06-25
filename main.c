#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Authentication.h"
// #include "Passenger.h"

// #define MAX_PASSENGERS 100

// Passenger passengers[MAX_PASSENGERS];
// int num_passengers = 0;

// char *addPassenger() {
//     if (num_passengers == MAX_PASSENGERS) {
//         return "Maximum number of passengers reached.\n";
//     }
//     printf("Enter name: ");
//     scanf("%s", passengers[num_passengers].name);
//     if (!isUnique(passengers[num_passengers].name)) {
//         return "Passengername already exists.\n";
//     }
//     printf("Enter password: ");
//     scanf("%s", passengers[num_passengers].password);
//     if (!isValidPassword(passengers[num_passengers].password)) {
//         return "Password must be at least 8 characters long and contain at least 1 special character.\n";
//     }
//     printf("Enter age: ");
//     scanf("%d", &passengers[num_passengers].age);
//     num_passengers++;
//     return "Passenger added successfully.\n";
// }

// char *viewpassengers() {
//     static char result[1000];
//     strcpy(result, "");
//     for (int i = 0; i < num_passengers; i++) {
//         char temp[100];
//         sprintf(temp, "Passenger %d: %s, %d\n", i+1, passengers[i].name, passengers[i].age);
//         strcat(result, temp);
//     }
//     return result;
// }

int main() {
    int choice;
    while (1) {
        printf("Welcome to SAA\nLets Book a flight!\n");
        printf("\nWill your flight be\n1. Domestic\n2. International\n3. Exit\n");
            //had a problem with infinite looping when user eneters a non integer value
            if (scanf("%d", &choice) != 1) { 
                handleInvalidInput(3);
                continue;
            };
            switch (choice) {
                case 1:
                    printf("Domestic\n");
                    break;
                case 2:
                    printf("International\n");
                    break;
                case 3:
                    exit(0);
                default:
                    printf("Invalid choice.\n");
            };

        // printf("1. Add Passenger\n2. View Passengers\n3. Exit\nEnter choice: ");
        // if (scanf("%d", &choice) != 1) {
        //     printf("Invalid choice please enter a number 1, 2 or 3. \n");
        //     int c;
        //     while ((c = getchar()) != '\n' && c != EOF); // clear the input buffer (stops infinite looping when a non integer is encountered)
        //     continue;
        // };
        // switch (choice) {
        //     case 1:
        //         printf("%s", addPassenger());
        //         break;
        //     case 2:
        //         printf("%s", viewpassengers());
        //         break;
        //     case 3:
        //         exit(0);
        //     default:
        //         printf("Invalid choice.\n");
        // }
    }
    return 0;
}

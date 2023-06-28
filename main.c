#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Authentication.h"
#include "FlightType.h"

int main() {
    int choice;
    while (1) {
        system("cls");
        start:
        printf("Welcome to SAA\nLets Book a flight!\n");
        printf("\nWill your flight be\n1. Domestic\n2. International\n3. Exit\n");
            //had a problem with infinite looping when user eneters a non integer value
            if (scanf("%d", &choice) != 1) { 
                handleInvalidInput(3);
                goto start;
            };
            switch (choice) {
                case 1:
                    printf("Domestic()\n");
                    domestic();
                    break;
                case 2:
                    printf("International\n");
                    international();
                    break;
                case 3:
                    exit(0);
                default:
                    system("cls");
                    printf("Invalid choice number, please try again...\n");
                    goto start;
            };
    }
    return 0;
}

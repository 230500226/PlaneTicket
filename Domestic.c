#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Authentication.h"

char *domesticCountries[6] = {"Cape Town", "Durban", "Johannesburg", "Port Elizabeth", "East London", "George"};

int domestic(){

    int choice;
    while (1) {
        system("cls");
        printf("Origin \nWhere from?\n");
        int lengthCountries = sizeof(domesticCountries)/sizeof(domesticCountries[0]);
            for (int i = 0; i < lengthCountries; i++){
                printf("%d. %s\n", i, domesticCountries[i]);
            }
            
            //had a problem with infinite looping when user eneters a non integer value
            if (scanf("%d", &choice) != 1) { 
                handleInvalidInput(lengthCountries);
                continue;
            };

            if (choice >= 1 && choice <= lengthCountries) {
                printf("You chose: %s\n", domesticCountries[choice-1]);
                break;
            } else {
                printf("Invalid choice. Please try again.\n");
        };
    }
return 0;}
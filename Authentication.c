#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"

int isUnique(char *name) {
    for (int i = 0; i < num_passengers; i++) {
        if (strcmp(passengers[i].name, name) == 0) {
            return 0;
        }
    }
    return 1;
}

int isValidPassword(char *password) {
    if (strlen(password) < 8) {
        return 0;
    }
    int specialCharacter = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            specialCharacter = 1;
            break;
        }
    }
    return specialCharacter;
}
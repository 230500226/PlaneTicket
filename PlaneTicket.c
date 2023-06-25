#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100

typedef struct {
    char name[50];
    char password[50];
    int age;
} User;

User users[MAX_USERS];
int num_users = 0;

int isUnique(char *name) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
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

char* addUser() {
    if (num_users == MAX_USERS) {
        return "Maximum number of users reached.\n";
    }
    printf("Enter name: ");
    scanf("%s", users[num_users].name);
    if (!isUnique(users[num_users].name)) {
        return "Username already exists.\n";
    }
    printf("Enter password: ");
    scanf("%s", users[num_users].password);
    if (!isValidPassword(users[num_users].password)) {
        return "Password must be at least 8 characters long and contain at least 1 special character.\n";
    }
    printf("Enter age: ");
    scanf("%d", &users[num_users].age);
    num_users++;
    return "User added successfully.\n";
}

char* viewUsers() {
    static char result[1000];
    strcpy(result, "");
    for (int i = 0; i < num_users; i++) {
        char temp[100];
        sprintf(temp, "User %d: %s, %d\n", i+1, users[i].name, users[i].age);
        strcat(result, temp);
    }
    return result;
}

int main() {
    int choice;
    while (1) {
        printf("1. Add user\n2. View users\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("%s", addUser());
                break;
            case 2:
                printf("%s", viewUsers());
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

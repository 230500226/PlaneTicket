#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    char name[50];
    int age;
} User;

User users[MAX_USERS];
int num_users = 0;

char *add_user() {
    if (num_users == MAX_USERS) {
        return "Maximum number of users reached.\n";
    }
    printf("Enter name: ");
    scanf("%s", users[num_users].name);
    printf("Enter age: ");
    scanf("%d", &users[num_users].age);
    num_users++;
    return "User added successfully.\n";
}

char *view_users() {
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
                printf("%s", add_user());
                break;
            case 2:
                printf("%s", view_users());
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

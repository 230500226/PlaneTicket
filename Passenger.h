#ifndef PASSENGER_H
#define PASSENGER_H

typedef struct {
    char name[50];
    int id;
    char phone[20];
    char origin[50];
    char destination[50];
} passengerData;

//Spent a lot of time debugging the way the passenger data was modified between the c files eventually got it working tho😎

void displayPassenger(passengerData *passenger, int numPassengers);
void createPassenger(passengerData *passenger, int numPassengers);

#endif

#ifndef PASSENGER_H
#define PASSENGER_H

typedef struct {
    char name[50];
    int id;
    char phone[20];
    char origin[50];
    char destination[50];
} passengerData;

void displayPassenger(passengerData *passenger);
passengerData createPassenger();

#endif

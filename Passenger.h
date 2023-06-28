#ifndef PASSENGER_H
#define PASSENGER_H

typedef struct {
    char name[50];
    char *id; //ID was too long for type int eish that took a while to figure out
    int age;
    char phone[20];
    char origin[50];
    char destination[50];
} passengerData;


typedef struct {
    char city[50];
    int passengers;
}flightData;

//Spent a lot of time debugging the way the passenger data was modified between the c files eventually got it working tho😎 more iin readme pdf

void createPassenger(passengerData *passenger, int numPassengers);
void displayAllPassengers(passengerData *passenger, int numPassengers);
void displayPassenger(passengerData *passenger, int numPassengers);

#endif

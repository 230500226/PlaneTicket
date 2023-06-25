#ifndef PASSENGER_H
#define PASSENGER_H

#define MAX_PASSENGERS 100

typedef struct {    
    char name[50];
    char password[50];
    int age;
}   Passenger;

extern Passenger passengers[MAX_PASSENGERS];
extern int num_passengers;

#endif
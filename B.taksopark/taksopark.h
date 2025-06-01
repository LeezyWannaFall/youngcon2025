#ifndef TAKSOPARK_H_
#define TAKSOPARK_H_

// INCLUDES
#include <stdio.h>

// DEFINES
#define MAX_CARS_AND_FRIENDS 200000
#define MAX_PRICE 10000
#define MAX_VACATION 100000000

// STRUCTERS
typedef struct Friends {
    long long FirstVacationDay;
    long long LastVacationDay;
    int CarPrice;
} Friend;

// FUNCTIONS
int ScanfFriend(Friend *person, int NumberOfFriends);
void ProfitSort(Friend *person, int NumberOfFriends);
int MaxDayToWork(Friend *person, int NumberOfFriends);
int ProfitFunction(int NumberOfFriends, Friend *person, int NumberOfCars);

#endif    // TAKSOPARK_H_
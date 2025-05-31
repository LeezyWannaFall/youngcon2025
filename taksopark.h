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
    int FirstVacationDay;
    int LastVacationDay;
    int CarPrice;
} Friend;

//FUNCTIONS
void ScanfFriend(Friend *person, int NumberOfFriends);


#endif // TAKSOPARK_H_
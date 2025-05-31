#include "taksopark.h"

int main() {
    int NumberOfCars, NumberOfFriends;
    Friend person[MAX_CARS_AND_FRIENDS];

    scanf("%d", &NumberOfFriends);
    scanf("%d", &NumberOfCars);
    ScanfFriend(person, NumberOfFriends);
    
    printf("%d", NumberOfCars);
    printf("%d", NumberOfFriends);
}

void ScanfFriend(Friend *person, int NumberOfFriends) {
    for (int i = 0; i < NumberOfFriends; i++) {
        scanf("%d", &person[i].FirstVacationDay);
        scanf("%d", &person[i].LastVacationDay);
        scanf("%d", &person[i].CarPrice);
    }
}

// TO DO: EarnFunction 

// int EarnFunction(int NumberOfFriends, Friend *person) {
//     int DayCounter, DailyProfit, AllProfit = 0;
//     int MaxPersonProfit;

//     for (int i = 0; i < NumberOfFriends; i++) {
//         DayCounter++;
//         if (person[i].FirstVacationDay) {

//         }
//     }
// }
#include "taksopark.h"

int main() {
  int NumberOfCars, NumberOfFriends;
  Friend person[MAX_CARS_AND_FRIENDS];

  if (scanf("%d", &NumberOfFriends) != 1) {
    printf("%s\n", "Error: Invalid input");
    return 0;
  }

  if (scanf("%d", &NumberOfCars) != 1) {
    printf("%s\n", "Error: Invlaid input");
    return 0;
  }

  ScanfFriend(person, NumberOfFriends);
  printf("%d\n", ProfitFunction(NumberOfFriends, person, NumberOfCars));
}

int ScanfFriend(Friend *person, int NumberOfFriends) {
  for (int i = 0; i < NumberOfFriends; i++) {
    if (scanf("%lld", &person[i].FirstVacationDay) != 1) {
      printf("%s\n", "Error: Invalid input");
      return 0;
    }

    if (scanf("%lld", &person[i].LastVacationDay) != 1) {
      printf("%s\n", "Error: Invalid input");
      return 0;
    }

    if (scanf("%d", &person[i].CarPrice) != 1) {
      printf("%s\n", "Error: Invalid input");
      return 0;
    }
  }
}

void ProfitSort(Friend *person, int NumberOfFriends) {
  for (int i = 0; i < NumberOfFriends - 1; i++) {
    for (int j = 0; j < NumberOfFriends - i - 1; j++) {
      if (person[j].CarPrice < person[j + 1].CarPrice) {
        Friend temp = person[j];
        person[j] = person[j + 1];
        person[j + 1] = temp;
      }
    }
  }
}

int MaxDayToWork(Friend *person, int NumberOfFriends) {
  int MaxDayCounter = 0;

  for (int i = 0; i < NumberOfFriends; i++) {
    if (person[i].LastVacationDay > MaxDayCounter) {
      MaxDayCounter = person[i].LastVacationDay;
    }
  }

  return MaxDayCounter;
}

int ProfitFunction(int NumberOfFriends, Friend *person, int NumberOfCars) {
  int AllProfit = 0;
  int MaxDay = MaxDayToWork(person, NumberOfFriends);

  ProfitSort(person, NumberOfFriends);

  for (int DayCounter = 0; DayCounter < MaxDay + 1; DayCounter++) {
    int CarAvaliable = NumberOfCars;
    int DailyProfit = 0;
    for (int j = 0; j < NumberOfFriends && CarAvaliable != 0; j++) {
      if (person[j].FirstVacationDay <= DayCounter &&
          DayCounter <= person[j].LastVacationDay) {
        DailyProfit += person[j].CarPrice;
        CarAvaliable--;
      }
    }
    AllProfit += DailyProfit;
  }

  return AllProfit;
}

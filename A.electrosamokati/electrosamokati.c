#include <stdio.h>
#define MAX_HOUSES 100000
#define MAX_SECONDS 1000000

int ScanfSeconds(int NumberOfHouses, int SecondsToNextHouse[MAX_HOUSES]);
long long TimeToGetToWork(int NumberOfHouses,
                          int SecondsToNextHouse[MAX_HOUSES]);

int main() {
  int NumberOfHouses;
  int SecondsToNextHouse[MAX_HOUSES];

  if (scanf("%d", &NumberOfHouses) != 1) {
    printf("%s", "Error: ivalid input");
    return 0;
  }

  if (NumberOfHouses == 1) {
    printf("%d", 0);
    return 0;
  }

  if (ScanfSeconds(NumberOfHouses, SecondsToNextHouse) == 1) {
    printf("%s", "Error: ivalid input");
    return 0;
  }

  printf("%lld", TimeToGetToWork(NumberOfHouses, SecondsToNextHouse));
  return 0;
}

int ScanfSeconds(int NumberOfHouses, int SecondsToNextHouse[MAX_HOUSES]) {
  int flag = 0;

  for (int i = 0; i < NumberOfHouses; i++) {
    int temp;
    if (scanf("%d", &temp) != 1) {
      flag = 1;
    }
    SecondsToNextHouse[i] = temp;
  }

  return flag;
}

long long TimeToGetToWork(int NumberOfHouses,
                          int SecondsToNextHouse[MAX_HOUSES]) {
  long long SecondsCounter = 0;
  long long MinSeconds = MAX_SECONDS;

  for (int i = 0; i < NumberOfHouses - 1; i++) {
    if (SecondsToNextHouse[i] < MinSeconds) {
      MinSeconds = SecondsToNextHouse[i];
    }
    SecondsCounter += MinSeconds;
  }

  return SecondsCounter;
}
#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  int month = startAge;
  double money = initial;
  // working
  for (int i = 0; i < working.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", month / 12, month % 12, money);
    money = money + (working.rate_of_return * money) + working.contribution;
    month += 1;
  }

  // retired
  for (int i = 0; i < retired.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", month / 12, month % 12, money);
    money = money + (retired.rate_of_return * money) + retired.contribution;
    month += 1;
  }  
}

int main() {

  // Workingx
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;

  // Retired
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;

  //Starting
  int age = 327;
  double savings = 21345.0;

  retirement(age, savings, working, retired);

  return EXIT_SUCCESS;
}

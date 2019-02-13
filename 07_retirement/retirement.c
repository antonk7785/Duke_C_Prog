#include <stdio.h>
#include <stdlib.h>

struct _retire_info 
{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double balance_change(double balance, double rate_of_return, double contribution)
{
  double new_balance;
  double ret;
  ret = balance * rate_of_return;
  new_balance = balance + ret + contribution;
  
  return new_balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{

  double balance = initial;
  int age = startAge;
  
 
  while (age < startAge + working.months)
  {
    
    printf("Age %3d month %2d you have $%.2lf\n", age / 12, age % 12, balance);
    
    balance = balance_change(balance, working.rate_of_return, working.contribution);
  
    age++;
  }
  
  while (age < startAge + working.months + retired.months)
  {
    
    printf("Age %3d month %2d you have $%.2lf\n", age / 12, age % 12, balance);
    
    balance = balance_change(balance, retired.rate_of_return, retired.contribution);
  
    age++;
  }
}

int main(void)
{
  //workin data
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;
  
  //retired data
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;
  
  //initial conditions
  int init_age = 327;
  double balance = 21345;

  retirement(init_age, balance, working, retired);
  return 0;
}

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
  float change_due, change_in_cents;
  int number_of_coins = 0, number_of_cents;

  do {
    printf("How much change is owed? \n");
    change_due = GetFloat();
  } while (change_due < 0);

  if (change_due == 0)
  {
    printf("%d\n", number_of_coins);
  }
  else
  {
    change_in_cents = change_due * 100;
    double d = round(change_in_cents);
    number_of_cents = d;

    while (number_of_cents >= 25)
    {
      int coins = number_of_cents / 25;
      number_of_coins += coins;
      number_of_cents = number_of_cents % 25;
    }
    while (number_of_cents >= 10)
    {
      int coins = number_of_cents / 10;
      number_of_coins += coins;
      number_of_cents = number_of_cents % 10;
    }
    while (number_of_cents >= 5)
    {
      int coins = number_of_cents / 5;
      number_of_coins += coins;
      number_of_cents = number_of_cents % 5;
    }
    while (number_of_cents >= 1)
    {
      number_of_coins += number_of_cents;
      number_of_cents = 0;
    }
    printf("%d\n", number_of_coins);
  }
  return 0;
}

#include <cs50.h>
#include <stdio.h>

int calc_min_num_coins(int change);

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    int num_coins = calc_min_num_coins(change);
    printf("%i\n", num_coins);
}

int calc_min_num_coins(int change)
{
    int num_coins = 0;
    int remaining = change;

    const int quarter = 25;
    const int dime = 10;
    const int nickel = 5;
    const int penny = 1;

    while (remaining >= quarter)
    {
        remaining -= quarter;
        num_coins += 1;
    }

    while (remaining >= dime)
    {
        remaining -= dime;
        num_coins += 1;
    }

    while (remaining >= nickel)
    {
        remaining -= nickel;
        num_coins += 1;
    }

    while (remaining >= penny)
    {
        remaining -= penny;
        num_coins += 1;
    }

    return num_coins;
}

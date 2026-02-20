#include <cs50.h>
#include <math.h>
#include <stdio.h>

string get_card_type(long number);
bool is_valid(long number);
int get_sum_of_digits(int number);

int main(void)
{
    long number = get_long("Number: ");
    string card_type = get_card_type(number);
    printf("%s\n", card_type);
}

string get_card_type(long number)
{
    string card_type;
    bool number_is_valid = is_valid(number);
    if (number_is_valid)
    {
        int first_13_digit = number / pow(10, 12);
        int first_16_digit = number / pow(10, 15);
        int start_15_digit = number / pow(10, 13);
        int start_16_digit = number / pow(10, 14);
        if (start_15_digit == 34 || start_15_digit == 37)
        {
            card_type = "AMEX";
        }
        else if (start_16_digit >= 51 && start_16_digit <= 55)
        {
            card_type = "MASTERCARD";
        }
        else if (first_13_digit == 4 || first_16_digit == 4)
        {
            card_type = "VISA";
        }
        else
        {
            card_type = "INVALID";
        }
    }
    else
    {
        card_type = "INVALID";
    }
    return card_type;
}

bool is_valid(long number)
{
    long remaining = number;
    int sum = 0;
    int digit_counter = 0;
    while (remaining > 0)
    {
        int digit = remaining % 10;
        remaining = remaining / 10;
        // printf("%i\n", digit);
        if (digit_counter % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int value = get_sum_of_digits(2 * digit);
            sum += value;
        }
        digit_counter += 1;
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int get_sum_of_digits(int number)
{
    int sum = 0;
    int remaining = number;
    while (remaining > 0)
    {
        int digit = remaining % 10;
        remaining = remaining / 10;
        sum += digit;
    }
    return sum;
}

#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height, char symbol);
void print_row_for_pyramid(int width, int num_symbols, char symbol);
void print_characters(int num_characters, char character);

int main(void)
{
    const int height = get_height();
    const char symbol = '#';
    print_pyramid(height, symbol);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramid(int height, char symbol)
{
    for (int i = 0; i < height; i++)
    {
        int width = height;
        int num_symbols = i + 1;
        print_row_for_pyramid(width, num_symbols, symbol);
    }
}

void print_row_for_pyramid(int width, int num_symbols, char symbol)
{
    int num_spaces = width - num_symbols;
    int width_of_gap = 2;
    print_characters(num_spaces, ' ');
    print_characters(num_symbols, symbol);
    print_characters(width_of_gap, ' ');
    print_characters(num_symbols, symbol);
    printf("\n");
}

void print_characters(int num_characters, char character)
{
    for (int i = 0; i < num_characters; i++)
    {
        printf("%c", character);
    }
}

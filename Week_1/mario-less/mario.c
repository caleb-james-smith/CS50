#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_triangle_right_justify(int height, char symbol);
void print_triangle_left_justify(int height, char symbol);
void print_row_right_justify(int width, int num_symbols, char symbol);
void print_row_left_justify(int width, int num_symbols, char symbol);
void print_characters(int num_characters, char character);

int main(void)
{
    const int height = get_height();
    const char symbol = '#';
    print_triangle_right_justify(height, symbol);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);
    return height;
}

void print_triangle_right_justify(int height, char symbol)
{
    for (int i = 0; i < height; i++)
    {
        int width = height;
        int num_symbols = i + 1;
        print_row_right_justify(width, num_symbols, symbol);
    }
}

void print_triangle_left_justify(int height, char symbol)
{
    for (int i = 0; i < height; i++)
    {
        int width = height;
        int num_symbols = i + 1;
        print_row_left_justify(width, num_symbols, symbol);
    }
}

void print_row_right_justify(int width, int num_symbols, char symbol)
{
    int num_spaces = width - num_symbols;
    // Print spaces, then symbols
    print_characters(num_spaces, ' ');
    print_characters(num_symbols, symbol);
    printf("\n");
}

void print_row_left_justify(int width, int num_symbols, char symbol)
{
    int num_spaces = width - num_symbols;
    // Print symbols, then spaces
    print_characters(num_symbols, symbol);
    print_characters(num_spaces, ' ');
    printf("\n");
}

void print_characters(int num_characters, char character)
{
    for (int i = 0; i < num_characters; i++)
    {
        printf("%c", character);
    }
}

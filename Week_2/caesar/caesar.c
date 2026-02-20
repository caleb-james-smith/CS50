#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool contains_all_digits(string s);
void encrypt(string s, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: please provide exactly one argument.\n");
        return 1;
    }

    string program_name = argv[0];
    string key_string = argv[1];

    if (!contains_all_digits(key_string))
    {
        printf("Usage: %s key\n", program_name);
        return 1;
    }

    int key = atoi(key_string);
    printf("key: %i\n", key);

    string text = get_string("plaintext:  ");
    encrypt(text, key);
    printf("ciphertext: %s\n", text);
    return 0;
}

bool contains_all_digits(string s)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

void encrypt(string s, int key)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (isupper(s[i]))
        {
            int old_diff = s[i] - 'A';
            int new_diff = (old_diff + key) % 26;
            s[i] = 'A' + new_diff;
        }
        else if (islower(s[i]))
        {
            int old_diff = s[i] - 'a';
            int new_diff = (old_diff + key) % 26;
            s[i] = 'a' + new_diff;
        }
    }
}

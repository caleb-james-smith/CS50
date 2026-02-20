#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calc_score(string word, bool verbose);
void print_results(int score_1, int score_2, bool verbose);

int main(void)
{
    bool verbose = false;

    string word_1 = get_string("Player 1: ");
    string word_2 = get_string("Player 2: ");

    int score_1 = calc_score(word_1, verbose);
    int score_2 = calc_score(word_2, verbose);

    print_results(score_1, score_2, verbose);
}

int calc_score(string word, bool verbose)
{
    if (verbose)
    {
        printf("Calculating score for the word '%s'.\n", word);
    }
    int score = 0;
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        if (verbose)
        {
            printf("%c: ASCII = %i", word[i], word[i]);
        }
        if (isupper(word[i]))
        {
            int index = word[i] - 'A';
            if (verbose)
            {
                printf(", points = %i", points[index]);
            }
            score += points[index];
        }
        else if (islower(word[i]))
        {
            int index = word[i] - 'a';
            if (verbose)
            {
                printf(", points = %i", points[index]);
            }
            score += points[index];
        }
        if (verbose)
        {
            printf("\n");
        }
    }
    if (verbose)
    {
        printf("score = %i\n", score);
    }
    return score;
}

void print_results(int score_1, int score_2, bool verbose)
{
    if (verbose)
    {
        printf("Score 1: %i\n", score_1);
        printf("Score 2: %i\n", score_2);
    }

    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

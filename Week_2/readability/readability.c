#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void compute_word_count(string text, int *word_count, bool verbose);
float compute_coleman_liau_index(int *word_count, bool verbose);
void print_grade_level(float index, bool verbose);

int main(void)
{
    bool verbose = false;

    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int word_count[3];
    compute_word_count(text, word_count, verbose);

    // Compute the Coleman-Liau index
    float index = compute_coleman_liau_index(word_count, verbose);

    // Print the grade level
    print_grade_level(index, verbose);
}

void compute_word_count(string text, int *word_count, bool verbose)
{
    if (verbose)
    {
        printf("Computing word count:\n");
    }

    int num_letters     = 0;
    int num_words       = 0;
    int num_sentences   = 0;

    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        // Count uppercase and lowercase letters.
        if (isupper(text[i]) || islower(text[i]))
        {
            num_letters += 1;
        }
        else if (isspace(text[i]))
        {
            // Do not include the first or last character when counting whitespace.
            if (i != 0 && i != n - 1)
            {
                num_words += 1;
            }
        }
        // Check for terminating punctuation that indicates the end of a sentence.
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            num_sentences += 1;
        }
    }

    // Number of words should be one more than number of spaces
    num_words += 1;

    if (verbose)
    {
        printf(" - number of letters:   %i\n",  num_letters);
        printf(" - number of words:     %i\n",  num_words);
        printf(" - number of sentences: %i\n",  num_sentences);
    }

    // Store results in array
    word_count[0] = num_letters;
    word_count[1] = num_words;
    word_count[2] = num_sentences;
}

float compute_coleman_liau_index(int *word_count, bool verbose)
{
    if (verbose)
    {
        printf("Computing Coleman-Liau index:\n");
    }

    int num_letters     = word_count[0];
    int num_words       = word_count[1];
    int num_sentences   = word_count[2];

    // Important: cast integers to floats when dividing
    float letters_per_word = (float) num_letters / (float) num_words;
    float sentences_per_word = (float) num_sentences / (float) num_words;

    float letters_per_100_words = 100.0 * letters_per_word;
    float sentences_per_100_words = 100.0 * sentences_per_word;

    float index = 0.0588 * letters_per_100_words - 0.296 * sentences_per_100_words - 15.8;

    if (verbose)
    {
        printf(" - letters_per_word = %.2f\n", letters_per_word);
        printf(" - sentences_per_word = %.2f\n", sentences_per_word);
        printf(" - letters_per_100_words = %.2f\n", letters_per_100_words);
        printf(" - sentences_per_100_words = %.2f\n", sentences_per_100_words);
        printf(" - index = %.2f\n", index);
    }

    return index;
}

void print_grade_level(float index, bool verbose)
{
    int grade = (int) round(index);
    if (verbose)
    {
        printf("grade = %i\n", grade);
    }
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

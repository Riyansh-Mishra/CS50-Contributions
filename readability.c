#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string h);
int count_words(string h);
int count_sentences(string h);

int main(void)
{

    string text = get_string("Text: ");


    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);


    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;


    int index = round(0.0588 * L - 0.296 * S - 15.8);


    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string h)
{
    int no_letters = 0;
    for (int i = 0; i < strlen(h); i++)
    {
        if (isalpha(h[i]) != 0)
        {
            no_letters++;
        }
    }
    return no_letters;
}

int count_words(string h)
{
    int no_words = 1;
    for (int i = 0; i < strlen(h); i++)
    {
        if (h[i] == ' ')
        {
            no_words++;
        }
    }
    return no_words;
}

int count_sentences(string h)
{
    int no_sentences = 0;
    for (int i = 0; i < strlen(h); i++)
    {
        if (h[i] == '.' || h[i] == '!' || h[i] == '?')
        {
            no_sentences++;
        }
    }
    return no_sentences;
}

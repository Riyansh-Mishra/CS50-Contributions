#include <cs50.h>
#include <stdio.h>
#include <string.h>
int n = 0;
int calculate_scores(string hi);

int main(void)
{

    string player1 = get_string("Player 1: ");
    int c = calculate_scores(player1);
    string player2 = get_string("Player 2: ");
    int d = calculate_scores(player2);
    if (c > d)
    {
        printf("Player 1 wins!\n");
    }
    else if (c == d)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}
int calculate_scores(string hi)
{

    n = 0;
    int scrabble[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int a = 0; a < strlen(hi); a++)
    {
        if (hi[a] >= 'a' && hi[a] <= 'z')
        {
            int b = hi[a] - 97;
            n += scrabble[b];
        }
        else if (hi[a] >= 'A' && hi[a] <= 'Z')
        {
            int e = hi[a] - 65;
            n += scrabble[e];
        }
    }
    return n;
}

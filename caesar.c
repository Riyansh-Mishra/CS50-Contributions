#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, string argv[])
{
    // To ensure that the command line has 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // To ensure that the key only contains digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // To change the type from string to integer
    int a = atoi(argv[1]);

    // To input the text that has to be encrypted from the user
    string plaintext = get_string("Plain text: ");

    printf("Ciphertext: ");

    // To cipher the text
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + a) % 26 + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + a) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}

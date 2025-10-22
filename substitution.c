#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // To check whether the command line has two arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // To check that the key contains 26 alphabetical letters
    else if (strlen(argv[1]) != 26)
    {
        printf("The key should have 26 alphabetical letters\n");
        return 1;
    }
    // To check that the key contains alphabetical letters only
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("The key should have alphabetical letters only.\n");
            return 1;
        }

        int count = 1;
        // To check that the key doesn't contain duplicate letters
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            int y = argv[1][i]; 
            int z = argv[1][j];
            if (argv[1][i] == argv[1][j] && argv[1][i] != ' ') // To handle same case duplicate letters
            {
                count++;
            }
            else if (y == z - 32 || y - 32 == z) // To handle single mixed case duplicate letters
            {
                count++;
            }
        }
        if (count > 1)
        {
            printf("The keys should have distinct alphabets.\n");
            return 1;
        }
    }
    // To get string from the user
    string plaintext = get_string("Plain text: ");
    // To print the cipher text
    printf("ciphertext: ");
    // To cipher the text
    for (int a = 0; a < strlen(plaintext); a++)
    {
        if (isupper(plaintext[a]))
        {
            int b = plaintext[a] - 65;
            printf("%c", toupper(argv[1][b]));
        }
        else if (islower(plaintext[a]))
        {
            int c = plaintext[a] - 97;
            printf("%c", tolower(argv[1][c]));
        }
        else
        {
            printf("%c", plaintext[a]);
        }
    }
    printf("\n");
    return 0;
}

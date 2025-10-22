#include <cs50.h>
#include <stdio.h>
int n;

int main(void)
{
    do
    {
        n = get_int("Enter the amount of rows:");
    }
    while (n < 1);
    for (int rows = 0; rows < n; rows++)
    {
        for (int space = 0; space < n - rows - 1; space++)
        {
            printf(" ");
        }
        for (int hash = 0; hash <= rows; hash++)
        {
            printf("#");
        }
        printf(" ");
        for (int hash = 0; hash <= rows; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}

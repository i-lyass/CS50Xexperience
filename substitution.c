#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int G = 0;
    int d = 0;
    if (argc > 2)
    {
        return 1;
    }
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (argc == 2)
    {
        for (int j = 0, b = strlen(argv[1]); j < b; j++)
        {
            if (isdigit(argv[1][j]))
            {
                d++;
            }
            if (argv[1][j] == argv[1][j - 1])
            {
                G++;
            }

        }
    }
    if (argc == 2 && d != 0)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("key must contain 26 characters.\n");
        return 1;
    }
    if (d != 0 && G > 0)
    {
        printf("key must contain 26 characters.\n");
        return 1;
    }
    if (argc == 2 && strlen(argv[1]) == 26 && G == 0)
    {
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");
        for (int i = 0, a = strlen(plaintext); i < a; i++)
        {
            if (islower(plaintext[i]))
            {
                printf("%c", tolower(argv[1][plaintext[i] - 97]));
            }
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(argv[1][plaintext[i] - 65]));
            }
            if (isalpha(plaintext[i]) == 0)
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
    if (G > 0)
    {
        return 1;
    }
}

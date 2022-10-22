#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height;
    do
    {
        Height = get_int("Height: ");
    }
    while (Height < 1 || Height > 8);
    for (int row = 0; 1row < Height; row++)

    {
        for (int vide = 0; vide < Height - row - 1; vide++)
        {
            printf(" ");
        }
        for (int HASH = 0; HASH <= row; HASH++)
        {
            printf("#");
        }
        printf("  ");
        for (int HASHl = 0; HASHl <= row; HASHl++)
        {
            printf("#");
        }
        printf("\n");
    }

}

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int save;
int idk ;
int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //printf("score1 = %i \n", score1);
    //printf("score2 = %i \n", score2);
    if (score1 == score2)
    {
        printf("Tie! \n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins! \n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins! \n");
    }
}


int compute_score(string word)
{
    save = 0;
    idk = 0;
    for (int i = 0, a = strlen(word); i < a; i++)
    {
        if (isupper(word[i]))
        {
            save = word[i] - 65;
            idk = idk + POINTS[save];
        }
        if (islower(word[i]))
        {
            save = word[i] - 97;
            idk = idk + POINTS[save];
        }
        else
        {
            idk = idk + 0;
        }
    }
    return idk;
}

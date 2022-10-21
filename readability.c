#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    float words = 0.0;
    float letter = 0.0;
    float sentences = 0.0;
    string input = get_string("TEXT : ");

    for (int i = 0, A = strlen(input); i <= A; i++)
    {
        if (input[i] == '!' || input[i] == '?' || input[i] == '.')
        {
            sentences++;
        }
        if (input[i] == ' ' || input[i] == '\0')
        {
            words++;
        }
        if (islower(input[i]) || isupper(input[i]))
        {
            letter++;
        }
    }
    float L = letter / words * 100.0;
    float S = sentences / words * 100.0;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    //printf("L %f \n",L);
    //printf("S %f \n",S);
    //printf("Grade %f \n",round(index));
    //printf("words %f \n",words);
    //printf("letter %f \n",letter);
    //printf("sentences %f \n",sentences);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %g\n", round(index));
    }
}

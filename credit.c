#include <cs50.h>
#include <stdio.h>
#include <string.h>

// AMERICAN EXPRESS START 34 37 **15 digit
// MASTERCARD START 51 52 53 54 55 **16 digit**
// VISA start 4     **13 digit || 16 digits**
// CREDIT CARD
// output AMEX\n MASTERCARD\n VISA\n INVALID\N 4003600000000014
// if u understand this code i will go out naked
int main(void)
{
    int save = 0;
    int saver = 0;
    int t, l, i;
    int sum[20];
    int sam[20];
    int D = 0;
    string creditcard = get_string("Number : ");
    int n = strlen(creditcard);
    for (i = 0; i < n; i++)
    {
        if ((creditcard[i] < 47) & (creditcard[i] > 58))
        {
            printf("INVALID\n");
            return 0;
        }
    }

    if (n == 15 || n == 16 || n == 13)
    {
        for (i = n - 2, t = 0; i >= 0; i = i - 2)
        {
            int V = creditcard[i] - 48;
            sum[t] = V * 2;
            t++;
        }
        for (i = n - 1, l = 0; i >= 0; i = i - 2)
        {
            int e = creditcard[i] - 48;
            sam[l] = e;
            l++;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
    for (i = 0; i <= t + 2; i++)
    {
        if (sum[i] <= 9)
        {
            save = save + sum[i];
        }
        if (sum[i] > 9)
        {
            save = save + 1;
            save = save + sum[i] % 10;
        }
    }
    //printf("%i\n", save);
    for (i = 0; i <= l + 2; i++)
    {
        saver = saver + sam[i];
    }
    //printf("%i\n", saver);
    int FINALLY = save + saver;
    int done = FINALLY % 10;


    if (done < 1)
    {
        if (creditcard[0] == 52)
        {
            printf("VISA\n");
            return 0;
        }
        if (creditcard[0] == 51 && (creditcard[1] == 52 || creditcard[1] == 55))
        {
            printf("AMEX\n");
            return 0;
        }
        if (creditcard[0] == 53 & creditcard[1] <= 53)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

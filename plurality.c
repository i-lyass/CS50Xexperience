#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;
int voter_count;
int F;
int MX;
// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        F = 9;
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

    }

    print_winner();
}

bool vote(string name)
{
    F = 9;
    for (int j = 0; j < candidate_count; j++)
    {
        if (!strcmp(candidates[j].name, name))
        {
            candidates[j].votes++;
            F--;
        }
    }
    if (F == 9)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    MX = 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (MX <= candidates[i].votes)
        {
            MX = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == MX)
        {
            printf("%s", candidates[i].name);
            printf("\n");
        }
    }
    return ;
}

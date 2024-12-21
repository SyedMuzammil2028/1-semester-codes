#include <stdio.h>
#include <string.h>

struct Player
{
    char name[50];
    int runs;
    int matchesPlayed;
};
void readDataFromFile(struct Player players[], int *n)
{
    FILE *file = fopen("players.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%s %d %d", players[*n].name, &players[*n].runs, &players[*n].matchesPlayed) != EOF)
    {
        (*n)++;
    }

    fclose(file);
}
void calculateAverageRuns(struct Player players[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Player: %s, Average Runs: %.2f\n", players[i].name, (float)players[i].runs / players[i].matchesPlayed);
    }
}
void findTopPerformer(struct Player players[], int n)
{
    int bestPlayerIndex = 0;
    float highestRatio = (float)players[0].runs / players[0].matchesPlayed;

    for (int i = 1; i < n; i++)
    {
        float ratio = (float)players[i].runs / players[i].matchesPlayed;
        if (ratio > highestRatio)
        {
            highestRatio = ratio;
            bestPlayerIndex = i;
        }
    }
    printf("Player with highest runs-to-matches ratio: %s with a ratio of %.2f\n",
           players[bestPlayerIndex].name, highestRatio);
}
int main()
{
    struct Player players[50];
    int n = 0;
    readDataFromFile(players, &n);
    calculateAverageRuns(players, n);
    findTopPerformer(players, n);

    return 0;
}

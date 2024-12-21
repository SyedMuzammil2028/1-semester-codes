#include <stdio.h>

typedef struct Player
{
    int ballScore[12];
    char playerName[15];
    int totalScore;
} player;

int validScore(int score)
{
    if (score >= 0 && score <= 6)
    {
        return 1;
    }
    else
        return 0;
}

void playGame(player *p)
{
    printf("Enter the Player's name:\n");
    scanf(" %[^\n]", (*p).playerName);
    (*p).totalScore = 0;
    for (int i = 0; i < 12; i++)
    {
        int score = 0;
        printf("Enter score for ball %d (Between 0-6): ", i + 1);
        scanf("%d", &score);

        if (validScore(score))
        {
            (*p).ballScore[i] = score;
            (*p).totalScore += (*p).ballScore[i];
        }

        else
        {
            printf("Invalid score! But ball added!\n");
            (*p).ballScore[i] = 0;
        }
    }
}

void findWinner(player *p1, player *p2)
{
    if (((*p1).totalScore) > ((*p2).totalScore))
    {
        printf("%s is the Winner!\nTotal Score: %d", (*p1).playerName, (*p1).totalScore);
    }
    else if (((*p1).totalScore) < ((*p2).totalScore))
    {
        printf("%s is the Winner!\nTotal Score: %d", (*p2).playerName, (*p2).totalScore);
    }
    else
    {
        printf("The Match is tied with score %d: ", (*p1).totalScore);
    }
}

void displayMatchScoreboard(player *p1, player *p2)
{

    printf("\n\t\t\t\t\t Final Score Board:\n");

    printf("Player 1 %s :\n", (*p1).playerName);
    printf("Scores for 12 balls:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", (*p1).ballScore[i]);
    }
    printf("\nAverage Score: %.3f\n", (float)((*p1).totalScore) / 12);
    printf("Total Score: %d\n\n", (*p1).totalScore);

    printf("Player 2 %s :\n", (*p2).playerName);
    printf("Scores for 12 balls:\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", (*p2).ballScore[i]);
    }
    printf("\nAverage Score: %.3f\n", (float)((*p2).totalScore) / 12);
    printf("Total Score: %d\n", (*p2).totalScore);
}

int main()
{
    player p1, p2;
    printf("First Player's Turn: \n");
    playGame(&p1);

    printf("Second Player's Turn: \n");
    playGame(&p2);

    displayMatchScoreboard(&p1, &p2);

    findWinner(&p1, &p2);

    return 0;
}
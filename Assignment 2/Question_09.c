#include <stdio.h>
#define SIZE 5

void displayGrid(char grid[SIZE][SIZE]);
void movePlayer(char grid[SIZE][SIZE], int playerX, int playerY, char direction, int *newPlayerX, int *newPlayerY, int *itemsCollected);

int main()
{
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}};

    int playerX = 4, playerY = 4;
    int itemsCollected = 0;
    char direction;

    printf("Welcome to the Grid Adventure Game!\n");
    printf("Controls: W (up), S (down), A (left), D (right), Q (quit)\n\n");

    while (1)
{
        displayGrid(grid);

        printf("Items collected: %d\n", itemsCollected);
        printf("Enter your move (W, A, S, D) or Q to quit: ");
        scanf(" %c", &direction);

        if (direction == 'Q' || direction == 'q')
        {
            printf("Thanks for playing!\n");
            break;
        }

        int newPlayerX = playerX, newPlayerY = playerY;
        movePlayer(grid, playerX, playerY, direction, &newPlayerX, &newPlayerY, &itemsCollected);

        if (newPlayerX != playerX || newPlayerY != playerY)
        {
            grid[playerX][playerY] = ' ';
            grid[newPlayerX][newPlayerY] = 'P';
            playerX = newPlayerX;
            playerY = newPlayerY;
        }
    }

    return 0;
}

void displayGrid(char grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void movePlayer(char grid[SIZE][SIZE], int playerX, int playerY, char direction, int *newPlayerX, int *newPlayerY, int *itemsCollected)
{
    int tempX = playerX, tempY = playerY;

    switch (direction)
    {
    case 'W':
    case 'w':
        tempX--;
        break;
    case 'S':
    case 's':
        tempX++;
        break;
    case 'A':
    case 'a':
        tempY--;
        break;
    case 'D':
    case 'd':
        tempY++;
        break;
    default:
        printf("Invalid input! Use W, A, S, D to move, or Q to quit.\n");
        return;
    }

    if (tempX < 0 || tempX >= SIZE || tempY < 0 || tempY >= SIZE)
    {
        printf("You can't move outside the grid!\n");
        return;
    }

    if (grid[tempX][tempY] == 'X')
    {
        printf("You can't move into an obstacle!\n");
        return;
    }

    if (grid[tempX][tempY] == 'I')
    {
        printf("You collected an item!\n");
        (*itemsCollected)++;
    }

    *newPlayerX = tempX;
    *newPlayerY = tempY;
}

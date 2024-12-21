#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 6
#define COLS 5

void populateGrid(char grid[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 'A' + (rand() % 26); 
        }
    }
}

void displayGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int searchInGrid(char grid[ROWS][COLS], const char *str) {
    int len = strlen(str);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j + len <= COLS && strncmp(&grid[i][j], str, len) == 0) return 1;
            int found = 1;
            for (int k = 0; k < len && found; k++) {
                if (i + k >= ROWS || grid[i + k][j] != str[k]) found = 0;
            }
            if (found) return 1;
        }
    }
    return 0;
}

int main() {
    char grid[ROWS][COLS];
    char searchStr[50];
    int score = 0;

    while (1) {
        populateGrid(grid);
        displayGrid(grid);

        printf("Enter the string to search (or 'END' to quit): ");
        scanf("%s", searchStr);

        if (strcmp(searchStr, "END") == 0) break;

        if (searchInGrid(grid, searchStr)) {
            score++;
            printf("%s is present. Score: %d\n", searchStr, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", searchStr, score);
        }
    }

    return 0;
}

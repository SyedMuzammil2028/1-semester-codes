#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 6
#define COLS 5

int main() {
    char array[ROWS][COLS];
    int score = 0;
    char search_str[20];

    // Seed the random number generator
    srand(time(NULL));

    // Populate the array with random characters and last row with student ID
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS - 1) {
                // Last row with student ID (replace with your actual ID)
                array[i][j] = '0' + rand() % 10;
            } else {
                array[i][j] = 'A' + rand() % 26;
            }
        }
    }

    while (1) {
        // Print the array in tabular form
        printf("\nArray:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c ", array[i][j]);
            }
            printf("\n");
        }

        // Get the search string
        printf("Enter search string (or 'END' to quit): ");
        scanf("%s", search_str);

        if (strcmp(search_str, "END") == 0) {
            break;
        }

        // Search for the string in the array
        int found = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int k = 0;
                while (array[i][j] == search_str[k] && k < strlen(search_str)) {
                    j++;
                    k++;
                }
                if (k == strlen(search_str)) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        // Update the score
        if (found) {
            score++;
            printf("%s is present. Score: %d\n", search_str, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", search_str, score);
        }

        // Re-populate the array with new random characters
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == ROWS - 1) {
                    // Last row with student ID
                    array[i][j] = '0' + rand() % 10;
                } else {
                    array[i][j] = 'A' + rand() % 26;
                }
            }
        }
    }

    return 0;
}
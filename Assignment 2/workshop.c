#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 6
#define COLS 5

// Function to generate a random lowercase letter
char randomLetter() {
    return 'a' + rand() % 26;
}

// Function to populate the 2D array with random letters
void populateArray(char array[ROWS][COLS]) {
    for (int i = 0; i < ROWS - 1; i++) { // Fill all but the last row
        for (int j = 0; j < COLS; j++) {
            array[i][j] = randomLetter();
        }
    }
    // Set the last row to the last four digits of your student ID
    // Replace "1234" with your actual student ID last four digits
    char student_id[] = "2000"; // Example student ID
    for (int j = 0; j < COLS; j++) {
        if (j < strlen(student_id)) {
            array[ROWS - 1][j] = student_id[j];
        } else {
            array[ROWS - 1][j] = randomLetter(); // Fill remaining with random letters
        }
    }
}

// Function to print the 2D array in tabular form
void printArray(char array[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

// Function to search for a string in the 2D array
int searchString(char array[ROWS][COLS], char *str) {
    int score = 0;
    int strLen = strlen(str);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Check if the string starts at the current position
            if (array[i][j] == str[0]) {
                int k;
                // Check if all characters of the string match
                for (k = 1; k < strLen; k++) {
                    if (j + k < COLS && array[i][j + k] == str[k]) {
                        continue;
                    } else {
                        break;
                    }
                }

                // If all characters match, string is found
                if (k == strLen) {
                    return 1; // String found
                }
            }
        }
    }

    // String not found
    return 0;
}

int main() {
    char array[ROWS][COLS];
    char input[100];
    int score = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Populate and print the array
    populateArray(array);
    printArray(array);

    // Start the loop for user input
    while (1) {
        printf("Enter a string (or 'END' to exit): ");
        scanf("%s", input);

        // Check if the user wants to exit
        if (strcmp(input, "END") == 0) {
            // Re-populate the array with new random letters
            populateArray(array);
            printArray(array);
            continue; // Restart the loop
        }

        // Search for the string in the array
        if (searchString(array, input)) {
            score++;
            printf("String found! Current score: %d\n", score);
        } else {
            score--;
            printf("String not found! Current score: %d\n", score);
        }
    }

    return 0;
}
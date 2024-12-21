#include <stdio.h>
#include <string.h>

int main() {
    int height, age;
    char ride[100];
    
    printf("\nAmusement Park Ride eligibility");
    printf("\n-------------------------------");

    printf("Enter your height in inches: ");
    scanf("%d", &height);

    printf("Enter your age in years: ");
    scanf("%d", &age);

    // Clear the input buffer before taking the ride input
    getchar(); // This removes the newline character left in the buffer

    printf("Enter the ride name (The Dragon Roller Coaster, The Sky Swing, The Carousel): ");
    fgets(ride, sizeof(ride), stdin); // Read input including spaces
    ride[strcspn(ride, "\n")] = 0; // Remove the newline character from the input

    // Check if the visitor meets the criteria for The Dragon Roller Coaster
    if (strcmp(ride, "The Dragon Roller Coaster") == 0) {
        if (height >= 48 && age >= 10) {
            printf("You meet the criteria for The Dragon Roller Coaster.\n");
        } else {
            printf("Sorry, you do not meet the criteria for The Dragon Roller Coaster.\n");
        }
    }
    // Check if the visitor meets the criteria for The Sky Swing
    else if (strcmp(ride, "The Sky Swing") == 0) {
        if (height >= 54) {
            printf("You meet the criteria for The Sky Swing.\n");
        } else {
            printf("Sorry, you do not meet the criteria for The Sky Swing.\n");
        }
    }
    // Check if the visitor meets the criteria for The Carousel
    else if (strcmp(ride, "The Carousel") == 0) {
        if (age >= 5) {
            printf("You meet the criteria for The Carousel.\n");
        } else {
            printf("Sorry, you do not meet the criteria for The Carousel.\n");
        }
    } else {
        printf("Invalid ride name entered.\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int height, age;
    char ride;
    int band;

    printf("\nAmusement Park Ride eligibility");
    printf("\n-------------------------------\n");

    printf("Enter your height in inches: ");
    scanf("%d", &height);

    printf("Enter your age in years: ");
    scanf("%d", &age);

    printf("Enter Band (1 for yes, 0 for no): ");
    scanf("%d", &band);

    // Clear the input buffer before taking the ride input
    getchar(); // This removes the newline character left in the buffer
    printf("\nThe Dragon Roller Coaster --> 1\nThe Sky Swing --> 2\nThe Carousel --> 3");
    printf("\nEnter ride number: ");
    scanf("%c", &ride);

    // Check if the visitor meets the criteria for The Dragon Roller Coaster
    if (ride=='1') {
        if (height >= 48 && age >= 10) {
            printf("\nYou meet the criteria for The Dragon Roller Coaster.\n");
          if (band==1){
              printf("\nUnlimited The Dragon Roller Coaster ride for you");}
        } else {
            printf("\nSorry, you do not meet the criteria for The Dragon Roller Coaster.\n");
        }
    }
    // Check if the visitor meets the criteria for The Sky Swing
    else if (ride=='2') {
        if (height >= 54) {
            printf("\nYou meet the criteria for The Sky Swing.\n");
          if (band==1){
              printf("\nUnlimited The Sky Swing ride for you");}
        } else {
            printf("\nSorry, you do not meet the criteria for The Sky Swing.\n");
        }
    }
    // Check if the visitor meets the criteria for The Carousel
    else if (ride=='3') {
        if (age >= 5) {
            printf("\nYou meet the criteria for The Carousel.\n");
          if (band==1){
              printf("\nUnlimited The Carousel ride for you");}
        } else {
            printf("\nSorry, you do not meet the criteria for The Carousel.\n");
        }
    } else {
        printf("\nInvalid ride name entered.\n");
    }

    return 0;
}

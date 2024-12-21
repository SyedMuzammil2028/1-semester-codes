#include <stdio.h>
// A weather station records temperature in an array over the course of a week (7 days). Write a 
// program that calculates the average temperature of the week and identifies if any days had 
// extreme temperatures (above 40°C or below 0°C).
// Example Input: {25, 30, -2, 35, 42, 28, 10}
// Example Output: Average temperature: 24.0°C, Extreme temperatures on day 3 and day 5
int main() {
    int temperatures[7];
    int sum = 0;
    int extremeDays[7];
    int count = 0;

    // Input temperatures for each day
    printf("Enter temperatures for 7 days:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1);
        scanf("%d", &temperatures[i]);
        sum += temperatures[i];

        // Check for extreme temperatures (above 40°C or below 0°C)
        if (temperatures[i] > 40 || temperatures[i] < 0) {
            extremeDays[count] = i + 1; // Store the day number
            count++;
        }
    }

    // Calculate the average temperature
    float average = sum / 7.0;

    // Output average temperature
    printf("\nAverage temperature: %.1f C\n", average);

    // Output days with extreme temperatures
    if (count > 0) {
        printf("Extreme temperatures on day ");
        for (int i = 0; i < count; i++) {
            printf("%d", extremeDays[i]);
            if (i < count - 1) {
                printf(" and ");
            }
        }
        printf("\n");
    } else {
        printf("No extreme temperatures recorded.\n");
    }

    return 0;
}

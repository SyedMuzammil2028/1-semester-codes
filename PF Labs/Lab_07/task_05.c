#include<stdio.h>
// program that calculates the average temperature of the week
// and identifies if any days had extreme temperatures
int main() {
    int i, tempsum = 0;
    int temperatures[7];
    int moreExtremeDays=0;

    // input the temperature for each day
    printf("Enter temperature of 7 days\n");
    for ( i = 0; i < 7; i++){
        printf("Day %d: ", i + 1);
        scanf("%d", &temperatures[i]);
        tempsum += temperatures[i];
    }
    // calculate the average temperature
    float avgtemp = tempsum / 7;
    printf("\nAverage temperature: %.1f C\n", avgtemp);

    printf("Extreme temperatures on ");
    // check for extreme temperature
    for (int j = 0; j < 7; j++){
        if (temperatures[j] > 40 || temperatures[j] < 0){
            if(moreExtremeDays != 0){
                printf("and ");
                }
            printf("day %d ", j + 1);
            moreExtremeDays = 1;
            }
        }
        // Check if no extreme days were found
        if (moreExtremeDays == 0){
             printf("No extreme temperatures recorded.\n");
        }
    return 0; 
    }

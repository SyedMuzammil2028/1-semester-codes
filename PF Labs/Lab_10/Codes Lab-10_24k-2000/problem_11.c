#include <stdio.h>
//  C program that defines a constant for the conversion factor of meters to kilometers
#define M_TO_KM 0.001
void convertToKilometers(float meters){
    static int callCount = 0;
    callCount++;
    float kilometers = meters * M_TO_KM;
    printf("Meters: %.2f, Kilometers: %.3f (Function called %d times)\n", meters, kilometers, callCount);
}
int main(){
    int choice;
    float meters;
    do{
        printf("\nConversion Menu:\n");
        printf("1. Convert meters to kilometers\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter distance in meters: ");
            scanf("%f", &meters);
            convertToKilometers(meters);
            break;
        case 2:
            printf("Exiting the program. Thank you!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);
    return 0;
}

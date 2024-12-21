#include <stdio.h>
// Function to determine if irrigation should be initiated
int main() {
    char crop_type;
    float soil_moisture;
    int rainfall_status;

    printf("\n\t\tCrop management");
    printf("\n\nEnter the crop type (W for wheat, C for corn, R for rice): ");
    scanf(" %c", &crop_type);

    printf("Enter the soil moisture level (in %%): ");
    scanf("%f", &soil_moisture);

    printf("Has it rained in the last 24 hours? (1 for yes, 0 for no): ");
    scanf("%d", &rainfall_status);

switch (crop_type) {
        case 'W': // Wheat
            if (soil_moisture < 30 && !rainfall_status) {
                printf("Irrigation should be initiated for wheat.\n");
            } else {
                printf("No irrigation needed for wheat.\n");
            }
            break;
        case 'C': // Corn
            if (soil_moisture < 40) {
                printf("Irrigation should be initiated for corn.\n");
            } else {
                printf("No irrigation needed for corn.\n");
            }
            break;
        case 'R': // Rice
            if (soil_moisture < 25 && !rainfall_status) {
                printf("Irrigation should be initiated for rice.\n");
            } else {
                printf("No irrigation needed for rice.\n");
            }
            break;
        default:
            printf("Invalid crop type.\n");
            break;
    }
}
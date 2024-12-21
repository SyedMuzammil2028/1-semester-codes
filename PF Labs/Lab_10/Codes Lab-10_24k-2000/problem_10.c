#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100

struct TravelPackage {
    char packageName[50];
    char destination[50];
    int duration;
    float cost;
    int seatsAvailable;
};

// Function to add a travel package
int addPackage(struct TravelPackage packages[], int packageCount) {
    if (packageCount >= MAX_PACKAGES) {
        printf("Cannot add more packages. Maximum limit reached.\n");
        return packageCount;
    }

    printf("Enter package name: ");
    scanf(" %[^\n]", packages[packageCount].packageName);

    printf("Enter destination: ");
    scanf(" %[^\n]", packages[packageCount].destination);

    printf("Enter duration (in days): ");
    scanf("%d", &packages[packageCount].duration);

    printf("Enter cost (in USD): ");
    scanf("%f", &packages[packageCount].cost);

    printf("Enter number of seats available: ");
    scanf("%d", &packages[packageCount].seatsAvailable);

    printf("Package added successfully!\n");
    return packageCount + 1;
}

// Function to display all available travel packages
void displayPackages(struct TravelPackage packages[], int packageCount) {
    if (packageCount == 0) {
        printf("No packages available.\n");
        return;
    }

    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < packageCount; i++) {
        printf("Package %d:\n", i + 1);
        printf("  Name: %s\n", packages[i].packageName);
        printf("  Destination: %s\n", packages[i].destination);
        printf("  Duration: %d days\n", packages[i].duration);
        printf("  Cost: $%.2f\n", packages[i].cost);
        printf("  Seats Available: %d\n", packages[i].seatsAvailable);
        printf("-------------------------\n");
    }
}

// Function to book a travel package
void bookPackage(struct TravelPackage packages[], int packageCount) {
    if (packageCount == 0) {
        printf("No packages available to book.\n");
        return;
    }

    char packageName[50];
    printf("Enter the name of the package to book: ");
    scanf(" %[^\n]", packageName);

    for (int i = 0; i < packageCount; i++) {
        if (strcmp(packages[i].packageName, packageName) == 0) {
            if (packages[i].seatsAvailable > 0) {
                packages[i].seatsAvailable--;
                printf("Booking successful! Seats remaining: %d\n", packages[i].seatsAvailable);
            } else {
                printf("Sorry, no seats available for this package.\n");
            }
            return;
        }
    }

    printf("Package not found.\n");
}

int main() {
    struct TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;
    int choice;

    do {
        printf("\nTravel Package Management System\n");
        printf("1. Add Travel Package\n");
        printf("2. Display Available Packages\n");
        printf("3. Book a Travel Package\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                packageCount = addPackage(packages, packageCount);
                break;
            case 2:
                displayPackages(packages, packageCount);
                break;
            case 3:
                bookPackage(packages, packageCount);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

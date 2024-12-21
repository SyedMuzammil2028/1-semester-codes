#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char province[20];
    int age;
    char gender[10];

    printf("Child Marriage Law Checker\n");
    printf("---------------------------\n");

    printf("Enter your province (Sindh, Punjab, KPK, Balochistan): ");
    fgets(province, 20, stdin);
    province[strcspn(province, "\n")] = 0; // Remove newline character

    printf("Enter your age: ");
    scanf("%d", &age);

    // Clear input buffer to avoid issues with fgets after scanf
    while (getchar() != '\n');

    printf("Enter your gender (Male, Female): ");
    fgets(gender, 10, stdin);
    gender[strcspn(gender, "\n")] = 0; // Remove newline character

    if (strcasecmp(province, "sindh") == 0) {
        if (age >= 18) {
            printf("\nIt is legal for you to marry.\n");
        } else {
            printf("\nIt is not legal for you to marry.\n");
        }
    } else if (strcasecmp(province, "punjab") == 0 || strcasecmp(province, "kpk") == 0 || strcasecmp(province, "balochistan") == 0) {
        if (strcasecmp(gender, "male") == 0) {
            if (age >= 18) {
                printf("\nIt is legal for you to marry.\n");
            } else {
                printf("\nIt is not legal for you to marry.\n");
            }
        } else if (strcasecmp(gender, "female") == 0) {
            if (age >= 16) {
                printf("\nIt is legal for you to marry.\n");
            } else {
                printf("\nIt is not legal for you to marry.\n");
            }
        } else {
            printf("\nInvalid gender.\n");
        }
    } else {
        printf("\nInvalid province.\n");
    }

    return 0;
}

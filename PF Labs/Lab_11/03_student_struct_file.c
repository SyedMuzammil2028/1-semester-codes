#include <stdio.h>
struct student {
    char name[100];
    int id;
    float gpa;
}s[5];

int main()
{
    FILE *fptr;

    // Open a file in write mode
    fptr = fopen("03.txt", "w");
    if (fptr == NULL) {
        printf("Could not open file for writing\n");
        return 1;
    }

    // Read and write data for 5 students
    printf("Enter details for 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter your name: ");
        scanf("%s", s[i].name);
        printf("Enter your ID: ");
        scanf("%d", &s[i].id);
        printf("Enter your GPA: ");
        scanf("%f", &s[i].gpa);

        // Write the data to the file
        fprintf(fptr, "%s %d %.2f\n", s[i].name, s[i].id, s[i].gpa);
    }
    fclose(fptr);

    // Open the file in read mode
    fptr = fopen("q3.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file for reading\n");
        return 1;
    }

    // Read and display data from the file
    printf("\nReading data from file:\n");
    for (int i = 0; i < 5; i++) {
        fscanf(fptr, "%s %d %f", s[i].name, &s[i].id, &s[i].gpa);
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("ID: %d\n", s[i].id);
        printf("GPA: %.2f\n", s[i].gpa);
    }

    // Close the file
    fclose(fptr);

    return 0;
}

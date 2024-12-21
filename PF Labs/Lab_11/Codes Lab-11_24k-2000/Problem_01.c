#include <stdio.h>
#include <string.h>
// Structure to store information about students, including personal details,
// academic details, and address and a program to input details for 5 students
// and display the student with the highest GPA.
struct Address
{
    char city[50];
    char street[50];
    int postalCode;
};

struct Student
{
    char name[50];
    int age;
    int rollNumber;
    float gpa;
    struct Address address;
};

int findHighestGPA(struct Student students[], int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (students[i].gpa > students[index].gpa)
        {
            index = i;
        }
    }
    return index;
}

int main()
{
    struct Student students[5];
    int i;

    printf("Enter details for 5 students:\n");
    for (i = 0; i < 5; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
        printf("City: ");
        scanf("%s", students[i].address.city);
        printf("Street: ");
        scanf("%s", students[i].address.street);
        printf("Postal Code: ");
        scanf("%d", &students[i].address.postalCode);
    }

    int highestIndex = findHighestGPA(students, 5);
    printf("\nStudent with the highest GPA:\n");
    printf("Name: %s\n", students[highestIndex].name);
    printf("Age: %d\n", students[highestIndex].age);
    printf("Roll Number: %d\n", students[highestIndex].rollNumber);
    printf("GPA: %.2f\n", students[highestIndex].gpa);
    printf("Address: %s, %s, %d\n",
           students[highestIndex].address.city,
           students[highestIndex].address.street,
           students[highestIndex].address.postalCode);

    return 0;
}

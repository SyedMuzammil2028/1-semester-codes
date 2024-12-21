#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Develop a grading system using text files. Program to input and store student
// names, roll numbers, and grades into a text file. Allow the user to view records of students with
// a grade above a certain threshold.

const char *students_data = "students.txt";

struct students
{
    char student_name[15];
    char roll_no[10];
    float grade;
};

void add_data()
{
    struct students s;

    printf("==== INPUT STUDENT DATA ====\n");
    printf("Student Name: ");
    scanf("%s", s.student_name);
    printf("Student Roll No: ");
    scanf("%s", s.roll_no);
    printf("Student Grades: ");
    scanf("%f", &s.grade);

    FILE *file = fopen(students_data, "a");
    if (file == NULL)
    {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fprintf(file, "%s %s %.2f\n", s.student_name, s.roll_no, s.grade);
    fclose(file);

    printf("Student data added successfully!\n");
}

void view_records()
{
    char search_roll[10];
    struct students s[100];
    int s_count = 0;
    int flag = 0;

    printf("Enter the roll no of the student you want to view: ");
    scanf("%s", search_roll);

    FILE *file = fopen(students_data, "r");
    if (file == NULL)
    {
        printf("The file does not exist...\n");
        return;
    }

    while (fscanf(file, "%s %s %f", s[s_count].student_name, s[s_count].roll_no, &s[s_count].grade) == 3)
    {
        s_count++;
    }
    fclose(file);

    for (int i = 0; i < s_count; i++)
    {
        if (strcmp(s[i].roll_no, search_roll) == 0)
        {
            flag = 1;
            printf("\n\n>>>> Student Record Found!!! \n");
            printf("--- Student Details ---\n");
            printf("Student Name: %s\n", s[i].student_name);
            printf("Student Roll No: %s\n", s[i].roll_no);
            printf("Student Grades: %.2f\n", s[i].grade);
            break;
        }
    }

    if (flag == 0)
    {
        printf("No student record found with roll number: %s\n", search_roll);
    }
}

int main()
{
    int choice = 0;

    while (choice != 3)
    {
        printf("====== Students Menu ======\n");
        printf("1. Add Student Data\n");
        printf("2. View Student Record\n");
        printf("3. Exit the Program\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_data();
            break;

        case 2:
            view_records();
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid Input. Please try again.\n");
            break;
        }
    }

    return 0;
}

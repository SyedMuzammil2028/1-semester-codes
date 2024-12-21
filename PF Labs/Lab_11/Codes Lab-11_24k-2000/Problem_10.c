#include <stdio.h>
#include <string.h>
// Create a timetable management system using nested structures:
// Store course details, timings, and instructor details.
// Input and display the timetable for different departments.
// Save the timetable data into a text file.
// Allow the user to retrieve and edit the timetable for a specific department.

struct Instructor
{
    char name[50];
    char department[50];
};

struct Course
{
    char courseName[50];
    char timing[50];
    struct Instructor instructor;
};

struct Timetable
{
    char department[50];
    struct Course courses[10];
    int numCourses;
};

void inputTimetable(struct Timetable *timetable)
{
    printf("\nEnter details for department: %s\n", timetable->department);
    printf("Enter number of courses: ");
    scanf("%d", &timetable->numCourses);

    for (int i = 0; i < timetable->numCourses; i++)
    {
        printf("\nCourse %d:\n", i + 1);
        printf("Course Name: ");
        scanf(" %s", timetable->courses[i].courseName);
        printf("Timing: ");
        scanf(" %s", timetable->courses[i].timing);
        printf("Instructor Name: ");
        scanf(" %s", timetable->courses[i].instructor.name);
        printf("Instructor Department: ");
        scanf(" %s", timetable->courses[i].instructor.department);
    }
}

void displayTimetable(struct Timetable timetable)
{
    printf("\nTimetable for department: %s\n", timetable.department);
    for (int i = 0; i < timetable.numCourses; i++)
    {
        printf("\nCourse: %s\n", timetable.courses[i].courseName);
        printf("Timing: %s\n", timetable.courses[i].timing);
        printf("Instructor: %s, Department: %s\n",
               timetable.courses[i].instructor.name,
               timetable.courses[i].instructor.department);
    }
}
void saveTimetableToFile(struct Timetable timetable)
{
    FILE *file = fopen("timetable.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "Timetable for department: %s\n", timetable.department);
    for (int i = 0; i < timetable.numCourses; i++)
    {
        fprintf(file, "\nCourse: %s\n", timetable.courses[i].courseName);
        fprintf(file, "Timing: %s\n", timetable.courses[i].timing);
        fprintf(file, "Instructor: %s, Department: %s\n",
                timetable.courses[i].instructor.name,
                timetable.courses[i].instructor.department);
    }
    fclose(file);
}
void editTimetable(struct Timetable *timetable)
{
    printf("\nEnter department name to edit: ");
    char department[50];
    scanf("%s", department);

    if (strcmp(timetable->department, department) == 0)
    {
        printf("Editing timetable for department: %s\n", timetable->department);
        inputTimetable(timetable);
    }
    else
    {
        printf("Department not found.\n");
    }
}
int main()
{
    struct Timetable timetable = {"Computer Science", {}, 0};
    inputTimetable(&timetable);
    displayTimetable(timetable);
    saveTimetableToFile(timetable);
    editTimetable(&timetable);
    return 0;
}

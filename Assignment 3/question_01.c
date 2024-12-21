#include <stdio.h>
#include <string.h>
typedef struct Employee
{
    int employeeCode;
    char employeeName[20];
    int dateOfJoining;
} Employee;
void setValues(Employee *e)
{
    printf("Enter the Date of joining: (Format: DDMMYYYY)\n");
    scanf("%d", &(*e).dateOfJoining);
    printf("Enter the Code:\n");
    scanf("%d", &(*e).employeeCode);
    printf("Enter the Name of the employee:\n");
    scanf(" %[^\n]", (*e).employeeName);
}
void _3YearsTenure(Employee employees[], int size, int currentDate)
{
    int tenureCount = 0;
    int currentYear = currentDate % 10000;
    int currentMonth = (currentDate / 10000) % 100;
    int currentDay = currentDate / 1000000;
    for (int i = 0; i < size; i++)
    {

        int yearJoined = employees[i].dateOfJoining % 10000;
        int monthJoined = (employees[i].dateOfJoining / 10000) % 100;
        int dayJoined = employees[i].dateOfJoining / 1000000;

        int difference = (currentYear - yearJoined);

        if ((difference > 3) || ((difference == 3) && (currentMonth > monthJoined)) || ((difference == 3) && (currentMonth == monthJoined) && (currentDay > dayJoined)))
        {
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Employee Date Of Joining: %d\n\n", employees[i].dateOfJoining);
            tenureCount++;
        }
    }
    printf("Employees With Tenure more than three years: %d\n", tenureCount);
}
int main()
{
    Employee employees[4];
    int currentDate;
    for (int i = 0; i < 4; i++)
    {
        printf("Enter the Details of Employee %d: \n", i + 1);
        setValues(&employees[i]);
    }
    printf("Enter current Date: (Format: DDMMYYYY)\n");
    scanf("%d", &currentDate);
    _3YearsTenure(employees, 4, currentDate);
    return 0;
}
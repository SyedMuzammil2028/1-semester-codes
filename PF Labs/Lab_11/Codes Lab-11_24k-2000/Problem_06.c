#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Design a nested structure for employees that stores personal details and a timesheet
// for each day of the week (e.g., hours worked). Write a program to Input timesheet data for 10
// employees. Calculate and display the total hours worked by each employee in the week. Identify
// employees who worked overtime (above 40 hours).

#define working_days 5
#define max 10

struct daily
{
     float hours_worked_daily;
};

struct timesheet
{
     struct daily d[working_days];
};

struct employees
{
     char employee_id[10];
     char full_name[20];
     char gender[10];
     char dob[15];
     struct timesheet t_s;
};
struct employees e[max];

const char *days[working_days] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int i, j = 0;
float total_hours_worked[max] = {0};

void input_ts_data()
{

     printf("====INPUT TIMESHEET DATA====\n");

     for (i = 0; i < 10; i++)
     {
          for (j = 0; j < 5; j++)
          {
               printf("Enter hours worked on %s for the Employee %d: ", days[j], i + 1);
               scanf("%f", &e[i].t_s.d[j].hours_worked_daily);
          }
          printf("\nSuccessfully Added Timesheet data for Employee %d!!!\n", i + 1);
     }
}

void calculate_display()
{

     for (i = 0; i < 10; i++)
     {
          for (j = 0; j < 5; j++)
          {
               total_hours_worked[i] = total_hours_worked[i] + e[i].t_s.d[j].hours_worked_daily;
          }
     }

     for (i = 0; i < 10; i++)
     {
          printf("Total hours worked for Employee %d throughout the week is : %f\n", i + 1, total_hours_worked[i]);
     }
}

void search_overtime()
{
     printf("=====EXEMPLARY EMPLOYEES====\n");
     int found = 0;

     for (i = 0; i < 10; i++)
     {
          if (total_hours_worked[i] > 40)
          {
               found = 1;
               printf("Employee %d has worked overtime upto %.2f hours throughout the entire week !!!\n", i + 1, total_hours_worked[i]);
          }
     }

     if (found == 0)
     {
          printf("No Employees found working overtime...");
     }
}

int main()
{
     int choice;

     while (choice != 4)
     {
          printf("===EMPLOYEE MENU===\n");
          printf("1. Input timesheet data for all Employees \n");
          printf("2. Calculate and Display Hours worked by an Employee\n");
          printf("3. Search for Employees working overtime\n");
          printf("4. Exit the Program\n");
          printf(">>");
          scanf("%d", &choice);

          switch (choice)
          {
          case 1:
               input_ts_data();
               break;

          case 2:
               calculate_display();
               break;

          case 3:
               search_overtime();
               break;

          default:
               printf("Invalid Input.... Exiting...");
               break;
          }

          printf("Exiting the Program... Goodbye..");
     }
     return 0;
}
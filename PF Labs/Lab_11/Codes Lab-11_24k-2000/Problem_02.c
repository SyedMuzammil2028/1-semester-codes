#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// program to manage employee records in a company. Store employee details in
// an array of structures and implement the following:
// Add new employees.
// Search for an employee by ID.
// Update salary details for a specific employee.
// Display all employee details sorted by their joining date

#define MAX_EMPLOYEES 10

struct employee
{
    char employee_id[10];
    char name[20];
    char role[15];
    float salary;
    char dept[10];
    char join_date[15];
};

struct employee e[MAX_EMPLOYEES];
int employee_count = 0;
void add_new_employees()
{
    if (employee_count >= MAX_EMPLOYEES)
    {
        printf("Employee limit reached. Cannot add more employees.\n");
        return;
    }

    printf("==== Input Data for Employee %d ====\n", employee_count + 1);
    printf("Employee ID: ");
    scanf("%s", e[employee_count].employee_id);
    printf("Employee Name: ");
    scanf("%s", e[employee_count].name);
    printf("Employee Role: ");
    scanf("%s", e[employee_count].role);
    printf("Employee Salary: ");
    scanf("%f", &e[employee_count].salary);
    printf("Employee Department: ");
    scanf("%s", e[employee_count].dept);
    printf("Joining Date (DD/MM/YYYY): ");
    scanf("%s", e[employee_count].join_date);

    employee_count++;
    printf("Employee added successfully....\n");
}

void search_employee()
{
    char id_search[10];
    printf("Enter the ID of the employee you want to search for: ");
    scanf("%s", id_search);

    for (int i = 0; i < employee_count; i++)
    {
        if (strcmp(e[i].employee_id, id_search) == 0)
        {
            printf("Employee Found:\n");
            printf("==== EMPLOYEE DETAILS ====\n");
            printf("ID: %s\n", e[i].employee_id);
            printf("Name: %s\n", e[i].name);
            printf("Role: %s\n", e[i].role);
            printf("Department: %s\n", e[i].dept);
            printf("Salary: %.2f\n", e[i].salary);
            printf("Joining Date: %s\n", e[i].join_date);
            return;
        }
    }
    printf("No employee found with this ID.\n");
}

void update_salary()
{
    char id_search[10];
    float new_salary;
    printf("Enter the ID of the employee whose salary you want to update: ");
    scanf("%s", id_search);

    for (int i = 0; i < employee_count; i++)
    {
        if (strcmp(e[i].employee_id, id_search) == 0)
        {
            printf("Employee Found:\n");
            printf("Current Salary: %.2f\n", e[i].salary);
            printf("Enter the new salary: ");
            scanf("%f", &new_salary);
            e[i].salary = new_salary;
            printf("Salary updated successfully!\n");
            return;
        }
    }
    printf("No employee found with this ID.\n");
}

void display_all_details()
{
    if (employee_count == 0)
    {
        printf("No employees to display.\n");
        return;
    }

    printf("\n%-10s %-20s %-15s %-10s %-10s %-15s\n", "ID", "Name", "Role", "Salary", "Dept", "Join Date");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < employee_count; i++)
    {
        printf("%-10s %-20s %-15s %-10.2f %-10s %-15s\n", e[i].employee_id, e[i].name, e[i].role, e[i].salary, e[i].dept, e[i].join_date);
    }
}
void sort_the_employees()
{
    struct employee temp;
    for (int i = 0; i < employee_count - 1; i++)
    {
        for (int j = 0; j < employee_count - i - 1; j++)
        {
            if (strcmp(e[j].join_date, e[j + 1].join_date) > 0)
            {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
    printf("Employees sorted by joining date.\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Add New Employees\n2. Search for an Employee by ID\n3. Update Salary Details\n4. Display All Employee Details\n5. Sort Employees by Joining Date\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_new_employees();
            break;
        case 2:
            search_employee();
            break;
        case 3:
            update_salary();
            break;
        case 4:
            display_all_details();
            break;
        case 5:
            sort_the_employees();
            break;
        case 6:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

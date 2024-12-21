#include <stdio.h>
#include <stdlib.h>
void inputEmployees(int **ratings, int numEmployees, int numPeriods)
{
    int i, j;
    for (i = 0; i < numEmployees; i++)
    {
        printf("Enter ratings for employee %d: \n", i + 1);
        for (j = 0; j < numPeriods; j++)
        {
            while (1)
            {
                printf("Evaluation period %d (1-10): ", j + 1);
                scanf("%d", &ratings[i][j]);
                if (ratings[i][j] >= 1 && ratings[i][j] <= 10)
                {
                    break;
                }
                else
                {
                    printf("Invalid input. Please enter a rating between 1 - 10.\n");
                }
            }
        }
        printf("\n");
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods)
{
    printf("---------- PERFORMANCE RATINGS ----------\n");
    int i, j;
    for (i = 0; i < numEmployees; i++)
    {
        printf("Performance of employee %d: \n", i + 1);
        for (j = 0; j < numPeriods; j++)
        {
            printf("  Evaluation period %d: %d\n", j + 1, ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods)
{
    int max = 0, sum, index = -1;
    float avg;
    int i, j;
    for (i = 0; i < numEmployees; i++)
    {
        sum = 0;
        for (j = 0; j < numPeriods; j++)
        {
            sum = sum + ratings[i][j];
        }
        avg = (float)sum / numPeriods;
        if (avg > max)
        {
            max = avg;
            index = i;
        }
    }
    return index;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods)
{
    float max = 0;
    int sum, periodIndex = -1;
    int i, j;
    for (j = 0; j < numPeriods; j++)
    {
        sum = 0;
        for (i = 0; i < numEmployees; i++)
        {
            sum += ratings[i][j];
        }
        float avg = (float)sum / numEmployees;
        if (avg > max)
        {
            max = avg;
            periodIndex = j;
        }
    }
    return periodIndex;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods)
{
    int min = 1000, sum, index = -1;
    float avg;
    int i, j;
    for (i = 0; i < numEmployees; i++)
    {
        sum = 0;
        for (j = 0; j < numPeriods; j++)
        {
            sum = sum + ratings[i][j];
        }
        avg = (float)sum / numPeriods;
        if (avg < min)
        {
            min = avg;
            index = i;
        }
    }
    return index;
}
struct Employee
{
    int *ratings;
    int totalScore;
};
int main()
{
    int numEmployees, numPeriods;
    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter number of evaluation periods: ");
    scanf("%d", &numPeriods);
    int **ratings;
    ratings = (int **)malloc(numEmployees * sizeof(int *)); // aloocating memory to rating dynamically
    if (ratings == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    int i;
    for (i = 0; i < numEmployees; i++)
    {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
        if (ratings[i] == NULL)
        {
            printf("Memory allocation failed for employee %d!\n", i + 1);
            return 1;
        }
    }
    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);
    int a = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the year, who has the highest average rating, is employee number: %d\n", a + 1);
    int b = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated period is period: %d\n", b + 1);
    int c = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Employee of the year, who has the lowest average rating, is employee number: %d\n", c + 1);
    for (i = 0; i < numEmployees; i++)
    {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
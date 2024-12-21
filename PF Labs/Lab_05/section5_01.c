#include <stdio.h>
// program that is year is a leap year
int main()
{
    int year;

    // input year from user
    printf("Enter year to check whether it is leap year: ");
    scanf("%d", &year);

    // check if year is leap year
    if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))
    {
        printf("\n %d year is a leap year", year);
    }
    else
    {
        printf("\n %d year is not a leap year", year);
    }

    return 0;
}
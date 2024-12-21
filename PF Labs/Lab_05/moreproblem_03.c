#include <stdio.h>
// program to determine if a person is eligible for a loan:
// based on age, income, and credit score.
int main()
{
    int age, income, credit_score;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter income in PKR: ");
    scanf("%d", &income);
    printf("Enter credit score: ");
    scanf("%d", &credit_score);

    // Determine if the person is eligible for a loan
    if (age >= 18 && income > 30000 && credit_score >= 600)
    {
        printf("You are eligible for a loan");
    }
    else
    {
        printf("You are not eligible for a loan");
    }

    return 0;
}
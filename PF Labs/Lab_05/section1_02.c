#include <stdio.h>
// program to check number is positive, negative, or zero, and if it’s positive,
// checks if it’s an even or odd number
int main()
{
    int num;

    // read a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // check if the number is positive, negative, or zero
    if (num > 0)
    {
        printf("%d is positive", num);
        if (num % 2 == 0)
        {
            printf(" and is even number.");
        }
        else
        {
            printf(" and is odd number.");
        }
    }
    else if (num < 0)
    {
        printf("%d is negative", num);
    }
    else if (num == 0)
    {
        printf("%d is zero", num);
    }
    else
    {
        printf("Invalid input");
    }
    return 0;
}
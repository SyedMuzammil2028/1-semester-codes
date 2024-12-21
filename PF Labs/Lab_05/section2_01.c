#include <stdio.h>
// program to checks if number is divisible by 3 and 5 both.
int main()
{
    int number;

    // read a number from the user
    printf("Enter a number to check wether it is divisible by 3 and 5: ");
    scanf("%d", &number);

    // check if  the number is divisible by both 3 and 5
    if (number % 3 == 0 && number % 5 == 0)
    {
        printf("\n%d is divisible by both 3 and 5", number);
    }
    else
    {
        printf("\n%d is not divisible by both 3 and 5", number);
    }

    return 0;
}
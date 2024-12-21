#include <stdio.h>
int main()
{
    int number;

    // Prompt the user to enter a positive number greater than 0
    printf("Enter a positive number greater than 0: ");
    scanf("%d", &number);

    // Check if the input is valid (greater than 0)
    if (number <= 0)
    {
        printf("Invalid input. Please enter a positive number greater than 0.\n");
    }
    else
    {
        // Determine if the number is even or odd
        if (number % 2 == 0)
        {
            printf("%d is an even number.\n", number);
        }
        else
        {
            printf("%d is an odd number.\n", number);
        }

        return 0;
    }
}
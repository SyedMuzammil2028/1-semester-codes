#include<stdio.h>
// program to check whether a given number is prime or not.
int main()
{
    int num, i, result;

    // read the number from the user 
    printf("Enter number to check whether a number is prime: ");
    scanf("%d", &num);

    // check if input is 0 or 1
    if (num == 0 || num == 1)
    {
        printf("%d is not prime number .", num);
    }
    // check input is prime or not
    else
    {    
        // setting up the conditons to check number
        for (i = 2; i < num; i++)
        {
            // check if number is divisible by other numbers(i) than itself
            if (num % i == 0 && num != 2)
            {
                result = 1; // if condition is true, set result to 1 (not prime)
                break; // and exit the loop
            }
        }

        // check if flag(result) is 1 or not
        if (result == 1)
        {
            printf("%d is not a prime number.", num);
        }
        else
        {
            printf("%d is a prime number", num);
        }
    }
    return 0;
}
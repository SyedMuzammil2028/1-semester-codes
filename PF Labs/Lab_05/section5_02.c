#include <stdio.h>
// program that calculates the sum of digits of
// a number until the result is a single digit
int main()
{
    int num, sum, lastdigit;

    // Read a number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Loop until the sum becomes a single digit
    while (num >= 10)
    {
        sum = 0; 

        // Calculate sum of digits
        while (num > 0)
        {
            lastdigit = num % 10; // extract last digit from number
            sum += lastdigit; // add the last digit to the sum
            num /= 10; // remove the last digit
        }

        num = sum; 
    }

    printf("The single-digit sum is: %d\n", num);

    return 0;
}
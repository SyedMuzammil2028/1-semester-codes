#include <stdio.h>
// Use the ternary operator to check if a number is positive, negative, or zero
int main()
{
    int number;

    // read a number from the user
    printf("Enter a number: ");
    scanf("%d", &number);

    // using ternary operator  to check the number is +ve ,-ve, or zero
    number > 0 ? printf("The number is positive") : (number < 0 ? printf("The number is negative") : printf("The number is zero"));
    return 0;
}

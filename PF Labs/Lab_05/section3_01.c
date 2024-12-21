#include <stdio.h>
// program to find the maximum of two numbers using a ternary operator.
int main()
{
    int num_01, num_02;

    // read  two numbers from the user
    printf("Enter first number: ");
    scanf("%d", &num_01);

    printf("Enter second number: ");
    scanf("%d", &num_02);

    // using ternary operator to find the maximum of two numbers
    num_01 > num_02 ? printf("Maximum number is %d", num_01) : printf("Maximum number is %d", num_02);

    return 0;
}
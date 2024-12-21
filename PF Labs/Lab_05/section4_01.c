#include <stdio.h>
// program to swap two numbers using bitwise XOR
int main()
{
    int a, b;
    // read two numbers from user
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    // numbers before swapping
    printf("\nBefore swapping: a = %d , b = %d", a, b);
    // swapping using XOR operator
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    // numbers after swapping
    printf("\nAfter swapping: a = %d , b = %d", a, b);
    return 0;
}
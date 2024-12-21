#include <stdio.h>
// function that takes two numbers as input and returns their product.
int product(int a, int b);

int main()
{
    int a, b;
    printf("Enter two numbers to find there product:\n");
    scanf("%d %d", &a, &b);
    
    printf("\nProduct of %d and %d is: %d\n", a, b, product(a, b));

    return 0;
}

int product(int a, int b)
{
    return a * b;
}
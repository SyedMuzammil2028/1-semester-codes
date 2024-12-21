#include <stdio.h>
// progam to find greatest of three numbers
int main()
{
    int num1, num2, num3;

    // input three numbers from user
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // check the conditions to find the greatest number
    if (num1 >= num2)
    {
        if (num1 >= num3)
        {
            printf("%d is the greatest number", num1);
        }
    }
    else if (num2 >= num1)
    {
        if (num2 >= num3)
        {
            printf("%d is the greatest number", num2);
        }
    }
    else if (num3 >= num1)
    {
        if (num3 >= num2)
        {
            printf("%d is the greatest number", num3);
        }
    }

    return 0;
}
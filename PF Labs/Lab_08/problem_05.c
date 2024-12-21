#include <stdio.h>
// pattern of odd numbers in decreasing order starting
// from a user-specified number using nested loops.
int main()
{
    int num;
    printf("Enter starting odd number: ");
    scanf("%d", &num);

    while (num % 2 == 0)
    {
        printf("\n%d is not an odd number",num);
        printf("\nPlease enter an odd number: ");
        scanf("%d", &num);
    }

    for (int i = num; i >= 1; i -= 2)
    {
        for (int j = i; j >= 1; j -= 2)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
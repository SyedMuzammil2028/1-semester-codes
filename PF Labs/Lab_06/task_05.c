#include <stdio.h>
// program to print pattern of task 5
int main()
{
    int i;

    for (i = 1; i <= 14; i++)
    {
        // print the top row
        if (i >= 1 && i <= 5)
        {
            printf("* ");
        }

        // adding a new line
        if (i == 5)
        {
            printf("\n"); 
        }

        // print the middle rows with spaces between them
        if (i >= 6 && i <= 9)
        {
            printf("*\t*\n");
        }

        // print the bottom row
        if (i >= 10 && i <= 14)
        {
            printf("* ");
        }
    }

    return 0;
}
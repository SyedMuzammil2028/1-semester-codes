#include <stdio.h>
// program to print pattern of task 8
int main()
{
    int i;

    for (i = 1; i <= 16; i++)
    { 
        // printing the first row
        if (i <= 5)
        {
            printf(" *"); 
        }
        // adding new line
        if (i == 5)
        {
            printf("\n");
        }
        // printing the second row
        if (i>=6 && i<=7)
        {
            printf("   *");
        }
        // printing the middle row
        if (i == 8)
        {
            printf("\n     *\n");
        }
        // printing the second last row
        if (i>=9 && i<=10)
        {
            printf("   *");
        }
        // adding new line
        if (i==11)
        {
             printf("\n");
        }
        // printing the last row
        if (i >= 12 && i <= 16)
        {
            printf(" *");
        }
    }
    return 0;
}
#include <stdio.h>
// program to print pattern of task 8
int main()
{
    int i;

    // printing the first row
    for (i = 65; i <= 69; i++)
    {
        printf(" %c", i);
    }
    
    printf("\n"); // adding new line
    
    // printing the second row
    for (i = 67; i <= 70; i++)
    {
        if (i == 67 || i == 70)
        {
            printf("   %c", i);
        }
    }

    // printing the middle row
    printf("\n     %c\n", 69);

    // printing the second last row
    for (i = 69; i <= 72; i++)
    {
        if (i == 69 || i == 72)
        {
            printf("   %c", i);
        }
    }

    // printing the last row
    printf("\n");
    for (i = 69; i <= 73; i++)
    { 
        printf(" %c", i);
    }

    return 0;
}
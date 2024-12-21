#include<stdio.h>
// program to print pattern of task 5
int main()
{
    int i;
    
    // print the top row
    for ( i = 0; i < 5; i++)
    {
        printf("* ");
    }
    printf("\n");

    // print the middle rows with spaces between them
    for ( i = 0; i < 4; i++)
    {
        printf("*\t*\n");
    }

    // print the bottom row
    for ( i = 0; i < 5; i++)
    {
        printf("* ");
    }
    printf("\n");

    return 0;
}
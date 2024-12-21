#include<stdio.h>
// program to print pattern of task 7
int main()
{
    char alphatop,alphacoloum1,alphacoloum2,alphadown;

    // print the top row
    for ( alphatop = 'A'; alphatop <= 'E'; alphatop++)
    {
        printf("%c ",alphatop);
    }
    printf("\n");

    // print the middle rows with spaces between them
    for (alphacoloum1 = 'B',alphacoloum2='F'; alphacoloum1 <= 'E',alphacoloum2<='I'; alphacoloum1++,alphacoloum2++ )
    {
        printf("%c\t%c\n",alphacoloum1,alphacoloum2);
    }

    // print the bottom row
     for ( alphadown = 'F'; alphadown <= 'J'; alphadown++)
    {
        printf("%c ",alphadown);
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
// Program to create a 3D array representing 2 pages of a 3x3 matrix also
// Initializing it and to find the sum of all the elements on each page.
int main()
{
    int arr[2][3][3] = {{{1, 2, 4}, {3, 4, 1}, {3, 4, 9}},
                        {{5, 0, 6}, {7, 4, 8}, {3, 1, 4}}};
    int sum = 0;

    // Displaying the 3D array
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Calculating the sum of all elements on each page
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                sum += arr[i][j][k];
            }
        }
        // Printing the sum of each page
        printf("Sum of page %d is %d\n", i, sum);
        sum = 0;
    }
    return 0;
}
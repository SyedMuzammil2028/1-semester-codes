#include <stdio.h>
// Write a program to take a 2D array input
// from the user and display its transpose.
int main(){
    int arr[3][3];
    int i, j;
    int arrtranspose[3][3];
    printf("Enter elements of matrix\n");

    // input  elements in the matrix form user
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("element[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");

    // print original matrix
    printf("Original matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // taking transpose of matrix
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arrtranspose[j][i] = arr[i][j];
        }
    }
    printf("\n");

    // print transpose of matrix
    printf("Transpose of matrix:\n");
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            printf("%d ", arrtranspose[j][i]);
        }
        printf("\n");
    }
    return 0;
}
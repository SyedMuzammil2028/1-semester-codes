#include <stdio.h>
int main()
{
    int top=0, bottom=0, left=0, right=0;
    int row, column;
    printf("Enter row:");
    scanf("%d",&row);
    printf("Enter column:");
    scanf("%d",&column);
    int arr[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("\nenter element[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0; i < column; i++)
    {
        top+= arr[0][i];
        bottom+= arr[row-1][i];
    }
    for (int i = 0; i < row; i++)
    {
        left+= arr[i][0];
        right+= arr[i][column-1];
    }
    
    int sum = top + bottom + left + right;
    
    printf("\nSum of all elements in the array is: %d", sum);

    return 0;
}
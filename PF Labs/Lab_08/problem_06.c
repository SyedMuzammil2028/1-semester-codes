#include <stdio.h>
// program to find the saddle point(s) in a given 3x3 matrix.
int main(){
    int matrix[3][3];
    int i, j, k;
    int isSaddlePoint, saddlePointFound=0;

    printf("Enter the elements of a 3x3 matrix:\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++){
        int rowMin = matrix[i][0];
        int colIndex = 0;

        for (j = 1; j < 3; j++){
            if (matrix[i][j] < rowMin){
                rowMin=matrix[i][j];
                colIndex=j;
            }
        }
        isSaddlePoint=1;
        for (k = 0; k < 3; k++){
            if (matrix[k][colIndex] > rowMin){
                isSaddlePoint=0;
                break;
            }
        }
        if (isSaddlePoint){
            printf("\nSaddle point found at [%d][%d] with value %d\n",i,colIndex,rowMin);
            saddlePointFound=1;        
        }
    }

    if (!saddlePointFound){
        printf("\nNo saddle point found in the matrix.\n");
    }
    return 0;
}
#include <stdio.h>
// program to multiply two matrices of size 3x3 
// and display the result matrix.
int main(){
    int matrix_1[3][3];
    int matrix_2[3][3];
    int result_matrix[3][3];

    printf("Enter elements in first matrix:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("element [%d][%d]: ", i, j);
            scanf("%d", &matrix_1[i][j]);
        }
    }
    
    printf("\nEnter elements in second matrix:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("element [%d][%d]: ", i, j);
            scanf("%d", &matrix_2[i][j]);
        }
    }

    printf("\nFirst Matrix:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", matrix_1[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond Matrix:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", matrix_2[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            result_matrix[i][j] = 0;
            for (int h = 0; h < 3; h++)
            {
                result_matrix[i][j] += matrix_1[i][h] * matrix_2[h][j];
            }
        }
    }
    printf("\nResult Matrix:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
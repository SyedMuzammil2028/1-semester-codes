#include <stdio.h>
#include <stdlib.h>

void doubleArray(int **arr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] *= 2;
        }
    }
}

int main() {
    int **arr;

    arr = (int **)malloc(3 * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        arr[i] = (int *)malloc(4 * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed for row %d.\n", i);
            return 1;
        }
    }

    printf("Enter elements for a 3x4 array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    doubleArray(arr);

    printf("\nModified array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("arr[%d][%d] = %d  ", i + 1, j + 1, arr[i][j]);
        }
        printf("\n"); 
    }

    for (int i = 0; i < 3; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

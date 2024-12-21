#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nArray elements after calloc (initialized to 0):\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i + 1, arr[i]);
    }

    arr = (int *)realloc(arr, 2 * n * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    printf("\nEnter %d more elements to populate the expanded array:\n", n);
    for (int i = n; i < 2 * n; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements after reallocation:\n");
    for (int i = 0; i < 2 * n; i++) {
        printf("Element %d: %d\n", i + 1, arr[i]);
    }

    free(arr);

    return 0;
}

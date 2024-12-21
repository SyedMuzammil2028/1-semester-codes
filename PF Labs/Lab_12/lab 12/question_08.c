#include <stdio.h>
#include <stdlib.h>

int *allocatememory(int n) {
    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *array = allocatememory(n);

    for (int i = 0; i < n; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nArray elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: %d\n", i + 1, array[i]);
    }

    free(array);
    array = NULL;

    return 0;
}

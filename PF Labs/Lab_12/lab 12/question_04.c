#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr; 
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    printf("\nOriginal array elements:\n");
    for (i = 0; i < size; i++) {
        printf("Element %d: %d\n", i + 1, ptr[i]);
    }

    ptr = (int *)realloc(ptr, (size + 5) * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    printf("\nEnter 5 more elements:\n");
    for (i = size; i < size + 5; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    printf("\nUpdated array elements:\n");
    for (i = 0; i < size + 5; i++) {
        printf("Element %d: %d\n", i + 1, ptr[i]);
    }

    free(ptr);

    return 0;
}

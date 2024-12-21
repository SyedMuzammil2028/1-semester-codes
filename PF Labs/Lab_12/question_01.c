#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doubleArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
        }
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size );
    int *arr;

    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        return 1;
        }
    
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        }

    doubleArray( arr,size);
    printf("Modified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        }
    
    free(arr);

}
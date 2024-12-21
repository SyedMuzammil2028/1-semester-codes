#include <stdio.h>
// Recursive function linearSearch that takes an array, its size,
// the target element to search for, and the current index
int linearSearch(int arr[], int size, int target, int index){
    if (index >= size)
        return -1;
    if (arr[index] == target)
        return index;
    return linearSearch(arr, size, target, index + 1);
}
int main(){
    int size, target, result;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to search for: ");
    scanf("%d", &target);
    
    result = linearSearch(arr, size, target, 0);
    
    if (result == -1)
    {
        printf("Element %d not found in the array.\n", target);
    }
    else
    {
        printf("Element %d found at index %d.\n", target, result);
    }
    return 0;
}

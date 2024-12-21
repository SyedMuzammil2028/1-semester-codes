#include <stdio.h>
// program to read n number of values in an 
// array and display it in reverse order
int main(){
    int size, i, sum = 0;

    // read the size of array
    printf("Enter size of an array: ");
    scanf("%d", &size);
    int arr[size];
    
    // read the value from user
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d) ", i + 1);
        scanf("%d", &arr[i]);
    }

    // display orignal order
    printf("\nOriginal order: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    // display reverse order
    printf("\nReverse order: ");
    for (i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
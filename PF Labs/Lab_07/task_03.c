#include <stdio.h>
// Program to find the minimum maximum number in array.
int main()
{
    int size, i;
    // read size of an array form user
    printf("Enter size of an array: ");
    scanf("%d", &size);
    
    int arr[size]; // declare an array
    // read the elements
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d) ", i + 1);
        scanf("%d", &arr[i]);
    }

    int min = arr[0]; // declare variable for minimum
    // find the minimun element
    for (i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    int max = arr[0]; // declare variable for maximum
    // find the maximum element
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    // display result
    printf("\nMinimum number: %d", min);
    printf("\nMaximum number: %d", max);
    return 0; }
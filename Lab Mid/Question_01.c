#include <stdio.h>
int main()
{
    int size, i;
    printf("\nEnter size of both array : ");
    scanf("%d", &size);

    int arr1[size];
    int arr2[size];
    int arr3[size];

    printf("\nEnter elements of array 1:");
    for (i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("\nEnter elements of array 2:");
    for (i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < size; i++)
    {
        if (arr1[i] > arr2[size - i - 1])
        {
            arr3[i] = arr1[i] + arr2[size - i - 1];
        }
        else if (arr1[i] <= arr2[size - i - 1])
        {
            arr3[i] = (arr1[i] + arr2[size - i - 1] / 2);
        }
    }

    printf("\nArray 1: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\nArray 2: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\nArray 3: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}
#include <stdio.h>
// Recursive function bubbleSort that takes an array and its size. It performs the
// bubble sort algorithm by repeatedly comparing adjacent elements and swapping them if
// they are in the wrong order
void bubbleSortPass(int arr[], int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSortPass(arr, n - 1);
}

void bubbleSort(int arr[], int n)
{
    if (n <= 1)
        return;
    bubbleSortPass(arr, n);
    bubbleSort(arr, n - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

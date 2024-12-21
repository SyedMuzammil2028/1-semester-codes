#include <stdio.h>
int main()
{
    int size, i, min = 9999, second_min = 9999;
    printf("Enter size of an array: ");
    scanf("%d", &size);
    int arr[size];

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray;\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            second_min = min;
            min = arr[i];
        }
        else if (arr[i] < second_min && arr[i] != min)
        {
            second_min = arr[i];
        }
    }
    printf("\n\nSecond Maximum Element is: %d\n", second_min);

    return 0;
}
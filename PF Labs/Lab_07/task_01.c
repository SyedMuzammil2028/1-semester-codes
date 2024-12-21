#include <stdio.h>
// Program that takes a user input array
// and prints the sum of its elements.
int main()
{
    int size, i, sum = 0;

    // read size of array from user
    printf("Enter size of an array: ");
    scanf("%d", &size);

    // declare array
    int arr[size];

    // read array elements from user
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d) ", i + 1);
        scanf("%d", &arr[i]);

        //  add each element to sum
        sum += arr[i];
    }

    // display the sum of array
    printf("\nSum of elements in array is: %d", sum);
  return 0;
}
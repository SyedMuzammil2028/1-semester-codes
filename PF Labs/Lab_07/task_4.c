#include <stdio.h>
// Given an array arr[] of size N which contains elements from 0 to N-1, you need to find all the
// elements occurring more than once in the given array.
// Input:
// Array Size =5
// Element 1=2
// Element 2=3
// Element 3=1
// Element 4=2
// Element 5=3
// Output:
// Number 2 and 3 in array occur more than once.
// Note: You cannot utilize nested loops
int main() {
    int size;

    // Input size of the array
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];
    int frequency[size]; // Array to keep track of element frequencies

    // Initialize the frequency array with 0
    for (int i = 0; i < size; i++) {
        frequency[i] = 0;
    }

    // Input elements into the array
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Count the frequency of each element in the input array
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    // Output the elements that occur more than once
    printf("Numbers occurring more than once: ");
    for (int i = 0; i < size; i++) {
        if (frequency[i] > 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
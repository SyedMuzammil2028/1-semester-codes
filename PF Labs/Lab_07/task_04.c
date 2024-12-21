#include<stdio.h>
// program to print the elements occurring more than once 
int main(){
    int size;
    // input size of the array
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];
    int count[size]; // Array count the element
   
    // initialize the count array with 0
    for (int i = 0; i < size; i++){
        count[i] = 0;
    }
    // input elements into the array
    for (int i = 0; i < size; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // count each element in the input array
    for (int i = 0; i < size; i++){
        count[arr[i]]++;
    }
    // output the elements that occur more than once
    printf("\nNumbers");
    for (int i = 0; i < size; i++){
        if (count[i] > 1) {
            printf(" %d and", i);
        }
    }
    printf(" occurring more than once");
    return 0; }

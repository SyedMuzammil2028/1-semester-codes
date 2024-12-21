#include <stdio.h>
// function to find maximum & minimum element in an array
int minimumFuntion(int arr[], int size){
    int min = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
int maximumFuntion(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
int main(){
    int size;
    printf("Enter size of an array: ");
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nMinimum value in array is: %d", minimumFuntion(arr, size));
    printf("\nMaximum value in array is: %d", maximumFuntion(arr, size));
    return 0;
    }

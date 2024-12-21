#include <stdio.h>
// Recursive function that calculates the sum of digits of a number
int recursiveSum(int num){
    if (num == 0){
        return 0;
    }
    return num % 10 + recursiveSum(num / 10);
}

int main(){
    int number;
    printf("\nEnter number: ");
    scanf("%d", &number);

    int result = recursiveSum(number);
    printf("Sum of digits of %d is: %d\n", number, result);

    return 0;
}

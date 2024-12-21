#include <stdio.h>
// program that swaps the values of two integers using a user-defined function, swapIntegers.
void swapIntegers(int num1,int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;

    printf("\nAfter Swapping");
    printf("\nFirst integer --> %d",num1);
    printf("\nSecond integer --> %d",num2);
}

int main(){
    int num1,num2;
    printf("Program to swap values of two integers");
    printf("\nEnter first integer: ");
    scanf("%d",&num1);
    printf("Enter second integer: ");
    scanf("%d",&num2);

    swapIntegers(num1,num2);
    return 0;
}
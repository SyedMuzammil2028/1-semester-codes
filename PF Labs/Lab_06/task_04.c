#include<stdio.h>
// program to check whether a number is an Armstrong number or not.
int main()
{
    int num, lastDigit, cube_of_lastDigit, sum_of_cubesDigits = 0;

    // read the number from the user
    printf("Enter a number to check if it is an Armstrong number : ");
    scanf("%d", &num);

    int original_num = num;

    // calculate the sum of the cubes of its digits
    while (original_num != 0) {
        lastDigit = original_num % 10; // extract the last digit
        cube_of_lastDigit = lastDigit * lastDigit * lastDigit; // cube the digit
        sum_of_cubesDigits+=cube_of_lastDigit; // add to sum variable
        original_num /= 10; // remove the last digit
    }

    // check if the sum of cubes is equal to the number itself
    if (sum_of_cubesDigits == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}

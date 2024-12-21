#include<stdio.h>
int main()
{
    int number, sum = 0;

    // using a do-while loop to iterate the loop at least one
    do
    {
        // read the number form user
        printf("Enter a number (enter 0 to stop): ");
        scanf("%d", &number);

        // add the input to the sum except if it is zero
         if (number != 0) {
        sum += number;
         printf("Current sum: %d\n", sum);}
    } while (number != 0); // Repeat the loop until user enter zero

    printf("\nFinal sum: %d", sum);  // print the final sum
    return 0;
}
#include <stdio.h>
// program that counts the number of 1s
// in the binary representation of a number.
int main()
{
    int num, count = 0;

    // read the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // to count the number of 1s in the binary representation
    while (num > 0)
    {
        // Check if the least bit is 1
        if (num & 1)
        {
            count++;
        }
        num = num >> 1; // right shift the number to check the next bit
    }

    printf("Number of 1s in binary representation: %d\n", count);

    return 0;
}
#include<stdio.h>
// program to corresponding number in alphabat
int main()
{
    int n;
    // read number
    printf("Enter positive integer: ");
    scanf("%d",&n);

    // check if number is positive
    if (n>0)
    {
       // check for corresponding number
        switch (n)
        {
        case 1:
        printf("one\n");
        break;
        case 2:
        printf("two\n");
        break;
        case 3:
        printf("three\n");
        break;
        case 4:
        printf("four\n");
        break;
        case 5:
        printf("five\n");
        break;
        case 6:
        printf("six\n");
        break;
        case 7:
        printf("seven\n");
        break;
        case 8:
        printf("eight\n");
        break;
        case 9:
        printf("nine\n");
        break;
        default:
        printf("%d is greater than 9\n",n);
        break;
        }
    }
    else
    {
        printf("Error : Input is not a positive integer.\n");
    }
    return 0;
}
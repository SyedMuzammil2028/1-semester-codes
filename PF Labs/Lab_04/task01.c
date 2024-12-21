#include<stdio.h>
// program to check whether a number is multiple of 3 or not
int main ()
{
    int num;

    // get number from user
    printf("Enter a number to check whether it is multiple of 3 or not: ");  
    scanf("%d",&num);

    // check whether number is multiple of 3 or not
    if (num%3==0)
    {
        printf("%d is a multiple of 3.\n",num);
    }
    else
    {
        printf("%d is not multiple of 3.",num);
    }
    return 0;
}
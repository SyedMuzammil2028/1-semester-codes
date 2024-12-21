#include<stdio.h>
// program to see greetings according to time using a 24-hour format.
int main()
{
    int time;

   // read time from user
    printf("\nEnter time in 24-hour format: ");
    scanf("%d",&time);

   // display greeting according to time
    if (time>=5 && time<=11)
    {
        printf("Good Morning");
    }
    else if (time>=12 && time<=18)
    {
        printf("Good Evening");
    }
    else if (time>18 && time<=24)
    {
        printf("Good Night");
    }
    else
    {
        printf("NO Greetings!");
    }
    return 0;
}
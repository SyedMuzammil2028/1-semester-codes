#include <stdio.h>
// program to display a message based on the temperature range.
int main()
{
    float temp;

  // read the temperature from the user
    printf("Enter the temperature: ");
    scanf("%f",&temp);

  // display the temperature according to the temperaure range
    if (temp<0)
    {
        printf("Freezing weather");
    }
    else if (temp>=0 && temp<=10)
    {
        printf("Very cold weather");
    }
    else if (temp>=1 && temp<=20)
    {
        printf("Cold weather");
    }
    else if (temp>=1 && temp<=30)
    {
        printf("Normal temperture");
    }
     else if (temp>=1 && temp<=40)
    {
        printf("Hot weather");
    }
    else if (temp>=40)
    {
        printf("Very hot weather");
    }
    return 0;
}
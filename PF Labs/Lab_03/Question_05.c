#include<stdio.h>
// Program to calculate simple interst with its input values restrictions
int main()
 {
    float principle, rate, timeperiod, interest;
    printf("\nNote: Input values must be within the following ranges\n");
    printf("\n Principle range is 100 to 1000000 Rs");
    printf("\n Rate of interest range is 5 to 10 percent");
    printf("\n Time Period range is 1 to 10 years\n");

    printf("\nEnter the principle in Rs = ");
    scanf("%f",&principle);
   
    while (principle < 100 || principle > 1000000) 
    {
        printf("\nInvalid input! \nPrinciple must be between 100 to 1000000 Rs. \nTry again = ");
        scanf("%f",&principle);
    }

    printf("\nEnter the rate of interest in percentage = ");
    scanf("%f",&rate);

    while (rate < 5 || rate > 10)
    {
        printf("\nInvalid input! \nRate of interest must be between 5 to 10 percent. \nTry again = ");
        scanf("%f",&rate);
    }

    printf("\nEnter the time period in years = ");
    scanf("%f",&timeperiod);

    while (timeperiod < 1 || timeperiod > 10) 
    {
        printf("\nInvalid input! \nTime period must be between 1 to 10 years. \nTry again = ");
        scanf("%f", &timeperiod);
    }

    interest = (principle * rate * timeperiod) / 100;

    printf("\nThe interest is: %.2f Rs\n", interest);

    return 0;
}
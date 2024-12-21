#include<stdio.h>
// program to find the discount on an item
int main()
{
    float cost, discount;

    // read the data from user
    printf("Enter the cost of an item: ");
    scanf("%f", &cost);
    
    // calculate the discount
    if (cost < 500)
    {
        printf("You are not eligible for any discount");
    }
    else
    {
        if (cost < 2000)
        {
            printf("Discount is 5%%");
            discount = 5;
        }
        else if (cost >= 2000 && cost < 4000)
        {
            printf("Discount is 10%%");
            discount = 10;
        }
        else if (cost >= 4000 && cost <= 6000)
        {
            printf("Discount is 20%%");
            discount = 20;
        }
        else if (cost > 6000)
        {
            printf("Discount is 35%%");
            discount = 35;
        }
    
    // calculate the final amount
    float amount_saved = (discount/100)*cost;
    float final_amount =  cost - amount_saved;

    //  display the result
    printf("\nThe actual amount is: $%.2f", cost);
    printf("\nThe amount saved is: $%.2f", amount_saved);
    printf("\nThe amount after discount is: $%.2f", final_amount);
    }
    return 0;
}
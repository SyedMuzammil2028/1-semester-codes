#include <stdio.h>
int main()
{
    int itemNo,quantity;
    float price,bill=0.0;

    printf("--Cafe Management System--");
    printf("\nNo# |  item  |   price");
    printf("\n 1.   Coffee   -$2.50");
    printf("\n 2.   Tea      -$2.00");
    printf("\n 3.   Sandwich -$5.50");
    printf("\n 4.   Cake     -$3.75");
    printf("\n 5.Print Bill and Exit\n");
    
    do{
        printf("\nEnter item No# ");
        scanf("%d",&itemNo);
        if(itemNo==5){
            break;
        }
        switch (itemNo)
        {
        case 1:
            price=2.50;
            break;
        case 2:
            price=2.00;
            break;
        case 3:
            price=5.50;
            break;
        case 4:
            price=3.75;
            break;
        default:
            printf("\nInvalid! item no");
            continue;
        }
        printf("Enter Quantity: ");
        scanf("%d",&quantity);
        bill += quantity * price;
        printf("\nCurrent bill: $%.2f\n",bill);

    }while (1);

    printf("\n---------BILL SUMMARY---------");
    printf("\nTotal Amount to be Paid: $%.2f",bill);
    printf("\nThank You for Visiting Cafe\n");


    return 0;
}
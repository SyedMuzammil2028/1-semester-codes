#include <stdio.h>
int main()
{
    int carNo, days, totalRentedCars = 0, totalRentDays = 0;
    float price, bill = 0.0, totalBill = 0.0;

    printf("-----Prime Car Rentals-----");
    printf("\nNo# |  Catagory  |  Rent per day");
    printf("\n 1.   Sedan       -$10.50");
    printf("\n 2.   Couple      -$6.75");
    printf("\n 3.   SUV         -$18.50");
    printf("\n 4.   Mini van    -$15.00");
    printf("\n 5.   Luxary      -$24.75");
    printf("\n 6. Exit\n");
    
    do{
        printf("\nEnter Car No# ");
        scanf("%d",&carNo);
        if(carNo==6){
            break;
        }
        switch (carNo)
        {
        case 1:
            price=10.50;
            break;
        case 2:
            price=6.75;
            break;
        case 3:
            price=18.50;
            break;
        case 4:
            price=15.00;
            break;
        case 5:
            price=24.75;
            break;
        default:
            printf("\nInvalid! Car No");
            continue;
        }
        printf("Enter Days to Rent: ");
        scanf("%d",&days);
        bill = days * price;
        printf("\nRental Bill of this Car: $%.2f\n",bill);
        
        totalRentDays += days;
        totalBill += bill;
        totalRentedCars++;

    }while (1);

    printf("\n-----RENTAL BILL SUMMARY-----");
    printf("\nCar(s) Rented: %d",totalRentedCars);
    printf("\nTotal Rental Days: %d",totalRentDays);
    printf("\nTotal Bill: $%.2f",totalBill);
    printf("\nThank You for Visiting Prime Car Rentals \n");

    return 0;
}
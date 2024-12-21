#include<stdio.h>
// program to calculate an electricity bill of customer
int main()
{
    int id,unit ;
    char name[100];
    float unitprice;
    float bill=0.0;
    float surcharge=0.0;
    
    // read data from user
    printf("Enter customer id: ");
    scanf("%d",&id);
    printf("Enter customer name: ");
    scanf("%s",name);
    printf("Enter units consumed: ");
    scanf("%d",&unit);
    
    // calculate bill
    if (unit<=199)
    {
        unitprice=16.20;
        bill=unit*unitprice;
    }
    else if (unit>=200&&unit<300)
    {
        unitprice=20.10;
        bill=unit*unitprice;
    }
    else if (unit>=300&&unit<500)
    {
        unitprice=27.10;
        bill=unit*unitprice;
    }
    else if (unit>=500)
    {
        unitprice=35.90;
        bill=unit*unitprice;
    }
 
    // Display the bill
    printf("\n\tElectricity Bill\n");
    printf("-------------------------------");
    printf("\nCustomer ID: %d",id);
    printf("\nCustomer Name: %s",name);
    printf("\nUnits Consumed: %d",unit);
    printf("\nAmount Charges @Rs.%.2f per unit: Rs.%.2f ",unitprice,bill);
    
    // Apply surcharge if the bill exceeds Rs.18000
    if ( bill>18000)
    {
       surcharge=(15.0/100)*bill;
       bill=bill+surcharge;
    }  

    printf("\nSurcharge Amount : Rs.%.2f",surcharge);
    printf("\nNet Amount Paid by the Customer: Rs.%.2f\n",bill);

    return 0;
}
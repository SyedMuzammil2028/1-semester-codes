#include<stdio.h>
// Program to find tax on employe's salary & calculte his net salary 
int main()
{
    int salary;
    float tax_rate, tax, net_salary;

    printf("Enter Salary = ");
    scanf("%d",&salary);
    printf("Enter tax rate in % = ");
    scanf("%f",&tax_rate);
    
    tax = (salary * tax_rate)/100;
    net_salary = salary - tax;

    printf("\nTax employe has to pay is %.2f",tax);
    printf("\nEmploye's net salary after paying tax is %.2f",net_salary);
    return 0;
}
//  tax = (tax_rate / 100) * salary
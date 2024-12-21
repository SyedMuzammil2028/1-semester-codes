#include<stdio.h>
// program to swap the values of two variables
int main() 
{
    int variable_01, variable_02, temperory_variable;
    printf("Enter the first integer = ");
    scanf("%d",&variable_01);
    printf("Enter the second integer = ");
    scanf("%d",&variable_02);

    temperory_variable = variable_01;
    variable_01 = variable_02;
    variable_02 = temperory_variable;

    printf("\nValue in first variable after swapping = %d",variable_01);
    printf("\nValue in second variable after swapping = %d",variable_02);
    return 0;
}
#include<stdio.h>
// program to print pattern of task 6
int main()
{
    int i=1;

    // print the top row 
    do{   
        printf("*\t*\n");  
    }while(i!=1);

    // print the middle rows
    do{   
        printf("* "); 
        if (i==5 || i==10|| i==15 || i==20)
        {
            printf("\n");
        } 
        i++;
    }while(i<=20);

    // print the bottom row
    do{   
        printf("*\t*");
    }while(i==20);       
    return 0;
}
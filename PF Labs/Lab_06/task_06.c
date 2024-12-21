#include<stdio.h>
int main()
{
    int i=1;
    
    do
    {   // print the top row
        if(i==1)
        {
        printf("*\t*\n");
        }

        // print the middle rows
        if(i>1||i<4)
        {
        printf("* * * * * \n");
        }

        // print the bottom row
        if (i==4)
        {
            printf("*\t*");
        }    
        i++;   
    }while(i<=4);
  
    return 0;
}
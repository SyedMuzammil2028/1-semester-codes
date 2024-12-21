#include <stdio.h>
// program to generates a sequence of prime numbers 
// within a given range using nested loops
int main(){
    int num, i, start, end;
    printf("Enter starting range: ");
    scanf("%d", &start);
    printf("Enter ending range: ");
    scanf("%d", &end);
    printf("Prime numbers between %d and %d are: ", start, end);
    for (num = start; num <= end; num++)
    {
        int Prime = 1;
        if (num <= 1)
        {
            Prime = 0;
        }
        else
        {
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0 && num!=2)
                {
                    Prime = 0;
                    break;
                }
            }
        }
        if(Prime){
            printf("%d ", num);
        }
    }
    return 0;}
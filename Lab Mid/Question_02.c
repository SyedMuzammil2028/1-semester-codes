#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// program to generate random die numbers
int main(){
    int rollNumber, even_count=0, odd_count=0;
    int sum = 0;
    printf("Enter number you want to roll a die: ");
    scanf("%d", &rollNumber);

    while (rollNumber < 0){
        printf("Enter number positive number: ");
        scanf("%d", &rollNumber);
    }
    int dieArray[rollNumber];
    srand(time(0));

    for (int i = 0; i < rollNumber; i++){
        int die = (rand() % 6) + 1;
        dieArray[i] = die;
        printf("\nDie Roll no %d: %d", i+1, dieArray[i]);
    }

    for (int i = 0; i < rollNumber; i++){
        sum += dieArray[i];
        if (dieArray[i] % 2 == 0){
            even_count++;
        }
        else{
            odd_count++;
        }
    }

    printf("\n\nSum of Rolled Die: %d", sum);
    printf("\nNo of even die: %d", even_count);
    printf("\nNo of odd die: %d", odd_count);

    return 0;
}
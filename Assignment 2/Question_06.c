#include <stdio.h>
int matchStickGame(int N){
    if (N % 5 == 0){
        return -1;
    }
    else{
        return N % 5;
    }
}

int main(){
    int N;
    printf("\nEnter the number of matchsticks: ");
    scanf("%d", &N);

    int result = matchStickGame(N);
    if (result == -1){
        printf("It's impossible for A to guarantee a win.");
    }
    else{
        printf("\nA should pick %d matchstick(s) to guarantee a win.", result);
    }

    return 0;
}
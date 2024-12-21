#include <stdio.h>
// Function that checks if a given integer is a prime number.
int isPrime(int num){
    if (num <= 1){
        return 0; 
    }
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0){
            return 0; 
        }
    }
    return 1; 
}

int main(){
    int num, result;

    printf("Enter number to check whether it is a prime: ");
    scanf("%d", &num);

    result = isPrime(num);

    if (result == 1){
        printf("%d is a prime number.\n", num);
    } else{
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}

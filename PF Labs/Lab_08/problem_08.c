#include <stdio.h>
// program to print diamond pattern
int main(){
    int rows, space;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    space = rows - 1;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < space; j++){
            printf(" ");
        }
        for (int j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
        space--;
    }
    
    space = 0;
    for (int i = rows - 1; i > 0; i--){
        for (int j = 0; j < space; j++){
            printf(" ");
        }
        for (int j = 0; j < i; j++){
            printf(" *");
        }
        printf("\n");
        space++;
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
// Function that reverses a given string and 
// stores the reversed string in reverseStr.
void reverseArray(char str[]){
    int length = strlen(str);
    char reverseStr[100];
    
    for (int i = 0; i < length; i++){
        reverseStr[i] = str[length - i - 1];
    }
    reverseStr[length] = '\0'; 
    printf("\nReversed string: %s\n", reverseStr);
}

int main(){
    char str[100];
    printf("Enter string: ");
    gets(str);
    
    reverseArray(str);

    return 0;
}

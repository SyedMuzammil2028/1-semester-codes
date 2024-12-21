#include<stdio.h>
int main() 
{
    char character;

    // read character form user
    printf("Enter a character: ");
    scanf("%c",&character);

    // process the character
    if (character>='A' && character<='Z') 
    {
        printf("The entered character is an uppercase alphabet");
    }
    else if (character>='a' && character<= 'z') 
    {
        printf("The entered character is a lowercase alphabet");
    }
    else if (character>='0' && character<='9') 
    {
        printf("The entered character is a digit");
    }
    else 
    {
       printf("The entered character is a special character");
    }
    return 0;
}

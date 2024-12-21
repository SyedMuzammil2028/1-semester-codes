#include <stdio.h>
#include <string.h>
int main()
{
    char source[10];
    char destination[10];
    int n;

    printf("Enter destination string: ");
    gets(destination);
    printf("Enter source string: ");
    gets(source);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    strncat(destination, source, n);
    printf("\nComnined string is: %s", destination);
    
    return 0;
}
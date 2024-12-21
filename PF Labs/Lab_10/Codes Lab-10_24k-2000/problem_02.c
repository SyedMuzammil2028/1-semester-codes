#include <stdio.h>
#include <string.h>
// Recursive function that takes a string as input
// and returns the reversed string
void reversedfunction(char str[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reversedfunction(str, start + 1, end - 1);
}

int main()
{
    char str[100];

    printf("Input the string: ");
    fgets(str, 100, stdin);

    int len = strlen(str);

    reversedfunction(str, 0, len - 1);
    printf("Reversed string: %s", str);

    return 0;
}

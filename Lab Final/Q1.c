#include <stdio.h>
#include <stdlib.h>

char* recursiveConcat(char *dest, char *src){

    if (*dest != '\0'){
        recursiveConcat(dest + 1, src);
    } else if (*src != '\0'){

        *dest = *src;

        recursiveConcat(dest + 1, src + 1);
    }
    return dest;
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Concatenated string: %s\n", recursiveConcat(str1, str2));

    return 0;
}

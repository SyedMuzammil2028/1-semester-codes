#include <stdio.h>
#include <string.h>
void compressWord(char word[])
{
    char compressed[20];
    int index = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (i == 0 || word[i] != word[i - 1])
        {
            compressed[index++] = word[i];
        }
    }
    compressed[index] = '\0';
    printf("\"%s\" ", compressed);
}

int main()
{
    char words[3][20] = {"baaaaak", "coooool", "heeeey"};
    printf("Compressed words: ");
    for (int i = 0; i < 3; i++)
    {
        compressWord(words[i]);
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
void frequency(char slogan[])
{
    int Frequency[256] = {0};

    for (int i = 0; slogan[i] != '\0'; i++)
    {
        Frequency[(int)slogan[i]]++;
    }

    printf("Character frequency for \"%s\": {", slogan);
    int printed[256] = {0};
    for (int i = 0; slogan[i] != '\0'; i++)
    {
        int ascii_value = (int)slogan[i];
        if (Frequency[ascii_value] != 0 && !printed[ascii_value])
        {
            printf("'%c': %d, ", slogan[i], Frequency[ascii_value]);
            printed[ascii_value] = 1;
        }
    }
    printf("}\n");
}

int main()
{
    char slogans[3][20] = {"buy now", "save big", "limited offer"};
    for (int i = 0; i < 3; i++)
    {
        frequency(slogans[i]);
    }
    return 0;
}

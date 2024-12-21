#include <stdio.h>
#include <string.h>

int main()
{
    char transactions[6][10] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int size = 6;
    int used[6] = {0};

    int asciiSums[6] = {0};

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < strlen(transactions[i]); j++)
        {
            sum += transactions[i][j];
        }
        asciiSums[i] = sum;
    }

    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            printf("[\"%s\"", transactions[i]);

            for (int j = i + 1; j < size; j++)
            {
                if (!used[j] && asciiSums[i] == asciiSums[j])
                {
                    printf(", \"%s\"", transactions[j]);
                    used[j] = 1;
                }
            }
            printf("]");
            if (i < size - 1)
                printf(", ");
        }
    }
    printf("]\n");

    return 0;
}

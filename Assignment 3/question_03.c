#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email)
{
    int length = strlen(email);
    int count1 = 0, count2 = 0;
    int temp;
    if (strlen(email) == 0)
    {
        printf("Empty Email, Invalid.\n");
        return 0;
    }
    for (int i = 0; i < length; i++)
    {
        if (email[i] == '@')
        {
            count1++;
            temp = i;
        }
    }
    for (int i = temp + 1; i < length; i++)
    {
        if (email[i] == '.')
        {
            count2++;
        }
    }
    if (count1 == 1 && count2 >= 1)
    {
        return 1;
    }
    else
    {
        printf("Incorrect or missing @ and .\n");
        return 0;
    }
}

int main()
{
    char *email;
    int size = 1;

    email = (char *)malloc(size * sizeof(char));
    if (email == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the E-mail: ");
    fgets(email, size, stdin);

    while (strchr(email, '\n') == NULL)
    {
        size *= 2;
        email = (char *)realloc(email, size * sizeof(char));
        if (email == NULL)
        {
            printf("Memory reallocation failed.\n");
            return 1;
        }
        fgets(email + strlen(email), size - strlen(email), stdin);
    }

    email[strcspn(email, "\n")] = '\0';

    printf("You entered: %s\n", email);
    if (validateEmail(email))
    {
        printf("\nValid Email-Address");
    }
    else
        printf("\nInvalid Email-Adress");

    free(email);

    return 0;
}
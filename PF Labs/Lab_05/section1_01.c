#include <stdio.h>
// program to categorizes a person's age into different life stages:
// Child, Teenager, Adult, and Senior.
int main()
{
    int age;

    // read the age from the user
    printf("Enter person's age: ");
    scanf("%d", &age);

    // check the age according to the life stages
    if (age > 0)
    {
        if (age < 10)
        {
            printf("Person is Child");
        }
        else if (age < 20)
        {
            printf("Person is Teenager");
        }
        else if (age < 60)
        {
            printf("Person is Adult");
        }
        else
        {
            printf("Person is Senior");
        }
    }
    else
    {
        printf("Invalid age");
    }
    return 0;
}
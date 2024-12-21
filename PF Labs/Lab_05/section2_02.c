#include <stdio.h>
// program that checks if a person is eligible
// to vote based on their age and citizenship status.
int main()
{
    int age, citizenship_status;

    // input the age and citizenship status
    printf("Enter persons age: ");
    scanf("%d", &age);

    printf("Enter person's citizenship status(1 for yes, 0 for no): ");
    scanf("%d", &citizenship_status);

    // check if the person is eligible to vote
    if (age >= 18 && citizenship_status == 1)
    {
        printf("\nPerson is eligible to vote");
    }
    else
    {
        printf("\nPerson is not eligible to vote");
    }

    return 0;
}
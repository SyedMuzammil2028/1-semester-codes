#include <stdio.h>
int main()
{
    int id, counter=0, batch, price, no_of_tickets;
    float discount, final_price;
    printf("Enter student id (XXYYYY):");
    scanf("%d", &id);
    printf("Enter no of tickets want to buy:");
    scanf("%d", &no_of_tickets);

    // Copy the id to a temporary variable for further use
    int temp_id = id;

    // Counting digits of the ID
    while (temp_id > 0) {
        temp_id = temp_id / 10;
        counter++;
    }
    // ID validation (6 digits)
    if (counter != 6) {
        printf("Invalid roll number.\n");
        return 1;
    }

    batch = id / 10000;

    if (batch == 21)
    {
        price = 1800;
    }
    else if (batch == 22)
    {
        price = 1700;
    }
    else if (batch == 23)
    {
        price = 1600;
    }
    else if (batch == 24)
    {
        price = 1500;
    }
    else
{
    printf("Invalid batch.\n");
    return 1;
}

    int id_end_digit = id % 100;
    if (id_end_digit == 10)
    {
        discount = 0.1 * price;
        final_price = price - discount;
    }
    else if (id_end_digit == 20)
    {
        discount = 0.2 * price;
        final_price = price - discount;
    }
    else if (no_of_tickets > 10)
    {
        final_price = price * (no_of_tickets - 1);
    }
    else
    {
        printf("\nYou can get only one ticket");
        final_price = price;
    }

    printf("\nThe total amount to be pay is : PKR %.2f", final_price);
    return 0;
}
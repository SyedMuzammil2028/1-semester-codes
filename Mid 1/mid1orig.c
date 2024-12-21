#include <stdio.h>

int main()
{
    int id, batch, price = 0, no_of_tickets, temp_id, counter = 0;
    float discount = 0, final_price;

    printf("Enter student ID (XXYYYY): ");
    scanf("%d", &id);

    printf("Enter number of tickets you want to buy: ");
    scanf("%d", &no_of_tickets);

    // Copy the id to a temporary variable for further use
    temp_id = id;

    // Counting digits of the ID
    while (temp_id > 0)
    {
        temp_id = temp_id / 10;
        counter++;
    }

    // ID validation (6 digits)
    if (counter != 6)
    {
        printf("Invalid roll number.\n");
        return 1;
    }

    // Extracting the batch (first two digits)
    batch = id / 10000;

    // Batch validation and setting the price
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

    // Extracting the last two digits of the ID for discount checks
    int id_end_digit = id % 100;

    // Checking discount conditions
    if (id_end_digit == 10)
    {
        discount = 0.10; // 10% discount
    }
    else if (id_end_digit == 20)
    {
        discount = 0.20; // 20% discount
    }

    // Bulk purchase rule: 1 ticket free if more than 10 tickets and no lucky number discount
    if (no_of_tickets > 10 && discount == 0)
    {
        no_of_tickets--; // One ticket free
    }

    // Calculate total price
    final_price = price * no_of_tickets;

    // Apply discount if applicable
    if (discount > 0)
    {
        final_price = final_price - (final_price * discount);
    }

    // Output the final price
    printf("The total amount to be paid is: PKR %.2f\n", final_price);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Create a banking system using structures to store account holder details and transaction
// history. Implement the following features:
// • Add new accounts.
// • Perform deposits and withdrawals.
// • Display the account with the highest balance.
// • Save and retrieve the account data from a binary file.
const char *accountsdb = "accounts.bin";

struct account
{
    char account_holder[50];
    char account_number[15];
    float balance;
    char transaction_history[5][50];
};

struct account acc[100];
int count = 0;

void add_account();
void deposit_withdraw();
void display_highest_balance();
void save_accounts();
void load_accounts();

int main()
{
    int choice = 0;

    load_accounts();

    while (choice != 5)
    {
        printf("\n====== Banking System Menu ======\n");
        printf("1. Add New Account\n");
        printf("2. Perform Deposit/Withdrawal\n");
        printf("3. Display Account with Highest Balance\n");
        printf("4. Save Account Data\n");
        printf("5. Exit the Program\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_account();
            break;

        case 2:
            deposit_withdraw();
            break;

        case 3:
            display_highest_balance();
            break;

        case 4:
            save_accounts();
            break;

        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid Input. Please try again.\n");
            break;
        }
    }

    return 0;
}

void add_account()
{
    printf("\n==== ADD NEW ACCOUNT ====\n");
    printf("Account Holder Name: ");
    scanf(" %s", acc[count].account_holder);
    printf("Account Number: ");
    scanf("%s", acc[count].account_number);
    printf("Initial Balance: ");
    scanf("%f", &acc[count].balance);

    for (int i = 0; i < 5; i++)
    {
        strcpy(acc[count].transaction_history[i], "NULL... No Transaction made yet");
    }

    printf("Account created successfully...\n");
    count++;
}

void deposit_withdraw()
{
    char acc_number[15];
    float amount;
    int found = 0;

    printf("\n==== DEPOSIT / WITHDRAW ====\n");
    printf("Enter Account Number: ");
    scanf("%s", acc_number);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(acc[i].account_number, acc_number) == 0)
        {
            found = 1;
            printf("Account Found: %s having Balance : %f \n", acc[i].account_holder, acc[i].balance);
            printf("Enter 1 to Deposit and 2 to Withdraw: ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1)
            {
                printf("Enter Deposit Amount: ");
                scanf("%f", &amount);
                acc[i].balance += amount;

                snprintf(acc[i].transaction_history[4], 50, "Deposited: %.2f", amount);
                for (int j = 0; j < 4; j++)
                {
                    strcpy(acc[i].transaction_history[j], acc[i].transaction_history[j + 1]);
                }

                printf("Amount Deposited Successfully. New Balance: %.2f\n", acc[i].balance);
            }
            else if (choice == 2)
            {
                printf("Enter Withdrawal Amount: ");
                scanf("%f", &amount);
                if (amount > acc[i].balance)
                {
                    printf("Insufficient Balance. Transaction Failed.\n");
                }
                else
                {
                    acc[i].balance -= amount;

                    // Update transaction history
                    snprintf(acc[i].transaction_history[4], 50, "Withdrew: %.2f", amount);
                    for (int j = 0; j < 4; j++)
                    {
                        strcpy(acc[i].transaction_history[j], acc[i].transaction_history[j + 1]);
                    }

                    printf("Amount Withdrawn Successfully. New Balance: %.2f\n", acc[i].balance);
                }
            }
            else
            {
                printf("Invalid Option. Try Again.\n");
            }
            break;
        }
    }

    if (found == 0)
    {
        printf("Account Not Found.\n");
    }
}

void display_highest_balance()
{
    if (count == 0)
    {
        printf("\nNo accounts available.\n");
        return;
    }

    int max = 0;
    for (int i = 1; i < count; i++)
    {
        if (acc[i].balance > acc[max].balance)
        {
            max = i;
        }
    }

    printf("\n==== ACCOUNT WITH HIGHEST BALANCE ====\n");
    printf("Account Holder: %s\n", acc[max].account_holder);
    printf("Account Number: %s\n", acc[max].account_number);
    printf("Balance: %.2f\n", acc[max].balance);
}

void save_accounts()
{
    FILE *file = fopen(accountsdb, "wb");
    if (file == NULL)
    {
        printf("Unable to open file for saving.\n");
        return;
    }

    fwrite(&acc, sizeof(struct account), count, file);
    fclose(file);
    printf("Account data saved successfully to file.\n");
}

void load_accounts()
{
    FILE *file = fopen(accountsdb, "rb");
    if (file == NULL)
    {
        printf("No existing account data found.\n");
        return;
    }

    count = fread(&acc, sizeof(struct account), 100, file);
    fclose(file);
    printf("Loaded %d account(s) from file.\n", count);
}

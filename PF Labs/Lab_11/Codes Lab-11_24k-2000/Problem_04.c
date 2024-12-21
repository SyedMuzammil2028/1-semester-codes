#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Write a program to store information about books in a library using a binary file.
// Implement the following operations:
// Add new books.
// Search for a book by title or author.
// Display all books sorted by year of publication.

const char *booksdb = "books.txt";

struct library
{
    char title[30];
    char author[20];
    char genre[15];
    char pub_date[15];
};

struct library b[100];
int b_count = 0;

void add_data()
{
    printf("==== INPUT BOOK DATA ====\n");
    printf("Book Title: ");
    scanf(" %s", b[b_count].title);
    printf("Book Author: ");
    scanf(" %s", b[b_count].author);
    printf("Book Genre: ");
    scanf(" %s", b[b_count].genre);
    printf("Publishing Date (YYYY-MM-DD): ");
    scanf(" %s", b[b_count].pub_date);

    FILE *file = fopen(booksdb, "a");
    if (file == NULL)
    {
        printf("Can't open file.... Try again...\n");
        return;
    }

    fwrite(&b[b_count], sizeof(struct library), 1, file);

    fclose(file);
    printf("Book data added successfully!\n");
    b_count++;
}

void sort_books()
{
    struct library temp;
    for (int i = 0; i < b_count - 1; i++)
    {
        for (int j = 0; j < b_count - i - 1; j++)
        {
            if (strcmp(b[j].pub_date, b[j + 1].pub_date) > 0)
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    printf("Books sorted by publication date.\n");
}

void view_records()
{
    char search[30];
    int flag = 0;

    printf("Enter the title or author of the book you want to search: ");
    scanf(" %s", search);

    FILE *file = fopen(booksdb, "r");
    if (file == NULL)
    {
        printf("The file does not exist...\n");
        return;
    }

    while (fread(&b[b_count], sizeof(struct library), 1, file))
    {
        b_count++;
    }
    fclose(file);

    for (int i = 0; i < b_count; i++)
    {
        if (strcmp(b[i].title, search) == 0 || strcmp(b[i].author, search) == 0)
        {
            flag = 1;
            printf("\n\n>>>> Book Record Found!!! \n");
            printf("--- Book Details ---\n");
            printf("Book Title: %s\n", b[i].title);
            printf("Book Author: %s\n", b[i].author);
            printf("Book Genre: %s\n", b[i].genre);
            printf("Publication Date: %s\n", b[i].pub_date);
            break;
        }
    }

    if (!flag)
    {
        printf("No book record found with the search: %s\n", search);
    }
}

void display_books()
{
    FILE *file = fopen(booksdb, "r");
    if (file == NULL)
    {
        printf("The file does not exist...\n");
        return;
    }

    b_count = 0;
    while (fread(&b[b_count], sizeof(struct library), 1, file))
    {
        b_count++;
    }
    fclose(file);

    sort_books();

    printf("==== LIST OF BOOKS ====\n");
    for (int i = 0; i < b_count; i++)
    {
        printf("\n--- Book %d ---\n", i + 1);
        printf("Title: %s\n", b[i].title);
        printf("Author: %s\n", b[i].author);
        printf("Genre: %s\n", b[i].genre);
        printf("Publication Date: %s\n", b[i].pub_date);
    }
}

int main()
{
    int choice = 0;

    while (choice != 4)
    {
        printf("\n====== Library Menu ======\n");
        printf("1. Add Book Data\n");
        printf("2. Search for a Book\n");
        printf("3. Display All Books\n");
        printf("4. Exit the Program\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_data();
            break;

        case 2:
            view_records();
            break;

        case 3:
            display_books();
            break;

        case 4:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid Input. Please try again.\n");
            break;
        }
    }

    return 0;
}

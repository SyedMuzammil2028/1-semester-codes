#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Write a program to manage an inventory of products: Use structures to store product
// details (ID, name, price, stock quantity). Implement the following:
// Add new products.
// Search for a product by name or ID.
// Update stock quantity after a sale.
// Save and load inventory data from a binary file.

struct products
{
    char product_id[15];
    char product_name[40];
    int stock_quantity;
};

const char *productsdb = "products.txt";

int count = 0;
struct products *p = NULL;

void add_products()
{
    count++;
    p = realloc(p, count * sizeof(struct products));

    if (p == NULL)
    {
        printf("There was an issue with memory allocation...\n");
        return;
    }

    printf("==== ADD NEW PRODUCT ====\n");
    printf("Enter Product ID: ");
    scanf("%s", p[count - 1].product_id);
    printf("Enter Product Name: ");
    scanf("%s", p[count - 1].product_name);
    printf("Enter Stock Quantity: ");
    scanf("%d", &p[count - 1].stock_quantity);

    printf("Product Data Added Successfully...\n");
}

void save_data()
{
    FILE *file = fopen(productsdb, "wb");

    if (file == NULL)
    {
        printf("Error opening the file...\n");
        return;
    }

    fwrite(p, sizeof(struct products), count, file);
    fclose(file);

    printf("Product Data Saved Successfully...\n");
}

void load_data()
{
    FILE *file = fopen(productsdb, "rb");

    if (file == NULL)
    {
        printf("Error opening the file...\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    count = file_size / sizeof(struct products);
    p = realloc(p, count * sizeof(struct products));

    if (p == NULL)
    {
        printf("Memory allocation failed while loading data...\n");
        fclose(file);
        return;
    }

    fread(p, sizeof(struct products), count, file);
    fclose(file);

    printf("Product Data Loaded Successfully...\n");
}

void search_products()
{
    if (count == 0)
    {
        printf("No products available to search.\n");
        return;
    }

    char search_key[40];
    printf("Enter Product Name or ID to Search: ");
    scanf("%s", search_key);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(p[i].product_id, search_key) == 0 || strcmp(p[i].product_name, search_key) == 0)
        {
            printf("Product Found: ID=%s, Name=%s, Stock=%d\n", p[i].product_id, p[i].product_name, p[i].stock_quantity);
            found = 1;
        }
    }

    if (found != 1)
    {
        printf("Product not found.\n");
    }
}

void view_updated()
{
    if (count == 0)
    {
        printf("No products available to display.\n");
        return;
    }

    printf("==== VIEW PRODUCTS ====\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID: %s, Name: %s, Stock: %d\n", p[i].product_id, p[i].product_name, p[i].stock_quantity);
    }
}

int main()
{
    int choice = 0;

    while (choice != -1)
    {
        printf("\n==== Product Management Menu ====\n");
        printf("1. Add New Product\n");
        printf("2. Search for Product by Name or ID\n");
        printf("3. View All Products\n");
        printf("4. Load Product Data from File\n");
        printf("5. Save Product Data to File\n");
        printf("Enter your choice (-1 to exit): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_products();
            break;

        case 2:
            search_products();
            break;

        case 3:
            view_updated();
            break;

        case 4:
            load_data();
            break;

        case 5:
            save_data();
            break;

        case -1:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid Input... Try again...\n");
            break;
        }
    }

    free(p);
    return 0;
}

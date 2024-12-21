#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ***speciessupply;
    int numberofspecies;
    int numberofsupplies, choice;
    int sizeofsupplies = 20;
    printf("Enter The number of species:\n");
    scanf("%d", &numberofspecies);
    printf("Enter The number of supplies:\n");
    scanf("%d", &numberofsupplies);

    speciessupply = (char *)malloc(numberofspecies * sizeof(char **));
    // Initializing The Inventory:
    for (int i = 0; i < numberofspecies; i++)
    {
        speciessupply[i] = (char *)malloc(numberofsupplies * sizeof(char));
        for (int j = 0; j < numberofsupplies; j++)
        {
            speciessupply[i][j] = (char *)malloc(sizeofsupplies * sizeof(char));
        }
    }
    while (1)
    {
        printf("Welcome To Pets In Heart:\n");
        printf("1.Add Supplies.\n");
        printf("2.Update Supply.\n");
        printf("3.Remove Species.\n");
        printf("4.Display.\n");
        printf("5.Exit.\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            // Adding supplies:
            for (int i = 0; i < numberofspecies; i++)
            {
                for (int j = 0; j < numberofsupplies; j++)
                {
                    fflush(stdin);
                    printf("Enter Supply %d for specie %d: \n", j + 1, i + 1);
                    fgets(speciessupply[i][j], sizeofsupplies, stdin);
                    speciessupply[i][j][strcspn(speciessupply[i][j], "\n")] = '\0';
                }
            }
            break;
        }
        case 2:
        {
            // Update Supplies:
            int update1 = 0, update2 = 0;
            printf("Enter The specie you want to update the supply for:\n");
            scanf("%d", &update1);
            printf("Enter the supply you want to update:\n");
            scanf("%d", &update2);

            printf("Enter The updated supply:\n");
            fflush(stdin);
            fgets(speciessupply[update1 - 1][update2 - 1], sizeofsupplies, stdin);
            speciessupply[update1 - 1][update2 - 1][strcspn(speciessupply[update1 - 1][update2 - 1], "\n")] = '\0';
            break;
        }
        case 3:
        {
            // Remove species:
            int deleteindex = 0;
            printf("Enter the spicie you want to delete:\n");
            scanf("%d", &deleteindex);

            if (deleteindex >= 1 && deleteindex <= numberofspecies)
            {
                for (int i = 0; i < numberofsupplies; i++)
                {
                    free(speciessupply[deleteindex - 1][i]);
                }
                free(speciessupply[deleteindex - 1]);
                for (int i = deleteindex - 1; i < numberofspecies - 1; i++)
                {
                    speciessupply[i] = speciessupply[i + 1];
                }
                speciessupply[numberofspecies - 1] = NULL;
                numberofspecies--;
            }
            else
            {
                printf("Invalid species index!\n");
            }
            break;
        }
        case 4:
        {
            // Display:
            for (int i = 0; i < numberofspecies; i++)
            {
                printf("Specie %d:\t", i + 1);
                for (int j = 0; j < numberofsupplies; j++)
                {
                    printf("%s ", speciessupply[i][j]);
                }
                printf("\n");
            }
        }
        break;
        case 5:
            printf("\n\t\t\tPets In Heart. Signing Out!");
            return 0;
        default:
            printf("Invalid Choice.\n");
            break;
        }
    }

    // Deallocation:
    for (int i = 0; i < numberofspecies; i++)
    {
        for (int j = 0; j < numberofsupplies; j++)
        {
            free(speciessupply[i][j]);
        }
        free(speciessupply[i]);
    }
    free(speciessupply);

    return 0;
}
#include <stdio.h>
#include <string.h>
// Program  that  use  a  structure  to  hold  information  about  movies,
// such  as  title, genre, director, release year, and rating.
typedef struct movies
{
    char title[20];
    char genre[20];
    char director[20];
    char release_date[20];
    float rating;
} Movies;

int main()
{
    int n;
    int choice = 0;
    char search_genre[20];
    printf("How many movies do you want to store? : ");
    scanf("%d", &n);
    Movies s[n];

    for (int i = 0; i < n; i++)
    {
        printf("-----Movie %d:-----\n", i + 1);
        printf("Enter the title of the movie: ");
        scanf(" %[^\n]s", s[i].title);
        printf("Enter the genre of the movie: ");
        scanf(" %[^\n]s", s[i].genre);
        printf("Enter the director of the movie: ");
        scanf(" %[^\n]s", s[i].director);
        printf("Enter the release date of the movie: ");
        scanf(" %[^\n]s", s[i].release_date);
        printf("Enter the rating of the movie: ");
        scanf("%f", &s[i].rating);
    }
    while (choice != 3)
    {
        printf("\n----Menu-----\n");
        printf("1. Search by genre\n");
        printf("2. Display all movie details\n");
        printf("3. Exit\n");
        printf("Choose one of the following options: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the genre of the movie you want to search: ");
            scanf(" %[^\n]s", search_genre);
            int found = 0;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(search_genre, s[i].genre) == 0)
                {
                    printf("\nTitle: %s\n", s[i].title);
                    printf("Genre: %s\n", s[i].genre);
                    printf("Director: %s\n", s[i].director);
                    printf("Release Date: %s\n", s[i].release_date);
                    printf("Rating: %.1f\n", s[i].rating);
                    found = 1;
                }
            }
            if (found != 0)
            {
                printf("No movies of the genre '%s' found.\n", search_genre);
            }
            break;
        }
        case 2:
            for (int i = 0; i < n; i++)
            {
                printf("\nMovie %d:\n", i + 1);
                printf("Title: %s\n", s[i].title);
                printf("Genre: %s\n", s[i].genre);
                printf("Director: %s\n", s[i].director);
                printf("Release Date: %s\n", s[i].release_date);
                printf("Rating: %.1f\n", s[i].rating);
            }
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}
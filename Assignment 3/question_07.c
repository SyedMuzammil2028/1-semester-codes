#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Content
{
    char title[100];
    float rating;
    int runtime;
    char encoding_format[50];
};

struct UserProfile
{
    double *engagementScores;
    double **devicePreferences;
    int numDevices;
};

void input_content_metadata(struct Content **contentMatrix, int num_categories, int *num_content_per_category)
{
    for (int i = 0; i < num_categories; i++)
    {
        printf("\nEnter the number of content items in category%d:", i + 1);
        scanf("%d", &num_content_per_category[i]);
        contentMatrix[i] = (struct Content *)malloc(num_content_per_category[i] * sizeof(struct Content));
        for (int j = 0; j < num_content_per_category[i]; j++)
        {
            printf("\nContent%d in Category%d:\n", j + 1, i + 1);
            printf("Title:");
            scanf(" %[^\n]", contentMatrix[i][j].title);
            printf("Rating(out of 10):");
            scanf("%f", &contentMatrix[i][j].rating);
            printf("Runtime(in minutes):");
            scanf("%d", &contentMatrix[i][j].runtime);
            printf("Encoding Format:");
            scanf("%s", contentMatrix[i][j].encoding_format);
        }
    }
}

void input_engagement_matrix(struct UserProfile *users, double **engagementMatrix, int num_users, int num_categories)
{
    for (int i = 0; i < num_users; i++)
    {
        printf("\nEnter engagement scores for User%d:\n", i + 1);
        for (int j = 0; j < num_categories; j++)
        {
            printf("Category%d:", j + 1);
            scanf("%lf", &engagementMatrix[i][j]);
        }
        users[i].engagementScores = engagementMatrix[i];
    }
}

void input_device_preferences(struct UserProfile *users, int num_users)
{
    for (int i = 0; i < num_users; i++)
    {
        printf("\nEnter the number of devices for User%d:", i + 1);
        scanf("%d", &users[i].numDevices);
        users[i].devicePreferences = (double **)malloc(users[i].numDevices * sizeof(double *));
        for (int j = 0; j < users[i].numDevices; j++)
        {
            users[i].devicePreferences[j] = (double *)malloc(3 * sizeof(double));
            printf("\nDevice%d for User%d:\n", j + 1, i + 1);
            printf("Resolution(pixels):");
            scanf("%lf", &users[i].devicePreferences[j][0]);
            printf("Playback Position(seconds):");
            scanf("%lf", &users[i].devicePreferences[j][1]);
            printf("Bandwidth Usage(Mbps):");
            scanf("%lf", &users[i].devicePreferences[j][2]);
        }
    }
}

void display_engagement_matrix(struct UserProfile *users, double **engagementMatrix, int num_users, int num_categories)
{
    printf("\n=====User Engagement Scores=====\n");
    for (int i = 0; i < num_users; i++)
    {
        printf("User%d:\n", i + 1);
        for (int j = 0; j < num_categories; j++)
        {
            printf("Category%d:%.2lf\n", j + 1, engagementMatrix[i][j]);
        }
    }
}

void display_device_preferences(struct UserProfile *users, int num_users)
{
    printf("\n=====Device Preferences=====\n");
    for (int i = 0; i < num_users; i++)
    {
        printf("User%d:\n", i + 1);
        for (int j = 0; j < users[i].numDevices; j++)
        {
            printf("Device%d:\n", j + 1);
            printf("Resolution:%.2lf pixels\n", users[i].devicePreferences[j][0]);
            printf("Playback Position:%.2lf seconds\n", users[i].devicePreferences[j][1]);
            printf("Bandwidth Usage:%.2lf Mbps\n", users[i].devicePreferences[j][2]);
        }
    }
}

void display_content_metadata(struct Content **contentMatrix, int num_categories, int *num_content_per_category)
{
    printf("\n=====Content Metadata=====\n");
    for (int i = 0; i < num_categories; i++)
    {
        printf("Category%d:\n", i + 1);
        for (int j = 0; j < num_content_per_category[i]; j++)
        {
            printf("Content%d:\n", j + 1);
            printf("Title:%s\n", contentMatrix[i][j].title);
            printf("Rating:%.2f\n", contentMatrix[i][j].rating);
            printf("Runtime:%d minutes\n", contentMatrix[i][j].runtime);
            printf("Encoding Format:%s\n", contentMatrix[i][j].encoding_format);
        }
    }
}

int main()
{
    int num_users, num_categories;

    printf("Enter the number of users:");
    scanf("%d", &num_users);
    printf("Enter the number of categories:");
    scanf("%d", &num_categories);

    double **engagementMatrix = (double **)malloc(num_users * sizeof(double *));
    for (int i = 0; i < num_users; i++)
    {
        engagementMatrix[i] = (double *)malloc(num_categories * sizeof(double));
    }

    struct UserProfile *users = (struct UserProfile *)malloc(num_users * sizeof(struct UserProfile));

    struct Content **contentMatrix = (struct Content **)malloc(num_categories * sizeof(struct Content *));
    int *num_content_per_category = (int *)malloc(num_categories * sizeof(int));

    input_engagement_matrix(users, engagementMatrix, num_users, num_categories);
    input_device_preferences(users, num_users);
    input_content_metadata(contentMatrix, num_categories, num_content_per_category);

    display_engagement_matrix(users, engagementMatrix, num_users, num_categories);
    display_device_preferences(users, num_users);
    display_content_metadata(contentMatrix, num_categories, num_content_per_category);

    for (int i = 0; i < num_users; i++)
    {
        for (int j = 0; j < users[i].numDevices; j++)
        {
            free(users[i].devicePreferences[j]);
        }
        free(users[i].devicePreferences);
    }
    for (int i = 0; i < num_categories; i++)
    {
        free(contentMatrix[i]);
    }
    for (int i = 0; i < num_users; i++)
    {
        free(engagementMatrix[i]);
    }
    free(users);
    free(contentMatrix);
    free(num_content_per_category);
    free(engagementMatrix);

    return 0;
}
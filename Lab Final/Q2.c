#include <stdio.h>
#include <stdlib.h>
struct record{
    int teamid ;
    char name[50];
    int totalwin;
    int totallose;
};

int main()
{
    int n,n2;
    struct record *r;
    printf("\nenter size");
    scanf("%d",&n);
    r=(struct record*)calloc(n,sizeof(struct record));
    if(r==NULL)
    {
        printf("\nmemory not allocated");
        exit(1);
    }
    
    for(int i=0;i<n;i++){
        printf("\nEnter data:");
        printf("\nEnter team id: ");
        scanf("%d",&r[i].teamid);
        printf("\nEnter name: ");
        scanf(" %[^\n]",r[i].name);
        printf("\ntotalwin: ");
        scanf("%d",&r[i].totalwin);
        printf("\ntotallose: ");
        scanf("%d",&r[i].totallose);
    }
    
    printf("\nEntetr th new size: ");{
        scanf("%d",&n2);
    }

    r=(struct record*)realloc( r, n2*sizeof(struct record));
    for(int i=0;i<n2;i++){
        printf("\nEnter data:");
        printf("\nEnter team id: ");
        scanf("%d",&r[i].teamid);
        printf("\nEnter name: ");
        scanf(" %[^\n]",r[i].name);
        printf("\ntotalwin: ");
        scanf("%d",&r[i].totalwin);
        printf("\ntotallose: ");
        scanf("%d",&r[i].totallose);
    }

    return 0;
}
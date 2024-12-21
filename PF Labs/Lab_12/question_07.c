#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define students 5

int i;
int j;

struct Student{
    char name[50];
    int age;
    float score;

};

int main() {
    struct Student *s;

    s = (struct Student*)malloc(students * sizeof(struct Student));

    printf("\t\tStudent Details\n");

    for(i=0 ; i<students ; i++) {
    	
        printf("\nStudent %d Detail:\n\n", i+1);
        
        printf("Name of Student %d : ", i+1);
        gets((s+i)->name);
        
        printf("Age of Student %d : ", i+1);
        scanf("%d", &(s+i)->age);
        
        printf("Score of Student %d : ", i+1);
        scanf("%f", &(s+i)->score);
        getchar();
        
    }

    for(i=0; i<students; i++){
        printf("\nStudent %d Detail\n\n", i+1);
        
        printf("Name of Student : %s\n",  (s+i)->name);
        
        printf("Age of Student : %d\n",  (s+i)->age);
        
        printf("Score of Student : %.2f\n", (s+i)->score);

    }
 
    return 0;
}

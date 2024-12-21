#include<stdio.h>
// progarm to allocated a seat based on student fsc & NTS marks 
// at different department of different university.
int main() 
{
    int fscmarks, ntsmarks;

    // get student data
    printf("Enter your F.Sc marks: ");
    scanf("%d",&fscmarks);

    printf("Enter your NTS marks: ");
    scanf("%d",&ntsmarks);

    // identify eligibility of student in university and department according to marks
    if (fscmarks>70) 
     {
        if (ntsmarks>=70) 
        {
         printf("Oxford University: IT\n");
        } else if (ntsmarks>=60) 
        {
         printf("Oxford University: Electronics\n");
        } else if (ntsmarks>=50) 
        {
         printf("Oxford University: Telecommunications\n");
        } else 
        {
         printf("No suitable department at Oxford University\n");
        }
     } 
     else if (fscmarks>=60 && fscmarks<=70) 
     {
        if (ntsmarks>=50) 
        {
         printf("MIT: IT\n");
        } else 
        {
         printf("No suitable department at MIT\n");
        }
     } 
     else if (fscmarks>=50 && fscmarks<=59) 
     {
        if (ntsmarks>=50) 
        {
         printf("MIT: Chemical\n");
        } else 
        {
         printf("No suitable department at MIT\n");
        }
     } 
     else if (fscmarks>=40 && fscmarks<50) 
     {
        if (ntsmarks>=50) 
        {
         printf("MIT: Computer\n");
        } else 
        {
         printf("No suitable department at MIT\n");
        }
     } 
     else 
     {
      printf("No suitable department available based on the provided marks\n");
     }

    return 0;
}

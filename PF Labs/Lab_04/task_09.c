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
    // Identify eligibility for Oxford University
    if (fscmarks>70)
  {
    if (ntsmarks>=70) 
    {
     printf("Congratulations! You are eligible for IT at Oxford University\n");
    } 
    else if (ntsmarks>=60) 
    {
     printf("Congratulations! You are eligible for Electronics at Oxford University\n");
    } 
    else if (ntsmarks>=50) 
    {
     printf("Congratulations! You are eligible for Telecommunications at Oxford University\n");
    } 
    else 
    {
     printf("No suitable department avaliable at Oxford University\n");
    }
  }
  // Identify eligibility for MIT
   else if (fscmarks>=60 && fscmarks<=70 && ntsmarks>=50) 
    {
     printf("Congratulations! You are eligible for IT at MIT\n");
    } 
    else if (fscmarks>=50 && fscmarks<=59 && ntsmarks>=50) 
    {
     printf("Congratulations! You are eligible for Chemical at MIT\n");
    }   
    else if (fscmarks>=40 && fscmarks<50 && ntsmarks>=50) 
    {
     printf("Congratulations! You are eligible for Computer at MIT\n");
    }  
    else 
    {
     printf("No suitable department avaliable at MIT University\n");
    }
    return 0;
}
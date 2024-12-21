#include <stdio.h>
// program to calculate grade of student base on academics performance
int main()
{
    float attendance, assignment_score, exam_score, final_score;

    printf("\nFinal Grade Calculator");
    printf("\n---------------------\n");

    // input attendance, assignment score, and exam result from the user
    printf("Enter attendance percentage (0-100): ");
    scanf("%f", &attendance);

    printf("Enter assignment score (0-100): ");
    scanf("%f", &assignment_score);

    printf("Enter exam score (0-100): ");
    scanf("%f", &exam_score);

    // check if input data match the passing range
    if (attendance >= 75)
    {
        if (assignment_score >= 50)
        {
            if (exam_score >= 50)
            {
                // calculate final score with weighted sum formula
                final_score = (attendance * 0.20) + (assignment_score * 0.30) + (exam_score * 0.50);
                printf("\nAverage academics score: %.2f\n", final_score);

                // mark the grade according to the final score

                if (final_score >= 90)
                {
                    printf("Final grade: A");
                }
                else if (final_score >= 80)
                {
                    printf("Final grade: B");
                }
                else if (final_score >= 70)
                {
                    printf("Final grade: C");
                }
                else if (final_score >= 60)
                {
                    printf("Final grade: D");
                }
                else
                {
                    printf("Final grade: F");
                }
            }
            else
            {
                printf("Status: Fail due to Low final grade");
            }
        }
        else
        {
            printf("Status: Fail due to Exam score is too low");
        }
    }
    else
    {
        printf("Status: Fail due to Attendance is too short");
    }

    return 0;
}
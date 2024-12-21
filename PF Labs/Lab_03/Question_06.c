#include<stdio.h>
// Progerm to calculate a slope of two points.
int main()
{
    float x1 = 5, y1 = 4, x2 = 3, y2 = 2;
    float slope = (y2 - y1) / (x2 - x1);

    printf("\nThe slope of the line passing through points (5,4) and (3,2) is %.3f", slope);
    return 0;
}
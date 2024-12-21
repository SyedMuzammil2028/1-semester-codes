#include <stdio.h>
#include <math.h>
// structure to represent a point in 2D space with x and y coordinates. Implement
// functions to calculate the distance between two points and to check if a point lies within
// a specific rectangular boundary
typedef struct
{
    float x;
    float y;
} point;

float calc_dis(point p1, point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int boundary_check(point p, point topleft_corner, point bottomright_corner)
{
    return (p.x >= topleft_corner.x && p.x <= bottomright_corner.x &&
            p.y >= bottomright_corner.y && p.y <= topleft_corner.y);
}

int main()
{
    point p1, p2;
    point topleft_corner = {0, 5};
    point bottomright_corner = {5, 0};

    printf("Input x co-ordinate of point p1: ");
    scanf("%f", &p1.x);
    printf("Input y co-ordinate of point p1: ");
    scanf("%f", &p1.y);
    printf("Input x co-ordinate of point p2: ");
    scanf("%f", &p2.x);
    printf("Input y co-ordinate of point p2: ");
    scanf("%f", &p2.y);

    printf("Distance between p1 and p2: %.2f\n", calc_dis(p1, p2));
    if (boundary_check(p1, topleft_corner, bottomright_corner))
    {
        printf("Point 1 is within boundary.\n");
    }
    else
    {
        printf("Point 1 is not within boundary.\n");
    }
    
    if (boundary_check(p2, topleft_corner, bottomright_corner))
    {
        printf("Point 2 is within boundary.\n");
    }
    else
    {
        printf("Point 2 is not within boundary.\n");
    }

    return 0;
}
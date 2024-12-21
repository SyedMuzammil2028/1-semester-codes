#include <stdio.h>
int main()
{
    float speed_kmh;
    printf("  Speed convertor\n");
    printf("Enter speed in km/h: ");
    scanf("%f", &speed_kmh);

    float speed_mph = speed_kmh * 3600 * 0.621371;
    
    printf("%.2f km/s is %.2f mph\n", speed_kmh, speed_mph);
    return 0;
}
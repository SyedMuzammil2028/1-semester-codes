#include <stdio.h>
#define MAX_TEMP 50
//  program with a constant that defines the maximum allowable temperature (in Celsius
void checkTemperature(float temp)
{
    static int count = 0; 
    if (temp > MAX_TEMP)
        count++;
    printf("Temperature: %.2f, Exceeded Limit: %d times\n", temp, count);
}

int main()
{
    int size;

    printf("Enter the number of temperatures: ");
    scanf("%d", &size);

    float temperatures[size];
    printf("Enter the temperatures:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Temperature %d: ", i + 1);
        scanf("%f", &temperatures[i]);
    }

    for (int i = 0; i < size; i++)
    {
        checkTemperature(temperatures[i]);
    }
    return 0;
}

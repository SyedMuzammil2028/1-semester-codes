#include <stdio.h>
// Program to calculate total fuel consumed & its costs when fuel average of a car is given.
int main()
{
    float fuel_avg, fuelcost_trip_forth = 0, fuelcost_trip_back = 0, total_fuel_cost = 0, total_fuel_consumed = 0;
    printf("Enter the car's fuel average (km/liter) = ");
    scanf("%f", &fuel_avg);
    if (fuel_avg > 0)
    {
        int oneway_distance = 1207;
        int total_distance = oneway_distance * 2;
        // int fuel_price_forth = 118;
        // int fuel_price_back = 123;

        total_fuel_consumed = total_distance / fuel_avg;

        fuelcost_trip_forth = (oneway_distance / fuel_avg) * 118;
        fuelcost_trip_back = (oneway_distance / fuel_avg) * 123;
        total_fuel_cost = fuelcost_trip_forth + fuelcost_trip_back;
        // total_fuel_cost = (fuel_price_forward + fuel_price_return) / 2 * total_fuel_consumed; 

        printf("\nTotal Fuel counsumed in both trips is %.2f liters", total_fuel_consumed);
        printf("\nTotal fuel cost for two way trip is %.2f Rs", total_fuel_cost);
    }
    else
    {
        printf("\nInvalid input! Please enter a correct fuel average.");
    }
    return 0;
}
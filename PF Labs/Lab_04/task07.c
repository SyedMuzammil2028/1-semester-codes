#include<stdio.h>
// proigram to control the brightness of the mobile phone according to the surrounding light.
int main() 
{
  int lightIntensity;

 // read the light intensity from the light sensor
  printf("Enter the light intensity value (0-1000): ");
  scanf("%d", &lightIntensity);

 // process the light intensity value
  if (lightIntensity>500 && lightIntensity<=1000) 
  {
    printf("\nMode: Sunshine --> Brightness set to high");
    printf("\nThe brightness of the mobile phone is set to 100%%");
  }
   else if (lightIntensity>=100 && lightIntensity<=500) 
  {
    printf("\nMode: Lighting --> Brightness set to medium");
    printf("\nThe brightness of the mobile phone is set to 50%%");
  }
   else if (lightIntensity>=0 && lightIntensity<=100) 
  {
    printf("\nMode: Evening --> Brightness set to low");
    printf("\nThe brightness of the mobile phone is set to 10%%");
  }
   else 
  {
    printf("\nInvalid light intensity value! Check the sensor.");
  }
  return 0;
}
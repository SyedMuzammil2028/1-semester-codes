#include <stdio.h>
// progarm to find digits sum
int main()
{
  int num, lastnum, sum = 0;
  printf("Digit Sum Calculator\n");  
  printf("Enter a number: ");
  scanf("%d", &num);

  while (num > 0)
  {
    lastnum = num % 10;
    sum += lastnum;
    num /= 10;
  }
  printf("Sum of digits: %d\n", sum);
  return 0;
}
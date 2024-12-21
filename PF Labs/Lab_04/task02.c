#include<stdio.h>
// program to built a simple calculator
int main()
 {
    float num1, num2, result;
    char oper;

    // get data form user
    printf("Enter first number: ");
    scanf("%f",&num1);
   printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &oper);
    printf("Enter second number: ");
    scanf("%f",&num2);

    // calculate the given data
    switch (oper)
	 {
        case '+':
            result=num1+num2;
            printf("Result: %.2f\n",result);
            break;
        case '-':
            result=num1-num2;
            printf("Result: %.2f\n",result);
            break;
        case '*':
            result=num1*num2;
            printf("Result: %.2f\n",result);
            break;
        case '/':
           if (num2==0) 
        {
                printf("Maths Error.\n");
        }
             else 
            {
                result = num1 / num2;
                printf("Result: %.2f\n",result);
            }
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }
}           
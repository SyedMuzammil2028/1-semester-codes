#include <stdio.h>
// Function to perform basic arithmetic operations
float calculate(float num1, float num2, char operation){
    float result;
    switch (operation){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0){
                result = num1 / num2;
            } 
            else{
                printf("Error: Division by zero is not allowed.\n");
                return 0; // Early exit for division by zero
            }
            break;
        default:
            printf("Error: Invalid operation.\n");
            return 0; // Early exit for invalid operation
    }
    return result;
}

int main(){
    float num1, num2, result;
    char operation;

    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    result = calculate(num1, num2, operation);

    if (operation == '+' || operation == '-' || operation == '*' || (operation == '/' && num2 != 0)) {
        printf("Result: %.2f\n", result);
    }

    return 0;
}

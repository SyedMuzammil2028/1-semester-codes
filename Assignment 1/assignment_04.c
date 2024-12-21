#include <stdio.h>

int main() {
    float money; // amount of money Mr. Bhoola has
    float onion_price, apricot_price, grape_price, tomato_price; // prices of each vegetable
    float onion_kg, apricot_kg, grape_kg, tomato_kg; // quantity of each vegetable
    float total_cost; // total cost of the vegetables
    float change; // change Mr. Bhoola gets back

    printf("\n\tGrocery Assistance for Mr.Bhoola\n");
    // Ask Mr. Bhoola how much money he has
    printf("How much money does Mr. Bhoola have today? $");
    scanf("%f", &money);

    // Ask for the prices of each vegetable
    printf("What is the price of onions per kg? $");
    scanf("%f", &onion_price);
    printf("What is the price of apricots per kg? $");
    scanf("%f", &apricot_price);
    printf("What is the price of grapes per kg? $");
    scanf("%f", &grape_price);
    printf("What is the price of tomatoes per kg? $");
    scanf("%f", &tomato_price);

    // Ask what vegetables Mr. Bhoola wants to buy and how many kg of each
    printf("How many kg of onions does Mr. Bhoola want to buy? ");
    scanf("%f", &onion_kg);
    printf("How many kg of apricots does Mr. Bhoola want to buy? ");
    scanf("%f", &apricot_kg);
    printf("How many kg of grapes does Mr. Bhoola want to buy? ");
    scanf("%f", &grape_kg);
    printf("How many kg of tomatoes does Mr. Bhoola want to buy? ");
    scanf("%f", &tomato_kg);

    // Calculate the total cost
    total_cost = onion_kg * onion_price + apricot_kg * apricot_price + grape_kg * grape_price + tomato_kg * tomato_price;

    // Check if Mr. Bhoola has enough money
    if (total_cost <= money) {
        // Calculate the change
        change = money - total_cost;
        printf("Mr. Bhoola needs to pay $%.2f\n", total_cost);
        printf("Mr. Bhoola gets $%.2f in change\n", change);
    } else {
        printf("Mr. Bhoola needs to pay $%.2f\n", total_cost);
        printf("But Mr. Bhoola doesn't have enough money\n");
    }

    return 0;
}
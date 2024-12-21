#include <stdio.h>
#include <string.h>
// Structure to store details about cars in a dealership, including make, model, 
// year, price, and mileage. Write a program that allows users to add new cars, display a 
// list of available cars, and search for cars by make or model
#define MAX_CARS 50

struct Car {
    char make[20];
    char model[20];
    int year;
    float price;
    float mileage;
};

int addCar(struct Car cars[], int count){
    if (count >= MAX_CARS) {
        printf("Car list is full! Cannot add more cars.\n");
        return count;
    }
    printf("Enter car make, model, year, price, mileage: ");
    scanf("%19s %19s %d %f %f", cars[count].make, cars[count].model, &cars[count].year, &cars[count].price, &cars[count].mileage);
    return count + 1;
}

void listCars(struct Car cars[], int count){
    if (count == 0) {
        printf("No cars available.\n");
        return;
    }
    for (int i = 0; i < count; i++){
        printf("%s %s %d $%.2f %.2f miles\n", cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }
}

void searchCar(struct Car cars[], int count, char *query){
    int found = 0;
    for (int i = 0; i < count; i++){
        if (strcmp(cars[i].make, query) == 0 || strcmp(cars[i].model, query) == 0){
            printf("Found: %s %s %d $%.2f %.2f miles\n", cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
            found = 1;
        }
    }
    if (!found){
        printf("No cars found for make or model: %s\n", query);
    }
}

int main(){
    struct Car cars[MAX_CARS];
    int count = 0;
    int choice;

    do {
        printf("\n1. Add Car\n2. List Cars\n3. Search Cars\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                count = addCar(cars, count); // Update count after adding a car
                break;
            case 2:
                listCars(cars, count);
                break;
            case 3:{
                char query[20];
                printf("Enter make or model to search: ");
                scanf("%19s", query);
                searchCar(cars, count, query);
                break;
            }
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

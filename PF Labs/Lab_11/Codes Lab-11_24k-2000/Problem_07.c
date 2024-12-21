#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Create a system to manage hospital patients using nested structures. Store patient
// details, including admission and discharge dates. Calculate the duration of each patient's stay in
// the hospital. Save patient data into a text file and retrieve it.

const char *patientsdb = "patients.txt";

struct admission
{
    char admission_date[15];
};
struct discharge
{
    char discharge_date[15];
};

struct patient
{
    char name[50];
    char gender[10];
    int age;
    struct discharge d_d;
    struct admission a_d;
};

int c = 0;
struct patient *p = NULL;

void store_data()
{
    c++;
    p = realloc(p, c * sizeof(struct patient));
    if (p == NULL)
    {
        printf("Memory allocation has failed....\n");
        return;
    }

    printf("Enter patient's name: ");
    scanf(" %s", p[c - 1].name);
    printf("Enter patient's gender: ");
    scanf(" %s", p[c - 1].gender);
    printf("Enter patient's age: ");
    scanf("%d", &p[c - 1].age);
    printf("Enter admission date: ");
    scanf(" %s", p[c - 1].a_d.admission_date);
    printf("Enter discharge date : ");
    scanf(" %s", p[c - 1].d_d.discharge_date);

    printf("Patient data added....\n");
}

void calculate_stay()
{
    if (c == 0)
    {
        printf("There are noo patients in the database at the moment...");
        return;
    }

    printf("Which patient's stay do you want to view?(Integers only) : ");
    int search;
    scanf("%d", &search);

    if (search < 1 || search > c)
    {
        printf("Invalid patient number.\n");
        return;
    }

    int ad_year, ad_month, ad_day;
    int dd_year, dd_month, dd_day;

    sscanf(p[search - 1].a_d.admission_date, "%d-%d-%d", &ad_day, &ad_month, &ad_year);
    sscanf(p[search - 1].d_d.discharge_date, "%d-%d-%d", &dd_day, &dd_month, &dd_year);

    int stay_days = (dd_year - ad_year) * 365 + (dd_month - ad_month) * 30 + (dd_day - ad_day);

    printf("Patient Name : %s... Days Stayed : %d", p[search - 1].name, stay_days);
}

void save_data()
{
    FILE *file = fopen(patientsdb, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < c; i++)
    {
        fprintf(file, "%s,%s,%d,%s,%s\n", p[i].name, p[i].gender, p[i].age, p[i].a_d.admission_date, p[i].d_d.discharge_date);
    }

    fclose(file);
    printf("Patient data saved to database\n");
}

void load_data()
{
    FILE *file = fopen(patientsdb, "r");
    if (file == NULL)
    {
        printf("Error.... Can't Open File...\n");
        return;
    }

    char buffer[200];
    c = 0;
    free(p);
    p = NULL;

    while (fgets(buffer, sizeof(buffer), file))
    {
        c++;
        p = realloc(p, c * sizeof(struct patient));
        if (p == NULL)
        {
            printf("Can't Allocate Memory...\n");
            fclose(file);
            return;
        }

        sscanf(buffer, "%[^,],%[^,],%d,%[^,],%s", p[c - 1].name, p[c - 1].gender, &p[c - 1].age, p[c - 1].a_d.admission_date, p[c - 1].d_d.discharge_date);
    }

    fclose(file);
    printf("Patient data loaded successfully...\n");
}

int main()
{
    int choice = 0;
    while (choice != -1)
    {
        printf("\n==== Patients Management Menu ====\n");
        printf("1. Store new patient data\n");
        printf("2. Calculate Patient's Stay in the Hospital\n");
        printf("3. Save data into database\n");
        printf("4. Load data from database\n");
        printf("Enter your choice (-1 to exit): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            store_data();
            break;

        case 2:
            calculate_stay();
            break;

        case 3:
            save_data();
            break;

        case 4:
            load_data();
            break;

        case -1:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid Input... Try again...\n");
            break;
        }
    }

    free(p);

    return 0;
}

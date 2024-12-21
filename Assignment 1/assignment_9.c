#include <stdio.h>

int main() {
    int day, month, year;
    int today_day, today_month, today_year;

    printf("Enter your birthday (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    printf("Enter today's date (dd mm yyyy): ");
    scanf("%d %d %d", &today_day, &today_month, &today_year);

    // Calculate age in years
    int age_years = today_year - year;

    // Adjust age in years if birthday hasn't passed this year
    if (today_month < month || (today_month == month && today_day < day)) {
        age_years--;
    }

    // Calculate age in months
    int age_months = (today_month - month + 12) % 12; // Handle negative months

    // Calculate age in days
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int age_days = 0;
    
    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days_in_month[1] = 29;
    }
    
    // Calculate days from birthday to end of birth year
    for (int i = month; i < 12; i++) {
        age_days += days_in_month[i];
    }
    age_days += days_in_month[month - 1] - day + 1;

    // Calculate days from beginning of this year to today
    for (int i = 0; i < today_month - 1; i++) {
        age_days += days_in_month[i];
    }
    age_days += today_day;

    // Adjust for leap year if today is after February 28th
    if ((today_year % 4 == 0 && today_year % 100 != 0) || today_year % 400 == 0) {
        if (today_month > 2) {
            age_days++;
        }
    }

    printf("Your exact age is: %d years, %d months, and %d days.\n", age_years, age_months, age_days);

    return 0;
}
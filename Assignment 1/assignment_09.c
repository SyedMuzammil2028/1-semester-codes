#include <stdio.h>

int main() {
    int day, month, year;
    int today_day, today_month, today_year;
    int age_years, age_months, age_days;

    // Input birthday
    printf("Enter your birthday (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    // Input today's date
    printf("Enter today's date (dd mm yyyy): ");
    scanf("%d %d %d", &today_day, &today_month, &today_year);

    // Calculate age in years
    age_years = today_year - year;

    // Adjust age if birthday hasn't occurred this year
    if (today_month < month || (today_month == month && today_day < day)) {
        age_years--;
    }

    // Calculate age in months
    age_months = today_month - month;
    if (age_months < 0) {
        age_months += 12;
    }

    // Calculate age in days
    age_days = today_day - day;
    if (age_days < 0) {
        age_months--;

        // Adjust if month goes below 0
        if (age_months < 0) {
            age_months += 12;
            age_years--;
        }

        // Determine how many days the previous month has
        int previous_month = today_month - 1;
        if (previous_month == 0) {
            previous_month = 12;
        }

        // Determine the number of days in the previous month
        if (previous_month == 1 || previous_month == 3 || previous_month == 5 || previous_month == 7 ||
            previous_month == 8 || previous_month == 10 || previous_month == 12) {
            age_days += 31;
        } else if (previous_month == 4 || previous_month == 6 || previous_month == 9 || previous_month == 11) {
            age_days += 30;
        } else if (previous_month == 2) {
            // Check for leap year for February
            if ((today_year % 4 == 0 && today_year % 100 != 0) || (today_year % 400 == 0)) {
                age_days += 29;
            } else {
                age_days += 28;
            }
        }
    }

    // Output the exact age
    printf("Your exact age is: %d years, %d months, and %d days.\n", age_years, age_months, age_days);

    return 0;
}

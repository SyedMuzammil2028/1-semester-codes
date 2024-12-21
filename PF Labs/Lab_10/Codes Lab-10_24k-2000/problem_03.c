#include <stdio.h>
#include <string.h>
// Program  that  uses  structures  to  manage  flight  information,  including  flight
// number, departure city, destination city, date, and available seats. Create functionalities
// to book a seat and display flight details
struct flight_info
{
    char flightname[20];
    char flightdate[20];
    char depart_city[20];
    char dest_city[20];
    int avail_seats;
};

int main()
{
    struct flight_info s;
    int count[10] = {0};
    int choice;
    int seatnum = 0;

    printf("Enter the flight name you want to board: ");
    scanf("%s", s.flightname);

    printf("Enter the date you want to board the flight : ");
    scanf("%s", s.flightdate);

    printf("Enter the departure city : ");
    scanf("%s", s.depart_city);

    printf("Enter the destination city : ");
    scanf("%s", s.dest_city);

    printf("------Your Boarding Info-------\n");
    printf("Your Flight Name : %s\n", s.flightname);
    printf("Your Flight Date : %s \n", s.flightdate);
    printf("Your Departure City : %s\n", s.depart_city);
    printf("Your Destination City : %s\n", s.dest_city);

    while (1)
    {
        printf("-----Choose one of the following Options-----\n");
        printf("1. Check availability \n");
        printf("2. Book flight \n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Available seats: \n");
            for (int i = 0; i < 10; i++)
            {
                if (count[i] == 0)
                {
                    printf("Seat %d\n", i + 1);
                }
            }
            break;

        case 2:
            printf("Which seat do you want to book? (1-10): \n");
            scanf("%d", &seatnum);

            if (seatnum < 1 || seatnum > 20)
            {
                printf("Invalid seat number!\n");
            }
            else if (count[seatnum - 1] == 1)
            {
                printf("This seat is already booked\n");
            }
            else
            {
                count[seatnum - 1] = 1;
                printf("Seat %d has been successfully booked!\n", seatnum);
            }
            break;

        case 3:
            printf("Program Exited Successfully \n");
            return 0;

        default:
            printf("Invalid Input... Please choose a valid option.\n");
            break;
        }
    }

    return 0;
}
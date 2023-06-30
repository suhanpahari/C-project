#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store train details
typedef struct {
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    int availableSeats;
    float fare;
} Train;

// Function to display available trains
void displayTrains(Train* trains, int count) {
    printf("Available Trains:\n");
    printf("-------------------------------------------------------------------\n");
    printf("Train No.\tTrain Name\t\tSource\t\tDestination\tAvailable Seats\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\n", trains[i].trainNumber, trains[i].trainName, trains[i].source, trains[i].destination, trains[i].availableSeats);
    }
    printf("-------------------------------------------------------------------\n");
}

// Function to book a ticket
void bookTicket(Train* trains, int count, int trainNumber, int numPassengers) {
    for (int i = 0; i < count; i++) {
        if (trains[i].trainNumber == trainNumber) {
            if (trains[i].availableSeats >= numPassengers) {
                printf("Enter passenger names:\n");
                for (int j = 0; j < numPassengers; j++) {
                    char passengerName[50];
                    scanf("%s", passengerName);
                    // Store passenger details or perform necessary actions
                }
                // Update available seats and perform necessary actions
                trains[i].availableSeats -= numPassengers;
                printf("Ticket booked successfully!\n");
                return;
            } else {
                printf("Sorry, there are not enough seats available.\n");
                return;
            }
        }
    }
    printf("Invalid train number.\n");
}

int main() {
    // Create an array of trains
    Train trains[] = {
        {12345, "Shatabdi Express", "Delhi", "Mumbai", 100, 500.0},
        {67890, "Rajdhani Express", "Mumbai", "Kolkata", 50, 800.0},
        // Add more train entries as needed
    };

    int numTrains = sizeof(trains) / sizeof(trains[0]);

    printf("Welcome to IRCTC Ticket Booking System!\n");

    while (1) {
        printf("\n1. Display Available Trains\n");
        printf("2. Book a Ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTrains(trains, numTrains);
                break;
            case 2: {
                int trainNumber, numPassengers;
                printf("Enter train number: ");
                scanf("%d", &trainNumber);
                printf("Enter number of passengers: ");
                scanf("%d", &numPassengers);
                bookTicket(trains, numTrains, trainNumber, numPassengers);
                break;
            }
            case 3:
                printf("Thank you for using IRCTC Ticket Booking System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
